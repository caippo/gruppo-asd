#include "queue.h"

using namespace queue;


/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/

/****************************************************************/

/****************************************************************/
bool queue::isEmpty(const Queue& l)                                                  
{
  return (l==NULL);

}

/****************************************************************/
void queue::enqueue(Elem e, Queue& l) // aggiunge e in coda                         
{
  if (isEmpty(l))
  {
    l= new queuecell;
    l->elem=e;
    l->next=EMPTYQUEUE;
    cout << "INSERIMENTO ELEM NELLA QUEUE" << std::endl;   
  }
  else
  {
  Queue aux=l;
   
    while(aux->next!=EMPTYQUEUE){
      aux=aux->next;
    aux->next=new queuecell;
    aux->next->elem=e;
    aux->next->next=EMPTYQUEUE;
    cout << "INSERIMENTO ELEM NELLA QUEUE" << std::endl;  
  }
}


/****************************************************************/                    // DA CONTROLLARE
Elem queue::dequeue(Queue& l) // rimuove il primo elemento e lo restituisce
{
  Elem e;
  e=l->elem;
  Queue aux=l;
  l=l->next;
  delete aux;
  cout << "USCITA ELEM NELLA QUEUE" << std::endl;   // TEST
  return e;
}
