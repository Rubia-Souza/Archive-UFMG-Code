set term postscript eps color 14
set output "/tmp/internoest/internoest-hist-0-1.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 20000 - Fase  0 - ID 1"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:1001] "/tmp/internoest/internoest-hist-0-1.gpdat" u 3:4 w boxes t ""
