#ifndef WEAPONS_H
#define WEAPONS_H
#include <iostream>
#include <string>
#include "gun.h"
class Ammo
{
public:
 Ammo(Gun somegun,std::string type):gun_(somegun),type_(type){};
 virtual int GetDamage();
 int GetPenetration();
 std::string ToString();
 Gun gun_;
private:

std::string type_;

};

class HECartridge :public Ammo{
 public: HECartridge(Gun someGun):Ammo(someGun,"HE"){}
 public: int GetDamage() override;
};

class HEATCartridge :public Ammo{
 public :
  HEATCartridge(Gun someGun):Ammo(someGun,"HEAT"){};
  int GetDamage () override;
};

class APCCatridge : public Ammo{
 public:
  APCCatridge(Gun someGun):Ammo(someGun,"APC"){}
  int GetDamage() override;
};

#endif // WEAPONS_H
