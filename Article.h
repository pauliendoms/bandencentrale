#include <iostream>
using namespace std;

class Article {
    public:
        void setName(string n) {
            name = n;
        }
        void setManufacturer(string m) {
            manufacturer = m;
        }
        void setStock(int s) {
            stock = s;
        }
        void setDiameter(int d) {
            diameter = d;
        }
        void setPrice(float p) {
            price = p;
        }
        void setType(char t) {
            type = t;
        }
        string getName() {
            return name;
        }
        string getManufacturer() {
            return manufacturer;
        }
        int getStock() {
            return stock;
        }
        int getDiameter() {
            return diameter;
        }
        float getPrice() {
            return price;
        }
        char getType() {
            return type;
        }
    private:
        string name;
        string manufacturer;
        int stock;
        int diameter;
        float price;
        char type;
};