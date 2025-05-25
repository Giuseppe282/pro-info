#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
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
    cout<< "8. Inserisci un nuovo studente" <<endl; // sullo stesso
    cout<< "9. Salva i dati su file" <<endl; // sullo stesso
    cout<< "X. Esci" <<endl;
    cout<< "=================================" <<endl;
}

//0

void insVal(map<string, vector<studente>>& studenti, map<string, vector<materia>>& materie, map<string, vector<corso>>& corsi, string &l){

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

    l = labels;
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

map<string, studente> studPerCor(map<string, vector<studente>> studenti, string cod) {

    map<string, studente> ris;

    if (studenti.find(cod) != studenti.end()) {

        for (auto &s : studenti[cod]) {

            ris[s.matr] = s;  // se uso la matricola i valori non si ripetono perchè magari l'ha già incontrata

        }
    }
    return ris;
}

// 4

map<string, materia> esamPerCorso(map<string, vector<materia>> materie, string cod) {

    map<string, materia> ris;

    // Se il corso esiste nella mappa

    if (materie.find(cod) != materie.end()) {

        for (auto &m : materie[cod]) {

            // Evita duplicati usando il codice materia come chiave
            ris[m.cod_mat] = m;

        }

    }
    return ris;

}

// 5

int numStudPerCor(map<string, vector<studente>> studenti, string cod) {

   int ris;
   map<string, studente> numeStud;

   if (studenti.find(cod) != studenti.end()){

        for(auto &s : studenti[cod]){

            numeStud[s.matr] = s;

        }
   }

   ris = numeStud.size();

   return ris;

}

// 6

int numMatPerCor (map<string, vector<materia>> materie, string cod){

    int ris;
    map<string, materia> numMat;


    if (materie.find(cod) != materie.end()) {

        for (auto &m : materie[cod]) {

            // Evita duplicati usando il codice materia come chiave
            numMat[m.cod_mat] = m;

        }
    }
    ris = numMat.size();
    return ris;
}

// 7

void matPerDesc (map<string, vector<materia>> materie, string s){

    // Trasforma la stringa s in minuscolo
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    set<string> stampati; // per evitare duplicati
    bool trovato = false;

    for (auto& pair : materie) {

        for (auto& m : pair.second) {

            string desc = m.desc_mat;
            transform(desc.begin(), desc.end(), desc.begin(), ::tolower);

            if (desc.find(s) != string::npos) {

                // Se non l'abbiamo già stampata
                if (stampati.find(m.cod_mat) == stampati.end()) {

                    cout << m.cod_mat << ": " << m.desc_mat << endl;
                    stampati.insert(m.cod_mat);
                    trovato = true;

                }
            }
        }
    }

    if (!trovato) {

        cout << "Nessuna materia trovata con"<<" "<< s <<endl;

    }

}

// 8

void insInStr (map<string, vector<studente>>& studenti, map<string, vector<materia>>& materi, map<string, vector<corso>>& corsi, string cod_cor, string des_cor, string cod_mat, string des_mat, string mat_stu, string cog_stu, string nome_stu){

    corso c {cod_cor, des_cor};
    corsi[cod_cor].push_back(c);

    materia m {cod_mat, des_mat, cod_cor};
    materi[cod_cor].push_back(m);

    studente s {nome_stu, cog_stu, mat_stu, cod_cor};
    studenti[cod_cor].push_back(s);

}

// 9

void insInFile (map<string, vector<corso>> corsi, map<string, vector<materia>> materie, map<string, vector<studente>> studenti, string labels){

     ofstream fout (NAMEFILE);

    fout << labels << endl;

    for (auto &pair : corsi) {
        for (auto &c : pair.second) {
            fout << c.cod_cors << DEL << c.decs_corso << endl;
        }
    }

    for (auto &pair : materie) {
        for (auto &m : pair.second) {
            fout << m.cod_mat << DEL << m.desc_mat << endl;
        }
    }

    for (auto &pair : studenti) {
        for (auto &s : pair.second) {
            fout << s.matr << DEL << s.cognome << DEL << s.nome << endl;
        }
    }


    fout.close();

}

int main()
{
  int val, val1;
  char op;
  string mat, cog, cod , cod1, cod2, cod3, desc, labels;
  string cod_cor,des_cor,cod_mat,des_mat,mat_stu,cog_stu,nome_stu;
  map<string, vector<studente>> studenti;
  map<string, vector<materia>> materie;
  map<string, vector<corso>> corsi;
  map<string, studente> stuPerCor;
  map<string, materia> esaPerCor;
  map<string, materia> matDes;

  menu();
  cout<< "Scelta: ";
  cin>>op;

  while (op != 'X'){

    switch (op){

        case '0':

            insVal(studenti, materie, corsi, labels);

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
            cin>>cod;

            stuPerCor = studPerCor(studenti, cod);

            if (stuPerCor.size() != 0){

                cout << "Studenti iscritti al corso " << cod <<endl;

                for (auto &pair : stuPerCor) {

                cout << pair.second.nome << " " << pair.second.cognome << endl;

            }

            }
            else{

                cout<<"Corso non trovato"<<endl;

            }

            break;

        case '4':

            cout<<"Inserici il corso"<<endl;
            cin>>cod1;

            esaPerCor = esamPerCorso(materie, cod1);

            if(esaPerCor.size() != 0){

                cout << "Esami del corso " << cod <<endl;

                for (auto &pair : esaPerCor) {

                    cout << pair.second.cod_mat << ": " << pair.second.desc_mat << endl;
                }

            }

            else{

                cout<<"Corso non trovato"<<endl;

            }

            break;

        case '5':

            cout<<"Inserisci il corso"<<endl;
            cin>>cod2;

            val = numStudPerCor(studenti, cod2);

            if (val != 0){

                cout<<"Il numero di studenti nel corso " << cod2 << " sono " << val <<endl;

            }
            else{

                cout<<"Corso non trovato"<<endl;

            }

            break;

        case '6':

            cout<<"Inserisci il corso"<<endl;
            cin>>cod3;

            val1 = numMatPerCor(materie, cod3);

            if (val1 != 0){

                cout<<"Il numero di materie nel corso " << cod3 << " sono " << val1 <<endl;

            }
            else{

                cout<<"Corso non trovato"<<endl;

            }

            break;

        case '7':

            cout<<"Inserisci il nome del corso"<<endl;
            cin.ignore();
            getline(cin, desc);

            matPerDesc(materie, desc);

            break;

        case '8':

            cod_cor,des_cor,cod_mat,des_mat,mat_stu,cog_stu,nome_stu;

            cout<<"Ins. il codice corso"<<endl;
            cin>>cod_cor;

            cout<<"Ins. la descrizione del corso"<<endl;
            cin>>des_cor;

            cout<<"Ins. il codice materia"<<endl;
            cin>>cod_mat;

            cout<<"Ins. la descrizione della materia"<<endl;
            cin>>des_mat;

            cout<<"Ins. la tricola dello studente"<<endl;
            cin>>mat_stu;

            cout<<"Ins. il cognome dello studente"<<endl;
            cin>>cog_stu;

            cout<<"Inserisci il nome dello studente"<<endl;
            cin>>nome_stu;

            insInStr(studenti, materie, corsi, cod_cor, des_cor, cod_mat, des_mat, mat_stu, cog_stu, nome_stu);

            break;

         case '9':

             insInFile(corsi, materie, studenti, labels);

             cout<<endl;

             cout<<"Informazioni aggiunte"<<endl;

            break;

    }

    cout<<endl;

    menu();
    cout<< "Scelta: " ;
    cin>>op;

  }

  cout<<"Fine";

}
