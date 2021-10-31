#include <iostream>
using namespace std;

void menu();
void stock();
void klanten();
void facturatie();

int main() {

}

void menu() {
    int keuze;

    cout << "Wat wil je doen?" << endl;
    cout << "1. Stock" << endl;
    cout << "2. Klanten" << endl;
    cout << "3. Facturatie" << endl;

    cin >> keuze;

    switch(keuze) {
        case 1:
            stock();
            break;
        case 2:
            klanten();
            break;
        case 3:
            facturatie();
            break;
    }
}

