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
    limparTela();
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
    float VF, correnteLED, tensaoLED, RLED;
    printf("\t=> Resistor de LED\n\n");

    printf("\tDigite a tensao de alimentacao VF (V): ");
    if (scanf("%f", &VF) != 1) {
        printf("\tEntrada invalida para a tensao de alimentacao VF.\n");
    }

    printf("\tDigite a corrente no LED (A): ");
    if (scanf("%f", &correnteLED) != 1) {
        printf("\tEntrada invalida para a corrente no LED.\n");
    }

    printf("\tDigite a tensao no LED (V): ");
    if (scanf("%f", &tensaoLED) != 1) {
        printf("\tEntrada invalida para a tensao no LED.\n");
    }

    // Verificando se a corrente ou a tensão do LED são zero para evitar divisão por zero
    if (correnteLED == 0 || tensaoLED == 0) {
        printf("\tA corrente ou a tensao no LED nao podem ser zero.\n");
    }

    RLED = (VF - tensaoLED) / correnteLED;

    printf("\tO valor do resistor RLED é: %.2f Ohms\n", RLED);
    voltarMenu();
}

void transistorComoChave() { //Matheus Andreoli
    float VS, VCC, IC, IB, VBE = 0.7, RS, RC, Bcc = 10;
    
    printf("\t=> Transistor como Chave\n\n");
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
    float VS, VCC, VCE, Beta, IC, VBE = 0.7, RS, RC,IB;

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
    
    IB = IC / Beta;
    RS = (VS - VBE) / IB;
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

float obterValor(const char *mensagem) { //Kaique Henrique
    float valor;
    printf("\tDigite o valor de %s: ", mensagem);
    while (scanf("%f", &valor) != 1) {
        printf("\tEntrada invalida para %s. Digite novamente: ", mensagem);
        while (getchar() != '\n'); // Limpar o buffer de entrada
    }
    return valor;
}

float calcularResistenciaR1(float VR1, float VR2, float R2) { //Kaique Henrique
    return VR1 / (VR2 / R2);
}

void polarizacaoPorDivisorDeTensao() { //Kaique Henrique
    float VCC, VCE, VRE, IC, Beta, VBE = 0.7;
    float R1, R2, RC, RE;
    
    printf("\t=> Polarização por divisor de tensão na base do transistor\n\n");
    VCC = obterValor("VCC");
    VCE = obterValor("VCE");
    VRE = obterValor("VRE");
    IC = obterValor("IC");
    Beta = obterValor("Beta do transistor");

    float VRC = VCC - VCE - VRE;
    RC = VRC / IC;
    RE = VRE / IC;
    R2 = 0.1 * Beta * RE;

    float VE = VCC * 0.1;
    float VR2 = VRE + VBE;
    float VR1 = VCC - VR2;
    float IR2 = VR2 / R2;

    R1 = calcularResistenciaR1(VR1, VR2, R2);

    // Exibindo os valores calculados
    printf("\n\tValor de R1: %.2f\n", R1);
    printf("\tValor de R2: %.2f\n", R2);
    printf("\tValor de RC: %.2f\n", RC);
    printf("\tValor de RE: %.2f\n", RE);

    // Aguardar uma tecla antes de retornar
    voltarMenu(); // Aguardar Enter
}

void montagemAmplificadorInversor() { //Matheus Sales
    float Vi, Vo, R1, Rf;
    
    printf("\t=> Montagem amplificador inveresor com amp-op\n\n");
    
    printf("\tDigite o valor de Vi: ");
    scanf("%f", &Vi);
    
    printf("\tDigite o valor de Vo: ");
    scanf("%f", &Vo);
    
    printf("\tDigite o valor de R1: ");
    scanf("%f", &R1);

    Rf = ((Vo / Vi)*-1) * R1;

    printf("\n\tValor de Rf: %.3f Ohm\n ", Rf);
    
    voltarMenu();
}

void montagemAmplificadorNaoInversor() { //Matheus Sales
    float Vi, Vo, R1,Rf;
    
    printf("\t=> Montagem amplificador nao inveresor com amp-op\n\n");
    
    printf("\tDigite o valor de Vi: ");
    scanf("%f", &Vi);
    
    printf("\tDigite o valor de Vo: ");
    scanf("%f", &Vo);
    
    printf("\tDigite o valor de R1: ");
    scanf("%f", &R1);
    
    Rf = R1*((Vo / Vi)-1);

    printf("\n\tValor de Rf: %.3f Ohm\n ", Rf);
    
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
                cabecalho();
                divisorDeTensao();
                break;
            case 2:
                limparTela();
                cabecalho();
                resistorDeLED();
                break;
            case 3:
                limparTela();
                cabecalho();
                transistorComoChave();
                break;
            case 4:
                limparTela();
                cabecalho();
                polarizacaoBasicaDoTransistor();
                break;
            case 5:
                limparTela();
                cabecalho();
                polarizacaoPorDivisorDeTensao();
                break;
            case 6:
                limparTela();
                cabecalho();
                montagemAmplificadorInversor();
                break;
            case 7:
                limparTela();
                cabecalho();
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
                scanf("%c%c",&fechar,&fechar);
        }
    } while(opcao != 8);

    return 0;
}