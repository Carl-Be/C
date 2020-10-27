/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Defines*/
#define MAX_LEN 12

/*Prototypes*/
void determine_selection(char selection, const struct student* student_records);
void display_menu();
void display_records(const struct student* student_records);
void fill_student_records(struct student* student_records, FILE* file_ptr);
char get_menu_input();
int get_segment(char* line_buffer, char* placeholder, int line_index);
FILE* read_file(char* file_name, char* mode);
int set_campus(struct student* student_records, char* line_buffer, char* placeholder, int line_index, int i);
int set_id(struct student* student_records, char* line_buffer, char* placeholder, int line_index, int i);
int set_name(struct student* student_records, char* line_buffer, char* placeholder, int line_index, int i);
int set_program(struct student* student_records, char* line_buffer, char* placeholder, int line_index, int i);
void student_campus_count(const struct student* student_records);
void student_lookup(const struct student* student_records);

/*Structure*/
struct student
{
	char* student_id;
	char* student_name;
	char* student_program;
	char* student_campus;
};

/****************************************************************************************************************************************/

int main(void)
{
	struct student student_records[MAX_LEN];
	FILE* file_ptr = read_file("student database.txt", "r");

	fill_student_records(student_records, file_ptr);

	char selection;
	do {

		display_menu();
		selection = get_menu_input();
		determine_selection(selection, student_records);

		puts("");
	} while (selection != 'Q');

	return 0;
}

/****************************************************************************************************************************************/

void display_menu()
{
	char* menu = "\
Press(D) to display all students records information\n\
Press(S) to search and display a student information by student ID\n\
Press(C) to provide a count of students per campus\n\
Press(Q) to quit\n\
Selection: ";

	printf("%s", menu);

}

/****************************************************************************************************************************************/

void determine_selection(char selection, const struct student* student_records)
{
	switch (selection)
	{
	case 'D':
		display_records(student_records);
		break;
	case 'S':
		student_lookup(student_records);
		break;
	case 'C':
		student_campus_count(student_records);
		break;
	case 'Q':
		break;
	default:
		printf("\nWrong input (%c) please try again.\n", selection);
	}
}

/****************************************************************************************************************************************/

void display_records(const struct student* student_records)
{
	char* id;
	char* name;
	char* program;
	char* campus;
	
	const char* HEADER = "\n\
  ID         Name              Program             Campus\n\
 ----       ------            ----------          --------\n";
	printf("%s", HEADER);

	for (int i = 0; i < MAX_LEN; i++)
	{
		id = student_records[i].student_id;
		name = student_records[i].student_name;
		program = student_records[i].student_program;
		campus = student_records[i].student_campus;

		printf("%-10s%-18s%-20s%s \n", id, name, program, campus);
	}
}

/****************************************************************************************************************************************/

void fill_student_records(struct student* student_records, FILE* file_ptr)
{
	char* line_buffer = calloc(60, sizeof(char));/*No line is biger then 60 chars*/
	char* placeholder = calloc(20, sizeof(char));/*No ID longer then 7 chars*/;
	int line_index = 0;

	for (int i = 0; i < MAX_LEN; i++)
	{
		fgets(line_buffer, 60, file_ptr);

		line_index = set_id(student_records, line_buffer, placeholder, line_index, i);
		line_index = set_name(student_records, line_buffer, placeholder, line_index, i);
		line_index = set_program(student_records, line_buffer, placeholder, line_index, i);
		line_index = set_campus(student_records, line_buffer, placeholder, line_index, i);

		line_index = 0;
	}

	free(line_buffer);
	free(placeholder);
}


int get_segment(char* line_buffer, char* placeholder, int line_index)
{
	int place_index = 0;
	do {
		placeholder[place_index++] = line_buffer[line_index++];
	} while (placeholder[place_index - 1] != ',' && placeholder[place_index - 1] != '\n');
	placeholder[place_index - 1] = '\0';

	return line_index;
}

int set_id(struct student* student_records, char* line_buffer, char* placeholder, int line_index, int i)
{
	line_index = get_segment(line_buffer, placeholder, line_index);
	
	student_records[i].student_id = malloc(strlen(placeholder));
	strcpy(student_records[i].student_id, placeholder);

	return line_index;
}

int set_name(struct student* student_records, char* line_buffer, char* placeholder, int line_index, int i)
{
	line_index = get_segment(line_buffer, placeholder, line_index);

	student_records[i].student_name = malloc(strlen(placeholder));
	strcpy(student_records[i].student_name, placeholder);

	return line_index;
}

int set_program(struct student* student_records, char* line_buffer, char* placeholder, int line_index, int i)
{
	line_index = get_segment(line_buffer, placeholder, line_index);

	student_records[i].student_program = malloc(strlen(placeholder));
	strcpy(student_records[i].student_program, placeholder);

	return line_index;
}

int set_campus(struct student* student_records, char* line_buffer, char* placeholder, int line_index, int i)
{
	line_index = get_segment(line_buffer, placeholder, line_index);

	student_records[i].student_campus = malloc(strlen(placeholder));
	strcpy(student_records[i].student_campus, placeholder);

	return line_index;
}

/****************************************************************************************************************************************/

char get_menu_input()
{
	char selection;

	for (int i = 0; i < 1; i++)
	{
		selection = getchar();
	}

	int clear_stdin_garbage;

	while((clear_stdin_garbage = getchar()) != '\n')
	{}

	return toupper(selection);
}

/****************************************************************************************************************************************/

FILE* read_file(char* file_name, char* mode)
{
	/*Read a file into the input stream*/
	FILE* file_ptr = fopen(file_name, mode);

	if (file_ptr == NULL)/*If no file handle it*/
	{
		printf("\nFile not found\n");
	}

	return file_ptr;
}

/****************************************************************************************************************************************/

void student_lookup(struct student* student_records)
{

}

/****************************************************************************************************************************************/

void student_campus_count(struct student* student_records)
{

}



