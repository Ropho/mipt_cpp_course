#include "general.hpp"

#include "class_r_vector/class_r_vector.hpp"
#include "class_sys/class_sys.hpp"


typedef struct r_clock {

    r_vector sec {};
    r_vector min {};
    r_vector hour{};

}r_clock;


int main (void) {

/////////////////////////////////////////////////
    axys_sys sys {};

    r_vector vec_sec (POLAR, sys.circle_rad - 25, 0);
    r_vector vec_min (POLAR, sys.circle_rad - 25, 0);
    r_vector vec_hour(POLAR, sys.circle_rad / 2,  0);


/////////////////////////////////////////////////SFML
    sf::RenderWindow window (sf::VideoMode (sys.WIDTH, sys.HEIGHT), "vector32.ru");


    while (window.isOpen ()) {

        sf::Event event {};

        while (window.pollEvent (event)) {

            if (event.type == sf::Event::Closed)
                window.close ();


            /////////////////////////////////////TRACE MOUSE
            // if (event.type == sf::Event::MouseMoved)                
                // vec1.set_coord (event.mouseMove.x - sys.WIDTH / 2, sys.HEIGHT / 2 - event.mouseMove.y);
        }

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


/////////////////////////////////////////////////DRAW
        window.clear (sf::Color::Black);

        sys.draw_clock (&window, sys.circle_rad);

        sys.draw (&window, vec_sec,  point (0, 0));
        sys.draw (&window, vec_min,  point (0, 0));
        sys.draw (&window, vec_hour, point (0, 0));

        window.display ();
    }

/////////////////////////////////////////////////
    puts ("SUCCESFUL END OF PROG =)");
    return 0;
}
