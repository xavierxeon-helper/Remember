#ifndef RememberValueListH
#define RememberValueListH

#include <Private/RememberBase.h>
#include <Private/RememberList.h>

#include <initializer_list>
#include <vector>

namespace Remember
{
   template <typename DataType>
   class ValueList : public Base, public List<DataType>
   {
   public:
      inline ValueList(Container* parent);
      inline ValueList(Container* parent, std::initializer_list<DataType> initialValues);

   private:
      inline void write(DataVector& data) const override;
      inline void read(const DataVector& data, uint64_t& cursor) override;

   protected: // accesible to Remember::String
      using Remember::List<DataType>::members;
   };

} // namespace Remember

#include "RememberValueList.hpp"

#endif // RememberValueListH
