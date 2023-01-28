#ifndef back_H_INCLUDED
#define back_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "entite.h"

typedef struct {
SDL_Surface *back ;

SDL_Rect back_pos;

SDL_Rect camera ; //t9os partie ml background w t7otha fl fenetre
}background ;
void initialiser_back (background *b, int ord) ;
int scrol_right(background *b, SDL_Surface *screen, entite *e,perso *p);
int scrol_left(background *b, SDL_Surface *screen, entite *e, perso *p);
void affiche_back(background *b, SDL_Surface *screen);
void scrol_right2(background *b, SDL_Surface *screen);
void scrol_left2(background *b, SDL_Surface *screen);



#endif
