#pragma once
#include "Customer.h"
#include "Article.h"
#include <vector>

class Invoice {
    public:
        Invoice(Customer, vector<Article*>, float, int);
        ~Invoice();
        void setCustomer(Customer);
        void setArticles(vector<Article*>);
        void setPrice(float);
        void setDiscount(int);
        Customer getCustomer();
        vector<Article*> getArticles();
        float getPrice();
        int getDiscount();
    private:
        Customer customer;
        vector<Article*> articles;
        float price;
        int discount;
};