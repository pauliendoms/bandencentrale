#include <Article.h>

class Rim: public Article {
    public:
        Rim(string, string, int, int, float, char, boolean, string, int);
        ~Rim();
        void setAluminium(boolean);
        void setColor(string);
        void setWidth(int);
        boolean getAluminium();
        string getColor();
        int getWidth();
    private:
        boolean aluminium;
        string color;
        int width;
};