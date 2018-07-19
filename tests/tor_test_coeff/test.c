#include "mmath.h"
#include "vect3d.h"
#include <stdio.h>
#include <math.h>

t_vect3d	pos;
t_vect3d	axis;
double		r0;
double		r1;
t_vect3d	start;
t_vect3d	ray_dir;
double		t;

void	function1()
{
	t_vect3d	p;
	t_vect3d	c;
	t_vect3d	v;
	t_vect3d	x;
	double		res;

	x = start - pos;
	p = x + vect3d_mult_on_scalar(ray_dir, t);
	//c = pos;
	v = axis;

	double tmp1 = square(vect3d_dot(p, v));
	double tmp2 = square(vect3d_len(p
				+ vect3d_mult_on_scalar(v, vect3d_dot(p, v)))
				- ((r1 - r0) / 2.0 + r0));
	double tmp4 = square((r1 - r0) / 2.0);
	printf("tmp1: %f\n", tmp1);
	printf("tmp2: %f\n", tmp2);
	res = square(vect3d_dot(p, v))
		+ square(vect3d_len(p + vect3d_mult_on_scalar(v, vect3d_dot(p, v)))
			- ((r1 - r0) / 2.0 + r0))
		- square((r1 - r0) / 2.0);
	printf("res1: %f\n", res);
}

void	function11()
{
	t_vect3d	p;
	t_vect3d	c;
	t_vect3d	v;
	double		res;
	double		pvd;
	double		a;
	double		b;
	double		coef;

	p = start + vect3d_mult_on_scalar(ray_dir, t);
	c = pos;
	v = axis;
	pvd = vect3d_dot(p, v);
	a = (r1 - r0) / 2.0 + r0;
	b = (r1 - r0) / 2.0;
	coef = vect3d_dot(c, v);

	double	tmp1;
	double	tmp2;
	double	tmp3;

	tmp1 = square(coef) - 2 * coef * pvd + square(pvd);
	tmp2 = square(vect3d_len(p + vect3d_mult_on_scalar(v, coef - pvd)));
	tmp3 = 2 * vect3d_len(p + vect3d_mult_on_scalar(v, coef - pvd)) * a;

	res = square(coef) - 2 * coef * pvd + square(pvd)
		+ square(vect3d_len(p + vect3d_mult_on_scalar(v, coef - pvd)))
		- 2 * vect3d_len(p + vect3d_mult_on_scalar(v, coef - pvd)) * a
		+ square(a) - square(b);
	printf("res11: %f\n", res);

	printf("tmp1: %f\n", tmp1);
	printf("tmp2: %f\n", tmp2);
	printf("tmp3: %f\n", tmp3);
}

void	function111()
{
	t_vect3d	p;
	t_vect3d	c;
	t_vect3d	v;
	double		res;
	double		pvd;
	double		a;
	double		b;
	double		coef;
	double		d;
	double		e;

	p = start + vect3d_mult_on_scalar(ray_dir, t);
	c = pos;
	v = axis;
	pvd = vect3d_dot(p, v);
	a = (r1 - r0) / 2.0 + r0;
	b = (r1 - r0) / 2.0;
	coef = vect3d_dot(c, v);
	d = vect3d_dot(start, v);
	d = vect3d_dot(ray_dir, v);

	double	tmp1;
	double	tmp2;
	double	tmp3;

	tmp1 = square(coef) - 2 * coef * d - 2 * coef * e * t + square(d)
	   		+ 2 * d * e * t + square(e * t);
	tmp2 = square(vect3d_len(start + vect3d_mult_on_scalar(v, coef - d)
			+ vect3d_mult_on_scalar(ray_dir , t)
			- vect3d_mult_on_scalar(v, e * t)));
	tmp3 = 2 * vect3d_len(start + vect3d_mult_on_scalar(v, coef - d)
			+ vect3d_mult_on_scalar(ray_dir , t)
			- vect3d_mult_on_scalar(v, e * t)) * a;
	
	res = square(coef) - 2 * coef * d - 2 * coef * e * t + square(d)
	   		+ 2 * d * e * t + square(e * t)
		+ square(vect3d_len(start + vect3d_mult_on_scalar(v, coef - d)
			+ vect3d_mult_on_scalar(ray_dir , t)
			- vect3d_mult_on_scalar(v, e * t)))
		- 2 * vect3d_len(start + vect3d_mult_on_scalar(v, coef - d)
			+ vect3d_mult_on_scalar(ray_dir , t)
			- vect3d_mult_on_scalar(v, e * t))
		* a + square(a) - square(b);
	printf("res111: %f\n", res);

	printf("tmp1: %f\n", tmp1);
	printf("tmp2: %f\n", tmp2);
	printf("tmp3: %f\n", tmp3);
}


