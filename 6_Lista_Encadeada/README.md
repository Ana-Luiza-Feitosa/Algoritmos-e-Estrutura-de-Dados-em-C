# Lista Simplismente Encadeada

1. [Conceito](#conceito)
2. [Definição das estrututras de dados](#definição-das-estruturas-de-dados)
3. [Operações básicas](#operações-básicas)
4. [Implementação da Fila Encadeada](/6_Lista_Encadeada/implemetacao.c)
5. [Algortimos e soluções](/6_Lista_Encadeada/exercicios/)
    - [Estoque de loja](/6_Lista_Encadeada/exercicios/estoque.c)

## Conceito
Diferentemente das estruturas do tipo pilha e fila, a lista é uma estrutura mais genérica, pois a inserção e remoção de elementos pode ser feita em qualquer parte da lista. Dessa forma, uma lista encadeada pode ser **definida** genericamente como uma sequência de estruturas (nós) ligados entre si por ponteiros.

A lista simplismente encadeada é implementada alocando um novo espaço de memória para cada nó, dessa forma o espaço total de memória gasto pela estrutura é proporcional ao número de elementos nela armazenado.

**OBS:** não se pode garantir que os elementos ocurparão um espaço sequencial na memória, portanto o acesso a cada elemento não é direto.


## Definição das estruturas de dados
**A lista encadeada foi implementada de forma que os ponteiros para o primeiro e para o último elemento da lista são guardados, por isso duas estruturas de dados são definidas a seguir:

`Definição da estrutura do tipo nó e seu respectivo ponteiro:`
```C
typedef struct no{
    int info; //Informação armazenada, do tipo inteiro
    struct no *prox; //Ponteiro para o próximo elemento 
}TNo;

typedef TNo *PNo; //Ponteiro para a estrutura do tipo nó
```
<br>

`Definição da estrutra do tipo lista e seu respectivo ponteiro:`
```C
typedef struct lista{
    PNo inicio; //Ponteiro para o primeiro elemento da lista
    PNo fim; //Ponteiro para o último elemento da lista
}TLista;

typedef TLista *PLista; //Ponteiro para a estrutura do tipo lista
```


## Operações básicas

`Função para inicializar uma nova lista.`
```C
PLista inicializa_lista(){
    PLista lista = (PLista)malloc(sizeof(TLista)); //ALoca dinamicamente espaço de memória para uma nova lista
    lista->inicio = lista->fim == NULL; //incializa o inicio e fim da lista como nulos

    //Verifica se a alocação de memória foi bem sucedida
    if(lista == NULL)
        printf("Erro: memória não alocada corretamente.\n");
    
    return lista;
}
```
<br>

`Função para inserir um novo elemento no inicio da lista:`
```C
void insert_ini(PLista lista, int dado){
    PNo novo = (PNo)malloc(sizeof(TNo));//Aloca espaço de memória para um novo nó

    //Verifica se a alocação de memória foi bem sucedida
    if(novo == NULL){
        printf("Erro: memória para o novo nó não alocada corretamente.\n");
        return;
    }

    novo->info = dado; //Guarda a infromação passada como parâmentro no novo nó

    //Verifica se a fila está vazia 
    if(lista->inicio == NULL) 
        lista -> fim = novo;
    else
        novo->prox = lista->inicio; //O próximo elemento do novo nó aponta para o início da lista
    lista->inicio = novo; //Atribui o novo nó ao início da lista
}  
```
<br>

`Função para inserir um novo nó no meio da lista:`
```C
void insere_meio(PLista lista, int posicao, int dado){
    PNo novo = (PNo)malloc(sizeof(TNo)); //Aloca espaço de memória para um novo nó

    //Verifica se a alocação de memória para o novo nó foi bem sucedida
    if(novo == NULL){
        printf("Erro: memória para o novo nó não alocada corretamente.\n");
        return;
    }

    //Verifica se a lista está vazia
    if(lista->inicio == NULL){
        printf("A posicao passada não foi encontrada pois a lista se encontra vazia.\n");
        return;
    }

    PNo aux;//Drclaração de um ponteiro auxiliar para um nó, utilizado para percorrer a lista
    for(aux= lista->inicio; aux!=NULL; aux=aux->prox)
        if(aux->info == posicao){
            novo->info = dado;
            PNo aux2 = aux->prox;
            aux -> prox = novo;
            novo->prox = aux2;
            return;
        }
    
    printf("Informação passada como parametro não encontrada.\nO novo elemento não foi inserido na lista.\n");
    free(novo);
}
```
<br>

`Função para inserir um novo nó no final da lista:`
```C
void insere_fim(PLista lista, int dado){
    PNo novo = (PNo)malloc(sizeof(TNo)); //Aloca dinamicamente espaço de meória para um novo nó

    //Verifica se a alocação de memória foi bem-sucedida
    if(novo == NULL){
        printf("Erro: falha ao alocar espaço de memória para um novo nó.\n");
        return;
    }

    novo->info = dado;//Atribui o valor passado como parametro ao novo nó
    if(lista->inicio == NULL)//Verifica se a lista está vazia
        lista-> inicio = lista->fim = novo;
    //Se não 
    else{
        lista->fim->prox = novo; //Atribui o novo nó ao próximo elemento da lista, depois do fim
        lista->fim = novo; //Atualiza o novo fim da lista
    }
}

```
<br>

`Função para buscar um elemento na lista:`
```C
PNo busca_elemento(PLista lista, int info){
    PNo aux;
    for(aux = lista->inicio; aux != NULL;aux = aux->prox){
        if(aux->info == info)
            return aux;
    }
    return NULL;
}
```
<br>

`Função para buscar um elemento na lista e remove-lo:`
```C
void busca_e_remocao(PLista lista, int info){
    //Ponteiros auxiliares para a estrutura do tipo nó, usada para percorrer a lista
    PNo atual = lista->inicio; 
    PNo anterior = NULL;

    // Percorre a lista para encontrar o elemento a ser removido
    while (atual != NULL && atual->info != info) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o elemento não foi encontrado, exibe uma mensagem e retorna
    if (atual == NULL) {
        printf("Elemento não encontrado na lista.\n");
        return;
    }

    // Se o elemento a ser removido está no início da lista
    if (anterior == NULL) {
        lista->inicio = atual->prox;
    } else {
        // Remove o elemento da lista
        anterior->prox = atual->prox;
    }

    // Se o elemento a ser removido é o último da lista, atualiza o ponteiro para o fim
    if (atual == lista->fim) {
        lista->fim = anterior;
    }

    free(atual); // Libera a memória do elemento removido
}
```
<br>

`Função para liberar o espaço de memória alocado para os nós e para a lista:`
```C
void libera_lista(PLista lista){
    PNo lixo = lista->inicio; //Ponteiro auxiliar para o nó que será removido
    PNo aux; // Ponteiro auxiliar para percorrer a lista

    //Percorre a lista até que o ponteiro auxiliar lixo aponte para o vazio, ou seja, até que todos os elementos sejam removidos
    while(lixo!=NULL){
        aux = lixo->prox;
        free(lixo);
        lixo = aux;
    }

    free(lista);
}
```