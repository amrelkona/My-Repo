#include <stdio.h>
#include <stdlib.h>

int x;
char z2[100] = "No tasks available!";
char z1[100] = "No tasks available!";
char z[100] = "No tasks available!";
char z3[100] = "Fo back to main menu";
int u;
int m;
int n;
void f1()
{
    printf("Welcome back to Minions Task Manager");
    printf("1:Add task\n");
    printf("2:View tasks\n");
    printf("3:Remove a task\n");
    printf("4:Exit\n");
    printf("Enter a number: ");
    scanf("%d",&x);
    if (x==1)
    {
        while(1)
        {
            printf("Enter task: ");
            scanf("%s",&z);
            gets(z);
            printf("Task added successfully!\n");
            printf("do yo wish to add another task?\n");
            scanf("%d",&u);
            if (u==0)
            {
                f1();
            }
            else if(u==1)
            {
                printf("Enter task: ");
                scanf("%s,&z2");
                gets(z1);
                printf("Task added successfully!\n");
                f1();
            }
        }
    }
    else if (x==2)
    {
        {
            printf("1-%s\n",z);
            printf("2-%s\n",z1);
            printf("3=%s\n",z2);
            printf("Do you wish to go back to main menu?(1:yes)");
            scanf("%d",&m);
            f1();
        }
    }
    else if (x==3)
    {
        printf("1-%s\n",z);
        printf("2-%s\n",z1);
        printf("3-%s\n",z2);
        printf("4-%s\n",z3);
        printf("Select which task you want to remove: \n");
        scanf("%d\n",&n);
        printf("Task Removed\n");
        if (n=1)
        {
            z[100] = "You have no tasks!\n";
        }
        else if (n=2)
        {
            z1[100] = "You have no tasks!";
        }
        else if (n=3)
        {
            z2[100] = "You have no tasks!\n";

        }
        else if (n=4)
        {
            printf("Try again\n");

        }
        else if (x=4)
        {
            printf("Hope to see you again\n");
        }
    }
            }
int main ()
{
    f1();
}
