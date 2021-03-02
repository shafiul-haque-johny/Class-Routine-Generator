#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void create_cr();
int edit_cr(int n);
int show_crList(int n);
int delete_cr(int n);
int search_cr(int n);

struct men_info
{
    char name[50];
    char address[100];
    char phn_number[1000];
    char email[100];
}list[100];

int n,i,flag=0,flag2=0,choice2;
char match_name[100];
char eName[100],eEmail[100],eAddress[100];
char  ePhn_Number[1000];
 int indexNoCollect;

int main()
{
  int choice;

do
{
    printf("\n\n1 for create a new class routine\n");
    printf("2 for edit class routine\n");
    printf("3 for delete class routine\n");
    printf("4 for search class routine\n");
    printf("5 for View All class routine\n");
    printf("6 for exit\n");
    printf("\n\nEnter Choice: \n");
    scanf("%d",&choice);
   switch(choice)
   {

        case 1:
            flag=1;
            create_cr();
            break;
        case 2:
            edit_cr(n);
            break;
        case 3:
            delete_cr(n);
            break ;
        case 4:
            search_cr(n);
            break;
        case 5:
            showcrList(n);
            break;
        case 6:
            exit(0);
            break;



   }

}
while(1);

}



void create_cr()
{
   printf("How many course do u have?\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("Enter %d course name :\n",i+1);
         fflush(stdin);
       gets(list[i].name);
       printf("Enter %d faculty name:\n",i+1);
       gets(list[i].address);
       printf("Enter %d room number:\n",i+1);
       gets(list[i].phn_number);
       printf("Enter %d time day and section:\n",i+1);
       fflush(stdin);
       gets(list[i].email);
       printf("\n\n");

   }
}


int edit_cr(int n)
{
   if(flag==0)
   {
       printf("\nAttention!\nPlease add course first\n\n");
       return 1;
   }
   else
     {
          printf("\nEnter the course name that you want to edit\n");
          fflush(stdin);
          gets( match_name);
          printf("\nWhat do you want to edit:\n");
          printf("1 for Name\n");
          printf("2 for #room \n");
          printf("3 for time,day and section \n");
          printf("4 for faculty\n");
          printf("\n\nEnter your choice\n");
          scanf("%d",&choice2);

          if(choice2==1)
          {
              printf("Enter new course name: \n");
              fflush(stdin);
              gets(eName);

          }
          else if(choice2==2)
          {
              printf("Enter new room number:\n ");
              fflush(stdin);
              gets(ePhn_Number);
          }
          else if(choice2==3)
          {
              printf("Enter new  time:\n");
              gets(eEmail);
          }
          else if(choice2==4)
          {
              printf("Enter new faculty: \n");
              fflush(stdin);
              gets(eAddress);
          }
          else
          {
              printf("Invalid choice\n");
          }

        for(i=0;i<n;i++)
        {
            if(strcmp(list[i].name,match_name)==0)
            {
                if(choice2==1)
                {
                    strcpy(list[i].name,eName);
                    break;
                }
                else if(choice2==2)
                {
                    strcpy(list[i].phn_number,ePhn_Number);
                    break;
                }
                else if(choice2==3)
                {
                    strcpy(list[i].email,eEmail);
                    break;
                }
                else if(choice2==4)
                {
                    strcpy(list[i].address,eAddress);
                    break;
                }

            }

        }
     }
}


int showcrList(int n)
{
    if(flag==0)
    {
        printf("Please Add course First\n");
        return 1;
    }
    else if(flag==1 && flag2!=1)
    {
        printf("\nAll course List: \n");
        for(i=0;i<n;i++)
        {
            printf("\n%d.course Name & day:  ",i+1);
            printf("%s",list[i].name);
            printf("   #room:   %s",list[i].phn_number);
            printf("   time day & section:   %s",list[i].email);
            printf("   faculty:   %s\n",list[i].address);
        }
    }
    else if(flag2==1)
    {
        printf("\nAll course List: \n");
        for(i=0;i<n-1;i++)
        {
            printf("\n%d.course Name :  ",i+1);
            printf("%s",list[i].name);
            printf("   #room:   %s",list[i].phn_number);
            printf("   time,day and section:   %s",list[i].email);
            printf("   faculty:   %s\n",list[i].address);
        }
    }
}


int delete_cr(int n)
{
    flag2=1;

    int j;
   if(flag==0)
   {
       printf("\n\nPlease add course first\n\n");
       return 1;
   }
   else
   {
       printf("\nEnter the course name that you want to delete\n");
       fflush(stdin);
       gets(match_name);

       for(i=0;i<n;i++)
       {

        if(strcmp(list[i].name,match_name)==0)
            {
             indexNoCollect=i;
            }
       }

       for(i=0,j=0;i<n;i++)
       {
           if(i==indexNoCollect)
           {
               continue;
           }
           else
           {
               strcpy(list[j].name,list[i].name);
               strcpy(list[j].phn_number,list[i].phn_number);
               strcpy(list[j].email,list[i].email);
               strcpy(list[j].address,list[i].address);
               j++;
           }
       }


   }
}
int search_cr(int n)
{
     if(flag==0)
     {
         printf("\n\nNo course Found!\n\n");
         return 1;
     }
     else
     {
        printf("\nEnter the course name that you want to search\n");
       fflush(stdin);
       gets(match_name);
        for(i=0;i<n;i++)
        {
            if(strcmp(list[i].name,match_name)==0)
                {
                    indexNoCollect=i;
                    break;
                }
        }

        for(i=indexNoCollect;i<=indexNoCollect;i++)
        {
            printf("Name: %s\t#room:  %s\ttime,day and section:  %s\tfaculty:  %s\n",list[i].name,list[i].phn_number,list[i].email,list[i].address);
        }

     }
}
