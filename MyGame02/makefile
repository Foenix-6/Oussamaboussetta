brog:main.o map.o entity.o ennemie.o
	gcc main.o map.o entity.o ennemie.o -o brog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

main.o:main.c 
	gcc -c main.c -g

entity.o:entity.c
	gcc -c entity.c -g
ennemie.o:ennemie.c
	gcc -c ennemie.c -g
map.o:map.c
	gcc -c map.c -g
