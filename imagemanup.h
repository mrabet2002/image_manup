#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "drawchart.h"
#include "ColorLevel.h"

#define IMG_SIZE 1000
#define IMG_FILE_NAME "image-matrix.csv"

int image[IMG_SIZE][IMG_SIZE];


void generateImage();
void saveImage();
void drawImage();
int getRandIntiger();


void generateImage()
{
    time_t seconds;
    srand(time(&seconds));
    for (int y = 0; y < IMG_SIZE; y++)
    {
        for (int x = 0; x < IMG_SIZE; x++)
        {
            image[y][x] = getRandIntiger();
        }
    }
}

void drawImage()
{
    Data data;
    data.src = IMG_FILE_NAME;
    data.separator = "\t";
    printf("in00");
    Chart chart = __constChart("Monochrome Image", NULL, NULL, "image", "grey", NULL, data);
    drawChart(chart);
}

void saveImage()
{
    FILE *filePtr = openFile(IMG_FILE_NAME, "wt");

    for (int y = 0; y < IMG_SIZE; y++)
    {
        for (int x = 0; x < IMG_SIZE; x++)
            fprintf(filePtr, "%d\t", image[y][x]); // fprintf(filePtr, "%d,%d,%d\n", y, x,image[y][x]);
        if (y < IMG_SIZE - 1)
            fprintf(filePtr, "\n");
    }

    fclose(filePtr);
}

int getRandIntiger()
{
    return (int)((255 * rand()) % 256);
}