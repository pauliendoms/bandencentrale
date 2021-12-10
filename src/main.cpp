#include <iostream>
#include "Rim.h"
#include "Customer.h"
#include "Company.h"
#include "TireCenter.h"
#include "Article.h"
#include "Tire.h"
#include <vector>

#define ADMIN "admin"
#define EMPLOYEE "employee"
#define ENTER cout << "" << endl
using namespace std;

vector<Article> articles;
vector<Customer> customers;

TireCenter tirecenter = TireCenter("BadYear", "Bandenstraat 14, Brussel", articles, customers);

string login();
int menu(string);
void customer_functions(string);
void article_functions(string);

int main() {
    string user;
    int keuze = 0;

    user = login();
    while (keuze < 6) {
        keuze = menu(user);

        switch(keuze) {
            case 1:
                customer_functions(user);
                break;
            case 2:
                break;
            case 3:
                break;
        }
    }
    

}

string login() {
    string login;
    cout << "Enter login: ";
    cin >> login;
    cout << "" << endl;
    return login;
}

int menu(string user) {
    int k;

    cout << "Menu: " << endl;
    cout << "1. Customers" << endl;
    cout << "2. Order" << endl;
    cout << "3. Update Stock" << endl;
    cout << "4. Invoices" << endl;
    cout << "5. Articles" << endl;
    cout << "6. Stop" << endl;
    
    ENTER;
    cin >> k;
    ENTER;
    return k;
}

void customer_functions(string user) {
    string n; string a; char t; string v; int d;

    int keuze;
    cout << "1. Search Customer" << endl;
    cout << "2. Add Customer" << endl;
    cout << "3. Change Customer" << endl;
    if (user == ADMIN) {
        cout << "4. Delete Customer" << endl;
    }
    ENTER;
    cin >> keuze;
    ENTER;

    switch(keuze) {
        case 1:
            cout << "zoeken ..." << endl;
            customers = tirecenter.getCustomers();
            for (int i = 0; i < size(customers); i++) {
                cout << customers[i].getName() << endl;
            }
            break;
        case 2:
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
                tirecenter.addCustomer(customer);
            } else if (t == 'c') {
                cout << "Enter the company VAT: " << endl;
                cin >> v;
                cout << "Enter the volume discount: " << endl;
                cin >> d;
                
                Customer customer = Company(n, a, t, v, d);
            }
            break;
        case 3:
            break;
        case 4:
            if (user != ADMIN) {
                keuze = 0;
            } else {
                break;
            }
        default:
            customer_functions(user);
            break;

    }
}

void article_functions(string user) {
    int keuze;
    cout << "1. Search Article" << endl;
    cout << "2. Change Article" << endl;
    if (user == ADMIN) {
        cout << "3. Add Article" << endl;
        cout << "4. Delete Article" << endl;
    }
    ENTER;
    cin >> keuze;
    ENTER;

    switch(keuze) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            if (user != ADMIN) {
                keuze = 0;
            } else {
                break;
            }
        case 4:
            if (user != ADMIN) {
                keuze = 0;
            } else {
                break;
            }
        default:
            customer_functions(user);
            break;

    }
}
