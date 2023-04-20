#include "../particle.h"

int	render(t_program *program)
{
	calc_cmass(program);
	calc_particles(program);
	create_space(program);
	return (0);
}
