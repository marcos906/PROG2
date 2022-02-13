
/*
    @Titulo: p1_e1.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Maneja las funciones definidas en point.c
    @Fecha: 10/02/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "point.h"
int main(){
    Point *p[4];
    p[0] = point_new (0, 0, BARRIER);
    p[1] = point_new (0, 1, BARRIER);
    FILE *pf;
    pf=fopen("e1.txt", "r");
        if(pf==NULL){
            printf("Error al abrir el archivo");
            return 1;
        }
        if(point_print (pf, p[0])==3 && point_print (pf, p[1])==3)
            fprintf(pf, "/n");
        if(point_equal (p[0], p[1])==FALSE)
            fprintf(pf, "Equal points p[0] and p[1]? No");
        else
            fprintf(pf, "Equal points p[0] and p[1]? Yes");
    p[2] = point_hardcpy(p[0]);
    fprintf(pf, "Creating p[2]: ");
        if(point_print (pf, p[2])==3)
            fprintf(pf, "/n");
        if(point_equal (p[0], p[2])==FALSE)
            fprintf(pf, "Equal points p[0] and p[2]? No");
        else
            fprintf(pf, "Equal points p[0] and p[2]? Yes");
        if(point_setSymbol (p[2], SPACE)== OK){
            if(point_equal (p[0], p[2])==FALSE)
            fprintf(pf, "Equal points p[0] and p[2]? No");
            else
            fprintf(pf, "Equal points p[0] and p[2]? Yes");
        }
    p[3]=p[1];
    fprintf(pf, "Assign p[3] = p[0]");
        if(point_setSymbol (p[3], OUTPUT)== OK)
            if(point_print (pf, p[0])==3 || point_print (pf, p[1])==3 || point_print (pf, p[2])==3 || point_print (pf, p[3])==3){
                printf("El programa se ha ejecutado correctamente");
                return 0;
            }
        
    point_free (p[0]);
    point_free (p[1]);
    point_free (p[2]);
    point_free (p[3]);

}


