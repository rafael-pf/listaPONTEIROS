#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    int qtd;
    int preco;
} produto;


int main(){
    produto **p=NULL, **pAux=NULL;
    char comando[50];
    int tam=0, i=0, j=0, remove=0;
    produto auxTroca;

    do{
        scanf(" %s", comando);
        pAux=p;
        if(strcmp(comando, "NEW")==0){
            p = (produto **) realloc(pAux, (tam+1)*sizeof(produto *));
            if(p==NULL){
                printf("Problema de alocacao");
                for(i=0; i<tam; i++){
                    free(p[i]);
                }
                free(p);
                exit(1);
            }
            p[tam] = (produto *) malloc(1*sizeof(produto)); 
            scanf("%d %d %d", &p[tam]->id, &p[tam]->qtd, &p[tam]->preco);
            tam++;

            for(i=0; i<tam; i++){
                for(j=0; j<tam; j++){
                    auxTroca = *p[i];
                    *p[i] = *p[tam-1];
                    *p[tam-1] = auxTroca;
                }
            }

        }

        else if(strcmp(comando, "RM")==0){
            scanf("%d", &remove);
            for(i=0; i<tam; i++){
                if(remove==p[i]->id){
                    auxTroca = *p[i];
                    *p[i] = *p[tam-1];
                    *p[tam-1] = auxTroca;
                }
            }
            tam--;
        }
        
    } while(strcmp(comando, "END")!=0);

    
    for(i=0; i<tam; i++){
        printf("\t%d. ID: %d - QTD: %d - PRECO: %d\n", i+1, p[i]->id, p[i]->qtd, p[i]->preco);
    }
    

    return 0;
}
