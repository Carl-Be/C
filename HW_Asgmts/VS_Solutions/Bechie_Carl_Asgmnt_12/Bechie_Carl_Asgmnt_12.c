/**************************************************************************
* FILE NAME: Bechie_Carl_Asgmnt_12.c                                      *
* Student: Carl Bechie                                                    *
* Class: CNR 10777 CIS265                                                 *
*                                                                         *
* PURPOSE: Create a student database using a struct array and             *
* preform functions on the data.                                          *
*                                                                         *
* FILE REFERENCES:                                                        *
*                                                                         *
* Name                     I/O             Description                    *
* ----                     ---             -----------                    *
* "student database.txt"    I              File holding student inform-   *
*                                          ation.                         *
*                                                                         *
* EXTERNAL VARIABLES:                                                     *
* Source: < >                                                             *
*                                                                         *
* Name        Type            I/O           Description                   *
* -----       ----            ---           -----------                   *
*                                                                         *
* EXTERNAL REFERENCES:                                                    *
*                                                                         *
* Name			Description                                               *
* ----			-----------                                               *
* <stdio.h>     printf(), getchar(), read_file(), puts(), fgets()         *
*                                                                         *
* <stdlib.h>    calloc(), malloc(), free()                                *
*                                                                         *
* <string.h>    strcpy(), strcmp()                                        *
*                                                                         *
* <ctype.h>     toupper()                                                 *
*                                                                         *
* <stdbool.h>   _Bool                                                     *
*                                                                         *
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:            *
*                                                                         *
* Warning - Wrong input (%c) please try again                             *
*                                                                         *
* Warning - Too much input. Only input %d char(s). Returning to Main Menu.*
*                                                                         *
* Warning - Input %s. Returning to Main Menu.\n                           *
*           Suggestion: Input six numbers for ID.                         *
*                                                                         *
* Adnormal Termination Condition - File not found                         *                           
*                                                                         *
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                                 *
*                                                                         *
* Assumption - Text files are in standard format for this program.        *
*                                                                         *
* Assumption - ID is 6 chars long always.                                 *
*                                                                         *
* Assumption - No segment of data is more than 20 chars long.             *
*                                                                         *                                                                        
* NOTES:                                                                  *
*                                                                         *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                      *
*                                                                         *
*  Preprocessor Definition - _CRT_SECURE_NO_WARNINGS                      * 
*                                                                         *
* DEVELOPMENT HISTORY:                                                    *
*                                                                         *
* Date          Author      Change Id Release     Description Of Change   *
* -----       ---------     -----------------     ---------------------   *
* 10/26/2020  Carl Bechie        1.0              First Edit / Working    *
* 10/27/2020  Carl Bechie        1.0              Documentation Completed *
* 10/29/2020  Carl Bechie        1.0              Refined Documentation   *
*                                                                         *
* ALGORITHM (PDL)                                                         *
*                                                                         *
**************************************************************************/

/*Includes ( https://devdocs.io/c )*/
#include <stdio.h> /*Input/output handling*/
#include <stdlib.h> /*General utilities: memory management, program utilities, string conversions, random numbers*/
#include <string.h> /*String handling*/
#include <ctype.h> /*Functions to determine the type contained in character data*/
#include <stdbool.h> /*Boolean type*/

/*Defines*/
#define MAX_LEN (int )12 /*Number of students in the text file. Struct array MAX_LEN*/
#define ID_LEN (int) 6 /*IDs are assumed to be 6 chars long based of the included text file*/
#define MENU_OPTION_LEN (int) 1 /*Menu option input length is only 1 char long*/
#define ONE_BYTE (int) 1 /*Just a macro used for readability when using calloc()*/
#define MAX_LINE_LEN (int) 60 /*No line is longer than 60 chars long in the provided text file*/
#define MAX_SEGMENT_LEN (int) 20 /*No data segment is longer than 20 chars ling in the provided text file*/

/*Prototypes*/

void clear_stdin_garbage(); /*Clears junk input from the stdin stream*/

/*Contains a switch statment that runs the users menu selection*/
void determine_selection(char selection, const struct student* student_records);

void display_menu();/*Display the menu options to the user*/

/*Display the recrod(s) to the user*/
void display_records(const struct student* student_records, int start, int stop);

/*Fills the struct student_records array with data from the file input stream*/
void fill_student_records(struct student* student_records, FILE* file_ptr);

