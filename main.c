#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct cloths
{
   char cloth[20];
   char brand[10];
   int price;
   int serial;
   int age;
   char myshop[50];
   struct cloths *link;
};
int s_num = 1;
int q;
struct buy
{
  char cloth[20];
  char brand[20];
  int price;
  struct buy *links;
};
struct cloths *first =NULL;
struct buy *second =NULL;
struct cloths *p;
void purchase(int i)
{
  struct cloths *p;
  struct buy *a,*t;
  a =(struct buy *)malloc(sizeof(struct buy));
  p=first;
  t=second;
   printf("\nENTER THE NUMBER OF QUANTITY YOU WANT TO ADD TO CART : ");
   scanf("%d",&q);

  while(p!=NULL)
  {
      if(i==p->serial)
      {
         strcpy(a->cloth,p->cloth);
         a->price=p->price *q;
         strcpy(a->brand,p->brand);
         if(second==NULL)
         {
             second =a;
         }
      }
      p=p->link;
  }
}
void ins(void)
{
   struct cloths *p,*t;
   t=first;
   p = (struct cloths *)malloc(sizeof(struct cloths));
   p->link =NULL;
   printf("\nENTER THE TYPE OF CLOTH      : ");
   fflush(stdin);
   gets(p->cloth);
   printf("\nENTER THE AGE(only numbers)  : ");
   scanf("%d",&p->age);
   fflush(stdin);
   printf("\nENTER THE BRAND              : ");
   gets(p->brand);
   printf("\nENTER THE ADDRESS            : ");
   gets(p->myshop);
   printf("\nENTER THE PRICE(only numbers): ");
   scanf("%d",&p->price);
   p->serial = s_num;
   if(first==NULL)
   {
     first =p;
     first->link = NULL;
   }
   else
   {
     while(t->link!=NULL)
     {
        t=t->link;
     }
     t->link =p;
   }
   s_num++;
}
void del()
{
    char key[100];
    struct cloths *prev,*t;
    printf(" ENTER THE CLOTH TYPE U WANT TO DELETE :");
    fflush(stdin);
    gets(key);
    t = first;
    if(first->link==NULL)
    {
        if(strcmp(t->cloth,key)==0)
        {
            free(t);
            first=NULL;
        }
    }
    else if(strcmp(first->cloth,key)==0&&first->link!=NULL)
    {
        first=first->link;
        free(t);
    }
    else
    {
        while(t!=NULL)
        {
            if(strcmp(t->cloth,key)!=0)
            {
                prev=t;
                t=t->link;
            }
            else
            {
                prev->link=t->link;
                free(t);
                break;
            }
        }
    }
}
void edit()
{
    int o,ag,pr;
    struct cloths *tmp;
    char add[50],br[50],ad[50];
    printf(" \n ENTER THE CLOTH U WANT TO EDIT : ");
    fflush(stdin);
    gets(add);
     tmp = first;
     while(tmp!=NULL)
     {
         if(strcmp(tmp->cloth,add)==0)
         {
             printf(" ENTER THE OPTION U WANT TO EDIT :\n ");
               printf(" 1. AGE \n 2. BRAND \n 3. ADDRESS \n 4. PRICE\n");
               scanf("%d",&o);
               switch(o)
               {
                    case 1:
                            printf(" \nREENTER THE AGE : ");
                            scanf("%d",&ag);
                            tmp->age=ag;
                            break;
                    case 2:
                            printf(" \nRENTER THE BRAND : ");
                            fflush(stdin);
                            gets(br);
                            strcpy(tmp->brand,br);
                            break;
                    case 3:
                            printf(" \nRENTER THE ADDRESS : ");
                            fflush(stdin);
                            gets(ad);
                            strcpy(tmp->myshop,ad);
                            break;
                    case 4:
                            printf(" \nRENTER THE PRICE :");
                            scanf("%d",&pr);
                            tmp->price=pr;
                            break;
                    default:
                            printf(" INVALID OPTION.");
               }
               break;
         }
         else
            tmp=tmp->link;
     }
}
void dis(void)
{
   struct cloths *p,*t;
   p=first;
   t =(struct cloths *)malloc(sizeof(struct cloths));
   if(p==NULL)
    printf("\nNO PRODUCTS ARE AVAILABLE");
    else
    {
   while(p!=NULL)
   {
       printf("\n\nCLOTH TYPE     : %s",p->cloth);
       printf("\nENTERED AGE    : %d",p->age);
       printf("\nBRAND          : %s",p->brand);
       printf("\nPRICE          : %d",p->price);
       printf("\nADDRESS        : %s",p->myshop);
       printf("\nSERIAL NUMBER  : %d",p->serial);
     p=p->link;
   }
    }
}
void c_dis(char a[])
{
   struct cloths *t;
   t=first;
    if(t==NULL)
        printf(" NO PRODUCTS AVAILABLE");
   while(t!=NULL)
   {
     if(strcmp(a,t->cloth)==0)
     {
       printf("\n\nCLOTH TYPE     : %s",t->cloth);
       printf("\nENTERED AGE    : %d",t->age);
       printf("\nBRAND          : %s",t->brand);
       printf("\nPRICE          : %d",t->price);
       printf("\nADDRESS        : %s",t->myshop);
       printf("\nSERIAL NUMBER  : %d",t->serial);
     }
      t=t->link;
   }

}
int main()
{
    int ch,s_ch,c_ch,i=1;
    char a[50];
    int code;
    struct buy *tmp;
    printf("\n\n                           WELCOME TO GAUTAM'S SHOPPING MALL\n");
    printf("                           --------------------------------- ");
  while(1)
  {
    printf("\n\n\nENTER YOUR CHOICE:\n");
    printf("\nARE YOU A....\n");
    printf("1.CUSTOMER\n2.SERVICE PROVIDER\n3.EXIT\n\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1 :{
               while(1)
               {  // dis();
                  printf("\nENTER YOUR CHOICE\n");
                  printf("\n1. BUY ITEMS\n2. BILL\n\n");
                  scanf("%d",&c_ch);
                  switch(c_ch)
                  {
                   case 1:
                    {
                      printf("\n\nPLEASE ENTER WHAT YOU ARE LOOKING FOR : ");
                      fflush(stdin);
                      gets(a);
                      c_dis(a);
                     // printf(" (serial number will be displayed only if the product is available)");
                      printf("\n\nENTER THE SERIAL NUMBER OF THE PRODUCT TO ADD IN CART : ");
                      scanf("%d",&code);
                      purchase(code);
                      break;
                    }
                   case 2:
                       {
                         tmp = second;
                         printf("\n\n              ---------------THE MALL--------------\n");
                         printf("                             --------\n");
                         printf("NAME: \t\t\t\t               DATE:\n\n");
                         printf("______________________________________________________________");
                         printf("\n| SR.NO| ITEMS         | BRAND      \t| QUANTITY | PRICE   |");
                         printf("\n--------------------------------------------------------------");
                         if(tmp==NULL)
                            printf(" \nNO PRODUCTS IN THE CART");
                        else
                        {
                         while(tmp!=NULL)
                         {
                            printf("\n %d \t %s            \t %s             \t%d          %d       ",i,tmp->cloth,tmp->brand,q,tmp->price);
                            printf("\n______________________________________________________________");
                                tmp=tmp->links;
                                printf("\n\n\n            THANK YOU FOR SHOPPING ");
                         }

                         break;
                        }
                        }
                  default:
                          printf("\nINVALID CHOICE\n");
                  }
               }
               break;
    }
    case 2 :
             {
               printf("\n1. ADD ITEM\n2. DELETE ITEM\n3. DISPLAY\n4. EDIT\n\n");
               scanf("%d",&s_ch);
               switch(s_ch)
               {
                 case 1:
                          ins();
                         break;
                 case 2:
                          del();
                          break;
                 case 3:
                          dis();
                          break;
                 case 4:
                          edit();
                          break;
                 default :
                        printf("INVALID CHOICE\n");
               }
            break;
             }
    case 3:
             exit(0);
    default :
             printf("INVALID CHOICE");
    }
  }
  return 0;
}

