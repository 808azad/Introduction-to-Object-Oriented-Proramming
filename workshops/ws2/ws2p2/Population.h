#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

	struct Population {
		char* pstCode;
		long int noOfPeople;
	};
	void sort();
	bool load(Population& pop);
	bool load(const char filename[]);
	long int totalOfPeople();
	void display(const Population& pop);
	void display();
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_