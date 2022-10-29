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