// Implementa le funzioni sulle liste realizzate con strutture doppiamente collegate, circolari, con sentinella, senza ordinamento

#include "ASD-doubly-linked-list.h"

using namespace list;

struct list::node {  // descrivo qui, fuori dal namespace, come e' fatta la struttura node: i dettagli interni non saranno visibili dal main
Elem info;
node *prev;
node *next;
};

const list::List emptyList = nullptr;

/*************************************************/
/* Implementazione delle operazioni di utilita'� */
/*************************************************/

void readFromStream(istream& str, List& l)
{
    createEmpty(l);
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e != FINEINPUT)  // assumiamo che il segnale di fine input nel file sia  FINEINPUT
        {
        addRear(e, l);   // aggiunge l'elemento alla fine della lista
        str>>e;
        if (!str) throw runtime_error("Errore inserimento dati\n");
        }
}

void readFromFile(string nome_file, List& l)  /* legge il contenuto di una lista da file */
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    readFromStream(ifs, l);
}



void readFromStdin(List& l)         /* legge il contenuto di una lista da standard input */
{
   cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
   readFromStream((std::cin), l);
}


void print(const List& l)           /* stampa la lista */
{
   List q = l->next;  // q "salta la sentinella" e va alla testa della lista
   while (q != l)     // avanza finche' non finisce la lista
     {
      cout << q->info << "; ";
      q = q->next;
      }
}

/**************************************************/
/* Implementazione delle operazioni nel namespace */
/**************************************************/

void list::clear(const List& l)                 /* "smantella" la lista svuotandola */
{
  delete l;
  /*List cursore = l;
  while (cursore->next != l) {
    delete cursore*/

  //}

}


Elem list::get(int pos, const List& l)        /* restituisce l'elemento in posizione pos se presente; restituisce un elemento che per convenzione si decide che rappresenta l'elemento vuoto altrimenti*/
{

}


void list::set(int pos, Elem e, const List& l)        /* modifica l'elemento in posizione pos, se la posizione e' ammissibile */
{

}


void list::add(int pos, Elem e, const List& l)        /* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */{

}


void list::addRear(Elem e,  const List& l)        /* inserisce l'elemento alla fine della lista */ //errore
{
  //list::node* cur = new list::node;
  /*list::List newelem = new list::List;
  list::List cur = l;
  newelem->info = e;
  while(cur->next != l){
    cur = cur->next;
  }*/
  //inserisco in coda
  //newelem->next = l/*
  list::node* tmp = new list::node;
  list::node* aux;
  aux->info = e;
  aux->prev = emptyList;
  aux->next = emptyList;
  /*if(l == emptyList){                     //errore! la lista non è mai == null!
    l = aux;
  }else*/
  while (tmp->next != l) {
    //tmp
  }

}


void list::addFront(Elem e, const List& l)        /* inserisce l'elemento all'inizio della lista */ //errore
{
  list::List aux = new list::node;
  aux->info = e;
  if (l == emptyList) //secondo me non è mai nulla!!!!
  aux->next = aux;
  else{
    List tmp = l;
    while (tmp->next != l)
    tmp = tmp->next;
    tmp->next = aux;
    aux->next = l;
  }
}


void list::removePos(int pos, const List& l)           /* cancella l'elemento in posizione pos dalla lista */
{

}


void list::removeEl(Elem e, const List& l)          /* cancella l'elemento elem, se presente, dalla lista */
{
  List cursore = l;
  List precc = emptyList;                           //nodo preccedente al cursore

  while(cursore->next != l && cursore->info != e){
    precc = cursore;
    cursore = cursore->next;
  }
  //ELIMINO IL NODO DELLA LISTA CON INFO == e
  if(cursore->info == e){
    precc->next = cursore->prev;

  }

}


bool list::isEmpty(const List& l)         /* restituisce true se la lista e' vuota (ed e' vuota se il next di l, e' l stessa */
{
  //list::node cur = new list::node;
  /*while(cur != l){ //&& cur->Elem !=
    cur=cur->next;
  }*/
   if (list::size(l)<=1 || l == l->next)
    return true;


}


int list::size(const List& l)           /* restituisce la dimensione della lista */
{
  int sizelist = 0;
  list::node* cur = new list::node;
  while(cur->next != l){ //&& cur->Elem !=
    ++sizelist;
    cur=cur->next;
  }
  return sizelist;

}


void list::createEmpty(List& l)           /* crea la lista vuota */
{
  list::node* sentinella = new list::node;
  //sentinella->prev = E
  sentinella->next = sentinella->prev;
  l = sentinella;
}
