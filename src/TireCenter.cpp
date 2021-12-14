#include "TireCenter.h"
#include <algorithm>
#include "Rim.h"
#include "Tire.h"
using namespace std;

#define ENTER cout << "" << endl

TireCenter::TireCenter(string n, string ad, vector<Article*> ar, vector<Customer*> c) {
    name = n;
    address = ad;
    articles = ar;
    customers = c;
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

void TireCenter::addCustomer() {
    string n; string a; char t; string v; int d;

    cout << "Enter customer name: " << endl;
    cin >> n;
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
    cin >> n;
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
    bool a; string c; int w;
    int h; string i; char se;
    Article* article;
    cout << "Enter the name: " << endl;
    cin >> n;
    cout << "Enter manufacturer: " << endl;
    cin >> m;
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
        cin >> a;
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