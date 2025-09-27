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
    txt("Jorge é um homem cego ele precisa de ajuda\n", atp);
    txt("O problema é que ele só fala uma lingua, a da radiciação\n", atp);
    txt("as não há problema, já que você é o mestre em radiciação\n", atp);
    txt("Irão surgir os problemas e só a resposta correta fará com que Jorge chegue em segurança\n", atp);
    txt("Boa sorte\n\n", atp);
    txt("Pressione [enter] para começar: ", atp);
    enter();

}
