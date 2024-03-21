/*
Tyler Sexton
lab 7
Phonebook with new options to search, sort, randomize, and delete.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct person{
  char firstName[20];
  char lastName[20];
  char phoneNumber[15];
}contact;

//Function prototypes
void addFriend(contact **phoneBook, int *contactCount);

int compare(const void *a, const void *b);

//Main
int main() {

int r, found, contactCount = 0, arraySize = 10;
char firstName[20], lastName[20];
int *pCount = &contactCount;

contact *phoneBook = NULL;

int menuInput;

//Displayed menu
while (1){
printf("\nPhone Book Application\n");
printf("1) Add friend\n");
printf("2) Delete friend\n");
printf("3) Show phonebook\n");	
printf("4) Search\n");
printf("5) Sort\n");
printf("6) Random\n");
printf("7) Delete Phonebook");

printf("\nWhat do you want to do?\n");
scanf("%d",&menuInput);

switch (menuInput)
  {
//Add Friend
  case 1:
    addFriend(&phoneBook,pCount);
  break;
//Delete Friend
  case 2:
    printf("First name:");
    scanf("%s",&firstName);
    printf("Last name:");
    scanf("%s",&lastName);
    
    for (int i = 0;i<*pCount;i++)
	{
	  if (strcmp(firstName, phoneBook[i].firstName)==0 && strcmp(lastName,phoneBook[i].lastName)==0)
	  {
	    for (int j = i;j<*pCount-1;j++)
          {
		    phoneBook[j]=phoneBook[j + 1];
	      }	  
	  (*pCount)--;
	  break;
	  }	
    }
    break;
//Show Phonebook
  case 3:
    printf("\nPhonebook Entries:\n");
    for (int i = 0;i<*pCount;i++)
    {
      printf("\n%s %s %s\n",phoneBook[i].firstName,phoneBook[i].lastName,phoneBook[i].phoneNumber);
    }  
    break;
//Search
  case 4:
  	printf("\nFirst name:");
    scanf("%s",firstName);
    printf("Last name:");
    scanf("%s",lastName);
    
	for (int i = 0;i<*pCount;i++)
	{
	  if (strcmp(firstName, phoneBook[i].firstName)==0 && strcmp(lastName,phoneBook[i].lastName)==0)
	  {
	    found = 1;
		printf("\n%s %s %s\n",phoneBook[i].firstName,phoneBook[i].lastName,phoneBook[i].phoneNumber);
	  }
	}
	if (found != 1)
	{	
	  printf("\nContact not found\n");
    }
	break;  
//Sort
  case 5:
  	qsort(phoneBook, *pCount, sizeof(contact), compare);
    
    printf("\nContacts\n");
     for (int i = 0; i < *pCount; i++) 
	 {
        printf("%s %s %s\n", phoneBook[i].firstName, phoneBook[i].lastName, phoneBook[i].phoneNumber);
     }
    break;
//Random Contact  
  case 6:
    srand(time(NULL));
    r = rand() % (*pCount);
    printf("%s %s %s\n", phoneBook[r].firstName, phoneBook[r].lastName, phoneBook[r].phoneNumber);
    break;
//Delete Phone Book  
   case 7:
    free(phoneBook);
    contactCount = 0;
    phoneBook = NULL;
    printf("\n Phonebook Deleted.\n");
    break;
  }
 }	
return 0;
}

//Function def used to sort
int compare(const void *a, const void *b) {
    return strcmp(((const contact *)a)->lastName, ((const contact *)b)->lastName);
}
//Function def to Add Friend
void addFriend(contact **phoneBook, int *contactCount) {
    *phoneBook = (contact*)realloc(*phoneBook, (*contactCount + 1) * sizeof(contact));

    if (*phoneBook == NULL) {
        printf("Could not allocate memory");
        exit(1);
    }
    printf("\nFirst name:");
    scanf("%s", (*phoneBook)[*contactCount].firstName);

    printf("Last name:");
    scanf("%s", (*phoneBook)[*contactCount].lastName);

    printf("Phone number:");
    scanf("%s", (*phoneBook)[*contactCount].phoneNumber);
    
	(*contactCount)++;

    printf("\nadded\n");
}