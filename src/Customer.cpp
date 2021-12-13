#include "Customer.h"
#include <iostream>
using namespace std;

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

void Customer::print() {
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Type: Private" << endl;
}