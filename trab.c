#include <stdio.h>
#include <stdlib.h>
#include <math.h>







typedef struct{
    int codigo;
    int validade;
}REG;



typedef struct lista{
    REG reg;
    struct lista *prox;
    struct lista *ant;
}cel;







int main(void){
    
    cel *lista,*p;
    p = lista = (cel*)malloc(sizeof(cel));
    p -> ant = NULL;
    p -> prox = NULL;
    REG aux;
    FILE *entrada = fopen("produtos.ent","r");
    while(fscanf(entrada,"%d %d",&aux.codigo,&aux.validade) != EOF){
        p -> reg = aux;
        p -> prox = (cel*)malloc(sizeof(cel));
        p -> prox -> ant = p;
        p = p -> prox;
    }

    for(p = lista; p -> prox != NULL; p = p -> prox){
        printf("%d %d\n",p -> reg.codigo,p -> reg.validade);
    }




}