#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "LibApp.h"
using namespace std;

namespace sdds {

	bool LibApp::confirm(const char* message) {
		int res = 0;
		if (message != nullptr && message[0] != '\0') {
			Menu confirmMenu(message);
			confirmMenu << "Yes";
			res = confirmMenu.run();
		}
		return res == 1;
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;
		ifstream file(m_filename);
		if (!file) {
			cerr << "Could not open a file!" << endl;
		}
		else {
			char pblType{};
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]) {
					delete m_PPA[i];
					m_PPA[i] = nullptr;
				}
			}
			m_NOLP = 0;
			for (int j = 0; file; j++) {
				file >> pblType;
				if (file) {
					if (pblType == 'P') {
						m_PPA[j] = new Publication;
					}
					else if (pblType == 'B') {
						m_PPA[j] = new Book;
					}
					if (m_PPA[j]) {
						file >> *m_PPA[j];
						m_NOLP++;
					}
				}
			}
			if (m_NOLP > 0) {
				m_LLRN = m_PPA[m_NOLP - 1] -> getRef();
				m_LLRN++;
			}
		}
		file.close();
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream outFile(m_filename); 
		if (!outFile) {
			cout << "Could not open a file! Error: " << strerror(errno) << endl;
		}
		else {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->getRef() != 0) {
					if (m_PPA[i]->getRef() == -1) {
						m_PPA[i]->setRef(m_LLRN);
						m_LLRN++;
					}
					outFile << *m_PPA[i] << endl;
				}
			}
			outFile.close();
		}
	}

	PublicationSelector* LibApp::search(int mode) {
		PublicationSelector* pblSelectorBook{ nullptr };
		PublicationSelector* pblSelectorPublication{ nullptr };
		pblSelectorBook = new PublicationSelector("Select one of the following found matches:");
		pblSelectorPublication = new PublicationSelector("Select one of the following found matches:");
		char buffer[256]{};
		cout << "Choose the type of publication:" << endl;
		int choice = m_typePublication.run();
		char book = 'B';
		char publication = 'P';
		if (choice == 0) {
			cout << "Aborted!" << endl;
			cout << "-------------------------------------------------------" << endl;
		}
		else {
			if (choice == 1) book;
			else if (choice == 2) publication;
			cout << "Publication Title: ";
			cin.get(buffer, 255);
			cin.ignore(10000, '\n');
			for (int i = 0; i < m_NOLP; i++) {
				bool equal = strstr(m_PPA[i]->getTitle(), buffer) != nullptr;
				if (m_PPA[i]->getRef() != 0) {
					if (m_PPA[i]->type() == book) {
						if (equal) {
							if ((mode == 0) || (mode == 1 && m_PPA[i]->onLoan()) || (mode == 2 && !m_PPA[i]->onLoan())) {
								*pblSelectorBook << m_PPA[i];
							}
						}
					}
					else if (m_PPA[i]->type() == publication) {
						if (equal) {
							if ((mode == 0) || (mode == 1 && m_PPA[i]->onLoan()) || (mode == 2 && !m_PPA[i]->onLoan())) {
								*pblSelectorPublication << m_PPA[i];
							}
						}
					}
				}
			}
			if (pblSelectorBook) {
				pblSelectorBook->sort();
			}
		    if (pblSelectorPublication) {
				pblSelectorPublication->sort();
			}
			else {
				cout << "No matches found" << endl;
			}
		}
		return (choice == 1) ? pblSelectorBook : pblSelectorPublication;
	}

	void LibApp::returnPub() {
		search(0);
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		cout << endl;
		m_changed = true;
	}

	void LibApp::newPublication() {
		if (m_NOLP < SDDS_LIBRARY_CAPACITY) {
			cout << "Adding new publication to the library" << endl;
			cout << "Choose the type of publication:" << endl;
			int choice = m_typePublication.run();
			Publication* p{ nullptr };
			if (choice == 0) {
				cout << "Aborted!" << endl;
				cout << "-------------------------------------------------------" << endl;
			}
			else {
				if (choice == 1) {
					p = new Book;
				}
				else if(choice == 2){
					p = new Publication;
				}
				if (p) {
					cin >> *p;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
					}
					cin.ignore(10000, '\n');
				}
				if (confirm("Add this publication to the library?")) {
					m_changed = true;
					m_PPA[m_NOLP] = p;
					m_NOLP++;
					cout << "Publication added" << endl;
				}
				else {
					delete p;
				}
				cout << endl;
			}
		}
		else {
			cout << "The library is full!" << endl;
		}
	}

	Publication* LibApp::getPub(int getRef) {
		int i{};
		bool done = false;
		for (i = 0; !done && i < m_NOLP; i++) {
			if (m_PPA[i]->getRef() == getRef) {
				done = true;
			}
		}
		return m_PPA[i];
	}

	void LibApp::removePublication() {
		ostream& os = cout;
		PublicationSelector* pblSelect = search(0);
		Publication* pbl{ nullptr };
		cout << "Removing Publication from the library" << endl;
		int choice = pblSelect->run();
		if (choice > 0) {
			pbl = getPub(choice);
			pbl->write(os) << endl;
   			if (confirm("Remove this publication from the library?")) {
				pbl->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
		cout << endl;
	}

	void LibApp::checkOutPub() {
		search(0);
		if (confirm("Check out publication?")) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
		cout << endl;
	}

	void LibApp::populateObj() {
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		m_typePublication << "Book";
		m_typePublication << "Publication";
	}

	LibApp::LibApp(const char* filename) :
		m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		if (filename != nullptr && filename[0] != '\0') {
			strcpy(m_filename, filename);
		}
		for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++) {
			m_PPA[i] = nullptr;
		}
		m_changed = false;
		populateObj();
		load();
	}

	LibApp::~LibApp() {
		for (int i = 0; i < m_NOLP; i++) {
			delete m_PPA[i];
			m_PPA[i] = nullptr;
		}
	}

	void LibApp::run() {
		bool done = false;
		while (!done) {
			int choice = m_mainMenu.run();
			switch (choice) {
				case 1:
					newPublication();
					break;
				case 2:
					removePublication();
					break;
				case 3:
					checkOutPub();
					break;
				case 4:
					returnPub();
					break;
				default:
					if (m_changed) {
						int choice2 = m_exitMenu.run();
						switch (choice2) {
							case 1:
								save();
								done = true;
								break;
							case 2:
								m_changed = true;
								cout << endl;
								break;
							default:
								if (confirm("This will discard all the changes are you sure?")) {
									done = true;
								}
								else {
									m_changed = false;
								}
						}
					}
					else {
						done = true;
					}
			}
		}
		cout << endl << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

}
