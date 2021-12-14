#pragma once
#include <iostream>
using namespace std;

class Article {
    public:
        Article(string, string, int, int, float, char);
        ~Article();
        
        void setName(string);
        void setManufacturer(string);
        void setStock(int);
        void setDiameter(int);
        void setPrice(float);
        void setType(char);

        string getName();
        virtual string getManufacturer();
        int getStock();
        int getDiameter();
        float getPrice();
        char getType();

        virtual void print() = 0;
    private:
        string name;
        string manufacturer;
        int stock;
        int diameter;
        float price;
        char type;
};