#include "general.hpp"

#include "class_r_vector/class_r_vector.hpp"
#include "class_sys/class_sys.hpp"

const size_t HEIGHT = 800;
const size_t WIDTH  = 1200;


//TODO:
//add NORMALIZE
//perp
//add usik norm impl......


//add графическая оболочка





int main (void) {


    axys_sys sys (point {}, WIDTH, HEIGHT);
    point light (400, 0, 0);


/////////////////////////////////////////////////SFML
    sf::RenderWindow window (sf::VideoMode (WIDTH, HEIGHT), "vector32.ru");


    while (window.isOpen ()) {

        sf::Event event {};

        while (window.pollEvent (event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    window.close ();
                break;

                case sf::Event::MouseMoved:
                   light.set_coord (sys.transfer_x (event.mouseMove.x), 
                                    sys.transfer_y (event.mouseMove.y), 
                                    light.get_z ());
                break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Up) {
                        light.set_z (light.get_z () + 50);
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        light.set_z (light.get_z () - 50);
                    }
                break;

                default:
                break;
            }
        }

/////////////////////////////////////////////////DRAW
        window.clear (sf::Color::Black);

        // sys.draw_sphere (&window, light);
        r_vector vec (100, 100, 0);
        r_vector norm = vec.get_perpendicular ();

        sys.draw_vec_2D (&window, vec,  point (0, 0, 0));
        sys.draw_vec_2D (&window, norm, point (0, 0, 0));

        window.display ();
    }



/////////////////////////////////////////////////
    puts ("SUCCESFUL END OF PROG =)");
    return 0;
}
