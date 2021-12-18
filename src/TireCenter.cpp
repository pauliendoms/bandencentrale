#include "TireCenter.h"
#include <algorithm>
#include "Rim.h"
#include "Tire.h"
using namespace std;

#define ENTER cout << "" << endl;

TireCenter::TireCenter(string n, string ad, vector<Article*> ar, vector<Customer*> c, vector<Invoice> i) {
    name = n;
    address = ad;
    articles = ar;
    customers = c;
    invoices = i;
}
TireCenter::~TireCenter() {
    for (Customer* customer : this->customers) {
        delete customer;
    }
}
void TireCenter::setName(string n) {
    name = n;
}
void TireCenter::setAddress(string a) {
    address = a;
}
void TireCenter::setArticles(vector<Article*> a) {
    articles = a;
}
void TireCenter::setCustomers(vector<Customer*> c) {
    customers = c;
}
void TireCenter::setInvoices(vector<Invoice> i) {
    invoices = i;
}
string TireCenter::getName() {
    return name;
}
string TireCenter::getAddress() {
    return address;
}
vector<Article*> TireCenter::getArticles() {
    return articles;
}
vector<Customer*> TireCenter::getCustomers() {
    return customers;
}
vector<Invoice> TireCenter::getInvoices() {
    return invoices;
}

void TireCenter::addCustomer() {
    string n; string a; char t; string v; int d;

    cout << "Enter customer name: " << endl;
    getline(cin, n);
    cout << "Enter customer address: " << endl;
    cin >> a;
    cin.ignore();
    cout << "Enter customer type: ";
    cin >> t;
    ENTER;

    if (t == 'p') {
        Customer* customer = new Customer(n, a, t);
        customers.push_back(customer);
    } else if (t == 'c') {
        cout << "Enter the company VAT: " << endl;
        cin >> v;
        cout << "Enter the volume discount: " << endl;
        cin >> d;

        Customer* customer = new Company(n, a, t, v, d);
        customers.push_back(customer);
        ENTER;
    }   

    cout << "Customer added" << endl;
    ENTER;
}

void TireCenter::listCustomers(vector<Customer*> list) {
    for (int i = 0; i < size(list); i++) {
        cout << to_string(customerIndex(list[i])+1) << " " << list[i]->getName() << endl;
    }
    ENTER;
}

void TireCenter::deleteCustomer(int id) {
    customers.erase(customers.begin() + (id-1));
    delete customers[id-1];
}

void TireCenter::changeCustomer(int id) {
    string n; string a; char t; string v; int d; char x;
    Customer* cust = customers[id-1];
    cust->print();
    ENTER;

    cout << "Enter x if you don't want to make a change." << endl;
    ENTER;

    cout << "Enter customer name: " << endl;
    getline(cin, n);
    if (n != "x") {
        cust->setName(n);
    }

    cout << "Enter customer address: " << endl;
    cin >> a;
    cin.ignore();

    if (a != "x") {
        cust->setAddress(a);
    }

    cout << "Enter customer type: ";
    cin >> t;

    if (t != 'x') {
        cust->setType(t);
    }

    ENTER;

    if (cust->getType() == 'c') {
        Company* comp = dynamic_cast<Company*>(cust);
        cout << "Enter the company VAT: " << endl;
        cin >> v;
        if (v != "x") {
            comp->setVat(v);
        }
        cout << "Enter the volume discount: " << endl;
        cin >> x;
        
        if (x != 'x') {
            d = int(x);
            comp->setVolumeDiscount(d);
        } 
    
        comp->setVolumeDiscount(d);

        Customer* customer = new Company(n, a, t, v, d);
        customers.push_back(customer);
        ENTER;
    }   

    cout << "Customer added" << endl;
    
    ENTER;
}

void TireCenter::searchCustomer(string zoekterm) {
    string name;
    vector<Customer*> results;
    int index;

    // bron: https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
    transform(zoekterm.begin(), zoekterm.end(), zoekterm.begin(),
    [](unsigned char c){ return tolower(c); });

    if (zoekterm == "0") {
        listCustomers(customers);
    } else {
        for (int i = 0; i < size(customers); i++) {
            name = customers[i]->getName();

            transform(name.begin(), name.end(), name.begin(),
            [](unsigned char c){ return tolower(c); });

            if (name.find(zoekterm) != string::npos) {
                results.push_back(customers[i]);
            }
        }
    }

    listCustomers(results);

    cout << "Enter index of customer you want to view (0 to cancel): " << endl;
    cin >> index;

    if (index != 0) {
        ENTER;
        customers[index-1]->print();
        ENTER;
    }
}

