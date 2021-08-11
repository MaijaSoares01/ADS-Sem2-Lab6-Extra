#define bool int
#define false 0
#define true (!false)
#include <stdio.h>
#define MAX 3

/* This text file saves a series of name and ages to a text file */


void inputDataAndSave(FILE *);
void getFromFileAndDisplay(FILE *);

int main()
{
	FILE *fp;
	
   
    
    fp = fopen("text.dat", "r"); //open a text file for reading - this will give an error if no file
	if (fp == NULL) //if the file doesn't already exist, ask user to input
           inputDataAndSave(fp);    //values and immediately save to the file
	else  
		getFromFileAndDisplay(fp); //othewise copy the values from the file and display.

}


void inputDataAndSave(FILE *fp) {
     char name[20];
     int age;
	
	 printf("Data file doesn't exist, so you must create the data yourself\n");
     fp = fopen("text.dat", "w"); //create the file and open for writing.
     int i;
     for (i=0; i< MAX; i++)
	 {
           printf("Enter name : ");
           scanf("%s", name);
           printf("Enter age: ");
           scanf("%d", &age);
           fprintf(fp, "%s %d\n", name, age);
     }
     fclose(fp);
}

void  getFromFileAndDisplay(FILE *fp)
{
      char name[20];
     int age;
     
     	 printf("Data file does exist, so no need to create the data \n");
      while (fscanf(fp, "%s%d", name, &age)!=EOF)
      {
            printf("Name = %s Age = %d\n", name, age);
      }
          
      fclose(fp);
      
}


