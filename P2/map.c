#include <stdio.h>
#include "point.h"
#include "map.h"
#include "stack_fDoble.h"

#define MAX_NCOLS 64 // Maximum map cols
#define MAX_NROWS 64 // Maximum map rows
#define MAX_BUFFER 64 // Maximum file line size

struct _Map {
    unsigned int nrows, ncols;
    Point *array[MAX_NROWS][MAX_NCOLS]; // array with the Map points
    Point *input, *output; // points input/output
};

Map * map_new (unsigned int nrows,  unsigned int ncols){
    if(nrows<1 || nrows>64 || ncols<1 || ncols>64 )
        return NULL;
    Map *mapNew;
    mapNew = (Map*)malloc(sizeof(Map)); //Alocamos memoria para el mapa
    if(mapNew == NULL){
        return NULL; //Control de errores
    }
    int i,j;
    mapNew->ncols = ncols; //Metemos la informacion que nos mandan a la nueva estructura map
    mapNew->nrows = nrows;
    
    for(i=0; i < MAX_NROWS; i++){
        for(j=0; j < MAX_NCOLS; j++)
            mapNew->array[i][j]= NULL;
    }

    return mapNew;

}

void map_free (Map * m){
    if (m == NULL)
        return;
    int i, j;
    for(i=0; i < MAX_NROWS; i++){
        for(j=0; j < MAX_NCOLS; j++){
            point_free(m->array[i][j]); // Liberas todos los puntos del mapa
        }
    }
    free(m); //malloc mapa
}

Point *map_insertPoint (Map *mp, Point *p){
    if (mp == NULL || p == NULL)
        return NULL; 
    if(mp->ncols > 64 || mp->nrows >64 || mp->ncols < 0 || mp->nrows <0)//control errores de >64 y <0 
        return NULL;
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    mp->array[y][x] = p;

    return p; //Returneas el punto dado
}

int map_getNcols (const Map *mp){
    if (mp == NULL || mp->ncols > 64 || mp->nrows >64 || mp->ncols < 0 || mp->nrows <0)
        return -1;  //Control errores
    return mp->ncols; //Returneas el numero de columnas 
}

int map_getNrows (const Map *mp){
    if (mp == NULL)
        return -1;  //Control errores
    return mp->nrows; //Returneas el numero de filas
}

Point * map_getInput(const Map *mp){
    return mp->input;
}
Point * map_getOutput (const Map *mp){
    return mp->output;
}
Point *map_getPoint (const Map *mp, const Point *p){
    Point *mapPoint;
    if (mp == NULL || p == NULL)
        return NULL;  //Control errores
    if(mp->ncols >= 64 || mp->nrows >= 64 || mp->ncols < 0 || mp->nrows <0)//control errores de >64 y <0 
        return NULL;
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    mapPoint = mp->array[y][x];

    return mapPoint; //Returneas el punto dado
}

Point *map_getNeighboor(const Map *mp, const Point *p, Position pos){
    if (mp == NULL || p == NULL || pos <0|| pos>4)
        return NULL;  //Control errores
    Point *neighboor;
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
    switch (pos)
    {
    case 0:
        x = x + 1;
        break;

    case 1:
        y = y - 1;
        break;

    case 2:
        x = x - 1;
        break;

    case 3:
        y = y + 1;
        break;

    case 4:
        break;
        
    default:
        break;
    }
    neighboor = map_getPoint(mp, mp->array[y][x]);
    return neighboor; //Returneamos el punto vecino
}
Status map_setInput(Map *mp, Point *p){
    if (mp == NULL || p == NULL)
        return ERROR; // Control de errores
    mp->input = p;
    return OK;
}
Status map_setOutput (Map *mp, Point *p){
    if (mp == NULL || p == NULL)
        return ERROR; // Control de errores
    mp->output = p;
    return OK;
}

Map * map_readFromFile (FILE *pf){
    if (pf == NULL)
        return NULL;
    Map *mp;
    int i, j, x, y;
    char symbol;
    fscanf(pf, "%d %d", &x, &y);
    mp = map_new(x, y);
    getc(pf);
    for(i=0;i<mp->nrows;i++){
        for(j=0;j<mp->ncols;j++){
            fscanf(pf, "%c", &symbol);
            if(symbol == INPUT)
            {   
                mp->array[i][j] = point_new (j, i, symbol);
                map_setInput(mp, mp->array[i][j]);
            }   
            if(symbol == OUTPUT)
            {   
                mp->array[i][j] = point_new (j, i, symbol);
                map_setOutput(mp, mp->array[i][j]);   
            }
            if(symbol != INPUT && symbol != OUTPUT)
                mp->array[i][j] = point_new (j, i, symbol);
        }
        getc(pf);    
    }
    return mp;
}

Bool map_equal (const void *_mp1, const void *_mp2){
    if(_mp2 == NULL || _mp1 == NULL)
        return FALSE;
    Map *mp1=(Map*)_mp1;
    Map *mp2=(Map*)_mp2;
    int i, j;
    if(mp1->nrows != mp2-> nrows || mp1->ncols !=mp2->ncols)
        return FALSE;
    for(i=0;i<mp1->nrows;i++){
        for(j=0;j<mp1->ncols;j++){
            if(point_equal(mp1->array[i][j], mp2->array[i][j])== FALSE)
                return FALSE;
        }   
    }
    return TRUE;      
    }


int map_print (FILE*pf, Map *mp){
    int i, j, x;
    if(pf == NULL || mp == NULL)
        return -1;
    fprintf(pf, "%d %d\n", mp->nrows, mp->ncols);
    for(i=0;i<mp->nrows;i++){
        for(j=0;j<mp->ncols;j++){
            x = point_print(pf, mp->array[i][j]);
        }   
    }
    return x;
}



Point * map_dfs (Map *mp){
if (mp == NULL)
    return NULL;
Point *pi, *po, *p, *pn;
Stack *s;
int i;
p = NULL;


pi = map_getInput(mp);
if(pi == NULL){
    map_free(mp);
    return NULL;
}

po = map_getOutput(mp);
if(po == NULL){
    map_free(mp);
    return NULL;
}

s = stack_init();
if(s == NULL){
    map_free(mp);
    return NULL;
}

if(stack_push (s, pi) == ERROR){
    map_free(mp); 
    stack_free(s);
    return NULL;
}

while (po != p && stack_isEmpty (s) == FALSE){
    p =  (Point*) stack_pop (s);
    if (p == NULL){
        map_free(mp); 
        stack_free(s);
        return NULL;
    }
    
    if (point_getVisited(p) == FALSE){
       
        if(point_setVisited (p, TRUE) == ERROR){
            
            map_free(mp); 
            stack_free(s);
            return NULL;
        }
       
        for(i = 0;i<5;i++){
        
            pn = map_getNeighboor(mp, p, i);
            if(pn != NULL){
                
                if (point_getVisited (pn) == FALSE){
                    if(point_getSymbol(pn) != BARRIER){
                        if(stack_push (s, pn)== ERROR){
                            map_free(mp); 
                            stack_free(s);
                            return NULL;
                        }
                    }
                    
                }
                
            }
            
        
           
        }
        point_print(stdout, p);
       
    }
    
        
    
    
}
printf("\n");
stack_free (s);
    
if (p == po)
    return p;
return NULL;

}

