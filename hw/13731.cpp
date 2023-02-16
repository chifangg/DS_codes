//this code is not AC
//it's 4/6 only


#include<stdio.h>
#include<stdlib.h>
#define MAX 500000

#define ABS(N) ((N<0)?(-N):(N))

int OrderF[MAX][2];
int OrderB[MAX][2];

int cmp(const void *a,const void *b)
{
    int *c = (int *)a;
    int *d = (int *)b;
    if(*c != *d)
        return *c - *d;
    return *(c+1) - *(d+1);
}

int main()
{
 
 int NumOfOrder;
 int TerminalPos;
 int StartP, EndP;
 
 scanf("%d %d", &NumOfOrder,&TerminalPos);
 int countF=0;
 int countB=0;
 int i,j;
 
 for (i=0;i<NumOfOrder;i++)
 {
  scanf("%d %d",&StartP, &EndP);
  if (StartP<EndP)
 { 
   OrderF[countF][0]=StartP;
    OrderF[countF][1]=EndP;
    countF++;
    }
    else
    {
     OrderB[countB][0]=EndP;
   OrderB[countB][1]=StartP;
  countB++; 
 }
 }
 
 qsort(OrderF,countF,sizeof(OrderF[0]),cmp);
 qsort(OrderB,countB,sizeof(OrderB[0]),cmp);
 
 long long int ans=0;
 int count;
 int countFB=0, countBB=0;
 int Dist;
 
 
 for (i=0;i<TerminalPos;i++)
 {
  Dist=0;
  count=countFB;
  while (count<countF)
  {
   if (i>=OrderF[count][0])
   {
    if (i<OrderF[count][1])
    {
     Dist++;
    ans++; 
   }
   /*else
   {
     countFB=count+1;
   }*/
   count++;
   }
  else break;
 }
 
 count=countBB;
 while (count<countB)
  {
   if (i>=OrderB[count][0])
   {
    if (i<OrderB[count][1])
    {
     Dist--;
    ans++; 
   }
   /*else
   {
     countBB=count+1;
   }*/
   count++;
  }
  else break;
 }
 ans+=ABS((1-Dist));
 }
 printf("%lld\n",ans); 
}
