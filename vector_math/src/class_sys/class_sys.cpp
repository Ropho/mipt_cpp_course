#include "class_sys.hpp"





void axys_sys::draw_axys (sf::RenderWindow *window) const {

    assert (window);

    r_vector y_axys (POLAR, HEIGHT_, 90);
    y_axys.set_color (sf::Color::Red);
    
    r_vector x_axys (POLAR, WIDTH_, 0);
    x_axys.set_color (sf::Color::Red);

    point y_axys_start (0, -HEIGHT_ / 2);
    point x_axys_start (-WIDTH_ / 2, 0);

    draw_vec (window, y_axys, y_axys_start);
    draw_vec (window, x_axys, x_axys_start);
}


void axys_sys::draw_vec (sf::RenderWindow *window, const r_vector& vec, const point& strt) const {

    assert (window);

    point pnt (STRT_.get_x () + strt.get_x (), 
               STRT_.get_y () + strt.get_y ());

/////////////////////////////////////////////////USIK CONSTRUCT
    point vec_point (vec.get_x () + pnt.get_x (), 
                     vec.get_y () + pnt.get_y ());

    r_vector usik1 = vec;
    usik1.synch ();

    usik1.change_len (-usik1.get_rho () + usik1.get_rho () / USIK_SCALE_);
    usik1 = usik1 * -1;

    r_vector usik2 = usik1;
    usik2  = usik1;

    draw_line (window, usik1, vec_point);
    draw_line (window, usik2, vec_point);

    // draw_line (window, -vec/10.perp() + -vec/10, vec_point + vec);

    usik1.rotate (-15);
    usik2.rotate ( 15);

/////////////////////////////////////////////////DRAW VEC + USIK
    draw_line (window, vec, pnt);
    draw_line (window, usik1, vec_point);
    draw_line (window, usik2, vec_point);    
}


void axys_sys::draw_line (sf::RenderWindow *window, const r_vector& vec, const point& strt) const {

    assert (window);

/////////////////////////////////////////////////
    r_vector vec_tmp = vec;
    point strt_tmp   = strt;

    strt_tmp.set_coord (change_x (strt.get_x (), 0),             change_y (strt.get_y (), 0));
    vec_tmp. set_coord (change_x (vec. get_x (), strt.get_x ()), change_y (vec. get_y (), strt.get_y ()));

    sf::Vertex vec_arr[] =
    {
        sf::Vertex (sf::Vector2f (strt_tmp.get_x (), strt_tmp.get_y ()), vec_tmp.get_color ()),
        sf::Vertex (sf::Vector2f (vec_tmp. get_x (), vec_tmp. get_y ()), vec_tmp.get_color ())
    };

/////////////////////////////////////////////////
    window->draw (vec_arr, 2, sf::Lines);      
}