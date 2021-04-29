#ifndef queue_h_
#define queue_h_

//==========Structs==========
typedef struct Person
{
    char name[64];
    int age;
    int profession;
    int condition;
} Person;

typedef struct Cell
{
    Person data;
    struct Cell *next;
} Cell;

typedef struct Queue
{
    Cell *start;
    Cell *end;
    int size;
} Queue;
//===========================

//=========Functions=========
Cell *new_cell();
void new_queue(Queue *q);
void enqueue(Queue *q, Person data);
void enqueue_priority(Queue *q, Person data);
int sizeofqueue(Queue *q);
void print_queue(Queue *q);
void print_person(Person p);
//===========================

#endif
