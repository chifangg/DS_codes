#include<stdio.h>
#include<stdlib.h>

int A[200001];
int PCLE[200001];
int i,j,k,l,num,PCLEpos;

int main()
{
 while((scanf("%d", &num))!= EOF)
 {
  A[i] = num;
  i++;
 }
 /*
 for (int ii=0;ii<i;ii++ )
 {
  printf("%d ", A[ii]);
 }
 */
 for(j = 0; j < i-1; j++)
 {
  PCLEpos=j;
  k=i-1;
  l=j-1;
  while (A[l]<=A[j] && l>=0) 
  {
   l--;
  }
  if (A[l]>A[j] && l>=0)
  {
   PCLEpos=l;
   PCLE[j]=PCLEpos-j;
  }
  else
  {
  while (A[k]<=A[j] && k>=j)
  {
   k--;
  }
  if (A[k]>A[j] && k>j)
  {
   PCLEpos=k;
   PCLE[j]=PCLEpos-j;
  }
  if (k<j)
  {
   PCLEpos=j;
   PCLE[j]=PCLEpos-j;
  }
  }

  printf("%d ", PCLE[j]);
 }
 
  PCLEpos=j;
  k=i-1;
  l=j-1;
  while (A[l]<=A[j] && l>=0) 
  {
   l--;
  }
  if (A[l]>A[j] && l>=0)
  {
   PCLEpos=l;
   PCLE[j]=PCLEpos-j;
  }
  else
  {
  while (A[k]<=A[j] && k>=j)
  {
   k--;
  }
  if (A[k]>A[j] && k>j)
  {
   PCLEpos=k;
   PCLE[j]=PCLEpos-j;
  }
  if (k<j)
  {
   PCLEpos=j;
   PCLE[j]=PCLEpos-j;
  }
  }

  printf("%d", PCLE[j]);
 
 printf(" \n");
}
