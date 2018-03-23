#include "stackASD-ptr.h"

using namespace stack;


struct stack::cell {
    Elem	elem;
    cell	*next;
};


/****************************************************************/
bool stack::isEmpty(const Stack& s)
{
  return(s==EMPTYSTACK);

}


/****************************************************************/
void stack::push(const Elem x, Stack& s)
{   //inserimento in cima
  Stack newcell = new stack::cell;
  newcell->elem = x;

  if(s != EMPTYSTACK){
    newcell->next = s;
  }else{
    newcell->next = EMPTYSTACK;
  }
  s = newcell;
  return;
}

/****************************************************************/
Elem stack::pop(Stack& s)
{
  if(s == EMPTYSTACK){
    return EMPTYELEM;
  }else{
    Stack aux = s;
    Elem e = s->elem;
    s = s->next;
    delete aux;
    return e;
  }
}


/****************************************************************/
Elem stack::top(Stack& s)
{
  if(s == EMPTYSTACK){
    return EMPTYELEM;
  }else{
    return s->elem;
    }


    //prev =

  }
    //return EMPTYELEM;
}



Stack readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    return readFromStream(ifs);
}



Stack readFromStdin()
{
    cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " <<  FINEINPUT << " per terminare\n";
    return readFromStream((std::cin));
}



Stack readFromStream(istream& str)
{
    Stack s = EMPTYSTACK;
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e!= FINEINPUT)  // assumiamo che il segnale di fine input nel file sia il numero  FINEINPUT
    {
    push(e, s);
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    }
return s;
}



void print(const Stack& s)
{
cell* aux = s;
cout << endl;
while (aux != EMPTYSTACK)
   {
   cout << aux->elem << "; ";
   aux = aux->next;
   }
std::cout << endl;
}
