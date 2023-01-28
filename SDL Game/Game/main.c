#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

#include"menu.h"
#include"st1.h"

#include "enigme.h"


int nb_enigme=4;



int main()
{
    int hauteur_fenetre = 700,
        largeur_fenetre = 1100;

        //choisir type entite
        int t;
        printf("choisir type entite :\n0-> bad\t1-> good\n");
        scanf("%d",&t);

    SDL_Init(SDL_INIT_VIDEO);

    //FENETRE PRINCIPALE
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("My Game", NULL); // titre de la fenetre
  int enigme_right=0,e1=0,e2=0,e3=0,e4=0,e5=0,e6=0,e7=0,e8=0,rep=0 ;

    int c,w,b=0 ;
    c=menu(screen);
    if (c==1)
if(stage1(screen,t)){

for (int i=0;i<nb_enigme;i++)
{rep++;
enigme_right+=enigme(screen,&e1,&e2,&e3,&e4,&e5,&e6,&e7,&e8,rep,&b);
if(b) break;
}

if (enigme_right>=(nb_enigme/2)) printf("win\n");
else printf("lose\n");
}


    SDL_Quit();

    return 0;
}
