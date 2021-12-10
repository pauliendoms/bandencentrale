#include "Customer.h"

Customer::Customer(string n, string a, char t)
    :name(n), address(a), type(t) {}

Customer::~Customer() {}
void Customer::setName(string n) {
    name = n;
}
void Customer::setAddress(string a) {
    address = a;
}
void Customer::setType(char t) {
    type = t;
}
string Customer::getName() {
    return name;
}
string Customer::getAddress() {
    return address;
}
char Customer::getType() {
    return type;
}