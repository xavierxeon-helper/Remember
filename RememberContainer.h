#ifndef RememberContainerH
#define RememberContainerH

#include <Private/RememberInterface.h>

namespace Remember
{
   class Container : public Interface
   {
   public:
      inline Container();
      inline Container(const Container& other) = delete; // to use a container in a ref list, the derived function needs a copy constructor

   protected:
      inline void write(DataVector& data) const override;

      inline void read(const DataVector& data, uint64_t& cursor) override;
      inline virtual void postRead();

   private:
      friend class Base;
      // clang-format off
      template <typename ContainerType> friend class Ref;
      template <typename ContainerType, uint16_t ArraySize> friend class RefArray;
      template <typename ContainerType> friend class RefList;
      // clang-format on
   private:
      Interface::List members;
   };
} // namespace Remember

#ifndef RememberContainerHPP
#include "RememberContainer.hpp"
#endif // NOT RememberContainerHPP

#endif //  RememberContainerH
