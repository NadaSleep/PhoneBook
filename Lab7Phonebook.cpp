/*
Tyler Sexton
lab 7
Phonebook with new options to search, sort, randomize, and delete.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTACTS 100 

typedef struct person{
  char firstName[20];
  char lastName[20];
  char phoneNumber[15];
}contact;

//Function Prototypes
void addFriend(contact **phoneBook, int *contactCount);
int compare(const void *a, const void *b);
void saveContacts(contact phoneBook[],int contactCount,char* fileName);
int loadContacts(contact phoneBook[],char* fileName);

//Main
int main() {

int r, found, contactCount = 0, arraySize = 10;
char firstName[20], lastName[20], fileName[50];
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
printf("7) Save Contacts\n");
printf("8) Load Contact List\n");
printf("9) Delete Phonebook");

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
//Save Phone Book
  case 7:
    printf("What would you like to name the file?\n");
    scanf("%s",fileName);
    strcat(fileName, ".txt");
    saveContacts(phoneBook,contactCount,fileName);
  break;
//Load Phone Book
  case 8:
    phoneBook = (contact*)malloc(MAX_CONTACTS* sizeof(contact));
    printf("What is the file name you would like to load?\n");
    scanf("%s",fileName);
    strcat(fileName, ".txt");
    contactCount = loadContacts(phoneBook,fileName);
  break;
//Delete Phone Book  
   case 9:
    free(phoneBook);
    contactCount = 0;
    phoneBook = NULL;
    printf("\n Phonebook Deleted.\n");
    break;
  }
 }	
free(phoneBook);
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
//Function def to Save Contacts
void saveContacts(contact phoneBook[],int contactCount,char* fileName) {
	FILE *fp=fopen(fileName,"w");
    if(fp==NULL){
      printf("Error opening the file");
	  return;
	}

  for(int i=0;i<contactCount;i++) {
  	  fprintf(fp,"%s %s %s\n",phoneBook[i].firstName,phoneBook[i].lastName,phoneBook[i].phoneNumber);
  }
  fclose(fp);
}

//Function def to Load Contacts
int loadContacts(contact phoneBook[],char* fileName) {
int contactCount = 0;  
//Open Stream
  FILE* fp=fopen(fileName,"r");
  if (fp==NULL) {
  	printf("Error in opening %s",fileName);
  	return 0;
  }
while(fscanf(fp,"%s %s %s",phoneBook[contactCount].firstName,phoneBook[contactCount].lastName,phoneBook[contactCount].phoneNumber) == 3) {
  contactCount ++;
}
fclose(fp);
return contactCount;
}
