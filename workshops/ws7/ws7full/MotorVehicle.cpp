#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "MotorVehicle.h"
using namespace std;

namespace sdds {

	MotorVehicle::MotorVehicle() {
		m_licencePlate[0] = '\0';
		m_adress[0] = '\0';
		m_year = 0;
	}

	MotorVehicle::MotorVehicle(const char* plateNumber, int year) {
		if (plateNumber != nullptr && plateNumber[0] != '\0' && year > 0) {
			strnCpy(m_licencePlate, plateNumber, 8);
			m_licencePlate[8] = '\0';
			strCpy(m_adress, "Factory");
			m_adress[strLen("Factory") + 1] = '\0';
			m_year = year;
		}
	}

	void MotorVehicle::moveTo(const char* adress) {
		if (adress != nullptr && adress[0] != '\0' && strCmp(m_adress, adress) != 0) {
			cout << "|" << right << setw(8) << m_licencePlate << "| ";
			cout << "|" << right << setw(20) << m_adress;
			cout << " ---> " << left << setw(20) << adress << "|" << endl;
			strCpy(m_adress, adress);
			m_adress[strLen(adress) + 1] = '\0';
		}
	}

	ostream& MotorVehicle::write(ostream& os) const {
		return os << "| " << m_year << " | " << m_licencePlate << " | " << m_adress << " |";
	}

	istream& MotorVehicle::read(istream& is) {
		cout << "Built year: ";
		is >> m_year;
		cout << "License plate: ";
		is >> m_licencePlate;
		cout << "Current location: ";
		is >> m_adress;
		if (is.fail()) {
			is.clear();
		}
		is.ignore(10000, '\n');
		return is;
	}

	ostream& operator<<(ostream& os, const MotorVehicle& motor) {
		return motor.write(os);
	}

	istream& operator>>(istream& is, MotorVehicle& motor) {
		return motor.read(is);
	}

}