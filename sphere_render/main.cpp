#include "class_sys/class_sys.hpp"
#include "class_r_vector/class_r_vector.hpp"


int main (void) {

    axys_sys sys {};
    
    point light (0, 0, 0);

/////////////////////////////////////////////////SFML
    sf::RenderWindow window (sf::VideoMode (sys.WIDTH, sys.HEIGHT), "vector32.ru");


    while (window.isOpen ()) {

        sf::Event event {};

        while (window.pollEvent (event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    window.close ();
                break;

                case sf::Event::MouseMoved:
                   light.set_coord (event.mouseMove.x - sys.WIDTH / 2, -event.mouseMove.y + sys.HEIGHT / 2, light.get_z ());
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

        sys.draw_sphere (&window, light);
        window.display ();
    }

/////////////////////////////////////////////////
    puts ("SUCCESFUL END OF PROG =)");
    return 0;
}
