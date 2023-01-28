#include "back.h"

int width_bg;

void initialiser_back (background *b, int ord)
{

  b->back_pos.x = 0;
  b->camera.x=0;
  b->camera.w=1100;

  if (ord==2){
b->back=IMG_Load("graphic/11.jpg");
b->back_pos.y = 0;
b->camera.y=0;
b->camera.h=350;
width_bg=1150;
}

if (ord==1){
b->back=IMG_Load("graphic/22.jpg");
b->back_pos.y = -350;
b->camera.y=-350;
b->camera.h=700;
width_bg=1380;
}

}
int scrol_right(background *b, SDL_Surface *screen, entite *e, perso *p)
{
if (b->camera.x < width_bg - b->camera.w){
b->camera.x+=p->mvtx;
e->entite_pos.x-=p->mvtx; //mvt entite secondaire
}
else return 1;

}

int scrol_left(background *b, SDL_Surface *screen, entite *e, perso *p)
{
if (b->camera.x > 0){
b->camera.x-=p->mvtx;
e->entite_pos.x+=p->mvtx; //mvt entite secondaire
}
else return 1;

}

void scrol_right2(background *b, SDL_Surface *screen)
{
if (b->camera.x < width_bg - b->camera.w){
b->camera.x+=2;
}
}

void scrol_left2(background *b, SDL_Surface *screen)
{
if (b->camera.x > 0){
b->camera.x-=2;
}

}

void affiche_back(background *b, SDL_Surface *screen)
{
   SDL_BlitSurface(b->back, &b->camera, screen, NULL);
}
