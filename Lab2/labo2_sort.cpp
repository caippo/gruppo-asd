#include "labo2_sort.h"
#include <ctime>


void qs(vector<int>& v, int begin, int end);
int partizionarnd(vector<int>& v, int inizio, int fine);
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

  int i = low + 1;
  for(int j= low + 1; j<=high; ++j){
    if(v[j] < v[low]){
      scambia(v, i, j);
      ++i;
    }
  }
  scambia(v, low, i-1);
  return i-1;
}


/**************************************************************************************
				QUICKSORT CON SCELTA "BANALE" DEL PIVOT
***************************************************************************************/

void quickSortTrivial(vector<int>& v){
   /* Implementare quickSort banale con partizione in place */
   qs(v, 0, v.size()-1);
}

void qs(vector<int>& v, int low, int high){
  if (low < high){
      int pivot = partition(v, low, high); // pivot
      qs(v, low, pivot - 1);
      qs(v, pivot + 1, high);
  }

}


/**************************************************************************************
				QUICKSORT RANDOMIZZATO
***************************************************************************************/

void quickSortRandom(vector<int>& v){
  /* Implementare quickSort randomizzato con partizione in place */
  qsrand(v, 0, v.size()-1);
}

void qsrand(vector<int>& v, int piccolo, int grande){
  srand(time(NULL));
  if (piccolo < grande){
      int pi = partizionarnd(v, piccolo, grande); // pivot
      qsrand(v, piccolo, pi - 1);
      qsrand(v, pi + 1, grande);
  }
}

int partizionarnd(vector<int>& v, int inizio, int fine){
  int pivotIndex = inizio+rand()%((fine+1)-inizio);

  scambia(v, pivotIndex, inizio);
  int i = inizio+1;
  for (int j=inizio+1; j<=fine; ++j){
    if (v[j] < v[inizio]){
      scambia(v, i, j);
      ++i;
    }
  }
 scambia(v, inizio, i-1);
 return i-1;
}
