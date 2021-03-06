#pragma once
#include "Article.h"

class Tire: public Article {
    public:
        Tire(string, string, int, int, float, char, int, int, string, char);
        ~Tire();
        
        void setWidth(int w);
        void setHeight(int h);
        void setSpeedIndex(string i);
        void setSeason(char s);

        int getWidth();
        int getHeight();
        string getSpeedIndex();
        char getSeason();

        void print() override;
        Article* copy() override;
    private:
        int width;
        int height;
        string speedIndex;
        char season;
};