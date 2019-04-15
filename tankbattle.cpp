#include <iostream>
#include <memory>

struct Coordinates {
  int x;
  int y;
};

class MovingTarget {
 public:
  virtual void NextPos() = 0;
  virtual int GetX()=0;
  virtual int GetY()=0;

  virtual void Shooting() = 0;
  virtual ~MovingTarget() = default;
};

class TankAggressor {
 public:
  virtual int GetX(){
    return coordinates.x;
  }
  virtual int GetY(){
    return coordinates.y;
  }
  virtual void  SetX(int x){
    coordinates.x= x;
  }
  virtual void  SetY(int y){
    coordinates.y= y;
  }
  TankAggressor(std::unique_ptr<MovingTarget> &&  moving_target) : moving_target_{std::move(moving_target)},damage_radius_(200),velocity_(15){};
  void NextPos(){
    coordinates.x+=velocity_*2;
    coordinates.y=velocity_*3;
  }
 private:
  std::unique_ptr<MovingTarget> moving_target_;
  Coordinates coordinates;
  double damage_radius_;
  double velocity_;
};

class SquareMoving:public MovingTarget {
  void NextPos(){

  }
};

class CircleMoving:public MovingTarget{
  void NextPos(){

  }
};
