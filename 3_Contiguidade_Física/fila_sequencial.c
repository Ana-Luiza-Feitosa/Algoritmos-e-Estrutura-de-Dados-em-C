#include <stdio.h>
#include <stdlib.h>

#define MAX_FILA 100 //Define o número máximo de elementos que podem ser armazenados na fila

//Definição da estrutura do tipo fila.
typedef struct fila{
    int elemento[MAX_FILA]; //Armazena os elementos da fila
    int n; //Contabiliza a quantidade de elementos armazenados
    int ini; //Marca o início da fila
}TFila;
typedef TFila *PFila; //Define o ponteiro para a estrutura do tipo fila

/*
 Função que cria uma fila vazia.
 @return fila: retorna a fila vazia inicializada.
*/
PFila cria_fila(){
    PFila fila = (PFila)malloc(sizeof(TFila)); //Aloca dinamicamente espaço de memória para a fila
    fila -> n = 0; //Atribui a fila como vazia, com zero elementos
    fila -> ini = 0; //O início da fila o índice zero
    return fila;
}

/*
 Função para inserir um elemento no final da fila.
 @param fila: estrutura do tipo fila, onde o dado passado como parâmetro será armazenado.
 @param dado: valor que será armazenado, do tipo inteiro.
 @return: retorna -1 se o elemtno não foi inserido na fila e 0 se a inserção foi feita.
*/
int insere_elemento(PFila fila, int dado){
    //Verifica se o espaço de memória para a estrutura do tipo pilha foi alocado corretamente
        if(fila == NULL) 
        return -1; 

    //Verifica se há espaço disponível na fila para inserir um novo elemento
    if(fila->n >= MAX_FILA){
        printf("A fila está cheia.\nO elemento em questão não pôde ser armazenado.\n");
        return -1;
    }
    
    int fim = (fila->n + fila->ini)%MAX_FILA; //Fim da fila
    fila->elemento[fim] = dado; //Atribui o valor passado como parâmetro ao fim da fila
    fila->n++; //Atualiza número de elementos armazenados na fila

    return 0; //Se a inserção foi bem-sucedida, retorna 0
}

/*
 Função para remover o elemento mais antigo inserido na fila.
 @param fila: ponteiro para a estrutura do tipo fila.
 @param dado: ponteiro para inteiro, que armazena o elemento removido da fila.
*/
void remove_elemento(PFila fila, int *dado){
    //Verifica se o espaço de memória para a estrutura do tipo pilha foi alocado corretamente
    if(fila == NULL){
        printf("Memória para fila não alocada corretamente.\n");
        return;
    }

    //Verifica se a fila está vazia, se sim, retorna 
    if(fila->n == 0){
        printf("FIla vazia.\n");
        return;
    }


    int n; //Variável auxiliar para ajudar a incrementar o início da fila
    if(fila->ini == MAX_FILA - 1)
        n = 0;
    else
        n = fila->ini + 1;

    *dado = fila->elemento[n]; //Armazena em um ponteiro o valor contido no elemento que será removido
    fila->ini++; //Atualiza o início da fila
    fila->n--; //atualiza a quantidade de elementos armazenados na fila
    return;
}

/*
 Função para liberar o espaço de memória alocado para a estrutura do tipo fila.
*/
void libera_fila(PFila fila){
    free(fila);
}


