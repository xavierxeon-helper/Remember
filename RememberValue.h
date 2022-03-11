#ifndef RememberValueH
#define RememberValueH

#include <Private/RememberBase.h>

namespace Remember
{
   // can be streamed directly

   template <typename DataType>
   class Value : public Base
   {
   public:
      Value(Container* parent, const DataType& initialValue);

   public:
      Value& operator=(const DataType& other);
      operator DataType() const;
      operator DataType&();

   protected:
      void write(DataVector& data) const override;
      void read(const DataVector& data, uint64_t& cursor) override;

   private:
      Value();

   private:
      DataType content;
   };
} // namespace Remember

#include <RememberValue.hpp>

#endif //  RememberValueH
