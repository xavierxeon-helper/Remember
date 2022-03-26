#ifndef RememberStringH
#define RememberStringH

#include <RememberValueList.h>

#include <string>

namespace Remember
{
   class String : public ValueList<char>
   {
   public:
      inline String(Container* parent);
      inline String(Container* parent, const std::string& text);

   public:
      inline String& operator=(const std::string& text);
      inline operator std::string() const;
   };

} // namespace Remember

#ifndef RememberStringHPP
#include "RememberString.hpp"
#endif // NOT RememberStringHPP

#endif // RememberStringH
