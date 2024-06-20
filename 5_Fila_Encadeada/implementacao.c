#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura do tipo nó
typedef struct no{
    int info; //Informação armazenada, do tipo inteiro
    struct no *prox; //Ponteiro para o próximo nó da fila
}TNo;
typedef TNo *PNo; //Ponteiro para a estrutura do tipo nó

//Defição da estrutura do tipo fila
typedef struct fila{
    PNo inicio; //Define o primeiro elemento da fila
    PNo fim; //Define o último elemento da fila
}TFila;
typedef TFila *PFila; //Ponteiro para a estrutura do tipo fila;

/*
 * Função para inicializar a fila
 * @param fila: ponteiro para estrutura do tipo fila que será alocada
 * @return: fila alocada dinamicamente
*/
PFila inicializa_fila(PFila fila){
    PFila nova = (PFila)malloc(sizeof(TFila)); //Aloca dinamicamente espaço de memória para uma nova fila

    //Verifica se a alocação de memória foi bem-sucedida
    if(nova == NULL){
        printf("Erro: falha ao alocar memória para uma nova fila.\n");
        return NULL;
    }
    nova->inicio = nova-> fim = NULL;  //Inicializa os ponteiros de início e fim da fila como NULL
    return nova;
}

/*
 * Função para inserir um novo nó no final da fila
 * @param  fila: ponteiro para estrutura do tipo fila
 * @param dado: número inteiro que será armazenado no novo nó
*/
void insert(PFila fila, int dado){
    PNo novo = (PNo)malloc(sizeof(TNo)); //Aloca dinamicamente espaço de memória para um novo nó

    //Verifica se a alocação de memória foi bem-sucedida
    if(novo == NULL) {
        printf("Erro: falha ao alocar memória para um novo nó.\n");
        return;
    }

    novo->info = dado;//Atribui a valor passado como parâmentro ao novo nó
    novo->prox = NULL; //O novo nó aponta para NULL, pois será o último nó da fila

    if(fila->inicio == NULL) //Se a fila está vazia
        fila->inicio = novo; //Nó novo é o primeiro elemento da fila
    
    else
        fila->fim->prox = novo; //Senão, nó novo é o colocado após o último elemento da fila

    fila->fim = novo; //Atualiza o fim da fila
}


/*
 * Função para remover um nó do início da fila
 * @param fila: ponteiro para estrutura do tipo fila
 * @param dado: ponteiro para inteiro, que armazenará a informação do nó removido
*/
PNo remove_no(PFila fila, int *dado){
    //Verifica se há espaço de memória alocado para a fila passada como parâmetro
    if(fila == NULL){
        printf("Erro: flha ao alocar memória para a fila.\n");
        return NULL;
    }
    //Verifica se a fila está vazia
    if(fila->inicio == NULL){
        printf("Fila vazia.\n");
        return NULL;
    }

    //Se não estiver vazia e for alocada corretamente, faz a remoção do nó do início da fila
    *dado = fila->inicio->info; //Armazena em um ponteiro para inteiro a informação contida no nó removido

    PNo lixo = fila->inicio; //Ponteiro para auxiliar na remoção do nó
    fila->inicio = fila->inicio->prox; //Atualiza o novo início da fila

    if(fila->inicio == NULL)//Verifica se a fila ficou vazia após a remoção
        fila->fim = NULL;

    free(lixo); //Libera o espaço de memória alocado para o nó removido

    return fila->inicio;//retorna o novo início da fila 
}

/*
 * Função para listar todos os elementos da fila, do inicio ao fim, de forma recursiva
 * @param inicio: ponteiro para o primeiro nó da fila
*/
void listarRecursivo(PNo no){
    if(no == NULL) //Verifica se o nó está vazio, se sim, sai da função
        return;
    printf("%i ", no->info); //Imprime a informação contida no nó
    return listarRecursivo(no->prox); //Atualiza o parâmetro da função para o próximo nó da fila
}

/*
 * Função interativa para listar os elementos da fila, do início ao fim.
 * @param: ponteiro para a estrutura do tipo fila
*/
void listar(PFila fila){
    PNo aux; //Ponteiro auxiliar para estrutura do tipo nó, usado para percorrer a fila
    for(aux = fila->inicio; aux!=NULL; aux= aux->prox) //Percorre a lista, atualizando o nó auxiliar sempre para o próximo nó, até que o nó auxiliar seja nulo
        printf("%i ", aux->info); //Imprime a informação contida no nó
}

/*
 * Função para liberar os espaços de memória alocados para os nós e para a fila.
 * @param fila: ponteiro para estrutura do tipo fila
*/
void libera(PFila fila){
    //Verifica o espaço de memória para a fila foi alocado corretamente
    if(fila == NULL){
        printf("Erro: flha para alocar espaço de memória para a fila.\n");
        return;
    }

    PNo aux = fila->inicio;//Ponteiro auxiliar para estrutura do tipo nó, usado para percorrer a fila
    
    while(aux!=NULL){
        PNo lixo = aux;//Armazena o nó atual em uma variável temporária
        aux = aux->prox;//Atualiza o ponteiro auxiliar para o próximo nó
        free(lixo);//Libera o espaço de memória alocado para o nó atual
    }
    
    free(fila); //Libera o espaço de memória alocado para a estrutura do tipo fila
}

int main(){
    return 0;
}