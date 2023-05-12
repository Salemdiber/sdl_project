#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
#include "background.h"
#include "input.h"
void scrolling (Hero *evan,background *b,int co )
{
  
  const int speed = 4;
  if (evan->direction == 1 && (co==0||co==2))
  {
    if (( b->pos_background2.x <6400 - 1280)  &&(evan->heroPos.x >= 520))
    {
      if(evan->col_droite==0)
      b->pos_background2.x += speed;
    }
  }
  else if (evan->direction == -1 && (co==0||co==2) )
  {
    if (b->pos_background2.x > 0)
    {
      if(evan->col_gauche==0)
      b->pos_background2.x -= speed;
	  printf("%d\n",b->pos_background2.x );
    }
  }

	
}


