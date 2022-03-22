/*
    @Titulo: point.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Define cada una de las funciones nombradas en point.h
    @Fecha: 8/02/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "point.h"
#include "sorted_queue.h"
#include "utilities.h"

int main(){
    SortedQueue *qEnteros, *qPoint, *qChars;

    qEnteros = squeue_new();
    if(!qEnteros)
        return -1;
    
    qPoint = squeue_new();
    if(!qPoint)
        return -1;
    
    qChars = squeue_new();
    if(!qChars)
        return -1;
    if(squeue_push(qEnteros, NULL, int_cmp) == ERROR) //Comprobamos la correcta funcionalidad con NULL en squeue_push
        printf("Has metido un número que apunta a NULL\n");



    return 0;
}