/*
    @Titulo: p2_e2.c
    @Autores: Hector Labrador Gomez y Samuel Heras De Paz
    @Descripcion: Maneja las funciones definidas en map.c
    @Fecha: 08/03/2022
    @Asignatura: Practicas Programacion II
    @Grupo:2132
*/

#include "map.h"


int main(int argc, char **argv){
    Map *mp;
    FILE *file;
    Point *p;
    int auxiliar;

    if(argc < 2)
    {
        printf("Sintaxis: ./P2e2 [file]\n");
        return -1;
    }
    file = fopen(argv[1], "r");
    mp = map_readFromFile (file);


    fprintf(stdout, "Maze: \n");
    auxiliar = map_print (stdout, mp);

    fprintf(stdout, "\nDFS traverse: \n");
    p = map_dfs(mp);
    if(p == NULL){
        fprintf(stdout, "ERROR");
        return 1;
    }

    return auxiliar;
}