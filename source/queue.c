#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "headers/queue.h"



//This function receives a person object and prints it's data to terminal.
void print_person(Person p)
{
    printf("{\nNome: %s", p.name);
    printf("Idade: %d anos\n", p.age);

    switch(p.profession)
    { //Converts profession value to it's correspondent description.
        case 1:
            printf("Area da profissao: Saude\n");
            break;

        case 2:
            printf("Area da profissao: Ensino/Seguranca\n");
            break;

        case 3:
            printf("Area da profissao: Outros\n");
            break;
    }

    switch(p.condition)
    { //Converts condition value to it's correspondent description.
        case 1:
            printf("Tem problema de saude: Sim\n}\n");
            break;

        case 2:
            printf("Tem problema de saude: Nao\n}\n");
            break;
    }
}



//This function receives a queue and uses a secondary function "print_person" to print it's data to terminal.
void print_queue(Queue *q)
{
    Cell *scan = q->start->next;

    if(q->size > 0)
    {
        while(scan != NULL)
        { //Runs until scan reaches the end.
            print_person(scan->data);
            printf("\n");
            scan = scan->next;
        }
    }
    else
    {
        printf("Nenhuma pessoa cadastrada.\n\n");
    }
}



//This function receives a queue and checks for cells that have informed number of priority to print, it uses a secondary function "print_person" to print it's data to terminal.
void print_priority_queue(Queue *q, int priority)
{
    bool searching = true;
    Cell *scan = q->start->next;

    if(q->size > 0)
    {
        do
        { //Runs ultil scan reachs the end or scan finds a person with lesser priority meaning there is no other person with specified priority.
            if(scan->data.priority == priority)
            {
                print_person(scan->data);
                printf("\n");
            }

            scan = scan->next;

            if(scan != NULL)
            {
                if(scan->data.priority > priority)
                {
                    searching = false;
                }
            }
            else
            {
                searching = false;
            }
        } while(searching == true);
    }
    else
    {
        printf("Nenhum pessoa cadastrada nessa fase.\n\n");
    }
}



//This function return "Cell" type object from a informed position of a queue.
Cell *get_cell(Queue *q, int position)
{
    Cell *scan = q->start;

    for(int i = 0; i < position; i++)
    { //Runs for each registered cell in the queue.
        scan = scan->next;
    }

    return scan;
}



//This function return "Cell" type object from a informed position of a queue.
void delete_cell(Queue *q, int position)
{
    Cell *scan = q->start;
    Cell *previous = NULL;

    for(int i = 0; i < position; i++)
    { //Runs for each registered cell in the queue.
        previous = scan;
        scan = scan->next;
    }

    previous->next = scan->next;

    if(scan == q->end)
    {
        q->end = previous;
    }

    q->size--;
    free(scan);
}

//This function creates a blank new cell with it's "next" pointer pointing to NULL by default.
Cell *new_cell()
{
    Cell *temp = (Cell*)malloc(sizeof(Cell));
    temp->next = NULL;
    return temp;
}



//This function converts a queue pointer into a proper queue, with a sentinel cell as it's start and end, defines initial size to 0.
//Uses a secondary function "new_cell" to create a new cell.
void new_queue(Queue *q)
{
    Cell *newcell = new_cell();

    q->start = newcell;
    q->end = newcell;
    q->size = 0;
}



//Fhis functino enqueues "Person" type ojects to a queue base on it's priority value.
void enqueue(Queue *q, Person data)
{
    Cell *newcell = new_cell();
    newcell->data = data;

    if(q->size > 0)
    {
        int priority = 2;

        switch(newcell->data.priority)
        { //Enqueues data differently depending on its priority value.
            case 4:
                priority++;
            case 3:
                priority++;
            case 2:
                priority++;
            case 1:
            {
                bool searching = true;
                Cell *scan = q->start;
                Cell *previous = NULL;

                do
                { //Finds spot for the new cell, runs until scan reaches the end or finds a cell with lesser priority to enqueue ahead.
                    previous = scan;
                    scan = scan->next;

                    if(scan != NULL)
                    {
                        if(scan->data.priority > priority)
                        {
                            searching = false;
                        }
                    }
                    else
                    {
                        searching = false;
                    }
                } while(searching == true);

                previous->next = newcell;
                newcell->next = scan;

                if(scan == NULL)
                {
                    q->end = newcell;
                }
                break;
            }

            case 5:
            {
                q->end->next = newcell;
                q->end = newcell;
                break;
            }
        }
    }
    else
    {
        q->end->next = newcell;
        q->end = newcell;
    }

    q->size++;
}



//This function checks for occurrences of a name in a queue.
//This function returns 0 if it does not find a cell with the same name, else it returns it's position value.
int scan_queue(Queue *q, char name[64])
{
    int position = 1;
    Cell *scan = q->start->next;

    while(scan != NULL)
    { //Runs until scan reaches the end.
        if(strcmp(name, scan->data.name) == 0)
        {
            return position;
        }

        scan = scan->next;
        position++;
    }

    return 0;
}
