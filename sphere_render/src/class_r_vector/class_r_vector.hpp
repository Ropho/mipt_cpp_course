#ifndef CLASS_R_VECTOR_HPP
#define CLASS_R_VECTOR_HPP


#include "../general.hpp"
#include "../class_kernel/class_kernel.hpp"


class r_vector : public kernel {
    
    private:
        sf::Color color = {};
        
    public:

        void gen_color (void)      {color = sf::Color (rand () % UCHAR_MAX, rand () % UCHAR_MAX, 
                                                       rand () % UCHAR_MAX, UCHAR_MAX);}
        sf::Color get_color () const    {return color;}
        void set_color (sf::Color color_init) {color = color_init;}


        r_vector (double fisrt_param, double second_param, double third_param) {
            set_coord (fisrt_param, second_param, third_param);
            gen_color ();
        }

        r_vector (void) {
            set_coord (0, 0, 0);
            gen_color ();
        }

       ~r_vector ()
            {}
    
        r_vector get_perpendicular      () const;
        r_vector get_norm_perpendicular () const;

        // void rotate     (double phi);
        // void change_len (double len);

        friend r_vector operator + (const r_vector& vec1, const r_vector& vec2);
        friend r_vector operator + (const r_vector& vec,  double num);

        friend r_vector operator - (const r_vector& vec1, const r_vector& vec2);
        friend r_vector operator - (const r_vector& vec,  double num);
        friend r_vector operator - (const r_vector& vec);

        friend double   operator * (const r_vector& vec1, const r_vector& vec2);
        friend r_vector operator * (const r_vector& vec,  double num);


        friend r_vector operator / (const r_vector& vec, double num);

        friend double   operator ^ (const r_vector& vec1, const r_vector& vec2);
        friend double   operator ^=(const r_vector& vec1, const r_vector& vec2);


        r_vector&        operator += (const r_vector& vec);
        r_vector&        operator -= (const r_vector& vec);
        r_vector&        operator =  (const r_vector& vec);

        void print_coord () const;
};


#endif