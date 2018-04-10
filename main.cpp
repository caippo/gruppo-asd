/////////////////////////////////////////////////////////////////////
//
// Laboratorio 3: calcolo di semplici espressioni numeriche
//                mediante pile e code
//
// vengono accettati dall'esterno solo numeri positivi.
// Per trattare anche numeri negativi occorre modificare
// l'analizzatore lessicale.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "token.h"
#include "queue.h"
#include "stack.h"

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ostringstream;

/////////////////////////////////////////////////////////////////////
// Funzioni principali: leggi() e calcola()
/////////////////////////////////////////////////////////////////////

// Estrae uno dopo l'altro i token dalla stringa "str", inserendoli via via nella coda "codaToken"
bool leggi(string &str, queue::Queue &codaToken) {
  token currentoken;
  while(!str.empty())
  {
    if(!prossimoToken(str,currentoken))
    {
      return false;
    }
    else
      queue::enqueue(currentoken,codaToken);                                              // DA TESTARE
  }
  return true;
}

// Estrae uno dopo l'altro i token dalla coda, inserendoli via via sullo stack.
// Appena si incontra un token PARENTESI CHIUSA, quello segnala la fine
// di una sottoespressione; allora tiriamo giu' dallo stack gli ultimi cinque token inseriti.
// I token estratti dovrebbero essere esattamente, nell'ordine:
// un ")", un numero, un operatore aritmetico, un altro
// numero, e un "("; se non è così, allora si segnala
// errore sintattico e l'algoritmo termina.
// A questo punto la funzione deve convertire i token di tipo NUMERO in numeri interi,
// eseguire l'operazione aritmetica opportuna, e trasformare il risultato da numero a
// token e inserire quest'ultimo sullo stack.
// Alla fine se non ci sono errori sintattici la funzione deve mettere nella variabile
// risultato il vaore dell'espressione
bool calcola(queue::Queue codaToken, int &risultato)
{
  int numeroconvertito1;
  int numeroconvertito2;
  token currentoken;
  token chiusaparentesi;
  token numero1;
  token numero2;
  token operatore;
  token apertaparentesi;
  stack::Stack lonelystack = NULL;
  while(codaToken!=NULL)
  {
    currentoken=queue::dequeue(codaToken);
    stack::push(currentoken,lonelystack);
    if(currentoken.k==PARENTESI_CHIUSA)
    {                        //CONTROLLO SINTASSI
      chiusaparentesi=stack::pop(lonelystack);
      numero1=stack::pop(lonelystack);
      if(numero1.k!=NUMERO)
        return false;
      operatore=stack::pop(lonelystack);
      if(operatore.k!=OP_SOMMA && operatore.k!=OP_SOTTRAZIONE && operatore.k!=OP_MOLTIPLICAZIONE)
        return false;
      numero2=stack::pop(lonelystack);
      if(numero2.k!=NUMERO)
        return false;
      apertaparentesi=stack::pop(lonelystack);
      if(apertaparentesi.k!=PARENTESI_APERTA)
        return false;
      //OPERAZIONE
      numeroconvertito1=str2int(numero1.val);
      numeroconvertito2=str2int(numero2.val);

        if(operatore.k==OP_SOMMA)
        {
          numero1.val=int2str(numeroconvertito1 + numeroconvertito2);
          stack::push(numero1,lonelystack);
        }
        if(operatore.k==OP_SOTTRAZIONE)
        {
          numero1.val=int2str(numeroconvertito1 - numeroconvertito2);
          stack::push(numero1,lonelystack);
        }
        if(operatore.k==OP_MOLTIPLICAZIONE)
        {
          numero1.val=int2str(numeroconvertito1 * numeroconvertito2);
          stack::push(numero1,lonelystack);
        }

    }
  }
  risultato=str2int(stack::pop(lonelystack).val);
  return (lonelystack==NULL);
}




/////////////////////////////////////////////////////////////////////
//                               MAIN
/////////////////////////////////////////////////////////////////////

int main() {

  string s;
  queue::Queue q = NULL;
  int r;

  cout << "Inserisci l'espressione che vuoi valutare:" << endl;
  getline(cin,s);

  if (!leggi(s,q)) {
    cout << "errore lessicale\n";
    exit(1);
  }

  if (!calcola(q,r)) {
    cout << "errore sintattico\n";
    exit(1);
  }

  cout << "risultato: " << r << "\n";
  exit(0);
}
