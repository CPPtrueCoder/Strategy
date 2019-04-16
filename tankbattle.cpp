#include <iostream>
#include <memory>

struct Coordinates {
  int x;
  int y;
};
std::ostream& operator<<(std::ostream& out, const Coordinates current_coordinates_) {
  out << "X: " << current_coordinates_.x << " "
      << "Y: " << current_coordinates_.y << std::endl;
  return out;
}
class MovingTarget {
 public:
  virtual Coordinates NextPos(Coordinates& coordinates) = 0;

  virtual void Shooting() = 0;
  virtual ~MovingTarget() = default;
};

class TankAggressor : public MovingTarget {
 public:
  TankAggressor(std::unique_ptr<MovingTarget>&& moving_target)
      : moving_target_{std::move(moving_target)},
        damage_radius_(200),
        velocity_(15){};
  void Move() {
    moving_target_->NextPos(current_coordinates_);
  }

 private:
  std::unique_ptr<MovingTarget> moving_target_;
  Coordinates current_coordinates_;
  double damage_radius_;
  double velocity_;
};

class SquareMoving : public MovingTarget {
  Coordinates NextPos(Coordinates&coordinates) {

  }
};

class CircleMoving : public MovingTarget {
  void NextPos() {}
};
