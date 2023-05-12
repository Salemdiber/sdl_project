#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>

#include "player.h"




void init_hero(Hero *h)
{

    h->allMvt = IMG_Load("sprites/sprite.png");
    if(h->allMvt==NULL)
    {
        printf("CAN'T LOAD IMAGE");
    }

    h->frame = 0;
   // h->currentMode = 0;
    
    h->heroPos.x = 100;
    h->heroPos.y = 486;
    h->heroPos.w = 133;
    h->heroPos.h = 198;

    h->herosprite.x=0;
    h->herosprite.y=38; 
    h->herosprite.w=133;
    h->herosprite.h=198;

    h->velocity = 0;
    h->speed = 0;

    h->xStep = 0;
    h->yStep = 0;
    h->direction =0;
    h->last_direction=1;
    h->col_bas=0;
    h->VarX=0;
    h->Ground=486;


    //setrects(h->rects);
}



void init_hero2(Hero *h)
{
   h->allMvt = IMG_Load("sprites/sprite2.png");
    if(h->allMvt==NULL)
    {
        printf("CAN'T LOAD IMAGE");
    }

    h->frame = 0;
   // h->currentMode = 0;
    
    h->heroPos.x = 150;
    h->heroPos.y = 486;
    h->heroPos.w = 133;
    h->heroPos.h = 198;

    h->herosprite.x=0;
    h->herosprite.y=38; 
    h->herosprite.w=133;
    h->herosprite.h=198;

    h->velocity = 0;
    h->speed = 0;

    h->xStep = 0;
    h->yStep = 0;
    h->direction =0;
    h->last_direction=1;
    h->col_bas=0;
    h->VarX=0;
    h->Ground=486;
}

void afficher_Hero(Hero h, SDL_Surface *screen)
{
    SDL_BlitSurface(h.allMvt, &h.herosprite, screen, &h.heroPos);
}
void idleAnimation(Hero *h)
{
    
    if(h->last_direction == 1 && h->frame>=10)
    {
        if(h->herosprite.y!=38)
        {
            h->herosprite.x=0;
            h->herosprite.y=38;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
            h->heroPos.w = 133;
            h->heroPos.h = 198;
        }
        h->herosprite.x+=315;
        if(h->herosprite.x > 1260)
        {
            h->herosprite.x=0;
        }
        h->frame=0;
    }
    else if(h->last_direction == -1 && h->frame>=10)
    {
        if(h->herosprite.y!=276 && h->frame>=10)
        {
            h->herosprite.x=0;//poschoix.x >250
            h->herosprite.y=276;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
            h->heroPos.w = 133;
            h->heroPos.h = 198;
        }
        h->herosprite.x+=315;
        if(h->herosprite.x >1260)
        {
             h->herosprite.x=0;
        }
        h->frame=0;
    }

}

