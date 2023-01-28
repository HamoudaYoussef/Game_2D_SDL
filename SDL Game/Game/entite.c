#include "entite.h"

int nb_frames_e = 6;


void init_tab_anim_entite(SDL_Rect *clip)
{
    //vers droite
    clip[0].x = 0;
    clip[0].y = 25;
    clip[0].w = 100;
    clip[0].h = 100;
    int i = 1;
    for (i = 1; i < nb_frames_e; i++)
    {
        clip[i].w = 100;
        clip[i].h = 100;
        clip[i].x = clip[i].w + clip[i - 1].x;
        clip[i].y = 25;
    }


}

void initialiser_entite(entite *e, int t)
{
    e->entite = IMG_Load("graphic/bad.jpg");
    e->entite_pos.x = 900;
    e->entite_pos.y = 100;
    init_tab_anim_entite(e->animation_entite);
    e->frame_entite=0;
    e->type=t;
e->col=0;
e->up=350;
e->down=650;
e->maxup=350;
e->maxdown=650;
}

int detect_collision(perso *p, entite* e){
  if (e->col==0){
if ((p->position_perso.x + p->position_perso. w< e->entite_pos. x) || (p->position_perso.x> e->entite_pos. x + e->entite_pos. w) ||
(p->position_perso.y + p->position_perso.h< e->entite_pos. y) || (p->position_perso.y> e->entite_pos. y + e->entite_pos. h ))
e->col= 0;
else
e->col=1;
}
return e->col;
}

void afficher_entite(entite * e , SDL_Surface *screen)
{

   SDL_BlitSurface(e->entite,&e->animation_entite[e->frame_entite], screen, &e->entite_pos);



}

void anim_entite(entite *e)
{    e->frame_entite++;

    if (e->frame_entite <0 || e->frame_entite > 5)
       e->frame_entite=0;

}
  int down=0,up=0;

int distance;

void mvt_entite(entite *e, perso *p)
{
/*
var dans structure entite secondaire
int maxup,maxdown;
int type ; //definie effet de l'entite (win or lose score/vie/....)
int collision; //determine si il y a collision par defaut =0
*/
//mvt vertical par defaut
if(e->entite_pos.y<=e->maxup){
  down=1;
  up=0;}
if(e->entite_pos.y>=e->maxdown){
  down=0;
  up=1;
randomise_min_max(e);
}

  if (up==1) e->entite_pos.y-=10;
  if (down==1) e->entite_pos.y+=10;

  //mvt horizontal : interaction avec perso si entite nefaste
if(!e->type){
  distance=e->entite_pos.x-p->position_perso.x;
  //mvt entite si distance avec perso (x_entite-x_perso) < |300|
  if (distance<300 && distance>50 ){
//if x_perso < x_entite  =>entite recule
e->entite_pos.x--;
  }

if (distance >-300 && distance < 0){
  //if x_perso > x_entite => entite avance
  e->entite_pos.x++;
  }

}


}

void mise_a_jour_entite(entite *e,perso *p){
mvt_entite(e,p);
anim_entite (e);

}

void randomise_min_max(entite *e){
  srand (time(0));
  e->maxup=e->up+rand()%100;
  e->maxdown=e->down-rand()%100;

  //printf("maxup : %d\tmaxdown : %d\n",e->maxup,e->maxdown );

}
