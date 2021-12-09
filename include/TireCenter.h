#pragma once
#include "Article.h"
#include "Customer.h"
#include <vector>

class TireCenter {
    public:
        TireCenter(string, string, vector<Article>, vector<Customer>);
        ~TireCenter();

        void setName(string);
        void setAddress(string);r<Article>;
        void setCustomers(vector<Customer>);

        string getName();
        string getAddress();
        vector<Article> getArticles();
        vector<Customer> getCustomers();
    private:
        string name;
        string address;
        vector<Article> articles;
        vector<Customer> customers;
};