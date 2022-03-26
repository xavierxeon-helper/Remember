#ifndef RememberValueArrayH
#define RememberValueArrayH

#include <Private/RememberArray.h>
#include <Private/RememberBase.h>

#include <initializer_list>

namespace Remember
{
   // array of things that can stream directly

   template <typename DataType, uint16_t ArraySize>
   class ValueArray : public Base, public Array<DataType, ArraySize>
   {
   public:
      ValueArray(Container* parent);
      ValueArray(Container* parent, std::initializer_list<DataType> initialValues);

   protected:
      void write(DataVector& data) const override;
      void read(const DataVector& data, uint64_t& cursor) override;

   private:
      using Remember::Array<DataType, ArraySize>::members;
   };
} // namespace Remember

#ifndef RememberValueArrayHPP
#include "RememberValueArray.hpp"
#endif // NOT RememberValueArrayHPP

#endif //  RememberValueArrayH
