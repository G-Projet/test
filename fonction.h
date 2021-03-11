
  
typedef enum bool_t{FALSE,TRUE=-1}bool;

extern void bienvenus();

extern void sdl_init(bool* const error, int (*sdlInit)(int*));

extern char message_erreurs();

extern void arret_programme(SDL_Surface* image,SDL_Renderer* renderer,SDL_Window * window);

extern
void clean_ressources(SDL_Window*w, SDL_Renderer *r, SDL_Texture *t);