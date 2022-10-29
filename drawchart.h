#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FMANUP_H_INCLUDED
    #define FMANUP_H_INCLUDED
    #include "fmanup.h"
#endif

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