#ifndef RememberValueArrayH
#define RememberValueArrayH

#include <Private/RememberBase.h>

#include <initializer_list>

namespace Remember
{
   // array of things that can stream directly

   template <typename DataType, uint16_t ArraySize>
   class ValueArray : public Base
   {
   public:
      ValueArray(Container* parent);
      ValueArray(Container* parent, std::initializer_list<DataType> initialValues);

   public:
      DataType& operator[](const uint16_t index);
      const DataType& operator[](const uint16_t index) const;

   protected:
      void write(DataVector& data) const override;
      void read(const DataVector& data, uint64_t& cursor) override;

   private:
      DataType members[ArraySize];
   };
} // namespace Remember

#include <RememberValueArray.hpp>

#endif //  RememberValueArrayH
