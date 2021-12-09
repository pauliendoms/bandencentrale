#include "Article.h"

Article::Article(string n, string m, int s, int d, float p, char t) {
    name = n;
    manufacturer = m;
    stock = s;
    diameter = d;
    price = p;
    type = t;
}
Article::~Article() {}
void setName(string n) {
    name = n;
}
void Article::setManufacturer(string m) {
    manufacturer = m;
}
void Article::setStock(int s) {
    stock = s;
}
void Article::setDiameter(int d) {
    diameter = d;
}
void Article::setPrice(float p) {
    price = p;
}
void Article::setType(char t) {
    type = t;
}
string Article::getName() {
    return name;
}
string Article::getManufacturer() {
    return manufacturer;
}
int Article::getStock() {
    return stock;
}
int Article::getDiameter() {
    return diameter;
}
float Article::getPrice() {
    return price;
}
char Article::getType() {
    return type;
}