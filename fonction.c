#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
#include "input.h"
#include "player.h"
#include "background.h"
#include "minimap.h"
#include "temps.h"
#include "enigme.h"
#include "enigme6.h"
#include "enemy.h"
#include <time.h>
#include "sauv.h"


// ****** traitement des images******/////
void initialiser_imageBACK(image *imge, int x, int y, int w, int h, char emplacement[])
{
    //  changement de l image
    imge->url = emplacement;
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("unable to load background image %s \n", SDL_GetError());
        return;
    }

    imge->pos_img_ecran.x = x;
    imge->pos_img_ecran.y = y;

    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = h;
    imge->pos_img_affiche.w = w;
}

void initialiser_imageBOUTON(image *imge, int x, int y, int w, int h, char emplacement[])
{
    // chargement de l image
    imge->url = emplacement;
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("unable to load bouton image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_ecran.x = x;
    imge->pos_img_ecran.y = y;

    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = h;
    imge->pos_img_affiche.w = w;
}
void initialiser_imageBOUTON_OP(image *imge, int x, int y, int w, int h, char emplacement[])
{
    // chargement de l image
    imge->url = emplacement;
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("unable to load bouton image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_ecran.x = x;
    imge->pos_img_ecran.y = y;

    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = h;
    imge->pos_img_affiche.w = w;
}

void afficher_image(SDL_Surface *screen, image imge)
{
    // Coller et afficher l image de back dans screen
    SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void afficher_imageBTN(SDL_Surface *screen, image imge)
{
    // Coller et Afficher 1'image du btn play dans screen
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}
void afficher_imageBTN_OP(SDL_Surface *screen, image imge)
{
    // Coller et Afficher 1'image du btn play dans screen
    SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void liberer_image(image imge)
{
    SDL_FreeSurface(imge.img);
}
/********************************
****** *TRAITEMENT MUSIQUE* ******/

void initialiser_audio(Mix_Music *music, char emplacement[])
{
    // initialiser les fonction audio de SDL mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1)
    {
        printf("%s", SDL_GetError());
    }
    music = Mix_LoadMUS(emplacement); // chargement de la musique
    Mix_PlayMusic(music, -1);         // jouer la musique
    Mix_VolumeMusic(100);
}

void liberer_musique(Mix_Music *music)
{
    Mix_FreeMusic(music);
}

void initialiser_audiobref(Mix_Chunk *music, char emplacement[])
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1)
    {
        printf("%s", SDL_GetError());
    }
    music = Mix_LoadWAV(emplacement);
    Mix_PlayChannel(-1, music, 0);
    if (music == NULL)
        printf("%s\n", SDL_GetError());
}

void liberer_musiquebref(Mix_Chunk *music)
{
    Mix_FreeChunk(music);
}

int options(SDL_Surface *screen, int volume)
{
    image IMAGE_BTN7, IMAGE_BTN8, IMAGE_BTN9, IMAGE_BTN10, IMAGE_BTN11, IMAGE_BTN12, IMAGE_BTN13, IMAGE_BTN14, IMAGE_BTN15, IMAGE_BTN16, IMAGE_BTN17, IMAGE_BTN1;
    image IMAGE;
    SDL_Event event;
    initialiser_imageBACK(&IMAGE, 0, 0, 1280, 720, "image_menu/menu background 2.jpg");
    initialiser_imageBOUTON_OP(&IMAGE_BTN7, 450, 250, 320, 130, "image_menu/MoinsBoutton.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN8, 700, 250, 320, 130, "image_menu/PlusBoutton.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN9, 574, 177, 320, 130, "image_menu/zero.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN10, 574, 177, 320, 130, "image_menu/vingtcinq.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN11, 574, 177, 320, 130, "image_menu/cinquante.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN12, 574, 177, 320, 130, "image_menu/soixanteQuinze.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN13, 574, 177, 320, 130, "image_menu/cent.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN14, 665, 325, 320, 130, "image_menu/full screen 1.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN15, 665, 325, 320, 130, "image_menu/full screen 2.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN16, 400, 325, 320, 130, "image_menu/windowed1.png");
    initialiser_imageBOUTON_OP(&IMAGE_BTN17, 400, 325, 320, 130, "image_menu/windowed.png");
    int boucle = 1;
    int detecte = 0;
    while (boucle)
    {
        afficher_image(screen, IMAGE);            // twarili back ta3 option
        afficher_imageBTN_OP(screen, IMAGE_BTN7); // button -
        afficher_imageBTN_OP(screen, IMAGE_BTN8); // button +
        if (volume == 0)
            afficher_imageBTN_OP(screen, IMAGE_BTN9); // image t3 volume=0
        if (volume == 25)
            afficher_imageBTN_OP(screen, IMAGE_BTN10); // image t3 volume=25
        if (volume == 50)
            afficher_imageBTN_OP(screen, IMAGE_BTN11); // image t3 volume=50
        if (volume == 75)
            afficher_imageBTN_OP(screen, IMAGE_BTN12); // image t3 volume=75
        if (volume == 100)
            afficher_imageBTN_OP(screen, IMAGE_BTN13); // image t3 volume=100

        afficher_imageBTN_OP(screen, IMAGE_BTN15); // full screen non cliquee
        if (detecte == 1)
            afficher_imageBTN_OP(screen, IMAGE_BTN14); // full screen  cliquee
        afficher_imageBTN_OP(screen, IMAGE_BTN17);     // window non cliquee
        if (detecte == 2)
            afficher_imageBTN_OP(screen, IMAGE_BTN16); // window cliquee

        Mix_VolumeMusic(volume);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                boucle = 0;
                break;
                //avec souris
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    int x = event.button.x;
                    int y = event.button.y;

                    if (x >= IMAGE_BTN7.pos_img_ecran.x && x <= IMAGE_BTN7.pos_img_ecran.x + IMAGE_BTN7.pos_img_affiche.w && y >= IMAGE_BTN7.pos_img_ecran.y && y <= IMAGE_BTN7.pos_img_ecran.y + IMAGE_BTN7.pos_img_affiche.h)
                    {

                        volume -= 25;//if je clique sur le bouton 7"-" el sot yan9ess
                        if (volume <= 0)
                            volume = 0;
                        Mix_VolumeMusic(volume);
                    }
                    if (x >= IMAGE_BTN8.pos_img_ecran.x && x <= IMAGE_BTN8.pos_img_ecran.x + IMAGE_BTN8.pos_img_affiche.w && y >= IMAGE_BTN8.pos_img_ecran.y && y <= IMAGE_BTN8.pos_img_ecran.y + IMAGE_BTN8.pos_img_affiche.h)
                    {

                        volume += 25;//if je clique sur le bouton 8 "+"el sot yzid
                        if (volume >= 100)
                            volume = 100;
                        Mix_VolumeMusic(volume);
                    }
                    if (x >= IMAGE_BTN15.pos_img_ecran.x && x <= IMAGE_BTN15.pos_img_ecran.x + IMAGE_BTN15.pos_img_affiche.w && y >= IMAGE_BTN15.pos_img_ecran.y && y <= IMAGE_BTN15.pos_img_ecran.y + IMAGE_BTN15.pos_img_affiche.h)
                    {
                        SDL_WM_ToggleFullScreen(screen);//e4a necliqué 3la el bouton 15 twali full screen
                        detecte = 1;
                    }
                    if (x >= IMAGE_BTN17.pos_img_ecran.x && x <= IMAGE_BTN17.pos_img_ecran.x + IMAGE_BTN17.pos_img_affiche.w && y >= IMAGE_BTN17.pos_img_ecran.y && y <= IMAGE_BTN17.pos_img_ecran.y + IMAGE_BTN17.pos_img_affiche.h)
                    {
                        screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);//e4a necliqué 3la el bouton 17 twali window
                        detecte = 2;
                    }
                }
                break;
                //avec souris
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_KP_PLUS:
                    volume += 25;
                    if (volume >= 100) // kif ywalli akber ml 100 ya7bess f 100
                        volume = 100;
                    Mix_VolumeMusic(volume);
                    break;
                case SDLK_KP_MINUS:
                    volume -= 25;    // nakes f sout bl -
                    if (volume <= 0) // kif ywalli as8er ml 0 ya7bess f 0
                        volume = 0;
                    Mix_VolumeMusic(volume);
                    break;
                case SDLK_ESCAPE:
                    boucle = 0;
                    break;
                case SDLK_f:
                    SDL_WM_ToggleFullScreen(screen);//ttwali full screen ki necliqué 3la f
                    detecte = 1;
                    break;
                case SDLK_w:
                    screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);//ttwali window ki necliqué 3la w
                    detecte = 2;
                    break;
                }
                break;
            }
        }
        SDL_Flip(screen);// reffraichir l ecran
    }
    liberer_image(IMAGE);
    liberer_image(IMAGE_BTN7);
    liberer_image(IMAGE_BTN8);
    liberer_image(IMAGE_BTN9);
    liberer_image(IMAGE_BTN10);
    liberer_image(IMAGE_BTN11);
    liberer_image(IMAGE_BTN12);
    liberer_image(IMAGE_BTN13);
    liberer_image(IMAGE_BTN14);
    liberer_image(IMAGE_BTN15);
    liberer_image(IMAGE_BTN16);
    liberer_image(IMAGE_BTN17);
    return volume;
}


