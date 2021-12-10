#include "TireCenter.h"
#define ENTER cout << "" << endl

TireCenter::TireCenter(string n, string ad, vector<Article> ar, vector<Customer> c) {
    name = n;
    address = ad;
    articles = ar;
    customers = c;
}
TireCenter::~TireCenter() {}
void TireCenter::setName(string n) {
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

void TireCenter::addCustomer() {
    string n; string a; char t; string v; int d;

    cout << "Enter customer name: " << endl;
    cin >> n;
    cout << n << endl;
    cout << "Enter customer address: " << endl;
    cin >> a;
    cin.ignore();
    cout << "Enter customer type: ";
    cin >> t;
    ENTER;

    if (t == 'p') {
        Customer customer = Customer(n, a, t);
        customers.push_back(customer);
    } else if (t == 'c') {
        cout << "Enter the company VAT: " << endl;
        cin >> v;
        cout << "Enter the volume discount: " << endl;
        cin >> d;
                
        Customer customer = Company(n, a, t, v, d);
        customers.push_back(customer);
    }   

    cout << "Customer added" << endl;
    ENTER;
}

void TireCenter::listCustomers() {
    for (int i = 0; i < size(customers); i++) {
        cout << to_string(i+1) << " " << customers[i].getName() << endl;
    }
    ENTER;
}

void TireCenter::deleteCustomer(int id) {
    customers.erase(customers.begin() + (id-1));
}

void TireCenter::changeCustomer(int id) {
    // 
}