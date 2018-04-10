#include "stack.h"

using namespace stack;

/****************************************************************/
bool stack::isEmpty(const Stack& s)                                                    // DA CONTROLLARE
{
    return (s==NULL);

}

/****************************************************************/
void stack::push(const Elem x, Stack& s)                                               // DA CONTROLLARE
{
  if(isEmpty(s))
  {
    s= new stackcell;
    s->elem=x;
    s->next=NULL;
    cout << "INSERIMENTO ELEM NELLO STACK" << std::endl;   // TEST
  }
  else
  {
    Stack aux=new stackcell;
    aux->elem=x;
    aux->next=s;
    s=aux;
    cout << "INSERIMENTO ELEM NELLO STACK" << std::endl;   // TEST
  }
}

/****************************************************************/
Elem stack::pop(Stack& s)                                                              // DA CONTROLLARE
{
    Elem e;
    e=s->elem;
    Stack aux=s;
    s=s->next;
    delete aux;
    cout << "USCITA " << e.val << "DALLO STACK" << std::endl;   // TEST
    return e;

}

/****************************************************************/
