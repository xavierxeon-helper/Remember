#ifndef RememberStringHPP
#define RememberStringHPP

#include "RememberString.h"

Remember::String::String(Container* parent)
   : ValueList<char>(parent)
{
}

Remember::String::String(Container* parent, const std::string& text)
   : ValueList<char>(parent)
{
   *this = text;
}

Remember::String& Remember::String::operator=(const std::string& text)
{
   members.clear();

   for (const char& letter : text)
      append(letter);

   return *this;
}

Remember::String::operator std::string() const
{
   std::string text;
   for (const char& letter : members)
      text += letter;

   return text;
}

#endif // RememberStringHPP
