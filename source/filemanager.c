#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filemanager.h"



//Saves queue data into file.
void save_queue(Queue *queue)
{
    FILE *file = fopen("Queue\\Queue.dat", "w");

    if(file == NULL)
    { //Checks if the file was open successfully.
        exit(302); //This means the program has failed to open/create a file in "Queue" directory.
    }

    Cell *scan = queue->start->next;

    while(scan != NULL)
    {
        fprintf(file, "{\n%s", scan->data.name);
        fprintf(file, "%d %d %d %d\n}\n\n", scan->data.age, scan->data.profession, scan->data.condition, scan->data.priority);

        scan = scan->next;
    }
    fprintf(file, "!");

    fclose(file);
}



//Load queue data from file.
//Return 1 if if has successfully loaded queue with file contents, return 0 otherwise.
int load_queue(Queue *queue)
{
    FILE *file = fopen("Queue\\Queue.dat", "a"); fclose(file); //Creates a files if it does not exist.
    file = fopen("Queue\\Queue.dat", "r");

    if(file == NULL)
    { //Checks if the file was open successfully.
        exit(302); //This means the program has failed to open/create a file in "Queue" directory.
    }

    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    if(file_size == 0)
    { //Checks if files have content on it
        return 0;
    }
    rewind(file);

    char scanner;
    Person *scanperson = (Person*)malloc(sizeof(Person));

    fscanf(file, "%c\n", &scanner);
    do
    { //File scanner.
        fgets(scanperson->name, 64, file);
        fscanf(file, "%d ", &scanperson->age);
        fscanf(file, "%d ", &scanperson->profession);
        fscanf(file, "%d ", &scanperson->condition);
        fscanf(file, "%d\n", &scanperson->priority);
        fscanf(file, "%c\n\n", &scanner);
        fscanf(file, "%c\n", &scanner);

        enqueue(queue, *scanperson);
    } while(scanner == '{');

    scanperson = NULL;
    free(scanperson);
    fclose(file);
    return 1;
}
