
set terminal png
set output "plot.png"
set logscale y
set title "Rabbit population" 
set ylabel "Number of rabbits"
set xlabel "Number of generations"
plot "_data3.csv" using 1 with lines title "unlimited lifespan", "_data.csv" using 1 with lines title "limited lifespan (4 months)"

