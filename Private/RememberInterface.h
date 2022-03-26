#ifndef RememberInterfaceH
#define RememberInterfaceH

#include <vector>

#include <Private/RememberDataVector.h>

namespace Remember
{
   class Interface
   {
   public:
      using List = std::vector<Interface*>;

   public:
      Interface();
      virtual ~Interface();

   public:
      virtual void write(DataVector& data) const = 0;
      virtual void read(const DataVector& data, uint64_t& cursor) = 0;
   };

} // namespace Remember

#endif //  RememberInterfaceH
