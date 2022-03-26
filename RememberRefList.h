#ifndef RememberRefListH
#define RememberRefListH

#include <Private/RememberBase.h>
#include <Private/RememberList.h>

namespace Remember
{
   // to use a container in a ref list, the derived function needs a copy constructor

   template <typename ContainerType>
   class RefList : public Base, public List<ContainerType>
   {
   public:
      inline RefList(Container* parent);

   protected:
      inline void write(DataVector& data) const override;
      inline void read(const DataVector& data, uint64_t& cursor) override;

   private:
      using Remember::List<ContainerType>::members;
   };
} // namespace Remember

#ifndef RememberRefListHPP
#include "RememberRefList.hpp"
#endif // NOT RememberRefListHPP

#endif // RememberRefListH
