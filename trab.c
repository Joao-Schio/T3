#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Docente: João Pedro Schio Ortega - RGA 2021.1905.022-5
   Discente: Francisco Eloi Soares de Araujo */




// Estrutura pedida no trabalho
typedef struct{
    int codigo;
    int validade;
}REG;


// Estrutura para a lista de registros
typedef struct lista{
    REG reg;
    struct lista *prox;
    struct lista *ant;
}cel;


// função para trocar dois registros, mas manter a ordem da lista
void troca (REG *a, REG*b){
    REG aux = *a;
    *a = *b;
    *b = aux;
}

// Sort por codigo
void selection (cel *lst, int *n){
    cel *i, *j, *min;
    for (i = lst; i->prox != NULL; i = i->prox){
        min = i;
        for (j = i->prox; j != NULL; j = j->prox){
            if (j->reg.codigo < min->reg.codigo){
                min = j;
            }
        }
        troca(&i->reg, &min->reg);
        *n = *n + 1;
    }
}

// sort por validade
void insertion (cel *lst, int *n){
    cel *i, *j;
    for (i = lst; i->prox != NULL; i = i->prox){
        for (j = i->prox; j != NULL; j = j->prox){
            if (i -> reg.validade > j -> reg.validade){
                troca(&i->reg, &j->reg);
                *n = *n + 1;
            }
        }
    }
}





int main(void){
    
    cel *lista,*p;
    // decidi fazer o uso de listas duplamente encadeadas, pois é uma estrutura onde eu não preciso saber
    // o tamanho da lista,portanto esse código irá rodar para qualquer tamanho de entrada.
    p = lista = (cel*)malloc(sizeof(cel));
    p -> ant = NULL;
    p -> prox = NULL;



    // variaveis auxiliares
    REG aux;
    FILE *entrada = fopen("produtos.ent","r");
    int TrocasS = 0;
    int TrocasI = 0;

    


    while(fscanf(entrada,"%d %d",&aux.codigo,&aux.validade) != EOF){
        p -> prox = (cel*)malloc(sizeof(cel));
        p -> prox -> ant = p;
        p = p -> prox;
        p -> reg = aux;
        p -> prox = NULL;
    }
    fclose(entrada);





    selection(lista, &TrocasS);
    insertion(lista, &TrocasI);

    for (p = lista -> prox ; p != NULL; p = p->prox){
        printf("%d %d\n",p->reg.codigo,p->reg.validade);
    }
    printf("Trocas S = %d Trocas I = %d\n",TrocasS,TrocasI);


    return 0;

}