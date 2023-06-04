#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds {
	
	class Food {
		char foodName[31];
		int noOfCalories;
		int consumptionTime;
		void setName(const char* name);
	public:
		void setEmpty();
		void set(const char* name, int size, int time);
		void display()const;
		bool isValid()const;
		int calories()const;
		int consumption()const;
	};

}
#endif // !FOOD_H
