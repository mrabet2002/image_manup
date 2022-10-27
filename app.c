#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include "imagemanup.h"
// #include "imagemanup_v2.h"

#define IMG_SIZE 1000

typedef enum boolean
{
    false,
    true
} boolean;

int main(int argc, char const *argv[])
{

    int **image = generateImage(image, IMG_SIZE);

    // Image image = __constImage(IMG_SIZE);
    // generatePixels(&image);

    int opperation;

    while (1)
    {
        printf("Voulez vous ?\n");
        printf("Afficher l'image (tapper 1)\n");
        printf("Afficher la courbe des frequences (tapper 2)\n");
        printf("Quitter (tapper 0)\n");
        scanf("%d", &opperation);

        switch (opperation)
        {
        case 1:
            drawImage();
            break;
        case 2:
            calculateFrequencies(image, IMG_SIZE);
            drawFrequenciesChart();
            break;
        case 0:
            return 0;

        default:
            printf("Veulliez entrer une valeur valide!\n");
            break;
        }
    }
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