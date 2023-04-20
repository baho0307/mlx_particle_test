#include "../particle.h"

t_vector	v_zero()
{
	t_vector	v;

	v.x = 0;
	v.y = 0;
	return (v);
}

t_vector	v_multiplyf(t_vector v, float f)
{
	t_vector	r;

	r.x = v.x * f;
	r.y = v.y * f;
	return (r);
}

t_vector	v_add(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	return (v);
}

float	v_dis(t_vector	a, t_vector	b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}
