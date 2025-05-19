#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

const string namefile = "corsi_studenti.csv";

struct studente{

    string nome, cognome, matr, cod_corso;

};

struct materia{

    string cod_mat, desc_mat, cod_corso;

};

struct corso{

    string cod_cors, decs_corso;

};

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
}

void insVal(vector<studente>& stud, vector<materia>& mat, vector<corso>& cor){

    ifstream fin(namefile);

    string labels;
    string cod_corso, dec_corso, cod_mat, dec_mat, matr, cog, nom;

    getline(fin, labels);

    while(!fin.eof()){

        getline(fin, cod_corso, ',');
        if(cod_corso == "") break;


        getline(fin, dec_corso, ',');
        getline(fin, cod_mat, ',');
        getline(fin, dec_mat, ',');
        getline(fin, matr, ',');
        getline(fin, cog, ',');
        getline(fin, nom);

        studente x = {nom, cog, matr, cod_corso};

        stud.push_back(x);

        materia y = {cod_mat, dec_mat, cod_mat};

        mat.push_back(y);

        corso z = {cod_corso, dec_corso};

        cor.push_back(z);

    }

    fin.close();

}

ostream& operator<<(ostream& out, const studente& s) {
    out << "Nome: " << s.nome << ", Cognome: " << s.cognome << ", Matricola: " << s.matr << ", Codice Corso: " << s.cod_corso;
    return out;
}

ostream& operator<<(ostream& out, const materia& m) {
    out << "Codice Materia: " << m.cod_mat << ", Descrizione: " << m.desc_mat << ", Codice Corso: " << m.cod_corso;
    return out;
}


ostream& operator<<(ostream& out, const corso& c) {
    out << "Codice Corso: " << c.cod_cors << ", Descrizione Corso: " << c.decs_corso;
    return out;
}

string  matPerCorso (string m, vector<studente> stud, vector<corso> cor){

    string cc; // codice corso
    string dc; // descrizine corso

    for (int i=0; i<stud.size(); i++){

        if( stud[i].matr == m){

            cc = stud[i].cod_corso;
            break;
        }
    }

    for (int i=0; i<cor.size(); i++){

        if (cc == cor[i].cod_cors){

            dc = cor[i].decs_corso;
        }

    }

    if (dc != ""){

        return dc;
    }
    else{

        return "corso non trovato";
    }

}

int main()
{

  char op;
  vector<studente> studenti;
  vector<materia> materie;
  vector<corso> corsi;
  string mat;

  menu();
  cout<< "Scelta: ";
  cin>>op;

  while (op != 'X'){

    switch (op){

        case '0':

            insVal(studenti, materie, corsi);

/*            cout<<"studenti"<<endl;
            for (auto elem : studenti){

                cout<<elem<<endl;
            }

            cout<<endl;
            cout<<"materie"<<endl;
            for (auto elem1 : materie){

                cout<<elem1<<endl;
            }
            cout<<"corsi"<<endl;
            for (auto elem2 : corsi){

                cout<<elem2<<endl;

            }
*/
            break;

        case '1':

            cout<<"Inserisci la matricola"<<endl;
            cin>>mat;

            cout<<"Matricola "<< mat <<" : "<< matPerCorso(mat, studenti, corsi)<<endl;

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
