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

vector<Article*> articles;
vector<Customer*> customers;

TireCenter tirecenter = TireCenter("BadYear", "Bandenstraat 14, Brussel", articles, customers);

string login();
int menu();
void customer_functions(string);
void article_functions(string);

int main() {
    string user;
    int keuze = 0;

    user = login();
    while (keuze < 6) {
        cin.ignore();
        keuze = menu();

        switch(keuze) {
            case 1:
                customer_functions(user);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                article_functions(user);
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

int menu() {
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
    string query;
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
            cout << "Enter your search query (0 to show all): " << endl;
            cin >> query;
            tirecenter.searchCustomer(query);
            break;
        case 2:
            tirecenter.addCustomer();
            break;
        case 3:
            cout << "Enter the id of the customer you want to edit: " << endl;
            cin >> keuze;
            ENTER;

            tirecenter.changeCustomer(keuze);

            break;
        case 4:
            if (user != ADMIN) {
                keuze = 0;
            } else {
                cout << "Enter the id of the customer you want to delete: " << endl;
                cin >> keuze;
                tirecenter.deleteCustomer(keuze);
                break;
            }
        default:
            customer_functions(user);
            break;

    }
}

void article_functions(string user) {
    string query;

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
            cout << "Enter query to search article by name (0 to show all): " << endl;
            cin >> query;

            tirecenter.searchArticle(query);
            break;
        case 2:
            cout << "Enter the id of the article you want to change: " << endl;
            cin >> keuze;
            ENTER;

            tirecenter.changeArticle(keuze);
            break;
        case 3:
            if (user != ADMIN) {
                keuze = 0;
            } else {
                tirecenter.addArticle();
                break;
            }
        case 4:
            if (user != ADMIN) {
                keuze = 0;
            } else {
                cout << "Enter the id of the article you want to delete: " << endl;
                cin >> keuze;
                ENTER;

                tirecenter.deleteArticle(keuze);
                break;
            }
        default:
            customer_functions(user);
            break;

    }
}
