#include <iostream>
#include <Customer.h>
using namespace std;

class Company: public Customer {
    public:
        Company(string v, int d) {
            vat = v;
            volumeDiscount = d;
        }
        ~Company() {}
        void setVat(string v) {
            vat = v;
        }
        void setVolumeDiscount(int d) {
            volumeDiscount = d;
        }
        string getVat() {
            return vat;
        }
        int getVolumeDiscount() {
            return volumeDiscount;
        }
    private:
        string vat;
        int volumeDiscount;
};