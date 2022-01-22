#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include <unistd.h>
void cls()
{
    system("cls");
}
void string(char print[])
{
    printf("%s",print);
}
void newn(int line)
{
    int i;
    for( i=0; i<line; i++)
    {
        printf("\n");
    }
}
void nt(int tab)
{
    int i;
    for(i=0; i<tab; i++)
    {
        printf("\t");
    }
}


typedef struct Node
{
    char foodname[50];
    int quantity;
    float price;
    int data;
    struct Node *next;
} node;

node *head;
node  *list;

void openlist()
{
    system("COLOR CF");
    cls();
    newn(5);
    nt(3);
    string("1. Food List");
    Sleep(400);
    newn(2);
    nt(3);
    string("2. View History");
    Sleep(400);
    newn(2);
    nt(3);
    string("0. Exit");




    Sleep(400);


}


void insertend(int data, char foodname[25], int quantity, float price)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data = data;
    temp->price = price;
    temp-> quantity = quantity;
    strcpy(temp->foodname,foodname);
    temp->next = NULL;
    if(head==NULL)
    {
        head = temp;
        list = head;
    }
    else
    {
        while(head->next != NULL)
        {
            head = head->next;
        }
        head->next = temp;
    }
}


void updatefood(int udata, int uquantity)
{
    node *temp;
    temp = list;
    while(temp->data!=udata)
    {
        temp = temp->next;
    }
    if(temp->data == udata)
    {
        temp->quantity = uquantity;
    }
}
int countitem()
{
    node *temp;
    temp = list;
    int countitem=0;
    if(temp==NULL)
    {
        countitem = 0;
    }
    else
    {
        countitem = 1;
        while(temp->next != NULL)
        {
            countitem++;
            temp = temp->next;
        }
    }
    return countitem;
}
void foodlist()
{
    system("COLOR 70");

    printf("\n\t\t");

    printf("___________________________________________________________ ");

    printf("\n\t\t");

    printf("|  Food No.  |    Name         |      Price     | Quantity |");

    printf("\n\t\t");

    printf("-----------------------------------------------------------");

    node *temp;
    temp = list;
    while(temp != NULL)
    {

        printf("\n\t\t");

        printf("|     %d      |    %s     |      %0.2f    |     %d",temp->data,temp->foodname, temp->price, temp->quantity);

        printf("\n\t\t");

        printf("-----------------------------------------------------------");
        temp = temp->next ;
        Sleep(100);
    }


}
void order_view(int order, int quantity, int or_no)
{
    system("COLOR 70");
    node *temp;
    temp = list;
    while(temp->data != order)
    {
        temp = temp->next;
    }
    if(temp->data == order)
    {

        printf("\n\t\t");

        printf("|     %d      |    %s  |     %d     |     %d     |",or_no,temp->foodname,quantity,temp->quantity);

        printf("\n\t\t");

        printf("-------------------------------------------------------");
        Sleep(100);
    }

}



void loadingbar(void)
{
    int i;
    for ( i=15; i<=100; i+=5)
    {
        cls();

        newn(7);
        nt(4);
        printf("%d %% Loading...\n\n\t\t",i);
        printf("");
        int j;
        for (j=0; j<i; j+=2)
        {

            printf(" ");

        }
        Sleep(100);

    }
}

typedef struct Queue
{
    char customer[50];

    int num;
    struct Node *point;
} queue;

queue *front=NULL;
queue* rear=NULL;

void makequeue (int x, char customer[50])
{
    queue *temp=(queue*)malloc(sizeof(queue));
    temp->num=x;
    temp->point=NULL;
    strcpy(temp->customer, customer);
    if (front ==NULL && rear ==NULL)
    {
        front=rear=temp;
        return;
    }
    rear->point=temp;
    rear=temp;

}
void deque()
{
          queue* temp=front;
          if (front == NULL)
                return;
          if (front==rear)
          {
              front=rear=NULL;
          }
          else
          {
              front=front->point;
          }
          free(temp);


}

void display()
{
    queue *head;
    head=front;
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        while(head!=NULL)
        {

            printf("\t\t\t\t%d. ", head -> num);
        printf("%s\n", head -> customer);
        head=head->point;
        }
    }
}


