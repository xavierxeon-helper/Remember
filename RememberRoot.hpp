#ifndef RememberRootHPP
#define RememberRootHPP

#include <RememberRoot.h>

Remember::Root::Root()
   : Remember::Container()
{
}

void Remember::Root::setUnsynced()
{
   synced = false;
}

bool Remember::Root::isUnsynced()
{
   return (synced == false);
}

Remember::DataVector Remember::Root::get() const
{
   DataVector data;
   write(data);

   return data;
}

void Remember::Root::set(const DataVector& data)
{
   if (0 == data.size())
      return;

   uint64_t cursor = 0;
   read(data, cursor);
}

void Remember::Root::setSynced()
{
   synced = true;
}

#endif // RememberRootHPP
