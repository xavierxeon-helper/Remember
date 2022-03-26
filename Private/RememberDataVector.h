#ifndef RememberDataVectorH
#define RememberDataVectorH

#include <cinttypes>
#include <vector>

namespace Remember
{
   class DataVector : public std::vector<uint8_t>
   {
   public:
      inline DataVector(const uint64_t size = 0);
      inline DataVector(const std::vector<uint8_t>& data);
      inline DataVector& operator=(const std::vector<uint8_t>& data);

   public:
      // clang-format off
      template <typename DataType> void append(const DataType& value);
      template <typename DataType> void copyToValue(DataType& value, uint64_t& cursor) const;
      // clang-format on
   };
} // namespace Remember

#ifndef RememberDataVectorHPP
#include "Private/RememberDataVector.hpp"
#endif // NOT RememberDataVectorHPP

#endif //  RememberDataVectorH
