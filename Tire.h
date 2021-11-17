#include <iostream>
#include <Article.h>
using namespace std;

class Tire: public Article {
    public:
        Tire(int w, int h, string i, char s) {
            width = w;
            height = h;
            speedIndex = i;
            season = s;
        }
        ~Tire() {}
        void setWidth(int w) {
            width = w;
        }
        void setHeight(int h) {
            height = h;
        }
        void setSpeedIndex(string i) {
            speedIndex = i;
        }
        void setSeason(char s) {
            season = s;
        }
        int getWidth() {
            return width;
        }
        int getHeight() {
            return height;
        }
        string getSpeedIndex() {
            return speedIndex;
        }
        char getSeason() {
            return season;
        }
    private:
        int width;
        int height;
        string speedIndex;
        char season;
};