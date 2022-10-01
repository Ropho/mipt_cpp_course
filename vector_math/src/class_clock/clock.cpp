#include "clock.hpp"


const double RAD = 200;

void draw_clock (const axys_sys &sys, sf::RenderWindow *window) {

    assert (window);

/////////////////////////////////////////////////
    sf::CircleShape circle_small (RAD / 10);
    circle_small.move  (sys.STRT_.get_x () + sys.WIDTH_  / 2 - RAD / 10, 
                        sys.STRT_.get_y () + sys.HEIGHT_ / 2 - RAD / 10);

/////////////////////////////////////////////////
//centralize
    sf::CircleShape circle (RAD);
    circle.move (sys.STRT_.get_x () + sys.WIDTH_  / 2 - RAD, 
                 sys.STRT_.get_y () + sys.HEIGHT_ / 2 - RAD);

    sf::Texture texture {};
    if (!texture.loadFromFile ("clock2.png")) {
        perror ("ERROR IN LOADING FROM FILE");
    }

    texture.setSmooth (true);

    circle.setTexture (&texture);
    circle.setTextureRect (sf::IntRect (0, 0, 300, 300));
    
/////////////////////////////////////////////////
    window->draw (circle);
    window->draw (circle_small);

    draw_arrows (sys, window);
}

void draw_arrows (const axys_sys &sys, sf::RenderWindow *window) {

    assert (window);

    static r_vector vec_sec (POLAR, RAD - 25, 0);
    static r_vector vec_min (POLAR, RAD - 25, 0);
    static r_vector vec_hour(POLAR, RAD / 2,  0);


    time_t curr = time (NULL) % (3600 * 24);

    size_t hour = (curr / 60 / 60 + 3) % 12;
    size_t min  =  curr / 60 % 60;
    size_t sec  =  curr % 3600 % 60;


/////////////////////////////////////////////////SEC
    double phi_sec = -grad_into_rad (sec / 60.f * 360);
    vec_sec.set_phi (phi_sec + grad_into_rad (90));
    vec_sec.synch ();

/////////////////////////////////////////////////MIN
    double phi_min = -grad_into_rad (min / 60.f * 360) + phi_sec / 60;
    vec_min.set_phi (phi_min + grad_into_rad (90));
    vec_min.synch ();

/////////////////////////////////////////////////HOUR
    double phi_hour = -grad_into_rad (hour / 12.f * 360) + phi_min / 12;
    vec_hour.set_phi (phi_hour + grad_into_rad (90));
    vec_hour.synch ();


    sys.draw_vec (window, vec_sec,  point (0, 0));
    sys.draw_vec (window, vec_min,  point (0, 0));
    sys.draw_vec (window, vec_hour, point (0, 0));

}