void	function12()
{
	t_vect3d	p;
	t_vect3d	c;
	t_vect3d	v;
	double		res;
	double		pvd;
	double		a;
	double		b;
	double		coef;
	double		d;
	double		e;
	t_vect3d	q;
	t_vect3d	f;

	p = start + vect3d_mult_on_scalar(ray_dir, t);
	c = pos;
	v = axis;
	pvd = vect3d_dot(p, v);
	a = (r1 - r0) / 2.0 + r0;
	b = (r1 - r0) / 2.0;
	coef = vect3d_dot(c, v);
	d = vect3d_dot(start, v);
	e = vect3d_dot(ray_dir, v);

	q = ray_dir - vect3d_mult_on_scalar(v, e);
	f = start + vect3d_mult_on_scalar(v, coef - d);

	res = square(t * e + d - coef)
		+ vect3d_dot(q, q) * (t * t) + 2 * vect3d_dot(q, f) * t
			+ vect3d_dot(f, f)
		-2 * sqrt(vect3d_dot(q, q) * (t * t) + 2 * vect3d_dot(q, f) * t
			+ vect3d_dot(f, f)) * a + square(a) - square(b);
	printf("res12: %f\n", res);
}

void	function13()
{
	t_vect3d	p;
	t_vect3d	c;
	t_vect3d	v;
	double		res;
	double		pvd;
	double		a;
	double		b;
	double		coef;
	double		d;
	double		e;
	t_vect3d	q;
	t_vect3d	f;

	p = start + vect3d_mult_on_scalar(ray_dir, t);
	c = pos;
	v = axis;
	pvd = vect3d_dot(p, v);
	a = (r1 - r0) / 2.0 + r0;
	b = (r1 - r0) / 2.0;
	coef = vect3d_dot(c, v);
	d = vect3d_dot(start, v);
	e = vect3d_dot(ray_dir, v);

	q = ray_dir - vect3d_mult_on_scalar(v, e);
	f = start + vect3d_mult_on_scalar(v, coef - d);

	res = square(t) * (square(e) + vect3d_dot(q, q))
			+ 2 * t * (e * d - e * coef + vect3d_dot(q, f))
			+ square(d) + square(coef) - 2 * d * coef + vect3d_dot(f, f)
		- 2 * sqrt(vect3d_dot(q, q) * (t * t) + 2 * vect3d_dot(q, f) * t
			+ vect3d_dot(f, f)) * a + square(a) - square(b);
	printf("res13: %f\n", res);
}

void	function14()
{
	t_vect3d	p;
	t_vect3d	c;
	t_vect3d	v;
	double		res;
	double		pvd;
	double		a;
	double		b;
	double		coef;
	double		d;
	double		e;
	double		h;
	double		j;
	double		l;
	t_vect3d	q;
	t_vect3d	f;

	p = start + vect3d_mult_on_scalar(ray_dir, t);
	c = pos;
	v = axis;
	pvd = vect3d_dot(p, v);
	a = (r1 - r0) / 2.0 + r0;
	b = (r1 - r0) / 2.0;
	coef = vect3d_dot(c, v);
	d = vect3d_dot(start, v);
	e = vect3d_dot(ray_dir, v);

	q = ray_dir - vect3d_mult_on_scalar(v, e);
	f = start + vect3d_mult_on_scalar(v, coef - d);

	h = square(e) + vect3d_dot(q, q);
	j = 2 * (e * d - e * coef + vect3d_dot(q, f));
	l = square(d) + square(coef) - 2 * d * coef + vect3d_dot(f, f) + square(a)
		- square(b);

	res = square(t) * h
			+ t * j 
			+ l 
		- 2 * sqrt(vect3d_dot(q, q) * (t * t) + 2 * vect3d_dot(q, f) * t
			+ vect3d_dot(f, f)) * a;
	printf("res14: %f\n", res);
}