int main()
{
    system("COLOR CF");
    system("title ..................TOUSIF RESTAURANT.......................");
    system("mode con: cols=80 lines=30");
    loadingbar();
    cls();

    Sleep(300);
    cls();
    int c=0;


    float totalmoney = 0;
    int total_order[100];
    int orderquantity[100];
    int order=0;
    int uquantity;

    head = NULL;

    insertend(1,"BIRIYANI",200,120.00);
    insertend(2,"ICECREAM",50,200);
    insertend(3,"STEAK\t  ",56,999.5);
    insertend(4,"SOUP\t  ",100,200);
    insertend(5,"GRIll\t  ",100,320.50);
    insertend(6,"BREAD\t  ",50,150);
    insertend(7,"BEVERAGE",1000,100);

    makequeue(1,"tousif");
    makequeue(2,"rahim");
    makequeue(3,"karim");


mainmenu:
    newn(1);
    openlist();
    newn(5);
    nt(3);

    int openlistchoice;
    newn(1);
    nt(4);
    fflush(stdin);
    scanf("%d",&openlistchoice);
    if((openlistchoice >=1 && openlistchoice <3))
    {
        if(openlistchoice == 1)
        {
foodlist:
            cls();
            string("=> 0. Main Menu ");
            foodlist();
        }
        else if( openlistchoice == 2)
        {

            node *temp;
            temp = list;
choise:
            cls();
            newn(5);
            nt(4);


            printf(" 1. Today's total bill \n\n");

            Sleep(250);
            nt(4);

            printf(" 2. View Food List \n\n");
            Sleep(250);
            nt(4);
            printf(" 3. Item Counter \n\n");

            Sleep(250);
            nt(4);
            printf(" 4. Order Preview\n\n");
            Sleep(250);
            nt(4);
            printf(" 5. Customer list\t[FIFO]\n\n");

            nt(4);
            printf(" *. Order amount %d .*", order);
            Sleep(250);


            nt(9);
            printf(" \n\n\t\t\t\t0. Main Menu ");
            Sleep(250);
            int mychoise;
            fflush(stdin);
            scanf("%d",&mychoise);
            if(mychoise==1)
            {
                cls();
                newn(6);
                nt(4);
                printf("Todays Total Cash : %0.2f  \n",totalmoney);
                Sleep(2000);
                goto choise;
            }


            else if(mychoise==2)
            {
                cls();
                foodlist();
                Sleep(1000);
                newn(2);
                nt(4);

                Sleep(6000);
                goto choise;
            }
            else if(mychoise==3)
            {

                cls();
                newn(6);
                nt(4);
                printf("Total Food Item is --> %d  \n",countitem());
                Sleep(2000);
                goto choise;
            }

            else if(mychoise==4)
            {
                cls();
                newn(2);
                nt(2);

                printf("\n\t\t");

                printf("______________________________________________________ ");

                printf("\n\t\t");

                printf("|  Order No.  |   FooD Name   |  Quantity |  In Stock |");

                printf("\n\t\t");

                printf("------------------------------------------------------");

                int o;
                for(o=1; o<=order; o++)
                {
                    order_view(total_order[o],orderquantity[o],o);
                }
                newn(2);
                nt(4);
                Sleep(6000);
                goto choise;
            }
            else if(mychoise==5)
            {
                cls();
                newn(2);

                display();
                Sleep(6000);
                goto choise;

            }

            else if(mychoise==0)
            {
                goto mainmenu;
            }
            else
            {
                newn(2);
                nt(4);
                printf("Please Select From List :  ");
                Sleep(500);
                goto choise;
            }
        }


        else
        {
            newn(2);
            nt(4);
            printf("Please Enter Correct Choice");
            goto mainmenu;
        }
    }


    else
    {
        cls();
        newn(6);
        nt(3);
        printf("\tA big applause to you!\n\n\n\n\n\n\n");
        Sleep(1000);
        exit(0);
    }
    int getfoodnum;
    newn(2);
    nt(3);
    fflush(stdin);
    printf("Place Your Order: ") ;
    scanf("%d",&getfoodnum);
    if(getfoodnum==0)
    {
        goto mainmenu;
    }
    node *temp;
    temp = list ;
    while(temp->data != getfoodnum)
    {
        temp = temp->next;

    }
    if(getfoodnum == temp->data)
    {
fcquantity:
        newn(2);
        nt(3);
        string("Enter Food Quantity : ");
        int fquantity;
        fflush(stdin);
        scanf("%d",&fquantity);
        cls();
        if(fquantity==0)
        {
            cls();
            newn(6);
            nt(3);
            printf("Quantity can't be 0 ");
            Sleep(2000);
            cls();
            goto foodlist;
        }
        else if(fquantity>temp->quantity)
        {
            cls();
            newn(6);
            nt(3);
            printf("Out of Stock ! ");
            Sleep(2000);
            goto foodlist;
        }
        newn(6);
        nt(4);
        printf("Choice food %s  \n\n\t\t\t\tIt's price is %0.2f/== \n\n",temp->foodname,temp->price*fquantity);
        nt(4);
        printf("1. Confirm to buy this \n\n");
        nt(4);
        printf("2. Food List  ");
confirm:

        fflush(stdin);
        int confirm;
        scanf("%d",&confirm);
        if(confirm == 1 )
        {
            newn(2);
            nt(4);
            printf(" 1. Cash ");
            newn(2);
            nt(4);

payment:

            fflush(stdin);
            int payment;
            scanf("%d",&payment);
            if(payment==1)
            {
                totalmoney += temp->price*fquantity;
                order++;

                deque();
                total_order[order]=getfoodnum;
                orderquantity[order]=fquantity;
                uquantity = temp->quantity - fquantity;
                updatefood(getfoodnum,uquantity);
                cls();
                newn(6);
                nt(4);
                string("THANK YOU");
                newn(2);
                nt(4);
                string("Food Ordered Successfully ...");

                newn(2);
                nt(4);
                string("1. Buy Another Food? ");
                newn(2);
                nt(4);
                string("2. Main Menu ");


openlist:

                fflush(stdin);
                int getmenu;
                scanf("%d",&getmenu);

                if(getmenu==1)
                {
                    goto foodlist;
                }
                else if(getmenu==2)
                {
                    goto mainmenu;
                }
                else
                {
                    newn(2);
                    nt(4);
                    string("Please Choice from list : ");
                    goto openlist;
                }
            }

            else
            {
                newn(2);
                nt(4);
                string("Enter Choice from List : ");
                goto payment;
            }
        }
        else if(confirm == 2)
        {
            goto foodlist;
        }
        else
        {
            newn(2);
            nt(4);
            string("Enter Choise from List : ");
            goto confirm;
        }
    }
    else
    {
        newn(2);
        nt(4);
        string("Please Choice From List ");
        newn(2);
        Sleep(300);
        goto foodlist;
    }
}



















