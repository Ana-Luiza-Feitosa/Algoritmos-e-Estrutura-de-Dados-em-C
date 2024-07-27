# Lista Encadeada Circular
1. [Conceito](#conceito) 
2. [Definição das estruturas de dados](#definição-das-estruturas-de-dados) 
3. [Operações básicas](#operações-básicas) 
4. [Implementação da lista circular]() 
5. [Algoritmos e Soluções](#algortimos-e-soluções)


## Conceito
A estrutura do tipo **Lista Encadeada Circular** ou apenas **Lista Circular**, na forma de implementação, se assemelha muito a estrutura lista simplesmente encadeada. O que as diferem é que, na lista circular, o último elemento tem como próximo o
primeiro elemento da lista, formando um **ciclo**. Dessa forma, a rigor, não faz sentido falarmos em primeiro e último elemento.

**Representação:**  a lista circular pode ser representada como um ponteiro para um elemento qualquer da lista.   
Por convenção, guardamos sempre o endereço do último nó adicionado na lista.
 - Esta convenção tem a vantagem de poder **incluir ou remover** um elemento convenientemente **a partir do início ou final** de uma lista.

<br>
Um ponteiro nulo, representa uma fila circular vazia.


## Definição da estruturas de dados

```C
typedef struct fila_circular{
    int info;
    struct fila_circular *prox;
}TFila_C;
typedef TFila_C *PFila_C;
```

## Operações básicas

`Função para criar uma lista vazia. Por padrão, uma lista vazia é uma lista nula.`
```C
PLista_C cria_lista(){
    return NULL;
}
```
<br>

`Função para inserir um novo elemento no início da fila, ou seja, antes do primeiro elemento que foi inserido ou após o último elemento.`
```C
PLista_C insereInicio(PLista_C ultimo, int dado){
    PLista_C novo = (PLista_C)malloc(sizeof(TLista_C)); //Aloca espaço de memória para um novo nó
    novo->info = dado;
    if(ultimo == NULL){
        novo -> prox = novo; //Lista com um único elemento
        return novo; //Retorna o último nó, que é o único elemento da lista
    }
    //Adiciona o novo nó no início da lista circular
    novo -> prox = ultimo -> prox; //O novo nó aponta para o antigo início da lista circular
    ultimo -> prox = novo; // atualiza o início da fila, fazendo com que o último nó aponte para o novo nó

    return ultimo; //Retorna o último elemento da lista, que permaneceu inalterado
}
```
<br>

`Função para procurar um elemento na lista. A função retorna apenas se o elemento existe ou não na lista, ignorando informações duplicadas.`
```C
int buscaElemento(PLista_C ultimo, int info){
    if(ultimo == NULL)//Verifica se a lista está vazia
        return 0;

    PLista_C aux;//Ponteiro para nó auxiliar, para ajudar a percorer a lista circular
    for(aux = ultimo->prox; aux!= ultimo; aux = aux ->prox) 
        if(aux -> info == info)
            return 1;

    if(ultimo -> info == info) return 1; //Verifica se a informação buscada está no último nó da lista

    return 0;

}
```
<br>

`Função que remove o primeiro nó que contenha o elemento passado como parâmetro.`
```C
PLista_C removeElemento(PLista_C ultimo, int info){
    if(ultimo == NULL)//Se a lista circular estiver vazia, retorna 
        return NULL;
    
    PLista_C aux,ant = ultimo;//Ponteiros para nó auxiliares, para ajudar a percorer a lista circular e remover o nó desejado
    //Percorre a lista circular a partir do primeiro nó, enquanto o ponteiro auxiliar não apontar para o último elemento
    for(aux = ultimo->prox;aux!=ultimo; aux = aux->prox){
        if(aux->info == info){
            ant->prox = aux->prox;
            free(aux);
            break;
        }
        ant = aux;
    }
    //Se a informação buscada estiver no último elemento da lista ciricular
    if(ultimo->info == info){
        if (ultimo->prox == ultimo){ // Se há apenas um nó na lista
            free(ultimo); //Libera o espaço de meória do único elemento
            return NULL; //Retorna a lista vazia
        } 
        else{
            ant->prox = ultimo->prox; //Atualiza o poteiro do nó anterior ao último, apontando para o primeiro
            free(ultimo); //Libera o espaço de memória do elemento removido
            ultimo = ant; //Atualiza o novo último elemento da lista circular
        }
    }
    return ultimo; //Retorna o último elemento da lista circular
}
```
<br>

`Função que lista todos os elementos da lista circular.`
```C
int listarElementos(PLista_C ultimo){
    if(ultimo == NULL) //Se a lista circular estiver vazia, retorna -1
        return -1;
    PLista_C aux; //Ponteiro auxiliar, para ajudar a percorrer a lista circular encadeada
    for(aux = ultimo -> prox; aux != ultimo; aux = aux -> prox) //Percorre a lista, a partir do primeiro elemento, enquanto o ponteiro auxiliar não apontar para o ultimo elemento
        printf("%d, ", aux->info); //Imprime a informação armazenada temporariamente no nó auxiliar

    printf("%d.\n", ultimo->info);//Por fim, imprime a informação no último no
    return 0; 
}
```
<br>

`Função para liberar o espaço de memória alocado para todos os nós a lista circular.`
```C
PLista_C liberarListaCirc(PLista_C ultimo){
    if(ultimo == NULL)//Se a lista estiver vazia, retorna NULL
        return NULL;
    PLista_C aux, no_removido;

    for(aux = ultimo->prox; aux!=ultimo;aux=aux->prox){
        no_removido = aux;
        ultimo->prox = aux->prox;
        free(no_removido);
    }
    free(ultimo);
    return NULL;//Lista vazia, retorna NULL
}
```
## Algortimos e soluções
 - [Sorteio de soldados](soldados.c)