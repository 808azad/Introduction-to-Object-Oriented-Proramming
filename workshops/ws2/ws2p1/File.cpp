#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
 
   bool read(char* empName) {
       bool done = false;
       if (fscanf(fptr, "%[^\n]\n", empName) == 1) {
           done = true;
       }
       return done;
   }
   bool read(int& empNum) {
       bool done = false;
       if (fscanf(fptr, "%d,", &empNum) == 1) {
           done = true;
       }
       return done;
       
   }
   bool read(double& empSalary) {
       bool done = false;
       if (fscanf(fptr, "%lf,", &empSalary) == 1) {
           done = true;
       }
       return done;
   }
}