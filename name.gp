set datafile separator ','
set xlabel 'Time / s'
set ylabel 'Concentraction'
set yrange [0.0:1.0]
plot 'test.csv' using 1:2 with lines title 'cA', \
'test.csv' using 1:4 with lines title 'cC'