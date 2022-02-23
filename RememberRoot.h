#ifndef RememberRootH
#define RememberRootH

#include <RememberContainer.h>

namespace Remember
{
   // this is the top level container
   class Root : public Remember::Container
   {
   public:
      Root();

   public:
      static void setUnsynced();
      static bool needsSync();

   protected:
      void setSynced();

   private:
      static bool synced;
   };
} // namespace Remember

#endif // RememberRootH
