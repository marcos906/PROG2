/*
    @Titulo: p2_e1b.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Maneja las funciones definidas en map.c
    @Fecha: 03/03/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "map.h"
#include "stack_fDoble.h"
#include <time.h>

Stack *stack_orderPoints (Stack *sin){
    Stack *s;
    Point *e, *ea;
    s = stack_init ();
    if ( s == NULL)
        return NULL;
    while (stack_isEmpty (sin) == FALSE){
        e = stack_pop (sin);
        if( e == NULL)
            return s;
        while (stack_isEmpty (s) == FALSE && point_cmpEuDistance (e, stack_top (s)) == -1){
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













int main(int argc, char **argv){
    if(argc < 2)
    {
        printf("Sintaxis: ./P1e3 [número]\n");
        return -1;
    }
    int argumento = atoi(argv[1]);
    int i;

    Stack *s, *f;
    s = stack_init();
    if (s == NULL)
        return 1;

    Point *p[argumento];
    Point *compare;

    double distance;
    compare = point_new(0, 0, BARRIER);
    if(compare == NULL)
        return 1;
    for(i=0;i< argumento;i++){
        fprintf(stdout, "Point p[%d]=", i);
        p[i] = point_new(rand() % 11, rand() % 11, BARRIER);
        if(p[i] == NULL){
            point_free(compare);
            return 1;
        }
        if(point_print(stdout, p[i]) != -1){
            point_free(compare);
            return 1;
        }

        if(point_euDistance(p[i], compare, &distance)== ERROR){
            point_free(compare);
            return 1;
        }
        fprintf(stdout, " distance: %lf\n", distance);
        if (stack_push(s, p[i]) == ERROR){
            stack_free(s);
            return 1;
        }
    }

    point_free(compare);
    fprintf(stdout, "Original stack: \n");
    if(stack_print(stdout, s, point_print) < 0){
        stack_free(s);
        return 1;
    }

    f = stack_init();
    if (f == NULL){
        stack_free(s);
        return 1;
    }
    f = stack_orderPoints(s);
    fprintf(stdout, "Ordered stack: \n");
    if(stack_print(stdout, f, point_print) < 0){
        stack_free(s);
        stack_free(f);
        return 1;
    }

    fprintf(stdout, "Original tack: \n");
    if(stack_print(stdout, s, point_print) < 0){
        stack_free(s);
        return 1;
    }

    stack_free(s);
    stack_free(f);
    return 0;

}