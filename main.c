#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
#include "sauvegarde.h"
int main()
{ 



    char nomj[100]; // nom du joueur 
    strcpy(nomj, ""); // initialiser le nom a vide 
    saisir_nom(nomj);
    TTF_Init();
    // Declaration des variables
    SDL_Surface *screen;
    image IMAGE, IMAGE1, IMAGE2, IMAGE3, IMAGE4, IMAGE_BTN1, IMAGE_BTN2, IMAGE_BTN3, IMAGE_BTN7, IMAGE_BTN8, IMAGE_BTN9, IMAGE_BTN10, IMAGE_BTN11, IMAGE_BTN12, IMAGE_BTN13, IMAGE_BTN14, IMAGE_BTN15, IMAGE_BTN16, IMAGE_BTN17;
    image IMAGE_BTN4, IMAGE_BTN5, IMAGE_BTN6;
    Mix_Music *music;
    Mix_Chunk *mus;
    // texte txte;
    SDL_Event event;
    int boucle = 1, tt = 0, tt1 = 0, tt2 = 0;
    int detect = 0;
    int cpt = 0;
    //screen num 
    int screen_num=0; //numero switch mte3 menu = 0   ki tabda in game numero switch = 1
  
    // initialisation de la SDL

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1)
    {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        return -1;
    }
    
    // reglage de la fenetre
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    // initialisation
    //(image *imge,int x,int y,int w,int h,char emplacement[]);
    IMAGE_BTN1, IMAGE_BTN2, IMAGE_BTN3, IMAGE_BTN4, IMAGE_BTN5, IMAGE_BTN6;
    initialiser_imageBACK(&IMAGE, 0, 0, 1280, 720, "image_menu/background 1.jpg");//taswirat back 1
    initialiser_imageBACK(&IMAGE1, 0, 0, 1280, 720, "image_menu/background 2.jpg");//taswirat back 2
    initialiser_imageBACK(&IMAGE2, 0, 0, 1280, 720, "image_menu/background 3.jpg");//taswirat back 3
    initialiser_imageBACK(&IMAGE3, 0, 0, 1280, 720, "image_menu/background 4.jpg");//taswirat back 4
    initialiser_imageBACK(&IMAGE4, 0, 0, 1280, 720, "image_menu/background 5.jpg");//taswirat back 5
    initialiser_imageBOUTON(&IMAGE_BTN1, 740, 186, 320, 130, "image_menu/PLAY1.png");
    initialiser_imageBOUTON(&IMAGE_BTN2, 733, 320, 320, 130, "image_menu/SETTING1.png");
    initialiser_imageBOUTON(&IMAGE_BTN3, 740, 451, 320, 130, "image_menu/QUIT1.png");
    initialiser_imageBOUTON(&IMAGE_BTN4, 740, 186, 320, 130, "image_menu/PLAY2.png");
    initialiser_imageBOUTON(&IMAGE_BTN5, 733, 320, 320, 130, "image_menu/SETTING2.png");
    initialiser_imageBOUTON(&IMAGE_BTN6, 740, 451, 320, 130, "image_menu/QUIT2.png");

    initialiser_audio(music, "son/Cool Ringtone.mp3");
    // initialiser_audiobref(mus,"beep.wav");
    //  initialiser_texte(&txte);
    /****************/
    // boucle de menu
    /***************/
    int volume = 100;

    while (boucle)
    {
        switch(screen_num)
        {
            //case menu
            case 0:
                Mix_VolumeMusic(volume);
                afficher_image(screen, IMAGE);    // afficher l image de background
                if (cpt % 30 >= 0 && cpt % 30 < 10)//animation
                {
                    afficher_image(screen, IMAGE1);//taswirat back 2 
                }
                else if (cpt % 30 >= 10 && cpt % 30 < 15)
                {
                    afficher_image(screen, IMAGE2);//taswirat back 3
                }
                else if (cpt % 30 >= 15 && cpt % 30 < 20)
                {
                    afficher_image(screen, IMAGE3);//taswirat back 4
                }
                else
                {
                    afficher_image(screen, IMAGE4);//taswirat back 5
                }
                cpt++;  
                afficher_image(screen, IMAGE_BTN1); // afficher le bouton play
                afficher_image(screen, IMAGE_BTN2); // afficher le bouton setting
                afficher_image(screen, IMAGE_BTN3); // afficher le bouton  quit
                if (detect == 1)
                    afficher_image(screen, IMAGE_BTN4);// afficher le bouton play selectionee
                if (detect == 2)
                    afficher_image(screen, IMAGE_BTN5);// afficher le bouton setting selectionee
                if (detect == 3)
                    afficher_image(screen, IMAGE_BTN6);// afficher le bouton quit selectionee
                // afficher_texte(screen, txte);
                while (SDL_PollEvent(&event))
                {



                    switch (event.type)
                    {
                    case SDL_QUIT:
                        boucle = 0;
                        break;
                        //avec souris
                    case SDL_MOUSEBUTTONDOWN: // quitter le menu
                        if (detect == 1 || detect == 2)
                            initialiser_audiobref(mus, "son/mus.wav");
                        if (detect == 2)
                            volume = options(screen, volume);//nod5el lel option ki neclique ala setting b souris
                        if (detect == 1)
                            screen_num=1;
                            //volume = play(screen, volume);//nod5el lel option ki neclique ala play b souris
                        if (detect == 3)
                            boucle = 0; //ki neclique 3ala quit no5rej ml jeu
                        break;
                        //avec clavier
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_RETURN) // entrer
                        {
                            if (detect == 1 || detect == 2)
                                initialiser_audiobref(mus, "son/mus.wav");
                            if (detect == 1)
                                screen_num=1;
                                //volume = play(screen, volume); // ki necliquer entrer w ani play da5elner lel play

                            if (detect == 2)
                                volume = options(screen, volume); // ki necliquer entrer w ani option da5elner lel option
                            if (detect == 3)
                                boucle = 0; // ki necliquer entrer w ani quit no5rej ml jeu
                        }
                        if (event.key.keysym.sym == SDLK_p)// p t3 el clavier
                        {
                            detect = 1;
                            initialiser_audiobref(mus, "son/mus.wav");
                            screen_num=1;
                            //volume = play(screen, volume);//ki necliquer 3ala p nod5el lel play
                        }
                        else if (event.key.keysym.sym == SDLK_ESCAPE)
                        {
                            boucle = 0;//no5rej ml jeu
                        }
                        else if (event.key.keysym.sym == SDLK_s)//s t3 clavier
                        {
                            detect = 2;
                            initialiser_audiobref(mus, "mus.wav");
                            SDL_Event mouseEvent;
                            mouseEvent.type = SDL_MOUSEBUTTONDOWN;
                            mouseEvent.button.button = SDL_BUTTON_LEFT;
                            SDL_PushEvent(&mouseEvent);
                        }//nod5el lel setting 

                        else if (event.key.keysym.sym == SDLK_UP) // flech fou9eni
                        {
                            if (detect == 0)
                            {
                                detect = 3; // button quit selectionee
                            }

                            else if (detect == 3)
                            {
                                detect = 2; // button setting selectionee
                            }
                            else if (detect == 2)
                            {
                                detect = 1; // button play selectionee
                            }
                            else
                                detect = 0;
                        }

                        else if (event.key.keysym.sym == SDLK_DOWN) // flech loutani
                        {
                            if (detect == 0)
                            {
                                detect = 1; // button play selectionnee
                            }

                            else if (detect == 1)
                            {
                                detect = 2; // button setting selectionnee
                            }
                            else if (detect == 2)
                            {
                                detect = 3; // button quit selectionnee
                            }
                            else
                                detect = 0;
                        }

                        break;
                        //avec souris
                    case SDL_MOUSEMOTION:
                        if ((event.motion.x > IMAGE_BTN1.pos_img_ecran.x) && (event.motion.x < IMAGE_BTN1.pos_img_ecran.x + 340) && (event.motion.y > IMAGE_BTN1.pos_img_ecran.y) && (event.motion.y < IMAGE_BTN1.pos_img_ecran.y + 130))
                        {
                            detect = 1;//button play selecctionnee
                        }

                        else if ((event.motion.x > IMAGE_BTN2.pos_img_ecran.x) && (event.motion.x < IMAGE_BTN2.pos_img_ecran.x + 340) && (event.motion.y > IMAGE_BTN2.pos_img_ecran.y) && (event.motion.y < IMAGE_BTN2.pos_img_ecran.y + 130))
                        {
                            detect = 2;//button setting selecctionnee
                        }
                        else if ((event.motion.x > IMAGE_BTN3.pos_img_ecran.x) && (event.motion.x < IMAGE_BTN3.pos_img_ecran.x + 340) && (event.motion.y > IMAGE_BTN3.pos_img_ecran.y) && (event.motion.y < IMAGE_BTN3.pos_img_ecran.y + 130))
                        {
                            detect = 3;//button quit selecctionnee
                        }
                        else
                            detect = 0;
                    break;
             }   
                }   
              SDL_Flip(screen); // reffraichir l ecran
                // SDL_Delay(5000);
            break;
            //in game 
            case 1:
                screen_num=0;
                detect=0;  
                if(play(screen, volume)==1)
                {
                    screen_num=2;
                }

            break;
            case 2:
                screen_num=2;
                detect=0;
                
                if(play_level2(screen, volume)==2)
                {
                    screen_num=1;
                }
                else 
                    screen_num=0;
                 
                printf("alooo\n");
                //SDL_Quit();
            break;
        }
        
    }
    sauvegarder(SDL_GetTicks(),nomj,"fichier");
    // liberer les surfaces
    liberer_image(IMAGE);
    liberer_image(IMAGE_BTN1);
    liberer_image(IMAGE_BTN2);
    liberer_image(IMAGE_BTN3);
    liberer_image(IMAGE_BTN4);
    liberer_image(IMAGE_BTN5);
    liberer_image(IMAGE_BTN6);

    // liberer la musique
    liberer_musique(music);
    liberer_musiquebref(mus);
    // liberer texte
    // liberer_texte(txte);
    // quitter SDL
    SDL_Quit();
    return 0;
}
