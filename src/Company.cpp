#include "../include/Company.h"

Company::Company(string n, string a, string v, int d) {
    name = n;
    address = a;
    vat = v;
    volumeDiscount = d;
}
Company::~Company() {}
void setVat(string v) {
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