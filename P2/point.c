
/*
    @Titulo: point.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Define cada una de las funciones nombradas en point.h
    @Fecha: 8/02/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/


#include "point.h"
#include <limits.h> 
struct _Point {
    int x, y;
    char symbol;
    Bool visited; // for DFS
};
Point *point_new (int x, int y, char symbol){
    Point *a;
    a = (Point*)malloc(sizeof(Point));
    if(a == NULL){
        return NULL;
    }
    a->x=x;
    a->y=y;
    a->symbol=symbol;
    return a;
}

void point_free (Point *p){
    free(p);
}

int point_getCoordinateX (const Point *p){
    if(p==NULL)
        return INT_MAX;
    else
        return p->x;
}

int point_getCoordinateY (const Point *p){
    if(p==NULL)
        return INT_MAX;
    else
        return p->y;
}

char point_getSymbol (const Point *p){
    if(p==NULL)
        return ERRORCHAR;
    else
        return p->symbol;
}
Status point_setCoordinateX (Point *p, int x){
    if(x<0){
        return ERROR;
    }
    else if(p == NULL)
        return ERROR;
    else{
        p->x=x;
        return OK;
    }
}
Status point_setCoordinateY (Point *p, int y){
    
    if(y<0)
        return ERROR;
    else if(p == NULL)
        return ERROR;
    else{
        p->y=y;
        return OK;
    }
}
Status point_setSymbol (Point *p, char c){
    if(p == NULL)
        return ERROR;
    else if(c==INPUT || c==OUTPUT || c==BARRIER || c== SPACE){
        p->symbol=c;
        return OK;
    }
    else
        return ERROR;
}
Point *point_hardcpy (const Point *src){
    if(src == NULL)
        return NULL;
    Point *trg;
    trg = point_new (src->x, src->y, src->symbol);
    if(trg == NULL)
        return NULL;
    return trg;

}

Bool point_equal (const void *p1, const void *p2){
    if(p1==NULL || p2==NULL)
        return FALSE;
    Point *_p1=(Point*)p1;
    Point *_p2=(Point*)p2;
    if(_p1->x==_p2->x && _p1->y==_p2->y && _p1->symbol==_p2->symbol)
        return TRUE;
    else
        return FALSE;  
    }

int point_print (FILE *pf, const void *p){
    if(p==NULL || pf == NULL)
        return -1;
    Point *_p=(Point*)p;
    return fprintf(pf, "[(%d, %d): %c]", _p->x, _p->y, _p->symbol);
}

Status point_euDistance (const Point *p1, const Point *p2, double *distance){

    if(p1 == NULL || p2 == NULL || distance == NULL)
        return ERROR;
    
    *distance = sqrt (((p1->x-p2->x)^2) + ((p1->y-p2->y)^2));

    return OK;
}

int point_cmpEuDistance (const void *p1, const void *p2){
    if(p1==NULL || p2==NULL)
        return INT_MIN;
    Point *_p1=(Point*)p1;
    Point *_p2=(Point*)p2;
    Point *compare;
    double distance1, distance2;

    compare = point_new(0, 0, BARRIER);
    if(compare == NULL)
        return INT_MIN;
    
    if(point_euDistance(_p1, compare, &distance1) == OK && point_euDistance(_p2, compare, &distance2) == OK){
        if(distance1 == distance2){
            point_free(compare);
            return 0;
        }
        else if(distance1 > distance2)
        {
            point_free(compare);
            return 1;
        }
        else{
            point_free(compare);
            return -1;
        }
    }
    else{
        point_free(compare);
        return INT_MIN;
    }
}

Bool point_getVisited (const Point *p){
    if( p == NULL)
        return FALSE;
    if(p->visited == TRUE)
        return TRUE;
    return FALSE;
}

Status point_setVisited (Point *p, Bool bol){
    if(p == NULL)
        return ERROR;
    p->symbol = bol;
    return OK;
}