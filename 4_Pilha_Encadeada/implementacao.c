#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}TNo;
typedef TNo *PNo;

typedef struct pilha{
    struct no *topo;
}TPilha;
typedef TPilha *PPilha;

/*
 * Função para inicializar uma nova pilha, alocando espaço de memória e indicando o topo como vazio.
 * @return nova: pilha alocada dinamicamente
*/
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

/*
 * Função para empilhar um novo elemento na pilha.
 * @param pilha: ponteiro para a estrutura do tipo pilha 
 * @param dado: informação do tipo inteiro que será armazenado na pilha
*/
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

/*
 * Função para desempilhar um elemento da pilha. O elemento retirado é sempre o último que foi inserido.
 * @param pilha: ponteiro para a estrutura de dados do tipo pilha
 * @param dado: ponteiro para inteiro, utilizado para armazenar a informação do nó removido
*/
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

/*
 * Função para listar os elementos da pilha, a partir do topo, de forma recursiva.
 * @param no: ponteiro para a estrutura do tipo nó, referente ao topo da pilha
*/
void listarRecursivo(PNo no){
    //Se o nó for NULL, a função retorna
    if(no == NULL)
        return;
    printf("%i ", no->info);//Imprime a informação contida no nó atual
    listarRecursivo(no->prox);
}



/*
 * Função para listar os elementos da pilha, a partir do topo, de forma interativa.
 * @param pilha: ponteiro para a estrutura do tipo pilha
*/
void listarPilha(PPilha pilha){
    PNo aux;//Nó auxiliar utilizado para percorrer a pilha

    //Percorre a pilha interativamente, a partir do nó do topo, até o último nó
    for(aux = pilha->topo; aux!=NULL; aux = aux->prox)
        printf("%i ", aux->info); //Imprime a informação contida no nó auxiliar 
}

/*
 * Função para liberar o espaço de memória alocado dinamicamente para os nós da pilha e para a estrutura do tipo pilha.
 * @param pilha: ponteiro para a estrutura do tipo pilha
*/
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

int main(){
    PPilha cod_livros = inicializa();

    int cod;
    printf("Digite o código do livro.\n");
    scanf("%i",&cod);
    
    push(cod_livros, cod);

    listarRecursivo(cod_livros->topo);
    libera(cod_livros);
    return 0;

}