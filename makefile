GXX = gcc
BIN = im3D
HEAD =	src/buffer.h src/color.h src/point.h  \
		src/draw.h src/math.h src/io.h src/matrix.h  \
		src/model.h src/shaders.h src/material.h
OBJ = main.o buffer.o point.o draw.o math.o io.o \
	  matrix.o model.o shaders.o material.o

all: build

run: build
	./$(BIN) 4 models/war.obj

build: $(OBJ)
	$(GXX) -g -O3 -fopenmp -lm -o $(BIN) $(OBJ)

main.o: src/main.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/main.c

buffer.o: src/buffer.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/buffer.c

point.o: src/point.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/point.c

draw.o: src/draw.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/draw.c

math.o: src/math.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/math.c

io.o: src/io.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/io.c

matrix.o: src/matrix.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/matrix.c

model.o: src/model.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/model.c

shaders.o: src/shaders.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/shaders.c

material.o: src/material.c $(HEAD)
	$(GXX) -g -O3 -fopenmp -c src/material.c

clean:
	rm -rf *.o
	rm -rf *.png
	rm -rf im3D
