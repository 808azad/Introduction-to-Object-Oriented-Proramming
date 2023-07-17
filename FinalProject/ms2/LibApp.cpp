#include "LibApp.h"
using namespace std;

namespace sdds {
   
	bool LibApp::confirm(const char* message) {
		if (message != nullptr && message[0] != '\0') {
			Menu confirmMenu(message);
			confirmMenu << "yes";
			return (confirmMenu.run() == 1);
		}
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
		m_changed = true;
	}

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?")) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}

}
