#ifndef RememberRefArrayH
#define RememberRefArrayH

#include <Private/RememberBase.h>

#include <RememberRef.h>

namespace Remember
{
   // array of things that can be streamed via container

   template <typename ContainerType, uint16_t ArraySize>
   class RefArray : public Base
   {
   public:
      RefArray(Container* parent);

   public:
      ContainerType& operator[](const uint16_t index);
      const ContainerType& operator[](const uint16_t index) const;

   protected:
      void write(DataVector& data) const override;
      void read(const DataVector& data, uint64_t& cursor) override;

   private:
      ContainerType members[ArraySize];
   };
} // namespace Remember

#include <RememberRefArray.hpp>

#endif //  RememberRefArrayH
