#ifndef RememberRefH
#define RememberRefH

#include <Private/RememberBase.h>

namespace Remember
{
   // can be streamed via container

   template <typename ContainerType>
   class Ref : public Base
   {
   public:
      Ref(Container* parent);

   public:
      Ref& operator=(const ContainerType& other);
      operator ContainerType*();
      ContainerType* operator->();
      const ContainerType* operator->() const;

   protected:
      void write(DataVector& rawData) const override;
      void read(const DataVector& rawData, uint64_t& cursor) override;

   private:
      Ref();

   private:
      ContainerType container;
   };
} // namespace Remember

#ifndef RememberRefHPP
#include "RememberRef.hpp"
#endif // NOT RememberRefH

#endif //  RememberRefH
