SRC = src/main.c src/buffer.c src/point.c src/draw.c src/math.c src/io.c src/matrix.c src/model.c
HEAD = src/buffer.h src/color.h src/point.h src/draw.h src/math.h src/io.h src/matrix.h src/model.h

all: build

build: $(SRC) $(HEAD)
	gcc -o im3D $(SRC) -lpng -lm

run: build
	./im3D
	feh out.png

clean:
	rm -rf out.png
	rm -rf im3D
