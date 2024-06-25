/*O código a seguir implementa a conversão de expressões infixas pra pósfixas, utilizando a estrutura de pilha encadeada.*/

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estrutura do tipo pilha*/
typedef struct pilha{
    char caractere;
    struct pilha *prox;
}TPilha;
/*Ponteiro para a estrutura do tipo pilha*/
typedef TPilha *PPilha;

/*Função para inciar uma nova pilha*/
PPilha inicializa_pilha(){
    return NULL;
}

/*Função para alocar espaço de memória para um novo nó.*/
PPilha inicializa_no(){
    PPilha novo_no = (PPilha)malloc(sizeof(TPilha)); //ALoca dinamicamente espaço de memória para o nó
    
    /*Verifica se a alocação de meória foi bem-sucedida*/
    if(novo_no == NULL){
        printf("Erro ao alocar espaço de memória para um novo nó da pilha.\n");
        return NULL;
    }
    return novo_no; //Retorna o novo nó
}

/*Função para adicionar um nobo nó na pilha.
 * @param topo: ponteiro para a estrutura do tipo pilha, que referencia o topo da pilha.
 * @param elemento_infix: informação que será adicionada ao novo nó, do tipo char.
 */
PPilha push(PPilha topo, char elemento_infix){
    PPilha novo = inicializa_no(); //Aloca espaço de memória, através da função inicaliza_no()

    novo->caractere = elemento_infix; //Atribui a informação passada como parâmentro ao nó
    novo->prox = topo; //Atualiza o topo da pilha, atribuindo o ponteiro para o próximo elemento do novo nó ao topo

    return novo; //Retorna o novo topo da pilha
}

/*Função para desempilhar o topo da pilha.
 * @param topo: ponteiro para a estrutura do tipo pilha, que referencia o topo da pilha.
 * @param elemento_infix: ponteiro do tipo char para guardar o elemento retirado da pilha
 */
PPilha pop(PPilha topo, char *elemento_posfix){
    if(topo == NULL)return NULL; //Verifica se a pilha está vazia

    PPilha aux = topo;//Ponteiro para auxiliar na remoção do elemento do topo da pilha

    *elemento_posfix = topo->caractere; //Guarda o elemento a ser removido em um ponteiro para char

    topo = aux->prox; //Atualiza o novo topo da pilha
    free(aux); //Libera o espaço de meória alocado para o nó removido
    return topo; //Retorna o novo topo
}

/* Função para liberar o espaço de memória alocado para a pilha.
 * @param pilha: ponteiro para a estrutura do tipo pilha, que terá memória desalocada.
 */
void liberar(PPilha pilha){
    PPilha lixo = pilha; //Ponteiro auxiliar para estrutura do tipo pilha 

    /*Percorre a pilha*/
    while(pilha!=NULL){
        pilha = pilha->prox; //Atualiza o topo da pilha para não perder referência
        free(lixo); //Libera espaço de memória alocado para o nó guardado em lixo
        lixo = pilha; // Atualiza o ponteiro auxiliar para o próximo elemento da lsita
    }
}


/*Função para converter uma expressão matemática de infixa para pósfixa*/
char *converter(char *infix){
    int j=0; 
    char value;
    int n = strlen(infix);
    
    char *posfix = (char*)malloc((n+1)*sizeof(char));
    if(posfix == NULL){
        printf("Er4o ao alocar memória para a expressão pósfixa.\n");
        return NULL;
    }

    PPilha pilha = inicializa_pilha();

    for(int i=0; infix[i]!='\0';i++){
        switch(infix[i]){
            case '(':
                pilha = push(pilha, '(');
                break;
            case ')':
                while(pilha!=NULL && pilha->caractere!='('){
                    pilha = pop(pilha, &value);
                    posfix[j++] = value;
                }
                if (pilha != NULL)// Remove o '(' da pilha
                    pilha = pop(pilha, &value);
                break;
            case '*':
            case '/':
                while (pilha != NULL && (pilha->caractere == '*' || pilha->caractere == '/')){
                    pilha = pop(pilha, &value);
                    posfix[j++] = value;
                }
                pilha = push(pilha, infix[i]);
                break;
            case '+':
            case '-':
                while(pilha!=NULL && (pilha->caractere == '*' || pilha->caractere == '/' || pilha->caractere == '+' || pilha->caractere == '-')){
                    pilha = pop(pilha, &value);
                    posfix[j++] = value;
                }
                pilha = push(pilha, infix[i]);
                break;
            default:
                if(infix[i]!=' ')
                    posfix[j++] = infix[i];
                
        }
    }

    liberar(pilha);

    return posfix;
}

int main(){
    char infix[] = "(A+B*(C-D*(E-F)-G*H)-I*3)"; //Expressão infixa
    char *posfix = converter(infix); 
    
    printf("Expressão pósfixa: %s\n", posfix);
    free(posfix);
    return 0;
}