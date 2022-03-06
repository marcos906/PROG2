/*
    @Titulo: p2_e1c.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Maneja las funciones definidas en map.c
    @Fecha: 05/03/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "map.h"
#include "stack_fDoble.h"
#include <time.h>
#include <limits.h>

#define MAX_RANDOM 10

Stack *stack_order(Stack *sin, int (*f_cmp)(const void *, const void *)){
    Stack *s;
    void *e, *ea;
    s = stack_init ();
    if ( s == NULL)
        return NULL;
    while (stack_isEmpty (sin) == FALSE){
        e = stack_pop (sin);
        if( e == NULL)
            return s;
        while (stack_isEmpty (s) == FALSE && f_cmp(e, stack_top (s)) < 0){
            ea = stack_pop (s);
            if( ea == NULL)
                return s;
            if (stack_push (sin, ea) == ERROR)
                return s;
        }
        if (stack_push (s, e) == ERROR)
            return s;
    }
    

    return s;
}

int int_cmp(const void *c1, const void *c2) {
    if (!c1 || !c2)
    return INT_MIN;
    return (*(int *)c1 - *(int *)c2);
}

int int_print (FILE *pf, const void *a) {
    if (!pf || !a) return -1;
    return fprintf(pf, "%d", *(int *)a);
}













int main(int argc, char **argv){
    if(argc < 2)
    {
        printf("Sintaxis: ./P1e3 [número]\n");
        return -1;
    }
    int argumento = atoi(argv[1]);
    int i, numero[MAX_RANDOM];

    Stack *s, *f;
    s = stack_init();
    if (s == NULL)
        return 1;

    for(i=0;i< argumento;i++){
        numero[i] = rand() % MAX_RANDOM;
        fprintf(stdout, "Entero %d: %d\n", i+1, numero[i]);
        if (stack_push(s, &numero[i]) == ERROR){
            stack_free(s);
            return 1;
        }
    }

    fprintf(stdout, "Original stack: \n");
    if(stack_print(stdout, s, int_print) < 0){
        stack_free(s);
        return 1;
    }

    f = stack_init();
    if (f == NULL){
        stack_free(s);
        return 1;
    }
    f = stack_order(s, int_cmp);
    fprintf(stdout, "Ordered stack: \n");
    if(stack_print(stdout, f, int_print) < 0){
        stack_free(s);
        stack_free(f);
        return 1;
    }

    fprintf(stdout, "Original stack: \n");
    if(stack_print(stdout, s, int_print) < 0){
        stack_free(s);
        return 1;
    }

    stack_free(s);
    stack_free(f);
    return 0;

}