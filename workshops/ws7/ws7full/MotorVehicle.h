#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

namespace sdds {

	class MotorVehicle {
		char m_licencePlate[9];
		char m_adress[64];
		int m_year;
	public:
		MotorVehicle();
		MotorVehicle(const char* plateNumber, int year);
		void moveTo(const char* adress);
		std::ostream& write(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& is = std::cin);
	};
	
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& motor) ;
	std::istream& operator>>(std::istream& is, MotorVehicle& motor);
}

#endif 

