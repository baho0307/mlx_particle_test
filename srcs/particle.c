#include "../particle.h"

void	create_sqparticle(float mass, t_program *program, int n)
{
	int			i;

	i = 0;
	program->c_mass_pos.x = 0;
	program->c_mass_pos.y = 0;
	program->c_mass = 0;
	program->particles = (t_particle *) malloc(sizeof(t_particle) * (n * n + 1));
	while (i < n * n)
	{
		program->particles[i].mass = mass;
		program->c_mass += mass;
		program->c_mass_pos.x += (i % n) * 2 * mass;
		program->c_mass_pos.y += (i / n) * 2 * mass;
		program->particles[i].pos.x = (i % n) * 2;
		program->particles[i].pos.y = (i / n) * 2;
		program->particles[i].a = v_zero();
		program->particles[i].v = v_zero();
		i++;
	}
	program->c_mass_pos.x /= program->c_mass;
	program->c_mass_pos.y /= program->c_mass;
}


