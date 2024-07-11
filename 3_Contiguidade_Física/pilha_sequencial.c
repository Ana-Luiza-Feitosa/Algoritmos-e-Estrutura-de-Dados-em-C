#include <stdio.h>
#include <stdlib.h>

#define MAX_PILHA 100 //Define o tamnho máximo de elementos da pilha

//Definição da estrutura do tipo pilha
typedef struct pilha{ 
  int elemento[MAX_PILHA];
  int topo;
}TPilha;
typedef TPilha *PPilha; //Ponteiro para a estrutura do tipo pilha

/*
 Função para alocar espaço de memória para uma nova pilha e iniciar o topo com -1
 @return nova: ponteiro para a estrutura do tipo pilha
*/
PPilha cria_pilha(){
  PPilha nova = (PPilha)malloc(sizeof(TPilha)); 
  nova->topo = -1;
  return nova;
}
/*
 Função pra inserir um elemento no topo da pilha.
 @param pilha: ponteiro para a estrutura do tipo pilha
 @param dado: valor que será armazenado, do tipo inteiro
 @return: retorna -1 se o elemento não foi inserido na pilha e 0 se foi inserido com sucesso.
*/
int insere_elemento(PPilha pilha, int dado){
  if(pilha == NULL) return -1;//Verifica se a pilha foi alocada corretamente
  if(pilha->topo == MAX_PILHA - 1) return -1;//Verifica se há espaço de memória disponível

  pilha->elemento[++pilha->topo] = dado; //Atualiza o topo da pilha e insere o elemento

  return 0;
}

/*
 Função para remover o elemento do topo da pilha.
 @param pilha: ponteiro para a estrutura do tipo pilha
 @param dado: ponteiro para inteiro, que armazena o elemento removido da pilha.
 @return: retorna -1 se o elemento não foi removido da pilha e 0 se foi removido com sucesso.
*/
int remove_elemento(PPilha pilha, int *dado){
  //Verifica se o espaço de memória para a estrutura do tipo pilha foi alocado corretamente.
  if(pilha == NULL) return -1;
  //Verifica se a pilha está vazia, se sim, retorna  
  if(pilha->topo == -1) return -1;
  
  *dado = pilha->elemento[pilha->topo]; //Armazena o elemento do topo da pilha em um ponteiro
  pilha->topo--; //Decrementa o topo da pilha
  return 0;
}
/*
 Função para listar os elementos armazenados na pilha.
 @param pilha: ponteiro para a estrutura do tipo pilha
 @param topo: variável inteira que indica o topo da pilha
*/
void listarRecursivo(PPilha pilha, int topo){
  if(pilha == NULL) return;//Verifica se a memória para a estrutura do tipo pilha foi alocada corretamente
  if(topo == -1) return; //Quando o topo for -1, retorna


  printf("%i ", pilha->elemento[topo]); //Imprime a informmação amrazenada no topo
  return listarRecursivo(pilha, topo - 1); //Atualiza topo para o próximo elemento da pilha
}

/*
 Função para liberar o espaço de memória armazenado para a estrutura do tipo pilha.
 @param pilha: ponteiro para a estrutura do tipo pilha.
*/
void liberar(PPilha pilha){
  free(pilha);
}

//Verificação simples das funções
int main(){
  PPilha pilha = cria_pilha();
  int x,value;
  do{
    printf("\nOpcoes:\t(0)Inserir\t(1)Remover\t(2)Listar\t(3)Sair\n\n");
    scanf("%i",&x);
    switch(x){
     case 0:
      printf("Insira um valor: ");
      scanf("%i",&value);
      insere_elemento(pilha, value);
      break;

    case 1:
        if(remove_elemento(pilha, &value) == 0)
            printf("Elemento removido: %i\n", value);
        else
            printf("Erro ao remover o elemento.\n");
      break;
    case 2:
        listarRecursivo(pilha, pilha->topo);
        break;
    case 3:
        break;
    default:
        printf("ERRO. Opção inválida.\n");
    }

  
  }while(x != 3);

  liberar(pilha);

  return 0;
}