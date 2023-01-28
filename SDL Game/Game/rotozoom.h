#ifndef rotozoom_H_INCLUDED
#define rotozoom_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct
{
  SDL_Surface *rotation;
  SDL_Surface *attention;
  SDL_Rect pos_attention;
  int sens;
  double angle;
  double zoom;

} rotozoom;

void init_rotozoom(rotozoom *roto);
void grandir(rotozoom *roto);
void update_rotozoom(rotozoom *roto, int fps, Uint32 dt);
void afficher_rotozoom(rotozoom roto, SDL_Surface *screen);




#endif
