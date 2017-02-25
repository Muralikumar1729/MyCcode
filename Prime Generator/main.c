/*
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input

The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testcase,*from,*to,i,j,k;
    scanf("%d",&testcase);
    if(testcase>10)return ;
    from=malloc(sizeof(int)*testcase);
    to=malloc(sizeof(int)*testcase);
    /*for(i=0;i<testcase;i++)
    {   scanf("%d",&from[i]);
        scanf("%d",&to[i]);

        if(1>= to[i] || from[i] > 1000000000 || to[i] > 1000000000 || (to[i]-from[i])>100000)return;

    }*/
    for(i=0;i<testcase;i++)
    {
        int low=from[i];
        int high=to[i];
        while(low<=high)
        {
         int flag=0;int j;
         for(j= 2; j <= low/2; ++j)
            {
                if(low % j == 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            if(low!=1)printf("\n%d", low);

            ++low;
        }

        printf("\n");
    }

    return 0;
}

     /*for(k=from[i];k<to[i];k++)
    {   int count=0;
        for(j=2;j<=k;j++)
        {
            if(k%j==0)count++;
        }
    if(count==2)printf("%d\n",k);
    }
   */
