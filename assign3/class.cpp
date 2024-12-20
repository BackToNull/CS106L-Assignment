#include"class.h"

MyClass::MyClass() {}
MyClass::MyClass(int a, int b) {
    x = a;
    y = b;
}
int MyClass::getX() const{
    return x;
}
void MyClass::setX (int a) {
    x = a;
}
void MyClass::addX (int a) {
    x += a;
}