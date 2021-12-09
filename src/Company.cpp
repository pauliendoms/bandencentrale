#include "Company.h"
Company::Company(string n, string a, char t, string v, int d)
    :Customer(n, a, t), vat(v), volumeDiscount(d) {}
/*
Company::Company(string n, string a, char t, string v, int d) {
    setName(n);
    setAddress(a);
    setType(t);
    vat = v;
    volumeDiscount = d;
}*/
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