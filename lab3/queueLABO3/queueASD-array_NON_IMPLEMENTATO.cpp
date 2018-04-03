#include "queueASD-array.h"

using namespace queue;


/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/

/****************************************************************/
Queue queue::createEmpty()
{
    Queue aux;
    aux.queue = new Elem[BLOCKDIM];
    aux.size = 0;
    aux.maxsize = BLOCKDIM;

    return aux;
}

/****************************************************************/
void queue::enqueue(Elem e, Queue& l) // aggiunge e in coda
{
  /*if(l.size >= l.maxsize){
    Queue newqueue;
    newqueue.queue = new Elem[BLOCKDIM+l.size];
    newqueue.size = l.size;
    newqueue.maxsize = BLOCKDIM + l.size;

  }else{*/
    //l.queue[0] = e;
    //for(int i=0; i<l.size; ++i){}
    l.queue[l.size] = e;
    ++l.size;
  //}
  return;
}


/****************************************************************/
Elem queue::dequeue(Queue& l) // rimuove il primo elemento e lo restituisce
{
  Elem elemdarem = l.queue[0];

  Elem * aux = new Elem[BLOCKDIM];

  for(int i=0;i<l.size-1; ++i){
      aux[i] = l.queue[i+1];
  }

  l.queue = aux;
  --l.size;

  return elemdarem;
   //return EMPTYELEM;
}


/****************************************************************/
Elem queue::first(Queue& l) // restituisce il primo elemento
{
    return(l.queue[0]);
   //return EMPTYELEM;
}


/****************************************************************/
bool queue::isEmpty(const Queue& l)
{
   //return true;
   return (l.size == 0);
}



/****************************************************************/
Queue readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    return readFromStream(ifs);
}


/****************************************************************/
Queue readFromStdin()
{
    cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
    return readFromStream((std::cin));
}


/****************************************************************/
Queue readFromStream(istream& str)
{
    Queue l = createEmpty();
    int dato;
    str>>dato;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (dato!= FINEINPUT)  // assumiamo che il segnale di fine input nel file sia  FINEINPUT
        {
        enqueue(dato, l);   // aggiunge l'elemento alla fine della coda
        str>>dato;
        if (!str) throw runtime_error("Errore inserimento dati\n");
        }
return l;
}

/****************************************************************/
void print(const Queue& l)
{
cout << endl;
for (int i=0; i<l.size; ++i)
   cout << l.queue[i] << "; ";
cout << endl;
}
