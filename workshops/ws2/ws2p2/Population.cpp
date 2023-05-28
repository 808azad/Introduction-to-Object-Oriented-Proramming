#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	int recordNum;
	Population* populations;

    void sort() {
        int i, j;
        Population temp;
        for (i = recordNum - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (populations[j].noOfPeople > populations[j + 1].noOfPeople) {
                    temp = populations[j];
                    populations[j] = populations[j + 1];
                    populations[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population& population) {
        bool ok = false;
        char postal[128];
        if (read(postal) && read(population.noOfPeople)) {
            population.pstCode = new char[strlen(postal) + 1];
            strCpy(population.pstCode, postal);
            ok = true;
        }
        return ok;
    }

    bool load(const char filename[]) {
        int i;
        bool ok = false;
        if (openFile(filename)) {
            recordNum = noOfRecords();
            populations = new Population[recordNum];
            for (i = 0; i < recordNum; i++) {
                if (load(populations[i])) {
                    ok = true;
                }
                else {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
                }
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << filename << endl;
        }
        return ok;
    }

    long int totalOfPeople() {
        int i;
        long int total = 0;
        for (i = 0; i < recordNum; i++) {
            total += populations[i].noOfPeople;
        }
        return total;
    }

    void display(const Population& population) {
        cout << population.pstCode << ":  " << population.noOfPeople << endl;
    }

    void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < recordNum; i++) {
            cout << i + 1 << "- ";
            display(populations[i]);
        }
        long int peopleTotal = totalOfPeople();
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << peopleTotal << endl;
    }

    void deallocateMemory() {
        int i;
        for (i = 0; i < recordNum; i++) { 
            delete[] populations[i].pstCode;
        }
        delete[] populations;
    }
}
