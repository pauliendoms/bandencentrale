#include <iostream>
using namespace std;

class Customer {
    public:
        Customer(string n, string a, char t) {
            name = n;
            address = a;
            type = t;
        }
        ~Customer() {}
        void setName(string n) {
            name = n;
        }
        void setAddress(string a) {
            address = a;
        }
        void setType(char t) {
            type = t;
        }
        string getName() {
            return name;
        }
        string getAddress() {
            return address;
        }
        char getType() {
            return type;
        }
    private:
        string name;
        string address;
        char type;
};