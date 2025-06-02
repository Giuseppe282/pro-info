#include "FunzCSV.h"
using namespace std;

int main()
{
  int val, val1;
  char op;
  string mat, cog, cod , cod1, cod2, cod3, desc, labels;
  string cod_mat, mat_stu, cog_stu, nome_stu;
  map<string, vector<studente>> studenti;
  map<string, vector<materia>> materie;
  map<string, vector<corso>> corsi;
  map<string, studente> stuPerCor;
  map<string, materia> esaPerCor;
  map<string, materia> matDes;
  set<string> matDesc;

  menu();
  cout<< "Scelta: ";
  cin>>op;

  while (op != 'X'){

    switch (op){

        case '0':

            insVal(studenti, materie, corsi, labels);

            cout<<endl;

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

            cout<<"Inserisci una stringa"<<endl;
            cin.ignore();
            getline(cin, desc);

            matDesc = matPerDesc(materie, desc);

            cout<<endl;

            if (matDesc.size() != 0){

               for (auto& elem : matDesc){

                    cout<<elem<<endl;
               }

               matDesc.clear();

            }
            else{
                cout<<"Nessuna stringa trovata"<<endl;
            }

            break;

        case '8':

            cout << "Inserisci il codice della materia: "<<endl;
            cin >> cod_mat;

            cout << "Inserisci la matricola dello studente: "<<endl;
            cin >> mat_stu;

            cout << "Inserisci il cognome dello studente: "<<endl;
            cin >> cog_stu;

            cout << "Inserisci il nome dello studente: "<<endl;
            cin >> nome_stu;

            insInStr(studenti, materie, cod_mat, mat_stu, cog_stu, nome_stu);

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

  cout<<"Fine del programma!";

}
