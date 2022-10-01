#include "class_sys.hpp"


void axys_sys::draw_sphere (sf::RenderWindow *window, point light) const {

    assert (window);

    double rad = 200;
/////////////////////////////////////////////////
    sf::Texture texture {};
    texture.create (WIDTH_, HEIGHT_);

    sf::Sprite sprite (texture);

/////////////////////////////////////////////////POINT

    // point center (0, 0, 0);
/////////////////////////////////////////////////MAIN
    size_t index   = 0;

    double rad_sqr = rad * rad;
    double max_z   = rad;

    for (int y = HEIGHT_ / 2; y > -HEIGHT_ / 2; --y) {
        
        for (int x = -WIDTH_ / 2; x < WIDTH_ / 2; ++x) {

            pixels[index++] = 255;          //R
            pixels[index++] = 0;            //G
            pixels[index++] = 0;            //B

            double sqr = x * x + y * y;
            double z   = rad_sqr - sqr;

            if (z >= 0) {
                
                // pixels[index ++] = 255;
                // continue;

                z = sqrt (z);

                r_vector vec_light (light.get_x () - x, light.get_y () - y, 
                                    light.get_z () - z);
                r_vector normal (x, y, z);

                double phi = vec_light ^= normal;
                // printf ("%lf\n", phi);
                // phi = cos (phi);
                if (phi < 0)
                    pixels[index++] = 0;
                else {
                    double color = phi * 255;
                    pixels[index++] = (sf::Uint8) color;
                }

            }
            else
                pixels[index++] = 0;

        }
    }


/////////////////////////////////////////////////
    texture.update (pixels);
    
    window->draw (sprite);
}




// void axys_sys::draw_axys (sf::RenderWindow *window) const {

//     assert (window);

//     r_vector y_axys (POLAR, HEIGHT_, 90);
//     y_axys.set_color (sf::Color::Red);
    
//     r_vector x_axys (POLAR, WIDTH_, 0);
//     x_axys.set_color (sf::Color::Red);

//     point y_axys_start (0, -HEIGHT_ / 2);
//     point x_axys_start (-WIDTH_ / 2, 0);

//     draw_vec (window, y_axys, y_axys_start);
//     draw_vec (window, x_axys, x_axys_start);
// }


void axys_sys::draw_vec_2D (sf::RenderWindow *window, const r_vector& vec, const point& strt) const {

    assert (window);

    point pnt (STRT_.get_x () + strt.get_x (), 
               STRT_.get_y () + strt.get_y (),
               STRT_.get_z () + strt.get_z ());

// /////////////////////////////////////////////////USIK CONSTRUCT
    point vec_point (vec.get_x () + pnt.get_x (), 
                     vec.get_y () + pnt.get_y (),
                     vec.get_z () + pnt.get_z ());

    r_vector usik = -vec / USIK_SCALE_;

    r_vector perp = usik.get_perpendicular ();


// /////////////////////////////////////////////////DRAW VEC + USIK
    draw_line (window, vec, pnt);
    draw_line (window, usik + perp, vec_point);
    draw_line (window, usik - perp, vec_point);
}


void axys_sys::draw_line (sf::RenderWindow *window, const r_vector& vec, const point& strt) const {

    assert (window);

/////////////////////////////////////////////////
    r_vector vec_tmp = vec;
    point strt_tmp   = strt;

    strt_tmp.set_coord (change_x (strt.get_x (), 0),             change_y (strt.get_y (), 0),             strt.get_z ());
    vec_tmp. set_coord (change_x (vec. get_x (), strt.get_x ()), change_y (vec. get_y (), strt.get_y ()), strt.get_z ());

    sf::Vertex vec_arr[] =
    {
        sf::Vertex (sf::Vector2f (strt_tmp.get_x (), strt_tmp.get_y ()), vec_tmp.get_color ()),
        sf::Vertex (sf::Vector2f (vec_tmp. get_x (), vec_tmp. get_y ()), vec_tmp.get_color ())
    };

/////////////////////////////////////////////////
    window->draw (vec_arr, 2, sf::Lines);      
}