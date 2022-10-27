#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fmanup.h"

#define FMANUP_H_INCLUDED

#define GNUPLOT_SCRIPT_PATH "plot-script.gp"

typedef struct Data
{
    char *src;
    char *type;
    char *separator;
} Data;

typedef struct Chart
{
    const char *title;
    const char *xLabel;
    const char *yLabel;
    const char *type;
    const char *color;
    const char *lineWidth;
    Data data;
} Chart;

char plotScript[1000];

Chart __constChart(const char *, const char *, const char *, const char *, const char *, const char *, Data);
void drawChart(Chart);
// void initPlotScript(const char *dataType);

Chart __constChart(const char *title,
                   const char *xLabel,
                   const char *yLabel,
                   const char *type,
                   const char *color,
                   const char *lineWidth, Data data)
{
    Chart chart;

    chart.title = title;
    chart.xLabel = xLabel;
    chart.yLabel = yLabel;
    chart.type = type;
    chart.color = color;
    chart.lineWidth = lineWidth;
    chart.data = data;

    return chart;
}

void drawChart(Chart chart)
{
    char cmd[100];

    // initPlotScript(chart.type);

    if (strcmp(chart.type, "image") == 0)
    {
        printf("image");
        sprintf(cmd, "gnuplot -e \"filename=\'%s\'\" -e \"data_separator=\'%s\'\" -e \"chart_title=\'%s\'\" -e \"chart_type=\'%s\'\" %s",
                chart.data.src, chart.data.separator, chart.title, chart.type, GNUPLOT_SCRIPT_PATH);
    }
    else
    {
        sprintf(cmd, "gnuplot -e \"filename=\'%s\'\" -e \"data_separator=\'%s\'\" -e \"chart_title=\'%s\'\" -e \"chart_type=\'%s\'\" -e \"line_w=\'%s\'\" -e \"line_c=\'%s\'\" -e \"x_label=\'%s\'\" -e \"y_label=\'%s\'\" %s",
                chart.data.src, chart.data.separator, chart.title, chart.type, chart.lineWidth, chart.color, chart.xLabel, chart.yLabel, GNUPLOT_SCRIPT_PATH);
    }
    system(cmd);
}

/* void initPlotScript(const char *chartType)
{

    if (strcmp(chartType, "image") == 0)
    {
        printf("in");
        sprintf(plotScript, "set datafile separator data_separator\nset title chart_title\nunset colorbox\nunset tics\nset palette grey\nplot filename matrix w image\npause 5");
    }
    else
    {
        sprintf(plotScript, "set datafile separator data_separator\nset title chart_title\nset xlabel x_label\nset ylabel y_label\nset grid\nplot filename using 1:2 w lines lw line_w lc line_c\npause 5");
    }

    FILE *filePtr = openFile(GNUPLOT_SCRIPT_PATH, "wt");

    fprintf(filePtr, plotScript);

    fclose(filePtr);
}
 */