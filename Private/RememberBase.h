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

#include <Private/RememberBase.hpp>

#endif //  RememberBaseH
