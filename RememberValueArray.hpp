#ifndef RememberValueArrayHPP
#define RememberValueArrayHPP

#include <RememberValueArray.h>

#include <type_traits>

#include <RememberContainer.h>

template <typename DataType, uint16_t ArraySize>
Remember::ValueArray<DataType, ArraySize>::ValueArray(Container* parent)
   : Base(parent)
   , members()
{
   static_assert(!std::is_base_of<Container, DataType>::value, "DataType must not inherit from container");
}

template <typename DataType, uint16_t ArraySize>
Remember::ValueArray<DataType, ArraySize>::ValueArray(Container* parent, std::initializer_list<DataType> initialValues)
   : ValueArray<DataType, ArraySize>(parent)
{
   uint16_t index = 0;
   for (const DataType& value : initialValues)
   {
      members[index].refValue() = value;
      index++;
      if (index == ArraySize)
         break;
   }
}

template <typename DataType, uint16_t ArraySize>
Remember::Value<DataType>& Remember::ValueArray<DataType, ArraySize>::operator[](const uint16_t index)
{
   return members[index];
}

template <typename DataType, uint16_t ArraySize>
const Remember::Value<DataType>& Remember::ValueArray<DataType, ArraySize>::operator[](const uint16_t index) const
{
   return members[index];
}

template <typename DataType, uint16_t ArraySize>
void Remember::ValueArray<DataType, ArraySize>::write(DataVector& data) const
{
   for (uint16_t index = 0; index < ArraySize; index++)
      members[index].write(data);
}

template <typename DataType, uint16_t ArraySize>
void Remember::ValueArray<DataType, ArraySize>::read(const DataVector& data, size_t& cursor)
{
   for (uint16_t index = 0; index < ArraySize; index++)
      members[index].read(data, cursor);
}

#endif // RememberValueArrayHPP