int TireCenter::customerIndex(Customer* cust) {
    // bron: https://www.geeksforgeeks.org/how-to-find-index-of-a-given-element-in-a-vector-in-cpp/
    auto i = find(customers.begin(), customers.end(), cust);

    int index = i - customers.begin();

    return index;  
}

void TireCenter::addArticle() {
    string n; string m; int s; int d; float p; char t;
    bool a; string c; int w; string boolean;
    int h; string i; char se;
    Article* article;
    cin.ignore();
    cout << "Enter the name: " << endl;
    getline(cin, n);
    cout << "Enter manufacturer: " << endl;
    getline(cin, m);
    cout << "Enter stock: " << endl;
    cin >> s;
    cout << "Enter diameter: " << endl;
    cin >> d;
    cout << "Enter price: " << endl;
    cin >> p;
    cout << "Enter type: " << endl;
    cin >> t;

    if (t == 'r') {
        cout << "Enter aluminium (true or false): " << endl;
        cin >> boolean;
        if (boolean == "true") {a = true;} else if (boolean == "false") {a=false;};
        cout << "Enter color: " << endl;
        cin >> c;
        cout << "Enter width: " << endl;
        cin >> w;

        article = new Rim(n, m, s, d, p, t, a, c, w);
    } else if (t == 't') {
        cout << "Enter width: " << endl;
        cin >> w;
        cout << "Enter height: " << endl;
        cin >> h;
        cout << "Enter speed index: " << endl;
        cin >> i;
        cout << "Enter season: " << endl;
        cin >> se;

        article = new Tire(n, m, s, d, p, t, w, h, i, se);
    }

    articles.push_back(article);
}

void TireCenter::listArticles(vector<Article*> list) {
    for (int i = 0; i < size(list); i++) {
        cout << to_string(articleIndex(list[i])+1) << " " << list[i]->getName() << endl;
    }
    ENTER;
}

int TireCenter::articleIndex(Article* art) {
    auto i = find(articles.begin(), articles.end(), art);

    int index = i - articles.begin();

    return index;
}

void TireCenter::deleteArticle(int id) {
    articles.erase(articles.begin() + (id -1));
    delete articles[id-1];
}

void TireCenter::changeArticle(int id) {
    string n; string m; int s; int d; float p; char t;
    int w; int h; string i; char se;
    string a; string c;
    char x;  
    Article* art = articles[id-1];
    art->print();
    ENTER;

    cout << "Enter x if you don't want to make a change." << endl;
    ENTER;
    cin.ignore();
    cout << "Enter article name: " << endl;
    getline(cin, n);
    if (n != "x") {
        art->setName(n);
    }

    cout << "Enter manufacturer: " << endl;
    getline(cin, m);

    if (m != "x") {
        art->setManufacturer(m);
    }

    cout << "Enter stock: " << endl;
    cin >> x;

    if (x != 'x') {
        s = int(x);
        art->setStock(s);
    }

    cout << "Enter diameter: " << endl;
    cin >> x;

    if (x != 'x') {
        d = int(x);
        art->setDiameter(d);
    }

    cout << "Enter price: " << endl;
    cin >> n;

    if (n != "x") {
        p = stof(n);
        art->setPrice(p);
    }

    cout << "Enter type: " << endl;
    cin >> t;

    if (t != 'x') {
        art->setType(t);
    }

    ENTER;

    if (art->getType() == 't') {
        Tire* tire = dynamic_cast<Tire*>(art);
        cout << "Enter width: " << endl;
        cin >> x;
        if (x != 'x') {
            w = int(x);
            tire->setWidth(w);
        }
        cout << "Enter height: " << endl;
        cin >> x;
        
        if (x != 'x') {
            h = int(x);
            tire->setHeight(h);
        } 

        cout << "Enter speed Index: " << endl;
        cin >> i;

        if (i != "x") {
            tire->setSpeedIndex(i);
        }

        cout << "Enter season: " << endl;
        cin >> se;

        if (se != 'x') {
            tire->setSeason(se);
        }

        ENTER;

    } else if (art->getType() == 'r') {
        Rim* rim = dynamic_cast<Rim*>(art);
        
        cout << "Enter aluminium (true or false): " << endl;
        cin >> a;
        if (a == "true") {
            rim->setAluminium(true);
        } else if (a == "false") {
            rim->setAluminium(false);
        }

        cout << "Enter color: " << endl;
        cin >> c;
        
        if (c != "x") {
            rim->setColor(c);
        }

        cout << "Enter width: " << endl;
        cin >> x;
        if (x != 'x') {
            w = int(x);
            rim->setWidth(w);
        }
    }

    cout << "Article added" << endl;
    
    ENTER;
}

