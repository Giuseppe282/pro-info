#ifndef FUNZCSV_H_INCLUDED
#define FUNZCSV_H_INCLUDED

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

void menu();

void insVal(map<string, vector<studente>>& studenti, map<string, vector<materia>>& materie, map<string, vector<corso>>& corsi, string &l);

string corPerMat(map<string, vector<studente>> studenti, map<string, vector<corso>> corsi, string mat);

string corPerCog (map<string, vector<studente>> studenti, map<string, vector<corso>> corsi, string cog);

map<string, studente> studPerCor(map<string, vector<studente>> studenti, string cod);

map<string, materia> esamPerCorso(map<string, vector<materia>> materie, string cod);

int numStudPerCor(map<string, vector<studente>> studenti, string cod);

int numMatPerCor (map<string, vector<materia>> materie, string cod);

set<string> matPerDesc (map<string, vector<materia>> materie, string s);

void insInStr(map<string, vector<studente>>& studenti, map<string, vector<materia>>& materie, string cod_mat, string matr, string cognome, string nome);

void insInFile (map<string, vector<corso>> corsi, map<string, vector<materia>> materie, map<string, vector<studente>> studenti, string labels);


#endif // FUNZCSV_H_INCLUDED
