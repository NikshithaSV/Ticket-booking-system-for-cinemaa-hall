#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;


}b;
void insert_details(); //To insert movie details
void viewAll(); //To view movie data
void find(); // To find a movie
void book_ticket(); //To book movie tickets
void old_record(); //To view all old booking records(Booked Tickets)
