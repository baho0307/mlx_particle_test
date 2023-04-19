#include "../particle.h"

t_program	create_program(float mass, int n)
{
	t_program	program;

	program.mlx.mlx = mlx_init();
	program.mlx.win = mlx_new_window(program.mlx.mlx, 960, 540, "PARTICLE");
	create_sqparticle(mass, &program, n);
	program.p_count = n;
	return (program);
}

void	calc_cmass(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->p_count * program->p_count)
	{
		program->c_mass_pos.x += program->particles[i].pos.x;
		program->c_mass_pos.y += program->particles[i].pos.y;
	}
	program->c_mass_pos.x /= program->c_mass;
	program->c_mass_pos.y /= program->c_mass;
}
