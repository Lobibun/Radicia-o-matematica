#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include<conio.h>

#define vida_maxima 3
#define tamanho_da_pista 48
#define passos_por_acerto 10
#define total_de_perguntas_por_nivel 7
#define pool_de_perguntas 10

typedef struct {
    char pergunta[100];
    int resposta;
} Questao;


void txt(const char *texto, int atrasotxt)
{
    for (int i = 0; texto[i] != '\0';
    i++) {
        printf("%c", texto[i]);
        fflush(stdout);
        Sleep(atrasotxt);


    }
}void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void desenharTela(int vida, int posicao, const char* avatar) {
    system("cls");
    gotoxy(0, 0);
    printf("VIDA: ");
    for (int i = 0; i < vida; i++) {
        printf("\x03 "); 
    }
    for (int i = vida; i < vida_maxima; i++) {
        printf("  ");
    }
    printf("\n\n");
    printf("|");
    for (int i = 0; i < tamanho_da_pista; i++) {
        printf("=");
    }
    printf(" \u2691\n"); 
    gotoxy(posicao + 1, 3);
    printf("%s", avatar);
    gotoxy(0, 6);
}

void enter() {
  
    while (_getch() != '\r');
    printf("\n");
}
void mostrarTelaDeAjuda(int dificuldade) {
    system("cls");
    int atp = 1;
    gotoxy(0, 2);
    
    switch (dificuldade) {
        case 1:
            txt("--- DICAS PARA O NIVEL FACIL ---\n\n", atp);
            txt("1. Raiz Quadrada (V): Encontre o numero que, multiplicado por si mesmo, da o valor original.\n", atp);
            txt("   Exemplo: V25 = 5, pois 5 * 5 = 25.\n\n", atp);
            txt("2. Raiz Cubica (V): Encontre o numero que, multiplicado 3 VEZES, da o valor original.\n", atp);
            txt("   Exemplo: V27 = 3, pois 3 * 3 * 3 = 27.\n\n", atp);
            txt("3. Contas Dentro da Raiz: SEMPRE resolva a conta DENTRO da raiz PRIMEIRO!\n", atp);
            txt("   Exemplo: V(30 - 5) -> Primeiro faca 30 - 5 = 25 -> Agora calcule V25 = 5.\n", atp);
            break;
            
        case 2:
            txt("--- DICAS PARA O NIVEL MEDIO ---\n\n", atp);
            txt("Lembre-se das regras do nivel facil!\n\n", atp);
            txt("1. Raiz Quarta (V): Busque um numero que, multiplicado 4 VEZES, da o valor original.\n", atp);
            txt("   Exemplo: V81 = 3, pois 3 * 3 * 3 * 3 = 81.\n\n", atp);
            txt("2. Potencias Dentro da Raiz (x²): Resolva as potencias antes de somar ou subtrair.\n", atp);
            txt("   Exemplo: V(5² - 3²) -> Resolva 25 - 9 = 16 -> Agora calcule V16 = 4.\n\n", atp);
            txt("3. Raiz de Raiz: Comece resolvendo a raiz mais interna.\n", atp);
            txt("   Exemplo: V(V81) -> Primeiro resolva V81 = 9 -> Agora calcule V9 = 3.\n", atp);
            break;
            
        case 3:
            txt("--- DICAS PARA O NIVEL DIFICIL ---\n\n", atp);
            txt("Voce precisa dominar todas as regras anteriores!\n\n", atp);
            txt("1. Potenciacao (x^y): Um numero elevado a uma potencia significa multiplica-lo por si mesmo.\n", atp);
            txt("   Exemplo: 4³ = 4 * 4 * 4 = 64.\n\n", atp);
            txt("2. Raiz como Expoente: As vezes, o resultado de uma raiz vira a potencia de outro numero.\n", atp);
            txt("   Exemplo: 2^(V64) -> Primeiro resolva V64 = 4 -> Agora calcule 2^4 = 16.\n\n", atp);
            txt("3. ORDEM DAS OPERACOES: Siga a ordem correta!\n", atp);
            txt("   1º Raizes e Potencias -> 2º Multiplicacao e Divisao -> 3º Soma e Subtracao.\n", atp);
            txt("   Exemplo: (V100 - 2^4) -> Resolva V100=10 e 2^4=16 -> Agora faca 10 - 16 = -6.\n", atp);
            break;
    }
    
    printf("\n\n\n");
    printf("Pressione [ENTER] para voltar ao jogo...");
    enter();
}

