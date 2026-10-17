/* In this programs if you are using fscanf it will directly read the data from the file into the array,
on the other hand if we are using sscanf, that particular movies record, which includes name, year, rating language
all that is stored as a single string within double quotes but the individual things like name, year and all are 
seperated by commas, now this line's job [ie.%99[^,],%49[^,],%d,%f], is to break it down into the individual elements,
when a comma is encountered stop and then move to next element....THIS IS HOW sscanf and fscanf work.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    char language[50];
    int year;
    float rating;

} Movie;

/* Function Prototypes */

int countMovies(char filename[]);
Movie* allocateMemory(int count);
void readMovies(char filename[], Movie *movies, int count);
void getSearchMovieName(char searchName[]);
void removeNewLine(char str[]);
int linearSearch(Movie *movies, int count, char searchName[]);
void displayMovie(Movie *movies, int position);
void freeMemory(Movie **movies);

/* Main Function */

int main()
{
    char filename[] = "sorted_movies.csv";
    int count, position;
    char searchName[100];
    Movie *movies;

    count = countMovies(filename);
    if (count <= 0)
    {
        return 0;
    }

    movies = allocateMemory(count); // why use this line we are just counting movies right?
    if (movies == NULL) // in above line specify the data type also which is Movie*
    {
        return 0;
    }

    readMovies(filename, movies, count);

    getSearchMovieName(searchName);

    position = linearSearch(movies, count, searchName);

    displayMovie(movies, position);

    freeMemory(&movies);

    return 0;
}

/* Function Definitions */

int countMovies(char filename[])
{
    FILE *fp;
    char line[300];
    int count = 0;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 0;
    }

    fgets(line, sizeof(line), fp); //skipping header

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        count++;
    }

    fclose(fp);
    return count;
}

Movie* allocateMemory(int count)
{
    Movie *movies;

    movies = (Movie *)malloc(count * sizeof(Movie));

    if (movies == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    return movies;
}

void readMovies(char filename[], Movie *movies, int count) // reading movies from file to array.
{
    FILE *fp;
    char line[300];
    int i = 0;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    fgets(line, sizeof(line), fp);

    while (i < count && fgets(line, sizeof(line), fp) != NULL)
    {
        removeNewLine(line);// this line is optional

        sscanf(line, "%99[^,],%49[^,],%d,%f", // if you are using fscanf then include space before %99(imp)
               movies[i].name,
               movies[i].language,
               &movies[i].year,
               &movies[i].rating);

        i++;
    }

    fclose(fp);
}

void getSearchMovieName(char searchName[]) // 4.
{
    printf("Enter movie name to search: ");
    fgets(searchName, 100, stdin);
    removeNewLine(searchName);// this has to be there for sure.
}

void removeNewLine(char str[])// we do not call this function in main-->remember (JUST USED IN getsearch...)
{
    str[strcspn(str, "\n")] = '\0';  /*Inside the brackets do not use '\n' instead of "\n" as strcspn needs a string
    not a char and also do not use "\0" instead of '\0'  because the "" quotes represent string.*/
}

int linearSearch(Movie *movies, int count, char searchName[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(movies[i].name, searchName) == 0)
        {
            return i;
        }
    }

    return -1; // this line is very imp do not write return 0 here.
}

void displayMovie(Movie *movies, int position)
{
    if (position == -1)
    {
        printf("\nMovie not found\n");
    }
    else
    {
        printf("\nMovie found at index %d in array and row %d in the file\n\n", position, position + 2);// for printing row why position+2?
        printf("Movie Name : %s\n", movies[position].name);
        printf("Language   : %s\n", movies[position].language);
        printf("Year       : %d\n", movies[position].year);
        printf("Rating     : %.1f\n", movies[position].rating);
    }
}

void freeMemory(Movie **movies)
{
    free(*movies);
    *movies = NULL;
}