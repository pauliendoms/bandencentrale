#include <iostream>
#include <Article.h>
using namespace std;

class Rim: public Article {
    public:
        Rim(boolean a, string c, int w) {
            aluminium = a;
            color = c;
            width = w;
        }
        ~Rim() {}
        void setAluminium(boolean a) {
            aluminium = a;
        }
        void setColor(string c) {
            color = c;
        }
        void setWidth(int w) {
            width = w;
        }
        boolean getAluminium() {
            return aluminium;
        }
        string getColor() {
            return color;
        }
        int getWidth() {
            return width;
        }
    private:
        boolean aluminium;
        string color;
        int width;
};