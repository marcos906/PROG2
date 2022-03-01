/*
    @Titulo: p1_e3.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Maneja las funciones definidas en map.c
    @Fecha: 22/02/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "map.h"

int main(int argc, char **argv){
    Map *mp;
    Point *output, *neighboor, *esquina_inferior, *holder;
    FILE *file;
    int auxiliar, i;

    if(argc < 2)
    {
        printf("Sintaxis: ./P1e3 [file]\n");
        return -1;
    }
    file = fopen(argv[1], "r");
    mp = map_readFromFile (file);
    int x = map_getNcols(mp);
    int y = map_getNrows(mp);
    holder = point_new (x -1, y -1, BARRIER);
    if(!holder) 
    {   
        fclose(file);
        map_free(mp);
        return -2;
    }

    output = map_getOutput(mp);
    if(output == NULL){
        fclose(file);
        map_free(mp);
        return 1;
    }

    esquina_inferior = map_getPoint(mp, holder);
    point_free(holder);
    fprintf(stdout, "Maze: \n");
    auxiliar = map_print (stdout, mp);
    fprintf(stdout, "\nGet output neighboors:\n");
    for(i=0;i<4;i++){
    
        neighboor = map_getNeighboor(mp, output, i);
        auxiliar = point_print(stdout, neighboor);
    }
    fprintf(stdout, "\nGet right inferior corner neighboors:\n");
    for(i=0;i<4;i++){
    
        neighboor = map_getNeighboor(mp, esquina_inferior, i);
        auxiliar = point_print(stdout, neighboor);
    }
    fprintf(stdout, "\n");
    map_free(mp);
    fclose(file);
    return auxiliar;
}
