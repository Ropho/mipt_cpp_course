#ifndef CLASS_SYS_HPP
#define CLASS_SYS_HPP

#include "../general.hpp"
#include "../class_r_vector/class_r_vector.hpp"


class axys_sys {
    
    private:

    public:

        axys_sys (const point &strt, const size_t &width, const size_t &height) :
            WIDTH_ (width), HEIGHT_ (height), STRT_ (strt)
            {}

        axys_sys (const size_t &width, const size_t &height) :
            WIDTH_ (width), HEIGHT_ (height), STRT_ {}
            {}

       ~axys_sys () {delete (pixels);}

        const point STRT_      = {};
        const int WIDTH_       =  0;
        const int HEIGHT_      =  0; 

        const int USIK_SCALE_  = 5;
        const int SCALE_       = 100;

        sf::Uint8* pixels = new sf::Uint8 [WIDTH_ * HEIGHT_ * 4];

        friend void draw_clock (const axys_sys &sys, sf::RenderWindow *window);
        
        // void draw_axys  (sf::RenderWindow *window) const;
        // void draw_vec   (sf::RenderWindow *window, const r_vector& vec, const point& strt) const ;
        
        void draw_line   (sf::RenderWindow *window, const r_vector& vec, const point& strt) const;
        void draw_sphere (sf::RenderWindow *window, point light) const;

        double change_x (double x, double strt_x) const {return WIDTH_  / 2 + x + strt_x;}
        double change_y (double y, double strt_y) const {return HEIGHT_ / 2 - y - strt_y;}

        double transfer_x (double x) const {return  x - STRT_.get_x ()  - WIDTH_  / 2;}
        double transfer_y (double y) const {return -y + STRT_.get_y () + HEIGHT_ / 2;}

        void draw_vec_2D (sf::RenderWindow *window, const r_vector& vec, const point& strt) const;

};


#endif