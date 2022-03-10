#ifndef RememberStringH
#define RememberStringH

#include <RememberValueList.h>

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

#include "RememberString.hpp"

#endif // RememberStringH
