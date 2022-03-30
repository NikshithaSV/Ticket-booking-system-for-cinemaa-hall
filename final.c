#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"final.h"

void insert_details()
{

	FILE *fp;
	struct book b;
	printf("Enter movie code:");
	scanf("%s",b.code);
	printf("Enter  name:");
	scanf("%s",b.name);
	printf("Enter Release Date:");
	scanf("%s",b.date);
	printf("Enter Ticket Price:");
	scanf("%d",&b.cost);

	fp=fopen("data.txt","a");

	if(fp == NULL)
	{
		printf("\nCannot find file!");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Recorded Successfully!");
	}
	printf("\n");
	fclose(fp);
}

void find() //find details
{
	struct book b;
	FILE *fp;

	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("Cannot find data..");

	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0)
			{
				printf("\n\t\tRECORD FOUND\n");
				printf("\n\t\tMovie code :%s",b.code);
				printf("\n\t\tMovie Name :%s",b.name);
				printf("\n\t\tRelease Date :%s",b.date);
				printf("\n\t\tTicket Price :%d",b.cost);
				break;
			}
		}

	}

	fclose(fp);
}



void viewAll()
{

	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("Cannot find file!");
		exit(1);

	}
	else
	{
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}

	fclose(fp);

}
void book_ticket()//for ticket booking

{
 	struct book b;
	FILE *fp;
	FILE *ufp;
	int total_seat,total_amount;
	char name[20];
	char mobile[11];
	char ch; //used in display all movies
	char movie_code[20]; //for searching
	// disply all movies by default for movie code
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("Cannot find file !");
		exit(1);

	}
	else
	{
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp);

	//display ends
	printf("\n TO BOOK TICKET\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("File not found !");
		exit(1);

	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tRelease Date ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}

	}
	printf("\nFILL DETAILS");
	printf("\nNAME:");
	scanf("%s",name);
	do
    	{
        printf("PHONE NUMBER\n");
        scanf("%10s",&mobile);
        if((strlen(mobile)!=10))
            printf("Invalid phone number..Enter again!\n");
    	}while(strlen(mobile)!=10);

	printf("\nNUMBER OF TICKETS :");
	scanf("%d",&total_seat);
    	total_amount = b.cost * total_seat;
        fclose(fp);

    	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("FILE NOT FOUND !");
		exit(0);
	}
	else
	{
		while(getc(fp) != EOF)
        {
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp(b.code,movie_code) == 0)
            {
                printf("\n ENJOY MOVIE \n");
                printf("\n\t\tname : %s",name);
                printf("\n\t\tmobile Number : %s",mobile);
                printf("\n\t\tmovie name : %s",b.name);
                printf("\n\t\tTotal seats : %d",total_seat);
                printf("\n\t\tcost per ticket : %d",b.cost);
                printf("\n\t\tTotal Amount : %d",total_amount);
	    


	ufp=fopen("oldTransaction.txt","a");
	if(ufp == NULL)
	{
		printf("FILE NOT FOUND");
	}
	else
	{
		fprintf(ufp,"%s %s %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
		printf("\n Record inserted successfully to Booking Record!");
	}
	printf("\n");
	fclose(ufp);
            }
          }
	}


	fclose(fp);}

void old_record()//for view all user transactions
{
	char ch;
	FILE *fp;

	fp = fopen("oldTransaction.txt","r");
	if(fp == NULL)
	{
		printf("Cannot find file!");
		exit(1);

	}
	else
	{
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}
	fclose(fp);


}

void login()
{
	int a=0,i=0;
    	char uname[10],c=' ';
    	char pword[10],code[10];
    	char user[10]="admin";
   	char pass[10]="pass";
   	do
	{

    		printf("\n ************************ ADMIN LOGIN ************************  ");
    		printf(" \n\n                  ENTER USERNAME:-");
		scanf("%s", &uname);
		printf(" \n\n                  ENTER PASSWORD:-");
		while(i<10)
		{
	    	pword[i]=getch();
	    	c=pword[i];
	    	if(c==13) break;
	    	else printf("*");
	    	i++;
		}
	pword[i]='\0';
	i=0;
	if(strcmp(uname,"admin")==0 && strcmp(pword,"pass")==0)
	{
	printf("\nLogin Successful!");
	time_t now;//Arithmetic Time Type
	time(&now);//Returned as time_t value
	printf("  \nLOGIN AT: %s\n",ctime(&now));
	printf("\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n       Login unsuccessful..Retry!");
		a++;

		getch();//holds the screen

	}
	}while(a<=2);
	if (a>2)
	{
		printf("\nWrong username and password entered more than two times!EXIT	");
		getch();
		exit(1);

	}
		

}
