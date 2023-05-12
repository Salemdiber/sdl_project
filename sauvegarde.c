#include "sauvegarde.h"

void saisir_nom(char * nomj)
{
    ///////////////////////////////////////////////////////////////////
     if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        printf("Can't init SDL:  %s\n", SDL_GetError());
        
    }
    
    if (TTF_Init() == -1)
    {
        printf("Can't ttf:  %s\n", SDL_GetError());
        
    }
    SDL_Surface *screen, *nom;
    SDL_Event event;
    int quit = 0;
    strcpy(nomj, "");
    SDL_Rect posnom;
    posnom.x = 100;
    posnom.y = 400;
    SDL_Color color = {255,255,255};
    TTF_Font *font = NULL;
    font = TTF_OpenFont("outils/Pixeboy.ttf", 80);
    if (font == NULL )
    printf("can't font \n");
    SDL_Surface *IMG;
    IMG=IMG_Load("start.png");

   
    //////////////////////////////////////
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL)
    {
        printf("Can't set video mode: %s\n", SDL_GetError());
    }
    while (quit == 0)
    {
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF)); /// fond blanc 
        SDL_BlitSurface(IMG,NULL,screen,NULL);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
            {
                quit = 1;
            }
            break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_RETURN) /////////////
                {
                    quit = 1;
                }
                if ((event.key.keysym.sym == SDLK_BACKSPACE) && (strlen(nomj) > 0))
                {
                    nomj[strlen(nomj) - 1] = '\0';
                }
                if (event.key.keysym.sym == SDLK_a)
                {
                    strcat(nomj, "A");
                }
                if (event.key.keysym.sym == SDLK_b)
                {
                    strcat(nomj, "B");
                }
                if (event.key.keysym.sym == SDLK_c)
                {
                    strcat(nomj, "C");
                }
                if (event.key.keysym.sym == SDLK_d)
                {
                    strcat(nomj, "D");
                }
                if (event.key.keysym.sym == SDLK_e)
                {
                    strcat(nomj, "E");
                }
                if (event.key.keysym.sym == SDLK_f)
                {
                    strcat(nomj, "F");
                }
                if (event.key.keysym.sym == SDLK_g)
                {
                    strcat(nomj, "G");
                }
                if (event.key.keysym.sym == SDLK_h)
                {
                    strcat(nomj, "H");
                }
                if (event.key.keysym.sym == SDLK_i)
                {
                    strcat(nomj, "I");
                }
                if (event.key.keysym.sym == SDLK_j)
                {
                    strcat(nomj, "J");
                }
                if (event.key.keysym.sym == SDLK_k)
                {
                    strcat(nomj, "K");
                }
                if (event.key.keysym.sym == SDLK_l)
                {
                    strcat(nomj, "L");
                }
                if (event.key.keysym.sym == SDLK_m)
                {
                    strcat(nomj, "M");
                }
                if (event.key.keysym.sym == SDLK_n)
                {
                    strcat(nomj, "N");
                }
                if (event.key.keysym.sym == SDLK_o)
                {
                    strcat(nomj, "O");
                }
                if (event.key.keysym.sym == SDLK_p)
                {
                    strcat(nomj, "P");
                }
                if (event.key.keysym.sym == SDLK_q)
                {
                    strcat(nomj, "Q");
                }
                if (event.key.keysym.sym == SDLK_r)
                {
                    strcat(nomj, "R");
                }
                if (event.key.keysym.sym == SDLK_s)
                {
                    strcat(nomj, "S");
                }
                if (event.key.keysym.sym == SDLK_t)
                {
                    strcat(nomj, "T");
                }
                if (event.key.keysym.sym == SDLK_u)
                {
                    strcat(nomj, "U");
                }
                if (event.key.keysym.sym == SDLK_v)
                {
                    strcat(nomj, "V");
                }
                if (event.key.keysym.sym == SDLK_w)
                {
                    strcat(nomj, "W");
                }
                if (event.key.keysym.sym == SDLK_x)
                {
                    strcat(nomj, "X");
                }
                if (event.key.keysym.sym == SDLK_y)
                {
                    strcat(nomj, "Y");
                }
                if (event.key.keysym.sym == SDLK_z)
                {
                    strcat(nomj, "Z");
                }
                break;
                default: 
                break;

            } // end event case
        }     // end event loop

        nom = TTF_RenderText_Blended(font, nomj, color);
        SDL_BlitSurface(nom, NULL, screen, &posnom);
        SDL_Flip(screen);
        SDL_Delay(10); /// retard 10 ms 
    }

    SDL_FreeSurface(nom);
    TTF_CloseFont(font);
    SDL_Quit();
    
}
void sauvegarder(int score, char nomj[], char nomf[])
{
    FILE * f = fopen(nomf,"a+");
    fprintf(f,"%s %d\n",nomj,score);
    fclose(f);
}
