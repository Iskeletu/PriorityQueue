#ifndef queue_h_
#define queue_h_

//==========Structs==========
typedef struct Person
{
    char name[64];
    int age;
    int profession;
    int condition;
    int priority;
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
Cell *get_cell(Queue *q, int position);
void delete_cell(Queue *q, int position);
void print_queue(Queue *q);
void print_priority_queue(Queue *q, int priority);
void print_person(Person p);
int scan_queue(Queue *q, char name[64]);
//===========================

#endif
