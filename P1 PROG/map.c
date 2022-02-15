#include <stdio.h>
#include "point.h"
#include "map.h"

#define MAX_NCOLS 64 // Maximum map cols
#define MAX_NROWS 64 // Maximum map rows
#define MAX_BUFFER 64 // Maximum file line size

struct _Map {
    unsigned int nrows, ncols;
    Point *array[MAX_NROWS][MAX_NCOLS]; // array with the Map points
    Point *input, *output; // points input/output
};

struct _Point {
    int x, y;
    char symbol;
    Bool visited; // for DFS
};

Map * map_new (unsigned int nrows,  unsigned int ncols){
    Map *mapNew;
    int i,j;
    mapNew = (Map*)malloc(sizeof(Map)); //Alocamos memoria para el mapa
    if(mapNew == NULL)
        return NULL; //Control de errores

    mapNew->ncols = ncols; //Metemos la informacion que nos mandan a la nueva estructura map
    mapNew->nrows = nrows;
    
    mapNew->input = 0;
    mapNew->output = 0; //Inicializamos a 0
    
    for(i=0; i < MAX_NROWS; i++){
        for(j=0; j < MAX_NCOLS; j++)
            mapNew->array[i][j]= 0; //A 0 todos los puntos del mapa
    }

    return mapNew;

}

void map_free (Map * m){
    int i, j;
    for(i=0; i < MAX_NROWS; i++){
        for(j=0; j < MAX_NCOLS; j++)
            free(m->array[i][j]); // Liberas todos los puntos del mapa
    }
}

Point *map_insertPoint (Map *mp, Point *p){
    
    if (mp == NULL || p == NULL)
        return NULL;  //Control errores
    mp->input->x = p->x; //Pones el punto (Coordenada x) en el mapa
    mp->input->y = p->y; //Pones el punto (Coordenada y) en el mapa

    return p; //Returneas el punto dado
}

int map_getNcols (const Map *mp){
    if (mp == NULL)
        return -1;  //Control errores
    return mp->ncols; //Returneas el numero de columnas 
}

int map_getNrows (const Map *mp){
    if (mp == NULL)
        return -1;  //Control errores
    return mp->nrows; //Returneas el numero de filas
}

Point * map_getInput(const Map *mp){
    Point *point;
    if (mp == NULL)
        return NULL;  //Control errores
    point->x = mp->input->x; //coordenada x del input asociada al punto
    point->y = mp->input->y; //coordenada y del input asociada al punto

    return point; //Returneas el punto con las coordenadas del imput
}

Point * map_getOutput (const Map *mp){
    Point *punto;
    if (mp == NULL)
        return NULL;  //Control errores
    punto->x = mp->output->x; //coordenada x del output asociada al punto
    punto->y = mp->output->y; //coordenada y del output asociada al punto

    return punto; //Returneas el punto con las coordenadas del output
}
Point *map_getPoint (const Map *mp, const Point *p){
    if (mp == NULL || p == NULL)
        return NULL;  //Control errores

    p->x = mp->input->x; //Coges el punto (Coordenada x) en el mapa
    p->y = mp->input->y; //Coges el punto (Coordenada y) en el mapa

    return p; //Returneas el punto dado
}

Point *map_getNeighboor(const Map *mp, const Point *p, Position pos){
    Point *pointNeighboor;

    if (mp == NULL || p == NULL)
        return NULL;  //Control errores

    //Ascociamos las coordenadas dependiendo
    if(pos == 0){
        pointNeighboor->x = p->x + 1;
        pointNeighboor->y = p->y;
    }
    else if(pos == 1){
        pointNeighboor->x = p->x;
        pointNeighboor->y = p->y - 1;
    }
    else if(pos == 2){
        pointNeighboor->x = p->x - 1;
        pointNeighboor->y = p->y;
    }
    else{
        pointNeighboor->x = p->x;
        pointNeighboor->y = p->y + 1;
    }

    return pointNeighboor; //Returneamos el punto vecino

}

Map * map_readFromFile (FILE *pf){
    
}