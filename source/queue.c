#include <stdio.h>
#include <stdlib.h>

#include "queue.h"



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

        default:
            exit(253); //This exit code means that the profession was not registered correctly.
    }

    switch(p.condition)
    { //Converts condition value to it's correspondent description.
        case 1:
            printf("Tem problema de saude: Sim\n}\n");
            break;

        case 2:
            printf("Tem problema de saude: Nao\n}\n");
            break;

        default:
            exit(235); //This exit code means that the condition was not registered correctly.
    }
}



//This function receives a queue and uses a secondary function "print_person" to print it's data to terminal.
void print_queue(Queue *q)
{
    Cell *scan = q->start->next;

    while(scan != NULL)
    {
        print_person(scan->data);
        scan = scan->next;
    }
}



//This function return the amount of objects there are in a given queue.
int sizeofqueue(Queue *q)
{
    return q->size;
}



//
Cell *new_cell()
{
  Cell *temp = (Cell*)malloc(sizeof(Cell));
  temp->next = NULL;
  return temp;
}



//
void new_queue(Queue *q)
{
  Cell *newcell = new_cell();

  q->start = newcell;
  q->end = newcell;
  q->size = 0;
}



//
void enqueue(Queue *q, Person data)
{
  Cell *newcell = new_cell();
  newcell->data = data;

  q->end->next = newcell;
  q->end = newcell;
  q->size++;
}


