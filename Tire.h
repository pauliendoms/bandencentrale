#include <Article.h>

class Tire: public Article {
    public:
        Tire(string, string, int, int, float, char, int, int, string, char);
        ~Tire() {}
        
        void setWidth(int w);
        void setHeight(int h);
        void setSpeedIndex(string i);
        void setSeason(char s);

        int getWidth();
        int getHeight();
        string getSpeedIndex();
        char getSeason();
    private:
        int width;
        int height;
        string speedIndex;
        char season;
};