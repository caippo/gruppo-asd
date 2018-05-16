#include "graph.h"

using namespace graph;

/*******************************************************************************************************/
// Grafo
/*******************************************************************************************************/

struct halfEdgeVertex;

//PROTOTIPI FUNZIONI AUX:
void printAdjacent(halfEdgeVertex*& ListA);
bool isEmptyArc(halfEdgeVertex*& a);
Graph getVertex(const Graph,const Label); //dato il label ritorna il puntatore alla lista
halfEdgeVertex* newAdjListNode(const Graph, const Weight, const Label);

/* “Mezzo arco”, non tiene l'etichetta del vertice
sorgente ma solo il puntatore al vertice
destinazione e il peso dell'arco; tiene inoltre il
puntatore al prossimo mezzo arco nella lista di
adiacenza */

struct halfEdgeVertex {
 //Label label;
 vertexNode *vertPtr; // puntatore al vertice
 Weight weight; // etichetta (o “peso”) dell'arco
 halfEdgeVertex* next; // puntatore al mezzo arco successivo
};
//typedef halfEdgeVertex* ArcList;
const halfEdgeVertex* emptyArc = NULL;
const Label emptyLabel = "$#$#$";
/* Un vertice è caratterizzato dall'etichetta, dal
puntatore alla lista dei “mezzi archi” adiacenti, dal
booleano che dice se il vertice è stato marcato oppure no
e dal puntatore al prossimo vertice nella lista di
vertici */
struct graph::vertexNode {
 Label label;
 halfEdgeVertex *adjList;
 vertexNode *next;
 bool visited;
};

// Restituisce il grafo vuoto
Graph graph::createEmptyGraph()
{
  Graph newvertice = new vertexNode;
  newvertice->label = emptyLabel;
  return newvertice;
  //return emptyGraph;
}


//FUNZ AUX crea nuovo nodo lista adiacenza
halfEdgeVertex* newAdjListNode(const Graph g, const Weight w, const Label to){
  halfEdgeVertex* newadj = new halfEdgeVertex;
  newadj->vertPtr = getVertex(g, to);
  newadj->weight = w;
  return newadj;
}

// Aggiunge nuovo vertice con etichetta la stringa. Fallisce se gia' presente
bool graph::addVertex(Label l, Graph& g) {
  Graph aux = g;
  while (aux->next) {
    if(aux->label == l){
      return false;
    }
    aux = aux->next;
  }

    if(g->label == emptyLabel){
      std::cout << "addVertex() inserisco: " << l << '\n';
      g->label = l;
      return true;
    }else{
      std::cout << "addVertex(): inserisco un nuovo vertice: "<< l << '\n';
      Graph newvertice = new vertexNode;
      newvertice->label = l;
      newvertice->next = g;
      g = newvertice;
      return true;
    }


}

//dato il label ritorna il puntatore alla lista
Graph getVertex(const Graph g, const Label l){
  Graph aux = g;
  while (!isEmpty(aux->next) && aux->label != l) {
    std::cout << "GetVertex(): scansiono: "<< aux->label << '\n';
    aux = aux->next;
  }
  if(aux->label == l){
    std::cout << "GetVertex(): cerco " << l << " ho trovato" << aux->label << '\n';
    return aux;
  }else{
    std::cout << "GetVertex(): non ho trovato " << l << '\n';
    return emptyGraph;
  }

}

