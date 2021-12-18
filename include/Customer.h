#pragma once
#include <string>
using namespace std;

class Customer {
    public:
        Customer(string, string, char);
        virtual ~Customer();
        
        void setName(string);
        void setAddress(string);
        void setType(char);

        string getName();
        string getAddress();
        char getType();

        virtual void print();
        virtual Customer* copy();
    private:
        string name;
        string address;
        char type;
};