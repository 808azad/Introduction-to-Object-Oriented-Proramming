#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#endif // !SDDS_HTMLTEXT_H

#include <iostream>
#include "Text.h"

namespace sdds {
   class HtmlText :  public Text {
       char* m_title{ nullptr };
   public:
      HtmlText();
      HtmlText(const char* filename);
      HtmlText(const char* filename, const char* title);
      HtmlText(const HtmlText& html);
      HtmlText& operator=(const HtmlText& html);
      ~HtmlText();
      void write(std::ostream& os) const override;
      operator bool() const;
   };
}
#endif // !SDDS_HTMLTEXT_H__
