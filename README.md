# PriorityQueue

PriorityQueue is a C program that creates a vaccination queue base on the following criteria:  
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
  
    
The program saves the queue into it's respective *.dat* files in [Queue](Queue) direcotry.  
Default example queue files has been added to the proejct.

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

The user will be given an option to enqueue this person or discrd it.  

- Option 2 ```Exibir fila geral```:  

Prints the whole queue, person data will me displayed as following:
```bash
{
Nome: {name}
Idade: {age}
Area da profissao: {work fiel}
Tem problema de saude: {health condition}
}
```

## License

Distributed under MIT License, see [LICENSE](LICENSE) for more information.

## PUC MINAS - CORAÇÃO EUCARÍSTICO
