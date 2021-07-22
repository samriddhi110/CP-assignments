#include <stdio.h>
#include <stdlib.h>
struct user{
    int accountno;
    char name[25];
    char address[75];
    char phone[14];
    float money;
};
void menu();
void createaccount(){
    FILE *info;
    info = fopen ("userinfo.txt","w");
    if (info == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    
    int exit_menu;
    struct user user1;
    printf("Account number:\n");
    scanf("%d",&user1.accountno);
    
    printf("Name:\n");
    scanf("%s",user1.name);
    
    printf("Address:\n");
    scanf("%s",user1.address);
   
    printf("phone:\n");
    scanf("%s",user1.phone);
    
    printf("money to be deposited:\n");
    scanf("%f",&user1.money);
    
    fprintf(info,"%d\n",user1.accountno);
    fprintf(info,"%s\n",user1.name);
    fprintf(info,"%s\n",user1.address);
    fprintf(info,"%s\n",user1.phone);
    fprintf(info,"%f\n",user1.money);
    fclose(info);
    printf("\nAccount created successfully\n");
    printf("Enter 1 to go to the main menu and 0 to exit:\n");
    scanf("%d",&exit_menu);
     if (exit_menu==1)
    menu();
     
    else if(exit_menu==0)
        exit(0);
}

void withdraw(){
    struct user user1;
    int account;
    float moneywithdrawn;
    int exit_menu;
    FILE *old,*newrec;
    old =fopen("userinfo.txt","r");
    newrec =fopen("newinfo.txt","w");
    printf("\nEnter the account no. of the customer:\n");
    scanf("%d",&account);
    fscanf(old,"%d %s %s %s %f",&user1.accountno, user1.name,user1.address,user1.phone,&user1.money);
    if(user1.accountno == account){
        printf("Enter the amount you want to withdraw:");
        scanf("%f",&moneywithdrawn);
        if(user1.money>moneywithdrawn){
        user1.money-=moneywithdrawn;
        fprintf(newrec,"%d %s %s %s %f",user1.accountno, user1.name,user1.address,user1.phone,user1.money);
        printf("\n Amount Withdrawn successfully\n");
        }
        else
        printf("\nNot enough balance\n");
    }
    else{
    printf("\nWrong account number\n");
    }
   fclose(old);
   fclose(newrec);
   remove("userinfo.txt");
   rename("newinfo.txt","userinfo.txt");
    printf("\nEnter 1 to go to the main menu and 0 to exit:\n");
    scanf("%d",&exit_menu);
     if (exit_menu==1)
    menu();
     
    else if(exit_menu==0)
        exit(0);
}

void deposit(){
    
    struct user user1;
    int account;
    float deposit;
    int exit_menu;
    FILE *old,*newrec;
    old =fopen("userinfo.txt","r");
    newrec =fopen("newinfo.txt","w");
    printf("\nEnter the account no. of the customer:\n");
    scanf("%d",&account);
    fscanf(old,"%d %s %s %s %f",&user1.accountno, user1.name,user1.address,user1.phone,&user1.money);
    if(user1.accountno == account){
        printf("Enter the amount you want to deposit:");
        scanf("%f",&deposit);
        user1.money+= deposit;
        fprintf(newrec,"%d %s %s %s %f",user1.accountno, user1.name,user1.address,user1.phone,user1.money);
        printf("\n Amount Deposited successfully\n");
    }
    else{
    printf("\nWrong account number\n");
    }
   fclose(old);
   fclose(newrec);
   remove("userinfo.txt");
   rename("newinfo.txt","userinfo.txt");
    printf("\nEnter 1 to go to the main menu and 0 to exit:\n");
    scanf("%d",&exit_menu);
     if (exit_menu==1)
    menu();
     
    else if(exit_menu==0)
        exit(0);
}


void display()
{
    
struct user user1;
int exit_menu,account;
    FILE *view;
    view = fopen("userinfo.txt","r");
    printf("\nEnter the account number:\n");
    scanf("%d",&account);
    fscanf(view,"%d %s %s %s %f",&user1.accountno, user1.name,user1.address,user1.phone,&user1.money);
    if(user1.accountno == account){
    printf("\nAccount number\t%d",user1.accountno);
    printf("\nName\t%s",user1.name);
    printf("\nAddress\t%s",user1.address);
    printf("\nPhone\t%s",user1.phone);
    printf("\nMoney\t%f",user1.money);
    
    fclose(view);
    }
    else {
        printf("No Records Found");
    }
    printf("\nEnter 1 to go to the main menu and 0 to exit:\n");
    scanf("%d",&exit_menu);
     if (exit_menu==1)
    menu();
     
    else if(exit_menu==0)
        exit(0);
    
}
void delete()
{
    
struct user user1;
    FILE *old,*newrec;
    int account,n=0;
    old = fopen("userinfo.txt","r");
    newrec = fopen("delete.txt","w");
    int exit_menu;
    printf("\nEnter the account no. of the customer you want to delete:\n");
    scanf("%d",&account);
    fscanf(old,"%d %s %s %s %f",&user1.accountno, user1.name,user1.address,user1.phone,&user1.money);
    if(user1.accountno == account){
        fprintf(newrec,"%d %d %d %d %d",n, n,n,n,n);
        printf("\n Account Deleted successfully\n");
    }
    else{
    printf("\nNo Record Found\n");
    }
   fclose(old);
   fclose(newrec);
   remove("userinfo.txt");
   rename("delete.txt","userinfo.txt");
    printf("\nEnter 1 to go to the main menu and 0 to exit:\n");
    scanf("%d",&exit_menu);
     if (exit_menu==1)
    menu();
     
    else if(exit_menu==0)
        exit(0);
    }  

void menu(){
    int choice;
    printf("\t\t\t\t\t------WELCOME TO THE BANK SYSTEM------\n");
    printf("Enter a number to continue further\n");
    printf("PRESS 1 TO CREATE AN ACCOUNT\n");
    printf("PRESS 2 TO DISPLAY THE DETAILS\n");
    printf("PRESS 3 TO WITHDRAW MONEY\n");
    printf("PRESS 4 TO DEPOSIT MONEY\n");
    printf("PRESS 5 TO DELETE AN ACCOUNT\n");
    printf("PRESS 0 TO EXIT\n ");
    
    do{
         scanf("%d",&choice);
            switch(choice){
        case 1:
            printf("creating an account\n");
            createaccount();
            break;
        case 2:
            printf("Displaying details\n");
            display();
            break;
        case 3:
            printf("withdrawing money");
            withdraw();
            break;
        case 4:
            printf("depositing money");
            deposit();
            break;
        case 5:
            printf("deleting an account");
            delete();
            break;
        case 0:
            printf("Thank you for using our services");
            exit(0);
            break;
            default:
            printf("wrong input try again\n");
            break;
        }
    }
    while(choice>=6);
    
}
int main(){
    menu();
    }