
/** TP 5ETI IMI- CPE Lyon - 2015-2016 */



#include "lib/common/error_handling.hpp"

#include "discrete/bresenham.hpp"
#include "discrete/line_discrete.hpp"
#include "discrete/line_interpolation_parameter.hpp"
#include "image/image.hpp"
#include "image/drawer.hpp"
#include "discrete/triangle_scanline.hpp"
#include "image/image_zbuffer.hpp"
#include "lib/mesh/mesh.hpp"
#include "lib/mesh/mesh_io.hpp"
#include "render_engine/render_engine.hpp"
#include "lib/3d/mat4.hpp"
#include "lib/3d/mat3.hpp"
#include "image/texture.hpp"

#include <iostream>
#include <fstream>
#include <cmath>



using namespace cpe;

int main(int argc,char *argv[])
{

    std::cout<<"***********************"<<std::endl;
    std::cout<<"run "<<argv[0]<<" with "<<argc-1<<" parameters ... \n"<<std::endl;


    try
    {
        int const Nx = 1000;
        int const Ny = 1000;

        image im(Nx,Ny);
        image_zbuffer iz(Nx, Ny);
        im.fill({1.0f,1.0f,1.0f});

        //question 4 
        /*************************************
         * Trace d une ligne verticale avec degrade du noir au blanc
         */
        /*
        float coef4 = Ny * 1.0f;
        for(int k=0; k< Ny; k++)
            im(int(Nx/2),k) = color(k/coef4, k/coef4, k/coef4);
        im.save("imagequestion4.ppm");
        */

        //question 7 
        /**************************************
         * Test des exceptions
         */
         
        //std::cout<<im(Nx+1,10)<<std::endl;

        //Q8 une image derive de la classe image_basic, donnees stockees en rgb(255) sur un fichier .ppm
/*
        //Question 9
        /*************************************
         * utilisation de la structure line_discrete
         * Nx = 20 et Ny = 20;
         */
        /****
        line_discrete line;
        line.push_back(ivec2(4,5));
        line.push_back({5,6});
        ivec2 const p(6,7);
        line.push_back(p);
        std::cout<<line<<std::endl;

        //premiere methode de parcours de la ligne
        for(int k=0;k<line.size();++k)
        std::cout<<line[k]<<" ";
        std::cout<<std::endl;
        //deuxieme methode de parcours de la ligne
        for(ivec2 const& p : line)
        std::cout<<p<<" ";
        std::cout<<std::endl;

        line_discrete line2;
        std::cout<<line2<<std::endl;
        draw_line(im,ivec2(5,5),ivec2(12,9),color(1.0f,0.0f, 0.0f));
        draw_line(im,ivec2(0,0),ivec2(1,10),color(1.0f,0.0f, 0.0f));
        *****/

        //question 17
        /*************************************
         * interpollation (couleur)
         */
        /********
        line_discrete line;
        bresenham({5,5},{12,9},line);
        std::cout<<line<<std::endl;
        line_interpolation_parameter interpolation(line);
        std::cout<<interpolation<<std::endl;
        //draw_line(image& im,ivec2 const& p0,ivec2 const& p1,color const& c0,color const& c1)
        draw_line(im,ivec2(5,5),ivec2(12,9),blue , red);
        *******/

        //question 19
        /**************************************
         * affichage d un triangle avec une couleur unique 
         */

        //draw_triangle_wireframe(im, ivec2(0,0), ivec2(3,3), ivec2(5,0), red);

        //question 20
        /***************************************
         * test fonction scanline
         */
        /**** 
        draw_triangle_wireframe(im , {15,12},{2,17},{6,3} , {0,0,0});
        auto scanline = triangle_scanline_factory({15,12},{2,17},{6,3} ,
        0.0f,1.0f,2.0f);
        std::cout<<scanline<<std::endl;
        *****/

        //question 24
        /****************************************
         * trace d un triangle plein de couleur uniforme 
         */ 
        //draw_triangle(im , {0,0},{5,5},{8,0} , blue);

        //question 26 
        /*****************************************
         * trace d un triangle plein de couleur variable
         */     
        //draw_triangle(im , {15,12},{2,17},{6,3} , color(1,0,0), color(0,1,0), color(0,0,1));

        //question 29 
        /*****************************************
         * Trace d un triangle ayant une couleur et une profondeur associee a chacun de ses sommets
         */
        // Nx = 300 et Ny = 300
        /****
        draw_triangle(im, iz, {15,12},{60,170},{200,3}, color(1,0,1), color(1,0,1), color(1,0,1),0.5f,0.25f,0.75f);
        draw_triangle(im, iz, {12,12},{170,170},{230,3}, red, blue, blue,0.9f,0.9f, 0.9f);
        *****/

        //Partie 6 moteur de rendu pour un triangle 
        /*******************************************/

        mat4 model; //identitee
        mat4 view;  //identitee
        mat4 projection;
        //matrice de projection angle de vue de 60 degres,
        // image de taille carree,
        // sommets visibles entre z=0.1 et z=20.
        projection.set_projection_perspective(60*M_PI/180.0f,1.0f,0.1f,20.0f);

        //Illumination de Phong
        /*
        vec3 p0 = {-1,-1,0};
        vec3 p1 = {1,-1,-1};
        vec3 p2 = {1,1,0};
        vec3 n0, n1, n2;
        vec3 p01 = p1 -p0;
        vec3 p02 = p2 - p0;
        vec3 p21 = p1 - p2;
        vec3 p20 = -1*p02;
        vec3 p10 = -1*p01;
        vec3 p12 = -1*p21;
        n0 = normalized(cross(p01,p02)); 
        n1 = normalized(cross(p10,p12)); 
        n2 = normalized(cross(p20,p21)); 
        render(im, iz, p0, p1, p2, red, green, green, n0, n1, n2, model, view, projection);
        */
        
        
        // Maillage
        //chargement du fichier
        mesh m = load_mesh_file("projet/data/Frankie/Frankie.obj");
                  
        //applique potentiellement une rotation, translation
        //(scaling possible egalement)
        m.transform_apply_rotation({0,1,0},-M_PI/4.0f);
       // m.transform_apply_rotation({0,1,0},-M_PI);
        m.transform_apply_translation({0,0,-1.5f});
        m.fill_color({1,1,1}); //applique la couleur blanche 
        m.fill_normal(); //calcul automatique des normales
        render(im, iz, m, model, view, projection);
       
    im.save("mon_image.ppm");
    iz.save("imazezbuffer.ppm");
    }
    catch(cpe::exception_cpe const& e)
    {


        std::cout<<"**********************************"<<std::endl;
        std::cout<<"**********************************"<<std::endl;
        std::cout<<"Exception found"<<std::endl;
        std::cout<<e.info()<<std::endl;
        std::cout<<"\nSaving backtrace in file backtrace_log.txt"<<std::endl;
        std::cout<<"**********************************"<<std::endl;
        std::cout<<"**********************************"<<std::endl;


        std::ofstream back_file("backtrace_log.txt");
        back_file<<e.info()<<std::endl;
        back_file<<e.info_backtrace();
        back_file.close();

        exit(1);
    }


    std::cout<<"Exit Main"<<std::endl;

    return 0;
}
