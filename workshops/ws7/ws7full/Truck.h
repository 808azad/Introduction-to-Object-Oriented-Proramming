#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"
namespace sdds {

	class Truck : public MotorVehicle {
		double m_capacity;
		double m_cargoLoad;
	public:
		Truck();
		Truck(const char* licensePlate, int year, double capacity, const char* adress2);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os = std::cout) const ;
		std::istream& read(std::istream& is = std::cin);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& truck);
	std::istream& operator>>(std::istream& is, Truck& truck);

}


#endif 

