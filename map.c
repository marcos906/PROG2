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

    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    mp->array[y][x] = p;

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
    Point *getImput;
    if (mp == NULL)
        return NULL;  //Control errores

    int x = point_getCoordinateX(mp->input);//coordenada x del input 
    int y = point_getCoordinateY(mp->input); //coordenada y del input 
    char symbol = point_getSymbol (mp->input); //coge el simbolo del imput
    getImput = point_new (x, y, symbol);
    return getImput;  //Returneas el punto con las coordenadas del imput
}

Point * map_getOutput (const Map *mp){
    Point *getOutput;
    if (mp == NULL)
        return NULL;  //Control errores

    int x = point_getCoordinateX(mp->output);//coordenada x del output 
    int y = point_getCoordinateY(mp->output); //coordenada y del output 
    char symbol = point_getSymbol (mp->output); //coge el simbolo del output
    getOutput = point_new (x, y, symbol);
    return getOutput;  //Returneas el punto con las coordenadas del output
}
Point *map_getPoint (const Map *mp, const Point *p){
    Point *mapPoint;
    if (mp == NULL || p == NULL)
        return NULL;  //Control errores
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    mapPoint = mp->array[y][x];

    return mapPoint; //Returneas el punto dado
}

Point *map_getNeighboor(const Map *mp, const Point *p, Position pos){
    Point *neighboor;
    if (mp == NULL || p == NULL)
        return NULL;  //Control errores
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    char symbol = point_getSymbol(p);
    //Ascociamos las coordenadas dependiendo
    if(pos == 0){
        x = x + 1;
        neighboor = point_new (x, y, symbol);
    }
    else if(pos == 1){
        y = y - 1;
        neighboor = point_new (x, y, symbol);
    }
    else if(pos == 2){
        x = x - 1;
        neighboor = point_new (x, y, symbol);
    }
    else if(pos == 3){
        y = y + 1;
        neighboor = point_new (x, y, symbol);
    }
    else{
        neighboor = point_new (x, y, symbol);
    }
    return neighboor; //Returneamos el punto vecino
}
Status map_setInput(Map *mp, Point *p){
    if (mp == NULL || p == NULL)
        return ERROR; // Control de errores
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    if (point_setCoordinateX(mp->input, x)==OK || point_setCoordinateY(mp->input, y)==OK || point_setSymbol(mp->input, INPUT)==OK)
        return OK;
    return ERROR;
}
Status map_setOutput (Map *mp, Point *p){
   if (mp == NULL || p == NULL)
        return ERROR; // Control de errores
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    if (point_setCoordinateX(mp->output, x)==OK || point_setCoordinateY(mp->output, y)==OK || point_setSymbol(mp->output, OUTPUT)==OK)
        return OK;
    return ERROR;
}
Map * map_readFromFile (FILE *pf){
    Map *mp;
    Point *p;
    int i, j;
    char symbol;
    mp = (Map*)malloc(sizeof(Map));
    fscanf(pf, "%d %d", mp->nrows, mp->ncols);
    for(i=0;i<mp->nrows;i++){
        for(j=0;j<mp->ncols;j++){
            fscanf(pf, "%c", &symbol);
            p = point_new (i, j, symbol);
            mp->array[j][i] = p;
        }    
    }
    return mp;
}

Bool map_equal (const void *_mp1, const void *_mp2){
    Map *mp1=(Map*)_mp1;
    Map *mp2=(Map*)_mp2;
    int xi1, yi1, xi2, yi2, xo1, yo1, xo2, yo2;
    if(_mp2 == NULL || _mp1 == NULL)
        return FALSE;
    if(mp1->nrows != mp2-> nrows || mp1->ncols !=mp2->nrows)
        return FALSE;
    xi1 = point_getCoordinateX(mp1->input);
    yi1 = point_getCoordinateY(mp1->input);
    xi2 = point_getCoordinateX(mp2->input);
    yi2 = point_getCoordinateY(mp2->input);
    xo1 = point_getCoordinateX(mp1->output);
    yo1 = point_getCoordinateY(mp1->output);
    xo2 = point_getCoordinateX(mp2->output);
    yo2 = point_getCoordinateY(mp2->output);
    if( xi1 != xi2 || yi1 != yi2 || xo1 != xo2 || yo1 != yo2)
        return FALSE;
    return TRUE;      
    }

int map_print (FILE*pf, Map *mp){
    int i, j, x;
    if(pf == NULL || mp == NULL)
        return -1;
    Point *input, *output;
    input = map_getInput(mp);
    output = map_getOutput(mp);
    fprintf(pf, "%d %d\n", mp->ncols, mp->nrows);
    for(i=0;i<mp->nrows;i++){
        for(j=0;j<mp->ncols;j++){
            if(i == point_getCoordinateX(input) && j == point_getCoordinateY(input))
                x = fprintf(pf, "[(%d, %d): %c] ", i, j, INPUT);
            else if (i == point_getCoordinateX(output) && j == point_getCoordinateY(output))
                x = fprintf(pf, "[(%d, %d): %c] ", i, j, OUTPUT);
            else
                x = fprintf(pf, "[(%d, %d): %c] ", i, j, BARRIER);
        }   
    }
    return x;
}