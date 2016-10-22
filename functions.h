#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[50];
    int estado;
    int id;
}Movie;
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int addMovie(Movie* list, int size);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int eraseMovie(Movie* list, int size);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */

void loading();

void generateHTML(Movie list[],int size);

int initMovies(Movie* list, int size, int);

int freeMovieIndex(Movie* list,int size,int );

void pause(char message[]);

void getString(char message[],char input[]);

int checkRange(int x,int from,int to);

int checkAlphanumeric(char str[],int limit);

int checkNatural(char number[],int limit);

int checkLetter(char letter[],int limit);

char retry(char eMessage[],char message[]);

int menu(int* input);

void showMenu(char options[][100]);

int getTitle(Movie* list,int size,int empty, char input[]);

int browseIndex(Movie* list, int size, int id);

int repeatedTitle(Movie* list,int size,int value, char input[]);

int getGenre(Movie* list,int size, char input[]);

int getDuration(Movie* list,int size,int empty,int* input);

int getDescription(Movie* list,int size,int empty, char input[]);

int getLink(Movie* list,int size, char input[]);

int getRating(Movie* list, int size, int* input);

int repeatedDescription(Movie* list,int size,int value, char input[]);

int printTitles(Movie* list, int size, int occupied);

int generateID(Movie* list,int size);

int getIdMovie(Movie* list, int size);

int modifyMovie(Movie* list, int size);

void leerPelicula();

int loadMovies(Movie* peli, int);

int saveData(Movie* movie, int size);
#endif // FUNCTIONS_H_INCLUDED

