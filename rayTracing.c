#include<stdio.h>
#include<SDL2/SDL.h>
#include<math.h>

#define WIDTH 1200
#define HEIGHT 800
#define COLOR_WHITE 0xffffffff
#define COLOR_BLACK 0x00000000
#define COLOR_YELLOW 0xFFFFFF00
#define RAYS_NUMBERS 500

struct Circle {
    double x;
    double y;
    double r;
};

struct Ray{
	double x_start , y_start;
	double angle;
};

void FillCircle(SDL_Surface* surface, struct Circle circle,Uint32 color) {
    double radius_squared = pow(circle.r, 2);
    for (double x = circle.x - circle.r; x <= circle.x + circle.r; x++) {
        for (double y = circle.y - circle.r; y <= circle.y + circle.r; y++) {
            double distance_squared = pow(x - circle.x, 2) + pow(y - circle.y, 2);
            if (distance_squared < radius_squared) {
                if (x >= 0 && x < surface->w && y >= 0 && y < surface->h) {  
                    SDL_Rect pixel = (SDL_Rect){x, y, 1, 1};
                    SDL_FillRect(surface, &pixel, color);
                }
            }
        }
    }
}
void generate_rays(struct Circle circle ,struct Ray rays[RAYS_NUMBERS]){
	for (int i=0 ;i<RAYS_NUMBERS;i++){
		double angle = ((double) i/RAYS_NUMBERS)* 2 * M_PI;
		struct Ray ray = {circle.x,circle.y,angle};
		rays[i] = ray;
	}

}

void FillRays(SDL_Surface* surface,struct Ray rays[RAYS_NUMBERS],Uint32 color,struct Circle object){
	double radius_squared = pow(object.r,2);
	for (int i=0;i<RAYS_NUMBERS ;i++){
		struct Ray ray = rays[i];
		
		int end_of_screen = 0;
		int object_hit = 0;

		double step = 1;
		double x_draw= ray.x_start;
		double y_draw= ray.y_start;
		while(!end_of_screen && !object_hit){
			x_draw += step*cos(ray.angle);
			y_draw += step*sin(ray.angle);
			SDL_Rect pixel = (SDL_Rect){x_draw, y_draw, 1, 1};
			SDL_FillRect(surface, &pixel, color);

			if(x_draw < 0 || x_draw > WIDTH){
				end_of_screen = 1;
			}
			if(y_draw < 0 || y_draw >HEIGHT){
				end_of_screen = 1;
			}
			// DOES THE RAYS HITTING THE OBJECT?
			double distance_squared = pow(x_draw-object.x,2)+ pow(y_draw-object.y,2);
			if(distance_squared <radius_squared){
				break;
			}

		}
	}
}


int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Raytracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    
    struct Circle circle = {200, 200, 80};
    struct Circle shadow_circle = {650, 300, 140};
    SDL_Rect erase_rect = {0,0,WIDTH,HEIGHT};
    
    struct Ray rays[RAYS_NUMBERS];
    generate_rays(circle,rays);
   
    int simulation_running = 1;
    SDL_Event event;
    
    while (simulation_running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                simulation_running = 0;
            }
	    if(event.type == SDL_MOUSEMOTION && event.motion.state != 0){
		  circle.x=event.motion.x;
		  circle.y=event.motion.y;
		  generate_rays(circle,rays);
	    }
        }

    	SDL_FillRect(surface, &erase_rect, COLOR_BLACK );
        FillCircle(surface, circle,COLOR_YELLOW);

        FillCircle(surface,shadow_circle,COLOR_WHITE);
	FillRays(surface, rays, COLOR_YELLOW,shadow_circle);


        SDL_UpdateWindowSurface(window);  
        SDL_Delay(10);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

