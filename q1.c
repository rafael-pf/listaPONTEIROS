#include <stdio.h>

int main(){
    char c;
    char *pc;

    c='a';
    pc = &c;

    printf("a)\n");
    printf("\t%p\n", &c);
    printf("\t%c\n", c);
    printf("b)\n");
    printf("\t%p\n", pc);
    printf("\t%c\n", *pc);
    printf("c)\n");
    printf("\t%p\n", &pc);
    printf("d)\n");
    printf("\t%p\n", &*pc);
    printf("\t%p\n", *&pc);
    printf("\t\tO 1o eh o endereco para o qual o ponteiro aponta (endereco de c) e o 2o eh o conteudo do ponteiro (conteudo do end de memoria que ele esta).\n");
    printf("\t\tEles sao iguais porque o conteudo do end de memoria do ponteiro eh o end de memoria que ele aponta, que no caso eh o end de da variavel c.\n");

    //oiiiiiiii


    return 0;
}
