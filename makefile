SRC = src/main.c src/buffer.c src/color.c src/point.c src/draw.c src/math.c
HEAD = src/buffer.h src/color.h src/point.h src/draw.h src/math.h

all: build

build: $(SRC) $(HEAD)
	gcc -o im3D $(SRC) -lpng -lm

run: build
	feh out.png

clean:
	rm -rf out.png
	rm -rf im3D
