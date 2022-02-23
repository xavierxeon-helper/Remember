#ifndef RememberValueHPP
#define RememberValueHPP

#include <RememberValue.h>

#include <type_traits>

#include <RememberContainer.h>

template <typename DataType>
Remember::Value<DataType>::Value(Container* parent, const DataType& initialValue)
   : Base(parent)
   , content(initialValue)
{
   static_assert(!std::is_base_of<Container, DataType>::value, "DataType must not inherit from container");
}

template <typename DataType>
Remember::Value<DataType>& Remember::Value<DataType>::operator=(const DataType& other)
{
   content = other;
   return *this;
}

template <typename DataType>
Remember::Value<DataType>::operator DataType() const
{
   return content;
}

template <typename DataType>
DataType& Remember::Value<DataType>::refValue()
{
   return content;
}

template <typename DataType>
const DataType& Remember::Value<DataType>::constValue() const
{
   return content;
}

template <typename DataType>
void Remember::Value<DataType>::write(DataVector& data) const
{
   data.append(content);
}

template <typename DataType>
void Remember::Value<DataType>::read(const DataVector& data, size_t& cursor)
{
   data.copyToValue(content, cursor);
}

template <typename DataType>
Remember::Value<DataType>::Value()
   : Value<DataType>(nullptr, 0)
{
}

#endif // RememberValueHPP
