prog:  *.o
	gcc *.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm -g
sauvegarde.o : sauvegarde.c
	gcc -c sauvegarde.c -g
enigme6.o:enigme6.c
	gcc -c enigme6.c
enemy.o:enemy.c
	gcc -c enemy.c
enigme.o:enigme.c 
	gcc -c enigme.c -g	
temps.o : temps.c
	gcc -c temps.c -g
minimap.o : minimap.c
	gcc -c minimap.c -g
scrolling.o:scrolling.c 
	gcc -c scrolling.c -lSDL -lSDL_image -lSDL_mixer -g
collisionPP.o:collisionPP.c 
	gcc -c collisionPP.c -g
background.o:background.c 
	gcc -c background.c  -g
input.o:input.c
	gcc -c input.c -g
player.o:player.c
	gcc -c player.c -g
main.o:main.c
	gcc -c main.c -g
fonction.o:fonction.c
	gcc -c fonction.c -g
sauv.o:sauv.c
	gcc -c sauv.c -g
source.o:source.c
	gcc -c functionsPartage.c
