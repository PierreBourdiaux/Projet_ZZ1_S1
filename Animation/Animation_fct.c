#include "Animation_fct.h"


void AnimationLapin(SDL_Renderer * renderer, SDL_Window* window){

    SDL_Rect 
        source = {0},                         // Rectangle définissant la zone de la texture à récupérer
        window_dimensions = {0},              // Rectangle définissant la fenêtre, on n'utilisera que largeur et hauteur
        destination = {0},                   // Rectangle définissant où la zone_source doit être déposée dans le renderer
        state = {0},
        sourceSol = {0},
        sourceForet = {0},
        sourceMontagne = {0},
        destinationSol= {0},
        destinationSol2= {0},
        destinationForet = {0},
        destinationForet2 = {0},
        destinationMontagne={0};
    SDL_Texture *texture = IMG_LoadTexture(renderer,"./img/sprite_Lapin.png");
    if (texture == NULL) SDL_Quit();

    SDL_Texture *texture_Sol = IMG_LoadTexture(renderer,"./img/sol.png");
    if (texture == NULL) SDL_Quit();
    
    SDL_Texture *texture_Foret = IMG_LoadTexture(renderer,"./img/foret.png");
    if (texture == NULL) SDL_Quit();

    SDL_Texture *texture_Montagne = IMG_LoadTexture(renderer,"./img/montagne.png");
    if (texture == NULL) SDL_Quit();


    SDL_GetWindowSize(
    window, &window_dimensions.w,
    &window_dimensions.h);                   
    SDL_QueryTexture(texture, NULL, NULL,
             &source.w, &source.h);      

    int nb_images = 8;                    
    float zoom = 1;                       
    int offset_x = source.w / nb_images,  
         offset_y = 238 ;    

    state.x = 0 ;                          // La première vignette est en début de ligne
    state.y = 0 * offset_y;                // On s'intéresse à la 4ème ligne, le bonhomme qui court
    state.w = offset_x;                    // Largeur de la vignette
    state.h = offset_y;                    // Hauteur de la vignette

    destination.w = offset_x * zoom;       
    destination.h = offset_y * zoom;
    destination.y = (window_dimensions.h - destination.h-80);  //milieu de l'écran


    SDL_QueryTexture(texture_Sol, NULL,NULL,&sourceSol.w, &sourceSol.h);
    destinationSol.w = sourceSol.w * 1.5;       
    destinationSol.h = sourceSol.h * 1.5;
    destinationSol.x = 0;
    destinationSol.y = (window_dimensions.h-100*1.5);

    destinationSol2.w = sourceSol.w * 1.5;       
    destinationSol2.h = sourceSol.h * 1.5;
    destinationSol2.x = 1900;
    destinationSol2.y = (window_dimensions.h-100*1.5);

    SDL_QueryTexture(texture_Foret, NULL,NULL,&sourceForet.w, &sourceForet.h);
    destinationForet.w= sourceForet.w *1.15;
    destinationForet.h= sourceForet.h *1.15;
    destinationForet.x= 0;
    destinationForet.y= (window_dimensions.h-destinationForet.h*1.15);

    destinationForet2.w= sourceForet.w *1.15;
    destinationForet2.h= sourceForet.h *1.15;
    destinationForet2.x= 2060;
    destinationForet2.y= (window_dimensions.h-destinationForet.h*1.15);

    SDL_QueryTexture(texture_Montagne, NULL,NULL,&sourceMontagne.w, &sourceMontagne.h);
    destinationMontagne.w =sourceMontagne.w*2;
    destinationMontagne.h =sourceMontagne.h*2;
    destinationMontagne.x =300;
    destinationMontagne.y =window_dimensions.h-sourceMontagne.h*2.1;
    

    int speed = 9;
    for (int frame = 0; frame<400; frame++) {
        destination.x =frame*8;
        int x = frame /100;
      state.x += offset_x;                 // On passe à la vignette suivante dans l'image
      state.x %= source.w;                 // La vignette qui suit celle de fin de ligne est

        destinationMontagne.x = destinationMontagne.x -2;
        if(destinationSol.x <-1900) destinationSol.x = 1900;
        else  destinationSol.x = destinationSol.x -20;
        if(destinationSol2.x <-1900) destinationSol2.x = 1900;
        else destinationSol2.x = destinationSol2.x -20;

        if(destinationForet.x <-2060) destinationForet.x = 2060;
        else  destinationForet.x = destinationForet.x -10;
        if(destinationForet2.x <-2060) destinationForet2.x = 2060;
        else destinationForet2.x = destinationForet2.x -10;

        
        printf("%d, %d, %d, %d\n", destinationMontagne.x, destinationMontagne.y, destinationMontagne.w, destinationMontagne.h);

      SDL_RenderClear(renderer);           // Effacer l'image précédente avant de dessiner la nouvelle

      //printf("%d, %d, %d, %d\n", state.x, state.y, state.w, state.h);
       SDL_RenderCopy(renderer, texture_Montagne, 
               &sourceMontagne,
               &destinationMontagne);


       SDL_RenderCopy(renderer, texture_Foret, 
               &sourceForet,
               &destinationForet);

      SDL_RenderCopy(renderer, texture_Foret, 
               &sourceForet,
               &destinationForet2);
      
      SDL_RenderCopy(renderer, texture_Sol, 
               &sourceSol,
               &destinationSol);

      SDL_RenderCopy(renderer, texture_Sol, 
               &sourceSol,
               &destinationSol2);
               
     

      
  
      SDL_RenderCopy(renderer, texture, 
               &state,
               &destination); 


 
      SDL_RenderPresent(renderer);         // Affichage
      SDL_Delay(50);                       // Pause en ms
     }



   
   IMG_Quit();

   SDL_DestroyTexture(texture);


}

