#ifndef RememberRefListH
#define RememberRefListH

#include <Private/RememberBase.h>

#include <vector>

namespace Remember
{
   template <typename ContainerType>
   class RefList : public Base
   {
   public:
      inline RefList(Container* parent);

   public:
      inline ContainerType& operator[](const uint16_t index);
      inline const ContainerType& operator[](const uint16_t index) const;
      inline void append(const ContainerType& container);
      inline uint64_t size() const;
      inline void clear();

   protected:
      inline void write(DataVector& data) const override;
      inline void read(const DataVector& data, uint64_t& cursor) override;

   protected:
      std::vector<ContainerType> members;
   };
} // namespace Remember

#include "RememberRefList.hpp"

#endif // RememberRefListH
