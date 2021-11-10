#include <iostream>
#include <Customer.h>
#include <Article.h>
using namespace std;

class Invoice {
    public:
        Invoice(Customer c, Article a, float p, int d) {
            customer = c;
            articles = a;
            price = p;
            discount = d;
        }
        ~Invoice() {}
        void setCustomer(Customer c) {
            customer = c;
        }
        void setArticles(Article a) {
            articles = a;
        }
        void setPrice(float p) {
            price = p;
        }
        void setDiscount(int d) {
            discount = d;
        }
    private:
        Customer customer;
        Article articles;
        float price;
        int discount;
};