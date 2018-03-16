#include "labo2_sort.h"

<<<<<<< HEAD
void qs(vector<int>& v, int begin, int end);

=======
/***************************************************************************************
        SWAP
****************************************************************************************/
>>>>>>> f7267d4f9a08c22a8ed22a22fc53cc68d85e600d
void scambia(vector<int>& v, int i, int j)
{
  int tmp = v[j];
  v[j] = v[i];
  v[i] = tmp;
}


/***************************************************************************************
        PARTIZIONE IN PLACE
****************************************************************************************/
int partition(vector<int> &a,int l,int r){
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
    int pivot = v[0];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (v[j] <= pivot)
        {
            i++;    // increment index of smaller element
            scambia(v,i, j);
        }
    }
    scambia(v, (i + 1), high);
    return (i + 1);
}


/**************************************************************************************
				QUICKSORT CON SCELTA "BANALE" DEL PIVOT
***************************************************************************************/

void quickSortTrivial(vector<int>& v)
<<<<<<< HEAD
{
   /* Implementare quickSort banale con partizione in place */
   qs(v, 0, v.size()-1);

=======
{/*

      unsigned int  l,r,p,piv;

      while (v[v.begin()]<v[v.size()])
      {
          l = v[v.begin()];
          p = 0 ;
          r = v[v.size()];

          piv = v[p];


          partition ( v, l, r);


          list[p]=list[r];
          list[r]=piv;
          r--;


          if ((r-v[v.begin()])<(v[v.size()]-l))
          {
              qs(v, v[v.begin()], r);
              v[v.begin()]=l;
          }
          else
          {
              qs(v, l, v[v.size()]);
              v[v.size()]=r;
          }
      }
*/}

void qs (vector <int> v ,unsigned int l ,unsigned int  r){
/*
    if (l < r)
    {

        int m = l+(r-l)/2;


        qs(arr, l, m);
        qs(arr,m+1, r);

        quickSortTrivial(v();
    }
*/
>>>>>>> f7267d4f9a08c22a8ed22a22fc53cc68d85e600d
}

void qs(vector<int>& v, int low, int high){
  if (low < high)
  {
      /* pi is partitioning index, arr[p] is now
         at right place */
      int pi = partition(v, low, high);

      // Separately sort elements before
      // partition and after partition
      qs(v, low, pi - 1);
      qs(v, pi + 1, high);
  }

}


/**************************************************************************************
				QUICKSORT RANDOMIZZATO
***************************************************************************************/

void quickSortRandom(vector<int>& v)
{
   /* Implementare quickSort randomizzato con partizione in place */
}
