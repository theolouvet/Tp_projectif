
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
        im.fill({1.0f,1.0f,1.0f});

        //question 4
       /* for(int k=0; k<= 20; k++)
            im(int(Nx/2),k) = color(k/20.0f,k/20.0f,k/20.0f);*/

        /*im(20,10) = color(1.0f,1.0f,0.0f);
        im(21,10) = color(1.0f,0.0f,0.0f);

        for(int k=0;k<20;++k)
            im(10+k,5) = color(k/20.0f,0.0f,1.0f-k/20.0f);
*/
        //Q7 ca marche bien, on est hors des limites de l image
        //std::cout<<im(91,10)<<std::endl;

        //Q8 une image derive de la classe image_basic, donnees stockees en rgb(255) sur un fichier .ppm
/*
        //Question 9
        line_discrete line;
        line.push_back(ivec2(4,5));
        line.push_back({5,6});
        ivec2 const p(6,7);
        line.push_back(p);
        std::cout<<line<<std::endl;
        // creation d'une ligne discrete
        // ajout d'une position
        // autre methode d'ajout
        // autre methode d'ajout
        // affichage du contenu de la ligne
        //premiere methode de parcours de la ligne
        for(int k=0;k<line.size();++k)
        std::cout<<line[k]<<" ";
        std::cout<<std::endl;
        //deuxieme methode de parcours de la ligne
        for(ivec2 const& p : line)
        std::cout<<p<<" ";
        std::cout<<std::endl;

        //bresenham_first_octant(ivec2 const& p0,ivec2 const& p1,line_discrete& line,int const octant)

        line_discrete line2;
     //   line2.push_back(ivec2(5,5));
      //  line2.push_back({12,9});
       // bresenham(ivec2(12,9),ivec2(5,5), line2);
        std::cout<<line2<<std::endl;

        draw_line(im,ivec2(5,5),ivec2(12,9),color(1.0f,0.0f, 0.0f));
        draw_line(im,ivec2(0,0),ivec2(1,10),color(1.0f,0.0f, 0.0f));
*/
//q17
  /*      line_discrete line;
        bresenham({5,5},{12,9},line);
        std::cout<<line<<std::endl;
        line_interpolation_parameter interpolation(line);
        std::cout<<interpolation<<std::endl;
        //draw_line(image& im,ivec2 const& p0,ivec2 const& p1,color const& c0,color const& c1)
        draw_line(im,ivec2(5,5),ivec2(12,9),color(1.0f,0.0f, 0.0f), color(0.0f,1.0f,0.0f));*/

     //q19   draw_triangle_wireframe(im, ivec2(0,0), ivec2(3,3), ivec2(5,0), color(1,0,0));

       /* draw_triangle_wireframe(im , {15,12},{2,17},{6,3} , {0,0,0});
        auto scanline = triangle_scanline_factory({15,12},{2,17},{6,3} ,
        0.0f,1.0f,2.0f);
        std::cout<<scanline<<std::endl;*/
       /* draw_triangle(im , {0,0},{5,5},{8,0} , color(1,1,0));
        draw_triangle(im , {15,12},{2,17},{6,3} , color(1,0,0), color(0,1,0), color(0,0,1));*/
        image_zbuffer iz(Nx, Ny);
      /*  for(int k = 0; k<15; ++k){
            draw_point(im, iz, ivec2(5,k),-1, color(1,0,0));
            draw_point(im, iz, ivec2(k,5), 0.5 , color(0.0f,1.0f,0.0f));
        }*/

      //  draw_line(im, iz, ivec2(0,0), ivec2(3,3),color(1,0,0), color(0,1,0), 0.25, 0.75);


      //  draw_triangle(im, iz, {15,12},{60,170},{200,3},color(1,0,1), color(1,0,1), color(1,0,1),0.5f,0.25f,0.75f);

        //draw_triangle(im, iz, {12,12},{170,170},{230,3},color(1,0,0), color(0,0,1), color(0,0,1),0.9f,0.9f, 0.9f);

        mat4 model; //identitee
        mat4 view;
        //identitee
        mat4 projection;
        //matrice de projection angle de vue de 60 degres,
        // image de taille carree,
        // sommets visibles entre z=0.1 et z=20.
        projection.set_projection_perspective(60*M_PI/180.0f,1.0f,0.1f,20.0f);

        /*void render(image& im,image_zbuffer& zbuffer,
            vec3 const& p0,vec3 const& p1,vec3 const& p2,
            color const& c0,color const& c1,color const& c2,
            vec3 const& n0,vec3 const& n1,vec3 const& n2,
            mat4 const& model,mat4 const& view,mat4 const& projection
            )*/

/*
            vec3 p0 = {0,0,1};
            vec3 p1 = {1,0,0};
            vec3 p2 = {0,1,0};

*/
            vec3 p0 = {-1,-1,0};
            vec3 p1 = {1,-1,-1};
            vec3 p2 = {1,1,0};



        color c0 = color(1,0,0);
        color c1 = color(1,0,0);
        color c2 = color(1,0,0);


        vec3 n0 = {0,0,0};
        vec3 n1 = {0,0,0};
        vec3 n2  = {0,0,0};

        //sans illumination de phong 
       // render(im, iz, p0, p1, p2, c0, c1, c2, n0, n1, n2, model, view, projection);


        

        vec3 p01 = p1 -p0;
        vec3 p02 = p2 - p0;

        vec3 p21 = p1 - p2;
        vec3 p20 = -1*p02;
        vec3 p10 = -1*p01;
        vec3 p12 = -1*p21;
        

        n0 = normalized(cross(p01,p02)); 
        n1 = normalized(cross(p10,p12)); 
        n2 = normalized(cross(p20,p21)); 
        
       /* vec4 n4 = transposed(inverted(model*view)) * vec4(n0.x(),n0.y(),n0.z(),0);
        n0 = vec3(n4.x(), n4.y(), n4.z());*/
        //std::cout << "n   " << n0 <<std::endl << n1 << std::endl<< n2 <<std::endl;

       
        render(im, iz, p0, p1, p2, c0, c1, c2, n0, n1, n2, model, view, projection);


        //chargement du fichier
        mesh m = load_mesh_file("projet/data/Frankie/Frankie.obj");
        //applique potentiellement une rotation, translation
        //(scaling possible egalement)
        m.transform_apply_rotation({0,1,0},-M_PI/4.0f);
        m.transform_apply_translation({0,0,-1.5f});
        m.fill_color({1,1,1}); //applique la couleur blanche a
        m.fill_normal();
       // render(im, iz, m, model, view, projection);
        //calcul automatique des normales
       
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
