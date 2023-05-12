#ifndef player_H_INCLUDED
#define player_H_INCLUDED
#include "input.h"


typedef struct
{
    SDL_Surface *allMvt;
    SDL_Rect heroPos;
    
    SDL_Rect herosprite;

    int frame;
    float xStep, yStep;
    float velocity, speed;
    int direction; // 0: no move 1:right move -1: left move (num kima repere fel math )
    int last_direction; // 1 or -1 we will save the last direction  right or left 
    int col_bas;
    int col_gauche;
    int col_droite;
    float VarX;
    int Ground;




}Hero;




void init_hero(Hero *h);
void init_hero2(Hero *h);
void afficher_Hero(Hero h, SDL_Surface *screen);
void idleAnimation(Hero *h);
void leftAndRightHeroMvtR(Hero *hero,Input I, Uint32 dt);
void runAnimation(Hero *h);
void jumpHeroMvt(Hero *hero, Input *I);
void jumpAnimation(Hero *h);
void attackAnimation(Hero *h,Input *I);
/*

void runAnimation(Hero *h);

void jumpAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos, int run);

void attackAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos);
void leftAndRightHeroMvt(Hero *hero, Input I);
void leftAndRightHeroMvtR(Hero *hero, Input I, Uint32 dt);
void jumpHeroMvt(Hero *hero, Input I, int *run);*/


#endif
