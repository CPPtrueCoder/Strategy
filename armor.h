#ifndef ARMOR_H
#define ARMOR_H
#include<iostream>
#include<string>
#include<memory>
#include "weapons.h"

class Armor
{
public:
 Armor(int thickness,std::string type):thickness_(thickness),type_(type){};
 Armor(const Armor&)=delete;
 Armor& operator=(const Armor&) = delete;

 virtual bool IsPenetrated(Ammo projectile);
 int GetThickness(){
   return thickness_;
 }
private:
 int thickness_;
 std:: string type_;

};
class HArmor:public Armor{
 public:
  HArmor(int thickness,std::unique_ptr <Armor>&& armor):Armor(thickness,"Heavy armor"),armor_{std::move(armor)}{};
  bool IsPenetrated(Ammo projectile){
    if (projectile.ToString()=="HECartridge"){
      return  projectile.GetPenetration() > armor_->GetThickness()*1.2;
    }
    else if (projectile.ToString()=="HEATCartridge"){
      return projectile.GetPenetration()>armor_->GetThickness()*1;
    }
    else {
      return projectile.GetPenetration()>armor_->GetThickness()*0.5;
    }
  }
 private:
  std::unique_ptr<Armor> armor_;
};


#endif // ARMOR_H
