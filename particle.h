#ifndef PARTICLE_H
#define PARTICLE_H

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_particle
{
	t_vector	pos;
	float		mass;
	t_vector	a;
	t_vector	v;
}	t_particle;

typedef struct s_program
{
	t_mlx		mlx;
	t_particle	*particles;
	int			p_count;
	t_vector	c_mass_pos;
	float		mass;
	float		c_mass;
	t_img		space;
}	t_program;

t_program	create_program(float mass, int n);
void		create_sqparticle(float mass, t_program *program, int n);
void		create_space(t_program *program);
void		my_pixel_put(t_img *data, int x, int y, int color);
int			render(t_program *program);
t_vector	v_zero();
t_vector	v_multiplyf(t_vector v, float f);
t_vector	v_add(t_vector a, t_vector b);
float		v_dis(t_vector	a, t_vector	b);
void		calc_cmass(t_program *program);
void	calc_particles(t_program *program);

#endif