/*Gets all user input used throughout the program*/
void get_input(char* ptr, int stop);

/*Used as a delimiter to get a segment of data to place into the struct student_records array*/
/*int*/ void get_segment(char* line_buffer, char* placeholder, /*int line_index,*/ _Bool new_student);

/*Opens the file for reading*/
FILE* read_file(char* file_name, char* mode);

/*Sets the campus field of student struct object*/
void set_campus(struct student* student_records, char* line_buffer, char* placeholder, int current_student);

/*Sets the id field of student struct object*/
void set_id(struct student* student_records, char* line_buffer, char* placeholder, int current_student);

/*Sets the name field of student struct object*/
void set_name(struct student* student_records, char* line_buffer, char* placeholder, int current_student);

/*Sets the program field of student struct object*/
void set_program(struct student* student_records, char* line_buffer, char* placeholder, int current_student);

/*Counts the students per campus using a switch and displays the results to the user*/
void student_campus_count(const struct student* student_records);

/*Looks up an individual student using the students ID*/
void student_lookup(const struct student* student_records);

/*Veifies the users search input is correct format for the student_lookup function.*/
void verify_user_search(char* id);

/*Structure*/
struct student /*An opbject used to hold student infromation inputed from the file stream*/
{
	char* student_id;
	char* student_name;
	char* student_program;
	char* student_campus;
};

/****************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: main                                                   *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  none                                                                 *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void main(void)/*Function determine_selection ends program if user enters 'q' or 'Q'*/
{
	/*I feel like I should of made these three Initializing statements external. Since I return to main() by calling it in two functions.*/
	struct student student_records[MAX_LEN]; /*Declearing a struct array named stedent_records*/
	FILE* file_ptr = read_file("student database.txt", "r");/*Opening a file in read only mode*/
	fill_student_records(student_records, file_ptr);/*Filling the student_records struct array*/

	char* selection = calloc(MENU_OPTION_LEN + 1, ONE_BYTE); /*Initializing a char pointer to hold  user input.*/
	do {
		display_menu();/*Displays the menu options to the user*/
		get_input(selection, MENU_OPTION_LEN);/*Gets the input from the user. In a way that no buffer overrun happens. As far as I can tell.*/
		determine_selection(selection[0], student_records);/*Detemermines wether or not the user inputted a correct menu option*/

		puts("");/*Place a new line for readability*/
	} while (1);/*As stated above keep going on forever until user inputs 'q' or 'Q' determined by the determine_selection function*/

}

/****************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: clear_stdin_garbage                                    *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void clear_stdin_garbage()
{
	/*Clears the users standard input stream so no undefined behavior happens*/

	int clear_stdin_garbage; /*Used to hold garbage data to throw away*/

	while ((clear_stdin_garbage = getchar()) != '\n')/*Keep going until a newline is reached*/
	{
	}
}

/****************************************************************************************************************************************/

/***************************************************************************************
*                                                                                      *
* FUNCTION NAME: determine_selection                                                   *
*                                                                                      *
* ARGUMENT LIST:                                                                       *
*                                                                                      *
* ARGUMENT         TYPE                     I/O            DESCRIPTION                 *
* --------         ----                     ---            -----------                 *
* selection        char                      I             Users menu option used to   *
*                                                          determine what function to  *
*                                                          execute.                    *
*                                                                                      *
* student_records  const struct student*                   Used to hold an array of    *
*                                                          student structs.            *
*                                                                                      *
* RETURNS:                                                                             *
* void                                                                                 *
*                                                                                      *
****************************************************************************************/

void determine_selection(char selection, const struct student* student_records)
{
	switch (toupper(selection))/*Turn all input to uppercase for uniformity*/
	{
	case 'D':
		display_records(student_records, 0, MAX_LEN);/*Display all records to the user in a formated fashion*/
		break;
	case 'S':
		student_lookup(student_records);/*Allows users to look up a student record using the students ID*/
		break;
	case 'C':
		student_campus_count(student_records);/*Counts the students per campus and displays the results*/
		break;
	case 'Q': /*If inputted by user terminate the program*/
		exit(0);/*Exit Program with normal exit code*/
		break;
	default: /*No match for user input display warning message to user.*/
		printf("\nWrong input (%c) please try again.\n", selection);
	}
}

