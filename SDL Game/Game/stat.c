#include "stat.h"

void init_score(score_perso* s){
    s->police_score=TTF_OpenFont("graphic/font.ttf",40);

    s->texte_score=NULL;
    s->pos_texte_score.x=50;
    s->pos_texte_score.y=50;
}

void init_vie(vie_perso* v){
    v->police_vie=TTF_OpenFont("graphic/font.ttf",40);

    v->texte_vie=NULL;
    v->pos_texte_vie.x=550;
    v->pos_texte_vie.y=50;
}

void init_chrono(chrono_perso* c){
    c->police_chrono=TTF_OpenFont("graphic/font.ttf",40);

    c->texte_chrono=NULL;
    c->pos_texte_chrono.x=750;
    c->pos_texte_chrono.y=50;

    c->temps_init=50;
}

int gestion_vie_score(perso* p, entite* e){
//entite reste apres collision -> retour 1
if (!e->type) //si type=0 (diminuer vie)
{
 p->vie--;
 if(p->position_perso.x<= e->entite_pos.x) p->position_perso.x-=150;
  if(p->position_perso.x>= e->entite_pos.x) p->position_perso.x+=150;
  return 1;
}
//entite disparait apres collision -> retour 0;
if (e->type)//si type =1 (ajout score)
 {
  p->score+=100;
  e->entite_pos.y=100;
e->down=110;
e->up=100;
e->maxup=e->up+rand()%2;
e->maxdown=e->down+rand()%2;
return 0;
// dans main : if (gestion_vie_score(&p,&e))   afficher_entite(...)
}
}

//la structure personnage contient int vie et int score initialsés;
//p est une variable de type personnage principal (perso)
void afficher_score(perso* p,SDL_Surface* screen,score_perso* s)
{
  SDL_Color couleur_score={255,255,255}; //type RGB
  char char_score[10];
  sprintf(char_score,"%06d",p->score);
  s->texte_score=TTF_RenderText_Solid(s->police_score,char_score,couleur_score);
  SDL_BlitSurface(s->texte_score,NULL,screen,&s->pos_texte_score);
}

void afficher_vie(perso* p,SDL_Surface* screen,vie_perso* v)
{SDL_Color couleur_vie={255,255,255};
  char char_vie[10];
  sprintf(char_vie,"%02d",p->vie);
  v->texte_vie=TTF_RenderText_Solid(v->police_vie,char_vie,couleur_vie);
  SDL_BlitSurface(v->texte_vie,NULL,screen,&v->pos_texte_vie);
}

void afficher_vie_score(perso* p,SDL_Surface* screen,score_perso* s,vie_perso* v)
{
  afficher_score(p,screen,s);
  afficher_vie(p,screen,v);

}

void afficher_chrono(SDL_Surface* screen,chrono_perso* c)
{ SDL_Color couleur_chrono={255,255,255};
  char char_chrono[50];
  c->temps_restant= c->temps_init-(float)SDL_GetTicks()/1000;
  sprintf(char_chrono,"Timer : %0.2f",c->temps_restant);
  c->texte_chrono=TTF_RenderText_Solid(c->police_chrono,char_chrono,couleur_chrono);
  SDL_BlitSurface(c->texte_chrono,NULL,screen,&c->pos_texte_chrono);
}

int condition_fin_jeu (perso* p,chrono_perso *c, int *co){//int condition ....
  if(p->vie<=0 || c->temps_restant<=0 ) {
printf("you lose\n");
    *co=0;
    return 0 ;
  }

  if (p->position_perso.x+p->position_perso.w>=1100)
  {
    printf("you win\n");
    *co=0;
    return 1;
  }
}
