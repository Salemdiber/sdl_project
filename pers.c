/** 
*@file pers.c

* @brief file for personne 
*/ 

#include"pers.h"


void initperso(personne* p)
{
    p->x = 150.0f;          // type de mesure
    p->y = 700.0f;
    p->status = STAT_SOL;
    p->vx = p->vy = 0.0f;
p->vitesse=5;
p->acc=0;
p->num=1;
p->dr=-1;
p->vi=0;
p->vie.x=500;
p->vie.y=0;
p->fig=0;
char nomFich[20];
int i;
for(i=0;i<20;i++)
{
    sprintf(nomFich,"a%d.png",i);
    p->tab[i]=IMG_Load(nomFich);
}
char nomvie[20];
int j;
for(j=0;j<4;j++)
{
    sprintf(nomvie,"v%d.png",j);
    p->tabvie[j]=IMG_Load(nomvie);
}

}


void Miseajour(personne* p,SDL_Surface* screen)
{
   
   p->posperso.x = (Sint16)p->x/10;             
      p->posperso.y = (Sint16)p->y;
      p->posperso.w = 20;
p->posperso.h = 40;
  
}
 

void afficherperso(personne* p,SDL_Surface *ecran)
{  
SDL_BlitSurface(p->tab[p->num],NULL,ecran,&(p->posperso));
SDL_BlitSurface(p->tabvie[p->vi],NULL,ecran,&(p->vie));
}

 

void Saute(personne* p,float impulsion)
{
    p->vy = -impulsion;           
    p->status = STAT_AIR;           
}




void deplacerperso(personne *p)
{
if(p->dep==1)
{
p->x+=((0.5*p->acc)+(p->vitesse))+50;
}
else if(p->dep==0)
{p->x-=((0.5*p->acc)+(p->vitesse))+50;
}
if(p->x<=10)
{
p->x+=60;
}
if(p->x>=9060.000000)
{
p->x-=80;
}

}



void ControleSol(personne* p)
{
    if (p->y>200.0f)    
    {
        p->y = 200.0f;
        if (p->vy>0)
            p->vy = 0.0f;
        p->status = STAT_SOL;
    }
}

void Gravite(personne* p,float factgravite,float factsautmaintenu,Uint8* keys)
{
    if (p->status == STAT_AIR &&( keys[SDLK_UP]||keys[SDLK_z]))
        factgravite/=factsautmaintenu; // factgravite=factgravite/factsautmaintenu
    p->vy += factgravite;
}


void animerperso(personne* p)
 {  
     if(p->dr==0)
     {if(p->num>=5)
      p->num=1;
      else p->num++;
     }
     else if(p->dr==1)
     {
      if(p->num==10||p->num<6||p->num>11)
       p->num=6;
       else p->num++;
      }
 else if(p->dr==2)
     {
      if(p->num==13||p->num<11||p->num>14)
       p->num=11;
       else p->num++;
      }
 else if(p->dr==3)
     {
   
       p->num=16;
    
      }
else if(p->dr==4)
     {
     
       p->num=17;
     
      }
 else 
     {
      if(p->num==15||p->num<14||p->num>16)
       p->num=14;
       else p->num++;
      }
 
      }


void Updateperso(personne* p,Uint8* keys)
{ 
    float impulsion = 6.0f;
    float factgravite = 0.5f;
    float factsautmaintenu = 3.0f;
 if (keys[SDLK_RIGHT]==0&&keys[SDLK_LEFT]==0&&keys[SDLK_j]==0&&keys[SDLK_UP]==0&&keys[SDLK_w]==0)
{ 
  p->dr=-1;
animerperso(p);

}

 if (keys[SDLK_RIGHT]==1)
{ p->dep=1;
     deplacerperso(p);
  p->dr=0;
animerperso(p);

}
if (keys[SDLK_j])
{ p->dr=2;
animerperso(p);
p->fig=3;//mtaa edharba
}
 if (keys[SDLK_w])
{
  p->acc=20;
p->dr=4;
animerperso(p);
}
 if (keys[SDLK_a])
  p->acc=0;
 if (keys[SDLK_f])
{ p->vi=1;
}
 if (keys[SDLK_LEFT])
{ p->dep=0;
     deplacerperso(p);
  p->dr=1;
animerperso(p);

}
if (keys[SDLK_UP] && p->status == STAT_SOL)
      {  Saute(p,impulsion);
         p->dr=3;
animerperso(p);}
    Gravite(p,factgravite,factsautmaintenu,keys);
    ControleSol(p);
      
    p->x +=p->vx;
    p->y +=p->vy;


}