// Aggiunge un arco di peso "w" tra i nodi con etichetta "f" e "t". Fallisce se esiste gia' l'arco
// se i nodi non esistono nel grafo e se si tenta di inserire un arco tra un nodo ed esso stesso
bool graph::addEdge(Label from, Label to, Weight w, Graph& g) {
  std::cout << "INSERIMENTO NUOVO ARCO: da "<< from << " a "<< to << '\n';

  Graph auxFrom, auxTo;
  if(isEmpty(g)){
    return false;
  }

  if(from == to){
    return false;
  }

  auxFrom = getVertex(g, from);
  if(isEmpty(auxFrom)){             //NON ESISTE CITTA' FROM
    return false;
  }
  auxTo = getVertex(g, to);
  if(isEmpty(auxTo)){               //NON ESISTE CITTA' TO
    return false;
  }

  // DA FROM A TO

  halfEdgeVertex* auxAdjList = auxFrom->adjList;
  if(isEmptyArc(auxAdjList)){
    std::cout << "Non esiste cella di adiacenza, la creo!" << '\n';
    auxFrom->adjList = newAdjListNode(g, w, to);
  }else{
    while (!isEmptyArc(auxAdjList->next)) {
      auxAdjList = auxAdjList->next;
    }
    if(!isEmpty(auxAdjList->vertPtr)){
      if(auxAdjList->vertPtr->label == to){
        std::cout << "L'arco esiste gia'!!" << '\n';
        return false;
      }else{
        std::cout << "inserisco in cima alla lista adiacenza" << '\n';
        halfEdgeVertex* tmp = auxFrom->adjList;
        auxFrom->adjList = newAdjListNode(g, w, to);
        auxFrom->adjList->next = tmp;
      }
    }
  }

  // DA TO A FROM

  auxAdjList = auxTo->adjList;
  if(isEmptyArc(auxAdjList)){
    std::cout << "Non esiste cella di adiacenza, la creo!" << '\n';
    auxTo->adjList = newAdjListNode(g, w, from);
  }else{
    while (!isEmptyArc(auxAdjList->next)) {
      auxAdjList = auxAdjList->next;
    }
    if(!isEmpty(auxAdjList->vertPtr)){
      if(auxAdjList->vertPtr->label == to){
        std::cout << "L'arco esiste gia'!!" << '\n';
        return false;
      }else{
        std::cout << "inserisco in cima alla lista adiacenza" << '\n';
        halfEdgeVertex* tmp = auxTo->adjList;
        auxTo->adjList = newAdjListNode(g, w, from);
        auxTo->adjList->next = tmp;
      }
    }
  }
  return true;
}

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph& g){
 return (g == emptyGraph);//true;
}

//FUNZIONE AUX return true se puntatore arco vuoto
bool isEmptyArc(halfEdgeVertex*& a){
  return(a == emptyArc);
}

// Ritorna il numero di vertici del grafo
int graph::numVertices(const Graph& g){
 return 0;
}

// Ritorna il numero di archi del grafo
int graph::numEdges(const Graph& g){
 return 0;
}

// Calcola e ritorna (nel secondo parametro) il grado del nodo. Fallisce
// se il nodo non esiste
bool graph::nodeDegree(Label l, int& degree, const Graph& g) {
  return true;
}

// Verifica se i due vertici v1 e v2 sono adiacenti (ovvero se esiste un arco)
bool graph::areAdjacent(Label v1, Label v2, const Graph& g) {
  return true;
}

// Restituisce la lista di adiacenza di un vertice
list::List graph::adjacentList(Label v1, const Graph& g) {
  list::List lst = list::createEmpty();
  return lst;
}

// Ritorna un cammino tra una citta' ed un altra
// Il cammino da "v1" a "v2" alla fine sara' in "path"
// e la lunghezza sara' in "len".
// Si assume che il chiamante fornisca inizialmente un cammino vuoto.
//
// La funzione rappresenta una variante della visita DFS

void graph::findPath(Label v1, Label v2, list::List &path, int &len, const Graph& g) {
    return;
}
/*******************************************************************************************************/
// Stampa il grafo

//funzione aux per stamapre citta'
void printCity(graph::Graph& g){
  if(isEmpty(g)){
    return;
  }else{
    std::cout << "Citta': " << g->label << '\n';
    halfEdgeVertex* aux = g->adjList;
    while (!isEmptyArc(aux)) {
      printAdjacent(aux);
      aux = aux->next;
    }
    //g = g->next;
  }
}
//funzione aux per stampare lista di adiacenza
void printAdjacent(halfEdgeVertex*& ListA) {
  if(isEmptyArc(ListA)){
    std::cout << "\t Nessuna adiacenza per questa citta'!" << '\n';
    return;
  }else{
    std::cout << "\tadiacenza:" << '\n';\
    //std::cout << "puntatore a lista vertex =" << ListA->vertPtr << '\n';
    std::cout << "\t\t-" << ListA->vertPtr->label << '\n';
    std::cout << "\t\t-distanza = "<< ListA->weight << " km" << '\n';
    //ListA = ListA->next;
  }
}

void printGraph(const graph::Graph& g) {
  if(g->label == emptyLabel){
    std::cout << "Il grafo e' vuoto!" << '\n';
  }else{
    Graph aux = g;
    while (!isEmpty(aux)) {
      printCity(aux);
      aux = aux->next;
    }
  }
}
