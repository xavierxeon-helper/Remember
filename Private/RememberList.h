#ifndef RememberListH
#define RememberListH

#include <vector>

namespace Remember
{
   template <typename ContentType>
   class List
   {
   public:
      inline List();

   public:
      inline ContentType& operator[](const uint16_t index);
      inline const ContentType& operator[](const uint16_t index) const;

      inline operator std::vector<ContentType>();
      inline List<ContentType>& operator=(const std::vector<ContentType>& other);

      inline void append(const ContentType& value);
      inline uint64_t size() const;
      inline void clear();

   protected:
      std::vector<ContentType> members;
   };
} // namespace Remember

#include "RememberList.hpp"

#endif // RememberListH
