short		torus_intersection(void *v_torus, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_torus		*torus;
	double		coefficients[3];
	double		t;

	torus = (t_torus *)v_torus;
	a = (torus->r1 - torus->r0) / 2.0 + torus->r0;
	b = (torus->r1 - torus->r0) / 2.0;
	c = vect3d_dot(torus->pos, torus->axis);
	d = vect3d_dot(start, torus->axis);
	e = vect3d_dot(ray_dir, torus->axis);
	h = e * e + vect3d_dot(q, q);
	j = 2 * (e * d - e * c + vect3d_dot(q, f));
	l = d * d + c * c - 2 * d * c + vect3d_dot(f, f) + a * a - b * b;
	coeff[0] = h * h;
	coeff[1] = 2 * h * j;
	coeff[2] = j * j + 2 * h * l - vect3d_dot(q, q);
	coeff[3] = 2 * j * l - 2 * vect3d_dot(q, f) * a * a;
	coeff[3] = l * l - vect3d_dot(f, f) * a * a;
	// t = get_positive_root(coefficients);
	// if (t < 0)
	// 	return (0);
	// if (intersect_point)
	// 	*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	return (1);
}