#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void darbinieku_reisi() {
    ifstream file("dati.txt");
    if (!file) {
        cout << "Sistēmas kļūda, pamēģiniet vēlreiz  vēlāk!" << endl;
        return;
    }

    bool darb_atrasts = false;
    string rinda, id_darbinieks;

    cout << "Ievadiet darbinieka ID: ";
    cin >> id_darbinieks;
    cout << "------------------------------------------" << endl;

    while (getline(file, rinda)) {
        stringstream ss(rinda);
        string id, amats;
        getline(ss, id, ',');

        if (id == id_darbinieks) {
            getline(ss, amats);
            cout << "Darbinieka amats: " << amats << endl;
            darb_atrasts = true;

            while (getline(file, rinda) && !rinda.empty()) {
                stringstream sstream(rinda);
                string id_reiss, ceļa_nr, laiks, maršruts_no, maršruts_uz;
                getline(sstream, id_reiss, ',');
                getline(sstream, ceļa_nr, ',');
                getline(sstream, laiks, ',');
                getline(sstream, maršruts_no, ',');
                getline(sstream, maršruts_uz, ',');
                cout << endl;
                cout << "Reisa ID: " << id_reiss << endl;
                cout << "Maršruts: " << maršruts_no << " - " << maršruts_uz << endl;
                if (maršruts_no == " Rīga") {
                    cout << "Ceļa Nr: " << ceļa_nr << endl;
                }
                cout << "Laiks: " << laiks << endl;
            }
            break;
        }
    }
    if (!darb_atrasts) cout << "Nav ierakstu par doto darbinieku!" << endl;
}

int main() {
    string ok = "1";
    do {
        darbinieku_reisi();
        cout << "------------------------------------------" << endl;
        cout << "Turpināt (1) | Beigt (0) :";
        cin >> ok;
        while (ok != "0" && ok != "1") {
            cout << "Kļūda! Lūdzu ievadiet 1, lai turpinātu, vai 0, lai beigtu.\n" << endl;
            cout << "Turpināt (1) | Beigt (0) :";
            cin >> ok;
        };
        cout << endl;
    } while (ok == "1");
    return 0;
}

// Piemēri
//////////////////////////////////////////////
//Ievadiet darbinieka ID: 1001
// ------------------------------------------
// Darbinieka amats:  mašinists

// Reisa ID: 009
// Maršruts:  Aizkraukle -  Rīga
// Laiks:  19/02/2024 8:42

// Reisa ID: 204
// Maršruts:  Rīga -  Aizkraukle
// Ceļa Nr:  4
// Laiks:  19/02/2024 12:24
// ------------------------------------------
//////////////////////////////////////////////
// Ievadiet darbinieka ID: 1002
// ------------------------------------------
// Darbinieka amats:  kontrolieris

// Reisa ID: 009
// Maršruts:  Aizkraukle -  Rīga
// Laiks:  21/02/2024 8:42
// ------------------------------------------
//////////////////////////////////////////////
// Ievadiet darbinieka ID: 1003
// ------------------------------------------
// Nav ierakstu par doto darbinieku!
// ------------------------------------------