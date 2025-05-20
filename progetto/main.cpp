#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

const string NAMEFILE = "corsi_studenti.csv";
const char DEL = ',';

struct studente{

    string nome, cognome, matr, cod_corso;

};

struct materia{

    string cod_mat, desc_mat, cod_corso;

};

struct corso{

    string cod_cors, decs_corso;

};

map<string, vector<studente>> studenti;
map<string, vector<materia>> materie;
map<string, vector<corso>> corsi;

// menù
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
    cout<< "=================================" <<endl;
}

void insVal(){

    ifstream fin(NAMEFILE);

    string labels;
    string cod_corso, dec_corso, cod_mat, dec_mat, matr, cog, nom;

    getline(fin, labels);

    while(!fin.eof()){

        getline(fin, cod_corso, DEL);
        if(cod_corso == "") break;


        getline(fin, dec_corso, DEL);
        getline(fin, cod_mat, DEL);
        getline(fin, dec_mat, DEL);
        getline(fin, matr, DEL);
        getline(fin, cog, DEL);
        getline(fin, nom);


        studente x {nom, cog, matr, cod_corso};
        studenti[cod_corso].push_back(x);

        materia y {cod_mat, dec_mat, cod_corso};
        materie[cod_corso].push_back(y);

        corso z {cod_corso, dec_corso};
        corsi[cod_corso].push_back(z);



    }

    fin.close();

}


int main()
{

  char op;

  string mat;

  menu();
  cout<< "Scelta: ";
  cin>>op;

  while (op != 'X'){

    switch (op){

        case '0':

            insVal();

            cout<<"Caricamento fatto!"<<endl;

            break;

        case '1':

            cout<<"Inserisci la matricola"<<endl;
            cin>>mat;



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

    cout<<endl;

    menu();
    cout<< "Scelta: " ;
    cin>>op;

  }

  cout<<"Fine";


}
