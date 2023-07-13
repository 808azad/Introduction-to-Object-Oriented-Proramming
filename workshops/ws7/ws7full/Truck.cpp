#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Truck.h"
using namespace std;

namespace sdds {

	Truck::Truck() : MotorVehicle() {
		m_capacity = 0;
		m_cargoLoad = 0;
	}

	Truck::Truck(const char* licensePlate, int year, double capacity, const char* adress2) : MotorVehicle(licensePlate, year) {
		MotorVehicle::moveTo(adress2);
		if (capacity > 0) m_capacity = capacity;
		else m_capacity = 0;
		m_cargoLoad = 0;
	}

	bool Truck::addCargo(double cargo) {
		bool res = false;
		if (cargo > 0) {
			if (cargo <= m_capacity && m_cargoLoad < m_capacity) {
				if (m_cargoLoad + cargo <= m_capacity) {
					m_cargoLoad += cargo;
					res = true;
				}
				else {
					m_cargoLoad = m_capacity;
					res = true;
				}
			}
		}
		return res;
	}

	bool Truck::unloadCargo() {
		bool res = false;
		if (m_cargoLoad > 0) {
			m_cargoLoad = 0;
			res = true;
		}
		return res;
	}

	ostream& Truck::write(ostream& os) const {
		MotorVehicle::write(os);
		os << " | " << m_cargoLoad << "/" << m_capacity;
		return os;
	}

	istream& Truck::read(istream& is) {
		MotorVehicle::read(is);
		cout << "Capacity: ";
		is >> m_capacity;
		cout << "Cargo: ";
		is >> m_cargoLoad;
		if (is.fail()) {
			is.clear();
		}
		is.ignore(10000, '\n');
		return is;
	}

	ostream& operator<<(ostream& os, const Truck& truck) {
		return truck.write(os);
	}

	istream& operator>>(istream& is, Truck& truck) {
		return truck.read(is);
	}

}