/****************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: display_menu                                           *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void display_menu()
{
	/*Builds a constant menu display to show the user a group of options to select from*/

	const char* MENU = "\
Press(D) to display all students records information\n\
Press(S) to search and display a student information by student ID\n\
Press(C) to provide a count of students per campus\n\
Press(Q) to quit\n\
Selection: ";

	printf("%s", MENU); /*Show user the menu*/

}

/****************************************************************************************************************************************/

/***************************************************************************************
*                                                                                      *
* FUNCTION NAME: determine_selection                                                   *
*                                                                                      *
* ARGUMENT LIST:                                                                       *
*                                                                                      *
* ARGUMENT         TYPE                     I/O            DESCRIPTION                 *
* --------         ----                     ---            -----------                 *                                                                                                    *
* student_records  const struct student*     O             Used to hold an array of    *
*                                                          student structs.            *
*                                                                                      *
* start            int                                     Used to start displaying    *
*                                                          student records at the cor- *
*                                                          rect index of the student_- *
*                                                          records array.              *
*                                                                                      *
* stop             int                                     Used to stop displaying     *
*                                                          student records at the cor- *
*                                                          rect index of the student_- *
*                                                          records array.              *
* RETURNS:                                                                             *
* void                                                                                 *
*                                                                                      *
****************************************************************************************/

void display_records(const struct student* student_records, int start, int stop)
{
	/*Displays student records in a formatted fashion to the user*/

	char* id; /*Pointer to the current student ID*/
	char* name; /*Pointer to the current student name*/
	char* program; /*Pointer to the current student program*/
	char* campus; /*Pointer to the current student campus*/
	
	/*Builds a constant header to be displayed before student records are shown to the user*/
	const char* HEADER = "\n\
  ID         Name              Program             Campus\n\
 ----       ------            ----------          --------\n";
	printf("%s", HEADER);

	for (int i = start; i < stop; i++) /*Display the correct student record(s) to the user*/
	{
		id = student_records[i].student_id; /*Initializing ID of the student to be displayed next*/
		name = student_records[i].student_name; /*Initializing name of the student to be displayed next*/
		program = student_records[i].student_program; /*Initializing program of the student to be displayed next*/
		campus = student_records[i].student_campus; /*Initializing campus of the student to be displayed next*/

		printf("%-10s%-18s%-20s%s \n", id, name, program, campus); /*Print the student record object in a formatted fashion*/
	}
}

/****************************************************************************************************************************************/

/***************************************************************************************
*                                                                                      *
* FUNCTION NAME: determine_selection                                                   *
*                                                                                      *
* ARGUMENT LIST:                                                                       *
*                                                                                      *
* ARGUMENT         TYPE                     I/O            DESCRIPTION                 *
* --------         ----                     ---            -----------                 *
* student_records  const struct student*                   Used to hold an array of    *
*                                                          student structs.            *
*                                                                                      *
* file_ptr         FILE*                     I             Used to input data into the *
*                                                          student_record struct array *
*                                                                                      *
* RETURNS:                                                                             *
* void                                                                                 *
*                                                                                      *
****************************************************************************************/

void fill_student_records(struct student* student_records, FILE* file_ptr)
{
	/*Fills the student_record array elements with student struct objects*/

	char* line_buffer = calloc(MAX_LINE_LEN, ONE_BYTE);/*Used to take in one line at a time from the .txt file*/
	char* placeholder = calloc(MAX_SEGMENT_LEN, ONE_BYTE);/*Temp holding place for the data to be inputted into the student_records struct array*/;
	
	for (int i = 0; i < MAX_LEN; i++) /*Fills the the student_record array to the appropriate length.*/
	{
		/*Gets a line of data segments on the current student from the file.*/
		fgets(line_buffer, MAX_LINE_LEN, file_ptr); 
		
		set_id(student_records, line_buffer, placeholder, i); /*Sets the current students id in the student struct. Current student is repersented by int i.*/
		set_name(student_records, line_buffer, placeholder, i); /*Sets the current students name in the student struct. Current student is repersented by int i.*/
		set_program(student_records, line_buffer, placeholder, i); /*Sets the current students program in the student struct. Current student is repersented by int i.*/
		set_campus(student_records, line_buffer, placeholder, i); /*Sets the current students campus in the student struct. Current student is repersented by int i.*/
	}

	free(line_buffer);/*Free memory allocation*/
	free(placeholder);/*Free memory allocation*/
}

