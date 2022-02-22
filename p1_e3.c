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
    Point *output, *neighboor, *esquina_inferior;
    int auxiliar, i;
    mp = map_readFromFile (argv);
    if(map_print (stdout, mp) == -1)
        return 1;
    int x = map_getNcols(mp);
    int y = map_getNrows(mp);
    esquina_inferior = point_new (x, y, BARRIER);
    output = map_getOutput(mp);
    if(output == NULL)
        return 1;
    esquina_inferior = map_getPoint(mp, esquina_inferior);
    fprintf(stdout, "Maze: \n");
    auxiliar = map_print (stdout, mp);
    fprintf(stdout, "\nGet output neighboors:\n");
    for(i=0;i<4;i++){
        if(map_getNeighboor(mp, output, i) == NULL)
                return 1;
            neighboor = map_getNeighboor(mp, output, i);
            auxiliar = point_print(stdout, neighboor);
    }
    fprintf(stdout, "\nGet right inferior corner neighboors:\n");
    for(i=0;i<4;i++){
        if(map_getNeighboor(mp, esquina_inferior, i) == NULL)
                return 1;
            neighboor = map_getNeighboor(mp, esquina_inferior, i);
            auxiliar = point_print(stdout, neighboor);
    }
    
}
