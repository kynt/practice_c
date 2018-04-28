#include <iostream>
#include <string>
#include <stack>

template <class T>
class TLoad {
public:
  static void Load(std::function<void(void)>);
  static void LoadBack();
};

template <class T>
void TLoad<T>::Load(std::function<void(void)>) {
  std::cout <<  "Load Function" << std::endl;
  return;
}

template <class T>
void TLoad<T>::LoadBack() {
  std::cout <<  "Load Back Function" << std::endl;
  return;
}

class Parent {
public:
  std::stack<std::function<void(void)> > st;

  virtual void setFunc(std::function<void(void)> func) {
    st.push(func);
  }
  virtual std::function<void(void)> getFunc() {
    if (st.empty()) {
      return nullptr;
    }

    auto func = st.top();
    st.pop();
    return func;
  }

  Parent();
  ~Parent();
};
Parent::Parent() {
}
Parent::~Parent() {
}

class MyClass : public TLoad<MyClass> , public Parent {
public:
  MyClass();
  ~MyClass();
};
MyClass::MyClass() {
}
MyClass::~MyClass() {
}

int main(void) {
  auto my = new MyClass();
  my->setFunc(MyClass::LoadBack);
  auto func = my->getFunc();
  func();
}
