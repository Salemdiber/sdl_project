#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
typedef struct background{

	SDL_Surface *afficher_background;
	SDL_Surface *aff;
	SDL_Rect pos_background;
	SDL_Rect pos_background2;
	SDL_Surface *calque_background;
	SDL_Surface *porte[14];
	SDL_Surface *owl[14];
	SDL_Rect port;
	SDL_Rect owll;
}background;

void initBack(background *b);
void initBack2(background *b);

void afficherBack(background b,SDL_Surface *ecran);
void scrolling (Hero *evan,background *b,int co );
int collisionPP(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
int collisionPP_gauche(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
int collisionPP_droite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);




#endif