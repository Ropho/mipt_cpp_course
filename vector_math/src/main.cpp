#include "general.hpp"

#include "class_r_vector/class_r_vector.hpp"
#include "class_sys/class_sys.hpp"
#include "class_clock/clock.hpp"

const size_t HEIGHT = 800;
const size_t WIDTH  = 1200;


//add графическая оболочка
//add NORMALIZE
//add usik norm impl......


int main (void) {


    axys_sys sys_mouse (point (WIDTH / 2, 0), WIDTH / 2, HEIGHT);
    r_vector vec_mouse {};


/////////////////////////////////////////////////
    axys_sys sys_clock (point {}, WIDTH / 2, HEIGHT);

/////////////////////////////////////////////////SFML
    sf::RenderWindow window (sf::VideoMode (WIDTH, HEIGHT), "vector32.ru");


    while (window.isOpen ()) {

        sf::Event event {};

        while (window.pollEvent (event)) {

            if (event.type == sf::Event::Closed)
                window.close ();


            /////////////////////////////////////TRACE MOUSE
            if (event.type == sf::Event::MouseMoved) {
                
                point pnt  (sys_mouse.transfer_x (event.mouseMove.x), 
                            sys_mouse.transfer_y (event.mouseMove.y));

                if (abs (pnt.get_x ()) < sys_mouse.WIDTH_ / 2 && abs (pnt.get_y ()) < sys_mouse.HEIGHT_ / 2)
                    vec_mouse.set_coord (pnt.get_x (), pnt.get_y ());
            }
        }


/////////////////////////////////////////////////DRAW
        window.clear (sf::Color::Black);

        draw_clock (sys_clock, &window);

        sys_mouse.draw_vec  (&window, vec_mouse, point (0, 0));
        sys_mouse.draw_axys (&window);

        window.display ();
    }

/////////////////////////////////////////////////
    puts ("SUCCESFUL END OF PROG =)");
    return 0;
}
