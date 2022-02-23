#ifndef RememberBaseHPP
#define RememberBaseHPP

#include <RememberBase.h>

#include <RememberContainer.h>

Remember::Base::Base(Container* parent)
   : Interface()
{
   if (parent)
   {
      parent->members.push_back(this);
   }
}

#endif // RememberBaseHPP
