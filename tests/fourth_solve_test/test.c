#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "mmath.h"

static void	eval(double c[5], double x[4])
{
	double	res;
	int		ok;

	ok = 0;
	for (int i = 0; i < 4; i++)
	{
		double t;
		
		t = x[i];
		res = c[0] * (t * t * t * t)
			+ c[1] * (t * t * t)
			+ c[2] * (t * t)
			+ c[3] * (t)
			+ c[4];
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
	double	c[5];
	double	x[4];

//	c[0] = 91;
//	c[1] = 451;
//	c[2] = 84;
//	c[3] = 5123;

//	c[0] = 2;
//	c[1] = 2;
//	c[2] = 2;
//	c[3] = 2;
//	c[4] = 2;

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

		printf("a: %f b: %f c: %f d: %f e: %f\n", c[0], c[1], c[2], c[3], c[4]);
		solve4(c, x);
		printf("x1: %f x2: %f x3: %f x4: %f\n", x[0], x[1], x[2], x[3]);
		eval(c, x);
	}
}
