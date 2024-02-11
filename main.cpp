#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void info_izvads(const string& reisu_info) {
    stringstream ss(reisu_info);
    string id_reiss, ceļa_nr, laiks, maršruts;
    getline(ss, id_reiss, ',');
    getline(ss, ceļa_nr, ',');
    getline(ss, laiks, ',');
    getline(ss, maršruts);
    cout << endl;
    cout << "Reisa ID: " << id_reiss << endl;
    cout << "Maršruts: " << maršruts << endl;
    cout << "Ceļa Nr: " << ceļa_nr << endl;
    cout << "Laiks: " << laiks << endl;
}
int main() {
    int ok = 1;
    do{
        string id_darbinieks, rinda;
        cout << "Ievadiet darbinieka ID: ";
        cin >> id_darbinieks;
        cout << "------------------------------------------" << endl;

        ifstream file("dati.txt");
        bool darb_atrasts = false;
        while (getline(file, rinda)) {
            stringstream ss(rinda);
            string id, amats;
            getline(ss, id, ',');
            if (id == id_darbinieks) {
                getline(ss, amats);
                cout << "Darbinieka amats: " << amats << endl;
                darb_atrasts = true;
                while (getline(file, rinda) && !rinda.empty()) {
                    info_izvads(rinda);
                } break;
            }
        }
        if (!darb_atrasts) cout << "Nav ierakstu par doto darbinieku!" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Turpināt (1) | Beigt (0) :";
        cin >> ok;
        cout << endl;
    } while (ok == 1);
    return 0;
}