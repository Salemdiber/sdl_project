#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background.h"



void initBack(background *b)
{
	b->calque_background=NULL;
	b->calque_background=IMG_Load("image_level/calque_level2.png");
	b->afficher_background=NULL;
	b->afficher_background=IMG_Load("image_level/level2.png");
	b->aff=NULL;
	b->aff=IMG_Load("map.png");
	b->pos_background.x=0;
	b->pos_background.y=0;
	b->pos_background2.x=0;
	b->pos_background2.y=0;
	b->pos_background2.h=1020;
	b->pos_background2.w=1920;
	b->port.x=  0 ;
        b->port.y=  0 ;
        b->owll.x=  0 ;
        b->owll.y=  0 ;
}
void initBack2(background *b)
{
	b->calque_background=NULL;
	b->calque_background=IMG_Load("image_level/calque_level1.png");
	b->afficher_background=NULL;
	b->afficher_background=IMG_Load("image_level/level1.png");
	b->aff=NULL;
	//b->aff=IMG_Load("map.png");
	b->pos_background.x=0;
	b->pos_background.y=0;
	b->pos_background2.x=0;
	b->pos_background2.y=0;
	b->pos_background2.h=1020;
	b->pos_background2.w=1920;
	b->port.x=  0 ;
        b->port.y=  0 ;
        b->owll.x=  0 ;
        b->owll.y=  0 ;
}


void afficherBack(background b,SDL_Surface *ecran)
{	
	SDL_BlitSurface(b.afficher_background,&(b.pos_background2),ecran,&(b.pos_background));
}


void animerBackground (background *b,SDL_Surface *ecran)
{   
    int j;
    char ch[50];
    int i;
    char chh[50];
     SDL_BlitSurface(b->aff,NULL,ecran,&(b->port));
    for(j=1; j<10; j++)
    {
        SDL_BlitSurface( b->porte[j], NULL,ecran,&(b->port));
        SDL_Flip(ecran);
        SDL_Delay(130);      
    }
SDL_Delay(1000);
SDL_BlitSurface(b->aff,NULL,ecran,&(b->port));
    for(j=1; j<12; j++)
    {
        SDL_BlitSurface( b->owl[j], NULL,ecran,&(b->owll));
        SDL_Flip(ecran);
        SDL_Delay(130);
    }
SDL_Delay(2000);
    for(j=1; j<12; j++)
    {
        SDL_BlitSurface( b->owl[j], NULL,ecran,&(b->owll));
        SDL_Flip(ecran);
        SDL_Delay(130);
    }


}

