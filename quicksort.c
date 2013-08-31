#include<stdio.h>
#define M 100
void quicksort (int[], int, int);
int main ()
{
  int a[M], n, i;
  printf ("\n Enter the total number of elements : ");
  scanf ("%d", &n);
  if(n>M)
    {
      printf("\n Please enter between 1 to 100 !");
      return 0;
    }
  for (i = 0; i < n; i++)
    {
      printf ("\n Enter Element : ");
      scanf ("%d", &a[i]);
    }
  quicksort (a, 0, n-1);
  printf ("\n The sorted elements are : ");
  for (i = 0; i < n; i++)
    printf ("%d \t", a[i]);
  printf ("\n");
  return 0;
}

void quicksort (int a[], int lo, int hi)
{
  int i, j, x, temp;
  i = lo;
  j = hi;
  x = a[(lo + hi) / 2];
  do
    {
      while (i < hi && a[i] < x)
	i++;
      while (j > lo && a[j] > x)
	j--;
      if (i <= j)
	{
	  temp = a[i];
	  a[i] = a[j];
	  a[j] = temp;
	  i++;
	  j--;
	}
    }
  while (i <= j);
  if (lo < j)
    quicksort (a, lo, j);
  if (i < hi)
    quicksort (a, i, hi);
}
