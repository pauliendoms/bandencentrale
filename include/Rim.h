#pragma once
#include "Article.h"

class Rim: public Article {
    public:
        Rim(string, string, int, int, float, char, bool, string, int);
        ~Rim();
        void setAluminium(bool);
        void setColor(string);
        void setWidth(int);
        bool getAluminium();
        string getColor();
        int getWidth();
    private:
        bool aluminium;
        string color;
        int width;
};