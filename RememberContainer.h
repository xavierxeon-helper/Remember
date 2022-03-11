#ifndef RememberContainerH
#define RememberContainerH

#include <Private/RememberInterface.h>

namespace Remember
{
   class Container : public Interface
   {
   public:
      inline Container();

   protected:
      inline void write(DataVector& data) const override;
      inline void read(const DataVector& data, uint64_t& cursor) override;

   private:
      friend class Base;
      // clang-format off
      template <typename ContainerType> friend class Ref;
      // clang-format on
   private:
      Interface::List members;
   };
} // namespace Remember

#include <RememberContainer.hpp>

#endif //  RememberContainerH
