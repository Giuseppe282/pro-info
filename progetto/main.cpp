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

//0

void insVal(map<string, vector<studente>>& studenti, map<string, vector<materia>>& materie, map<string, vector<corso>>& corsi){

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

//1

string corPerMat(map<string, vector<studente>> studenti, map<string, vector<corso>> corsi, string mat){

    string ris;

    map<string, string> matrPerCod;

    for (auto &pair : studenti){

        for (auto &s : pair.second){

            if (s.matr == mat){

               matrPerCod[mat] = s.cod_corso;
               break;

            }
        }
    }

    for (auto &pair : corsi){

        for (auto &c : pair.second){

            if (c.cod_cors == matrPerCod[mat]){

                ris = c.decs_corso;
            }
        }

    }

    if(ris != ""){
        return ris;
    }
    else{
        return "Matricola non trovata";
    }

}

// 2

string corPerCog (map<string, vector<studente>> studenti, map<string, vector<corso>> corsi, string cog){

    string ris;

    map<string, string> cognPerCod;

    for (auto &pair : studenti){

        for (auto &s : pair.second){

            if (s.cognome == cog){

               cognPerCod[cog] = s.cod_corso;
               break;

            }
        }
    }

    for (auto &pair : corsi){

        for (auto &c : pair.second){

            if (c.cod_cors == cognPerCod[cog]){

                ris = c.decs_corso;
            }
        }

    }

    if(ris != ""){
        return ris;
    }
    else{
        return "Matricola non trovata";
    }


}

// 3

void studPerCor (map<string, vector<studente>> studenti, map<string, vector<corso>> corsi, string cor){

    string cc;

    map<string, vector<studente>> studCor;
    map<string, vector<studente>> ap;

    for (auto &pair : corsi){

        for (auto &c : pair.second){

            if (c.cod_cors == cor){

                cc = c.cod_cors;
                break;
            }
        }

    }

    for (auto &pair : studenti){

        for (auto &s : pair.second){

             if (s.cod_corso == cc) {
                studCor[cc].push_back(s);
            }
        }
    }

   for (auto &pair : studenti){

        for (auto &s : pair.second){

            cout<<"Corso "<<cor<<" ";cout<<"Studente "<<s.nome<<" "<<s.cognome<<endl;
        }
    }

}

int main()
{

  char op;
  string mat, cog, cor;
  map<string, vector<studente>> studenti;
  map<string, vector<materia>> materie;
  map<string, vector<corso>> corsi;

  menu();
  cout<< "Scelta: ";
  cin>>op;

  while (op != 'X'){

    switch (op){

        case '0':

            insVal(studenti, materie, corsi);

            cout<<"Caricamento fatto!"<<endl;

            break;

        case '1':

            cout<<"Inserisci la matricola"<<endl;
            cin>>mat;

            cout<<"Matricola : "<<mat<<" Corso "<<corPerMat(studenti, corsi, mat)<<endl;

            break;

        case '2':

            cout<<"Inserisci il cognome"<<endl;
            cin>>cog;

            cout<<"Cognome : "<<cog<<" Corso : "<<corPerCog(studenti, corsi, cog)<<endl;

            break;

        case '3':

            cout<<"Inserici il corso"<<endl;
            cin>>cor;

            studPerCor(studenti, corsi, cor);

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
