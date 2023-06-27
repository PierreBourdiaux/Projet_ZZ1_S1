#include "pave_serpent_fct.h"  
  
  void drawMouton(SDL_Renderer* renderer, int x, int y) { 
 
      srand(y*x);
 
       SDL_SetRenderDrawColor(renderer,rand()%255,rand()%255,rand()%255,255);   
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

     void SauteMouton(SDL_Renderer* renderer, int No){
      switch(No){
        case 0 : 
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
        break;

        case 1 : 
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
        break;

        default :
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
        break;
      }   
     }