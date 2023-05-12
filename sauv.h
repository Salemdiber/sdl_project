#ifndef SAUV_H_INCLUDED
#define SAUV_H_INCLUDED
#include "player.h"
#include"background.h"

void sauvegarderpos (Hero p, background b, char * nomfichier);
int charger (Hero *p, background *b , char * nomfichier);

#endif
