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

## Algortimos e soluções