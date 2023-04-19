#include "particle.h"

int	main(void)
{
	t_program	program;

	program = create_program(10.0, 20);
	create_space(&program);
	mlx_loop(program.mlx.mlx);
}
