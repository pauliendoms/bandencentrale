#include <iostream>
#include <Customer.h>
#include <Article.h>
#include <vector>
using namespace std;

class Invoice {
    public:
        Invoice(Customer c, vector<Article> a, float p, int d) {
            customer = c;
            articles = a;
            price = p;
            discount = d;
        }
        ~Invoice() {}
        void setCustomer(Customer c) {
            customer = c;
        }
        void setArticles(vector<Article> a) {
            articles = a;
        }
        void setPrice(float p) {
            price = p;
        }
        void setDiscount(int d) {
            discount = d;
        }
        Customer getCustomer() {
            return customer;
        }
        vector<Article> getArticles() {
            return articles;
        }
        float getPrice() {
            return price;
        }
        int getDiscount() {
            return discount;
        }
    private:
        Customer customer;
        vector<Article> articles;
        float price;
        int discount;
};