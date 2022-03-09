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
      inline ValueList(Container* parent);
      inline ValueList(Container* parent, std::initializer_list<DataType> initialValues);

   public:
      inline DataType& operator[](const uint16_t index);
      inline const DataType& operator[](const uint16_t index) const;

   protected:
      inline void write(DataVector& data) const override;
      inline void read(const DataVector& data, size_t& cursor) override;

   private:
      std::vector<DataType> members;
   };
} // namespace Remember

#include "RememberValueList.hpp"

#endif // RememberValueListH
