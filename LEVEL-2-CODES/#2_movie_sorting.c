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
void displayMoviesFromFile(char filename[], int n);
void sortMovies(Movie *movies, int count);
void writeMovies(char filename[], Movie *movies, int count);
void freeMemory(Movie **movies);

/* Main Function */
int main()
{
    char inputFile[] = "IMDb_400_Movies1.csv";
    char outputFile[] = "sorted_movies.csv";

    int count = countMovies(inputFile);
    if (count <= 0)
    {
        printf("No movie records found or file error.\n");
        return 1;
    }

    Movie *movies = allocateMemory(count);
    if (movies == NULL)
    {
        return 1;
    }

    readMovies(inputFile, movies, count); // will read the movies into the memory.

    int n;
    /* PROMPT MUST MATCH EXPECTED OUTPUT EXACTLY */
    printf("Enter how many movie records to display: ");
    scanf("%d", &n);
    if (n > count)
    {
        n = count;
    }

    /* FORMAT AROUND HEADINGS MATCHES EXPECTED OUTPUT */
    printf("\nBefore Sorting:\n\n");
    displayMoviesFromFile(inputFile, n);

    sortMovies(movies, count);
    writeMovies(outputFile, movies, count);

    printf("\nAfter Sorting:\n\n");
    displayMoviesFromFile(outputFile, n);

    printf("\nSorted movie data stored successfully.\n");

    freeMemory(&movies);
    return 0;
}

/* Count number of movie records (lines after header) */
int countMovies(char filename[])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 0;
    }

    char line[300];
    int count = 0;

    /* Skip header line */
    if (fgets(line, sizeof(line), fp) == NULL) // if there is no header then no point on working on the file.
    {
        fclose(fp);
        return 0;
    }

    /* Count each remaining line */
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (line[0] != '\n' && line[0] != '\r')
            count++;
    }

    fclose(fp);
    return count;
}

/* Allocate memory for count movies */
Movie* allocateMemory(int count)
{
    Movie *movies = (Movie *)malloc(count * sizeof(Movie));
    if (movies == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return movies;
}

/* Read CSV into movies array */
void readMovies(char filename[], Movie *movies, int count) // reading it into the memory.
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    char line[300];
    int i = 0; // we are not taking int count here as we have count already passed to the functions.

    /* Skip header */
    fgets(line, sizeof(line), fp);

    /* Read each line: Name,Language,Year,Rating */
    while (i < count && fgets(line, sizeof(line), fp) != NULL)
    {
        if (line[0] == '\n' || line[0] == '\r') // to avoid reading blank lines.
            continue;

        /* Easier parsing with sscanf */
        sscanf(line, "%[^,],%[^,],%d,%f",
               movies[i].name,
               movies[i].language,
               &movies[i].year,
               &movies[i].rating);
        i++;
    }

    fclose(fp);
}

/* Display first n movies from a file */
void displayMoviesFromFile(char filename[], int n)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    char line[300];
    int count = 0; // instead of count you can just take varaible i, taking count as the name does not make any sense.


    /* Skip header */
    if (fgets(line, sizeof(line), fp) == NULL)
    {
        fclose(fp);
        return;
    }

    char name[100], language[50];
    int year;
    float rating;

    while (count < n && fgets(line, sizeof(line), fp) != NULL)
    {
        if (line[0] == '\n' || line[0] == '\r')
            continue;
 
        sscanf(line, "%[^,],%[^,],%d,%f", // extracting structure members from a long string
               name, language, &year, &rating);// we are not reading from memory here

        printf("%s | %s | %d | %.1f\n", name, language, year, rating); // displaying those members
        count++;
    }

    fclose(fp);
}

/* Bubble sort movies by name (ascending) */
void sortMovies(Movie *movies, int count)
{
    Movie temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (strcmp(movies[j].name, movies[j + 1].name) > 0)
            {
                temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

/* Write sorted movies to CSV file */
void writeMovies(char filename[], Movie *movies, int count)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Cannot create output file\n");
        return;
    }

    fprintf(fp, "Movie Name,Language,Year,Rating\n");// this is the header here so you do not have to skip anything.
    

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s,%s,%d,%.1f\n",
                movies[i].name,
                movies[i].language,
                movies[i].year,
                movies[i].rating);
    }

    fclose(fp);
}

/* Free allocated memory safely */
void freeMemory(Movie **movies)
{
    if (*movies != NULL)
    {
        free(*movies);
        *movies = NULL;
    }
}