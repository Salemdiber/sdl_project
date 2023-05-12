#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "enemy.h"

// This function initializes an ennemi structure with default values
void initEnnemi(ennemi *e)
{
    // Load the sprite image for the ennemi
	e->sprite = IMG_Load("picture/enemy.png");

    // Check if the sprite image was loaded successfully
	if (e->sprite == NULL)
	{
		printf("Can't Load image : %s\n", SDL_GetError());
	}

    // Set the direction of the ennemi to move horizontally
	e->direction_x = 1;
    e->direction_y = 0;

    //Set enemy health 
    e->nb_vie=100;

    // Set the initial position of the ennemi on the screen
    e->posScreen.x = 500;
	e->posScreen.y = 520;
    e->posScreen.w = 120;
    e->posScreen.h = 124;

    // Set the initial position of the sprite for the ennemi
	e->posSprite.x = 0;
	e->posSprite.y = 579; 
    e->posSprite.w = 120;
	e->posSprite.h = 116; 
	
    // Set the initial frame and movement speed of the ennemi
	e->frame = 0;
    e->speed = 2;

    // Set the initial and final positions of the ennemi
    e->posinit=300;
    e->posfinal=600;
}

// This function displays the ennemi on the screen
void afficherEnnemi(ennemi e, SDL_Surface  * screen)
{
	SDL_BlitSurface(e.sprite, &(e.posSprite), screen, &(e.posScreen)); 
}

// This function animates the sprite of the ennemi
void animerEnnemi(ennemi *e)
{
    // Increment the frame counter
    e->frame++;

    // Change the sprite position of the ennemi every 30 frames
    if(e->direction_x !=0&& e->frame>=30 ){
        e->posSprite.x+=120;
        e->frame =0;
    }

    // Reset the sprite position of the ennemi if it reaches the end of the sprite sheet
    if(e->posSprite.x>=1200)
    {
        e->posSprite.x=0;
    }
}

// This function moves the ennemi on the screen
void move( ennemi * e,int x) 
{
    int random_num;    //effacer
    srand(time(NULL)); //effacer 
    random_num = rand() % 3+1; //effacer 
    // If the ennemi is moving to the right and it reaches its final position, change its direction and sprite position
    if(e->direction_x ==1 && e->posScreen.x>=e->posfinal && e->mode_attack==0)
    {
        e->direction_x = -1;
        e->posSprite.y = 467;
    }

    // If the ennemi is moving to the left and it reaches its initial position, change its direction and sprite position
    if(e->direction_x == -1 && e->posScreen.x<=e->posinit && e->mode_attack==0)
    {
        e->direction_x = 1;
        e->posSprite.y = 579;
    }

    if(e->direction_x == -1 && e->posScreen.x<=e->posinit && e->mode_attack==0)
    {
        e->direction_x = 1;
        e->posSprite.y = 579;
    }



    // Move the ennemi horizontally
    
    if(e->direction_x ==1 && (e->frame % random_num)==0 && e->mode_attack==0) //random_num -> 2 ou 3 ou 4 
    {
         e->posScreen.x += (e->speed * e->direction_x);
         
    }
    if(e->direction_x == -1 && (e->frame % random_num)==0 && e->mode_attack==0 ) // random_num -> 2 ou 3 ou 4
    {
         e->posScreen.x += (e->speed * e->direction_x);
         
    } 
    
    
}

// Checks if there is a collision between the player and the enemy character
int collisionBB(SDL_Rect posp, SDL_Rect pose)
{
    if((posp.x + posp.w < pose.x) || (posp.x > pose.x + pose.w) || (posp.y + posp.h < pose.y) || (posp.y > pose.y + pose.h)){
        return 0;
    }
    else{
        return 1;
    }
}
