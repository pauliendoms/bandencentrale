#include <iostream>
using namespace std;

string login();
int menu(string);

int main() {
    string user;
    int keuze;

    user = login();
    keuze = menu(user);

    switch(keuze) {
        case 1:
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

    cout << "Wat wil je doen?" << endl;

    if (user == "admin") {
        cout << "1. Customers" << endl;
        cout << "2. Order" << endl;
        cout << "3. Update Stock" << endl;
        cout << "4. Invoices" << endl;
        cout << "5. Articles" << endl;
    } else if (user == "employee") {
        cout << "1. Customers" << endl;
        cout << "2. Order" << endl;
        cout << "3. Update Stock" << endl;
        cout << "4. Invoices" << endl;
        cout << "5. Articles" << endl;
    }

    cin >> keuze;
    return keuze;
}

