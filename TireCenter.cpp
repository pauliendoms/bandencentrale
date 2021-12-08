#include <TireCenter.h>

TireCenter::TireCenter(string n, string ad, vector<Article> ar, vector<Customer> c) {
    name = n;
    address = ad;
    articles = ar;
    customers = c;
}
TireCenter::~TireCenter() {}
void setName(string n) {
    name = n;
}
void TireCenter::setAddress(string a) {
    address = a;
}
void TireCenter::setArticles(vector<Article> a) {
    articles = a;
}
void TireCenter::setCustomers(vector<Customer> c) {
    customers = c;
}
string TireCenter::getName() {
    return name;
}
string TireCenter::getAddress() {
    return address;
}
vector<Article> TireCenter::getArticles() {
    return articles;
}
vector<Customer> TireCenter::getCustomers() {
    return customers;
}