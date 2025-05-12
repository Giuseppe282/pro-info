#include <iostream>
#include <vector>
#include <map>
using namespace std;

string namefile = "corsi_studenti.csv";

// menù

struct studente{

    string nome, cognome, matr, cod_corso;

};

struct materia{

    string cod_mat, desc_mat, cod_corso;

};

struct corso{

    string cod_cors, decs_corso;

};

void menu(){

    cout<< "==== GESTIONE UNIVESITARIA ====" <<endl;
    cout<< "0. Carica dati file" <<endl;
    cout<< "1. Cerca corsi di uno studente (matricola)" <<endl;
    cout<< "2. Cerca corsi di uno studente (cognome)" <<endl;
    cout<< "3. Elenca studenti iscritti di un corso" <<endl;
    cout<< "4. Stampa dati esami di un corso" <<endl;
    cout<< "5. Numero di studenti per corso" <<endl;
    cout<< "6. Numero di materie per corso" <<endl;
    cout<< "7. Cerca materie per descrizione" <<endl;
    cout<< "8. Inserisci un nuovo studente" <<endl;
    cout<< "9. Salva i dati su file" <<endl;
    cout<< "X. Esci" <<endl;
}


int main()
{

  char op;
  vector<studente>;
  vector<materia>;
  vector<corso>;

  menu();
  cout<< "Scelta: ";
  cin>>op;

  while (op != 'X'){

    switch (op){

        case '1':

            ins(namefile);

            break;

        case '2':

            break;

        case '3':

            break;

        case '4':

            break;

        case '5':

            break;

        case '6':

            break;

        case '7':

            break;

        case '8':

            break;

        case '9':

            break;



    }


    menu();
    cout<< "Scelta: " ;
    cin>>op;
  }

  cout<<"Fine";


}