int main()
{
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL,"Portuguese_Brazil");
     system("chcp 65001"); 
    int atp=4;
    int dificuldade = 0;

    txt("=====================================================\n", atp);
    txt("               Ajuda de Jorge\n\n", atp);
    txt("Jorge é um homem cego e ele precisa de sua ajuda.\n", atp);
    txt("O problema é que ele só entende uma língua: a da radiciação.\n", atp);
    txt("Mas não há problema, já que você é o mestre em radiciação!\n\n", atp);
    txt("Para cada pergunta que você acertar, Jorge dará um passo seguro.\n", atp);
    txt("Cuidado! Cada erro o deixará mais vulnerável.\n", atp);
    txt("Boa sorte!\n\n", atp);
     do {
    txt("Escolha o nivel de dificuldade: \n", atp);
    txt("Facil[1]:\nMedio[2]:\nDificil[3]: ", atp);
     scanf("%d", &dificuldade);
      while(getchar() != '\n'); 
      if (dificuldade < 1 || dificuldade > 3)
       {
          printf("\nOpcao invalida! Por favor, escolha 1, 2 ou 3.\n\n");
          Sleep(1500);
          system("cls");
       }   
        } while (dificuldade < 1 || dificuldade > 3);    
       txt("A dificuldade foi selecionada o jogo vai comecar\n\n", atp);

     hideCursor();
     Questao quizFacil[total_de_perguntas_por_nivel][pool_de_perguntas] = {
        /* P1 */ {{"√25 ?", 5}, {"√4 ?", 2}, {"√16 ?", 4}, {"√9 ?", 3}, {"√36 ?", 6}, {"√64 ?", 8}, {"√81 ?", 9}, {"√100 ?", 10}, {"√1 ?", 1}, {"√0 ?", 0}},
    /* P2 */ {{"∛8 ?", 2}, {"√49 ?", 7}, {"∛27 ?", 3}, {"√121 ?", 11}, {"∛64 ?", 4}, {"√9 ?", 3}, {"∛1 ?", 1}, {"√144 ?", 12}, {"∛-8 ?", -2}, {"√16 ?", 4}},
    /* P3 */ {{"√(10+6) ?", 4}, {"√(30-5) ?", 5}, {"√(5*5) ?", 5}, {"√(2*8) ?", 4}, {"√(50/2) ?", 5}, {"√(100-64) ?", 6}, {"√(40+9) ?", 7}, {"√(3*12) ?", 6}, {"√(8*2) ?", 4}, {"√(90-9) ?", 9}},
    /* P4 */ {{"∛(20+7) ?", 3}, {"∛(100-36) ?", 4}, {"√(10*10-19) ?", 9}, {"√81 ?", 9}, {"∛64 ?", 4}, {"√(25+11) ?", 6}, {"∛(120+5) ?", 5}, {"√(1+√9) ?", 2}, {"√(10+√36) ?", 4}, {"∛(30-3) ?", 3}},
    /* P5 */ {{"√9+√16 ?", 7}, {"√25+√4 ?", 7}, {"√64-√1 ?", 7}, {"√100-√49 ?", 3}, {"√36+√16 ?", 10}, {"√81+√9 ?", 12}, {"√144-√4 ?", 10}, {"√1+√0 ?", 1}, {"∛27+√4 ?", 5}, {"∛64-√9 ?", 1}},
    /* P6 */ {{"(√4)*(∛27) ?", 6}, {"(√81)/(∛27) ?", 3}, {"5+√100 ?", 15}, {"√144-10 ?", 2}, {"1+∛125 ?", 6}, {"(√36)*2 ?", 12}, {"10/(√25) ?", 2}, {"√49+∛8 ?", 9}, {"20-√100 ?", 10}, {"(√9)*10 ?", 30}},
    /* P7 */ {{"√(3²+4²) ?", 5}, {"√(10²-6²) ?", 8}, {"√(5²-3²) ?", 4}, {"√(13²-12²) ?", 5}, {"√(3*√9) ?", 3}, {"√(2*∛8) ?", 2}, {"√(3*10-√25) ?", 5}, {"√(4*√49) ?", 5}, {"√(8²+6²) ?", 10}, {"√(2*√16) ?", 4}}
    };

    Questao quizMedio[total_de_perguntas_por_nivel][pool_de_perguntas] = {
    /* P1 */ {{"√144 ?", 12}, {"√121 ?", 11}, {"√169 ?", 13}, {"√196 ?", 14}, {"√225 ?", 15}, {"√256 ?", 16}, {"√289 ?", 17}, {"√324 ?", 18}, {"√361 ?", 19}, {"√400 ?", 20}},
    /* P2 */ {{"∛125 ?", 5}, {"∛216 ?", 6}, {"∛343 ?", 7}, {"∜81 ?", 3}, {"∜16 ?", 2}, {"∛-125 ?", -5}, {"∛512 ?", 8}, {"∜1 ?", 1}, {"∛-27 ?", -3}, {"∜625 ?", 5}},
    /* P3 */ {{"√(10²+21) ?", 11}, {"√(12²+25) ?", 13}, {"√(5³-25) ?", 10}, {"√(200-56) ?", 12}, {"√(100+∛64) ?", 12}, {"√(13²-25) ?", 12}, {"√(20*5+21) ?", 11}, {"√(6²+8²) ?", 10}, {"√(∛729 + 16) ?", 5}, {"√(2*√100 + 5) ?", 5}},
    /* P4 */ {{"√100+∛125 ?", 15}, {"√144-∛8 ?", 10}, {"∜81+√49 ?", 10}, {"∛216+√169 ?", 19}, {"√225-∛27 ?", 12}, {"√400-∛1000 ?", 10}, {"∜16+√121 ?", 13}, {"√196-∛64 ?", 10}, {"√289+∛1 ?", 18}, {"√324-∛-8 ?", 20}},
    /* P5 */ {{"(√100)*(√9) ?", 30}, {"(∛216)*(√4) ?", 12}, {"(√196)/(√4) ?", 7}, {"(∛64)*(√25) ?", 20}, {"(√144)/(∛8) ?", 6}, {"(√225)/(√9) ?", 5}, {"(∛-27)*(√16) ?", -12}, {"(√400)/∛-1 ?", -20}, {"(√16)*(√25) ?", 20}, {"(∛125)*(√1) ?", 5}},
    /* P6 */ {{"(√4)³ ?", 8}, {"(∛8)² ?", 4}, {"(√9)² ?", 9}, {"(∜16)³ ?", 8}, {"(√25)³ ?", 125}, {"(∛-1)⁵ ?", -1}, {"(√16)² ?", 16}, {"(∛125)¹ ?", 5}, {"(∛-27)² ?", 9}, {"(√36/3)² ?", 4}},
    /* P7 */ {{"√(√81) ?", 3}, {"∛(√64) ?", 2}, {"√(∛729) ?", 3}, {"∜(√256) ?", 4}, {"√(√625) ?", 5}, {"√(√16) ?", 2}, {"∛(∛512) ?", 2}, {"∜(∜65536) ?", 4}, {"∜(√1) ?", 1}, {"√(∛125 + 4) ?", 3}}
    };

    Questao quizDificil[total_de_perguntas_por_nivel][pool_de_perguntas] = {
      /* P1 */ {{"(√16)³ ?", 64}, {"(√4)⁵ ?", 32}, {"(∛27)² ?", 9}, {"(∛-8)³ ?", -512}, {"(√9)³ ?", 27}, {"(∜16)⁵ ?", 32}, {"(√25)² ?", 25}, {"(∛-64)² ?", 16}, {"(√100/5)³ ?", 8}, {"(√1)¹⁰⁰ ?", 1}},
    /* P2 */ {{"2^(∛64) ?", 16}, {"3^(√16) ?", 81}, {"5^(∛8) ?", 25}, {"10^(√4) ?", 100}, {"4^(√9) ?", 64}, {"2^(√25) ?", 32}, {"8^(√4) ?", 64}, {"1^(√400) ?", 1}, {"7^(∛(√64)) ?", 49}, {"9^(√4) ?", 81}},
    /* P3 */ {{"(∛1000)/(√4) ?", 5}, {"(√144)/(∛-27) ?", -4}, {"(√121)*(∛8) ?", 22}, {"(∜256)/(√16) ?", 1}, {"(√169*0) ?", 0}, {"(√400)/(√25) ?", 4}, {"(∛-216)/2 ?", -3}, {"(√36)*(√9) ?", 18}, {"(∜81)*(√49) ?", 21}, {"(√100)/(-√25) ?", -2}},
    /* P4 */ {{"∜(100-19) + 5² ?", 28}, {"(∛(3³))*10 ?", 30}, {"(√25+√16)² ?", 81}, {"20-(√9)³ ?", -7}, {"1+(√4)⁴ ?", 17}, {"(10-∛8)³ ?", 512}, {"(∜16+1)³ ?", 27}, {"5² - √16 ?", 21}, {"(1+√1)² ?", 4}, {"(√100-√64)³ ?", 8}},
    /* P5 */ {{"(∛125)*(√81)-10 ?", 35}, {"100-(√100*∛64) ?", 60}, {"2*(√121+√9) ?", 28}, {"(√400)/(√25)+1 ?", 5}, {"5²+∛216 ?", 31}, {"(√144+∛-8)*5 ?", 50}, {"10*(√9+∛-27) ?", 0}, {"(√169-3)*∛8 ?", 20}, {"25+(√100*√4) ?", 45}, {"(∜625+1)*10 ?", 60}},
    /* P6 */ {{"√((3*√9)+7) ?", 4}, {"∛(2*√100-12) ?", 2}, {"√((∛27)*12) ?", 6}, {"∛(10²+√625) ?", 5}, {"√((√16)*5+5) ?", 5}, {"√((√25)*4+16) ?", 6}, {"∛(2*√169-1) ?", 3}, {"√((∛-8)*-4) ?", 4}, {"√((√49)*2+2) ?", 4}, {"∛(√400+7) ?", 3}},
    /* P7 */ {{"(√144/∛8)³ ?", 216}, {"(∜81+∛-1)³ ?", 8}, {"(√49-∛343)² ?", 0}, {"(10+√25)³ ?", 3375}, {"(√100-2⁴) ?", -6}, {"(∛64/√16)² ?", 4}, {"(√(√256))³ ?", 64}, {"(3+∛-27)² ?", 4}, {"(√225/5)² ?", 9}, {"(100-√100)/10 ?", 9}}
    };

    Questao (*bancoDePerguntasAtual)[pool_de_perguntas] = NULL;
      switch (dificuldade) {
        case 1: bancoDePerguntasAtual = quizFacil; break;
        case 2: bancoDePerguntasAtual = quizMedio; break;
        case 3: bancoDePerguntasAtual = quizDificil; break;
    }
 const int passosPorAcerto = 6;
 int vidaDoJogador = vida_maxima;
 int posicaoDoJogador = 0;
