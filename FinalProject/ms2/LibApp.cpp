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
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
	}

	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		cout << endl;
		m_changed = true;
	}

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?")) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
		cout << endl;
	}

	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?")) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
		cout << endl;
		
	}

	void LibApp::checkOutPub() {
		search();
		if (confirm("Check out publication?")) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
		cout << endl;
	}

	LibApp::LibApp() : 
		m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?") 
	{
		m_changed = false;
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		load();
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
