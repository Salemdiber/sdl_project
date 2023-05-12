#include "temps.h"

void initialiser_temps(temps *t)
{
  t->texte = NULL; // surface li bech nblitiwha (forme mm:ss)
  t->score = NULL;
  t->s = 0;
  t->position.x = 500;
  t->position.y = 50;
  t->police = NULL;
  t->police = TTF_OpenFont("outils/avocado.ttf", 40);
  if (t->police == NULL)
  {
    printf("error loading font \n ");
  }
  t->color.r = 255 ; 
  t->color.g = 255 ; 
  t->color.b = 255 ; 

  strcpy(t->entree, "");
  (t->secondesEcoulees) = 0;
  time(&(t->t1)); // temps du debut
}

void afficher_temps(temps *t, SDL_Surface *ecran)
{ 
  SDL_Rect pos_score;
  char sscore[100];
  pos_score.x= 800;
  pos_score.y= 50;

  time(&(t->t2)); // temps actuel

  t->secondesEcoulees = t->t2 - t->t1;

  t->min = ((t->secondesEcoulees / 60) % 60);
  t->sec = ((t->secondesEcoulees) % 60);

  sprintf(t->entree, "%02d:%02d", t->min, t->sec); // "%d:%d",t->min,t->sec resultat : entree="02:30"

  t->texte = TTF_RenderText_Blended(t->police, t->entree, t->color);

  SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); /* Blit du temps */

  t->s = (t->sec * 10 + t->min * 600);
  sprintf(sscore, "%02d", t->s ); 

  t->score = TTF_RenderText_Blended(t->police, sscore , t->color);

  SDL_BlitSurface(t->score, NULL, ecran, &pos_score); /* Blit du score */
}

void free_temps(temps *t)
{
  SDL_FreeSurface(t->texte);
  SDL_FreeSurface(t->score);
  TTF_CloseFont(t->police);
}
