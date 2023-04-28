/** 
*@file pers.h
* @struct personne 
* @brief struct for personne 
*/ 

 #include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



#define STAT_SOL 0
#define STAT_AIR 1

typedef struct
{
    int status,num,dr,vi;
    float x,y;
    float vx,vy;
 SDL_Rect posperso,vie; /*!< Rectangle*/
SDL_Surface *tab[20],*tabvie[3]; /*!< Surface. */ 
 int fig;
    int dep,acc,vitesse;
    int vieper;
} personne;









//************personnage***************
void initperso(personne* p);
void Miseajour(personne* p,SDL_Surface* screen);
void afficherperso(personne* p,SDL_Surface *ecran);
void deplacerperso(personne *p);
void Saute(personne* p,float impulsion);
void ControleSol(personne* p);
void Gravite(personne* p,float factgravite,float factsautmaintenu,Uint8* keys);
void animerperso(personne* p);
void Updateperso(personne* p,Uint8* keys);
void Updateperso1(personne* p1,Uint8* keys);


