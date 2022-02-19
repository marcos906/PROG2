
/*
    @Titulo: p1_e1.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Maneja las funciones definidas en point.c
    @Fecha: 10/02/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "point.h"
#define MAX 4
int main(){
    int i;
    Point *p[MAX];
    if(point_new (0, 0, BARRIER) == NULL || point_new (0, 1, BARRIER) == NULL)
        return 1;
    p[0] = point_new (0, 0, BARRIER);
    p[1] = point_new (0, 1, BARRIER);
        if(point_print (stdout, p[0])!=-1 && point_print (stdout, p[1])!=-1)
            fprintf(stdout, "\n");
        if(point_equal (p[0], p[1])==FALSE)
            fprintf(stdout, "Equal points p[0] and p[1]? No\n");
        else
            fprintf(stdout, "Equal points p[0] and p[1]? Yes\n");
    if(point_hardcpy(p[0]) == NULL)
        return 1;
    p[2] = point_hardcpy(p[0]);
    fprintf(stdout, "Creating p[2]: ");
        if(point_print (stdout, p[2])!=-1)
            fprintf(stdout, "\n");
        if(point_equal (p[0], p[2])!=-1)
            fprintf(stdout, "Equal points p[0] and p[2]? No\n");
        else
            fprintf(stdout, "Equal points p[0] and p[2]? Yes\n");
        if(point_setSymbol (p[2], SPACE)== OK){
            fprintf(stdout, "Modifying p[2]:");
            if(point_print (stdout, p[2])!=-1)
                fprintf(stdout, "\n");
            if(point_equal (p[0], p[2])==FALSE)
                fprintf(stdout, "Equal points p[0] and p[2]? No\n");
            else
                fprintf(stdout, "Equal points p[0] and p[2]? Yes\n");
        }
    p[3]=p[0];
    fprintf(stdout, "Assign p[3] = p[0]\n");
        if(point_setSymbol (p[3], OUTPUT)== OK && point_setCoordinateY(p[3], 0)==OK){
            fprintf(stdout, "Modifying p[3]:");
            if(point_print (stdout, p[3])!=-1)
                fprintf(stdout, "\n");
            if(point_print (stdout, p[0])!=-1 && point_print (stdout, p[1])!=-1 && point_print (stdout, p[2])!=-1 && point_print (stdout, p[3])!=-1){
                printf("\nEl programa se ha ejecutado correctamente\n");
                return 0;
            }
        }
        
    for(i=0;i<MAX;i++){
        point_free (p[i]);
    }
    

}


