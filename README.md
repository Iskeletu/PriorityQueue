# PriorityQueue

PriorityQueue is a C program that creates a vaccination queue based on the following criteria:  
- Working Field  
- Age  
- Health Condition  

***The registered people are divided in 5 groups:***  
- Phase One:
  * People that work with health care and/or are above 75 years old.
- Phase Two:
  * People that are btween 60 and 74 years old.
- Phase Three:
  * People that have health conditions.
- Phase Four:
  * People that work in the teaching fiel or public security field.
- Non Priority:
  * Everyone that isn't part of the four groups listed above.
  
    
The program saves the queue into a *.dat* file in [Queue](Queue) direcotry.  
Default example queue file has been added to the project.

## Usage

The program will automatically try to load "queue.dat" file into the queue if it is not empty.  
Main menu:
```bash
Bem vindo!

Selecione um opcao:

1 - Cadastrar pessoa na fila
2 - Exibir fila geral
3 - Filtrar fila por fase
4 - Localizar posicao na fila
5 - Editar Pessoa
0 - Salvar e sair

> _
```
- Option 1 ```Cadastrar pessoa na fila```:
  * Register a person an enqueues it, will require the following information:
    - Name;
    - Age;
    - Profession field;
    - Health condition;  

The same name cannot be registered twice.  
The user will be given an option to enqueue this person or discard it.  

- Option 2 ```Exibir fila geral```:  

Prints the whole queue, person data will be displayed as following:
```bash
{
Nome: {name}
Idade: {age}
Area da profissao: {work field}
Tem problema de saude: {health condition}
}
```

- Option 3 ```Filtrar fila por fase```:  

This option will display a sub menu to select which priority is to be displayed.  
Prints the queue filtered by select priority, it displays data in the same pattern as Option 2.

- Option 4 ```Localizar posicao na fila```:  

Requires a name, it compares the informed name with each of the registeres cells and returns it's position on the queue.  
Will return nothing if there is no person with the informed name registered.

- Option 5 ```Editar Pessoa```:  

Requires a position *(can be consulted with option 4)*, it gets the cell stored in this position of the queue and deletes it.
Will enqueue a substitute cell using the same interface as option 1.

- Option 0 ```Salvar e sair```:  

Exit option, will store queue data into file and close the program when selected.

## License

Distributed under MIT License, see [LICENSE](LICENSE) for more information.

## PUC MINAS - CORAÇÃO EUCARÍSTICO
