#include <stdio.h>
#include <stdlib.h>

#define MAX_LISTA 100

typedef struct lista{
    int n;//Armazena o número de elementos inseridos na lista
    int ini;
    int fim;
    int vet[MAX_LISTA];
}TLista;

typedef TLista *PLista;

PLista inicializa_lista_seq(){
    PLista nova = (PLista)malloc(sizeof(TLista));
    nova -> n = 0;
    nova ->ini = 0;
    nova -> fim = -1;
    return nova;
}

int insere_elemento_fim(PLista l, int valor){
    if(l == NULL) return -1;
    if(l -> n == MAX_LISTA) return -1;
    
    if(l->fim==MAX_LISTA-1)
        l->fim = 0;
    else
        if(l-> n == 0){
            l->ini = 0;
            l->fim = 0;
        }
        else
            (l->fim)++;
    
    l->vet[l->fim] = valor;
    (l->n)++;

    return 0;
}

int insere_elemento_inicio(PLista l, int valor){
    if(l == NULL) return -1;
    if(l->n == MAX_LISTA) return -1;

    if(l->n == 0){//Se a list aestiver vazia, insere o primeiro elemento no índice 0 e atualiza os ponteiros de inicio e fim para esse índice
        l->ini = 0;
        l->fim = 0;
    }
    else{
        if(l->ini == 0)
            l->ini = MAX_LISTA -1;
        else
            (l->ini)--;
    }
    
    l->vet[l->ini] = valor;
    (l->n)++;

    return 0;
}

int remove_inicio(PLista l, int *valor){
    if(l == NULL) return -1;
    if(l-> n == 0) return -1;

    *valor = l->vet[l->ini];
    (l-> n)--;

    if(l-> n == 0){
        l->ini = 0;
        l->fim = -1;
    }
    else{
        if(l->ini = MAX_LISTA-1)
            l->ini = 0;
        else
            (l->ini)++;
    }
        
    return 0;
}

int remove_fim(PLista l, int *valor){
    if(l==NULL) return -1;
    if(l->n == 0) return -1;

    *valor = l->vet[l->fim];
    (l->n)--;

    if(l->n == 0){
        l->fim = -1;
        l-> ini = 0;
    }
    else{
        if(l->fim == 0)
            l->fim = MAX_LISTA-1;
        else 
            (l-> fim)--;
    }

    return 0;
}

void liberar_memoria(PLista l){
    free(l);
}
