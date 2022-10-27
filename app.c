#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include "drawchart.h"
#ifndef FMANUP_H_INCLUDED
#include "fmanup.h"
#endif

#define IMG_SIZE 1000
#define IMG_FILE_NAME "image-matrix.csv"
#define COLORS_FREQ_FILE_NAME "levels-frequencies.csv"
#define PLOT_SCRIPT_FILE_NAME "plotScript.gp"

int image[IMG_SIZE][IMG_SIZE];

typedef struct ColorLevel ColorLevel;

struct ColorLevel
{
    int value; // ColorLevel value
    int occurrence;
    double frequency;
};

ColorLevel colorLevels[255];

void generateImage();
void saveImage();
void drawImage();
int getRandIntiger();
ColorLevel createColorLevel(int);
void initColorLevels();
void calculateFrequencies();
void saveFrequencies();
void drawFrequenciesChart();

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

ColorLevel createColorLevel(int value)
{
    ColorLevel level;
    level.value = value;
    level.occurrence = 0;
    level.frequency = level.occurrence / IMG_SIZE;
    return level;
}

void initColorLevels()
{
    for (int i = 0; i < 256; i++)
    {
        colorLevels[i] = createColorLevel(i);
    }
}

void calculateFrequencies()
{
    for (int i = 0; i < IMG_SIZE; i++)
    {
        for (int j = 0; j < IMG_SIZE; j++)
        {
            colorLevels[image[i][j]].occurrence++;
            colorLevels[image[i][j]].frequency = (double)colorLevels[image[i][j]].occurrence / (IMG_SIZE * IMG_SIZE);
        }
    }
}

void saveFrequencies()
{

    FILE *filePtr = openFile(COLORS_FREQ_FILE_NAME, "wt");
    for (int i = 0; i < 255; i++)
        fprintf(filePtr, "%d,%.6f\n", i, colorLevels[i].frequency);
    fclose(filePtr);
}

void drawFrequenciesChart()
{
    Data data;
    data.src = COLORS_FREQ_FILE_NAME;
    data.separator = ",";
    Chart chart = __constChart("Levels", "Level", "Frequncies", "l", "f", "1.5", data);
    drawChart(chart);
}

int main(int argc, char const *argv[])
{
    generateImage();
    saveImage();
    initColorLevels();
    calculateFrequencies();
    saveFrequencies();
    drawImage();
    drawFrequenciesChart();
    return 0;
}

/* typedef struct Pixel Pixel;
typedef struct Pixel *PixelsList;

struct Pixel{
    int color; // pixel value
    int occurrence;
    double frequency;
    Pixel *next;
};


Pixel *new_pixel(int color);
PixelsList calculateFrequencies(); */

/* Pixel *new_pixel(int color){
    Pixel *p = (Pixel*)malloc(sizeof(Pixel));
    p->color = color;
    p->occurrence = 1;
    p->frequency = p->occurrence / IMG_SIZE;
    p->next = NULL;
}

PixelsList calculateFrequencies(){
    PixelsList pixelsList = NULL;
    for (int i = 0; i < IMG_SIZE; i++)
    {
        for (int j = 0; j < IMG_SIZE; j++)
        {
            if (pixelsList == NULL)
            {
                pixelsList =
            }

        }

    }


} */