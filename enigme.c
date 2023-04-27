#include "enigme.h"
#include "input.h"
#include <time.h>
//----------------------------Fonction init enigme-----------------------------------------
int Init_enigme(enigme *g)
{

    SDL_Rect bgpos;
    char quest1[100], choix1[100], choix2[100], win[100], lose[100], rep1[3], line[300];
    int i, j;
    FILE *fichier = NULL;
    fichier = fopen("text.txt", "r");
    i = genererEnigme();
    if (fichier != NULL)

    {

        for (j = 0; j < i + 1; j++)
        {
            fgets(line, 300, fichier);
        }

        char *token = strtok(line, " ");

        strcpy(choix1, token);
        token = strtok(NULL, " ");

        strcpy(choix2, token);
        token = strtok(NULL, " ");

        strcpy(rep1, token);
        token = strtok(NULL, " ");

        strcpy(quest1, token);
        token = strtok(NULL, " ");

        strcpy(win, token);
        token = strtok(NULL, " ");

        strcpy(lose, token);
    }

    bgpos.x = 0;
    bgpos.y = 0;
    g->pos.x = 0;
    g->pos.y = 0;
    g->enigme = IMG_Load(quest1);
    g->reponse = IMG_Load(choix1);
    g->reponse1 = IMG_Load(choix2);

    g->reponse_pos.x = 0;
    g->reponse_pos.y = 0;

    g->t = IMG_Load(win);
    g->h = IMG_Load(lose);
    strcpy(g->rep, rep1);
}

//---------------------------Fonction afficher enigme-------------------------------------------
void afficherEnigme(enigme *e)
{
    SDL_Surface *bg;
    SDL_Surface *screen;
    SDL_Surface *qst;
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("salem", NULL); // window title
    // declare simple variables
    bool running = true;
    int i;
    int yesIndex = 0, noIndex = 0;
    Input I;
    I.Return = 0;
    //----------

    // declare the event
    SDL_Event event;

    SDL_EnableKeyRepeat(200, 0);
    bg = IMG_Load("Assets/graphic/stages/oil_map1.jpg");
    int k = 2;
    while (running)
    {
        k++;
        SDL_BlitSurface(bg, NULL, screen, NULL);
        SDL_BlitSurface(e->enigme, NULL, screen, &e->pos);
        SDL_BlitSurface(e->reponse, NULL, screen, &e->reponse_pos);
        SDL_BlitSurface(e->reponse1, NULL, screen, &e->reponse_pos);
        animerEnigme(e, k);
        if (k == 10)
        {
            running = false;
            SDL_Quit();
        }
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                SDL_Quit();
                running = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_KP1:
                    if (strcmp(e->rep, "1") == 0)
                    {
                        SDL_BlitSurface(e->t, NULL, screen, &e->reponse_pos);
                        SDL_Flip(screen);
                        bg = IMG_Load("Assets/graphic/stages/oil_map1.jpg");
                        SDL_Delay(1000);
                    }
                    else
                    {
                        SDL_BlitSurface(e->h, NULL, screen, &e->reponse_pos);
                        SDL_Flip(screen);
                        bg = IMG_Load("Assets/graphic/stages/oil_map1.jpg");
                        SDL_Delay(1000);
                    }

                    break;

                case SDLK_KP2:
                    if (strcmp(e->rep, "2") == 0)
                    {
                        SDL_BlitSurface(e->t, NULL, screen, &e->reponse_pos);
                        SDL_Flip(screen);
                        SDL_Delay(1000);
                    }
                    else
                    {
                        SDL_BlitSurface(e->h, NULL, screen, &e->reponse_pos);
                        SDL_Flip(screen);
                        SDL_Delay(1000);
                    }

                    break;
                }
                break;
            }
        }

        SDL_Flip(screen);
        SDL_Delay(16);
    }
}
void animerEnigme(enigme *e, int i)
{
    char filename[50];
    sprintf(filename, "Assets/graphic/chrono/chrono%d.png", i);
    e->qst = IMG_Load(filename);
    SDL_BlitSurface(e->qst, NULL, SDL_GetVideoSurface(), &e->pos);
    SDL_Flip(SDL_GetVideoSurface());
    SDL_Delay(1000);
}
//-----------------------------------Fonction generer enigme-------------------------------------------
int genererEnigme()
{
    int i;
    srand(time(NULL));
    i = (rand() % 3);
    return i;
}
