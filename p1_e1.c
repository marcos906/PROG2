
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
    p[0] = point_new (0, 0, BARRIER);
    p[1] = point_new (0, 1, BARRIER);
    FILE *pf;
    pf=fopen("e1.txt", "w");
        if(pf==NULL){
            printf("Error al abrir el archivo");
            return 1;
        }
        if(point_print (pf, p[0])==3 && point_print (pf, p[1])==3)
            fprintf(pf, "\n");
        if(point_equal (p[0], p[1])==FALSE)
            fprintf(pf, "Equal points p[0] and p[1]? No\n");
        else
            fprintf(pf, "Equal points p[0] and p[1]? Yes\n");
    p[2] = point_hardcpy(p[0]);
    fprintf(pf, "Creating p[2]: ");
        if(point_print (pf, p[2])==3)
            fprintf(pf, "\n");
        if(point_equal (p[0], p[2])==FALSE)
            fprintf(pf, "Equal points p[0] and p[2]? No\n");
        else
            fprintf(pf, "Equal points p[0] and p[2]? Yes\n");
        if(point_setSymbol (p[2], SPACE)== OK){
            fprintf(pf, "Modifying p[2]:");
            if(point_print (pf, p[2])==3)
                fprintf(pf, "\n");
            if(point_equal (p[0], p[2])==FALSE)
                fprintf(pf, "Equal points p[0] and p[2]? No\n");
            else
                fprintf(pf, "Equal points p[0] and p[2]? Yes\n");
        }
    p[3]=p[0];
    fprintf(pf, "Assign p[3] = p[0]\n");
        if(point_setSymbol (p[3], OUTPUT)== OK && point_setCoordinateY(p[3], 0)==OK){
            fprintf(pf, "Modifying p[3]:");
            if(point_print (pf, p[3])==3)
                fprintf(pf, "\n");
            if(point_print (pf, p[0])==3 && point_print (pf, p[1])==3 && point_print (pf, p[2])==3 && point_print (pf, p[3])==3){
                printf("El programa se ha ejecutado correctamente\n");
                return 0;
            }
        }
        
    for(i=0;i<MAX;i++){
        point_free (p[i]);
    }
    

}


