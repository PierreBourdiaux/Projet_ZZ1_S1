 #include <SDL2/SDL.h>
     #include <math.h>
     #include <stdio.h>
     #include <string.h>
    #include <time.h>
    #include "pave_serpent_fct.h"

     /*********************************************************************************************************************/
     /*                              Programme d'exemple de création de rendu + dessin                                    */
     /*********************************************************************************************************************/
                                                  
                                            
   

     int main(int argc, char** argv) {
       (void)argc;
       (void)argv;
        int x,y;
       SDL_Window* window = NULL;
       SDL_Renderer* renderer = NULL;

       SDL_DisplayMode screen;

       /*********************************************************************************************************************/  
       /*                         Initialisation de la SDL  + gestion de l'échec possible                                   */
       if (SDL_Init(SDL_INIT_VIDEO) != 0) SDL_Quit();                                

       SDL_GetCurrentDisplayMode(0, &screen);
       printf("Résolution écran\n\tw : %d\n\th : %d\n",
          screen.w, screen.h);

       /* Création de la fenêtre */
       window = SDL_CreateWindow("Premier dessin",
                 SDL_WINDOWPOS_CENTERED,
                 SDL_WINDOWPOS_CENTERED, screen.w * 0.66,
                 screen.h * 0.66,
                 SDL_WINDOW_OPENGL);
       if (window == NULL) SDL_Quit();                                

       /* Création du renderer */
       renderer = SDL_CreateRenderer(window, -1,
                     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
       if (renderer == NULL) SDL_Quit();                                ;

       /*********************************************************************************************************************/
       /*                                     On dessine dans le renderer                                                   */
       /*********************************************************************************************************************/
       /*             Cette partie pourrait avantageusement être remplacée par la boucle évènementielle                     */ 
       setBackGround(renderer);
        drawMouton(renderer, -50, 300);                                      // appel de la fonction qui crée l'image  
        drawMouton(renderer, 200,300);                                      // appel de la fonction qui crée l'image  
        SDL_RenderPresent(renderer); 
        SDL_Delay(5000);


        for(int i =0; i<100; i++){
          if(i<50){
            SDL_RenderClear(renderer);
            setBackGround(renderer);
            drawMouton(renderer, -50+5*i, 300-5*i);                                      // appel de la fonction qui crée l'image  
            drawMouton(renderer, 200,300);                                      // appel de la fonction qui crée l'image  
            SDL_RenderPresent(renderer); 
            SDL_Delay(10);
          }
          else{
            SDL_RenderClear(renderer);
            setBackGround(renderer);
            drawMouton(renderer, -50+5*i, 300-5*(100-i));                                      // appel de la fonction qui crée l'image  
            drawMouton(renderer, 200,300);                                      // appel de la fonction qui crée l'image  
            SDL_RenderPresent(renderer); 
            SDL_Delay(10);
          }
        }


        for(int i =0; i<101; i++){
          if(i<50){
            SDL_RenderClear(renderer);
            setBackGround(renderer);
            drawMouton(renderer, 200+5*i, 300-5*i);                                      // appel de la fonction qui crée l'image  
            drawMouton(renderer, 450,300);                                      // appel de la fonction qui crée l'image  
            SDL_RenderPresent(renderer); 
            SDL_Delay(10);
          }
          else{
            SDL_RenderClear(renderer);
            setBackGround(renderer);
            drawMouton(renderer, 200+5*i, 300-5*(100-i));
            drawMouton(renderer, 450,300);                                      // appel de la fonction qui crée l'image  
            SDL_RenderPresent(renderer); 
            SDL_Delay(10);
          }
        }

        for(int i =0; i<101; i++){
          if(i<50){
            SDL_RenderClear(renderer);
            setBackGround(renderer);
            drawMouton(renderer, 450+5*i, 300-5*i);                                      // appel de la fonction qui crée l'image  
            drawMouton(renderer, 700,300);                                      // appel de la fonction qui crée l'image  
            SDL_RenderPresent(renderer); 
            SDL_Delay(10);
          }
          else{
            SDL_RenderClear(renderer);
            setBackGround(renderer);
            drawMouton(renderer, 450+5*i, 300-5*(100-i));
            if(i==100) printf("X : %d , Y: %d\n",200+5*i, 300-5*(100-i) );                                     // appel de la fonction qui crée l'image  
            drawMouton(renderer, 700,300);                                      // appel de la fonction qui crée l'image  
            SDL_RenderPresent(renderer); 
            SDL_Delay(10);
          }
        }

         SDL_bool
      program_on = SDL_TRUE,                          // Booléen pour dire que le programme doit continuer
      paused = SDL_FALSE,                             // Booléen pour dire que le programme est en pause
      event_utile = SDL_FALSE;                        // Booléen pour savoir si on a trouvé un event traité 
    SDL_Event event;                                  // Evènement à traiter

    while (program_on) {                              // La boucle des évènements
      event_utile = SDL_FALSE;
      while(!event_utile && SDL_PollEvent(&event)) {  // Tant que on n'a pas trouvé d'évènement utile
                                                      // et la file des évènements stockés n'est pas vide et qu'on n'a pas
                              // terminé le programme Défiler l'élément en tête de file dans 'event'
    switch (event.type) {                         // En fonction de la valeur du type de cet évènement
    case SDL_QUIT:                                // Un évènement simple, on a cliqué sur la x de la // fenêtre
      program_on = SDL_FALSE;                     // Il est temps d'arrêter le programme
      event_utile = SDL_TRUE;
      break;
    
    case SDL_MOUSEBUTTONDOWN:                     // Click souris   
      if (SDL_GetMouseState(&x, &y) & 
          SDL_BUTTON(SDL_BUTTON_LEFT) ) {         // Si c'est un click gauche
                   printf("X: %d Y: %d \n", x,y);
      }
      event_utile = SDL_TRUE;
      break;
    default:                                      // Les évènements qu'on n'a pas envisagé
      break;
    }}  }                                    

       /* on referme proprement la SDL */
      SDL_Quit();                                
       return EXIT_SUCCESS;
     }