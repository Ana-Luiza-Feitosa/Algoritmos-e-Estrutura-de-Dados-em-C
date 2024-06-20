# Fila Encadeada

1. [Conceito](#conceito-e-exemplos) 
2. [Definição das estrututras de dados](#definição-das-estruturas-de-dados)
3. [Operações básicas](#operações-básicas)
4. [Implementação da Fila Encadeada](/5_Fila_Encadeada/implementacao.c)
5. [Algortimos e soluções](/5_Fila_Encadeada/exercicios)

## Conceito e aplicaçõoes
**Filas** são estruturas nas quais é possível inserir elementos em uma extremidade e retirar da outra. São conhecidas por serem estruturas do tipo FIFO, ou seja, o primeiro elemento a entrar é também o primeiro a sair.

> FIFO: First-in, First-out

 Os elementos são ordenados confrome o tempo de chegada.

### Utilizações mais comuns
- Fila de processos em Sistemas operacionais
- Fila de impressão
- Tratamento de teclas acionadas no computador
- Check-in de voô


## Definição das estruturas de dados

 Para a implementação de uma fila simplesmente encadeada em C, utilizamos duas estruturas principais: a estrutura do tipo nó, responsável por armazenar a informação passada e um ponteiro para o próximo elemento da fila, e estrutura do tipo fila, que armazena ponteiros para os nós que marcam o início e fim da fila.   

Além disso, também utilizamos ponteiros tanto para estrutura do tipo nó, quanto para a estrutura do tipo fila.

Para cada novo elemento inserido na estrutura, alocamos um espaço de
memória para armazená-lo.

`Definição da estrutura do tipo nó e seu respectivo ponteiro`
```C

typedef struct no{
    int info; //Informação armazenada, do tipo inteiro
    struct no *prox; //Ponteiro para o próximo nó da fila
}TNo;
typedef TNo *PNo; //Ponteiro para a estrutura do tipo nó
```

`Definição da estrutura do tipo fila e seu respectivo ponteiro`
```C
typedef struct fila{
    PNo inicio; //Define o primeiro elemento da fila
    PNo fim; //Define o último elemento da fila
}TFila;
typedef TFila *PFila; //Ponteiro para a estrutura do tipo fila;
```

<br>

## Operações básicas

`1. Função para incializar a fila:`

```C
PFila inicializa_fila(PFila fila){
    PFila nova = (PFila)malloc(sizeof(TFila)); //Aloca dinamicamente espaço de memória para uma nova fila

    //Verifica se a alocação de memória foi bem-sucedida
    if(nova == NULL){
        printf("Erro: falha ao alocar memória para um novo nó.\n");
        return NULL;
    }
    nova->inicio = nova-> fim = NULL;  //Inicializa os ponteiros de início e fim da fila como NULL
    return nova;
}
```
<br>

`2. Função para inserir um novo nó no final da fila:`

```C
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
```

<br>

`3. Função para remover um nó do início da fila`

```C
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
```

<br>

`4. Função para listar todos os elementos da fila, do inicio ao fim, de forma recursiva:`

```C
void listarRecursivo(PNo no){
    if(no == NULL) //Verifica se o nó está vazio, se sim, sai da função
        return;
    printf("%i ", no->info); //Imprime a informação contida no nó
    return listarRecursivo(no->prox); //Atualiza o parâmetro da função para o próximo nó da fila
}
```

<br>

`5.Função interativa para listar os elementos da fila, do início ao fim:`

```C
void listar(PFila fila){
    PNo aux; //Ponteiro auxiliar para estrutura do tipo nó, usado para percorrer a fila
    for(aux = fila->inicio; aux!=NULL; aux= aux->prox) //Percorre a lista, atualizando o nó auxiliar sempre para o próximo nó, até que o nó auxiliar seja nulo
        printf("%i ", aux->info); //Imprime a informação contida no nó
}
```

<br>

`6. Função para liberar os espaços de memória alocados para os nós e para a fila.`

```C
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
```