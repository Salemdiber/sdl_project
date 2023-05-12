#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

// Definition of a structure for an enemy
typedef struct
{
SDL_Surface * sprite; // The sprite image for the enemy
SDL_Rect posScreen; // The position of the enemy on the screen
SDL_Rect posSprite; // The position of the enemy on the sprite
int posinit,posfinal; // The initial and final positions of the enemy
int direction_x; // The direction of the enemy in the x-axis
int direction_y; // The direction of the enemy in the y-axis
int speed; // The speed of the enemy
int frame; // The current frame of the enemy's animation
int nb_vie;
int mode_attack; //0 si no attack 1si le person entre dans la zone de enemy(posinit jusqua pos final)
}ennemi; // Structure name

// Function declarations
void initEnnemi(ennemi *e); // Initializes the enemy object
void afficherEnnemi(ennemi e, SDL_Surface * screen); // Displays the enemy on the screen
void animerEnnemi(ennemi * e); // Animates the enemy
void move( ennemi * e,int x);
 // Moves the enemy
int collisionBB(SDL_Rect posp, SDL_Rect pose); // Checks if there is a collision between two rectangles

#endif
