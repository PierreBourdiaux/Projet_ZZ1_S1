#include "pave_serpent_fct.h"  
  
  void drawMouton(SDL_Renderer* renderer, int x, int y) { 
 
           

       SDL_SetRenderDrawColor(renderer,255,255,255,255);   
       drawRect(renderer, 100+x,100+y,150,100);                            

       SDL_SetRenderDrawColor(renderer,240,240,240,255);         
       drawRect(renderer, 225+x,75+y,75,75);                            

       SDL_SetRenderDrawColor(renderer,0,0,0,255);                              
       drawRect(renderer,245+x,100+y,10,10);                            

       SDL_SetRenderDrawColor(renderer,0,0,0,255);   
       drawRect(renderer, 280+x,100+y,10,10);                           

                                

       SDL_SetRenderDrawColor(renderer,0,0,0,255);  
       drawRect(renderer, 130+x,200+y,15,60);      

       SDL_SetRenderDrawColor(renderer,0,0,0,255);  
       drawRect(renderer, 215+x,200+y,15,60);                            
                    
     
                                            
       
     }

     void drawRect(SDL_Renderer* renderer, int x, int y, int w,int h){
        SDL_Rect rectangle;                                                
       rectangle.x = x;                                             
       rectangle.y = y;                                                  
       rectangle.w = w;                                                
       rectangle.h = h; 
       SDL_RenderFillRect(renderer, &rectangle); 
     }

     void setBackGround(SDL_Renderer* renderer){
      SDL_Rect rectangle;                                                
                                            
       SDL_SetRenderDrawColor(renderer,135,206,235,255);                                 // 0 = transparent ; 255 = opaque
       rectangle.x = 0;                                             // x haut gauche du rectangle
       rectangle.y = 0;                                                  // y haut gauche du rectangle
       rectangle.w = 1920;                                                // sa largeur (w = width)
       rectangle.h = 1080;                                                // sa hauteur (h = height)
                                            
       SDL_RenderFillRect(renderer, &rectangle); 

       SDL_SetRenderDrawColor(renderer,0,255,0,255);                                 // 0 = transparent ; 255 = opaque
       rectangle.x = 0;                                             // x haut gauche du rectangle
       rectangle.y = 550;                                                  // y haut gauche du rectangle
       rectangle.w = 1920;                                                // sa largeur (w = width)
       rectangle.h = 1080;                                                // sa hauteur (h = height)
                                            
       SDL_RenderFillRect(renderer, &rectangle); 

      SDL_SetRenderDrawColor(renderer,255,255,0,255);                                 // 0 = transparent ; 255 = opaque
       rectangle.x = 1000;                                             // x haut gauche du rectangle
       rectangle.y = 30;                                                  // y haut gauche du rectangle
       rectangle.w = 80;                                                // sa largeur (w = width)
       rectangle.h = 80;                                                // sa hauteur (h = height)
                                            
       SDL_RenderFillRect(renderer, &rectangle); 

     }