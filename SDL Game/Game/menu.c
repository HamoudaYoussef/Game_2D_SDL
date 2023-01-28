
#include "menu.h"

int menu(SDL_Surface *screen){
SDL_Surface *image = NULL ,*start = NULL, *options=NULL , *exit=NULL, *start1= NULL, *options1= NULL , *exit1=NULL , *texte=NULL;
SDL_Rect postionecran,positionstart0,positionoptions0,positionexit0,positionstart1,positionoptions1,positionexit1,ptexte;
TTF_Font *police=NULL;
SDL_Color couleurNoire={255,255,255};
    SDL_Event event ;
    int continuer=1;
    int c;
Mix_Music *musique;
char pause;
int a=1;





    image=SDL_LoadBMP("graphic/image1.bmp");
    start = SDL_LoadBMP ("graphic/start.bmp");
    options = SDL_LoadBMP ("graphic/opt.bmp");
    exit = SDL_LoadBMP ("graphic/ext.bmp");
    start1 = SDL_LoadBMP ("graphic/start1.bmp");
    options1 = SDL_LoadBMP ("graphic/opt1.bmp");
    exit1 = SDL_LoadBMP ("graphic/ext1.bmp");

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
//init de l'API Mixer
    {
    printf ("%s",Mix_GetError());
    }
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
    musique =Mix_LoadMUS("graphic/menu.mp3");//chargement de la musique
    Mix_PlayMusic(musique,-1);//(lancer la music)&jouer infiniment la musique
    TTF_Init();
   police = TTF_OpenFont("graphic/ANGELTEARS-trial.ttf",65);//chargement de la police

    postionecran.x=0;
    postionecran.y=0;
    positionstart0.x = 300;
    positionstart0.y = 150;
    positionoptions0.x = 300;
    positionoptions0.y = 260;
    positionexit0.x = 300;
    positionexit0.y = 370;
    positionstart1.x = 300;
    positionstart1.y = 150;
    positionoptions1.x = 300;
    positionoptions1.y = 260;
    positionexit1.x = 300;
    positionexit1.y = 370;
    ptexte.x=10;
    ptexte.y=500;
	SDL_BlitSurface(image,NULL,screen,&postionecran);
	SDL_BlitSurface(start1,NULL,screen,&positionstart0);
	SDL_BlitSurface(options,NULL,screen,&positionoptions0);
	SDL_BlitSurface(exit,NULL,screen,&positionexit0);


 while (continuer)
	{

    		SDL_WaitEvent(&event);
    		switch (event.type)
    		{


     			case SDL_QUIT:

     			continuer=0;

			case SDL_MOUSEBUTTONDOWN:
                            if ((event.button.button == SDL_BUTTON_LEFT)&&(event.motion.x>300)&&(event.motion.y>150)&&(event.motion.x<500)&&(event.motion.y<240))
                           {  c=1;
			     continuer=0;}

        			if ((event.button.button == SDL_BUTTON_LEFT)&&(event.motion.x>300)&&(event.motion.y>370)&&(event.motion.x<500)&&(event.motion.y<460))
				{
				continuer = 0 ;
				}
     			case SDL_KEYDOWN:

      			switch (event.key.keysym.sym)
       			{

				case SDLK_UP:
					if (a==3)
					{

						SDL_BlitSurface(image,NULL,screen,&postionecran);
						SDL_BlitSurface(start,NULL,screen,&positionstart0);
						SDL_BlitSurface(options1,NULL,screen,&positionoptions0);
						SDL_BlitSurface(exit,NULL,screen,&positionexit0);
                  				texte = TTF_RenderText_Blended(police,"would you like to see the options ",couleurNoire);//ecriture du text
                			        SDL_BlitSurface(texte, NULL, screen, &ptexte);
						SDL_Flip(screen);
						a=2;break;
                                                 // if( Mix_PlayChannel( -1, bip, 0 ) == -1 ) { return 1; }

					}
					else if (a==2)
					{
						SDL_BlitSurface(image,NULL,screen,&postionecran);
						SDL_BlitSurface(start1,NULL,screen,&positionstart0);
						SDL_BlitSurface(options,NULL,screen,&positionoptions0);
						SDL_BlitSurface(exit,NULL,screen,&positionexit0);
						texte = TTF_RenderText_Blended(police," would you like to start the game",couleurNoire);//ecriture du text
                 			        SDL_BlitSurface(texte, NULL, screen, &ptexte);
						SDL_Flip(screen); // mise a jour ecran
                                                 // if( Mix_PlayChannel( -1, bip, 0 ) == -1 ) { return 1; }
						a=1;break;

					}

					else if (a==1)
					{
						SDL_BlitSurface(image,NULL,screen,&postionecran);
						SDL_BlitSurface(start,NULL,screen,&positionstart0);
						SDL_BlitSurface(options,NULL,screen,&positionoptions0);
						SDL_BlitSurface(exit1,NULL,screen,&positionexit0);
                  				texte = TTF_RenderText_Blended(police,"would you like to quit the game",couleurNoire);//ecriture du text
                 			        SDL_BlitSurface(texte, NULL, screen, &ptexte);
						SDL_Flip(screen);
                                                //  if( Mix_PlayChannel( -1, bip, 0 ) == -1 ) { return 1; }
						a=3;break;
					}
					case SDLK_DOWN:
					if (a==1)
					{
						SDL_BlitSurface(image,NULL,screen,&postionecran);
						SDL_BlitSurface(start,NULL,screen,&positionstart0);
						SDL_BlitSurface(options1,NULL,screen,&positionoptions0);
						SDL_BlitSurface(exit,NULL,screen,&positionexit0);
                  				texte = TTF_RenderText_Blended(police,"would you like to see the options ",couleurNoire);//ecriture du text
                			        SDL_BlitSurface(texte, NULL, screen, &ptexte);
						SDL_Flip(screen);
                                             //   if( Mix_PlayChannel( -1, bip, 0 ) == -1 ) { return 1; }
						a=2;break;
					}
					else if (a==2)
					{
						SDL_BlitSurface(image,NULL,screen,&postionecran);
						SDL_BlitSurface(start,NULL,screen,&positionstart0);
						SDL_BlitSurface(options,NULL,screen,&positionoptions0);
						SDL_BlitSurface(exit1,NULL,screen,&positionexit0);
                  				texte = TTF_RenderText_Blended(police,"would you like to quit the game",couleurNoire);//ecriture du text
                 			        SDL_BlitSurface(texte, NULL, screen, &ptexte);
						SDL_Flip(screen);
//                                                  if( Mix_PlayChannel( -1, bip, 0 ) == -1 ) { return 1; }
						a=3;break;

					}
					else if (a==3)
					{
						SDL_BlitSurface(image,NULL,screen,&postionecran);
						SDL_BlitSurface(start1,NULL,screen,&positionstart0);
						SDL_BlitSurface(options,NULL,screen,&positionoptions0);
						SDL_BlitSurface(exit,NULL,screen,&positionexit0);
						texte = TTF_RenderText_Blended(police," would you like to start the game",couleurNoire);//ecriture du text
                 			        SDL_BlitSurface(texte, NULL, screen, &ptexte);
						SDL_Flip(screen);
                                           //       if( Mix_PlayChannel( -1, bip, 0 ) == -1 ) { return 1; }
						a=1;break;

					}


}

			case SDL_MOUSEMOTION:
                		if ((event.motion.x>300)&&(event.motion.y>150)&&(event.motion.x<500)&&(event.motion.y<240))
				{

						SDL_BlitSurface(image,NULL,screen,&postionecran);
						SDL_BlitSurface(start1,NULL,screen,&positionstart0);
						SDL_BlitSurface(options,NULL,screen,&positionoptions0);
						SDL_BlitSurface(exit,NULL,screen,&positionexit0);
						texte = TTF_RenderText_Blended(police," would you like to start the game",couleurNoire);//ecriture du text
                 			        SDL_BlitSurface(texte, NULL, screen, &ptexte);
						SDL_Flip(screen);

						a=1;break;
				}
				else if ((event.motion.x>300)&&(event.motion.y>260)&&(event.motion.x<500)&&(event.motion.y<350))
				{
						SDL_BlitSurface(image,NULL,screen,&postionecran);
						SDL_BlitSurface(start,NULL,screen,&positionstart0);
						SDL_BlitSurface(options1,NULL,screen,&positionoptions0);
						SDL_BlitSurface(exit,NULL,screen,&positionexit0);
                  				texte = TTF_RenderText_Blended(police,"would you like to see the options ",couleurNoire);//ecriture du text
                			        SDL_BlitSurface(texte, NULL, screen, &ptexte);
						SDL_Flip(screen);

						a=2;break;
				}
				else if ((event.motion.x>300)&&(event.motion.y>370)&&(event.motion.x<500)&&(event.motion.y<460))
				{

						SDL_BlitSurface(image,NULL,screen,&postionecran);
						SDL_BlitSurface(start,NULL,screen,&positionstart0);
						SDL_BlitSurface(options,NULL,screen,&positionoptions0);
						SDL_BlitSurface(exit1,NULL,screen,&positionexit0);
                  				texte = TTF_RenderText_Blended(police,"would you like to quit the game",couleurNoire);//ecriture du text
                 			        SDL_BlitSurface(texte, NULL, screen, &ptexte);
						SDL_Flip(screen);
						a=3;break;
				}





		}




		SDL_Flip(screen);
	}



    TTF_CloseFont(police);
    TTF_Quit();
   SDL_Flip(screen);
SDL_FreeSurface(image);
    SDL_FreeSurface(start);
    SDL_FreeSurface(options);
    SDL_FreeSurface(exit);

return c;


}
