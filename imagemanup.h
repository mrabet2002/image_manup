#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ColorLevel.h"

#ifndef DRAWCHART_H_INCLUDED
    #define DRAWCHART_H_INCLUDED
    #include "drawchart.h"
#endif

#define IMG_FILE_NAME "image-matrix.csv"

int **generateImage(int **, int);
void saveImage(int **, int);
void drawImage();
int getRandIntiger();

int **generateImage(int **image, int imgSize)
{
    image = malloc(sizeof(int *) * imgSize);
    for (int x = 0; x < imgSize; x++)
    {
        image[x] = calloc(imgSize, sizeof(int));
    }

    time_t seconds;
    srand(time(&seconds));

    for (int y = 0; y < imgSize; y++)
    {
        for (int x = 0; x < imgSize; x++)
        {
            image[y][x] = getRandIntiger();
        }
    }

    saveImage(image, imgSize);

    return image;
}

void saveImage(int **image, int imgSize)
{
    FILE *filePtr = openFile(IMG_FILE_NAME, "wt");

    for (int y = 0; y < imgSize; y++)
    {
        for (int x = 0; x < imgSize; x++)
            fprintf(filePtr, "%d\t", image[y][x]); // fprintf(filePtr, "%d,%d,%d\n", y, x,image[y][x]);
        if (y < imgSize - 1)
            fprintf(filePtr, "\n");
    }

    fclose(filePtr);
}

void drawImage()
{
    Data data;
    data.src = IMG_FILE_NAME;
    data.separator = "\t";
    Chart chart = __constChart("Monochrome Image", NULL, NULL, "image", "grey", NULL, data);
    drawChart(chart);
}

int getRandIntiger()
{
    return (int)((255 * rand()) % 256);
}