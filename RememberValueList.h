#ifndef RememberValueListH
#define RememberValueListH

#include <Private/RememberBase.h>

#include <initializer_list>
#include <vector>

#include <RememberValue.h>

namespace Remember
{
   template <typename DataType>
   class ValueList : public Base
   {
   public:
      ValueList(Container* parent);
      ValueList(Container* parent, std::initializer_list<DataType> initialValues);

   public:
      Value<DataType>& operator[](const uint16_t index);
      const Value<DataType>& operator[](const uint16_t index) const;

   protected:
      void write(DataVector& data) const override;
      void read(const DataVector& data, size_t& cursor) override;

   private:
      std::vector<DataType> members;
   };
} // namespace Remember

#include "RememberValueList.hpp"

#endif // RememberValueListH
