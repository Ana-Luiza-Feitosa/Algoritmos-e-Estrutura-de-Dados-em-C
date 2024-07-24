#include <stdio.h>
#include <stdlib.h>


typedef struct lista_circular{
    int info;
    struct lista *prox;
}TLista_C;
typedef TLista_C *PLista_C;

PLista_C cria_lista(){
    return NULL;
}

/*
 Função para inserir um novo elemento no início da fila, ou seja, antes do primeiro elemento que foi inserido ou após o último elemento.
 @param ultimo: ponteiro para estrutura do tipo lista ciruclar, que referencia o endereço de ememória do último elemento da lista.
 @param dado: informação que será armazenada no novo nó, do tipo inteiro
 return novo/ultimo: retorna o último nó da lista.
*/
PLista_C insereInicio(PLista_C ultimo, int dado){
    PLista_C novo = (PLista_C)malloc(sizeof(TLista_C)); //Aloca espaço de memória para um novo nó
    novo->info = dado;
    if(ultimo == NULL){
        novo -> prox = novo; //Lista com um único elemento
        return novo; //Retorna o último nó, que é o único elemento da lista
    }
    //Adiciona o novo nó no início da fila
    novo -> prox = ultimo -> prox; //O novo nó aponta para o antigo início da lista circular
    ultimo -> prox = novo; // atualiza o início da fila, fazendo com que o último nó aponte para o novo nó

    return ultimo; //Retorna o último elemento da lista, que permaneceu inalterado
}


/*
 Função para procurar um elemento na lista. A função retorna apenas se o elemento existe ou não na lista, ignorando informações duplicadas.
 @param ultimo: ponteiro para a estrutura do tipo lista circular, que referencia o endereço de memória do último elemento da lista.
 @param info: iformação que será buscada na lista circular, do tipo inteiro.

*/
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

/*
 Função que remove o primeiro nó que contenha o elemento passado como parâmetro.
 @param ultimo: ponteiro para a estrutura do tipo lista circular, que referencia o endereço de memória do último elemento da lista.
 @param info: variável do tipo inteiro, que indica o valor contido no nó que será removido.
 return ultimo: retorna o último elemento da lista ou a lista vazia (caso o único elemento tenha sido removido ou se não houverem elementos na lista).
*/
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
        if (ultimo->prox == ultimo) { // Se há apenas um nó na lista
            free(ultimo); //Libera o espaço de meória do único elemento
            return NULL; //Retorna a lista vazia
        } else {
            ant->prox = ultimo->prox; //Atualiza o poteiro do nó anterior ao último, apontando para o primeiro
            free(ultimo); //Libera o espaço de memória do elemento removido
            ultimo = ant;
        }
    }
    return ultimo; //Retorna o último elemento da lista circular
}