#include <stdio.h>
main()
{
    int i, n, numero, in, out;
    printf("Insira quantos numeros vao ser pedidos:\n");
    scanf("%i", &n);
    for(i=0; i<n; i++)
    {
        printf("Insira um numero:\n");
        scanf("%i", &numero);
        if(numero>=10 && numero<=20)
        {
            in++;
        }
        else
        {
            out++;
        }
        }
        printf("Ao todo foram %i numeros dentro do intervalo e %i fora do intervalo\n", in, out);

    }
