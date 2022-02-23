#ifndef RememberContainerHPP
#define RememberContainerHPP

#include <RememberContainer.h>

Remember::Container::Container()
   : Interface()
   , members()
{
}

void Remember::Container::write(DataVector& data) const
{
   for (Interface* member : members)
      member->write(data);
}

void Remember::Container::read(const DataVector& data, size_t& cursor)
{
   for (Interface* member : members)
      member->read(data, cursor);
}

#endif // RememberContainerHPP