void	function2()
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;
	double	h;
	double	j;
	double	l;
	t_vect3d	q;
	t_vect3d	f;
	t_vect3d	x;
	double		coeff[5];

	a = (r1 - r0) / 2.0 + r0;
	b = (r1 - r0) / 2.0;
	c = vect3d_dot(pos, axis);
	d = vect3d_dot(start, axis);
	e = vect3d_dot(ray_dir, axis);

	q = ray_dir - vect3d_mult_on_scalar(axis, e);
	f = start + vect3d_mult_on_scalar(axis, c - d);

	h = e * e + vect3d_dot(q, q);
	j = 2 * (e * d - e * c + vect3d_dot(q, f));
	l = d * d + c * c - 2 * d * c + vect3d_dot(f, f) + a * a - b * b;
	coeff[0] = h * h;
	coeff[1] = 2 * h * j;
	coeff[2] = j * j + 2 * h * l - 4 * a * a * vect3d_dot(q, q);
	coeff[3] = 2 * j * l - 8 * a * a * vect3d_dot(q, f);
	coeff[4] = l * l - 4 * a * a * vect3d_dot(f, f);

	printf("%f %f %f %f %f\n", coeff[0], coeff[1], coeff[2], coeff[3], coeff[4]);
	double	res;

	res = coeff[0] * (t * t * t * t)
		+ coeff[1] * (t * t * t)
		+ coeff[2] * (t * t)
		+ coeff[3] * (t)
		+ coeff[4];
	printf("my_res: %f\n", res);
}

void	function3()
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	h;
	double	j;
	double	k;
	t_vect3d	q;
	t_vect3d	f;
	t_vect3d	x;
	double		coeff[5];

	x = start - pos;
	a = (r1 - r0) / 2.0 + r0;
	b = (r1 - r0) / 2.0;
	c = vect3d_dot(x, axis);
	d = vect3d_dot(ray_dir, axis);
	
	q = x - vect3d_mult_on_scalar(axis, c);
	f = ray_dir - vect3d_mult_on_scalar(axis, d);

	h = vect3d_dot(f, f) + d * d;
	j = 2 * (vect3d_dot(q, f) + c * d);
	k = vect3d_dot(q, q) + c * c + a * a - b * b;

	coeff[0] = h * h;
	coeff[1] = 2 * h * j;
	coeff[2] = j * j + 2 * h * k - square(2 * a) * vect3d_dot(f, f);
	coeff[3] = 2 * j * k - square(2 * a) * 2 * vect3d_dot(q, f);
	coeff[4] = k * k - square(2 * a) * vect3d_dot(q, q);

	double tmp1 = c * c + 2 * c * d * t * square(d * t);
	double tmp2 = square(vect3d_len(q + vect3d_mult_on_scalar(f, t)) - a);
	double tmp3 = vect3d_dot(q, q) + 2 * vect3d_dot(q, f) * t
		+ vect3d_dot(f, f) * t * t;
	double tmp4 = tmp1 + tmp3 + a * a - b * b - 2 * a * sqrt(tmp3);
	printf("tmp1: %f\n", tmp1);
	printf("tmp2: %f\n", tmp2);
	printf("tmp3: %f\n", tmp3);
	printf("tmp4: %f\n", tmp4);

	printf("%f %f %f %f %f\n", coeff[0], coeff[1], coeff[2], coeff[3], coeff[4]);
	double	res;

	res = coeff[0] * (t * t * t * t)
		+ coeff[1] * (t * t * t)
		+ coeff[2] * (t * t)
		+ coeff[3] * (t)
		+ coeff[4];
	printf("my_res: %f\n", res);
}

int main()
{
	pos = (t_vect3d){0, 0, 0};
	axis = (t_vect3d){0, 0, 1};
	r0 = 50;
	r1 = 100;
	start = (t_vect3d){400, 0, 0};
	ray_dir = (t_vect3d){-1, 0, 0};
	t = 300;
	function1();
	function3();
//	for (double i = 300.0; i <= 600.0; i += 0.5)
//	{
//		t = i;
//		function1();
//		function2();
//	}
}
