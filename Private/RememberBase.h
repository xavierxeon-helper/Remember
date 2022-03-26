#ifndef RememberBaseH
#define RememberBaseH

#include <Private/RememberInterface.h>

namespace Remember
{
   class Container;

   class Base : public Interface
   {
   public:
      inline Base(Container* parent);
   };

} // namespace Remember

#ifndef RememberBaseHPP
#include "Private/RememberBase.hpp"
#endif // NOT RememberBaseHPP

#endif //  RememberBaseH
