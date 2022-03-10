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

   template <class N>
   struct is_vector
   {
      static const bool test = false;
   };

   template <class N, class A>
   struct is_vector<std::vector<N, A>>
   {
      static const bool test = true;
   };

} // namespace Remember

#include <Private/RememberBase.hpp>

#endif //  RememberBaseH
