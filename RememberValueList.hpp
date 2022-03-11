#ifndef RememberValueListHPP
#define RememberValueListHPP

#include "RememberValueList.h"

template <typename DataType>
Remember::ValueList<DataType>::ValueList(Container* parent)
   : Base(parent)
   , members()
{
   static_assert(!std::is_base_of<Container, DataType>::value, "DataType must not inherit from container");
   static_assert(!is_vector<DataType>::test, "DataType must not be a vector");
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
void Remember::ValueList<DataType>::append(const DataType& value)
{
   members.push_back(value);
}

template <typename DataType>
uint64_t Remember::ValueList<DataType>::size() const
{
   return members.size();
}

template <typename DataType>
void Remember::ValueList<DataType>::clear()
{
   members.clear();
}

template <typename DataType>
void Remember::ValueList<DataType>::write(DataVector& data) const
{
   const uint64_t data_size = members.size();
   data.append(data_size);

   for (const DataType& value : members)
      data.append(value);
}

template <typename DataType>
void Remember::ValueList<DataType>::read(const DataVector& data, uint64_t& cursor)
{
   uint64_t data_size = 0;
   data.copyToValue(data_size, cursor);
   members.resize(data_size);

   for (uint64_t index = 0; index < data_size; index++)
   {
      DataType value;
      data.copyToValue(value, cursor);
      members[index] = value;
   }
}

#endif // RememberValueListHPP
