// CSE240 Homework
// 
// Homework 4: creating a student record
// Completion Time: 
// @author Miranda Coston, Acuna (base code)
// @version 1.22
//Compiler used: VS
     // You are given a partially completed program that creates a list of students, 
    //like students' record.
    // We use the word list in a general sense here - it is really a collection of 
    //students stored in an array of structs.

    // An array of structs called 'list' is made to hold the list of students.
    // You can use string library functions.
    // WRITE COMMENTS FOR IMPORANT STEPS IN YOUR CODE.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // for Visual Studio Only
#define MAX_STUDENTS 15
#define MAX_NAME_LENGTH 25
typedef enum { freshman = 0, sophomore, junior, senior } schoolYear; // enum type
struct studentRecord { // struct for student details
    char studentName[MAX_NAME_LENGTH];
    char major[MAX_NAME_LENGTH];
    schoolYear schoolYear;
    unsigned int studentID;
};
struct studentRecord list[MAX_STUDENTS]; // declare list of students
int count = 0; // the number of students currently stored in the list(initialized to 0)functions already implmented
void flushStdIn();
void executeAction(char);
void save(char* fileName);
// functions that need implementation:
int addSort(char* studentName_input, char* major_input, char* schoolYear_input,
    unsigned int studentID_input); // 30 points
void display(); // 10 points
void load(char* fileName); // 10 points
int main()
{
    char* fileName = "Student_List.txt";
    load(fileName); // load list of students from file (if it exists). 
    //Initially there will be no file.
        char choice = 'i'; // initialized to a dummy value
    do
    {
        printf("\nEnter your selection:\n");
        printf("\t a: add a new student\n");
        printf("\t d: display student list\n");
        printf("\t q: quit\n");
        choice = getchar();
        flushStdIn();
        executeAction(choice);
    } while (choice != 'q');
    save(fileName); // save list of students to file (overwrites file, if it 
    //exists)
    return 0;
}
// flush out leftover '\n' characters
void flushStdIn()
{
    char c;
    do c = getchar();
    while (c != '\n' && c != EOF);
}
// ask for details from user for the given selection and perform that action
void executeAction(char c)
{
    char studentName_input[MAX_NAME_LENGTH], major_input[MAX_NAME_LENGTH];
    unsigned int studentID_input, add_result = 0;
    char schoolYear_input[20];
    switch (c)
    {
    case 'a':
        // input student record from user
        printf("\nEnter student name: ");
        fgets(studentName_input, sizeof(studentName_input), stdin);
        studentName_input[strlen(studentName_input) - 1] = '\0'; // discard 
        //the trailing '\n' char
            printf("Enter major: ");
        fgets(major_input, sizeof(major_input), stdin);
        major_input[strlen(major_input) - 1] = '\0'; // discard the trailing 
        //'\n' char
            printf("Enter whether students is 'freshman' or 'sophomore' or 'junior' or 'senior': ");
                fgets(schoolYear_input, sizeof(schoolYear_input), stdin);
        schoolYear_input[strlen(schoolYear_input) - 1] = '\0'; // discard 
        //the trailing '\n' char
            printf("Please enter student ID number: ");
        scanf("%d", &studentID_input);
        flushStdIn();
        // add the student to the list
        add_result = addSort(studentName_input, major_input, schoolYear_input,
            studentID_input);
        if (add_result == 0)
            printf("\nStudent is already on the list! \n\n");
        else if (add_result == 1)
            printf("\nStudent successfully added to the list! \n\n");
        else
            printf("\nUnable to add. Student list is full! \n\n");
        break;
    case 'd': display(); break;
    case 'q': break;
    default: printf("%c is invalid input!\n", c);
    }
}
// Q1 : addSort (30 points)
int addSort(char* studentName_input, char* major_input, char* schoolYear_input, unsigned int studentID_input)
{
    struct studentRecord studentTemp; // needed for swapping structs. Not absolutely necessary to use.
    struct studentRecord* p = &list[0];

    for (int i = 0; i < count; i++) //compare the student names
    {
        if (strcmp(list[i].studentName, studentName_input) == 0)
            return 0;
    }
    if (count = 15) { //check if list is full
        return 2;
    }
    else {
        if (schoolYear_input = "freshman")            //strings to enum
        {
            list[count].schoolYear = 0;
        }
        else if (schoolYear_input = "sophomore")
        {
            list[count].schoolYear = 1;
        }
        else if (schoolYear_input = "junior")
        {
            list[count].schoolYear = 2;
        }
        else
        {
            list[count].schoolYear = 3;
        }
        strcpy(list[count].studentName, studentName_input); //adding name
        strcpy(list[count].major, major_input);             //adding major
        list[count].studentID = studentID_input;            //adding ID
        count++;                                        //incrementing count

            for (int i = 1; i < count; i++) {               //sorting ze list
                for (int j = i + 1; j < count; j++)
                {
                    if (strcmp(list[i].studentName, list[j].studentName) > 0)
                    {
                        studentTemp = list[i];
                        list[i] = list[j];
                        list[j] = studentTemp;
                    }
                }
            }
        return 1;
    }
}
// Q2 : display (10 points)
void display()
{
    for (int i = 0;i < count;i++)
    {
        printf("\nStudent name: %s", list[i].studentName);
        printf("\nMajor: %s", list[i].major);
        if (list[i].schoolYear = 0)
        {
            printf("\nSchool year: freshman");
        } else if (list[i].schoolYear = 1)
        {
            printf("\nSchool year: sophomore");
        } else if (list[i].schoolYear = 2)
        {
            printf("\nSchool year: junior");
        } else {
            printf("\nSchool year: senior");
        }
        printf("\nStudent ID: %d", list[i].studentID);
        i++;
    }
}

