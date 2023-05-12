#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
#include "background.h"

SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;
	char* pPosition = ( char* ) surface->pixels ;
	pPosition += ( surface->pitch * y ) ;
	pPosition += ( surface->format->BytesPerPixel * x ) ;
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}
int collisionPP(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col0,col1;
  

	col0=GetPixel(calque,posperso.x+(132/2)+posmap.x,posperso.y+(198-2));
	col1=GetPixel(calque,posperso.x+(132/2)+posmap.x,posperso.y+(198-7));

	//col22=GetPixel(calque,posperso.x+133+posmap.x,posperso.y+198);

	if ((col0.r==0)&&(col0.b==0)&&(col0.g==0) && (col1.r==0)&&(col1.b==0)&&(col1.g==255))
 	 return 2;
	else if ((col0.r==0)&&(col0.b==0)&&(col0.g==0) && (col1.r==0)&&(col1.b==0)&&(col1.g==0))
	return 1;
	else
	 return 0;
}
int collisionPP_gauche(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col0,col1,col2;
  

	col0=GetPixel(calque,posperso.x-20+posmap.x,posperso.y+90);
	col1=GetPixel(calque,posperso.x-20+posmap.x,posperso.y+100);
	col2=GetPixel(calque,posperso.x-20+posmap.x,posperso.y+110);
	//col22=GetPixel(calque,posperso.x+133+posmap.x,posperso.y+198);

	if ((col0.r==0)&&(col0.b==0)&&(col0.g==0) && (col1.r==0)&&(col1.b==0)&&(col1.g==0)  && (col2.r==0)&&(col2.b==0)&&(col2.g==0) )
 	 return 1;
	else
	 return 0;
}
int collisionPP_droite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col0,col1,col2;
  

	col0=GetPixel(calque,posperso.x+112+posmap.x,posperso.y+90);
	col1=GetPixel(calque,posperso.x+112+posmap.x,posperso.y+100);
	col2=GetPixel(calque,posperso.x+112+posmap.x,posperso.y+110);
	//col22=GetPixel(calque,posperso.x+133+posmap.x,posperso.y+198);
	if ((col0.r==0)&&(col0.b==0)&&(col0.g==0) && (col1.r==0)&&(col1.b==0)&&(col1.g==0)  && (col2.r==0)&&(col2.b==0)&&(col2.g==0) )
 	 return 1;
	else
	 return 0;
}