/****************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: get_input                                              *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* ptr             char*       I             The char pointer that is to *
*                                           be initialized.             *
*                                                                       *
* stop            int                       Used to determine if the    *
*                                           user has inputed to many    *
*                                           chars in the stdin stream   *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void get_input(char* ptr, int stop)
{
	/*Gets input from the user in a fashion that helps mitigate the risk of buffer overflows.*/

	for (int i = 0; i < stop + 1; i++) 
	{
		/*Input stream in done or user did not input enough input which is determinded by the calling function.*/
		if ((ptr[i] = getchar()) == '\n' || ptr[i] == '\0')/*'\0' can be used since the program uses calloc() to allocate memory space for input vars*/
		{
			if (ptr[i] == '\n')/*If not already a null terminated string turn the ptr into one.*/
			{
				ptr[i] = '\0';
			}

			break; /*End loop*/
		}

		if (i == stop) /*If the input equals stop the user inputted to many chars. Display warning message.*/
		{
			printf("\nToo much input. Only input %d char(s). Returning to Main Menu.\n\n", stop);
			clear_stdin_garbage(); /*Clear stdin steam of the remaining overflow of chars inputted by the user*/
			main();/*Return to main to get user input again.*/
		}
	}
}

/****************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: get_segment                                            *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* line_buffer     char*       I             Used to hold a line of data *
*                                           segments of the current     *
*                                           student.                    *
*                                                                       *
* placeholder     char*                     Used to hold the current    *
*                                           data segment that the pro-  *
*                                           gram needs to initialize    *
*                                           for the current student.    *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void get_segment(char* line_buffer, char* placeholder, _Bool new_student)
{
	/*Places the proper line_buffer data segment into the placeholder arrary*/

	static int line_index; /*Used to keep track of the current line_buffer index for delimiting purposes*/
	
	if (new_student) /*If true (re)set the static line_index to 0*/
	{
		line_index = 0; 
	}

	int place_index = 0; /*Initializing the var that keeps track of the current placeholder array element*/

	do {
		placeholder[place_index++] = line_buffer[line_index++]; /*Initialize the placeholder array elements to the proper line_buffer data segment*/
	} while (placeholder[place_index - 1] != ',' && placeholder[place_index - 1] != '\n');/*Stop once the end of the current data segment is found.*/
	
	placeholder[place_index - 1] = '\0';/*Terminate the placeholder char array with a NULL byte to make a proper string*/

}

/****************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: read_file                                              *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* file_name       char*       I             The name of the file that   *
*                                           is to be opened.            *
*                                                                       *
* mode            char*                     The mode that is to be used *
*                                           to open the file.           *
*                                                                       *
* RETURNS:                                                              *
*                                                                       *
*                                                                       *
************************************************************************/

FILE* read_file(char* file_name, char* mode)
{
	/*Reads a file into the input stream*/

	FILE* file_ptr = fopen(file_name, mode); /*Initializing the file pointer*/

	if (file_ptr == NULL)/*If no file handle it*/
	{
		printf("\nFile not found\n");
		exit(-1);/*Teminate program with non-normal termination code*/
	}

	return file_ptr;
}

/****************************************************************************************************************************************/

/***************************************************************************************
*                                                                                      *
* FUNCTION NAME: set_campus                                                            *
*                                                                                      *
* ARGUMENT LIST:                                                                       *
*                                                                                      *
* ARGUMENT         TYPE                     I/O           DESCRIPTION                  *
* --------         ----                     ---           -----------                  *
* student_records  const struct student*                  Used to hold an array of     *
*                                                         student structs.             *
*                                                                                      *
* line_buffer     char*                                   Used to hold a line of data  *
*                                                         segments of the current      *
*                                                         student.                     *
*                                                                                      *
* placeholder     char*                                   Used to hold the current     *
*                                                         data segment that the pro-   *
*                                                         gram needs to initialize     *
*                                                         for the current student.     *
*                                                                                      *
* current_student int                                     The current student the pro- *
*                                                         gram is working on to initi- *
*                                                         alize in the student_records *
*                                                         array.                       *
* RETURNS:                                                                             *
* void                                                                                 *
*                                                                                      *
****************************************************************************************/

