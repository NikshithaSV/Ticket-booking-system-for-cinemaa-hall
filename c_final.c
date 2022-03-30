#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "final.h"
void main()
{	printf("\n      ******************************************************");
	printf("\n             WELCOME TO MOVIE TICKET BOOKING SYSTEM 		");
	printf("\n      ******************************************************");
 	login();
    	clock_t st,end;
    	double tt;
    	int t;
    	int t1;
    	st=clock();
	   
	int ch;
 	do{
	printf("\nEnter (1)To Insert Movie");
   	printf("\nEnter (2) To View All Movie");
	printf("\nEnter (3) To Find Movie ");
	printf("\nEnter (4) To Book Tickets");
	printf("\nEnter (5) To View All Transactions");
   	printf("\nEnter (0) To Exit ");

   	printf("\nEnter your Choice(0-5)");
   	scanf("%d",&ch);
	system("cls");

   	switch (ch)
   	{
    		case 1 :
    		insert_details();
   		break;
		
		case 2:
    		viewAll();
   		break;

		case 3:
    		find();
   		break;

		case 4:
		book_ticket();
		break;

		case 5:
		old_record();
		break;

    		case 0:
		;
		time_t now;//Arithmetic Time Type
		time(&now);//Returned as time_t value
		printf("\nLOGOUT AT: %s\n",ctime(&now));
		end=clock();
		tt=(double)(end-st)/CLOCKS_PER_SEC;
		if(tt>=60)
		{t1=(int)(tt/60);
		 t=(int)tt%60;}
		printf("TIME SPENT BY ADMIN ON PORTAL: %dmin %dsecs \n",t1,t);
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice!!Enter again..");
    		break;
   	}
 }while(ch!=0);





}
