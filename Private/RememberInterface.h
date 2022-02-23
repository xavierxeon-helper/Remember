#ifndef RememberInterfaceH
#define RememberInterfaceH

#include <MusicTools.h>

#include <Private/RememberDataVector.h>

namespace Remember
{
   class Interface
   {
   public:
      using List = std::vector<Interface*>;

   public:
      virtual void write(DataVector& data) const = 0;
      virtual void read(const DataVector& data, size_t& cursor) = 0;
   };

} // namespace Remember

#endif //  RememberInterfaceH
