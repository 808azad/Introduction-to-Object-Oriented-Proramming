#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account& operator=(int accNum);
      Account& operator=(Account& accInfo);
      Account& operator+=(double amount);
      Account& operator-=(double amount);
      Account& operator<<(Account& accInfo);
      Account& operator>>(Account& accInfo);
   };

   double operator+(const Account& accInfo1, const Account& accInfo2);
   double operator+=(double& balance, Account& accInfo);
   
}
#endif // SDDS_ACCOUNT_H_