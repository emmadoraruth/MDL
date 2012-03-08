#ifndef DRAW_H
#define DRAW_H

#include "symtab.h"

void boxy_box(struct matrix *points, double x, double y, double z, double h, double w, double d);
void poxy_box(struct matrix *points, double x, double y, double z, double h, double w, double d);
void generate_torus_mesh( struct matrix *points, double r1, double r2,
			  double offx, double offy, double offz , double step);
void render_torus_mesh( struct matrix *points, double r, double r2,
			double offx, double offy, double offz, double step);
void render_sphere_mesh( struct matrix *points, double r,
			 double offx, double offy, double offz, double step);
void generate_sphere_mesh( struct matrix *points, double r,
			   double offx, double offy, double offz, double step);
void render_circle( struct matrix *points, double r, 
		    double offx, double offy, double step);
void generate_circle(struct matrix *points, double r, 
		     double offx, double offy, double step);
void add_point( struct matrix * points, int x, int y, int z);
void draw_lines( struct matrix * points, screen s, color c);
void add_edge( struct matrix * points, 
	       int x0, int y0, int z0, 
	       int x1, int y1, int z1);
void add_polygon( struct matrix * points, 
	       int x0, int y0, int z0, 
		  int x1, int y1, int z1,
		  int x2, int y2, int z2);
void draw_polygons(struct matrix *points, screen s, color c, struct constants *constant, struct zbuff *buff);
void draw_polygon(struct zbuff *buff, int x0, int y0, int z0, int x1, int y1, int z1, int x2, int y2, int z2, color c);
void draw_line(int x0, int y0, int x1, int y1, screen s, color c);
void save_line(struct matrix *points, int x0, int y0, int z0, int x1, int y1, int z1);
void draw_line_buffer(struct zbuff *buff, int x0, int y0, int z0, int x1, int y1, int z1, color c);
void render_polygonal_sphere(struct matrix *points, double r,
			     double offx, double offy, double offz, double step);
void render_polygonal_torus(struct matrix *points, double r1, double r2,
			    double offx, double offy, double offz, double step);
struct matrix *cull(struct matrix *points);
color illumination(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double ar, double ag, double ab, double dr, double dg, double db, double sr, double sg, double sb, double kr, double kg, double kb);
color calc_specular(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double kr, double kg, double kb);
color calc_ambient(double kr, double kg, double kb);
color calc_diffuse(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double kr, double kg, double kb);

#endif
