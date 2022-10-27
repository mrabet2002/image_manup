#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DRAWCHART_H_INCLUDED
    #define DRAWCHART_H_INCLUDED
    #include "drawchart.h"
#endif

#define COLORS_FREQ_FILE_NAME "levels-frequencies.csv"

typedef struct ColorLevel ColorLevel;

struct ColorLevel
{
    int value; // ColorLevel value
    int occurrence;
    double frequency;
};

ColorLevel colorLevels[255];

ColorLevel createColorLevel(int, int);
void initColorLevels(int);
void calculateFrequencies(int **, int);
void saveFrequencies();
void drawFrequenciesChart();


ColorLevel createColorLevel(int value, int imgSize)
{
    ColorLevel level;
    level.value = value;
    level.occurrence = 0;
    level.frequency = level.occurrence / imgSize;
    return level;
}

void initColorLevels(int imgSize)
{
    for (int i = 0; i < 256; i++)
    {
        colorLevels[i] = createColorLevel(i, imgSize);
    }
}

void calculateFrequencies(int **image, int imgSize)
{
    initColorLevels(imgSize);
    for (int i = 0; i < imgSize; i++)
    {
        for (int j = 0; j < imgSize; j++)
        {
            colorLevels[image[i][j]].occurrence++;
            colorLevels[image[i][j]].frequency = (double)colorLevels[image[i][j]].occurrence / (imgSize * imgSize);
        }
    }

    saveFrequencies();
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

// #endif