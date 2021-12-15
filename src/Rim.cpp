#include "Rim.h"

Rim::Rim(string n, string m, int s, int d, float p, char t, bool a, string c, int w)
    :Article(n, m, s, d, p, t), aluminium(a), color(c), width(w) {}

Rim::~Rim() {}

void Rim::setAluminium(bool a) {
    aluminium = a;
}

void Rim::setColor(string c) {
    color = c;
}

void Rim::setWidth(int w) {
    width = w;
}

bool Rim::getAluminium() {
    return aluminium;
}

string Rim::getColor() {
    return color;
}

int Rim::getWidth() {
    return width;
}

void Rim::print() {
    cout << "Name: " << getName() << endl;
    cout << "Manufacturer: " << getManufacturer() << endl;
    cout << "Stock: " << getStock() << endl;
    cout << "Diameter: " << getDiameter() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Type: " << getType() << endl;
    cout << "Aluminium: " << aluminium << endl;
    cout << "Color: " << color << endl;
    cout << "Width: " << width << endl;
}
