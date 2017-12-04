BIN = im3D
HEAD =	src/buffer.h src/color.h src/point.h  \
		src/draw.h src/math.h src/io.h src/matrix.h  \
		src/model.h src/shaders.h src/material.h
OBJ = main.o buffer.o point.o draw.o math.o io.o \
	  matrix.o model.o shaders.o material.o
LIB = -lm -fopenmp

all: build

run: build
	./$(BIN)

build: $(OBJ)
	gcc -o $(BIN) $(OBJ) $(LIB)

main.o: src/main.c $(HEAD)
	gcc -c src/main.c

buffer.o: src/buffer.c $(HEAD)
	gcc -c src/buffer.c

point.o: src/point.c $(HEAD)
	gcc -c src/point.c

draw.o: src/draw.c $(HEAD)
	gcc -c src/draw.c

math.o: src/math.c $(HEAD)
	gcc -c src/math.c

io.o: src/io.c $(HEAD)
	gcc -c src/io.c

matrix.o: src/matrix.c $(HEAD)
	gcc -c src/matrix.c

model.o: src/model.c $(HEAD)
	gcc -c src/model.c

shaders.o: src/shaders.c $(HEAD)
	gcc -c src/shaders.c

material.o: src/material.c $(HEAD)
	gcc -c src/material.c

clean:
	rm -rf *.o
	rm -rf *.png
	rm -rf im3D
