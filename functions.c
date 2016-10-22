#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // <3
#include <ctype.h>
#include <windows.h>
#include "functions.h"

void loading()
{
    system("cls");
    printf("* ");
    Sleep(500);
    printf("* ");
    Sleep(500);
    printf("* ");
    Sleep(500);
    printf("* ");
    Sleep(250);
    printf("* ");
    Sleep(100);
    printf("Carga finalizada :)\n");
    system("pause");
}

int initMovies(Movie* list, int size,int value)
{
    int result=1;
    if(list==NULL||size<1)
    {
        result=0;
        pause("Error de inicializacion");
    }
    else
    {
        int i;
        for(i=0;i<size;i++)
        {
            list[i].estado=value;
        }
    }
    return result;
}

int freeMovieIndex(Movie* list,int size,int value)
{
    int i;
    int result=-1;
    for(i=0;i<size;i++)
    {
        if(list[i].estado==value)
        {
            result=i;
            break;
        }
    }
    return result;
}

void getString (char message[],char input[])
{
    puts(message);
    fflush(stdin);
    gets(input);
}

int checkLetter(char letter[],int limit)
{
   int i=0;
   int success=1;
   int size=strlen(letter);
   if(limit<1)
   {
       pause("Error en validar letras");
       system("cls");
       success=0;
   }
   if(success)
   {
        while(letter[i] != '\0' || size==0)
        {
           if((size>limit)||((letter[i] != ' ') && (letter[i] < 'a' || letter[i] > 'z') && (letter[i] < 'A' || letter[i] > 'Z')))
            {
                success= 0;
                break;
            }
            i++;
        }
   }
   return success;
}

