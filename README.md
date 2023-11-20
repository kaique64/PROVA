
# **Objetivo:**
- Desenvolver um programa em linguagem C para auxílio de projeto de circuitos 	eletroeletrônicos;

# **Requisitos**:
- Circuito divisor de Divisor de tensão
  - **Autor:** Matheus Andreoli
- Resistor de LED
  - **Autor:** Kaique Henrique
- Transistor como Chave
  - **Autor:** Matheus Andreoli
- Polarização básica do transistor
  - **Autor:** Yago Bastos
- Polarização por divisor de tensão na base do transistor
  - **Autor:** Kaique Henrique
- Montagem Amplificador Inversor com amp-op
  - **Autor:** Matheus Sales
- Montagem Amplificador não inversor com amp-op
  - **Autor:** Matheus Sales
- Menu
  - **Autor:** Yago Bastos

### **Requisito: Circuito divisor de Divisor de tensão**:
**Autor:** Matheus Andreoli
- Solicitar a tensão de entrada (Vs);
- Solicitar a tensão de saída (Vm);
- Solicitar a corrente máxima no circuito;
- Calcular e Responder com o valor do R1 e do R2;
- Tratar devidamente os possíveis erros;
- Ao final, aguardar uma tecla e voltar para o menu;

### **Requisito: Resistor de LED**:
**Autor:** Kaique Henrique
- Solicitar a tensão de alimentação VF;
- Solicitar a corrente no LED;
- Solicitar a tensão no LED;
- Calcular e responder com o valor do RLED; 
- Tratar os possíveis erros;
- Ao final, aguardar uma tecla e voltar para o menu;

### **Requisito: Transistor como Chave**:
**Autor:** Matheus Andreoli
- Solicitar VS;
- Solicitar VCC;
- Solicitar Ic;
- Adotar VBE como 0,7V;
- Calcular e responder com os valores de Rs e Rc;
- Tratar os possíveis erros;
- Ao final, aguardar uma tecla e voltar para o menu;

### **Requisito: Polarização básica do transistor**:
**Autor:** Yago Bastos
- Solicitar o valor de VS;
- Solicitar o valor de VCC;
- Solicitar o valor de VCE;
- Solicitar o Beta do transistor;
- Solicitar o IC de operação;
- Adotar VBE = 0,7V;
- Calcular e responder com os valores de RS e RC;
- Tratar os possíveis erros;
- Ao final, aguardar uma tecla e voltar para o menu;

### **Requisito: Polarização por divisor de tensão na base do transistor**:
**Autor:** Kaique Henrique
- Solicitar o valor de VCC;
- Solicitar o valor de VCE;
- Solicitar o valor de VRE;
- Solicitar o IC de operação;
- Solicitar o Beta do transistor;
- Adotar VBE = 0,7V;
- Calcular e responder com os valores de R1, R2, RC e RE;
- Tratar os possíveis erros;
- Ao final, aguardar uma tecla e voltar para o menu;

### **Requisito: Montagem Amplificador Inversor com amp-op**:
**Autor:** Matheus Sales
- Solicitar o valor de Vi;
- Solicitar o valor de Vo;
- Solicitar o valor de R1;
- Calcular e retornar o valor de Rf;
- Tratar os possíveis erros;
- Ao final, aguardar uma tecla e voltar para o menu;

### **Requisito: Montagem Amplificador não inversor com amp-op**:
**Autor:** Matheus Sales
- Solicitar o valor de Vi;
- Solicitar o valor de Vo;
- Solicitar o valor de R1;
- Calcular e retornar o valor de Rf;
- Tratar os possíveis erros;
- Ao final, aguardar uma tecla e voltar para o menu;

### **Requisito: Menu**:
**Autor:** Yago Bastos

# Padrões de saída
- Valores de entrada devem ser sempre float
- Valores numéricos decimais devem conter sempre 3 casas decimais (0,000)
- Saída para valores de resistência devem ser retornados sempre em ohms
- Saída para valores de corrente devem ser retornados sempre em amperes
- Saída para valores de tensão devem ser retornados sempre em volts
- Utilizar, sempre, cabeçalho padronizado no projeto
