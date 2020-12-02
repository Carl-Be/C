/************************************************************************
* FILE NAME: queue.h                                                    *
* Student: Carl Bechie                                                  *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:                                                              *
* Contains the declarations for the queue.c file                        *
*                                                                       *
* FILE REFERENCES:                                                      *
*                                                                       *
* Name              I/O                     Description                 *
* ----              ---                     -----------                 *
*                                                                       *
* EXTERNAL VARIABLES:                                                   *
* Source: < >                                                           *
*                                                                       *
* Name        Type            I/O           Description                 *
* -----       ----            ---           -----------                 *
*                                                                       *
* EXTERNAL REFERENCES:                                                  *
*                                                                       *
* Name			Description                                             *
* ----			-----------                                             *
*                                                                       *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                    *
*    Pre-Processor - _CRT_SECURE_NO_WARNINGS                            *
*                                                                       *
* DEVELOPMENT HISTORY:                                                  *
*                                                                       *
* Date          Author      Change Id Release     Description Of Change *
* -----       ---------     -----------------     --------------------- *
* 11/30/2020  Carl Bechie        .1               First Edit            *
* 12/01/2020  Carl Bechie        1.0              Finished              *
*                                                                       *
* ALGORITHM (PDL)                                                       *
*                                                                       *
************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

typedef int Item; /*defining an int data type named Item*/

typedef struct Node { /*defining an struct data type named Node*/
	Item item; /*Node holds a value named item*/
	struct Node* next;/*Point to the next node in memory*/
}node;/*alias for Node is node*/

typedef struct Queue {/*defining an struct data type named Queue*/
	int size;/*Holds the size of the queue*/
	node* front;/*node pointer to point to the head of the linked list*/
	node* rear;/*node pointer to point to the tail of the linked list*/
}queue;/*alias for Queue is queue*/

queue* create_queue();/*Creates a Queue object*/
static void terminate(const char* error_message);/*Terminates the program if memory can not be allocated*/
void insert_item(queue* queue, Item item);/*Inserts an Item type to the tail of the queue*/
void remove_item(queue* queue);/*Removes an Item type from the head of the queue*/
void display_front(queue* queue);/*Displays the head item in the queue*/
void display_rear(queue* queue);/*Displays the tail item in the queue*/
void display_size(queue* queue);/*Displays the count of Items in the queue*/

#endif QUEUE_H_