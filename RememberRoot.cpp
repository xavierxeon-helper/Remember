#include <RememberRoot.h>

bool Remember::Root::synced = true;

Remember::Root::Root()
   : Remember::Container()
{
}

void Remember::Root::setUnsynced()
{
   synced = false;
}

bool Remember::Root::needsSync()
{
   return (synced == false);
}

void Remember::Root::setSynced()
{
   synced = true;
}

