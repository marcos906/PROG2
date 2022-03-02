/*
    @Titulo: p2_e1a.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Maneja las funciones definidas en map.c
    @Fecha: 01/03/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "map.h"
#include <time.h>


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

    for(i=0;i<argumento;i++){
        for(j=i; j<argumento;j++){
            fprintf(stdout, "p[%d] < p[%d]: ", i, j);
            if(point_cmpEuDistance (p[i], p[j]) == 0 || point_cmpEuDistance (p[i], p[j]) == 1)
                fprintf(stdout, "FALSE\n");
            else if(point_cmpEuDistance (p[i], p[j]) == -1)
                fprintf(stdout, "TRUE\n");
            else{
                for(i=0;i<argumento;i++){
                    point_free(p[i]);
                }
                return 1;
            }
        }
    }
    
    for(i=0;i<argumento;i++){
        point_free(p[i]);
    }
    return 0;
}