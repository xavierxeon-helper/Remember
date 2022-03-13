#ifndef RememberRefListHPP
#define RememberRefListHPP

#include <RememberRefList.h>

#include <type_traits>

#include <RememberContainer.h>

template <typename ContainerType>
Remember::RefList<ContainerType>::RefList(Container* parent)
   : Base(parent)
   , Remember::List<ContainerType>()
{
   static_assert(std::is_base_of<Container, ContainerType>::value, "ContainerType must inherit from container");
}

template <typename ContainerType>
void Remember::RefList<ContainerType>::write(DataVector& data) const
{
   const uint64_t counter = members.size();
   data.append(counter);

   for (uint16_t index = 0; index < counter; index++)
      members[index].write(data);
}

template <typename ContainerType>
void Remember::RefList<ContainerType>::read(const DataVector& data, uint64_t& cursor)
{
   uint64_t counter = 0;
   data.copyToValue(counter, cursor);
   members.resize(counter);

   for (uint16_t index = 0; index < counter; index++)
      members[index].read(data, cursor);
}

#endif // RememberRefListHPP