void set_campus(struct student* student_records, char* line_buffer, char* placeholder, int current_student)
{
	/*Sets the current students campus field*/
	
	get_segment(line_buffer, placeholder, false); /*Gets the campus field from the line_buffer*/

	student_records[current_student].student_campus = malloc(strlen(placeholder));/*Allocates the correct memory size to store the campus field*/
	strcpy(student_records[current_student].student_campus, placeholder);/*Initializies the campus field in the current student struct*/
}

/****************************************************************************************************************************************/

/***************************************************************************************
*                                                                                      *
* FUNCTION NAME: set_id                                                                *
*                                                                                      *
* ARGUMENT LIST:                                                                       *
*                                                                                      *
* ARGUMENT         TYPE                     I/O           DESCRIPTION                  *
* --------         ----                     ---           -----------                  *
* student_records  const struct student*                  Used to hold an array of     *
*                                                         student structs.             *
*                                                                                      *
* line_buffer     char*                                   Used to hold a line of data  *
*                                                         segments of the current      *
*                                                         student.                     *
*                                                                                      *
* placeholder     char*                                   Used to hold the current     *
*                                                         data segment that the pro-   *
*                                                         gram needs to initialize     *
*                                                         for the current student.     *
*                                                                                      *
* current_student int                                     The current student the pro- *
*                                                         gram is working on to initi- *
*                                                         alize in the student_records *
*                                                         array.                       *
* RETURNS:                                                                             *
* void                                                                                 *
*                                                                                      *
****************************************************************************************/

void set_id(struct student* student_records, char* line_buffer, char* placeholder, int current_student)
{
	/*Sets the current students id field*/

	get_segment(line_buffer, placeholder, true);/*Gets the id field from the line_buffer*/
	
	student_records[current_student].student_id = malloc(strlen(placeholder));/*Allocates the correct memory size to store the id field*/
	strcpy(student_records[current_student].student_id, placeholder);/*Initializies the id field in the current student struct*/

}

/****************************************************************************************************************************************/

/***************************************************************************************
*                                                                                      *
* FUNCTION NAME: set_name                                                              *
*                                                                                      *
* ARGUMENT LIST:                                                                       *
*                                                                                      *
* ARGUMENT         TYPE                     I/O           DESCRIPTION                  *
* --------         ----                     ---           -----------                  *
* student_records  const struct student*                  Used to hold an array of     *
*                                                         student structs.             *
*                                                                                      *
* line_buffer     char*                                   Used to hold a line of data  *
*                                                         segments of the current      *
*                                                         student.                     *
*                                                                                      *
* placeholder     char*                                   Used to hold the current     *
*                                                         data segment that the pro-   *
*                                                         gram needs to initialize     *
*                                                         for the current student.     *
*                                                                                      *
* current_student int                                     The current student the pro- *
*                                                         gram is working on to initi- *
*                                                         alize in the student_records *
*                                                         array.                       *
* RETURNS:                                                                             *
* void                                                                                 *
*                                                                                      *
****************************************************************************************/

void set_name(struct student* student_records, char* line_buffer, char* placeholder, int current_student)
{
	/*Sets the current students name field*/

	get_segment(line_buffer, placeholder, false);/*Gets the name field from the line_buffer*/

	student_records[current_student].student_name = malloc(strlen(placeholder));/*Allocates the correct memory size to store the name field*/
	strcpy(student_records[current_student].student_name, placeholder);/*Initializies the name field in the current student struct*/
}

/****************************************************************************************************************************************/

/***************************************************************************************
*                                                                                      *
* FUNCTION NAME: set_program                                                           *
*                                                                                      *
* ARGUMENT LIST:                                                                       *
*                                                                                      *
* ARGUMENT         TYPE                     I/O           DESCRIPTION                  *
* --------         ----                     ---           -----------                  *
* student_records  const struct student*                  Used to hold an array of     *
*                                                         student structs.             *
*                                                                                      *
* line_buffer     char*                                   Used to hold a line of data  *
*                                                         segments of the current      *
*                                                         student.                     *
*                                                                                      *
* placeholder     char*                                   Used to hold the current     *
*                                                         data segment that the pro-   *
*                                                         gram needs to initialize     *
*                                                         for the current student.     *
*                                                                                      *
* current_student int                                     The current student the pro- *
*                                                         gram is working on to initi- *
*                                                         alize in the student_records *
*                                                         array.                       *
* RETURNS:                                                                             *
* void                                                                                 *
*                                                                                      *
****************************************************************************************/

