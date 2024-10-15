#include <iostream>

using namespace std;

int innaffia();
string leggiOperazione();
int pianta(int sel, int piante);
int raccogli(int sel, int piante);
int resetGiardino(int capMax, int umid);
int sole();

int main() {
    int capMax, umid, piante, sel;
    string comando;
    
    cout << "Benvenuto nel pannello di controllo del giardino." << endl;
    cout << "Inserisci la capienza massima di slot disponibili per piantare delle piante: " << endl;
    cin >> capMax;
    cout << "Inserisci l'umidità dalla quale iniziare: " << endl;
    cin >> umid;
    piante = resetGiardino(capMax, umid);
    comando = leggiOperazione();
    while (comando != "X") {
        if (comando == "P") {
            cout << "Inserisci il numero di piante da piantare: " << endl;
            cin >> sel;
            piante = pianta(sel, piante);
            if (piante > capMax) {
                cout << "Il numero di piante che hai scelto da piantare vanno oltre la capienza massima. Sono avanzate " << piante - capMax << " piante." << endl;
                piante = capMax;
            }
            cout << "Piante: " << piante << "/" << capMax << ". Lv Umidità: " << umid << endl;
        } else {
            if (comando == "R") {
                cout << "Inserisci il numero di piante da raccogliere: " << endl;
                cin >> sel;
                piante = raccogli(sel, piante);
                if (piante < 0) {
                    cout << "Il numero di piante che hai scelto di raccogliere vanno oltre la quantità di piante che erano già presenti." << endl;
                    piante = 0;
                }
                cout << "Piante: " << piante << "/" << capMax << ". Lv Umidità: " << umid << endl;
            } else {
                if (comando == "I") {
                    umid = umid + innaffia();
                    cout << "Hai innaffiato il giardino con successo. Livello umidità: " << umid << endl;
                } else {
                    if (comando == "S") {
                        umid = umid - sole();
                        cout << "Il sole ha fatto il suo lavoro. Livello umidità: " << umid << endl;
                    } else {
                        if (comando == "T") {
                            cout << "Hai deciso di resettare il giardino, inserisci la capienza massima di slot disponibili per piantare delle piante: " << endl;
                            cin >> capMax;
                            cout << "Inserisci l'umidità dalla quale iniziare: " << endl;
                            cin >> umid;
                            piante = resetGiardino(capMax, umid);
                        }
                    }
                }
            }
        }
        comando = leggiOperazione();
    }
    cout << "Sei uscito dal programma con successo" << endl;
    return 0;
}

int innaffia() {
    int umid;
    
    umid = 10;
    
    return umid;
}

string leggiOperazione() {
    string comando;
    
    cout << "Inserire un operazione tra i seguenti valori: I P R I S T X " << endl;
    do {
        cin >> comando;
        if (comando != "I" && comando != "P" && comando != "R" && comando != "S" && comando != "T" && comando != "X") {
            cout << "Devi inserire un operazione tra i seguenti valori: I P R I S T X " << endl;
        }
    } while (comando != "I" && comando != "P" && comando != "R" && comando != "S" && comando != "T" && comando != "X");
    
    return comando;
}

int pianta(int sel, int piante) {
    int resto;
    
    resto = sel + piante;
    
    return resto;
}

int raccogli(int sel, int piante) {
    int resto;
    
    resto = piante - sel;
    
    return resto;
}

int resetGiardino(int capMax, int umid) {
    int piante;
    
    piante = 0;
    
    return piante;
}

int sole() {
    int umid;
    
    umid = 10;
    
    return umid;
}
