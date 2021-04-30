#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Includes queue functions
#include "queue.h"

//Includes file manager function
#include "filemanager.h"



//Main menu function, prints interface and reads user selection, checks for invalid user selection;
int menu()
{
    int selection;

    printf("Bem vindo!\n\n");

    do
    {
        printf("Selecione um opcao:\n\n");
        printf("1 - Cadastrar pessoa na fila\n");
        printf("2 - Exibir fila geral\n");
        printf("3 - Filtrar fila por fase\n");
        printf("4 - Localizar posicao na fila\n");
        printf("5 - Editar Pessoa\n");
        printf("0 - Salvar e sair\n\n> ");

        scanf("%d", &selection); fflush(stdin);
        system("cls");

        if(selection < 0 || selection > 5)
        {
            printf("Erro! Opcao invalida.\n\n");
        }
    } while(selection < 0 || selection > 5);

    return selection;
}



//Printing queue sorted by phase menu, prints interface and reads user selection, checks for invalid user selection;
void queue_printing_menu(Queue *queue)
{
    int selection;

    do
    { //Checks for invalid user selection.
        printf("Selecione qual fila:\n\n");
        printf("1 - Fila da fase 1\n");
        printf("2 - Fila da fase 2\n");
        printf("3 - Fila da fase 3\n");
        printf("4 - Fila da fase 4\n");
        printf("5 - Fila nao prioritaria\n");
        printf("0 - Voltar\n\n> ");
        scanf("%d", &selection); fflush(stdin);

        if(selection < 0 || selection > 5)
        {
            system("cls");
            printf("Erro! Opcao invalida!\n\n");
        }
    } while(selection < 0 || selection > 5);

    system("cls");

    switch(selection)
    {
        case 1:
            printf("Fase 1:\n\n");
            break;

        case 2:
            printf("Fase 2:\n\n");
            break;

        case 3:
            printf("Fase 3:\n\n");
            break;

        case 4:
            printf("Fase 4:\n\n");
            break;

        case 5:
            printf("Fase nao prioritaria:\n\n");
            break;
    }

    if(selection != 0)
    {
        print_priority_queue(queue, selection);
        printf("\n");
        system("PAUSE");
    }

    system("cls");
}



//Register person interface function, it reads user data and converts it into a "Person" object, the result is enqueued into it's respective queue.
//This function returns 1 of the Person object is ready to be enqueued.
int register_person(Queue *queue, Person *person)
{
    do
    { //Checks for unique name.
        printf("Digite o nome da pessoa:\n> ");
        fgets(person->name, 64, stdin); fflush(stdin);

        if(scan_queue(queue, person->name) != 0)
        {
            system("cls");
            printf("Erro! Nome ja cadastrado.\n\n");
        }
    } while(scan_queue(queue, person->name) != 0);

    do
    { //Checks for valid age.
        printf("\nDigite a idade da pessoa:\n> ");
        scanf("%d", &person->age); fflush(stdin);

        if(person->age < 0 || person->age > 130)
        {
            system("cls");
            printf("Erro! Insira uma idade valida.\n");
        }
    } while(person->age < 0 || person->age > 130);

    do
    { //Checks for valid profession.
        printf("\nSelecione a area da profissao da pessoa:\n\n");
        printf("1 - Saude\n");
        printf("2 - Ensino/Seguranca\n");
        printf("3 - Outro\n\n> ");
        scanf("%d", &person->profession); fflush(stdin);

        if(person->profession < 1 || person->profession > 3)
        {
            system("cls");
            printf("Erro! Opcao invalida.\n");
        }
    } while(person->profession < 1 || person->profession > 3);

    do
    { //Checks for valid health condition.
        printf("\nEsta pessoa tem alguma condicao de saude?\n\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n\n> ");
        scanf("%d", &person->condition); fflush(stdin);

        if(person->condition < 1 || person->condition > 2)
        {
            system("cls");
            printf("Erro! Opcao invalida.\n");
        }
    } while(person->condition < 1 || person->condition > 2);

    if(person->profession == 1 || person->age >= 75)
    {
        person->priority = 1;
    }
    else if(person->age > 60)
    {
        person->priority = 2;
    }
    else if(person->condition == 1)
    {
        person->priority = 3;
    }
    else if(person->profession == 2)
    {
        person->priority = 4;
    }
    else
    {
        person->priority = 5;
    }

    system("cls");
    print_person(*person);

    int selection;

    do
    { //Confirms if current Person object is ready to be enqueued.
        printf("\nDeseja cadastrar esta pessoa na fila?\n\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n\n> ");
        scanf("%d", &selection); fflush(stdin);

        if(selection < 1 || selection > 2)
        {
            system("cls");
            print_person(*person);
            printf("\nErro! Opcao invalida.\n");
        }
    } while(selection < 1 || selection > 2);

    system("cls");

    return selection;
}



