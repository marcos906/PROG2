/*
    @Titulo: stack_fDoble.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Define cada una de las funciones nombradas en stack_fDoble..h
    @Fecha: 21/03/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "stack_fDoble.h"

#define INIT_CAPACITY 2 // init stack capacity
#define FCT_CAPACITY 2 // multiply the stack capacity
struct _Stack {
    void **item; /*!<Dynamic array of elements*/
    int top; /*!<index of the top element in the stack*/
    int capacity; /*!<xcapacity of the stack*/
};

/*
--------------------------------------------------------
Funciones privadas 
--------------------------------------------------------
*/
Bool isFull( Stack *stc){
    if(stc == NULL)
        return FALSE;
    
    if(stc->capacity == stc->top)
        return TRUE;

    return FALSE;
}

Status increaseCapacity (Stack *stc){
    if(stc == NULL)
        return ERROR;
    stc->capacity = stc->capacity + FCT_CAPACITY;
    *stc->item = (Stack*)realloc(stc->item, stc->capacity*sizeof(Stack));

    if(stc->item == NULL)
        return ERROR;
    
    return OK;
}



Stack * stack_init (){
    Stack *s;

    int i;

    s = (Stack*)malloc(sizeof(Stack));

    if( s == NULL)
        return NULL;

    s->capacity = INIT_CAPACITY;

    s->top = -1;

    *s->item = (Stack*)malloc(s->capacity*sizeof(Stack));

    if(s->item == NULL)
        return NULL;

    for (i = 0; i < s->capacity; i++) {
        s->item[i] = NULL;
    }

    return s;

}


void stack_free (Stack *s){
    if(s == NULL)
        return;
    if(stack_isEmpty(s) == FALSE)
        return;
    free(s);
}


Status stack_push (Stack *s, const void *ele){
    if(s == NULL || ele == NULL)
        return ERROR;
    if (isFull(s) == FALSE)
    {
        s->item[s->top +1] = ele;
        s->top++;
    }
    else{
        if(increaseCapacity(s) == OK){
            s->item[s->top +1] = ele;
            s->top++; 
        }
        else
            return ERROR;
    }
    return OK;
    
}


void * stack_pop (Stack *s){
    if(s == NULL)
        return NULL;
    
    void *e;
    if(stack_isEmpty(s) == TRUE)
        return NULL;
    else{
        e = s->item[s->top];
        if(e == NULL)
            return NULL;
        s->item[s->top] = NULL;
        s->top--;
    }
    return e;
}



void * stack_top (const Stack *s){
    if(s == NULL)
        return NULL;
    void *e;
    if(stack_isEmpty(s) == TRUE)
        return NULL;
    else{
        e = s->item[s->top];
        if(e == NULL)
            return NULL;

    }
    return e;
    
}


Bool stack_isEmpty (const Stack *s){
    if(s == NULL)
        return FALSE;
    if(s->item[s->top] == NULL)
        return TRUE;
    return FALSE;
}


size_t stack_size (const Stack *s){
    if(s == NULL)
        return -1;
    
    return s->capacity;
}


int stack_print(FILE* fp, const Stack *s,  P_stack_ele_print f){
    if(fp == NULL || s == NULL)
        return -1;
    int i, res;
    size_t size;
    size = stack_size(s);
    if(size == -1)
        return -1;
    fprintf(fp, "SIZE: %ld\n", size);
    for(i = 0; i < s->capacity; i++){
        res = f(fp, s->item[i]);
    }
    return res;
}