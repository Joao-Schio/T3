#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Aluno: João Pedro Schio Ortega - RGA 2021.1905.022-5
   discente: Francisco Eloi Soares de Araujo */





typedef struct{
    int codigo;
    int validade;
}REG;



typedef struct lista{
    REG reg;
    struct lista *prox;
    struct lista *ant;
}cel;



void troca (REG *a, REG*b){
    REG aux = *a;
    *a = *b;
    *b = aux;
}


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
    p = lista = (cel*)malloc(sizeof(cel));
    p -> ant = NULL;
    p -> prox = NULL;
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

    selection(lista, &TrocasS);
    insertion(lista, &TrocasI);

    for (p = lista -> prox ; p != NULL; p = p->prox){
        printf("%d %d\n",p->reg.codigo,p->reg.validade);
    }
    printf("Trocas S = %d Trocas I = %d\n",TrocasS,TrocasI);


    return 0;

}