#! /bin/bash

# ----------------------------------------------
# Generates render times for im3D and creates
# an octave script which will graph the output.
# ----------------------------------------------

make

# Create the output file (if necessary) and wipe it.
OUT="$1.m"
> $OUT

echo "function $0
clear all;
close all;
hold on;

x = [44115 61152 113955 596682];
" >> $OUT

for THREAD_COUNT in 1 2 4 8 16
do
	printf "t$THREAD_COUNT = [ " >> $OUT
	for MODEL in "models/war.obj" "models/dragon.obj" "models/blackdragon.obj" "models/ironman.obj"
	do
		echo $THREAD_COUNT $MODEL | xargs ./im3D
	done
	printf "];\n" >> $OUT

	printf "plot(x, t$THREAD_COUNT, 'LineWidth', 3, 'DisplayName', '$THREAD_COUNT thread(s)');\n" >> $OUT
done

echo "
title('$1');
xlabel('Number of Vertices');
ylabel('Vertex Transformation Time');
legend('show', 'Location', 'NorthWest');
" >> $OUT
