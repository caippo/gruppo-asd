#include "list.h"


using namespace list;

const List emptylist = NULL;
typedef int Weight;

struct list::node{
  Elem elem;
  Weight w;
  node* next;
};

list::List getnext(list::List& l){
  l = l->next;
  return l;
}

//PROTOTIPI FUNZ AUX:
//void replaceElem(List&, Elem, Weight);

//sostituisce e, w=0 con e/w
/*void replaceElem(List& l, Elem e, Weight w){
  l->elem = e;
  l->w = w;
}*/

//FUNZ Aux
void addFrontWithWeight(Elem e, Weight w, List& l){ // aggiunge e in cima
  if(list::isEmpty(l)){
    l = list::createEmpty();
  }
  List newElem = new list::node;
  newElem->elem = e;
  newElem->w = w;
  List aux = l;
  newElem->next = aux;
  l = newElem;
}

void removeTop(List& l){
  list::List aux = l->next;       //cella da eliminare
  std::cout << "removeTop():"<< aux->elem << '\n';
  l = aux->next;
  delete aux;
}


/****************************************************************/
void list::clear(List& l){
  list::List aux= l;
  if(list::isEmpty(l)){  //(l!=emptylist)
    return;
  }

    while(!list::isEmpty(aux->next))  //(aux->next!=emptylist)
      aux=aux->next;
    delete aux;
  delete l;
}


/****************************************************************/
void list::set(int pos, Elem e, List& l){ // "set" nel senso di "assegna un valore", non nel senso di "insieme"! E' una terminologia standard, non fate confusione con gli insiemi

}


/****************************************************************/
void list::add(int pos, Elem e, List& l){ // aggiunge e nella posizione pos


}

/****************************************************************/
void list::addBack(Elem e, List& l){ // aggiunge e in fondo


}


/****************************************************************/
void list::addFront(Elem e, List& l){ // aggiunge e in cima
  if(list::isEmpty(l)){
    l = list::createEmpty();
  }
  List newElem = new list::node;
  newElem->elem = e;
  newElem->w = 0;
  List aux = l;
  newElem->next = aux;
  l = newElem;
}

/****************************************************************/
void list::removePos(int pos, List& l){

}


List list::createEmpty(){
  List l = new list::node;
  l->elem = emptyElem;
  l->w = 0;
  return l;
}

/****************************************************************/
Elem list::get(int pos, const List& l){
   return emptyElem;
}


/****************************************************************/
bool list::isEmpty(const List& l){
  return(l == emptylist);
   //return true;
}

/****************************************************************/
int list::size(const List& l){
  int count = 0;
  List aux = l;
  while (!list::isEmpty(aux)) {
    ++count;
    aux = aux->next;
  }
   return count;
}


/****************************************************************/
void printList(const List& l){
  if(list::isEmpty(l) || emptyElem == l->elem){
    std::cout << "\nLista vuota!!" << '\n';
    return;
  }

  List aux = l;
  std::cout << "\nStampa della lista:" << '\n';
  while (emptyElem != aux->elem){//(!list::isEmpty(aux->next)) {
    std::cout << "\t"<< aux->elem << '\n';
    aux = aux->next;
  }
  std::cout << "fine lista!" << '\n';
}
