#include <iostream>
#include <memory>

class Compression {
 public:
  virtual void compress() = 0;
  virtual ~Compression() = default;
};
class Compressor {
  std::unique_ptr<Compression> compression_;
 public:
  Compressor(std::unique_ptr<Compression>&& compression)
      : compression_{std::move(compression)} {}
  ~Compressor() = default;
  virtual void compress() {
    compression_->compress();
  }
};

class PrinterWorld : public Compression {
 public:
  void compress() { std::cout << " Hello Andrey" << std::endl; }
};
class PrinterAsker : public Compression {
 public:
  void compress() { std::cout << " How are u?" << std::endl; }
};

class Question : public Compression {
 public:
  void compress() { std::cout << " What do you do today?" << std::endl; }
};
