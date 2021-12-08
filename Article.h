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
        string getManufacturer();
        int getStock();
        int getDiameter();
        float getPrice();
        char getType();
    private:
        string name;
        string manufacturer;
        int stock;
        int diameter;
        float price;
        char type;
};