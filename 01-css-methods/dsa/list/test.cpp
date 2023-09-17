#include <iostream> 
using namespace std;

class Animal {
public:
  virtual void speak() {
    cout << "I am an animal!" << endl;
  }
};

class Dog : public Animal {
public:
  void speak() {
    cout << "Woof!" << endl;
  }
};

class Cat : public Animal {
public:
  void speak() {
    cout << "Meow!" << endl;
  }
};

int main() {
  Animal* animal = new Dog();
  animal->speak(); // Prints "Woof!"

  animal = new Cat();
  animal->speak(); // Prints "Meow!"

  return 0;
}
