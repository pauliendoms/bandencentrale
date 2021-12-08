#include <Rim.h>

Rim::Rim(string n, string m, int s, int d, float p, char t, boolean a, string c, int w) {
    aluminium = a;
    color = c;
    width = w;
}

Rim::~Rim() {}

void Rim::setColor(string c) {
    color = c;
}

void Rim::setWidth(int w) {
    width = w;
}

boolean Rim::getAluminium() {
    return aluminium;
}

string Rim::getColor() {
    return color;
}

int Rim::getWidth() {
    return width;
}