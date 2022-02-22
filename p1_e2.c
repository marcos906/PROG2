/*
    @Titulo: p1_e2.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Maneja las funciones definidas en map.c
    @Fecha: 20/02/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "map.h"

int main(){
    Map *nuevo;
    Point *input, *output, *puntos, *neighboor;
    int i, j, aux;
    if(point_new (1, 1, INPUT) == NULL || point_new (1, 2, OUTPUT) == NULL)
        return 1;
    input = point_new (1, 1, INPUT);
    output = point_new (1, 2, OUTPUT);
    int filas = 3;
    int columnas = 4;
    if(map_new (filas, columnas) == NULL)
        return 1;
    nuevo = map_new (filas, columnas);
    for(i=0;i<columnas;i++){
        for(j=0;j<filas;j++){
            if(point_new (i, j, BARRIER) == NULL)
                return 1;
            puntos = point_new (i, j, BARRIER);
            puntos = map_insertPoint(nuevo, puntos);
        }
    }
    if(map_setInput(nuevo, input) == OK && map_setOutput(nuevo, output)==OK)
        fprintf(stdout, "Map:\n");
    if(map_print (stdout, nuevo) != -1){
        fprintf(stdout, "\nGet output neighboors:\n");
        for(i=0;i<4;i++){
            if(map_getNeighboor(nuevo, output, i) == NULL)
                return 1;
            neighboor = map_getNeighboor(nuevo, output, i);
            aux = point_print(stdout, neighboor);
        }
    }
    map_free (nuevo);
    return aux;
}