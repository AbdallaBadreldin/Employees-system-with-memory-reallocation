#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct employee
{
    int id;
    char name[50];
    float age;
    int salary;
    int bouns;
    int deduct;
};

void displayMainMenu (int,int);
struct employee * empArr ;
//void addEmployee( int id,char name[50],float age,int salary,int bouns,int deduct);
void addEmployeeDisplay();
void gotoxy(int, int );


int main()
{
    //char selection='0';
    int arraySize=0;
      int pointer;
    int pointerX=28;
    int pointerZ [4]= {5,10,15,20};
int select=0;

    for(;;)
    {
        pointer = 0;
        //system("cls");
        //printf("\n\n\t\t1) Add employee or more\n");
        //printf("\n\n\t\t2) Display employees data\n");
        //printf("\n\n\t\t3) Clear all data\n");
        //printf("\n\n\t\t4) Exit\n");
        //printf("\n\n\n Enter selection number = ");
 displayMainMenu(pointerX,pointerZ[pointer]);

       for(;;)  //I don't konw what tyo do here
        {

            select = getch();
             flushall;
            if (select==13)   //enter = 13
            {

                break;
            }
            if (select==80)  //up arrow = 80
            {

                pointer++;
                if(pointer==4)
                    pointer =0;
                //printf(" ");                               //I want to delete the pointer '?'
                displayMainMenu(pointerX,pointerZ[pointer]);
                gotoxy(pointerX,pointerZ[pointer]);
                printf(">");
            }

            if (select==72) //down arrow
            {
                if(pointer ==0)
                    pointer=4;
                pointer--;
               displayMainMenu(pointerX,pointerZ[pointer]);
               //printf(' ');                                   //trying to delete
               gotoxy(pointerX,pointerZ[pointer]);
                printf(">");
            }

        }
        flushall;

        switch(pointer)
        {
        case 0:
            system("cls");
            if (arraySize==0)
            {
                printf("Enter the array size: ");
                scanf("%d",&arraySize);
                if(arraySize<1)
                    continue;
                empArr=(struct employee*)malloc(arraySize*sizeof(struct employee));
            for (int i=0; i<arraySize; i++)
            {
                system("cls");
                displayEmployeeAttributes();

                gotoxy(20,5);
                scanf("%d",&empArr[i].id);

                gotoxy(47,5);
                scanf("%s",&empArr[i].name);

                gotoxy(22,10);
                scanf("%f",&empArr[i].age);

                gotoxy(49,10);
                scanf("%d",&empArr[i].salary);

                gotoxy(23,15);
                scanf("%d",&empArr[i].bouns);

                gotoxy(49,15);
                scanf("%d",&empArr[i].deduct);
               }
            printf("\n\ndata insterted successfully");

            }
            else{

                printf("Add one more user");
                empArr= (struct employee *) realloc(empArr,(++arraySize)*sizeof(struct employee));
                getch();
                system("cls");
                displayEmployeeAttributes();
                int i =arraySize-1;

                gotoxy(20,5);
                scanf("%d",&empArr[i].id);

                gotoxy(47,5);
                scanf("%s",&empArr[i].name);

                gotoxy(22,10);
                scanf("%f",&empArr[i].age);

                gotoxy(49,10);
                scanf("%d",&empArr[i].salary);

                gotoxy(23,15);
                scanf("%d",&empArr[i].bouns);

                gotoxy(49,15);
                scanf("%d",&empArr[i].deduct);
 printf("\n\ndata insterted successfully");

            }

            break;


        case 1:
            system("cls");
            if (arraySize==0)
            {
                printf("No data is found\n");
                break;
            }
            for(int i= 0; i<arraySize; i++)
            {
                system("cls");
                displayEmployeeAttributes();

                gotoxy(20,5);
                printf("%d",empArr[i].id);

                gotoxy(47,5);
                printf("%s",empArr[i].name);

                gotoxy(22,10);
                printf("%f",empArr[i].age);

                gotoxy(49,10);
                printf("%d",empArr[i].salary);

                gotoxy(23,15);
                printf("%d",empArr[i].bouns);

                gotoxy(49,15);
                printf("%d",empArr[i].deduct);

                printf("\n\npress any thing to show next");
                pointer = getch();
                flushall;

            }

            break;

        case 2:
            arraySize=0;
            free(empArr);
            continue ;

        case 3:
            free(empArr);
            return 0;

        default:
            continue;
        }
        printf("\n\npress anything to continue ");

        pointer=  getch();
        flushall;

    }
}
void displayMainMenu(int x,int y)
{
    system("cls");

    gotoxy(x,y);
    printf(">");
    gotoxy(30,5);
    printf("1) Add employees");
    gotoxy(30,10);
    printf("2) Display employees\n");
    gotoxy(30,15);
    printf("3) Clear all data\n");
    gotoxy(30,20);
    printf("4) Exit");
    }
void displayEmployeeAttributes( )
{
    gotoxy(15,5);
    printf("id:");

    gotoxy(40,5);
    printf("name:");

    gotoxy(15,10);
    printf("age:");

    gotoxy(40,10);
    printf("salary:");

    gotoxy(15,15);
    printf("bouns:");

    gotoxy(40,15);
    printf("deduct:");

}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
