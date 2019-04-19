#include "weapons.h"



int Ammo::GetDamage()
{

    return gun_.GetCaliber()*3;

}

int Ammo::GetPenetration()
{
  return gun_.GetCaliber();
}

std::string Ammo::ToString()
{
  return type_;
}

int HECartridge::GetDamage()
{
  return (int)(Ammo::GetDamage());
}

int HEATCartridge::GetDamage()
{
  return (int) (Ammo::GetDamage()*0.6);
}

int APCCatridge::GetDamage()
{
  return (int)(Ammo::GetDamage()*0.3);
}
