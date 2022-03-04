#ifndef RememberRootH
#define RememberRootH

#include <RememberContainer.h>

namespace Remember
{
   // this is the top level container
   class Root : public Remember::Container
   {
   public:
      inline Root();

   public:
      inline static void setUnsynced();
      inline static bool isUnsynced();

   protected:
      inline void setSynced();
      inline size_t compileDataSize() const;
      inline DataVector get() const;
      inline void set(const DataVector& data);

   private:
      using Container::read;
      using Container::write;

      static bool synced;
   };
} // namespace Remember

#include <RememberRoot.hpp>

#endif // RememberRootH
