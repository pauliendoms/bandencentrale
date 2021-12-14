#pragma once
#include "Article.h"
#include "Customer.h"
#include "Company.h"
#include <vector>

class TireCenter {
    public:
        TireCenter(string, string, vector<Article*>, vector<Customer*>);
        ~TireCenter();

        void setName(string);
        void setAddress(string);
        void setArticles(vector<Article*>);
        void setCustomers(vector<Customer*>);

        string getName();
        string getAddress();
        vector<Article*> getArticles();
        vector<Customer*> getCustomers();

        void addCustomer();
        void listCustomers(vector<Customer*>);
        void deleteCustomer(int);
        void changeCustomer(int);
        void searchCustomer(string);
        int customerIndex(Customer*);

        void addArticle();
    private:
        string name;
        string address;
        vector<Article*> articles;
        vector<Customer*> customers;
};