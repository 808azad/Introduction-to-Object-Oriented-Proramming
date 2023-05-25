#include <iostream>
using namespace std;

namespace sdds {
	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	void strnCpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; i < len && src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		if (i < len) {
			des[i] = '\0';
		}
	}

	int strCmp(const char* s1, const char* s2) {
		int done = 0;
		int i;
		for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
			if (s1[i] > s2[i]) {
				done = 1;
			}										
			else if (s1[i] < s2[i]) {
				done = -1;
			}
		}
		if (done == 0) {
			if (s1[i] == '\0' && s2[i] != '\0') {
				done = -1;
			}
			else if (s1[i] != '\0' && s2[i] == '\0') {
				done = 1;
			}
		}
		return done;
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int done = 0;
		int i;
		for (i = 0; i < len; i++) {
			if (s1[i] > s2[i]) {
				done = 1;
			}
			else if (s1[i] < s2[i]) {
				done = -1;
			}
		}
		return done;
	}

	int strLen(const char* s) {
		int noOfChars = 0;
		int i;
		for (i = 0; s[i] != '\0'; i++) {
			noOfChars = i + 1;
		}
		return noOfChars;
	}

	const char* strStr(const char* str1, const char* str2) {
		const char* donePtr = nullptr;
		const char* ptr = nullptr;
		ptr = str1;
		int sz = strLen(str2);
		for (; *ptr != '\0'; ptr++) {
			if (strnCmp(ptr, str2, sz) == 0) {
				donePtr = ptr;
			}
		}
		return donePtr;
	}

	void strCat(char* des, const char* src) {
		int i;
		int j;
		for (i = 0; des[i] != '\0'; i++);
		for (j = 0; src[j] != '\0'; i++, j++) {
			des[i] = src[j];
		}
		des[i] = '\0';
	}
}




