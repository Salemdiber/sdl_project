


typedef struct 
{
	SDL_Surface* image[30]; 
	SDL_Surface *background_GameOver, *background_Victory; 
	SDL_Rect PositionBackground; 
        int current_frame, previous_frame; 
	SDL_Surface *ImageOriginale, *ImageModifiee; 
	SDL_Rect PositionImageOriginale, PositionImageModifiee; 
	int ReponseCorrecte; 
	Mix_Music *musique_enigme, *musique_victoire, *musique_defaite; 
}enigme6;

void initialiserEnigme6(enigme6* e); 
void afficherEnigme6(enigme6* e, SDL_Surface* screen); 
void animerEnigme6(enigme6* e); 
void genererEnigme6(enigme6 *e); 
void freeEnigme6(enigme6* e); 
void interface_win6(SDL_Surface* screen, int* boucle, enigme6* e); 
void interface_lose6(SDL_Surface* screen, int* boucle, enigme6* e); 
int generateRandomNumber6(int min, int max); 









