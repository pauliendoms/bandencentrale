#include <Invoice.h>

Invoice::Invoice(Customer c, vector<Article> a, float p, int d) {
    customer = c;
    articles = a;
    price = p;
    discount = d;
}
Invoice::~Invoice() {}
void setCustomer(Customer c) {
    customer = c;
}
void Invoice::setArticles(vector<Article> a) {
    articles = a;
}
void Invoice::setPrice(float p) {
    price = p;
}
void Invoice::setDiscount(int d) {
    discount = d;
}
Customer Invoice::getCustomer() {
    return customer;
}
vector<Article> Invoice::getArticles() {
    return articles;
}
float Invoice::getPrice() {
    return price;
}
int Invoice::getDiscount() {
    return discount;
}