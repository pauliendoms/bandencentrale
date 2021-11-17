#include <iostream>
#define ADMIN "admin"
#define EMPLOYEE "employee"
#define ENTER cout << "" << endl
using namespace std;

string login();
int menu(string);
void customers(string);
void articles(string);

int main() {
    string user;
    int keuze;

    user = login();
    keuze = menu(user);

    switch(keuze) {
        case 1:
            customers(user);
            break;
        case 2:
            break;
        case 3:
            break;
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
    int keuze;

    cout << "Menu: " << endl;

    if (user == ADMIN) {
        cout << "1. Customers" << endl;
        cout << "2. Order" << endl;
        cout << "3. Update Stock" << endl;
        cout << "4. Invoices" << endl;
        cout << "5. Articles" << endl;
    } else if (user == EMPLOYEE) {
        cout << "1. Customers" << endl;
        cout << "2. Order" << endl;
        cout << "3. Update Stock" << endl;
        cout << "4. Invoices" << endl;
        cout << "5. Articles" << endl;
    }
    
    ENTER;
    cin >> keuze;
    ENTER;
    return keuze;
}

void customers(string user) {
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
            break;
        case 2:
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
            customers(user);
            break;

    }
}

void articles(string user) {
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
            customers(user);
            break;

    }
}
