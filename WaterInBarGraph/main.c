#include <stdio.h>
#include <stdlib.h>

int min(int left,int right)
{
    //if(left > right)return right;
    //else return left;
    return (left > right ? right : left);
}
int main()
{
    int n,i,j,*Bars,*bar1,*bar2,total=0,right,left;

    printf("number of bars\n");
    scanf("%d",&n);

    Bars=malloc(sizeof(int)*n);
    bar1=malloc(sizeof(int)*n);
    bar2=malloc(sizeof(int)*n);

    printf("eneter bar graph heights\n");

    for(i=0;i<n;i++)
        scanf("%d",&Bars[i]);
    bar1[0]=-1;
    bar2[n-1]=-1;
    left=Bars[0];
    right=Bars[n-1];
    for(i=1;i<n;i++)
    {
        if(Bars[i]<=left)
        {


        bar1[i]=left;
      //  printf("%d\n",bar1[i]);

        }
        else
        {
            bar1[i]=left;
            left=Bars[i];
          //  printf("%d\n",bar1[i]);

        }

    }
    for(i=n-2;i>=0;i--)
    {
        if(Bars[i]<=right){
        bar2[i]=right;
       // printf("%d\n",bar2[i]);
        }
        else
        {
            bar2[i]=right;
            right=Bars[i];
            //printf("%d\n",bar2[i]);
        }

    }

   for(i=1;i<n-1;i++)
   {
      // printf("%d\n",min(bar1[i],bar2[i]));
       total=min(bar1[i],bar2[i])-Bars[i];
   }
    printf("\ntotal water we can store is %d",total);
    return 0;
}
