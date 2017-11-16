SRC = src/main.c src/img.c
HEAD = src/img.h

all: build

build: $(SRC) $(HEAD)
	gcc -o im3D $(SRC) -lpng

run: build
	feh out.png

clean:
	rm -rf out.png
	rm -rf im3D
