#! /bin/bash

# ----------------------------------------------
# Generates render times for im3D and creates
# an octave script which will graph the output.
# ----------------------------------------------

make

# Create the output file (if necessary) and wipe it.
OUT="time/$1.m"
> $OUT

echo "function $1
clear all;
close all;
hold on;

x = [1 2 4 8 16];
" >> $OUT

MODELS=("models/war.obj" "models/dragon.obj" "models/blackdragon.obj" "models/ironman.obj")
# MODELS=("models/ironman.obj")

IDX=0
for MODEL in ${MODELS[@]}
do
	printf "t$IDX = [ " >> $OUT
	for THREAD_COUNT in 1 2 4 8 16
	do
		echo "$THREAD_COUNT $MODEL --- BEGIN"
		echo $THREAD_COUNT $MODEL | xargs ./im3D >> $OUT
		echo "$THREAD_COUNT $MODEL --- END"
	done
	printf "];\n" >> $OUT

	printf "plot(x, t$IDX, 'LineWidth', 3, 'DisplayName', '$MODEL 3840x2160');\n" >> $OUT
	IDX=$((IDX+1))
done


echo "
title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');
" >> $OUT
