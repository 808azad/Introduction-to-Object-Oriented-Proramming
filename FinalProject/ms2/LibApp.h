#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"
namespace sdds {
   class LibApp {
	   bool m_changed = false; //flag to keep track of changes made to the application data
	   Menu m_mainMenu{}; //will be used as a main menu of the application
	   Menu m_exitMenu{};
	   bool confirm(const char* message);
	   void load();
	   void save();
	   void search();
	   void returnPub();
	   void newPublication();
	   void removePublication();
	   void checkOutPub();
   public:
	   LibApp();
	   void run();
   };
}
#endif // !SDDS_LIBAPP_H



