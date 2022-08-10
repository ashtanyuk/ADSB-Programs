#include <stdio.h>
#include <time.h>

int main()
{
  clock_t begin,end;
  double t1,t2;
  
  for(int n=1000000;n<=10000000;n+=1000000) {
    begin=clock();
    for(int i=0;i<n;i++)
       int res=factorial1(i%10);
    end=clock();
    t1=(double)(end-begin)/CLOCKS_PER_SEC;
    begin=clock();
    for(int i=0;i<n;i++)
       int res=factorial2(i%10);
    end=clock();
    t2=(double)(end-begin)/CLOCKS_PER_SEC;

    printf("%d,%lf,%lf\n",n,t1,t2);
  }
  return 0;
}