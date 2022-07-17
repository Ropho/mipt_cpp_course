#ifndef CLASS_R_VECTOR_HPP
#define CLASS_R_VECTOR_HPP


#include "../general.hpp"
#include "../class_kernel/class_kernel.hpp"


class r_vector : public kernel {
    
    private:
        sf::Color color = {};
        
    public:

        void gen_color (void)      {color = sf::Color (rand () % _UI8_MAX, rand () % _UI8_MAX, 
                                                       rand () % _UI8_MAX, _UI8_MAX);}
        sf::Color get_color () const    {return color;}
        void set_color (sf::Color color_init) {color = color_init;}


        r_vector (size_t, double, double);
        r_vector (void);

       ~r_vector ();
    
        void rotate     (double phi);
        void change_len (double len);


        friend r_vector operator+ (const r_vector& vec1, const r_vector& vec2);
        friend r_vector operator+ (const r_vector& vec,  double num);

        friend r_vector operator- (const r_vector& vec1, const r_vector& vec2);
        friend r_vector operator- (const r_vector& vec,  double num);

        friend double   operator* (const r_vector& vec1, const r_vector& vec2);
        friend r_vector operator* (const r_vector& vec,  double num);


        // friend bool     operator==(r_vector vec1, r_vector vec2);
        friend double   operator^ (const r_vector& vec1, const r_vector& vec2);
        
        r_vector&        operator= (const r_vector& vec);

        void print_coord () const;
};


#endif