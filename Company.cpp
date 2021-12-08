#include <Company.h>

Company::Company(string v, int d) {
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