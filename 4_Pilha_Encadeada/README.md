# Pliha Simplesmente encadeada

1. Conceito 
2. Definição das estrututras de dados
3. Operações básicas
4. Implementação da Fila Encadeada
5. [Algortimos e soluções](/4_Pilha_Encadeada/)
  

----
<br>  

## Conceito

**Pilhas** são estruturas de dados na qual o novo elemento é sempre inserido após os que já estão na estrutura, e o elemento retirado é sempre o último que foi inserido. A estrutura do tipo pilha recebe esse nome pois os elementos são armazenados sequencialmente, **empilhando** um em cima do outro. Além disso, a pilhas são comumnete chamadas de estruturas LIFO, pois o último elemento a entrar na pilha será o primeiro a sair.

> LIFO: Last-In, First-Out


### Aplicações da Estrutura do tipo Pilha

- Parser de expressões aritméticas: conversão e avaliação de expresões;
- Controle da sequência de chamada de funções;
- Processamento de linguagens;
- Verificar se um código fonte está bem estruturado;
- Recursividade;   
Entre outras...
 
--- 

<br>

## Definição das estrututras de dados

`Definição da estrutura do tipo nó e seu respectivo ponteiro`
```C
typedef struct no{
    int info;
    struct no *prox;
}TNo;
typedef TNo *PNo;
```

`Definição da estrutura do tipo pilha e seu respectivo ponteiro`
```C
typedef struct pilha{
    struct no *topo;
}TPilha;
typedef TPilha *PPilha;
```

<br>

## Operações básicas

`Função para inicializar uma nova pilha, alocando espaço de memória e indicando o topo como vazio:`
```C
PPilha inicializa(){
    PPilha nova = (PPilha)malloc(sizeof(TPilha)); //Aloca dinamicamente espaço de memória para uma nova pilha

    //Verifica se a alocação de memória foi bem-sucedida
    if(nova == NULL){
        printf("Erro: falha ao alocar espaço de memória para uma nova pilha.\n");
        return NULL;
    }

    nova->topo = NULL; //O topo da pilha é vazio

    return nova; 
}
```

`Função para empilhar um novo elemento na pilha:`
```C
void push(PPilha pilha, int dado){
    PNo novo = (PNo)malloc(sizeof(TNo));//Alco dinamicamente espaço de memória para um novo nó

    //Verifica se a alocação de memória foi bem-sucedida
    if(novo == NULL){
        printf("Erro: falha ao alocar espaço de memória para um novo nó.\n");
        return;
    }

    novo->info = dado;

    //Verifica se a pilha está vazia
    if(pilha->topo == NULL){
        pilha->topo = novo; //Adiciona o novo elemento no topo da pilha
        novo->prox = NULL; // O novo elemento aponta para o vazio
    }
    //Se a pilha não estiver vazia
    else{
        novo->prox = pilha->topo; //O novo elemento da pilha aponta pro antigo topo
        pilha->topo = novo; //Atualiza o topo da pilha para o novo elemento
    }
}
```

<br>

`Função para desempilhar um elemento da pilha:`
```C
void pop(PPilha pilha, int *dado){
    //Verifica se a pilha está vazia
    if(pilha->topo == NULL){
        printf("Erro: não há elementos na pilha a serem desempilhados.\n");
        return;
    }

    PNo aux = pilha->topo; //Nó auxiliar para liberar nó removido
    *dado = aux->info; //Armazena a informação removida em um ponteiro para inteiros

    pilha-> topo = pilha->topo->prox; //Atribui o próximo elemento da pilha ao novo topo
    free(aux); //Libera o espaço de memória do nó desempilhado
}
```

<br>

`Função para listar os elementos da pilha, a partir do topo, de forma recursiva:`
```C
void listarRecursivo(PNo no){
    //Se o nó for NULL, a função retorna
    if(no == NULL)
        return;
    printf("%i ", no->info);//Imprime a informação contida no nó atual
    listarRecursivo(no->prox);
}
```

<br>

`Função para listar os elementos da pilha, a partir do topo, de forma interativa:`
```C
void listarPilha(PPilha pilha){
    PNo aux;//Nó auxiliar utilizado para percorrer a pilha

    //Percorre a pilha interativamente, a partir do nó do topo, até o último nó
    for(aux = pilha->topo; aux!=NULL; aux = aux->prox)
        printf("%i ", aux->info); //Imprime a informação contida no nó auxiliar 
}
```

<br>

`Função para liberar o espaço de memória alocado dinamicamente para os nós da pilha e para a estrutura do tipo pilha:`
```C
void libera(PPilha pilha){
    PNo aux = pilha->topo; //Inicia atribuindo ao nó auxiliar aux o topo da pilha

    //Percorre a pilha, até que o nó aux seja vazio
    while(aux!=NULL){
        PNo lixo = aux; //Armazena o nó atual em um nó auxiliar(lixo) temporário
        aux = aux->prox; //Atualiza o nó auxiliar para o próximo da pilha
        free(lixo); //Libera o nó armazenado pelo nó temporário lixo
    }

    free(pilha); //Libera o espaço de memória alocado para a estrutura do tipo pilha
}
```


## Arquivos úteis

### Implementação 
A implementação completa das estruturas com as operações básicas você encontra no diretório 4_Pilha_Encadeada no arquivo [implementacao.c](/5_Pilha_Encadeada/implementacao.c)

### Algoritmos e soluções
Para fixar a utilização de pilhas, foram resolvidos alguns problemas usuais, em que a utilização de pilhas é mais frequente. Os algortimos criados estão listados abaixo, ou também podem ser encontrados seguindo o caminho 4_Pilha_Encadeada -> [algortimos](/4_Pilha_Encadeada/exercicios)
- [Notação Polonesa](/4_Pilha_Encadeada/exercicios/notacao_polonesa.c)
- 