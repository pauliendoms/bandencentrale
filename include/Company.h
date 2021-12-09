#pragma once
#include "Customer.h"

class Company: public Customer {
    public:
        Company(string, int);
        ~Company();
        void setVat(string);
        void setVolumeDiscount(int);
        string getVat();
        int getVolumeDiscount();
    private:
        string vat;
        int volumeDiscount;
};