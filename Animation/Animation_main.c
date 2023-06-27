#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <SDL2/SDL_image.h>


int main(int argc, char const *argv[])
{
    
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


       /* Création de la fenêtre */
    window = SDL_CreateWindow("Animation",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, screen.w*0.66,
                screen.h*0.66,
                SDL_WINDOW_OPENGL);
    if (window == NULL) SDL_Quit();                                

       /* Création du renderer */
    renderer = SDL_CreateRenderer(window, -1,
                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) SDL_Quit(); 

    SDL_Texture *my_texture; 
   my_texture = IMG_LoadTexture(renderer,"fond_xp.jpg");
   if (my_texture == NULL) SDL_Quit();

    SDL_Rect 
        source = {0},                         // Rectangle définissant la zone de la texture à récupérer
        window_dimensions = {0},              // Rectangle définissant la fenêtre, on n'utilisera que largeur et hauteur
        destination = {0};                    // Rectangle définissant où la zone_source doit être déposée dans le renderer

    SDL_GetWindowSize(
    window, &window_dimensions.w,
    &window_dimensions.h);                    // Récupération des dimensions de la fenêtre
    SDL_QueryTexture(my_texture, NULL, NULL,
             &source.w, &source.h);       // Récupération des dimensions de l'image

    

    for(int i = 0; i<100; i++){
        destination.x = 10*i;
        destination.y = 5*i;
        destination.w = window_dimensions.w*0.5;
        destination.h = window_dimensions.h*0.5;
        SDL_RenderCopy(renderer, my_texture,
           &source,
           &destination);
        SDL_RenderPresent(renderer); 
        SDL_Delay(10);
    }

   
   

   
   IMG_Quit();

   SDL_DestroyTexture(my_texture);
    return 0;
}
