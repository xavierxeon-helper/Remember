#ifndef RememberDataVectorH
#define RememberDataVectorH

#include <cinttypes>
#include <vector>

namespace Remember
{
   class DataVector : public std::vector<uint8_t>
   {
   public:
      inline DataVector(const size_t size = 0);

   public:
      // clang-format off
      template <typename DataType> void append(const DataType& value);
      template <typename DataType> void copyToValue(DataType& value, size_t& cursor) const;
      // clang-format on
   };
} // namespace Remember

#include <Private/RememberDataVector.hpp>

#endif //  RememberDataVectorH
