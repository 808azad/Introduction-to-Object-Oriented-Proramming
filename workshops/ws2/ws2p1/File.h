#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char empName[]);
   bool read(int &empNum);
   bool read(double &empSalary);
}
#endif 
