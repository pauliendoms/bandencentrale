#include "Invoice.h"

Invoice::Invoice(Customer* c, vector<Article*> a, float p, int d)
    :customer(c), articles(a), price(p), discount(d) {}

Invoice::~Invoice() {}
void Invoice::setCustomer(Customer* c) {
    customer = c;
}
void Invoice::setArticles(vector<Article*> a) {
    articles = a;
}
void Invoice::setPrice(float p) {
    price = p;
}
void Invoice::setDiscount(int d) {
    discount = d;
}
Customer* Invoice::getCustomer() {
    return customer;
}
vector<Article*> Invoice::getArticles() {
    return articles;
}
float Invoice::getPrice() {
    return price;
}
int Invoice::getDiscount() {
    return discount;
}

void Invoice::print() {
    cout << "Customer: " << getCustomer()->getName() << endl;
    cout << "Articles: " << endl;
    for (int i = 0; i < size(articles); i++) {
        cout << i+1 << ": " << articles[i]->getName() << endl;
    }
    cout << "Price: " << getPrice() << endl;
    cout << "Discount: " << getDiscount() << "%" << endl;
    cout << "Total: " << getPrice() - (getDiscount() * getPrice() / 100) << endl;
    cout << "\n\n" << endl;
}