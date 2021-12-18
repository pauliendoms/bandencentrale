#pragma once
#include "Customer.h"

class Company: public Customer {
    public:
        Company(string, string , char, string, int);
        ~Company();
        void setVat(string);
        void setVolumeDiscount(int);
        string getVat();
        int getVolumeDiscount();

        void print() override;
        Customer* copy() override;
    private:
        string vat;
        int volumeDiscount;
};