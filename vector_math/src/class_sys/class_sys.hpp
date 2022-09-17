#ifndef CLASS_SYS_HPP
#define CLASS_SYS_HPP

#include "../general.hpp"
#include "../class_r_vector/class_r_vector.hpp"


class axys_sys {
    
    private:

    public:

        axys_sys () {}
       ~axys_sys () {delete (pixels);}


        const int WIDTH       = 1200;
        const int HEIGHT      = 800; 
        const int USIK_SCALE  = 5;
        const int SCALE       = 100;

        const double circle_rad = 300;

        sf::Uint8* pixels = new sf::Uint8 [WIDTH * HEIGHT * 4];

        void draw_clock (sf::RenderWindow *window, const double& rad) const;
        void draw_axys  (sf::RenderWindow *window) const ;
        void draw       (sf::RenderWindow *window, const r_vector& vec, const point& strt) const ;
        
        void draw_line (sf::RenderWindow *window, const r_vector& vec, const point& strt) const;
        
        double change_x (double x, double strt_x) const {return WIDTH  / 2 + x + strt_x;}
        double change_y (double y, double strt_y) const {return HEIGHT / 2 - y - strt_y;}
};


#endif