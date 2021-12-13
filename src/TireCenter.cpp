#include "TireCenter.h"

#define ENTER cout << "" << endl

TireCenter::TireCenter(string n, string ad, vector<Article> ar, vector<Customer*> c) {
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
void TireCenter::setArticles(vector<Article> a) {
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
vector<Article> TireCenter::getArticles() {
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

void TireCenter::listCustomers() {
    for (int i = 0; i < size(customers); i++) {
        cout << to_string(i+1) << " " << customers[i]->getName() << endl;
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