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

   bool read(char* pstCode) {
       bool done = false;
       if (fscanf(fptr, "%[^,],", pstCode) == 1) {
           done = true;
       }
       return done;
   }
   bool read(long int& noOfPeople) {
       bool done = false;
       if (fscanf(fptr, "%ld\n", &noOfPeople) == 1) {
           done = true;
       }
       return done;

   }

}