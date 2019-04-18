#include "gun.h"


int Gun::GetCaliber()
{
  return caliber_;
}

bool Gun::IsOnTarget(int dice)
{
  return (barrelLenght_+dice)>100;
}
