#include "pave_serpent_fct.h"  
  
  void drawMouton(SDL_Renderer* renderer, int x, int y) { 

       SDL_Rect rectangle;                                                
                                            
       SDL_SetRenderDrawColor(renderer,rand()%255,rand()%255,rand()%255,255);                                 // 0 = transparent ; 255 = opaque
       rectangle.x = 0;                                             // x haut gauche du rectangle
       rectangle.y = 0;                                                  // y haut gauche du rectangle
       rectangle.w = 1920;                                                // sa largeur (w = width)
       rectangle.h = 1080;                                                // sa hauteur (h = height)
                                            
       if(x==0 & y == 0)SDL_RenderFillRect(renderer, &rectangle);      

       SDL_SetRenderDrawColor(renderer,255,255,255,255);   
       drawRect(renderer, 100+x,100+y,200,150);                            

       SDL_SetRenderDrawColor(renderer,240,240,240,255);         
       drawRect(renderer, 250+x,75+y,100,100);                            

       SDL_SetRenderDrawColor(renderer,0,0,0,255);                              
       drawRect(renderer,275+x,100+y,10,10);                            

       SDL_SetRenderDrawColor(renderer,0,0,0,255);   
       drawRect(renderer, 325+x,100+y,10,10);                           

       SDL_SetRenderDrawColor(renderer,0,0,0,255);     
       drawRect(renderer, 325+x,100+y,10,10);                            

       SDL_SetRenderDrawColor(renderer,0,0,0,255);  
       drawRect(renderer, 140+x,250+y,20,80);             
       SDL_SetRenderDrawColor(renderer,0,0,0,255);  
       drawRect(renderer, 250+x,250+y,20,80);                            
                    
     
                                            
       
     }

     void drawRect(SDL_Renderer* renderer, int x, int y, int w,int h){
        SDL_Rect rectangle;                                                
       rectangle.x = x;                                             
       rectangle.y = y;                                                  
       rectangle.w = w;                                                
       rectangle.h = h; 
       SDL_RenderFillRect(renderer, &rectangle); 
     }