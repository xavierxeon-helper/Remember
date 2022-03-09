#ifndef RememberValueListHPP
#define RememberValueListHPP

#include "RememberValueList.h"

template <typename DataType>
Remember::ValueList<DataType>::ValueList(Container* parent)
   : Base(parent)
   , members()
{
   static_assert(!std::is_base_of<Container, DataType>::value, "DataType must not inherit from container");
}

template <typename DataType>
Remember::ValueList<DataType>::ValueList(Container* parent, std::initializer_list<DataType> initialValues)
   : ValueList<DataType>(parent)
{
   for (const DataType& value : initialValues)
      members.push_back(value);
}

template <typename DataType>
DataType& Remember::ValueList<DataType>::operator[](const uint16_t index)
{
   return members[index];
}

template <typename DataType>
const DataType& Remember::ValueList<DataType>::operator[](const uint16_t index) const
{
   return members[index];
}

template <typename DataType>
void Remember::ValueList<DataType>::write(DataVector& data) const
{
   const size_t size = members.size();
   data.append(size);

   for (const DataType& value : members)
      data.append(value);
}

template <typename DataType>
void Remember::ValueList<DataType>::read(const DataVector& data, size_t& cursor)
{
   size_t size = 0;
   data.copyToValue(size, cursor);
   members.resize(size);

   for (uint16_t index = 0; index < size; index++)
   {
      DataType value;
      data.copyToValue(value, cursor);
      members[index] = value;
   }
}

#endif // RememberValueListHPP
