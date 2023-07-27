/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 
// Date	
// Author	
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	void flushKey();
	int readInt(int min, int max, const char message[]);
	static void prnInWidth(int width, const string& text, char paddingChar, ostream& os);
}
#endif // SDDS_UTILS_H__
