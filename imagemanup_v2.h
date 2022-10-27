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

typedef struct Image{
    int **pixels;
    int size;
} Image;

Image __constImage(int);
void generatePixels(Image *);
void saveImage(Image);
void drawImage();
int getRandIntiger();

Image __constImage(int imageSize){
    Image image;
    image.size = imageSize;
    image.pixels = malloc(sizeof(int) * imageSize);
    for (int x = 0; x < image.size; x++)
    {
        image.pixels[x] = calloc(image.size, sizeof(int));
    }

    return image;
}

void generatePixels(Image *image)
{
    time_t seconds;
    srand(time(&seconds));

    for (int y = 0; y < image->size; y++)
    {
        for (int x = 0; x < image->size; x++)
        {
            image->pixels[y][x] = getRandIntiger();
        }
    }

    saveImage(*image);
}

void saveImage(Image image)
{
    FILE *filePtr = openFile(IMG_FILE_NAME, "wt");

    for (int y = 0; y < image.size; y++)
    {
        for (int x = 0; x < image.size; x++)
            fprintf(filePtr, "%d\t", image.pixels[y][x]); // fprintf(filePtr, "%d,%d,%d\n", y, x,image[y][x]);
        if (y < image.size - 1)
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