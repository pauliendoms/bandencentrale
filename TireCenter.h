#include <iostream>
#include <Article.h>
#include <Customer.h>
#include <vector>
using namespace std;

class TireCenter {
    public:
        TireCenter(string n, string ad, vector<Article> ar, vector<Customer> c) {
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
        void setArticles(vector<Article> a) {
            articles = a;
        }
        void setCustomers(vector<Customer> c) {
            customers = c;
        }
        string getName() {
            return name;
        }
        string getAddress() {
            return address;
        }
        vector<Article> getArticles() {
            return articles;
        }
        vector<Customer> getCustomers() {
            return customers;
        }
    private:
        string name;
        string address;
        vector<Article> articles;
        vector<Customer> customers;
};