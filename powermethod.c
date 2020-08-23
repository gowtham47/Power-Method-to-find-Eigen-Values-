//Power method to find eigen value and eigen vector
#include<stdio.h>
#include<math.h>
int main()
{
    float m[40][40], v[40][40], multi[40][40], z[40], e[40], u[40], r, c, vr, vc;
    int i, j, k,n; 
	float a, b, zmax, emax;
    
    printf("\n\nEnter rows and column for matrix: ");
	scanf("%f %f", &r, &c);
    printf("\n\nEnter rows and column for vector: ");
	scanf("%f %f", &vr, &vc);

	printf("\\nnEnter elements of matrix:\n");
	for(i = 0; i < r; ++i)
	{
		for(j = 0; j < c; ++j)
		{
			printf("Enter elements m[%d][%d]: ", i , j);
			scanf("%f", &m[i][j]);
		}
	}

	printf("\n\nEnter elements for vector:\n");
	for(i = 0; i < vr; ++i)
	{
		for(j = 0; j < vc; ++j)
		{
			printf("Enter elements v[%d][%d]: ", i, j);
			scanf("%f", &v[i][j]);
		}
	}
	do
	{
		printf("\n\n\t%f%f",v[0][0],v[1][0]);

		for(i = 0; i < r; ++i)
		{
			for(j = 0; j < vc; ++j)
			{
				multi[i][j] = 0;
			}
		}
		
		for(i = 0; i < r; ++i)
		{
			for(j = 0; j < vc; ++j)
			{
				for(k=0; k<c; ++k)
				{
					multi[i][j] += m[i][k] * v[k][j];
				}
			}
		}
		printf ("\nmu0 %f",multi[0][0]);
		printf ("\nmu1 %f",multi[1][0]);
		z[0]=multi[0][0];
		z[1]=multi[1][0];
		printf ("\n\n\t%f%f",z[0],z[1]);
		u[0]=v[0][0];
		u[1]=v[1][0];
		zmax = fabs(z[0]);
		n = vc;


		for (i=1; i<=n; i++)
		{
			if((fabs(z[i]))>zmax)
					zmax=fabs(z[i]);
		}
		printf("\n\nzmax\t%f",zmax);
		for (i=0; i<=n; i++)
		{
			z[i] = z[i]/zmax;
		}
		printf("\nz new%f%f",z[0],z[1]);
		for (i=0; i<=n; i++)
		{
			e[i] = fabs((fabs(z[i]))-(fabs(u[i])));
		}
		printf("\ne %f%f",e[0],e[1]);
		emax = e[0];
		for (i=1; i<=n; i++)
		{
			if((e[i])>emax)
			emax=(e[i]);
		}		
		printf("\ne new %f%f",e[0],e[1]);
		v[0][0]=z[0];
		v[1][0]=z[1];
		printf ("\n\nv new \t%f%f",v[0][0],v[1][0]);
		printf("\n\nemax \t%f",emax);
	}
	while(emax>0.001);	
	printf("\n The required eigen value is %f",zmax);
return 0;
}
  
	




