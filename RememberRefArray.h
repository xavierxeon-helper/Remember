#ifndef RememberRefArrayH
#define RememberRefArrayH

#include <Private/RememberArray.h>
#include <Private/RememberBase.h>

namespace Remember
{
   // array of things that can be streamed via container

   template <typename ContainerType, uint16_t ArraySize>
   class RefArray : public Base, public Array<ContainerType, ArraySize>
   {
   public:
      RefArray(Container* parent);

   protected:
      void write(DataVector& data) const override;
      void read(const DataVector& data, uint64_t& cursor) override;

   private:
      using Remember::Array<ContainerType, ArraySize>::members;
   };
} // namespace Remember

#include <RememberRefArray.hpp>

#endif //  RememberRefArrayH