int play(SDL_Surface *screen, int volume)
{
    TTF_Init();
    int c=0;
    Uint32 dt, t_prev;
    image IMAGE;
    background back;
    minimap m;
    ennemi enemy;
    enigme e;
    temps t;
    SDL_Event event;
 initBack(&back);
 //initialiser_imageBACK(&IMAGE, 0, 0, 1280, 720, "image_level/level2.png");
 Hero hero;
    Input I;
    init_hero(&hero);
    init_input(&I);

Hero hero2;
    Input I2;
    init_hero2(&hero2);
    init_input(&I2);

    initEnnemi(&enemy);
    init_map(&m);
    initialiser_temps(&t);
     charger(&hero,&back,"test.txt");
    // charger(&hero2,&back,"test.txt");
int boucle =1; 
while (boucle)
{
    t_prev = SDL_GetTicks();
   //afficher_image(screen,IMAGE);
   afficherBack(back,screen);
   afficher_Hero(hero,screen);
   afficher_Hero(hero2,screen);
   afficher_temps(&t, screen);
   
   if(enemy.nb_vie>0)
   afficherEnnemi(enemy,screen);  // temps.c
   afficherminimap(m,back, screen);

   SDL_Flip(screen);


   while (SDL_PollEvent(&event))
   {
    switch (event.type)
    {
    case  SDL_QUIT : 
    boucle = 0 ;
        break;
    
    default:
        break;
        //avec souris
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
    {
        case SDLK_ESCAPE :
        boucle = 0 ; //ki necliquee escape traje3ni lel menu
        break ; 
            case SDLK_UP:
                I.jump = 1;
            break;
            case SDLK_RIGHT:
                I.right = 1;
                hero.direction=1;
                
             break;
            case SDLK_LEFT:
              I.left = 1;
              hero.direction=-1;
              
             break;
            case SDLK_x :
                I.attack = 1;
                
            break;
		 case SDLK_z:
                            I2.jump = 1;// Activer le saut
				//I2.jump = 1;
                        break;	
                     case SDLK_d:
                            I2.right = 1;// Activer le déplacement à droite
                            hero2.direction=1;// Changer la direction du personnage
                            
                         break;

                        case SDLK_q:
                          I2.left = 1;//Activer le déplacement à gauche
                          hero2.direction=-1;// Changer la direction du personnage
                          
                         break;
                        case SDLK_a :
                            I2.attack = 1; //Activer l'attaque
                            printf("%d",I2.attack);
                        break;
        }
        
    break;
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
             /*case SDLK_SPACE:
             I.jump = 0;
                break;*/
            case SDLK_RIGHT:
                I.right = 0;
                hero.last_direction=1;
                if(I.left == 1)
                hero.direction=-1;
                break;
            case SDLK_LEFT:
                I.left = 0;
                hero.last_direction=-1;
                
                if(I.right == 1)
                hero.direction=1;
                break;
	case SDLK_d:
                            I2.right = 0;// Désactiver le déplacement à droite
                            hero2.last_direction=1;// Sauvegarder la dernière direction
                            // Si le joueur se déplace à gauche, changer la direction
                            if(I2.left == 1)
                            hero2.direction=-1;


                            break;

                        case SDLK_q:
                            I2.left = 0;// Désactiver le déplacement à gauche
                            hero2.last_direction=-1;// Sauvegarder la dernière direction

                            
                            if(I2.right == 1)   // Si le joueur se déplace à droite, changer la dir
                            hero2.direction=1;

                            break;
                        
            
    }
    break;
    }
   }
   dt = (SDL_GetTicks()/10) - (t_prev/10);
           // update caractere position and animation 
        if(I.right == 0 && I.left == 0)
        {
            hero.direction=0;
        }
	
        if(hero.direction ==0)
        {
        idleAnimation(&hero);           
        }


        else if((hero.direction ==1 || hero.direction ==-1)&& I.jump==0 && I.attack ==0)
        {
        runAnimation(&hero);
        }
        else if((hero.direction ==1 || hero.direction ==-1)&& I.jump==1 && I.attack ==0)
        {
            jumpAnimation(&hero);
        }
        if(I.attack==1)
        {
            attackAnimation(&hero,&I);
        }

        hero.col_gauche=collisionPP_gauche(back.calque_background,hero.allMvt,hero.heroPos,back.pos_background2);
        hero.col_droite=collisionPP_droite(back.calque_background,hero.allMvt,hero.heroPos,back.pos_background2);
        if((back.pos_background2.x==0 || back.pos_background2.x==6400-1280))
        {
            if((hero.heroPos.x>=10 && I.left==1)|| (hero.heroPos.x<=1250 && I.right==1) )
            {

                
                leftAndRightHeroMvtR(&hero, I, dt);
            }
            
           
        }
        hero.col_bas=collisionPP(back.calque_background,hero.allMvt,hero.heroPos,back.pos_background2);
        
        jumpHeroMvt(&hero, &I);
        
        scrolling(&hero,&back,hero.col_bas);



        MAJMinimap(hero.heroPos, &m, back.pos_background2, 20); // mise a jour minimap.c
        if(back.pos_background2.x>=6400-1500)
        {
            Init_enigme(&e);
            if(afficherEnigme(&e)==1)
            {
                return 1;
            } 
            else{
                back.pos_background2.x=0;
	            back.pos_background2.y=0;
                I.left = 0;
                I.right = 0;
                I.down = 0;
                I.jump = 0;
                I.attack = 0;
                I.e = 0;
            }   
        }
        if(enemy.nb_vie>0){
        move(&enemy,back.pos_background2.x);
        animerEnnemi(&enemy);
        }
        else
        {
            enemy.posScreen.x=1400;
            enemy.nb_vie=100;
            
        }
        if(collisionBB(hero.heroPos,enemy.posScreen)==1 && I.attack==1)
        {
            enemy.nb_vie-=10;
            enemy.posScreen.x+=20;
        }
        if(hero.heroPos.x+132>enemy.posinit && hero.heroPos.x<enemy.posfinal && hero.heroPos.y>470)
        {
            enemy.mode_attack=1;
        }
        else
        {
            enemy.mode_attack=0;
        }
        if(enemy.posScreen.x>hero.heroPos.x && enemy.mode_attack==1)
            {
                enemy.direction_x=-1;
                enemy.posSprite.y=689;
                enemy.posScreen.x += enemy.speed * enemy.direction_x;

            }
            else if(enemy.posScreen.x<hero.heroPos.x && enemy.mode_attack==1) {
                enemy.direction_x=1;
                enemy.posSprite.y=800;
                enemy.posScreen.x += enemy.speed * enemy.direction_x;
            }

        

        hero.frame++;









/****************************************************************/

  if(I2.right == 0 && I2.left == 0)
        {
            hero2.direction=0;
        }
	
	
        if(hero2.direction ==0)
        {
        idleAnimation(&hero2);           
        }


        else if((hero2.direction ==1 || hero2.direction ==-1)&& I2.jump==0 && I2.attack ==0)
        {
        runAnimation(&hero2);
        }
        else if((hero2.direction ==1 || hero2.direction ==-1)&& I2.jump==1 && I2.attack ==0)
        {
            jumpAnimation(&hero2);
        }
        if(I2.attack==1)
        {
            attackAnimation(&hero2,&I2);
        }

        hero2.col_gauche=collisionPP_gauche(back.calque_background,hero2.allMvt,hero2.heroPos,back.pos_background2);
        hero2.col_droite=collisionPP_droite(back.calque_background,hero2.allMvt,hero2.heroPos,back.pos_background2);
        if((back.pos_background2.x==0 || back.pos_background2.x==6400-1280))
        {
            if((hero2.heroPos.x>=10 && I2.left==1)|| (hero2.heroPos.x<=1250 && I2.right==1) )
            {

                
                leftAndRightHeroMvtR(&hero2, I2, dt);
            }
            
           
        }
        hero2.col_bas=collisionPP(back.calque_background,hero2.allMvt,hero2.heroPos,back.pos_background2);
        
        jumpHeroMvt(&hero2, &I2);
        
        scrolling(&hero2,&back,hero2.col_bas);



        MAJMinimap(hero2.heroPos, &m, back.pos_background2, 20); // mise a jour minimap.c
        if(back.pos_background2.x>=6400-1500)
        {
            Init_enigme(&e);
            if(afficherEnigme(&e)==1)
            {
                return 1;
            } 
            else{
                back.pos_background2.x=0;
	            back.pos_background2.y=0;
                I2.left = 0;
                I2.right = 0;
                I2.down = 0;
                I2.jump = 0;
                I2.attack = 0;
                I2.e = 0;
            }   
        }
        if(enemy.nb_vie>0){
        move(&enemy,back.pos_background2.x);
        animerEnnemi(&enemy);
        }
        else
        {
            enemy.posScreen.x=1400;
            enemy.nb_vie=100;
            
        }
        if(collisionBB(hero2.heroPos,enemy.posScreen)==1 && I2.attack==1)
        {
            enemy.nb_vie-=10;
            enemy.posScreen.x+=20;
        }
        if(hero2.heroPos.x+132>enemy.posinit && hero2.heroPos.x<enemy.posfinal && hero2.heroPos.y>470)
        {
            enemy.mode_attack=1;
        }
        else
        {
            enemy.mode_attack=0;
        }
        if(enemy.posScreen.x>hero2.heroPos.x && enemy.mode_attack==1)
            {
                enemy.direction_x=-1;
                enemy.posSprite.y=689;
                enemy.posScreen.x += enemy.speed * enemy.direction_x;

            }
            else if(enemy.posScreen.x<hero2.heroPos.x && enemy.mode_attack==1) {
                enemy.direction_x=1;
                enemy.posSprite.y=800;
                enemy.posScreen.x += enemy.speed * enemy.direction_x;
            }

        

        hero.frame++;
        hero2.frame++;















/**********************************************************************/
   
}
sauvegarderpos(hero,back,"test.txt");
if(boucle==2)
return 2 ;
if(boucle==0)
return 0 ; 
}


