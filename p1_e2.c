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
    int filas = 3;
    int columnas = 4;
    if(map_new (filas, columnas) == NULL){
        return 1;
    }
    Map *nuevo;
    Point *input, *output, *neighboor;
    int i, aux;
    nuevo = map_new (filas, columnas);
    input = point_new(1, 1, INPUT);
    output = point_new(2, 1, OUTPUT);
    map_insertPoint(nuevo, point_new(0, 0, BARRIER));
    map_insertPoint(nuevo, point_new(1, 0, BARRIER));
    map_insertPoint(nuevo, point_new(2, 0, BARRIER));
    map_insertPoint(nuevo, point_new(3, 0, BARRIER));
    map_insertPoint(nuevo, input);
    map_insertPoint(nuevo, point_new(0, 1, BARRIER));
    map_insertPoint(nuevo, point_new(3, 1, BARRIER));
    map_insertPoint(nuevo, output);
    map_insertPoint(nuevo, point_new(0, 2, BARRIER));
    map_insertPoint(nuevo, point_new(1, 2, BARRIER));
    map_insertPoint(nuevo, point_new(2, 2, BARRIER));
    map_insertPoint(nuevo, point_new(3, 2, BARRIER));
    if(map_setInput(nuevo, input)==OK && map_setOutput(nuevo, output)==OK){
        fprintf(stdout, "Map:\n");
        aux = map_print (stdout, nuevo);
        fprintf(stdout, "\nGet output neighboors:\n");
            for(i=0;i<4;i++){
                if(map_getNeighboor(nuevo, output, i) == NULL)
                    return 1;
                neighboor = map_getNeighboor(nuevo, output, i);
                aux = point_print(stdout, neighboor);
            }
        fprintf(stdout, "\n");
    }
    map_free (nuevo);
    return aux;
}