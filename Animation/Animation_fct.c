#include "Animation_fct.h"


void AnimationLapin(SDL_Renderer * renderer, SDL_Window* window){

    SDL_Rect 
        source = {0},                         // Rectangle définissant la zone de la texture à récupérer
        window_dimensions = {0},              // Rectangle définissant la fenêtre, on n'utilisera que largeur et hauteur
        destination = {0},                   // Rectangle définissant où la zone_source doit être déposée dans le renderer
        state = {0},
        sourceSol = {0},
        destinationSol= {0};
    SDL_Texture *texture = IMG_LoadTexture(renderer,"./img/sprite_Lapin.png");
    if (texture == NULL) SDL_Quit();

    SDL_Texture *texture_Sol = IMG_LoadTexture(renderer,"./img/sol.png");
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
    printf("%d, %d, %d, %d\n", destinationSol.x, destinationSol.y, destinationSol.w, destinationSol.h);


    

    int speed = 9;
    for (int frame = 0; frame<400; frame++) {
        destination.x =frame*10;
        int x = frame /100;
      state.x += offset_x;                 // On passe à la vignette suivante dans l'image
      state.x %= source.w;                 // La vignette qui suit celle de fin de ligne est
                       // celle de début de ligne
      SDL_RenderClear(renderer);           // Effacer l'image précédente avant de dessiner la nouvelle

      //printf("%d, %d, %d, %d\n", state.x, state.y, state.w, state.h);
      
      SDL_RenderCopy(renderer, texture_Sol, 
               &sourceSol,
               &destinationSol); 
      SDL_RenderCopy(renderer, texture, 
               &state,
               &destination); 
 
      SDL_RenderPresent(renderer);         // Affichage
      SDL_Delay(50);                       // Pause en ms
     }



   
   IMG_Quit();

   SDL_DestroyTexture(texture);


}

