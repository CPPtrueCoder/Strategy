#include "armor.h"


bool Armor::IsPenetrated(Ammo projectile)
{
  return projectile.GetDamage()>thickness_;
}
