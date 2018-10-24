#include"client.h"

void main()
{
CLIENT a;
a.getname();
CLIENT::ChangeServerName();
a.getname();
a.ChangeServerName();
CLIENT::getname();
return;
}