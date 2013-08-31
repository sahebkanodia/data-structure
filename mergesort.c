#include<stdio.h>
#define M 100
void partition (int [], int, int);
void merge (int [], int, int, int);
int main ()
{
  int a[M], i, n, mid;
  printf ("\n Enter the number of elements : ");
  scanf ("%d", &n);
  //a = (int *) malloc((n+1) * sizeof(int));
  if(n>M)
	{
	printf("\n Array size should be less than 100 !");
	return 0;
	}
  printf ("\n Enter the elements : ");
  for (i = 0; i < n; i++)
    {
      printf ("\n Enter Number : ");
      scanf ("%d", &a[i]);
    }
  partition (a, 0, n-1);
  printf ("\n Sorted Numbers are : \n");
  for (i = 0; i < n; i++)
    {
      printf ("%3d", a[i]);
    }
  printf ("\n");
  return 0;
}

void partition (int a[], int low, int high)
{
  int mid;
  mid = (low + high) / 2;
  if (low < high)
    {
      partition (a, low, mid);
      partition (a, mid+1, high);
      merge (a, low, mid, high);
    }
}

void merge (int a[], int low, int mid, int high)
{
  int i, l, m, k, temp[M];
 // int *temp=(int*)malloc(sizeof(a)+1);
  i = low;
  l = low;
  m = mid + 1;
  while (l <= mid && m <= high)
    {
      if (a[l] < a[m]){
	temp[i] = a[l];
	l++;}
      else{
	temp[i] = a[m];
	m++;}
      i++;
    }
  if (l > mid)
    {
      for (k = m; k <= high; k++)
	{
	  temp[i] = a[k];
	  i++;
	}
    }
  else
    {
      for (k = l; k <= mid; k++)
	{
	  temp[i] = a[k];
	  i++;
	}
    }
  for (k = low; k <= high; k++)
    a[k] = temp[k];
}
