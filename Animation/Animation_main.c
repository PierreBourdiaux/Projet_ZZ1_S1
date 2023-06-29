#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <SDL2/SDL_image.h>
#include "Animation_fct.h"


int main(int argc, char const *argv[])
{
    
    (void)argc;
    (void)argv;
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

    AnimationLapin(renderer,window);
    return 0;
}
