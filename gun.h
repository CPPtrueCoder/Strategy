#ifndef GUN_H
#define GUN_H


class Gun
{
public:
 Gun(int caliber,int barrelLenght):caliber_(caliber),barrelLenght_(barrelLenght){};
 int GetCaliber();
 bool IsOnTarget(int dice);
private:
 int caliber_;
 int barrelLenght_;
};

#endif // GUN_H
