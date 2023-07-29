#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace sdds {
   class Text {
       char* m_filename{ nullptr };
       char* m_content{ nullptr };
       int getFileLength()const;
   protected:
       void setToSafeState();
       const char& operator[](int index)const;
   public:
       Text();
       Text(const char* filename);
       Text(const Text& text);
       Text& operator=(const Text& text);
       operator bool() const;
       virtual ~Text();
       void read();
       virtual void write(std::ostream& os)const;
   };

   std::ostream& operator<<(std::ostream& os, const Text& text);

}
#endif // !SDDS_PERSON_H__

