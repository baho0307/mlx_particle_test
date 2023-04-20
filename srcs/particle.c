#include "../particle.h"

void	create_sqparticle(float mass, t_program *program, int n)
{
	int			i;

	i = 0;
	program->c_mass_pos.x = 0;
	program->c_mass_pos.y = 0;
	program->mass = 0;
	program->particles = (t_particle *) malloc(sizeof(t_particle) * (n * n + 1));
	while (i < n * n)
	{
		program->particles[i].mass = mass;
		program->mass += mass;
		program->c_mass_pos.x += (i % n) * 2 * mass;
		program->c_mass_pos.y += (i / n) * 2 * mass;
		program->particles[i].pos.x = (i % n) * 2;
		program->particles[i].pos.y = (i / n) * 2;
		program->particles[i].a = v_zero();
		program->particles[i].v = v_zero();
		i++;
	}
	program->c_mass_pos.x /= program->mass;
	program->c_mass_pos.y /= program->mass;
}

void	calc_particles(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->p_count * program->p_count)
	{
		//printf(" %f\n", (program->c_mass_pos.x) * program->particles[i].mass / v_dis(program->c_mass_pos, program->particles[i].pos));
		//getchar();
		program->particles[i].a.x = ((program->c_mass_pos.x) * (program->mass / v_dis(program->c_mass_pos, program->particles[i].pos))) / 1000000;
		program->particles[i].a.x = (program->c_mass_pos.y) * (program->mass / v_dis(program->c_mass_pos, program->particles[i].pos))   / 1000000;
		program->particles[i].v = v_add(program->particles[i].v, program->particles[i].a);
		i++;
	}
	i = 0;
	while (i < program->p_count * program->p_count)
	{
		program->particles[i].pos = v_add(program->particles[i].pos, program->particles[i].v);
		i++;
	}
}