void leftAndRightHeroMvtR(Hero *hero,Input I, Uint32 dt)
{
    if (I.right == 0 && I.left == 0)
    {
        hero->velocity = 0;
        hero->speed =0;
    }
    else{
        if (hero->direction == 1 || hero->direction == -1)
        {
            if (I.right == 1 && I.left==0 )
            {

                hero->xStep = 0.5 * hero->velocity * dt * dt + hero->speed * dt;
                if(hero->xStep >6)
                {
                    hero->xStep=6;
                }
                if(hero->col_droite==0)
                hero->heroPos.x += hero->xStep; 
                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
                else{
                    hero->velocity=8;
                }
                if(hero->speed <2)
                {
                    hero->speed += 0.2;
                }
                else{
                    hero->speed=2;
                }

            }

            else if (I.left == 1 && I.right ==0)
            {
                hero->xStep = 0.5 * hero->velocity * dt * dt + hero->speed * dt;
                if(hero->xStep >6)
                {
                    hero->xStep=6;
                }
                if(hero->col_gauche==0)
                hero->heroPos.x -= hero->xStep;
                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
                else{
                    hero->velocity=8;
                }
                if(hero->speed <2)
                {
                    hero->speed += 0.2;
                }
                else{
                    hero->speed=3;
                }
            }
        }
    }
    
}
void jumpHeroMvt(Hero *hero, Input *I)
{
    ///printf("%f\n",p->VarX);
	int y;
	int Amp = -350;
	float delta = -4 * Amp;
	float x = (sqrt(delta) / 2);
	if ((I->jump == 1))
	{
		hero->VarX++;
        
        //hero->Ground=hero->heroPos.y+198;
	}
    
	y = (int)((hero->VarX - x) * (hero->VarX - x) + Amp);
	if (y < 0)
	{
		//hero->col_bas = 0;
	}
	if (y >= 0)
	{
		y = 0;
		hero->VarX = 0;
		I->jump = 0;
		//hero->col_bas = 0;
	}
    if(hero->col_bas==1 && I->jump == 1  )
    {
        hero->Ground-=abs(y);
        
    }
    else if(hero->col_bas==0 && I->jump==0 )
    {
        hero->Ground+=5;

    }
    else if(I->jump == 0 && hero->col_bas==1 )
    {
        hero->Ground--;
    }
	hero->heroPos.y = (int)y + hero->Ground;
    
}
void runAnimation(Hero *h)
{
    if(h->direction == 1 && h->frame>=10)
    {
        if(h->herosprite.y!=523)
        {
            h->herosprite.x=0;
            h->herosprite.y=523;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
        }
        h->herosprite.x+=333;
        if(h->herosprite.x > 2331)
        {
            h->herosprite.x=333;
        }
        h->frame=0;
    }
    else if(h->direction == -1 && h->frame>=10)
    {
        if(h->herosprite.y!=772)
        {
            h->herosprite.x=2324;
            h->herosprite.y=772;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
        }
        h->herosprite.x-=332;
        if(h->herosprite.x < 0)
        {
            h->herosprite.x=2324;
        }
        h->frame=0;
    }
}

void jumpAnimation(Hero *h)
{
    if(h->direction == 1 && h->frame>=10)
    {
        if(h->herosprite.y!=963)
        {
            h->herosprite.x=1104;
            h->herosprite.y=963;
            h->herosprite.w = 183;
            h->herosprite.h = 215;
        }
        h->herosprite.x+=374;
        if(h->herosprite.x > 1852 || h->herosprite.x<1104)
        {
            h->herosprite.x=1104;
        }
        h->frame=0;
    }
    else if(h->direction == -1 && h->frame>=10)
    {
        if(h->herosprite.y!=1289)
        {
            h->herosprite.x=354;
            h->herosprite.y=1289;
            h->herosprite.w = 155;
            h->herosprite.h = 206;
        }
        h->herosprite.x+=353;
        if(h->herosprite.x > 1060 || h->herosprite.x<354)
        {
            h->herosprite.x=354;
        }
        h->frame=0;
    }

}
void attackAnimation(Hero *h,Input *I)
{
    if((h->direction == 1 || h->last_direction ==1) && h->frame>=5)
    {
        if(h->herosprite.y!=1606)
        {
            h->herosprite.x=0;
            h->herosprite.y=1606;
            h->herosprite.w = 235;
            h->herosprite.h = 212;
            h->heroPos.w = 235;
            h->heroPos.h = 212;
        }
        h->herosprite.x+=352;
        if(h->herosprite.x > 1408 )
        {
            h->herosprite.x=0;
            I->attack=0;
        }
        h->frame=0;
    }
    else if((h->direction == -1 || h->last_direction==-1) && h->frame>=5)
    {
        if(h->herosprite.y!=1870)
        {
            h->herosprite.x=1324;
            h->herosprite.y=1870;
            h->herosprite.w = 235;
            h->herosprite.h = 212;
            h->heroPos.w = 235;
            h->heroPos.h = 212;
        }
        h->herosprite.x -=352;
        if(h->herosprite.x < 268 )
        {
            h->herosprite.x=0;
            I->attack=0;
        }
        h->frame=0;
    }

}
