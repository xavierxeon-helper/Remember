#ifndef RememberValueListHPP
#define RememberValueListHPP

#include "RememberValueList.h"

template <typename DataType>
Remember::ValueList<DataType>::ValueList(Container* parent)
   : Base(parent)
   , Remember::List<DataType>()
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
void Remember::ValueList<DataType>::write(DataVector& data) const
{
   const uint64_t counter = members.size();
   data.append(counter);

   for (const DataType& value : members)
      data.append(value);
}

template <typename DataType>
void Remember::ValueList<DataType>::read(const DataVector& data, uint64_t& cursor)
{
   uint64_t counter = 0;
   data.copyToValue(counter, cursor);
   members.resize(counter);

   for (uint64_t index = 0; index < counter; index++)
   {
      DataType value;
      data.copyToValue(value, cursor);
      members[index] = value;
   }
}

#endif // RememberValueListHPP
