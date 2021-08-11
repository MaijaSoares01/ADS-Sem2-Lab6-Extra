/**************************************************************/
/*                                                            */
/*   Program to demonstrate the implmentation of a simple     */
/*   linked list of numbers with a delete function.	          */
/*                                                            */
/**************************************************************/

#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h>

//Preprocessor Variable
#define SIZE 5

//Stucture template for data part of the linked list
 struct data {
 	int num;
 	char String[30];
 };

//Stucture template for one node
struct LinearNode {
     struct data *element;
	struct LinearNode *next;
};


// Function prototypes
void addNodes();  //adding nodes to front of the list
void deleteNode(int); // delete a specific node
void viewAllNodes();
bool isEmpty();
void linearSearch(int);
void displaySmallest();
//void sortList();


// Global Variables
struct LinearNode *list = NULL; //front of list

struct LinearNode *last = NULL; //pointer to last node in list



/**************MAIN FUNCTION*******************/ 
int main() {
	int delNum;
       
	addNodes();
//	sortList();
	viewAllNodes();
	linearSearch(3);
	printf("Please enter the number of the node to delete : ");
	scanf("%d", &delNum);
	deleteNode(delNum);
	viewAllNodes();
	displaySmallest();
	
}
	
	
	
/**********ADD THREE NODES TO THE LIST******************/
// Each new node is added to the front of the list

void addNodes() {	
	int i;
	int aNumber;
	char String[30];
	struct LinearNode *aNode;
	struct data *anElement;

	// add SIZE nodes to the list
	for (i=0; i<SIZE; i++) {
		printf("Enter a number for node %d: ", i+1);
		scanf("%d", &aNumber);
 		printf("Enter a string for node %d: ", i+1);
		scanf("%s", String);
         //create space for new data element
         anElement = (struct data *)malloc(sizeof(struct data));
         
		// create space for new node
		aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

         //add aNumber to data node
         anElement->num = aNumber;
         strcpy(anElement->String , String);
     
         //add data part to the node
		if (aNode == NULL)
			printf("Error - no space for the new node\n");
		else { // add data part to the node
		 	aNode->next = NULL;
		 	aNode->element = anElement;

			//add node to front of the list
			if (isEmpty())  
			{
				list = aNode;
				last = aNode;
		    }
			else {
				aNode->next = list;
				list = aNode;
			} //end else
		}//end else
	}//end for
	struct LinearNode *current = list, *index = NULL;  
        int tempNum;
		char tempString[30];  
          
        if(list == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                index = current->next;  
                  
                while(index != NULL) {   
                    if(current->element->num > index->element->num) {  
                        tempNum = current->element->num;  
                        strcpy(tempString , current->element->String);
                        current->element->num = index->element->num;  
                        strcpy(current->element->String , index->element->String);
                        index->element->num = tempNum;  
                        strcpy(index->element->String , tempString);
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        } 
} //end addNodes
 		
// void sortList() {   
//        struct LinearNode *current = list, *index = NULL;  
//        int tempNum;
//		char tempString[30];  
//          
//        if(list == NULL) {  
//            return;  
//        }  
//        else {  
//            while(current != NULL) {  
//                index = current->next;  
//                  
//                while(index != NULL) {   
//                    if(current->element->num > index->element->num) {  
//                        tempNum = current->element->num;  
//                        strcpy(tempString , current->element->String);
//                        current->element->num = index->element->num;  
//                        strcpy(current->element->String , index->element->String);
//                        index->element->num = tempNum;  
//                        strcpy(index->element->String , tempString);
//                    }  
//                    index = index->next;  
//                }  
//                current = current->next;  
//            }      
//        }  
//    }  	

void viewAllNodes() {
	struct LinearNode *current;

	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
			current = list;
			while (current != NULL) {
				printf("Node value is %d\n", current->element->num);
				printf("Node string is %s\n", current->element->String);
				current=current->next;
			} //end while
    }//end else
} //end viewAllNodes

void linearSearch(int target)
{
	        struct LinearNode *current = list;
			while (current != NULL && current->element->num != target) 
				current=current->next;
		    if (current == NULL)
		    printf("%d does not exist in the list\n", target);
		    else
		     printf("%d has been found in the list\n", current->element->num);
}

void displaySmallest() {
    struct LinearNode *current = list;
    int min = current->element->num;

    if (!isEmpty()) {
        while(current != NULL){
		    if(min > current->element->num){
		        min = current->element->num;
		    }
		    current=current->next;
		}
    } else {
        printf("empty list");
    }
    printf("\nThis is the smallest node value: %d\n", min);
}
void deleteNode(int aNumber) {
	struct LinearNode *current, *previous;
	bool notFound = true;

	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else  {
			current = previous = list;

			while (notFound && current != NULL) {
				if (aNumber == current->element->num)
					notFound = false;
				else {
						previous = current;
						current = current->next;
				}//end else
			} //end while

			if (notFound)
				printf("Error - there is not such node with value %d\n", aNumber);
			else  {
				if (current == list) {
					list = list->next;
					free(current);
				} //end else
				else {
						previous->next= current->next;
						free(current);
				} //end else
				printf("Node with value %d has been deleted\n", aNumber);
			}//end else
		}//end else
}// end deleteNode


bool isEmpty() {
	if (list == NULL)
		return true;
	else
		return false;
}