int checkAlphanumeric(char str[],int limit)
{
   int i=0;
   int result=1;
   int size;
   size=strlen(str);
   while(str[i] != '\0'||size==0)
   {
       if(size>limit||((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')))
        {
            result= 0;
            break;
        }
       i++;
   }
   return result;
}

void pause(char message[])
{
    system("cls");
    puts(message);
    system("pause");
    system("cls");
}

int checkNatural(char number[],int limit)
{
    int i=0;
    int success=1;
    int quantity=strlen(number);
    if(limit<1)
    {
        success=0;
        pause("Error en validar numero");
        system("cls");
    }
    if(success)
    {
        while(number[i] != '\0'|| quantity==0)
        {
            if((quantity>limit)||(number[i] < '0' || number[i] > '9'))
            {
                success= 0;
                break;
            }
            i++;
        }
    }
    return success;
}

int checkRange(int x,int from,int to)
{
    int success=1;
    if(x<from||x>to)
    {
        success=0;
    }
    return success;
}

void showMenu(char options[][100])
{
    int i = 0;
    char option[100];
    while (options[i][0] != '\0')
    {
        strcpy(option, options[i]);
        i++;
        printf("%d| %s\n", i, option);
    }
}

int menu(int* input)
{
    int result=1;

    if(input==NULL)
    {
        pause("Error en menu");
        result=0;
    }

    else
    {
        char options[11][100] = {{"Agregar Pelicula"},{"Modificar Pelicula"},{"Borrar Pelicula"},{"Generar html"},{"Salir"},{'\0'}};
        char aux[256];
        showMenu(options);
        gets(aux);

        while((!checkNatural(aux,1))||(!checkRange(atoi(aux),1,5)))
        {
            system("cls");
            if(retry("Debe ingresar un numero entre 1 y 4.","Desea reingresar?\n S/N\n")=='s')
            {
                system("cls");
                showMenu(options);
                getString("Ingrese una opcion del menu",aux);
            }
            else
            {
                system("cls");
                aux[0]='5';
                result=0;
                break;
            }
        }
        *input=atoi(aux);
    }
    return result;
}

char retry(char eMessage[],char message[])
{
    char result;
    system("cls");
    puts(eMessage);
    puts(message);
    result=getch();
    printf("\n");
    result=tolower(result);
    return result;
}

int getTitle(Movie* list,int size,int empty, char input[])
{
    int result=1;

    system("cls");
    getString("Ingrese el Titulo de la pelicula.",input);
    while(strlen(input)>50||repeatedTitle(list,size,empty,input))
    {
        system("cls");
        if(retry("El Titulo debe tener menos de 50 caracteres y no estar repetido","Desea volver a ingresar el titulo de la pelicula? S/N \n")=='s')
        {
            system("cls");
            getString("Reingrese el titulo de la pelicula \n",input);
        }
        else
        {
            result=0;
            break;
        }
    }
    return result;
}

int repeatedTitle(Movie* list,int size,int value, char input[])
{
    int i;
    int result=0;

    if(list==NULL||size<1)
    {
        pause("Error en titulo repetido");
        result=1;
    }

    else
    {
        for(i=0;i<size;i++)
        {
            if(list[i].estado==value)
            {
                continue;
            }

            if(stricmp(list[i].titulo,input)==0)
            {
                result=1;
                break;
            }
        }
    }
    return result;
}

int getGenre(Movie* list,int size, char input[])
{
    int result=1;
    if(list==NULL||size<1)
    {
        result=0;
    }
    if(result)
    {
        system("cls");
        getString("Ingrese genero de pelicula",input);

        while(!checkLetter(input,20))
        {
            if(retry("Ingrese solo letras o espacios","Desea reingresar el genero? S/N \n")=='s')
            {
                system("cls");
                getString("Reingrese genero de la pelicula",input);
            }

            else
            {
                system("cls");
                result=0;
            }
        }
    }
    return result;
}

int getLink(Movie* list,int size, char input[])
{
    int result=1;
    if(list==NULL||size<1)
    {
        result=0;
    }
    if(result)
    {
        system("cls");
        getString("Ingrese link de imagen de pelicula",input);
        while(strlen(input)>100||strlen(input)<1)
        {
            if(retry("Error al cargar el link de la imagen","Desea reingresar el link de la imagen? S/N \n")=='s')
            {
                system("cls");
                getString("Reingrese link de la imagen",input);
            }
            else
            {
                system("cls");
                result=0;
            }
        }
    }
    return result;
}

int getDuration(Movie* list,int size,int empty,int* input)
{
    int result=1;
    char aux[256];
    if(list==NULL||size<1)
    {
        result=0;
    }
    if(result)
    {
        system("cls");
        getString("Ingrese la duracion de la pelicula",aux);
        while(!checkNatural(aux,3))
        {
            system("cls");
            if(retry("Solo se permiten numeros","Desea reingresar los datos? S/N \n")=='s')
            {
                getString("Ingrese la duracion de la pelicula",aux);
            }
            else
            {
                system("cls");
                result=0;
            }
        }
        if(checkNatural(aux,3))
        *input=atoi(aux);
    }
    return result;
}

int getDescription(Movie* list,int size,int empty, char input[])
{
    int result=1;
    system("cls");
    getString("Ingrese una descripcion de la pelicula",input);
    while(repeatedDescription(list,size,empty,input)||strlen(input)>200)
    {
        system("cls");
        if(retry("La descripcion debe tener menos de 200 caracteres y no ser repetida","Desea volver a ingresar la descripcion? S/N \n")=='s')
        {
            system("cls");
            getString("Reingrese la descripcion de la pelicula \n",input);
        }
        else
        {
            result=0;
            break;
        }
    }
    return result;
}

int repeatedDescription(Movie* list,int size,int value, char input[])
{
    int i;
    int result=0;

    if(list==NULL||size<1)
    {
        pause("Error titulo repetido");
        result=1;
    }

    else
    {
        for(i=0;i<size;i++)
        {
            if(list[i].estado==value)
            {
                continue;
            }

            if(stricmp(list[i].descripcion,input)==0)
            {
                result=1;
                break;
            }
        }
    }
    return result;
}

int getRating(Movie* list, int size, int* input)
{
    int result=1;
    char aux[256];

    if(list==NULL||size<1)
    {
        result=0;
    }

    if(result)
    {
        system("cls");
        getString("Ingrese el puntaje de la pelicula ",aux);

        while(!checkNatural(aux,2)||!checkRange(atoi(aux),1,10))
        {
            system("cls");
            if(retry("El puntaje debe tener numeros del 1 al 10","Desea reingresar los datos? S/N \n")=='s')
            {
                getString("Reingrese el puntaje ",aux);
            }
            else
            {
                system("cls");
                result=0;
            }
        }

        if((checkNatural(aux,2))&&(checkRange(atoi(aux),1,10)))
        *input=atoi(aux);
    }
    return result;
}

int printTitles(Movie* list, int size, int occupied)
{
    int i;
    int result=1;

    if(list==NULL||size<1)
    {
        result=0;
    }

    if(result)
    {
        for(i=0;i<size;i++)
        {
            if(list[i].estado==occupied)
            {
                printf("%d| Titulo : %s\n",list[i].id,list[i].titulo);
            }
        }
    }
    return result;
}

int generateID(Movie* list,int size)
{
    int i,j;
    int result=1;

    if(list==NULL||size<1)
    {
        result=0;
    }

    else
    {
        for(i=0,j=1;i<size;i++)
        {
            if(list[i].estado==1)
            {
                list[i].id=j;
                j++;
            }
        }
    }
    return result;
}

int addMovie(Movie* list, int size)
{
    int result=1;
    Movie auxMovie;
    int index;

    if(list==NULL||size<1)
    {
        result=0;
    }

    if(result)
    {
        index=freeMovieIndex(list,size,0);
        if(index==-1)
        {
            printf("Todos los espacios estan ocupados.\n");
            result=0;
        }
    }

    if(result)
    {
        if(!getTitle(list,size,0,auxMovie.titulo))
        result=0;
    }

    if(result)
    {
        if(!getGenre(list,size,auxMovie.genero))
            result=0;
    }

    if(result)
    {
        if(!getDescription(list,size,0,auxMovie.descripcion))
            result=0;
    }

    if(result)
    {
        if(!getLink(list,size,auxMovie.linkImagen))
            result=0;
    }

    if(result)
    {
        if(!getDuration(list,size,0,&auxMovie.duracion))
            result=0;
    }

    if(result)
    {
        if(!getRating(list,size,&auxMovie.puntaje))
            result=0;
        else
        {
            strcpy(list[index].descripcion,auxMovie.descripcion);
            strcpy(list[index].titulo,auxMovie.titulo);
            strcpy(list[index].genero,auxMovie.genero);
            strcpy(list[index].linkImagen,auxMovie.linkImagen);
            list[index].duracion=auxMovie.duracion;
            list[index].puntaje=auxMovie.puntaje;
            list[index].estado=1;
        }
    }
    return result;
}

int eraseMovie(Movie* list, int size)
{
    int result=1;
    int index;

    if(list==NULL||size<1)
    {
        pause("Error baja De Pelicula");
        result=0;
    }

    if(result)
    {
        index=freeMovieIndex(list,size,1);

        if(index==-1)
        {
            pause("Todavia no se ingreso ninguna pelicula.");
            result=0;
        }
    }

    if(result)
    {
        generateID(list,size);
        index=getIdMovie(list,size);
        if(index==-1)  result=0;
    }

    if(result)
    {
        printf("Desea eliminar: %s ?",list[index].titulo);
        if(retry("Esta seguro?","S/N")=='s')
        {
            list[index].estado=0;
        }

        else
        {
            puts("Accion cancelada");
            result=0;
        }
    }

    return result;
}

int browseIndex(Movie* list, int size, int id)
{
    int i;
    int result;

    if(list==NULL||size<1)
    {
        pause("Error en buscar indice");
        result=-1;
    }

    else
    {
        result=-1;

        for(i=0;i<size;i++)
        {
            if(list[i].estado==0)
                continue;

            if(list[i].id==id)
            {
                result=i;
            }
        }
    }
    return result;
}

int getIdMovie(Movie* list, int size)
{
    char aux[256];

    if(list==NULL||size<1)
    {
        pause("Error en obtenerId");
    }

    else
    {
        printTitles(list,size,1);
        getString("Ingrese el ID de la pelicula ",aux);

        while(!checkNatural(aux,10)||(browseIndex(list,size,atoi(aux))==-1))
        {
            if(retry("Debe ingresar un numero que pertenezca a la lista","Desesa reingresar? S/N")=='s')
            {
                printTitles(list,size,1);
                getString("Reingrese el ID",aux);
            }
            else
            {
                break;
            }
        }
    }
    return browseIndex(list,size,atoi(aux));
}

int modifyMovie(Movie* list, int size)
{
    int result=1;
    int indice;
    Movie auxMovie;

    if(list==NULL||size<1)
    {
        puts("Error en modificar pelicula");
        result=0;
    }

    if(result)
    {
        indice=freeMovieIndex(list,size,1);
        if(indice==-1)
        {
            pause("No hay ninguna pelicula agregada");
            result=0;
        }
    }

    if(result)
    {
        generateID(list,size);
        indice=getIdMovie(list,size);
        if(indice==-1)  result=0;
    }

    if(result)
    {
        printf("Desea modificar: %s ?",list[indice].titulo);
        if(retry("Esta seguro de modificar?","S/N")=='s')
        {
                    if(!getTitle(list,size,0,auxMovie.titulo))
                    result=0;

                    if(result)
                    {
                        if(!getGenre(list,size,auxMovie.genero))
                            result=0;
                    }

                    if(result)
                    {
                        if(!getDescription(list,size,0,auxMovie.descripcion))
                            result=0;
                    }

                    if(result)
                    {
                        if(!getDuration(list,size,0,&auxMovie.duracion))
                            result=0;
                    }

                    if(result)
                    {
                        if(!getLink(list,size,auxMovie.linkImagen))
                            result=0;
                    }

                    if(result)
                    {
                        if(!getRating(list,size,&auxMovie.puntaje))
                            {result=0;}

                        else
                        {
                            strcpy(list[indice].descripcion,auxMovie.descripcion);
                            strcpy(list[indice].titulo,auxMovie.titulo);
                            strcpy(list[indice].genero,auxMovie.genero);
                            strcpy(list[indice].linkImagen,auxMovie.linkImagen);
                            list[indice].duracion=auxMovie.duracion;
                            list[indice].puntaje=auxMovie.puntaje;
                        }
                    }
        }
        else
        {
            puts("Accion cancelada");
            result=0;
        }
    }
    return result;
}

void generateHTML(Movie list[],int size)
{
    FILE* file;
    int i;
        file=fopen("./webpage.html","wb");
        fprintf(file,"<!DOCTYPE html>\n<html>\n<head>\n<title>TP3</title>\n</head>\n<body><article class='col-md-4 article-intro'>");
        for(i=0;i<size;i++)
        {
            if(list[i].estado!=1)
            {
                continue;
            }
            fprintf(file,"<a href='#'><h3>%s</h3></a>",list[i].titulo);
            fprintf(file," <img class='img-responsive img-rounded' src=' %s 'alt=''>",list[i].linkImagen);
            fprintf(file,"<ul><li>Genero:%s</li>",list[i].genero);
            fprintf(file,"<li>Puntaje:%d</li>",list[i].puntaje);
            fprintf(file,"<li>Duracion:%d minutos</li></ul>",list[i].duracion);
            fprintf(file,"<p>%s</p>",list[i].descripcion);
        }
        fprintf(file,"</article></body></html>");
        fclose(file);
}

int loadMovies(Movie* list, int size)
{
	FILE* file;
	int i=0, result=0;
	file = fopen("./movies.dat", "rb");

	if(file==NULL)
    {
		printf("\n No existe el archivo %s.\n\n","./movies.dat");
		system("pause");
		result=-1;
		exit(1);
	}

    if (result != -1)
    {
        while(!feof(file))
        {
            fread(&list[i], sizeof(Movie), 1, file);
            i++;
        }
        fclose(file);
    }
	return result;
}

int saveData(Movie* movie, int size)
{
	FILE* file;
	int i;
	file = fopen("./movies.dat", "wb");

	if(file==NULL)
    {
		printf("\n No se pudo guardar el archivo %s.\n\n", "./movies.dat");
		system("pause");
		exit(1);
		return 0;
	}

	for(i=0;i<size;i++)
    {
        if(movie[i].estado==1)
        {
            fwrite(&movie[i], sizeof(Movie), 1, file);
        }
    }

    fclose(file);
	return 1;
}