/*int play_level2(SDL_Surface *screen, int volume)
{
    TTF_Init();
    int c=0;
    Uint32 dt, t_prev;
    image IMAGE;
    background back;
    minimap m;
    ennemi enemy;
    enigme e;
    temps t;
    SDL_Event event;
 initBack2(&back);
 //initialiser_imageBACK(&IMAGE, 0, 0, 1280, 720, "image_level/level2.png");
 Hero hero;
    Input I;
    init_hero(&hero);
    init_input(&I);
    init_map2(&m);
    initEnnemi(&enemy);
    initialiser_temps(&t);
    
int boucle =1; 
while (boucle)
{
    t_prev = SDL_GetTicks();
   //afficher_image(screen,IMAGE);
   afficherBack(back,screen);
   afficher_Hero(hero,screen);
   afficher_temps(&t, screen);
   if(enemy.nb_vie>0)
   afficherEnnemi(enemy,screen); // temps.c
   afficherminimap2(m,back, screen);
   SDL_Flip(screen);


   while (SDL_PollEvent(&event))
   {
    switch (event.type)
    {
    case  SDL_QUIT : 
    boucle = 0 ;
        break;
    
    default:
        break;
        //avec souris
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
    {
        case SDLK_p:
             enemy.nb_vie-=50;
        break;
        case SDLK_ESCAPE :
        boucle = 0 ; //ki necliquee escape traje3ni lel menu
        break ; 
            case SDLK_SPACE:
                I.jump = 1;
            break;
            case SDLK_RIGHT:
                I.right = 1;
                hero.direction=1;
                
             break;
            case SDLK_LEFT:
              I.left = 1;
              hero.direction=-1;
              
             break;
            case SDLK_x :
                I.attack = 1;

            break;
        }
    break;
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
             
            case SDLK_RIGHT:
                I.right = 0;
                hero.last_direction=1;
                if(I.left == 1)
                hero.direction=-1;
                break;
            case SDLK_LEFT:
                I.left = 0;
                hero.last_direction=-1;
                
                if(I.right == 1)
                hero.direction=1;
                break;
            
    }
    break;
    }
   }
   dt = (SDL_GetTicks()/10) - (t_prev/10);
           // update caractere position and animation 
        if(I.right == 0 && I.left == 0)
        {
            hero.direction=0;
        }
        if(hero.direction ==0)
        {
        idleAnimation(&hero);           
        }


        else if((hero.direction ==1 || hero.direction ==-1)&& I.jump==0 && I.attack ==0)
        {
        runAnimation(&hero);
        }
        else if((hero.direction ==1 || hero.direction ==-1)&& I.jump==1 && I.attack ==0)
        {
            jumpAnimation(&hero);
        }
        if(I.attack==1)
        {
            attackAnimation(&hero,&I);
        }

        hero.col_gauche=collisionPP_gauche(back.calque_background,hero.allMvt,hero.heroPos,back.pos_background2);
        hero.col_droite=collisionPP_droite(back.calque_background,hero.allMvt,hero.heroPos,back.pos_background2);
        if((back.pos_background2.x==0 || back.pos_background2.x==6400-1280))
        {
            if((hero.heroPos.x>=10 && I.left==1)|| (hero.heroPos.x<=1250 && I.right==1) )
            {

                
                leftAndRightHeroMvtR(&hero, I, dt);
            }
            
           
        }
        hero.col_bas=collisionPP(back.calque_background,hero.allMvt,hero.heroPos,back.pos_background2);
        
        jumpHeroMvt(&hero, &I);
        
        scrolling(&hero,&back,hero.col_bas);



        MAJMinimap2(hero.heroPos, &m, back.pos_background2, 20); // mise a jour minimap.c

        if(back.pos_background2.x>=2470)
        {
            Init_enigme(&e);
            if(afficherEnigme(&e)==1)
            {
                return 1;
            } 
            else{
                back.pos_background2.x=0;
	            back.pos_background2.y=0;
                I.left = 0;
                I.right = 0;
                I.down = 0;
                I.jump = 0;
            }   
        }
        if(enemy.nb_vie>0){
        move(&enemy,back.pos_background2.x);
        animerEnnemi(&enemy);
        }
        else
        {
            enemy.posScreen.x=1400;
            enemy.nb_vie=100;
            
        }
        if(collisionBB(hero.heroPos,enemy.posScreen)==1 && I.attack==1)
        {
            enemy.nb_vie-=10;
            enemy.posScreen.x+=20;
        }
        if(hero.heroPos.x+132>enemy.posinit && hero.heroPos.x<enemy.posfinal && hero.heroPos.y>470)
        {
            enemy.mode_attack=1;
        }
        else
        {
            enemy.mode_attack=0;
        }
        if(enemy.posScreen.x>hero.heroPos.x && enemy.mode_attack==1)
            {
                enemy.direction_x=-1;
                enemy.posSprite.y=689;
                enemy.posScreen.x += enemy.speed * enemy.direction_x;

            }
            else if(enemy.posScreen.x<hero.heroPos.x && enemy.mode_attack==1) {
                enemy.direction_x=1;
                enemy.posSprite.y=800;
                enemy.posScreen.x += enemy.speed * enemy.direction_x;
            }


        

        hero.frame++;
   
}
if(boucle==2)
return 2 ;
if(boucle==0)
return 0 ; 
}*/


