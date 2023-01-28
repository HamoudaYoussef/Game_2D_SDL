#include "rotozoom.h"

void init_rotozoom(rotozoom *roto){

roto->rotation=NULL;
roto->attention=IMG_Load("graphic/attention.png");

roto->pos_attention.x=300;
roto->pos_attention.y=50;
roto->pos_attention.w=150;
roto->pos_attention.h=50;

roto->sens=0;
roto->angle=0;
roto->zoom=1.5;
}

void grandir(rotozoom *roto){
if(roto->zoom >= 2){
roto->sens=0;
}
else if(roto->zoom <= 0.5){
roto->sens=1;
}
if(roto->sens == 0){
roto->zoom -= 0.02;
}
else{
roto->zoom +=0.02;
}

}

void update_rotozoom(rotozoom *roto, int fps, Uint32 dt){
roto->rotation =rotozoomSurface (roto->attention,roto->angle,roto->zoom,0);
if(dt < 1000/fps) roto->angle+=2;

grandir(roto);
}


void afficher_rotozoom(rotozoom roto, SDL_Surface *screen){
  SDL_BlitSurface(roto.rotation, NULL, screen, &roto.pos_attention);
}
