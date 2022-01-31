// CSE240 Spring A - Tushara
// @author Miranda Coston
// @version 1.22 
// Compiler used: Visual studio 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // for Visual Studio Only
#define MAX_NAME_LENGTH 25
typedef enum { freshman = 0, sophomore, junior, senior } schoolYearType; // enum type 
struct studentRecord {
	char studentName[MAX_NAME_LENGTH];
	char major[MAX_NAME_LENGTH];
	schoolYearType schoolYear;
	unsigned int IDNumber;
	struct studentRecord* next;	// pointer to next node
} *list = NULL;					// Declare linked list 'list'
// forward declaration of functions (already implmented)
void flushStdIn();
void executeAction(char);
// functions that need implementation:
int addSort(char* studentName_input, char* major_input, char* schoolYear_input, unsigned int IDNumber_input); // 20 points
void displayList();						// 10 points
int countNodes();						// 5 points
int deleteNode(char* studentName_input);	// 10 points
void swapNodes(struct studentRecord* node1, struct studentRecord* node2);	// 5 points
int main()
{
	char selection = 'i';		// initialized to a dummy value
	printf("\nCSE240 HW6\n");
	do
	{
		printf("\nCurrently %d student(s) on the list.", countNodes());	// NOTE: countNodes() called here
		printf("\nEnter your selection:\n");
		printf("\t a: add a new student\n");
		printf("\t d: display student list\n");
		printf("\t r: remove a student from the list\n");
		printf("\t q: quit\n");
		selection = getchar();
		flushStdIn();
		executeAction(selection);
	} while (selection != 'q');
	return 0;
}
// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}
// Ask for details from user for the given selection and perform that action
// Read the code in the function, case by case
void executeAction(char c)
{
	char studentName_input[MAX_NAME_LENGTH], major_input[MAX_NAME_LENGTH];
	unsigned int IDNumber_input, result = 0;
	char schoolYear_input[20];
	switch (c)
	{
	case 'a':	// add student
		// input student details from user
		printf("\nEnter student name: ");
		fgets(studentName_input, sizeof(studentName_input), stdin);
		studentName_input[strlen(studentName_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter major: ");
		fgets(major_input, sizeof(major_input), stdin);
		major_input[strlen(major_input) - 1] = '\0';	// discard the trailing '\n' char

		printf("Enter whether student is 'freshman' or 'sophomore' or 'junior' or 'senior': ");
		fgets(schoolYear_input, sizeof(schoolYear_input), stdin);
		schoolYear_input[strlen(schoolYear_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter ID number: ");
		scanf("%d", &IDNumber_input);
		flushStdIn();

		// add the student to the list
		result = addSort(studentName_input, major_input, schoolYear_input, IDNumber_input);
		if (result == 0)
			printf("\nStudent is already on the list! \n\n");
		else if (result == 1)
			printf("\nStudent successfully added to the list! \n\n");
		break;
	case 'd':		// display the list
		displayList();
		break;
	case 'r':		// remove a student
		printf("\nPlease enter student name: ");
		fgets(studentName_input, sizeof(studentName_input), stdin);
		studentName_input[strlen(studentName_input) - 1] = '\0';	// discard the trailing '\n' char
		// delete the node
		result = deleteNode(studentName_input);
		if (result == 0)
			printf("\nStudent does not exist! \n\n");
		else if (result == 1)
			printf("\nStudent successfully removed from the list. \n\n");
		else
			printf("\nList is empty! \n\n");
		break;
	case 'q':		// quit
		break;
	default: printf("%c is invalid input!\n", c);
	}
}
// Q1 : addSort 
int addSort(char* studentName_input, char* major_input, char* schoolYear_input, unsigned int IDNumber_input) // 20 points
{
	struct studentRecord* tempList = list;	// work on a copy of 'list'
	while (tempList = !NULL) {			//check if student record already exits
		if (strcmp(tempList->studentName, studentName_input) == 0) {
			return 0;
			tempList = tempList->next;
		}
	}
	tempList = list; //reset tempList back to list after checking for student existence
	struct studentRecord* index = NULL;
	struct studentRecord* p = (struct studentRecord*)malloc(sizeof(struct studentRecord));
	struct studentRecord* q;
		strcpy(p->studentName, studentName_input); //copying new input into a new node
		strcpy(p->major, major_input);				//^
		p->IDNumber = IDNumber_input;				//^
			if (schoolYear_input = "freshman") {		//^^converting string to enum
				p->schoolYear = 0;
			}else if (schoolYear_input = "sophomore") {
				p->schoolYear = 1;
			}else if (schoolYear_input = "junior") {
				p->schoolYear = 2;
			}else {
				p->schoolYear = 3;
			}
		p->next = NULL;							//setting node ref to null (as it will be last in the list)

		if (tempList == NULL) {						//if list is empty, new student is first node
			tempList = p;
		}else {										//if not, traverse and add onto end
			q = tempList;						//setting q to front of list
			while (q->next != NULL)				//traverse to end of list
			{
				q = q->next;					//q is now pointing to last node on lis
			}
			q->next = p;			//makes 'input' node the last one
		}
		//sorting 
		while (tempList != NULL) {
			// index points to the node next to current
			index = tempList->next;
			while (index != NULL) {
				if (strcmp(tempList->studentName, index->studentName)>0) {
					swapNodes(tempList, index);
				} index = index->next;
			} tempList = tempList->next;
		} //end outer while loop
	return 1;
} //close the whole function
// Q2 : displayList (10 points)
void displayList() {	
	struct studentRecord *tempList = list;				// work on a copy of 'list'
		while (tempList !=NULL){
			printf("\nStudent name: %s", tempList->studentName);
			printf("\nMajor: %s", tempList->major);
				if (tempList->schoolYear == 0) {
					printf("\nSchool year: freshman");
				} else if (tempList->schoolYear == 1) {
					printf("\nSchool year: sophomore");
				} else if (tempList->schoolYear == 2) {
					printf("\nSchool year: junior");
				} else {
					printf("\nSchool year: senior");
				}
			printf("\nStudent ID: %d", tempList->IDNumber);
			tempList = tempList->next;
		}
	}
// Q3: countNodes (5 points)
int countNodes()
{
		struct studentRecord* temp = list; //assign a temp node to the list
		int count = 0;
		while (temp != NULL) {
			count++;
			temp = temp->next; //move to next node
		}
		return count;// edit this line as needed
}
// Q4 : deleteNode (10 points)
int deleteNode(char* studentName_input)
{
	struct studentRecord* tempList = list->next;				// work on a copy of 'list'
	struct studentRecord* prevNode = NULL;
	while (tempList != NULL) {
		if (strcmp(tempList->studentName, studentName_input)==0) {
			if (prevNode == NULL) {
				list = tempList->next;
			}else {
				prevNode->next = tempList->next;
				free(tempList);
				return 1; }
			prevNode = tempList;
			tempList = tempList->next;
		}
	} return 0;	
}
// Q5 : swapNodes (5 points)
void swapNodes(struct studentRecord* node1, struct studentRecord* node2)
{
			//tempp=node1
	char tempName[MAX_NAME_LENGTH];
	char tempMajor[MAX_NAME_LENGTH];
	strcpy(tempName, node1->studentName); //copying node1 into temp 
	strcpy(tempMajor,node1->major);	
	int temppIDNumber = node1->IDNumber;
	schoolYearType tempSchoolYear = node1->schoolYear;
			//node1 = node2
	strcpy(node1->studentName, node2->studentName); //copying node2 into node1
	strcpy(node1->major, node2->major);				//^
	node1->IDNumber = node2->IDNumber;				//^
	node1->schoolYear = node2->schoolYear;
			//node2 = temp
	strcpy(node2->studentName, tempName); //copying tempp into node2
	strcpy(node2->major, tempMajor);				//^
	node2->IDNumber = temppIDNumber;				//^
	node2->schoolYear = tempSchoolYear;
}


