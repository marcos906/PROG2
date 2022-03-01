/*
    @Titulo: p2_e1a.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Maneja las funciones definidas en map.c
    @Fecha: 01/03/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "map.h"

int main(int argc, char **argv){
    int argumento = atoi(argv[1]);
    int i;
    Point **p;
    *p = (Point**)malloc(argumento*sizeof(Point*));
    if(*p == NULL)
        return 1;
    if(argc < 2)
    {
        printf("Sintaxis: ./P1e3 [número]\n");
        return -1;
    }
    Point *compare;
    double distance;

    compare = point_new(0, 0, BARRIER);
    if(compare == NULL)
        return 1;
    for(i=0;i< argumento;i++){
        fprintf(stdout, "Point p[%d]=", i);
        p[i] = point_new(rand() % 101, rand() % 101, BARRIER);
        if(p[i] == NULL){
            return 1;
        }
        point_print(stdout, p[i]);

        if(point_euDistance(p[i], compare, &distance)== ERROR){
            point_free(compare);
            return 1;
        }
        fprintf(stdout, "distance: %lf", distance);
    }
}