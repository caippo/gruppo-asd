#include "list.h"

using namespace list;

/*struct list{

  list * next;
}*/


/****************************************************************/
void list::clear(List& l){

}


/****************************************************************/
void list::set(int pos, Elem e, List& l) // "set" nel senso di "assegna un valore", non nel senso di "insieme"! E' una terminologia standard, non fate confusione con gli insiemi
{

}


/****************************************************************/
void list::add(int pos, Elem e, List& l) // aggiunge e nella posizione pos
{

}

/****************************************************************/
void list::addBack(Elem e, List& l) // aggiunge e in coda
{

}


/****************************************************************/
void list::addFront(Elem e, List& l) // aggiunge e in coda
{

}

/****************************************************************/
void list::removePos(int pos, List& l)
{

}


List list::createEmpty()
{


}

/****************************************************************/
Elem list::get(int pos, const List& l)
{
   return emptyElem;
}


/****************************************************************/
bool list::isEmpty(const List& l)
{
   return true;
}

/****************************************************************/
int list::size(const List& l)
{
   return 0;
}


/****************************************************************/
void printList(const List& l)
{

}
