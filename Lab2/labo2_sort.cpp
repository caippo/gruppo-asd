#include "labo2_sort.h"
#include <ctime>


void qs(vector<int>& v, int begin, int end);
int partizionarnd(vector<int>& v, int inizio, int fine);
//int partitionrnd (vector<int>& v, int low, int high);
void qsrand(vector<int>& v, int low, int high);
/***************************************************************************************
        SWAP
****************************************************************************************/

void scambia(vector<int>& v, int i, int j)
{
  int tmp = v[j];
  v[j] = v[i];
  v[i] = tmp;
}


/***************************************************************************************
        PARTIZIONE IN PLACE
****************************************************************************************/
/*int partition(vector<int> &a,int l,int r){
  int p;
  int i;
  i = l +1;
  p = a[i];
  for (int j = l +1 ; j <= r ; ++j  ){
    if (a[j]<p){
      scambia (a, a[j], a[i]);
      i+=1;
    }
    else break ;
  }
scambia (a , a[l], a[i-1]);
return i;//indice del pivot
}*/



/**************************************************************************************
				SELECTION SORT
***************************************************************************************/
void selectionSort(vector<int>& v)
{
   int current_min_index;
   unsigned int size = v.size();
   for (unsigned int i=0; i<size; ++i)
   {
     current_min_index = i;
     for (unsigned int j=i+1;j<size; ++j)
        if (v[current_min_index] > v[j])
            current_min_index = j;
     scambia(v, i, current_min_index);
   }
}



/**************************************************************************************
				INSERTION SORT
***************************************************************************************/
void insertionSort(vector<int>& v)
{
   int current, prev;
   unsigned int size = v.size();
   for (unsigned int i=1; i<size; ++i)
   { current=i;
     prev=i-1;
     while(prev>=0 && v[current]<v[prev])
        {
         scambia(v, current, prev);
         --current;
         --prev;
        }
   }
}


/**************************************************************************************
				BUBBLESORT
***************************************************************************************/
void bubbleSort(vector<int>& v)
{
   unsigned int size = v.size();
   bool scambiati;
   for (unsigned int i=1; i<size; ++i)
      {
      scambiati = false;
      for (unsigned int j=0; j<size-i; ++j)
          if(v[j]>v[j+1])
            {
              scambia(v, j, j+1);
              scambiati = true;
            }
      if (!scambiati) return;
      }
}



/**************************************************************************************
				   MERGESORT
***************************************************************************************/
void fondi(vector<int>& v, unsigned int inizio, unsigned int centro, unsigned int fine)
{
   vector<int> vsinistra, vdestra;

   for (unsigned int i=inizio; i<=centro; ++i)
      vsinistra.push_back(v[i]);

   for (unsigned int i=centro+1; i<=fine; ++i)
      vdestra.push_back(v[i]);

   unsigned int indicesinistra = 0;
   unsigned int maxsin = vsinistra.size();
   unsigned int indicedestra = 0;
   unsigned int maxdes = vdestra.size();

   for (unsigned int i=inizio; i<=fine; ++i)
   {
      if (indicesinistra < maxsin && indicedestra < maxdes)
         {
         if (vsinistra[indicesinistra]<vdestra[indicedestra])
            {
             v[i] = vsinistra[indicesinistra];
             indicesinistra++; continue;
             }
         else
            {
            v[i] = vdestra[indicedestra];
            indicedestra++; continue;
            }
         }

      if (indicesinistra == maxsin && indicedestra < maxdes)
         {
            v[i] = vdestra[indicedestra];
            indicedestra++; continue;
         }

       if (indicedestra == maxdes && indicesinistra < maxsin)
         {
            v[i] = vsinistra[indicesinistra];
            indicesinistra++; continue;
         }
   }
}

void ms(vector<int>& v, unsigned int inizio, unsigned int fine)
{
    if (inizio < fine)
      {
          unsigned int centro = (inizio+fine)/2;
          ms(v, inizio, centro);
          ms(v, centro+1, fine);
          fondi(v, inizio, centro, fine);
      }
}


void mergeSort(vector<int>& v)
{
   if (v.size() != 0)
      ms(v, 0, v.size()-1);
}

int partition (vector<int>& v, int low, int high)
{

  int pivot = low;
  scambia(v, pivot, low);
      // metto il pivot all'inizio della sequenza da riordinare
      //- anche se sarebbe inutile vista la scelta fatta
  int i = low + 1;
  for(int j= low + 1; j<=high; ++j){
    if(v[j] < v[low]){
      scambia(v, i, j);
      ++i;
    }
  }
  scambia(v, low, i-1);
  return i-1;
    /*int pivot = v[0];    // pivot
    int i = (low - 1);  // Index of smaller element

    //for (int j = low; j <= high- 1; j++)
    for(int j= low + 1; j<= high; ++j)
    {
        // If current element is smaller than or
        // equal to pivot
        if (v[j] <= pivot)
        {
            i++;    // increment index of smaller element
            scambia(v,i, j);
        }
    }
    //scambia(v, (i + 1), high);
    scambia(v,(i-1),high);
    //return (i + 1);
    return i;*/
}


/**************************************************************************************
				QUICKSORT CON SCELTA "BANALE" DEL PIVOT
***************************************************************************************/

void quickSortTrivial(vector<int>& v)
{
   /* Implementare quickSort banale con partizione in place */
   qs(v, 0, v.size()-1);
}


void qs(vector<int>& v, int low, int high){
  if (low < high)
  {
      int pi = partition(v, low, high); // pivot
      qs(v, low, pi - 1);
      qs(v, pi + 1, high);
  }

}


/**************************************************************************************
				QUICKSORT RANDOMIZZATO
***************************************************************************************/

void quickSortRandom(vector<int>& v)
{
  qsrand(v, 0, v.size()-1);

	//int rand;
	//rand = rand() % v.size //? per il pivot
   /* Implementare quickSort randomizzato con partizione in place */
}

void qsrand(vector<int>& v, int low, int high){
  //srand(time(NULL)); // srand ha un costo non trascurabile: poiché basta chiamarla una sola volta all'interno del programma per fissare il seme della
                      // generazione pseudo-casuale, possiamo chiamarla in quickSortRandom prima di  qsrand(v, 0, v.size()-1) e non chiamarla più!
  if (low < high)
  {
      int pi = partizionarnd(v, low, high); // pivot
      qsrand(v, low, pi - 1);
      qsrand(v, pi + 1, high);
  }
}

int partizionarnd(vector<int>& v, int inizio, int fine)
{
   int pivotIndex = inizio+rand()%((fine+1)-inizio);//(fine-inizio+1);          //((fine-1)-inizio);
                    // scelgo un indice a caso tra inizio e fine: sara' il mio pivot
   scambia(v, pivotIndex, inizio); // metto il pivot all'inizio della sequenza da riordinare
   //int p = v[pivotIndex];
   int i = inizio+1;
   for (int j=inizio+1; j<=fine; ++j)
       {
       if (v[j] < v[i]) // confronto con il pivot che e' all'inizio
          {
          scambia(v, i, j);
          ++i;
          }
       }
 scambia(v, inizio, i-1);
 return i-1;
}
