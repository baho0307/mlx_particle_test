#include "../particle.h"

void	create_space(t_program *program)
{
	int	i;

	i = 0;
	program->space.img = mlx_new_image(program->mlx.mlx, 960, 540);
	program->space.addr = mlx_get_data_addr(program->space.img, &program->space.bpp,
		&program->space.line_length, &program->space.endian);
	while (i < program->p_count * program->p_count)
	{
		printf("X: %f, Y: %f\n", program->particles[i].pos.x, program->particles[i].pos.y);
		my_pixel_put(&program->space,
			program->particles[i].pos.x + 480 - program->p_count,
			program->particles[i].pos.y + 270 - program->p_count, 0xFFFFFFFF);
		i++;
	}
	mlx_put_image_to_window(program->mlx.mlx, program->mlx.win,
		program->space.img, 0, 0);
}
