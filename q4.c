#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int tam=0, i=0;
    char string[100];
    char **p=NULL;
    char **pAux=NULL;

    printf("->Digite as palavras: \n");
    while(scanf(" %s", string)!=EOF){
        pAux = p;
        //realocar vetor dinamico de string a cada entrada
        p = (char **) realloc(pAux, (tam+1)* sizeof(char *));
        if(p==NULL){
            printf("Problema de alocacao!\n");
            for(i=0; i<tam; i++){
                free(p[i]);
            }
            free(p);
            exit(1);
        }
        //alocar o espaço para a string
        p[tam] = (char *) malloc((strlen(string)+1) * sizeof(char));
        if(p[tam]==NULL){
            printf("Problema de alocacao!\n");
            for(i=0; i<tam; i++){
                free(p[i]);
            }
            free(p);
            exit(1);
        }
        //colocar a string no vetor e aumentar o tamanho
        strcpy(p[tam++], string);
    }

    printf("->Palavras armazenadas: \n");

    //printar palavras
    for(i=0; i<tam; i++){
        printf("\t-%s\n", p[i]);
    }

    //free
    for(i=0; i<tam; i++){
        free(p[i]);
    }
    free(p);
    
    
    return 0;
}
