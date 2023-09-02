#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{float x,y,z,a;
printf("please enter the first reading for sensor 1: ");
scanf("%f",&x);
printf("please enter the second reading for sensor 1: ");
scanf("%f",&y);
printf("please enter the third reading for sensor 1");
scanf("%f",&z);
a=(float)((x+y+z)/3.0);
printf("%f",a);

float b,c,d,f;
printf("please enter the first reading fpr sensor 2: ");
scanf("%f",&b);
printf("please enter the second reading for sensor 2: ");
scanf("%f",&c);
printf("please enter the third reading for sensor 2");
scanf("%f",&d);
f=(float)((b+c+d)/3.0);
printf("%f",f);
int o;
o=(float)((f+a)/2.0);
printf("%f",o);




    return 0;
}