//Edit person interface function, it deletes a given cell from the queue and replaces it with a new one informed by the user.
//This function uses a secondary function "register_person" to register a new cell.
void edit_person(Queue *queue)
{
    if(queue->size > 0)
    { //Checks if queue has at least one person registered in.
        int position;

        do
        { //Checks for valid position.
            printf("Informe a posicao da pessoa a ser editada:\n> ");
            scanf("%d", &position); fflush(stdin);

            if(position <= 0 || position > queue->size)
            {
                system("cls");
                printf("Erro! Posicao inexistente.\n\n");
            }
        } while(position <= 0 || position > queue->size);

        Cell *scan = queue->start;

        for(int i = 0; i < position; i++)
        { //Makes "scan" point to the specified cell.
            scan = scan->next;
        }

        system("cls");

        int selection;

        do
        { //Checks for valid selection.
            print_person(scan->data);
            printf("\nDeseja editar esta pessoa?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n\n> ");
            scanf("%d", &selection); fflush(stdin);

            if(selection < 1 || selection > 2)
            {
                system("cls");
                printf("Erro! Opcao invalida.\n\n");
            }
        } while(selection < 1 || selection > 2);

        system("cls");

        if(selection == 1)
        {
            delete_cell(queue, position);
            int sub_selection;
            Person *person = (Person*)malloc(sizeof(Person));

            do
            {
                printf("Informe os novos dados:\n\n");
                sub_selection = register_person(queue, person);
            } while(sub_selection != 1);

            enqueue(queue, *person);
            person = NULL;
            free(person);
        }
    }
    else
    {
        printf("Nao ha pessoas cadastradas na fila.\n\n");
        system("PAUSE");
        system("cls");
    }
}



int main()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue)); new_queue(queue);
    /*
    Phase1  = people that work with health or are above 75 years old.
    Phase2 = people that have between 60 and 74 years old.
    Phase3 = people that have health conditions.
    Phase4 = workers of the teaching or public security field.
    Non Priority queue = everyone else.
    */

    //Try to load file data into queue if it exists and isn't empty.
    printf("Tentando carregar arquivo...\n");
    int load = load_queue(queue);
    if(load == 1)
    {
        printf("Arquivo carregado com sucesso\n\n");
    }
    else
    {
        printf("Nao ha dados a serem carregados\n\n");
    }
    system("PAUSE");
    system("cls");

    int selection;
    bool sair = false;

    do
    { //Main loop
        selection = menu();

        switch(selection)
        { //Main menu selection
            case 0:
            { //Save and exit option.
                sair = true;
                break;
            }

            case 1:
            { //Register person option.
                Person *person = (Person*)malloc(sizeof(Person));
                int sub_selection = register_person(queue, person);

                if(sub_selection == 1)
                { //Selects what queue the Person object has to be enqueued to.
                    enqueue(queue, *person);
                }

                person = NULL;
                free(person);

                break;
            }

            case 2:
            { //Prints queues to terminal option.
                printf("Fila geral:\n\n");
                print_queue(queue);
                printf("\n");
                system("PAUSE");
                system("cls");
                break;
            }

            case 3:
            { //Prints specific queue to terminal option.
                queue_printing_menu(queue);
                break;
            }

            case 4:
            {  //Finds registered person with informed name and prints it's position;
                if(queue->size > 0)
                {
                    char name[64];
                    printf("Informe um nome a ser pesquisado:\n> ");
                    fgets(name, 64, stdin); fflush(stdin);
                    system("cls");

                    int position = scan_queue(queue, name);

                    if(position == 0)
                    {
                        printf("Nenhum resultado encontrado para o nome:\n%s\n", name);
                        system("PAUSE");
                        system("cls");
                    }
                    else
                    {
                        Cell *scan = queue->start;

                        for(int i = 0; i < position; i++)
                        { //Makes "scan" point to specified cell.
                            scan = scan->next;
                        }

                        print_person(scan->data);

                        printf("\nPosicao na fila: %d\n\n", position);
                        system("PAUSE");
                        system("cls");
                    }
                }
                else
                {
                    printf("Nao ha pessoas cadastradas na fila.\n\n");
                    system("PAUSE");
                    system("cls");
                }
                break;
            }

            case 5:
            { //Edits informed cell in the queue.
                edit_person(queue);
                break;
            }
        }
    } while(sair == false);

    //Saves queue to file.
    printf("Salvando arquivo...\n");
    save_queue(queue);
    printf("Arquivo salvo com sucesso.\n");

    free(queue);

    return 0;
}
