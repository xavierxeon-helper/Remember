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
      inline DataVector get() const;
      inline void set(const DataVector& data);
      inline void setSynced();

   private:
      using Container::read;
      using Container::write;

      static bool synced;
   };
} // namespace Remember

#ifndef RememberRootHPP
#include "RememberRoot.hpp"
#endif // NOT RememberRootHPP

#endif // RememberRootH