void TireCenter::searchArticle(string zoekterm) {

    string name;
    vector<Article*> results;
    int index;
    char x;

    transform(zoekterm.begin(), zoekterm.end(), zoekterm.begin(),
    [](unsigned char c){ return tolower(c); });
    
    if (zoekterm == "0") {
        for (int i = 0; i < size(articles); i++) {
            results.push_back(articles[i]);
        }
    } else {
        for (int i = 0; i < size(articles); i++) {
            name = articles[i]->getName();

            transform(name.begin(), name.end(), name.begin(),
            [](unsigned char c){ return tolower(c); });

            if (name.find(zoekterm) != string::npos) {
                results.push_back(articles[i]);
            }
        }
    }

    listArticles(results);

    cout << "Apply filter, enter 'r' for Rim and 't' for Tire, 'x' for no filter: " << endl;
    cin >> x;

    for (int j = 0; j < size(results); j++) {
        if (results[j]->getType() != x && x != 'x') {
            results.erase(results.begin() + j);
        }
    }

    listArticles(results);

    cout << "Enter index of article you want to view (0 to cancel): " << endl;
    cin >> index;

    if (index != 0) {
        ENTER;
        articles[index-1]->print();
        ENTER;
    }

}

void TireCenter::updateStock(int id) {
    int stock;

    cout << "Enter updated amount of stock: " << endl;
    cin >> stock;

    articles[id-1]->setStock(stock);
}

void TireCenter::order() {
    string query;
    int customer_id;
    int article_id;
    int amount;
    vector<Article*> article_list = {};
    vector<int> amounts = {};
    int keuze = 1;
    bool check_order = true;

    cout << "Use this search function to find the customer id." << endl;

    cout << "Enter your search query (0 to show all): " << endl;
    cin >> query;
    searchCustomer(query);

    cout << "Enter the customer id: " << endl;
    cin >> customer_id;

    while (keuze) {
        cout << "Use this search function to find the article's id." << endl;

        cout << "Enter query to search article by name (0 to show all): " << endl;
        cin >> query;

        searchArticle(query);

        cout << "Enter the id of the article you want to add to the order: " << endl;
        cin >> article_id;

        article_list.push_back(articles[article_id - 1]);

        cout << "Enter the amount of the article you want (tires = per 2; rims = per 4): " << endl;
        cin >> amount;

        amounts.push_back(amount);

        cout << "Do you want to add another article? (1 for yes, 0 for no);" << endl;
        cin >> keuze;
    }

    for (int j = 0; j < size(article_list); j++) {
        if ((article_list[j]->getStock() - amounts[j]) < 0) {
            check_order = false;
        }
    }

    if (check_order) {
        for (int i = 0; i < size(article_list); i++) {
            article_list[i]->setStock(article_list[i]->getStock() - amounts[i]);
        }

        addInvoice(customer_id, article_list, amounts);
    } else {
        cout << "The order is cancelled, not enough items in stock for this order." << endl;
    }



}

void TireCenter::addInvoice(int customer_id, vector<Article*> article_list, vector<int> amounts) {
    float price = 0.0;
    int discount;
    char customer_type = customers[customer_id-1]->getType();
    int sets = 0;
    int banden_sets = 0;
    int velgen_sets = 0;

    for (int i = 0; i < size(article_list); i++) {
        price += article_list[i]->getPrice() * amounts[i];
    }

    if (customer_type == 'c') {
        for (int j = 0; j < size(amounts); j++) {
            sets += amounts[j] / 4;
        }
        
        // 10 procent korting per 10 sets
        discount = 10 * (sets / 10);
    } else {
        // 5 procent korting voor een individueel set, 15% voor een set banden + velgen
        for (int k = 0; k < size(article_list); k++) {
            if (article_list[k]->getType() == 't') {
                banden_sets += amounts[k] / 4;
            } else {
                velgen_sets += amounts[k] / 4;
            }
        }

        if (banden_sets > velgen_sets) {
            discount = (15 * ((banden_sets + velgen_sets) - (banden_sets - velgen_sets)) / 2) + (5 * (banden_sets - velgen_sets));
        } else {
            discount = (15 * ((banden_sets + velgen_sets) - (velgen_sets - banden_sets)) / 2) + (5 * (velgen_sets - banden_sets));
        }
    }

    
    
    
}