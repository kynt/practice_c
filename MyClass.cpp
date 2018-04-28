#include <iostream>
#include <string>

class MyClass {
public:
  MyClass();
  ~MyClass();
  static void hoge();
};
MyClass::MyClass() {
}
MyClass::~MyClass() {
}
void MyClass::hoge() {
  std::cout << "hoge" << std::endl;
}


class MyClass2 {
public:
  MyClass2();
  ~MyClass2();
  void getClass(std::function<void(void)> a);
};
MyClass2::MyClass2() {

}
MyClass2::~MyClass2() {
}
void MyClass2::getClass(std::function<void(void)> func) {
  func();
}


int main(void) {
  // auto my = new MyClass();
  auto my = new MyClass();
  auto my2 = new MyClass2();
  MyClass::hoge();
  my2->getClass(MyClass::hoge);
}
