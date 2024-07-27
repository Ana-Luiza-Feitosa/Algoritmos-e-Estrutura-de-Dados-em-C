/*Um grupo de soldados está rodeado por forças inimigas e não há chance
de vitória sem a chegada de reforço. Como existe apenas um cavalo, os
soldados entram num acordo para decidir quem irá fugir com o cavalo para
tentar trazer ajuda. Eles formam um círculo e sorteiam num chapéu um
número n e um nome. Começando pelo soldado cujo nome foi sorteado, é
começado a contagem no sentido horário e quando esta contagem atingir o
número n, este soldado é retirado do círculo. A contagem reinicia com o
soldado seguinte ao que foi retirado e, novamente, quanto esta contagem
atingir o número n, este outro soldado é retirado do círculo, recomeçando a
contagem com o soldado seguinte, e assim por diante até que só reste um
soldado no círculo. Este é o que deverá fugir no cavalo e buscar ajudar.
Faça um programa que simule a formação dos soldados neste círculo
(inclusão dos soldados no círculo) e a saída dos soldados na forma
explicada até restar apenas um. Considere n e nome inicial do soldado pelo
qual a contagem deve iniciar como fornecidos pelo usuário (para facilitar,
considere que o usuário sempre entrará com um nome existente).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct soldado{
    char nome[50];
    struct soldado *prox;
}TSoldado;

typedef TSoldado *PSoldado;

PSoldado inicializa_circulo(){
    return NULL;
}

//Inserção no início
PSoldado insere_soldado(PSoldado ultimo_soldado, char nome[]){
    PSoldado novo = (PSoldado)malloc(sizeof(TSoldado));

    for(int i=0;i<strlen(nome);i++)
        novo->nome[i] = nome[i];

    novo->nome[strlen(novo->nome)-1] = '\0';

    if(ultimo_soldado == NULL){
        novo->prox = novo;
        return novo;
    }

    novo ->prox = ultimo_soldado->prox;
    ultimo_soldado ->prox = novo;
    return ultimo_soldado;
}

PSoldado busca_e_remove(PSoldado ultimo_soldado, int n_sorteado, char nome[]){
    //Verifica se o circulo não está vazio
    if(ultimo_soldado == NULL){
        printf("O circulo está vazio.\n");
        return NULL;
    }

    PSoldado auxiliar,anterior;
    int verifica_nome = 0; 

    for(auxiliar = ultimo_soldado->prox; auxiliar != ultimo_soldado; auxiliar = auxiliar->prox){
        anterior = auxiliar;
        if(strcmp(nome, auxiliar->nome) == 0)
            break;
            
    }
    if(strcmp(nome, ultimo_soldado->nome) == 0)
        auxiliar = ultimo_soldado;
    
    //Verifica se achou mesmo o nome desejado
    if(strcmp(auxiliar->nome, nome)!=0){
        printf("Nome não encontrado.\n");
        return ultimo_soldado;
    }


    for(int i=0;i<n_sorteado;i++){
        anterior = auxiliar;
        auxiliar = auxiliar->prox;
    }

   //Se no circulo restar apenas um soldado 
    if(auxiliar == auxiliar->prox){
        free(auxiliar);
        return NULL;
    }
    else{
        if(anterior == ultimo_soldado){
            anterior->prox = ultimo_soldado->prox;
            free(ultimo_soldado);
            return anterior;
        }
        else{
            anterior->prox = auxiliar->prox;
            free(auxiliar);
            return ultimo_soldado;
        }
    }
}

int contar_soldados(PSoldado ultimo_soldado){
    if(ultimo_soldado == NULL)
        return 0;
    int contador = 1;
    PSoldado auxiliar;
    for(auxiliar = ultimo_soldado; auxiliar!=ultimo_soldado; auxiliar= auxiliar->prox)
        contador++;
    
    return contador;
}

void liberar_memoria(PSoldado ultimo_soldado){
    if(ultimo_soldado == NULL)
        return;

    PSoldado auxiliar,temporario;
    for(auxiliar = ultimo_soldado->prox; auxiliar!= ultimo_soldado; auxiliar = auxiliar->prox){
        temporario = auxiliar;
        free(temporario);
    }
    free(ultimo_soldado);
}

void Menu(){
    printf("\n\nO que deseja executar:\n");
    printf("(1) - Inserir soldado\n(2) - Remover soldado\n(3) - Exibir numero de soldados restantes.\n");
}



int main(){
    PSoldado circulo = inicializa_circulo();
    int opcao, exit = 0, n;
    char name[50];

    while(exit == 0){
        Menu();
        scanf("%i",&opcao);
        getchar();
        switch(opcao){
            case 1:
                printf("\nDigite o primeiro nome do soldado:");
                fgets(name, sizeof(name),stdin);
                name[strlen(name)-1]='\0';
                insere_soldado(circulo, name);
            case 2:
                printf("\nDigite o primeiro nome do soldado:");
                fgets(name, sizeof(name),stdin);
                name[strlen(name)-1]='\0';
                printf("\nInsira um número desejado:");
                scanf("%i",&n);
                busca_e_remove(circulo, n, name);
                n = contar_soldados(circulo);
                if(n < 2)
                    exit = 1;
            case 3:
                n = contar_soldados(circulo);
                printf("Ainda há %i soldados.\n",n);
            default:
                printf("ERRO\n");

        }
    }

}