#include "Tire.h"

Tire::Tire(string n, string m, int s, int d, float p, char t, int w, int h, string i, char se) {
    name = n;
    manufacterer = m;
    stock = s;
    diameter = d;
    price = p;
    type = t;
    width = w;
    height = h;
    speedIndex = i;
    season = se;
}
Tire::~Tire() {}
void Tire::setWidth(int w) {
    width = w;
}
void Tire::setHeight(int h) {
    height = h;
}
void Tire::setSpeedIndex(string i) {
    speedIndex = i;
}
void Tire::setSeason(char s) {
    season = s;
}
int Tire::getWidth() {
    return width;
}
int Tire::getHeight() {
    return height;
}
string Tire::getSpeedIndex() {
    return speedIndex;
}
char Tire::getSeason() {
    return season;
}