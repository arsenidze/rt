#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "mmath.h"

static void	eval(double c[4], double x[3])
{
	double	res;
	int		ok;

	ok = 0;
	for (int i = 0; i < 3; i++)
	{
		double t;
		
		t = x[i];
		res = c[0] * (t * t * t)
			+ c[1] * (t * t)
			+ c[2] * (t)
			+ c[3];
		printf("res%d: %.10f\n", i, res);
		if (fabs(res) < 1e-5)
		{
			ok = 1;
		}
	}
	if (!ok)
	{
		printf("fail\n");
		exit(1);
	}
}

#define NTESTS 20

int		main()
{
	double	c[4];
	double	x[3];

//	c[0] = 91;
//	c[1] = 451;
//	c[2] = 84;
//	c[3] = 5123;

	srand(time(0));
	for (int i = 0; i < NTESTS; i++)
	{
		c[0] = rand() % 58234 - 6325;
		c[1] = rand() % 96745 - 12312;
		c[2] = rand() % 1205629 - 753158;
		c[3] = rand() % 2453 - 9123;
//	c[0] = 1;
//	c[1] = -3483.915039;
//	c[2] = 176.069595;
//	c[3] = 1277.741943;

		printf("a: %f b: %f c: %f d: %f\n", c[0], c[1], c[2], c[3]);
		solve3(c, x);
		printf("x1: %f x2: %f x3: %f\n", x[0], x[1], x[2]);
		eval(c, x);
	}
}
