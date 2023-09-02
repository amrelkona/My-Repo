#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{int x;
printf("Please enter x");
scanf("%d",&x);
while (x>=1)
    {printf("%d\n",x);
x=x-1;
sleep(1);
if (x<=0)
{break;

}

}

}
