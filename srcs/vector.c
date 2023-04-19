#include "../particle.h"

t_vector	v_zero()
{
	t_vector	v;

	v.x = 0;
	v.y = 0;
	return (v);
}

void	v_multiplyf(t_vector v, float f)
{
	v.x *= f;
	v.y *= f;
}

void	v_add(t_vector v, t_vector u)
{
	v.x += u.x;
	v.y += u.y;
}
