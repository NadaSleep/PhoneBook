#include<>
#include<>
#include<>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct{
  char fn[MAX_NAME_LENGTH];	
  char ln[MAX_NAME_LENGTH];
	
} User;

void store(User users[],int num_Entries,char* filename)
{
	FILE *fp=fopen(filename,"w");

    if(fp==NULL){
      printf("Error opening the file");
	  return;
	}

  for(int i=0;i<num_Entries;i++){
  	  fprintf(fp,"%s %s\n",users[i].fn,users[i].ln);
  }
  
//  Closing the stream
  fclose(fp);
}

int restoreData(User users[],char* filename){
  //Open Stream
  FILE* fp=fopen(filename,"r")
  if (fp==NULL) {
  	printf("Error in opening");
  	return 0;
  }
}
/read info
int count=0;
while(fscanf(tp,"%s %s",users[count].fn,users[count].ln)!=EOF) {
  count ++;
  if(count>=MAX_ENTRIES) {
  	printf("Array is full.\n");
  	return count -1;
  }
}
fclose(fp);
return count;

int main()
{

  User users[MAX_NAME_LENGTH];	
  int num_Entries=0;
  
  strcpy(users[0].fn,"A");
  strcpy(users[0].fn,"A");
  
  strcpy(users[1].fn,"B");
  strcpy(users[1].fn,"B");	
	
  num_Entries=2;
  store(users,num_Entries,contacts.txt);
	
num_Entries=restoreData(users,filename);
for(int i=0<num_Entries;i++){
	printf("%s %s\n")
}

return 0;	
}