#ifndef enigme_H_INCLUDED
#define enigme_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct
{
	SDL_Rect pos, reponse_pos, t_pos, h_pos;

	SDL_Surface *enigme;
	SDL_Surface *qst;
	SDL_Surface *reponse, *reponse1, *t, *h;
	char rep[3];

} enigme;

int Init_enigme(enigme *g);
int afficherEnigme(enigme *e);
int genererEnigme();
void animerEnigme(enigme *e,int i);
#endif // DS_H_INCLUDED