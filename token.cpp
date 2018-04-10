
/////////////////////////////////////////////////////////////////////
//
// Laboratorio 3: calcolo di semplici espressioni numeriche
//                mediante pile e code
//
// vengono accettati dall'esterno solo numeri positivi.
// Per trattare anche numeri negativi occorre modificare
// l'analizzatore lessicale.
//
///////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "token.h"
using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ostringstream;

/////////////////////////////////////////////////////////////////////
// Funzioni ausiliarie su tipi di dato semplici
/////////////////////////////////////////////////////////////////////

// da stringa a numero
int str2int(const string &s) {
  int n;
  istringstream itmp(s);
  itmp >> n;
  return n;
}

// da numero a stringa
string int2str(int n) {
  string s;
  ostringstream otmp ;
  otmp << n;
  s = otmp.str();
  return s;
}

// ritorna false se e solo se token di tipo sconosciuto o se stringa vuota.
// se stringa non vuota, la stringa perde il pezzo iniziale,
// che diventa token.

bool prossimoToken(string &s, token &t)             // IT WORK !!!  MAKE IT BETTER IF U FIND TIME TO DO IT
{
  int i=0;
  string tos;                       //top of string
  tos=s[i];
  int j=0;
  while (s[0]==' ')
    s.erase(s.begin());
  if(s.empty())
    return false;
    char tosch=s[i];
  switch (tosch)
  {
    case '+':
    t.val="+";
    t.k= OP_SOMMA;
    s.erase(s.begin());
    return true;

    case '-':
    t.val="-";
    t.k=OP_SOTTRAZIONE;
    s.erase(s.begin());
    return true;

    case '*':
    t.val="*";
    t.k=OP_MOLTIPLICAZIONE;
    s.erase(s.begin());
    return true;

    case '(':
    t.val="(";
    t.k=PARENTESI_APERTA;
    s.erase(s.begin());
    return true;

    case ')':
    t.val=")";
    t.k=PARENTESI_CHIUSA;
    s.erase(s.begin());
    return true;

    default :
    t.val=tos;
    t.k=SCONOSCIUTO;
  }
  int numberlenght=0;
  if(tosch >= '0' && tosch <= '9')
  {
    while (tosch >= '0' && tosch <= '9')
    {
      numberlenght++;
      tosch=s[numberlenght];
    }
    t.val=s.substr(0,numberlenght );
    t.k=NUMERO;
    s.erase(0,numberlenght);
    return true;
  }


    return false;
}
