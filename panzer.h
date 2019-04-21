#ifndef PANZER_H
#define PANZER_H
#include<iostream>
#include<memory>
#include<string>
#include <algorithm>
#include <list>
#include"armor.h"
#include"weapons.h"
#include"gun.h"

class panzer
{
public:
 panzer(Gun *gun):gun_(gun){};
 Ammo LoadedAmmo(){}

private:
 std::string model_ ;
 Gun *gun_;

 std::list<Armor> armours;
 std::list<Ammo> ammos;
 int health;


};

#endif // PANZER_H
