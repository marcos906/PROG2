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
    getImput = (Point*)malloc(sizeof(Point)); //Alocamos memoria para el punto
    if (mp == NULL || getImput == NULL)
        return NULL;  //Control errores

    int x = point_getCoordinateX(mp->input);//coordenada x del input 
    int y = point_getCoordinateY(mp->input); //coordenada y del input 
    char symbol = point_getSymbol (mp->input); //coge el simbolo del imput
    getImput = point_new (x, y, symbol);
    return getImput;  //Returneas el punto con las coordenadas del imput
}

Point * map_getOutput (const Map *mp){
    Point *getOutput;
    getOutput = (Point*)malloc(sizeof(Point)); //Alocamos memoria para el punto
    if (mp == NULL || getOutput == NULL)
        return NULL;  //Control errores

    int x = point_getCoordinateX(mp->output);//coordenada x del output 
    int y = point_getCoordinateY(mp->output); //coordenada y del output 
    char symbol = point_getSymbol (mp->output); //coge el simbolo del output
    getOutput = point_new (x, y, symbol);
    return getOutput;  //Returneas el punto con las coordenadas del output
}
Point *map_getPoint (const Map *mp, const Point *p){
    Point *mapPoint;
    if (mp == NULL || p == NULL || mapPoint == NULL)
        return NULL;  //Control errores
    int x = point_getCoordinateX(mp->array[0]);
    int y = point_getCoordinateY(p);
    mp->array[y][x] = mapPoint;

    return p; //Returneas el punto dado
}
    p->x = mp->input->x; //Coges el punto (Coordenada x) en el mapa
    p->y = mp->input->y; //Coges el punto (Coordenada y) en el mapa

    return p; //Returneas el punto dado
}

Point *map_getNeighboor(const Map *mp, const Point *p, Position pos){
    Point *neighboor;
    neighboor = (Point*)malloc(sizeof(Point));
    if (mp == NULL || p == NULL || neighboor == NULL)
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
        y = y + 1;
        neighboor = point_new (x, y, symbol);
    }
    else if(pos == 2){
        x = x - 1;
        neighboor = point_new (x, y, symbol);
    }
    else if(poss == 3){
        y = y - 1;
        neighboor = point_new (x, y, symbol);
    }
    else
        neighboor = point_new (x, y, symbol);

    return neighboor; //Returneamos el punto vecino

}
Status map_setInput(Map *mp, Point *p){
    if (mp == NULL || p == NULL)
        return ERROR; // Control de errores
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    char symbol = point_getSymbol(p);
    point_setCoordinateX(mp->imput)= x;
    point_setCoordinateY(mp->imput) = y;
    point_setSymbol(mp->imput) = symbol; 
    return OK;
}
Status map_setOutput (Map *mp, Point *p){
    if (mp == NULL || p == NULL)
        return ERROR; // Control de errores
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    char symbol = point_getSymbol(p);
    point_setCoordinateX(mp->output)= x;
    point_setCoordinateY(mp->output) = y;
    point_setSymbol(mp->output) = symbol; 
    return OK;
}
Map * map_readFromFile (FILE *pf){

}