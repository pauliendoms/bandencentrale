#include "Rim.h"

Rim::Rim(string n, string m, int s, int d, float p, char t, bool a, string c, int w)
    :Article(n, m, s, d, p, t), aluminium(a), color(c), width(w) {}
/*
Rim::Rim(string n, string m, int s, int d, float p, char t, bool a, string c, int w) {
    setName(n);
    setManufacturer(m);
    setStock(s);
    setDiameter(d);
    setPrice(p);
    setType(t);
    aluminium = a;
    color = c;
    width = w;
} */

Rim::~Rim() {}

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