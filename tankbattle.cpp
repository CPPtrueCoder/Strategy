#include <iostream>
#include <memory>

struct Coordinates {
  double x;
  double y;
};
[[nodiscard]] double ZeroVelocity()noexcept{
  double x=0;
  return x;
}
[[nodiscard]] Coordinates ZeroCoordinate() noexcept {
  Coordinates coordinates={0,0};
  return coordinates;
}

std::ostream& operator<<(std::ostream& out, const Coordinates current_coordinates_) {
  out << "X: " << current_coordinates_.x << " "
      << "Y: " << current_coordinates_.y << std::endl;
  return out;
}
class MovingTarget {
 public:
  virtual void NextPos(Coordinates& coordinates,double velocity) = 0;
  virtual void Shooting() = 0;
  virtual ~MovingTarget() = default;
};

class TankAggressor : public MovingTarget {
 public:
  TankAggressor(std::unique_ptr<MovingTarget>&& moving_target)
      : moving_target_{std::move(moving_target)},
        damage_radius_(200),
        velocity_(15){};
  virtual void NextPos(Coordinates &coordinates) {
    for (int i =0 ; i<30;++i){
      moving_target_->NextPos(current_coordinates_,velocity_);
    }
  }
  void Shooting()override{
    std::cout<<" Shoot!"<<std::endl;
  }
 private:
  std::unique_ptr<MovingTarget> moving_target_;
  Coordinates current_coordinates_;
  double damage_radius_;
  double velocity_;
};

class Stop: public MovingTarget {
  void NextPos(Coordinates&coordinates,double velocity) {
    coordinates=ZeroCoordinate();
    velocity=ZeroVelocity();
  }
};

class LineMovingX : public MovingTarget {
  void NextPos(Coordinates&coordinates,double velocity) {
    coordinates.x+=velocity;
  }
};

class LineMovingY:public MovingTarget{
  void NextPos(Coordinates&coordinates,double velocity){
    coordinates.y+=velocity;
  }
};