void set_program(struct student* student_records, char* line_buffer, char* placeholder, int current_student)
{
	/*Sets the current students program field*/

	get_segment(line_buffer, placeholder, false);/*Gets the program field from the line_buffer*/

	student_records[current_student].student_program = malloc(strlen(placeholder));/*Allocates the correct memory size to store the program field*/
	strcpy(student_records[current_student].student_program, placeholder);/*Initializies the program field in the current student struct*/
}

/****************************************************************************************************************************************/

/***************************************************************************************
*                                                                                      *
* FUNCTION NAME: student_campus_count                                                  *
*                                                                                      *
* ARGUMENT LIST:                                                                       *
*                                                                                      *
* ARGUMENT         TYPE                     I/O            DESCRIPTION                 *
* --------         ----                     ---            -----------                 *
* student_records  const struct student*                   Used to hold an array of    *
*                                                          student structs.            *
*                                                                                      *
* RETURNS:                                                                             *
* void                                                                                 *
*                                                                                      *
****************************************************************************************/

void student_campus_count(const struct student* student_records)
{
	/*Counts the number of students at each campus and displays the results*/

	/*Since campuses are pre-defined we can use their first letters ASCII values to determine which student is at what campus */
	enum campuses{west = 'W', east = 'E', downtown = 'D'}; /*Initializing enum*/

	int west_count = 0, east_count = 0, down_count = 0;/*Initializing campus count*/

	for (int i = 0; i < MAX_LEN; i++)/*Counting all student records*/
	{
		switch (student_records[i].student_campus[0]) /*Determine what student belongs to what campus*/
		{
			case west:
				west_count++; /*Increase the west_count by one*/
				break;
			case east:
				east_count++; /*Increase the east_count by one*/
				break;
			case downtown:
				down_count++; /*Increase the down(town)_count by one*/
				break;
		}
	}

	/*Print the results*/
	printf("\nEast Campus: %d students", east_count);
	printf("\nWest Campus: %d students", west_count);
	printf("\nDowntown Campus: %d students\n", down_count);
}

/****************************************************************************************************************************************/

/***************************************************************************************
*                                                                                      *
* FUNCTION NAME: student_lookup                                                        *
*                                                                                      *
* ARGUMENT LIST:                                                                       *
*                                                                                      *
* ARGUMENT         TYPE                     I/O            DESCRIPTION                 *
* --------         ----                     ---            -----------                 *
* student_records  const struct student*                   Used to hold an array of    *
*                                                          student structs.            *
*                                                                                      *
* RETURNS:                                                                             *
* void                                                                                 *
*                                                                                      *
****************************************************************************************/

void student_lookup(const struct student* student_records)
{
	/*
	Finds a student the user wants to look for. If no student 
	is found tell the user. If user input is in the incorrect 
	format warn the user.
	*/

	char* id = calloc(ID_LEN + 1, ONE_BYTE);/*Allocate proper memory size for the id array*/
	printf("\nEnter Student ID: "); /*Prompts user for the student ID to search for*/
	get_input(id, ID_LEN);/*Gets users input for the ID*/
	verify_user_search(id);/*Verifies user input is in the correct format*/

	for (int i = 0; i < MAX_LEN; i++) /*Searches for the student ID*/
	{
		if (strcmp(id, student_records[i].student_id) == 0) /*Trigers: When student record is found*/
		{
			display_records(student_records, i, i + 1); /*Display the student record*/
			break;
		}
		else if (i == (MAX_LEN - 1) && strcmp(id, student_records[i].student_id) != 0) /*No student was found with the ID that the user inputted*/
		{
			printf("Student ID %s not found.\n", id); /*Display result*/
			break;
		}
	}

	free(id);/*Free the memory location of id*/
}

/****************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: verify_user_search                                     *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* id              char*       I             The users inputted student  *
*                                           id to search for.           *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void verify_user_search(char* id)
{
	/*Verifies that the student id that the user inputted is in the correct format*/

	if (strlen(id) != ID_LEN)/*If not in correct format prompt warning message and return to the main menu*/
	{
		/*Display warning message*/
		printf("\nInput \"%s\". Returning to Main Menu.\nSuggestion: Input six numbers for ID.\n\n", id);
		free(id);/*Free the memory location*/
		main();/*Return to main menu*/
	}
}