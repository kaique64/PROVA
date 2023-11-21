/*

    Circuitos Eletroeletrônicos – ADC4
    
    Link do GitHub: https://github.com/kaique64/PROVA
    
    Grupo:
        Kaique Henrique     RA: 230023798
        Matheus Andreoli    RA: 230022942
        Matheus Sales       RA: 230024102
        Yago Bastos         RA: 230023898
    
    - Objetivo:
        - Desenvolver um programa em linguagem C para auxílio de projeto de circuitos eletroeletrônicos;
    
    - Deverá conter um menu inicial contendo as opções:
        - Circuito divisor de Divisor de tensão;
        - Resistor de LED;
        - Transistor como Chave;
        - Polarização básica do transistor;
        - Polarização por divisor de tensão na base do transistor;
        - Montagem Amplificador Inversor com amp-op;
        - Montagem Amplificador não inversor com amp-op;
        - Sair do programa;
    
*/
#include <stdio.h>
#include <stdlib.h>

char op, fechar;
void cabecalho() { //Yago Bastos
    printf("\t==========================================================\n");
    printf("\t\t    Circuitos Eletroeletrônicos – ADC4\n");
    printf("\t==========================================================\n\n");
}

void limparTela() { //Yago Bastos
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void voltarMenu() { // Matheus Andreoli
    printf("\n\tPressione qualquer tecla para voltar ao menu.");
    scanf("%c%c", &fechar, &fechar); // aguarda uma tecla
}

void divisorDeTensao() { //Matheus Andreoli
    float VS, VM, MAX_CURRENT, TOTAL_RESISTANCE, R1, R2;

    printf("\t=> Divisão de tensão\n\n");

    printf("\tDigite o valor da tensão de entrada VS (V): ");
    scanf("%f", &VS);

    while(VS <= 0) {
        printf("\n\tA tensão de entrada VS não pode ser menor ou igual a zero (0).\n");
        printf("\tDigite o valor da tensão de entrada VS (V): ");
        scanf("%f", &VS);
    }

    printf("\tDigite o valor da tensão de saída VM (V): ");
    scanf("%f", &VM);

    while(VM > VS) {
        printf("\n\tA tensão de saída VM não pode ser maior do que a tensão de entrada VS.\n");
        printf("\tDigite o valor da tensão de saída VM (V): ");
        scanf("%f", &VM);
    }

    printf("\tDigite o valor da corrente máxima do circuito (A): ");
    scanf("%f", &MAX_CURRENT);

    while(MAX_CURRENT <= 0) {
        printf("\n\tA corrente do circuito não pode ser menor ou igual a zero (0).\n");
        printf("\tDigite o valor da corrente máxima do circuito (A): ");
        scanf("%f", &MAX_CURRENT);
    }

    TOTAL_RESISTANCE = VS / MAX_CURRENT;
    R2 = VM / MAX_CURRENT;
    R1 = TOTAL_RESISTANCE - R2;

    printf("\n\tO valor da resistência R1 é: %.3f Ohm", R1);
    printf("\n\tO valor da resistência R2 é: %.3f Ohm\n", R2);

    voltarMenu();
}

void resistorDeLED() { //Kaique Henrique
    
}

void transistorComoChave() { //Matheus Andreoli
    float VS, VCC, IC, IB, VBE = 0.7, RS, RC, Bcc = 10;

    printf("\tDigite o valor da tensão VS (V): ");
    scanf("%f", &VS);

    while(VS <= 0) {
        printf("\n\tA tensão VS não pode ser menor ou igual a zero (0).\n");
        printf("\tDigite o valor da tensão VS (V): ");
        scanf("%f", &VS);
    }

    printf("\tDigite o valor da tensão VCC (V): ");
    scanf("%f", &VCC);

    while(VCC <= 0) {
        printf("\n\tA tensão VCC não pode ser menor ou igual a zero (0).\n");
        printf("\tDigite o valor da tensão VCC (V): ");
        scanf("%f", &VCC);
    }

    printf("\tDigite o valor da corrente IC (A): ");
    scanf("%f", &IC);

    while(IC <= 0) {
        printf("\n\tA corrente IC não pode ser menor ou igual a zero (0).\n");
        printf("\tDigite o valor da corrente IC (A): ");
        scanf("%f", &IC);
    }

    IB = IC / Bcc;
    RS = (VS - VBE) / IB;
    RC = VCC / IC;

    printf("\n\tO valor da resistência RS é: %.3f Ohm", RS);
    printf("\n\tO valor da resistência RC é: %.3f Ohm\n", RC);

    voltarMenu();
}

void polarizacaoBasicaDoTransistor() { //Yago Bastos
    float VS, VCC, VCE, Beta, IC, VBE = 0.7, RS, RC;

    printf("\t=> Polarização básica do transistor\n\n");

    printf("\tDigite o valor de VS (V): ");
    scanf("%f", &VS);

    printf("\tDigite o valor de VCC (V): ");
    scanf("%f", &VCC);

    printf("\tDigite o valor de VCE (V): ");
    scanf("%f", &VCE);

    printf("\tDigite o valor de Beta do transistor: ");
    scanf("%f", &Beta);

    printf("\tDigite o valor de IC de operação (A): ");
    scanf("%f", &IC);

    RS = (VS - VBE) / IC;
    RC = (VCC - VCE) / IC;

    // Verificação de possíveis erros
    if (RS < 0 || RC < 0) {
        printf("\n\tErro: Valores inválidos para RS ou RC.\n");
    } else {
        printf("\n\tValor de RS: %.3f Ohm\n", RS);
        printf("\tValor de RC: %.3f Ohm\n", RC);
    }

    voltarMenu();
}

void polarizacaoPorDivisorDeTensao() { //Kaique Henrique
    
}

void montagemAmplificadorInversor() { //Matheus Sales
    float Vi, Vo, R1, Rf;
    
    printf("\t=>Montagem amplificador inveresor com amp-op\n\n");
    
    printf("\t digite o valor de Vi: ");
    scanf("%f", &Vi);
    
    printf("\t digite o valor de Vo: ");
    scanf("%f", &Vo);
    
    printf("\t digite o valor de R1: ");
    scanf("%f", &R1);

Rf = ((Vo / Vi)*-1) * R1;

    printf("Valor de Rf:%.3f Ohm\n ", Rf);
    
    voltarMenu();
}

void montagemAmplificadorNaoInversor() { //Matheus Sales
    float Vi, Vo, R1,Rf;
    
    printf("\t=>Montagem amplificador nao inveresor com amp-op\n\n");
    
    printf("\t digite o valor de Vi: ");
    scanf("%f", &Vi);
    
    printf("\t digite o valor de Vo: ");
    scanf("%f", &Vo);
    
    printf("\t digite o valor de R1: ");
    scanf("%f", &R1);
    
    Rf = ((Vo / Vi)*-1) * R1;

    printf("Valor de Rf:%.3f Ohm\n ", Rf);
    
    voltarMenu();
    
}

int main() { //Yago Bastos
    int opcao;
    do {
        limparTela();
        cabecalho();
        printf("\t1. Circuito divisor de Divisor de tensão\n");
        printf("\t2. Resistor de LED\n");
        printf("\t3. Transistor como Chave\n");
        printf("\t4. Polarização básica do transistor\n");
        printf("\t5. Polarização por divisor de tensão na base do transistor\n");
        printf("\t6. Montagem Amplificador Inversor com amp-op\n");
        printf("\t7. Montagem Amplificador não inversor com amp-op\n");
        printf("\t8. Sair do programa\n\n");
        printf("\tEscolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                limparTela();
                divisorDeTensao();
                break;
            case 2:
                limparTela();
                resistorDeLED();
                break;
            case 3:
                limparTela();
                transistorComoChave();
                break;
            case 4:
                limparTela();
                cabecalho();
                polarizacaoBasicaDoTransistor();
                break;
            case 5:
                limparTela();
                polarizacaoPorDivisorDeTensao();
                break;
            case 6:
                limparTela();
                montagemAmplificadorInversor();
                break;
            case 7:
                limparTela();
                montagemAmplificadorNaoInversor();
                break;
            case 8:
                limparTela();
                cabecalho();
                printf("\tSaindo do programa...\n");
                break;
            default:
                limparTela();
                cabecalho();
                printf("\tOpção inválida.\n");
                printf("\tAperte qualquer tecla para voltar.");
                scanf("%s",&op);
        }
    } while(opcao != 8);

    return 0;
}

