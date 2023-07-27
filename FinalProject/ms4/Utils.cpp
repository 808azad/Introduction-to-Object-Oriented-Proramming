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

#include <iomanip>
#include <limits>
#include "Utils.h"

namespace sdds {

    void Utils::flushKey() {
        while (std::cin.get() != '\n');
    }

    int Utils::readInt(int min, int max, const char message[]) {
        int value = 0;
        bool done = false;
        while (!done) {
            std::cin >> value;
            if (!std::cin) {
                std::cin.clear();
                std::cout << message;
            }
            else {
                if (value >= min && value <= max) {
                    done = true;
                }
                else {
                    std::cout << message;
                }
            }
            flushKey();
        }
        return value;
    }

    void Utils::prnInWidth(int width, const std::string& text, char paddingChar, std::ostream& os) {
        std::string outputText;
        if (text.length() > width) {
            outputText = text.substr(0, width);
        }
        else {
            outputText = text;
        }
        os << std::left << std::setw(width) << std::setfill(paddingChar) << outputText;
    }

}