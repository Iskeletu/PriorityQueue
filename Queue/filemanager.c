#include <stdio.h>
#include <stdlib.h>

#include "filemanager.h"



//
void load_queue(Queue *q, int type)
{
    FILE *file;

    switch(type)
    {
        case 1:
            file  = fopen("Queue//First Phase.dat", "rb");
            break;

        case 2:
            file = fopen("Queue//Second Phase.dat", "rb");
            break;

        case 3:
            file = fopen("Queue//Third Phase.dat", "rb");
            break;

        case 4:
            file = fopen("Queue//Fourth Phase.dat", "rb");
            break;

        case 5:
            file = fopen("Queue//Non Priority.dat", "rb");
            break;
    }

    if(file == NULL)
    {
        exit(700); //This exit code means the program has failed to create/open a file in the Queue folder.
    }
    else
    {
       //TODO
    }

    fclose(file);
}



//
void save_queue(Queue *q, int type)
{
    FILE *file;

    switch(type)
    {
        case 1:
            file = fopen("Queue//First Phase.dat", "wb");
            break;

        case 2:
            file = fopen("Queue//Second Phase.dat", "wb");
            break;

        case 3:
            file = fopen("Queue//Third Phase.dat", "wb");
            break;

        case 4:
            file = fopen("Queue//Fourth Phase.dat", "wb");
            break;

        case 5:
            file = fopen("Queue//Non Priority.dat", "wb");
            break;
    }

    if(file == NULL)
    {
        exit(700); //This exit code means the program has failed to create/open a file in the Queue folder.
    }
    else
    {
       //TODO
    }

    fclose(file);
}
