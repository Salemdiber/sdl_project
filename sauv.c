#include "sauv.h"
#include "player.h"
#include "background.h"


void sauvegarderpos (Hero p, background b, char * nomfichier)
{	
	FILE *f;
   
	f=fopen(nomfichier, "w");
	fprintf(f, "%d %d\n", p.heroPos.x, p.heroPos.y);
	fprintf(f, "%d %d\n", b.pos_background2.x, b.pos_background2.y);
	fclose(f);
}

int charger (Hero *p, background *b , char * nomfichier)
{
	
	FILE *f=fopen(nomfichier,"r");
	if(f==NULL)
	{
	     printf("Erreur !");
	}
	else
	{	int x=0,y=0;
		printf("loading");
		fscanf(f,"%hd %hd\n",&p->heroPos.x,&p->heroPos.y);
		fscanf(f,"%hd %hd\n",&b->pos_background2.x,&b->pos_background2.y);
		printf("%hd %hd",x,y);
	}
	fclose(f);
}

