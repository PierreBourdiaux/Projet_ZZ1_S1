#include <SDL2/SDL.h>
     #include <stdio.h>
     #include <time.h>

     /************************************/
     /*  exemple de création de fenêtres */
     /************************************/

     int main(int argc, char **argv) {

       (void)argc;
       (void)argv;
        int x,y, h,w,nbWindow =5, random =0;  
        char fenetre[50];              
        SDL_Window *Windows_tab [nbWindow];
        for(int i = 0; i<nbWindow; i++) Windows_tab[i]=NULL;
        srand(time(NULL));

       /* Initialisation de la SDL  + gestion de l'échec possible */
       if (SDL_Init(SDL_INIT_VIDEO) != 0) {
     SDL_Log("Error : SDL initialisation - %s\n", 
                  SDL_GetError());                // l'initialisation de la SDL a échoué 
     exit(EXIT_FAILURE);
       }

       for(int i = 0; i<nbWindow; i++){
                /* Création de la fenêtre de gauche */
            sprintf(fenetre, "fenetre %d", i);
            Windows_tab[i] = SDL_CreateWindow(fenetre,0, 200*i,200, 200,SDL_WINDOW_RESIZABLE);                 // redimensionnable

            if ( Windows_tab[i] == NULL) {
            SDL_Log("Error : SDL window 1 creation - %s\n", 
                        SDL_GetError());                 // échec de la création de la fenêtre
            SDL_Quit();                              // On referme la SDL       
            exit(EXIT_FAILURE);
            }

       }
       for (int i = 0; i < 50; i++)
       {
            for (int j = 0; j < nbWindow; j++)
            {
                SDL_Delay(100);
                SDL_GetWindowPosition(Windows_tab[j], &x, &y);
                if(x>1700){
                    printf("fenetre %d à gagné\n", j);
                    j=9999;
                    i=9999;
                }
                else{  
                    random= rand() % 101; 
                    SDL_SetWindowPosition(Windows_tab[j],x+random,y);

                    

                }
              
                

            }
            
       }
       


       

       /* Normalement, on devrait ici remplir les fenêtres... */
                                  // Pause exprimée  en ms

       /* et on referme tout ce qu'on a ouvert en ordre inverse de la création */
    
       for(int i = 0; i<nbWindow; i++)SDL_DestroyWindow(Windows_tab[i]);

       SDL_Quit();                                // la SDL
 
       return 0;
     }