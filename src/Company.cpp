#include "Company.h"
#include <iostream>
using namespace std;

Company::Company(string n, string a, char t, string v, int d)
    :Customer(n, a, t), vat(v), volumeDiscount(d) {}

Company::~Company() {}
void Company::setVat(string v) {
    vat = v;
}
void Company::setVolumeDiscount(int d) {
    volumeDiscount = d;
}
string Company::getVat() {
    return vat;
}
int Company::getVolumeDiscount() {
    return volumeDiscount;
}

void Company::print() {
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Type: Company" << endl;
    cout << "VAT: " << vat << endl;
    cout << "Volume Discount: " << volumeDiscount << endl;
}

Customer* Company::copy() {
    Customer* cust = new Company(getName(), getAddress(), getType(), getVat(), getVolumeDiscount());
    return cust;
}