void save(char* fileName)
{
    FILE* file;
    int i, schoolYearValue = 0;
    file = fopen(fileName, "wb"); // open file for writing
    fwrite(&count, sizeof(count), 1, file); // First, store the number of students in the list
        // Parse the list and write student record to file
        // 
        for (i = 0; i < count; i++)
        {
            fwrite(list[i].studentName, sizeof(list[i].studentName), 1, file);
            fwrite(list[i].major, sizeof(list[i].major), 1, file);
            // convert enum to a number for storing
            if (list[i].schoolYear == freshman)
                schoolYearValue = 0; // 0 for freshman
            else if (list[i].schoolYear == sophomore)
                schoolYearValue = 1; // 1 for sophomore
            else if (list[i].schoolYear == junior)
                schoolYearValue = 2; // 2 for junior 
            else
                schoolYearValue = 3; // 3 for senior
            fwrite(&schoolYearValue, sizeof(schoolYearValue), 1, file);
            fwrite(&list[i].studentID, sizeof(list[i].studentID), 1, file);
        }
    fclose(file); // close the file after writing
}
void load(char* fileName)
{
    FILE* file;
    int schoolYearValue = 0;
    file = fopen(fileName, "rb");
    if (file == NULL)
    {
        printf("Student_List.txt not found");
        return;
    }
    fread(&count, sizeof(count), 1, file); //read number of students in the list
    for (int i = 0; i < count; i++)
    {
        fread(&list[i].studentName, sizeof(list[i].studentName), 1, file);
        fread(&list[i].major, sizeof(list[i].major), 1, file);
            if (list[i].schoolYear == freshman)
                schoolYearValue = 0; // 0 for freshman
            else if (list[i].schoolYear == sophomore)
                schoolYearValue = 1; // 1 for sophomore
            else if (list[i].schoolYear == junior)
                schoolYearValue = 2; // 2 for junior 
            else
                schoolYearValue = 3; // 3 for senior
        fread(&schoolYearValue, sizeof(schoolYearValue), 1, file);
        fread(&list[i].studentID, sizeof(list[i].studentID), 1, file);
    }
    fclose(file);
}
