#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const {
       return m_number > 0;
   }

   Account::operator int() const {
       return m_number;
   }

   Account::operator double() const {
       return m_balance;
   }
   
   bool Account::operator~() const {   
       bool state = false;
       if (m_number == 0) state = true;
       return state;
   }

   Account& Account::operator=(int accNum) {
       if (!(accNum >= 10000 && accNum <= 99999)){ 
           setEmpty();
       }
       else {
           if (~*this) m_number = accNum;
       }
       return *this;
   }

   Account& Account::operator=(Account& accInfo) {
       if ((~*this) && (accInfo.m_number >= 10000 && accInfo.m_number <= 99999)) {
           m_number = accInfo.m_number;
           accInfo.m_number = 0;
           m_balance = accInfo.m_balance;
           accInfo.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator+=(double amount) {
       if ((*this) && amount > 0) {
           m_balance += amount;
       }
       return *this;
   }

   Account& Account::operator-=(double amount) {
       if ((*this) && amount > 0 && amount < double(*this)) {
           m_balance -= amount;
       }
       return *this;
   }

   Account& Account::operator<<(Account& accInfo) {
       if ((*this) && int(*this) != int(accInfo)) {
           m_balance += accInfo.m_balance;
           accInfo.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& accInfo) {
       if ((*this) && int(*this) != int(accInfo)) {
           accInfo.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   double operator+(const Account& accInfo1, const Account& accInfo2) {
       double sum = 0.0;
       if (accInfo1) sum = double(accInfo1) + double(accInfo2);
       return sum;
   }

   double operator+=(double& balance, Account& accInfo) {
       if (accInfo) {
          balance += double(accInfo);
       }
       return balance;
   }

}