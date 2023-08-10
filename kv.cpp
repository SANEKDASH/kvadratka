#include <stdio.h>
#include <math.h>

main()
{
    float a, b, c, d, x1, x2;

    printf("enter the A value: ");
    scanf("%f", &a);

    printf("enter the B value: ");
    scanf("%f", &b);

    printf("enter the C value: ");
    scanf("%f", &c);
    printf("A = %0.2f B = %0.2f C = %0.2f\n", a, b, c);
    printf("____________________________________\n");

    d = pow(b, 2) - 4 * a * c;


    if (d < 0)
    {
        printf("there is no salvations\n");

    }
    else if (a != 0 && b != 0 && c != 0)
    {
        x1 = (b*(-1) + sqrt(d))/(2 * a);
        x2 = (b*(-1) - sqrt(d))/(2 * a);

        printf("x1 = %.2f\nx2 = %.2f\n", x1, x2);
    }
    else if (a == 0 && b != 0 && c != 0)
    {
        x1 = (-1)*c/b;
        printf("x = %0.2f\n", x1);
    }
    else if (a == 0 && b == 0 && c == 0)
    {
        printf("vse chisla");
    }
    else if (a ==0 && b == 0 && c != 0)
    {
        printf("net korney");
    }
    else if (a != 0 && b != 0 && c == 0)
    {
        x1 = (b*(-1) + sqrt(d))/(2 * a);
        x2 = (b*(-1) - sqrt(d))/(2 * a);

        printf("x1 = %.2f\nx2 = %.2f\n", x1, x2);
    }
    printf("____________________________________\n");
    return 0;

}
