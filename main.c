#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // perdon. por el getche.
#include <ctype.h>
#include "functions.h"
#define QTY_MOVIES 5

int main()
{
    char cont='s';
    int option=0;
    Movie movies[QTY_MOVIES];
    initMovies(movies,QTY_MOVIES,0);
    loadMovies(movies,QTY_MOVIES);
    while(cont=='s')
    {
        system("cls");
        menu(&option);
        switch(option)
        {
            case 1:
                if(addMovie(movies,QTY_MOVIES))
                {
                    system("cls");
                    puts("Pelicula cargada exitosamente");
                }
                break;
            case 2:
                system("cls");
                modifyMovie(movies,QTY_MOVIES);
                break;
            case 3:
                system("cls");
                if(eraseMovie(movies,QTY_MOVIES)==1)
                {
                    system("cls");
                    puts("Pelicula eliminada exitosamente");
                }
               break;
            case 4:
                saveData(movies, QTY_MOVIES);
                generateHTML(movies,QTY_MOVIES);
                loading();
                break;
            case 5:
                cont = 'n';
                break;
        }
    }
    return 0;
}
