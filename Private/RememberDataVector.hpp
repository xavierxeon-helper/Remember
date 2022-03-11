#ifndef RememberDataVectorHPP
#define RememberDataVectorHPP

#include <Private/RememberDataVector.h>

Remember::DataVector::DataVector(const uint64_t size)
   : std::vector<uint8_t>()
{
   if (0 != size)
      resize(size);
}

Remember::DataVector::DataVector(const std::vector<uint8_t>& data)
   : DataVector(0)
{
   *this = data;
}

Remember::DataVector& Remember::DataVector::operator=(const std::vector<uint8_t>& data)
{
   resize(data.size());
   for (uint64_t index = 0; index < data.size(); index++)
      (*this)[index] = data[index];

   return *this;
}

template <typename DataType>
void Remember::DataVector::append(const DataType& value)
{
   union
   {
      uint8_t out[sizeof(DataType)];
      DataType in;
   } convert;

   convert.in = value;

   for (uint64_t index = 0; index < sizeof(DataType); index++)
      push_back(convert.out[index]);
}

template <typename DataType>
void Remember::DataVector::copyToValue(DataType& value, uint64_t& cursor) const
{
   union
   {
      uint8_t in[sizeof(DataType)];
      DataType out;
   } convert;

   for (uint64_t index = 0; index < sizeof(DataType); index++)
      convert.in[index] = at(cursor + index);

   value = convert.out;
   cursor += sizeof(DataType);
}

#endif // RememberDataVectorHPP
