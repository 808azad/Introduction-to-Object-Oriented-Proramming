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

}