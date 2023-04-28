#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "pers.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 400
#define SPRITE_SIZE 32

int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL;
    SDL_Surface *background_surface = NULL;
    SDL_Event event;
    Uint8 *keystates;
    int running = 1;
    personne player1, player2;

   
    SDL_Init(SDL_INIT_VIDEO);

    
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("My Game", NULL);

   
    background_surface = IMG_Load("background.png");
    if (!background_surface) {
        fprintf(stderr, "Failed to load background image: %s\n", IMG_GetError());
        exit(1);
    }

    
    initperso(&player1);
    initperso(&player2);

    while (running) {
       
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }

        
        keystates = SDL_GetKeyState(NULL);

        
        Gravite(&player1, 0.01f, 3.0f, keystates);
        if (keystates[SDLK_UP] || keystates[SDLK_z]) {
            if (player1.status == STAT_SOL)
                Saute(&player1, 14.0f);
        }
        ControleSol(&player1);
        Updateperso(&player1, keystates);

        
        keystates = SDL_GetKeyState(NULL);

        Gravite(&player2, 0.01f, 3.0f, keystates);
        if (keystates[SDLK_w]) {
            if (player2.status == STAT_SOL)
                Saute(&player2, 14.0f);
        }
        ControleSol(&player2);
        Updateperso(&player2, keystates);

        
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        
        SDL_BlitSurface(background_surface, NULL, screen, NULL);

        
        Miseajour(&player1, screen);
        afficherperso(&player1, screen);
        Miseajour(&player2, screen);
        afficherperso(&player2, screen);

        
        SDL_Flip(screen);
    }

    
    SDL_FreeSurface(background_surface);
    SDL_FreeSurface(screen);
    SDL_Quit();

    return 0;
}

