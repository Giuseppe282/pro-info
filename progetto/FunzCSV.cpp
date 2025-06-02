#include "FunzCSV.h"

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

set<string> matPerDesc(map<string, vector<materia>> materie, string s) {

    // Trasforma la stringa s in minuscolo
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    set<string> stampati; // per evitare duplicati

    for (auto& pair : materie) {

        for (auto& m : pair.second) {

            string desc = m.desc_mat;
            transform(desc.begin(), desc.end(), desc.begin(), ::tolower);

            if (desc.find(s) != string::npos) {
                stampati.insert(m.desc_mat);
            }
        }
    }

    return stampati;
}


// 8

void insInStr(map<string, vector<studente>>& studenti, map<string, vector<materia>>& materie, string cod_mat, string matr, string cognome, string nome)
{
    string codiceCorso = "";
    bool trovato = false;

    for (auto &pair : materie) {
        for (auto &m : pair.second) {
            if (m.cod_mat == cod_mat) {
                codiceCorso = m.cod_corso;
                trovato = true;
                break;
            }
        }
        if (trovato) break;
    }

    if (!trovato) {
        cout << "Materia non trovata.\n";
        return;
    }

    studente s{nome, cognome, matr, codiceCorso};
    studenti[codiceCorso].push_back(s);
}


// 9

void insInFile (map<string, vector<corso>> corsi, map<string, vector<materia>> materie, map<string, vector<studente>> studenti, string labels){

    ofstream fout(NAMEFILE);

    fout << labels << endl;


    for (auto &pair : corsi) {
        string cod_corso = pair.first;
        string desc_corso = pair.second[0].decs_corso;

        materia prima_materia = materie[cod_corso][0];

        // Per ogni studente iscritto a questo corso
        for (auto &s : studenti[cod_corso]) {
            fout << cod_corso << DEL << desc_corso << DEL << prima_materia.cod_mat << DEL << prima_materia.desc_mat << DEL << s.matr << DEL << s.cognome << DEL << s.nome << endl;
        }
    }

    fout.close();
}
