/************************************************************************
* FILE NAME: queue.c                                                    *
* Student: Carl Bechie                                                  *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:                                                              *
* Implments the modules of queue.h. These modules will preform queue    *
* behavior in a First In First Out fashion.                             *
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
* <stdio.h>     printf()                                                *
*                                                                       *
* <stdlib.h>   NULL, EXIT_FAILURE                                       *
*                                                                       *
* "queue.h"     insert_int(), remove_int(), display_first()             *
*               display_last(), display_size(), Item                    *
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

/*Includes*/
#include <stdio.h>/*Standard C I/O lib*/
#include <stdlib.h>/*Stanrd C general lib*/
#include "queue.h"/*My Queue lib*/

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: create_queue                                           *
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

queue* create_queue()
{
    /*Creates a Queue object*/

    queue* q = malloc(sizeof(node));/*Allocate memory for a queue node*/

    if (q == NULL) /*If node is null memory did not allocate*/
    {
        terminate("Error: Faild to allocate memory to create queue."); /*Print error message and temrinate program*/
    }

    q->size = 0;/*Start size at 0*/
    q->front = NULL;/*Point front node pointer to NULL byte*/
    q->rear = NULL;/*Point rear node pointer to NULL byte*/

    return q; /*Return queue pointer*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: terminate                                              *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE         I/O        DESCRIPTION                   *
* --------        ----         ---        -----------                   *
* error_message   const char*   O         The error message to display  *
*                                         to the user.                  *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

static void terminate(const char* error_message)
{
    /*Terminates the program if memory can not be allocated*/

    printf("%s\n", error_message);/*Display error message*/
    exit(EXIT_FAILURE);/*exit program with an EXIT_FAILURE status*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: insert_item                                            *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE         I/O        DESCRIPTION                   *
* --------        ----         ---        -----------                   *
*   q             queue*                  A pointer to the queue object *
*                                         Linked List.                  *
*                                                                       *
*   i             Item          I         An Item data type to insert   *
*                                         into a new queue linked list  *
*                                         node.                         *
*                                                                       * 
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void insert_item(queue* q, Item i)
{
    /*Inserts an Item type to the tail of the queue*/

    node* new_node = malloc(sizeof(node));/*Allocate memory for new node*/
    if (new_node == NULL)/*If memoroy did not allocate terminate the program*/
    {
        terminate("Error: Failed to allocate memory for new item.");
    }
    
    new_node->item = i;/*Point new_node at user inputed Item*/
    
    if (q->rear != NULL) /*If rear is not NULL q->rear->next points to new_node memory location*/
    {
        q->rear->next = new_node;/*Point to new_node memory location*/
    }

    q->rear = new_node;/*Point the rear node pointer to the new tail/rear/end of the queue*/

    if (q->front == NULL)/*If front node pointer is null point to new_node memory location*/
    {
        q->front = new_node;/*Initialize front node pointer to new_node so its not NULL anymore*/
    }

    q->size++;/*add 1 to size*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: remove_item                                            *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE         I/O        DESCRIPTION                   *
* --------        ----         ---        -----------                   *
*   q             queue*                  A pointer to the queue object *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void remove_item(queue* q)
{
    /*Removes an Item type from the head of the queue*/

    node* placeholder = q->front; /*Make a node* placeholder to point at the memory location of the head/front node*/

    if (q->rear == q->front)/*If rear and front have the same memory location point rear/tail to NULL byte so no undefined behavior happens.*/
    {
        q->rear = NULL;
    }

    /*
         Point the front node memory location to the next pointer so we can free up the old memory location without
         corupting the linked list.
     */

    if (q->front->next == NULL)
    {
        terminate("Error: Removing NULL pointer not allowed.");
    }

    q->front = q->front->next;
    free(placeholder);/*Free the old front end/head memory location of the queue linked list*/

    q->size--;/*Take 1 away from size*/

     /*
     Could also make this return the node Item value that was removed.
     But I dont think the assignment calls for that.
     To do so add the following code though.
     
                     Item remove_Item(queue* q)
                     Item i = q->front->item;
                     .....
                     .....
                     .....
                     return i;
    */
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME:  display_front                                         *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE         I/O        DESCRIPTION                   *
* --------        ----         ---        -----------                   *
*   q             queue*                  A pointer to the queue object *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void display_front(queue* queue)
{
    /*Displays the head item in the queue*/
    
    if (queue->front != NULL)/*Only print if not NULL*/
    {
        printf("Head: %d\n", queue->front->item);
    }
    else/*Print warning message*/
    {
        printf("\nWarning: HEAD Node NULL. Try adding some nodes first.\n");
    }
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: display_rear                                           *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE         I/O        DESCRIPTION                   *
* --------        ----         ---        -----------                   *
*   q             queue*                  A pointer to the queue object *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void display_rear(queue* queue)
{
    /*Displays the tail item in the queue*/

    if (queue->rear != NULL)/*Only print if not NULL*/
    {
        printf("Tail: %d\n", queue->rear->item);
    }
    else/*Print warning message*/
    {
        printf("\nWarning: TAIL Node NULL. Try adding some nodes first.\n");
    }
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: display_count                                          *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE         I/O        DESCRIPTION                   *
* --------        ----         ---        -----------                   *
*   q             queue*                  A pointer to the queue object *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void display_size(queue* queue)
{
    /*Displays the count of Items in the queue*/
    
    printf("Queue Count: %d\n", queue->size);
}