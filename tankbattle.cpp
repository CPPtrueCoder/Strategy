#include <iostream>
#include <memory>

struct Coordinates {
  int x;
  int y;
};

class MovingTarget {
 public:
  virtual void NextPos() = 0;
  virtual void Shooting() = 0;
  virtual ~MovingTarget() = default;
};

class TankAggressor {
 public:
  TankAggressor(std::unique_ptr<MovingTarget> &&  moving_target) {}

 private:
  std::unique_ptr<MovingTarget> moving_target_;
  Coordinates coordinates;
  double damage_radius;
  double velocity;
};