int respostaDoUsuario;
 int indicePerguntaAtual = 0;
const char* avatarDoJogador = "(-_-)";
 while (vidaDoJogador > 0 && indicePerguntaAtual <  total_de_perguntas_por_nivel) {
        desenharTela(vidaDoJogador, posicaoDoJogador, avatarDoJogador);

        int indiceAleatorio = rand() % pool_de_perguntas;
printf("PERGUNTA (Nivel %d de %d):\n", indicePerguntaAtual + 1, total_de_perguntas_por_nivel);
        printf("%s\n", bancoDePerguntasAtual[indicePerguntaAtual][indiceAleatorio].pergunta);
        printf("Sua resposta: ");
        scanf("%d", &respostaDoUsuario);
        while(getchar() != '\n');
         if (respostaDoUsuario == bancoDePerguntasAtual[indicePerguntaAtual][indiceAleatorio].resposta) {
            gotoxy(0, 9);
            printf("RESPOSTA CORRETA! Jorge avancou!");
            posicaoDoJogador += passosPorAcerto;
            indicePerguntaAtual++;
            Sleep(1500);
        } else {
            vidaDoJogador--;
            
            desenharTela(vidaDoJogador, posicaoDoJogador, "(X_X)"); 
            gotoxy(0, 9);
            printf("RESPOSTA ERRADA! A resposta certa era %d.", bancoDePerguntasAtual[indicePerguntaAtual][indiceAleatorio].resposta);
            Sleep(2000);
            if (vidaDoJogador > 0) {
                gotoxy(0, 11); // Pula duas linhas para a pergunta
                printf("Deseja ver o quadro de ajuda? (S/N): ");
                char escolhaAjuda;
                scanf(" %c", &escolhaAjuda); // O espaço antes de %c é importante!

                if (escolhaAjuda == 's' || escolhaAjuda == 'S') {
                    mostrarTelaDeAjuda(dificuldade);
                }
            }
        }
    }

    // --- FIM DE JOGO ---
    if (vidaDoJogador <= 0) {
        avatarDoJogador = "(X_X)";
    }
    desenharTela(vidaDoJogador, posicaoDoJogador, avatarDoJogador);
    gotoxy(0, 8);

    if (indicePerguntaAtual >= total_de_perguntas_por_nivel) {
        printf("PARABENS! Voce superou todos os desafios e guiou Jorge em seguranca!\n");
    } else {
        printf("GAME OVER! Infelizmente Jorge nao conseguiu chegar... Tente novamente!\n");
    }

    printf("\n\n\nPressione qualquer tecla para sair...");
    _getch();
    return 0;
}
