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
    int num4=4, num2 = 2, num1 = 1;
    qEnteros = squeue_new();
    if(!qEnteros)
        return -1;
    
    qPoint = squeue_new();
    if(!qPoint)
        return -1;
    
    qChars = squeue_new();
    if(!qChars)
        return -1;
    printf("TEST 1: que pasa si metes un número nulo en la pila\n");
    if(squeue_push(qEnteros, NULL, int_cmp) == ERROR) //Comprobamos la correcta funcionalidad con NULL en squeue_push
        printf("    Test pasado: Has metido un número que apunta a NULL y da error\n");
    else
        printf("    Test no pasado: Has metido un número que apunta a NULL y no da error\n");


    printf("TEST 2: meter un numero(4) en una cola vacia y ver que pasa\n");
    if(squeue_push(qEnteros, &num4, int_cmp) == OK){
        printf("    Test no pasado: Has metido un número en una cola vacia y se ha implementado bien\n");
    }else{
        printf("    Test pasado: Has metido un número en una cola vacia y da error");
        printf("\n    Cola: ");
        queue_print(stdout, qEnteros, int_print);
    }

    queue_push(qEnteros, &num2);
    printf("TEST 3: meter un numero(4) en una cola con un numero(2) y ver que pasa\n");
    if(squeue_push(qEnteros, &num4, int_cmp) == OK){
        printf("    Test pasado: Has metido un número en una cola y se ha implementado bien(se ha ordenado)");
        printf("\n    Cola: ");
        queue_print(stdout, qEnteros, int_print);
    }else{
        printf("    Test no pasado: Has metido un número en una cola y da error");   
    }
    printf("TEST 4: meter un numero mas pequeño(1) en una cola y ver que pasa\n");
    if(squeue_push(qEnteros, &num1, int_cmp) == OK){
        printf("    Test pasado: Has metido un número en una cola y se ha implementado bien(se ha ordenado)");
        printf("\n    Cola: ");
        queue_print(stdout, qEnteros, int_print);
    }else{
        printf("    Test no pasado: Has metido un número en una cola y da error");   
    }


    
    
    
    
    
    return 0;
}