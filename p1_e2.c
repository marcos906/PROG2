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
    Map *nuevo;
    nuevo = map_new (filas, columnas);
    if(nuevo == NULL)
        return 1;
    Point *input, *output, *neighboor;
    int i, aux;
    input = point_new(1, 1, INPUT);
    output = point_new(2, 1, OUTPUT);
    if(input == NULL || output == NULL){
        map_free(nuevo);
        return 1;
    }
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
        if(aux == -1){
            map_free(nuevo);
            return 1;
        }
        fprintf(stdout, "\nGet output neighboors:\n");
        for(i=0;i<4;i++){
            neighboor = map_getNeighboor(nuevo, output, i);
            if(neighboor == NULL){
                map_free(nuevo);
                return 1;
            }
            aux = point_print(stdout, neighboor);
            if(aux == -1){
            map_free(nuevo);
            return 1;
            }
        }
        fprintf(stdout, "\n");
    }
    else{
        point_free(input);
        point_free(output);
        map_free(nuevo);
        return 1;
    }
    map_free (nuevo);
    return aux;
}