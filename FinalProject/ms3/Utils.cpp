/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
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

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Utils.h"
using namespace std;
namespace sdds {

    void flushKey() {
        while (cin.get() != '\n');
    }

    int readInt(int min, int max, const char message[]) {
        int value = 0;
        bool done = false;
        while (!done) {
            cin >> value;
            if (!cin) {
                cin.clear();
                cout << message;
            }
            else {
                if (value >= min && value <= max) {
                    done = true;
                }
                else {
                    cout << message;
                }
            }
            flushKey();
        }
        return value;
    }

    static void prnInWidth(int width, const string& text, char paddingChar, ostream& os) {
        string outputText;
        if (text.length() > width) {
            outputText = text.substr(0, width);
        }
        else {
            outputText = text;
        }
        os << left << setw(width) << setfill(paddingChar) << outputText;
    }

}