int play_level2(SDL_Surface *screen, int volume)
{
    TTF_Init();
    int c=0;
    Uint32 dt, t_prev;
    image IMAGE;
    background back;
    minimap m;
    ennemi enemy;
    enigme6* e;
    temps t;
    SDL_Event event;
    int interface=4;
    int loop=1;
 initBack2(&back);
 //initialiser_imageBACK(&IMAGE, 0, 0, 1280, 720, "image_level/level2.png");
 Hero hero;
    Input I;
    init_hero(&hero);
    init_input(&I);
    init_map2(&m);
    initEnnemi(&enemy);
    initialiser_temps(&t);
   //charger(&hero,&back,"stage2.txt");
    
int boucle =1; 
while (boucle)
{
    t_prev = SDL_GetTicks();
   //afficher_image(screen,IMAGE);
   afficherBack(back,screen);
   afficher_Hero(hero,screen);
   afficher_temps(&t, screen);
   if(enemy.nb_vie>0)
   afficherEnnemi(enemy,screen); // temps.c
   afficherminimap2(m,back, screen);
   SDL_Flip(screen);


   while (SDL_PollEvent(&event))
   {
    switch (event.type)
    {
    case  SDL_QUIT : 
    boucle = 0 ;
        break;
    
    default:
        break;
        //avec souris
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
    {
        case SDLK_p:
             enemy.nb_vie-=50;
        break;
        case SDLK_ESCAPE :
        boucle = 0 ; //ki necliquee escape traje3ni lel menu
        break ; 
            case SDLK_SPACE:
                I.jump = 1;
            break;
            case SDLK_RIGHT:
                I.right = 1;
                hero.direction=1;
                
             break;
            case SDLK_LEFT:
              I.left = 1;
              hero.direction=-1;
              
             break;
            case SDLK_x :
                I.attack = 1;

            break;
        }
    break;
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
             
            case SDLK_RIGHT:
                I.right = 0;
                hero.last_direction=1;
                if(I.left == 1)
                hero.direction=-1;
                break;
            case SDLK_LEFT:
                I.left = 0;
                hero.last_direction=-1;
                
                if(I.right == 1)
                hero.direction=1;
                break;
            
    }
    break;
    }
   }
   dt = (SDL_GetTicks()/10) - (t_prev/10);
           // update caractere position and animation 
        if(I.right == 0 && I.left == 0)
        {
            hero.direction=0;
        }
        if(hero.direction ==0)
        {
        idleAnimation(&hero);           
        }


        else if((hero.direction ==1 || hero.direction ==-1)&& I.jump==0 && I.attack ==0)
        {
        runAnimation(&hero);
        }
        else if((hero.direction ==1 || hero.direction ==-1)&& I.jump==1 && I.attack ==0)
        {
            jumpAnimation(&hero);
        }
        if(I.attack==1)
        {
            attackAnimation(&hero,&I);
        }

        hero.col_gauche=collisionPP_gauche(back.calque_background,hero.allMvt,hero.heroPos,back.pos_background2);
        hero.col_droite=collisionPP_droite(back.calque_background,hero.allMvt,hero.heroPos,back.pos_background2);
        if((back.pos_background2.x==0 || back.pos_background2.x==6400-1280))
        {
            if((hero.heroPos.x>=10 && I.left==1)|| (hero.heroPos.x<=1250 && I.right==1) )
            {

                
                leftAndRightHeroMvtR(&hero, I, dt);
            }
            
           
        }
        hero.col_bas=collisionPP(back.calque_background,hero.allMvt,hero.heroPos,back.pos_background2);
        
        jumpHeroMvt(&hero, &I);
        
        scrolling(&hero,&back,hero.col_bas);



        MAJMinimap2(hero.heroPos, &m, back.pos_background2, 20); // mise a jour minimap.c

        if(back.pos_background2.x>=2470)
        {
            e = calloc(1, sizeof(enigme6));



            initialiserEnigme6(e);
	        genererEnigme6(e);
            loop==1;
            while (loop==1)
	{
                if(interface==4) 
                { 
			animerEnigme6(e);
			afficherEnigme6(e,screen);
                }
		if(interface==5) 
		{
			interface_win6(screen,&loop,e);
            freeEnigme6(e);
            free(e);
            if(loop==0)
            return 1 ;
		}
		if(interface==6) 
		{
			interface_lose6(screen,&loop,e);
            back.pos_background2.x=0;
	            back.pos_background2.y=0;
                I.left = 0;
                I.right = 0;
                I.down = 0;
                I.jump = 0;
                interface=4;
            freeEnigme6(e);
            free(e);
            return 2;
		}

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT :
					loop = 0;
					break;
				case SDL_KEYDOWN:
				{
					switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE :
							loop = 0;
							break;
						case SDLK_KP0 :
							if (e->ReponseCorrecte==0) interface=5;
							else interface=6;
							break;
						case SDLK_KP1 :
							if (e->ReponseCorrecte==1) interface=5;
							else interface=6;
							break;
						case SDLK_KP2 :
							if (e->ReponseCorrecte==2) interface=5;
							else interface=6;
							break;
						case SDLK_KP3 :
							if (e->ReponseCorrecte==3) interface=5;
							else interface=6;
							break;
						case SDLK_KP4 :
							if (e->ReponseCorrecte==4) interface=5;
							else interface=6;
							break;
						case SDLK_KP5 :
							if (e->ReponseCorrecte==5) interface=5;
							else interface=6;
							break;
						case SDLK_KP6:
							if (e->ReponseCorrecte==6) interface=5;
							else interface=6;
							break;
						case SDLK_KP7 :
							if (e->ReponseCorrecte==7) interface=5;
							else interface=6;
							break;
						case SDLK_KP8 :
							if (e->ReponseCorrecte==8) interface=5;
							else interface=6;
							break;
						case SDLK_KP9 :
							if (e->ReponseCorrecte==9) interface=5;
							else interface=6;
							break;
						
					}

				}
			} 
                }
		SDL_Flip(screen);
		SDL_Delay(40);
	}
      
        }

        if(enemy.nb_vie>0){
        move(&enemy,back.pos_background2.x);
        animerEnnemi(&enemy);
        }
        else
        {
            enemy.posScreen.x=1400;
            enemy.nb_vie=100;
            
        }
        if(collisionBB(hero.heroPos,enemy.posScreen)==1 && I.attack==1)
        {
            enemy.nb_vie-=10;
            enemy.posScreen.x+=20;
        }
        if(hero.heroPos.x+132>enemy.posinit && hero.heroPos.x<enemy.posfinal && hero.heroPos.y>470)
        {
            enemy.mode_attack=1;
        }
        else
        {
            enemy.mode_attack=0;
        }
        if(enemy.posScreen.x>hero.heroPos.x && enemy.mode_attack==1)
            {
                enemy.direction_x=-1;
                enemy.posSprite.y=689;
                enemy.posScreen.x += enemy.speed * enemy.direction_x;

            }
            else if(enemy.posScreen.x<hero.heroPos.x && enemy.mode_attack==1) {
                enemy.direction_x=1;
                enemy.posSprite.y=800;
                enemy.posScreen.x += enemy.speed * enemy.direction_x;
            }


        

        hero.frame++;
        /*if(loop==0)
        {
            boucle=0;
        }*/
   
}
//sauvegarderpos(hero,back,"stage2.txt");
if(loop==0)
return 1 ;
if(boucle==0)
return 0 ; 
}
