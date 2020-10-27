/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Defines*/
#define MAX_LEN (int )12
#define ID_LEN (int) 6
#define MENU_OPTION_LEN (int) 1
#define ONE_BYTE (int) 1
#define MAX_LINE_LEN (int) 60
#define MAX_SEGMENT_LEN (int) 20

/*Prototypes*/
void clear_stdin_garbage();
void determine_selection(char selection, const struct student* student_records);
void display_menu();
void display_records(const struct student* student_records, int start, int stop);
void fill_student_records(struct student* student_records, FILE* file_ptr);
void get_input(char* ptr, int stop);
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

void main(void)/*Function determine_selection ends program if user enters 'q' or 'Q'*/
{
	struct student student_records[MAX_LEN];
	FILE* file_ptr = read_file("student database.txt", "r");
	fill_student_records(student_records, file_ptr);

	char* selection = calloc(MENU_OPTION_LEN + 1, ONE_BYTE);
	do {

		display_menu();
		get_input(selection, MENU_OPTION_LEN);
		determine_selection(selection[0], student_records);

		puts("");
	} while (1);

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
	switch (toupper(selection))
	{
	case 'D':
		display_records(student_records, 0, MAX_LEN);
		break;
	case 'S':
		student_lookup(student_records);
		break;
	case 'C':
		student_campus_count(student_records);
		break;
	case 'Q':
		exit(0);/*Exit Program with normal exit code*/
		break;
	default:
		printf("\nWrong input (%c) please try again.\n", selection);
	}
}

/****************************************************************************************************************************************/

void display_records(const struct student* student_records, int start, int stop)
{
	char* id;
	char* name;
	char* program;
	char* campus;
	
	const char* HEADER = "\n\
  ID         Name              Program             Campus\n\
 ----       ------            ----------          --------\n";
	printf("%s", HEADER);

	for (int i = start; i < stop; i++)
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
	char* line_buffer = calloc(MAX_LINE_LEN, ONE_BYTE);/*No line is biger then 60 chars*/
	char* placeholder = calloc(MAX_SEGMENT_LEN, ONE_BYTE);/*No segments longer then 20 chars*/;
	int line_index = 0;

	for (int i = 0; i < MAX_LEN; i++)
	{
		fgets(line_buffer, MAX_LINE_LEN, file_ptr);

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

void get_input(char* ptr, int stop)
{

	for (int i = 0; i < stop + 1; i++)
	{
		if ((ptr[i] = getchar()) == '\n' || ptr[i] == '\0')
		{
			ptr[i] = '\0';
			break; 
		}

		if (i == stop)
		{
			printf("\nTo much input. Only input %d char(s). Returning to Main Menu\n\n", stop);
			clear_stdin_garbage();
			main();
		}
	}

}

void clear_stdin_garbage()
{
	int clear_stdin_garbage;

	while ((clear_stdin_garbage = getchar()) != '\n')
	{
	}
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

void student_lookup(const struct student* student_records)
{
	char* id = calloc(ID_LEN + 1, ONE_BYTE);/*Student id_len = 6 + 1*/
	printf("\nEnter Student ID: ");
	get_input(id, ID_LEN);

	if (strlen(id) != ID_LEN)
	{
		printf("\nInput \"%s\". Returning to Main Menu.\nSuggestion: Input six numbers for ID.\n", id);
		free(id);
		return;
	}

	for (int i = 0; i < MAX_LEN; i++)
	{
		if (strcmp(id, student_records[i].student_id) == 0)
		{
			display_records(student_records, i, i + 1);
			break;
		}
		else if (i == (MAX_LEN - 1) && strcmp(id, student_records[i].student_id) != 0)
		{
			printf("Student ID %s not found.\n", id);
			break;
		}
	}

	free(id);
}

/****************************************************************************************************************************************/

void student_campus_count(const struct student* student_records)
{
	enum campuses{west = 'W', east = 'E', downtown = 'D'};

	int west_count = 0, east_count = 0, down_count = 0;

	for (int i = 0; i < MAX_LEN; i++)
	{
		switch (student_records[i].student_campus[0])
		{
			case west:
				west_count++;
				break;
			case east:
				east_count++;
				break;
			case downtown:
				down_count++;
				break;
		}
	}

	printf("\nEast Campus: %d students", east_count);
	printf("\nWest Campus: %d students", west_count);
	printf("\nDowntown Campus: %d students\n", down_count);
}



