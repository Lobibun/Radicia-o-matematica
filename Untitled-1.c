#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include <stdio.h>

void txt(const char *texto, int atrasotxt)
{
    for (int i = 0; texto[i] != '\0';
    i++) {
        printf("%c", texto[i]);
        fflush(stdout);
        Sleep(atrasotxt);


    }
}
void enter() {
    int c;
    do {
        c = getchar();
        
    }while (c != '\n'); 
}

main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
     system("chcp 65001"); 
    int atp=4;
    txt("=====================================================", atp);
    txt("\n      Ajuda de jorge\n\n", atp);
    txt("Jorge � um homem cego ele precisa de ajuda\n", atp);
    txt("O problema � que ele s� fala uma lingua, a da radicia��o\n", atp);
    txt("as n�o h� problema, j� que voc� � o mestre em radicia��o\n", atp);
    txt("Ir�o surgir os problemas e s� a resposta correta far� com que Jorge chegue em seguran�a\n", atp);
    txt("Boa sorte\n\n", atp);
    txt("Pressione [enter] para come�ar: ", atp);
    enter();

}