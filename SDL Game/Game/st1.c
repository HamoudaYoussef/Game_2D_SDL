#include "st1.h"

int stage1(SDL_Surface* screen,int t){
TTF_Init();

//declaration & int perso
perso p;
initialiser_perso(&p);

//declaration et init score
score_perso score;
init_score(&score);

//declaration & init vie
vie_perso vie;
init_vie(&vie);

//declaration et init chrono
chrono_perso c;
init_chrono(&c);


//declaration & init background
background bg,bg2;
initialiser_back(&bg,1);
initialiser_back(&bg2,2);

int a=1; //a -> affichage entite ou non

//declaration & init entite
entite es;
initialiser_entite(&es,t);

//declaration et init rotozoom
rotozoom roto;
init_rotozoom(&roto);

//declaration et init fps
Uint32 t_dep,t_fin,dt=1;
    int fps=30;



//boucle pseudo infinie
SDL_EnableKeyRepeat(200,0); //refresh imput : (duree de la pression du boutton,intervalle de repetition)
int continuer=1;
SDL_Event event;
int win;

while (continuer) {
t_dep=SDL_GetTicks();

  es.col=0;
  p.etat=0;



if(SDL_PollEvent(&event))
{
  switch(event.type)
  {
    case SDL_QUIT:
    win=0;
continuer=0;
    break;

    case SDL_KEYDOWN:

switch(event.key.keysym.sym){

  case SDLK_RIGHT: //appuie sur fleche droite
    apply_acceleration(&p,dt);
    p.etat=1;
    if(scrol_right(&bg,screen,&es,&p))
    if (p.position_perso.x<1000)
    deplacer_perso_droite(&p);
      break;

    case SDLK_LEFT : //appuie sur fleche gauche
    p.etat=1;
    apply_acceleration(&p,dt);
    if(scrol_left(&bg,screen,&es,&p))
    deplacer_perso_gauche(&p);
    break;

    case SDLK_UP : //jump
if(on_ground(&p))  jump_perso(&p);
    break;

    case SDLK_f : //teleport front
if(on_ground(&p)) teleport_front(&p);
    break;

    case SDLK_b : //teleport back
if(on_ground(&p)) teleport_back(&p);
    break;

    case SDLK_a : //activer/desactiver acceleration
p.acc++;
    break;

    case SDLK_d:
      scrol_right2(&bg2,screen);
        break;

      case SDLK_q :
      scrol_left2(&bg2,screen);
      break;

}

    break;
  }
}


//affichage background
affiche_back(&bg,screen);
affiche_back(&bg2,screen);

//mise a jour et affichage entite
mise_a_jour_entite(&es,&p);


if(detect_collision(&p,&es))
a=gestion_vie_score(&p,&es);

if(a) afficher_entite(&es,screen);

//mise a jour et affichage personnage
afficher_vie_score(&p,screen,&score,&vie);
afficher_chrono(screen,&c);

apply_gravity(&p);
if (!p.etat) {
animer_perso_stable(&p);
p.mvtx=2; //remove acceleration when not moving
}

//printf("%d\t%d\n",p.acc,p.mvtx );
afficher_peso(&p,screen);

//rotozoom
update_rotozoom(&roto,fps,dt);
afficher_rotozoom(roto,screen);

SDL_Flip(screen);
//conditions fin jeu
win=condition_fin_jeu (&p,&c,&continuer);

//appliquer fps
t_fin=SDL_GetTicks();
dt=t_fin-t_dep;
if (1000/fps>dt) SDL_Delay (1000/fps-dt);

}

return win;
}
