#include <stdio.h>
#include <math.h>


double discriminate (double a, double b, double c)
{
    double d;

    d = pow(b, 2) - 4 * a * c;

    return d;
}

double sq_solve (double a, double b, double c, double d, double mn)
{
    return (-b + mn * sqrt(d)) / (2 * a);
}

double line_solve(double b, double c)
{
    return -c / b;
}

void read_coeff(double *a, const char *s)
{
    printf("enter '%s' coefficient value:  ", s);
    scanf("%lf", a);

}

main()
{
    double a = 0;
    double b = 0;
    double c = 0;

    read_coeff(&a, "a");
    read_coeff(&b, "b");
    read_coeff(&c, "c");

    printf("\nA = %0.2f B = %0.2f C = %0.2f\n", a, b, c);

    printf("____________________________________\n");


    double d = 0;

    d = discriminate(a, b, c);


    if (d < 0)
    {
        printf("there are no salvations\n");
    }
    else if (a != 0)
    {
        double x1 = 0;
        double x2 = 0;

        x1 = sq_solve(a, b, c, d, 1);
        x2 = sq_solve(a, b, c, d, -1);

        if (x1 == x2)
        {
            printf("there is one root:\n");
            printf("\tx = %.2lf\n",x1 );
        }
        else
        {
            printf("there are two roots:\n");
            printf("\tx1 = %.2lf\n\tx2 = %.2lf\n", x1, x2);

        }
    }
    else
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf("x belongs to the set of all numbers\n");
            }
            else
            {
                printf("there are no roots\n");
            }
        }
        else
        {
            double x;

            x = line_solve(b, c);

            printf("there is one root:\n");
            printf("\tx = %.2lf\n", x);
        }
    }

    printf("____________________________________\n");

    return 0;

}
