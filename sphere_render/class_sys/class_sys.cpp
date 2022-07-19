#include "class_sys.hpp"


void axys_sys::draw_sphere (sf::RenderWindow *window, point light) const {

    assert (window);

/////////////////////////////////////////////////
    sf::Texture texture {};
    texture.create (WIDTH, HEIGHT);

    sf::Sprite sprite (texture);

/////////////////////////////////////////////////POINT

    point center (0, 0, 0);
/////////////////////////////////////////////////MAIN
    size_t index   = 0;

    double rad_sqr = circle_rad * circle_rad;
    double max_z   = circle_rad;

    for (int y = HEIGHT / 2; y > -HEIGHT / 2; --y) {
        
        for (int x = -WIDTH / 2; x < WIDTH / 2; ++x) {

            pixels[index++] = 255;          //R
            pixels[index++] = 0;            //G
            pixels[index++] = 0;            //B

            double sqr = x * x + y * y;
            double z = rad_sqr - sqr;

            if (z >= 0) {

                z = sqrt (z);
                    
                r_vector vec_light (light.get_x () - x, light.get_y () - y, light.get_z () - z);
                r_vector normal (x, y, z);

                double phi = vec_light ^ normal;
                
                phi = cos (phi);
                if (phi < 0)
                    pixels[index++] = 0;
                else {
                    double color = phi * 255;
                    pixels[index++] = color;
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


// void axys_sys::draw (sf::RenderWindow *window, const r_vector& vec, const point& strt) const {

//     assert (window);

// /////////////////////////////////////////////////USIK CONSTRUCT
//     point vec_point (vec.get_x () + strt.get_x (), vec.get_y () + strt.get_y ());

//     r_vector usik1 = vec;
//     usik1.synch ();

//     usik1.change_len (-usik1.get_rho () + usik1.get_rho () / USIK_SCALE);
//     usik1 = usik1 * -1;

//     r_vector usik2 = usik1;
//     usik2  = usik1;

//     draw_line (window, usik1, vec_point);

//     usik1.rotate (-15);
//     usik2.rotate ( 15);

// /////////////////////////////////////////////////DRAW VEC + USIK
//     draw_line (window, vec, strt);
//     draw_line (window, usik1, vec_point);
//     draw_line (window, usik2, vec_point);    
// }


// void axys_sys::draw_line (sf::RenderWindow *window, const r_vector& vec, const point& strt) const {

//     assert (window);

// /////////////////////////////////////////////////
//     r_vector vec_tmp = vec;
//     point strt_tmp   = strt;

//     strt_tmp.set_coord (change_x (strt.get_x (), 0),             change_y (strt.get_y (), 0));
//     vec_tmp. set_coord (change_x (vec. get_x (), strt.get_x ()), change_y (vec. get_y (), strt.get_y ()));

//     sf::Vertex vec_arr[] =
//     {
//         sf::Vertex (sf::Vector2f (strt_tmp.get_x (), strt_tmp.get_y ()), vec_tmp.get_color ()),
//         sf::Vertex (sf::Vector2f (vec_tmp. get_x (), vec_tmp. get_y ()), vec_tmp.get_color ())
//     };

// /////////////////////////////////////////////////
//     window->draw (vec_arr, 2, sf::Lines);      
// }