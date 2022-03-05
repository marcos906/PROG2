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
    Stack *s0;
    s0 = stack_init ();
    while (stack_isEmpty (s) = FALSE){
        e = stack_pop (s);
        while (stack_isEmpty (s0) = FALSE && e < stack_top (s0)){
            ea = stack_pop (s0);
            stack_push (s, ea);
        }
        stack_push (s0, e);
    }
    return s0;
}













int main(int argc, char **argv){
    if(argc < 2)
    {
        printf("Sintaxis: ./P1e3 [número]\n");
        return -1;
    }
    int argumento = atoi(argv[1]);
    int i, j;

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
            return 1;
        }
        point_print(stdout, p[i]);

        if(point_euDistance(p[i], compare, &distance)== ERROR){
            point_free(compare);
            return 1;
        }
        fprintf(stdout, " distance: %lf\n", distance);

    }

    point_free(compare);


}