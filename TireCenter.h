#include <iostream>
#include <Article.h>
#include <Customer.h>
using namespace std;

class TireCenter {
    public:
        TireCenter(string n, string ad, Article ar, Customer c) {
            name = n;
            address = ad;
            articles = ar;
            customers = c;
        }
        ~TireCenter() {}
        void setName(string n) {
            name = n;
        }
        void setAddress(string a) {
            address = a;
        }
        void setArticles(Article a) {
            articles = a;
        }
        void setCustomers(Customer c) {
            customers = c;
        }
        string getName() {
            return name;
        }
        string getAddress() {
            return address;
        }
        Article getArticles() {
            return articles;
        }
        Customer getCustomers() {
            return customers;
        }
    private:
        string name;
        string address;
        Article articles;
        Customer customers;
};