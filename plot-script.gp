set datafile separator data_separator
set title chart_title

if( chart_type eq "image" ){
    unset colorbox
    unset tics
    set palette grey
    plot filename matrix w image
} else {
    set xlabel x_label
    set ylabel y_label
    set grid
    plot filename using 1:2 w lines lw line_w lc line_c
}

pause 5