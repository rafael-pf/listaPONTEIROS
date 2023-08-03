#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct do produto
typedef struct{
    int id;
    int qtd;
    int preco;
} produto;


int main(){
    produto *p=NULL, *pAux=NULL;
    char comando[50];
    int tam=0, i=0, j=0, remove=0;
    produto auxTroca;

    do{
        //scanear comando(NEW/RM/END)
        scanf(" %s", comando);
        pAux=p;
        if(strcmp(comando, "NEW")==0){
            //se for NEW relloca o vetor dinamico aumentando seu tamanho em 1
            p = (produto *) realloc(pAux, (tam+1)*sizeof(produto ));
            //se apontar para NULL -> free e para o programa
            if(p==NULL){
                printf("Problema de alocacao");
                free(p);
                exit(1);
            }
            //scanear id, qtd e preco e aumentar o tamanho
            scanf("%d %d %d", &p[tam].id, &p[tam].qtd, &p[tam].preco);
            tam++;

        }

        else if(strcmp(comando, "RM")==0){
            scanf("%d", &remove);
            //procurar id a ser a removido
            for(i=0; i<tam; i++){
                //trocar este com o ultimo item e reduzir o tamanho do vetor
                if(remove==p[i].id){
                    auxTroca = p[i];
                    p[i] = p[tam-1];
                    p[tam-1] = auxTroca;
                }
            }
            tam--;
            p = (produto *) realloc(pAux, tam *sizeof(produto));
            if(p==NULL){
                printf("Problema de alocacao");
                free(p);
                exit(1);
            }
        }
        
    } while(strcmp(comando, "END")!=0);


    //ordenar os itens pelo id
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            if(p[i].id<p[j].id){
                auxTroca=p[i];
                p[i]=p[j];
                p[j]=auxTroca;
            }
        }
    }

    //imprimir
    for(i=0; i<tam; i++){
        printf("\t%d. ID: %d - QTD: %d - PRECO: %d\n", i+1, p[i].id, p[i].qtd, p[i].preco);
    }
    
    free(p);
    return 0;
}
