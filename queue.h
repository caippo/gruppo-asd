#include <iostream>
#include <stdexcept>

#include "token.h"

using namespace std;

// QUEUE
namespace queue{


// Gli elementi della QUEUE sono token
typedef token Elem;


struct queuecell{
	Elem elem;
	queuecell *next;
};
typedef queuecell *Queue;  // la coda è una lista semplice
typedef queue:Queue EMPTYQUEUE =nullptr;
bool isEmpty(const Queue&);
void enqueue(Elem, Queue&);  /* inserisce l'elemento alla fine della lista */
Elem dequeue(Queue&);        /* cancella l'elemento in prima posizione (se esiste) e lo restituisce */
}
