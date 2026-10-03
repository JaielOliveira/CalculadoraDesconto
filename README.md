# Montar Financeiro

Programa desenvolvido em **C** para auxiliar na montagem de propostas financeiras com aplicação de descontos, cálculo de valores líquidos, entradas e parcelamentos.

O sistema permite trabalhar com diferentes formas de negociação de desconto e apresenta os resultados de maneira organizada, utilizando o padrão monetário brasileiro.

---

## 📋 Sobre o programa

O **Montar Financeiro** foi desenvolvido para facilitar cálculos de negociação de valores.

A partir de um valor original, o usuário pode informar diferentes tipos de desconto, definir uma entrada e informar a quantidade de parcelas. O programa então calcula automaticamente:

* Valor total com desconto;
* Valor do desconto em reais;
* Percentual de desconto;
* Valor da entrada sem desconto;
* Desconto aplicado na entrada;
* Valor efetivamente pago como entrada;
* Valor das parcelas sem desconto;
* Desconto aplicado em cada parcela;
* Valor efetivo de cada parcela.

O programa possui também um **tutorial integrado**, explicando como utilizar cada modalidade de cálculo.

---

## ⚙️ Funcionalidades

### 1. Porcentagem de desconto

Permite informar diretamente o percentual de desconto que será aplicado sobre o valor original.

**Exemplo:**

```text
Valor Total Original: R$ 23.000,00
Percentual de Desconto: 15%
```

O programa calcula automaticamente o valor líquido da negociação.

Essa modalidade é indicada quando o desconto é definido como uma porcentagem fixa.

---

### 2. Valor final (líquido)

Permite informar diretamente qual será o valor final desejado após o desconto.

**Exemplo:**

```text
Valor Total Original: R$ 23.000,00
Valor Total com Desconto: R$ 19.500,00
```

A partir desses valores, o programa calcula qual percentual de desconto representa a negociação.

Essa modalidade é útil quando existe um **valor final específico** que se deseja alcançar.

---

### 3. Valor nominal do desconto

Permite informar diretamente o valor em reais que será concedido como desconto.

**Exemplo:**

```text
Valor Total Original: R$ 23.000,00
Valor do Desconto: R$ 7.000,00
```

O programa calcula:

* Valor líquido;
* Percentual correspondente ao desconto;
* Valores de entrada;
* Valores das parcelas.

Essa modalidade é indicada quando o desconto é negociado como um **valor fixo em reais**.

---

## 💰 Cálculo da entrada e das parcelas

Após definir o desconto, o programa solicita:

```text
Valor da Entrada (Pago)
Qtd Parcelas
```

Com essas informações, o sistema calcula os valores correspondentes à negociação.

Para demonstrar o impacto do desconto, são apresentados os valores **com e sem desconto**.

### Entrada

O programa apresenta:

* **Entrada s/ Desconto**
* **Desconto na Entrada**
* **Entrada c/ Desconto**

### Parcelas

O programa apresenta:

* **Parcela s/ Desconto**
* **Desconto na Parcela**
* **Parcela c/ Desconto**

Dessa forma, é possível visualizar quanto seria pago originalmente e quanto será pago após a aplicação do desconto.

---

## 🧮 Exemplo de utilização

Suponha uma negociação:

```text
Valor original:       R$ 23.000,00
Desconto:             15%
Entrada:              R$ 5.000,00
Parcelas:             6
```

O programa calcula automaticamente o valor líquido e distribui o saldo restante entre as parcelas.

Além disso, apresenta uma comparação entre os valores originais e os valores após o desconto.

O resultado possui uma estrutura semelhante a:

```text
==========================================
            RESULTADOS FINAIS
==========================================
Valor total (calculado):    R$ ...
Valor liquido:              R$ ...

Desconto Aplicado (R$):     R$ ...
Desconto Aplicado (%):      ...%

Entrada s/ Desconto:        R$ ...
Desconto na Entrada:        R$ ...
Entrada c/ Desconto:        R$ ...

Parcela s/ Desconto:        R$ ...
Desconto na Parcela:        R$ ...
Parcela c/ Desconto:        R$ ...
==========================================
```

---

## 🇧🇷 Formatação de valores

O programa foi desenvolvido considerando o padrão monetário utilizado no Brasil.

Os valores podem ser digitados utilizando **vírgula para separar os centavos**:

```text
1500,50
```

Também é possível utilizar pontos para separar milhares:

```text
1.500,50
23.000
23.000,75
```

O programa converte internamente esses formatos para realizar os cálculos.

Os resultados são apresentados no formato:

```text
R$ 1.500,50
R$ 23.000,00
```

---

## 📖 Tutorial integrado

A opção `[4] Tutorial` apresenta instruções sobre as três modalidades de cálculo.

O tutorial explica:

1. Porcentagem de desconto;
2. Valor final (líquido);
3. Valor nominal do desconto;
4. Como informar valores monetários.

Para retornar ao menu principal, basta pressionar **ENTER**.

---

## 🖥️ Menu principal

Ao executar o programa, o usuário encontra o seguinte menu:

```text
===================================
        MONTAR FINANCEIRO
===================================
[1] Porcentagem de desconto (%)
[2] Valor final (líquido)
[3] Valor nominal do desconto
[4] Tutorial
[0] Sair
-----------------------------------
Escolha uma opcao:
```

### Opções

| Opção | Função                                                |
| ----- | ----------------------------------------------------- |
| `1`   | Calcula o desconto a partir de uma porcentagem        |
| `2`   | Calcula o desconto a partir do valor líquido desejado |
| `3`   | Calcula o desconto a partir de um valor nominal       |
| `4`   | Exibe o tutorial de utilização                        |
| `0`   | Encerra o programa                                    |

---

## 🛠️ Tecnologias utilizadas

O projeto foi desenvolvido utilizando:

* **Linguagem:** C
* **Bibliotecas:**

  * `stdio.h`
  * `stdlib.h`
  * `string.h`

O programa utiliza recursos básicos da linguagem C, como:

* Variáveis;
* Funções;
* Estruturas condicionais;
* Estrutura de repetição `while`;
* Entrada e saída de dados;
* Manipulação de strings;
* Conversão de valores;
* Operações matemáticas.

---

## 🧩 Principais funções

### `limpar_buffer()`

Responsável por limpar o buffer de entrada do teclado.

Isso evita que caracteres deixados por operações como `scanf()` interfiram nas próximas leituras.

---

### `limpar_tela()`

Limpa o conteúdo do terminal.

O programa identifica o sistema operacional:

```c
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
```

Dessa forma, utiliza:

* `cls` no Windows;
* `clear` em outros sistemas.

---

### `ler_valor()`

Responsável por receber valores monetários digitados pelo usuário.

A função permite entradas como:

```text
23000
23.000
23.000,50
23000,50
```

Internamente, a função:

1. Lê o valor como texto;
2. Remove pontos de separação de milhares;
3. Converte vírgula decimal para ponto;
4. Mantém os números e o sinal negativo;
5. Converte o resultado para `double`.

---

### `imprimir_moeda()`

Responsável por apresentar os valores no formato monetário brasileiro.

Por exemplo:

```text
23000.50
```

é exibido como:

```text
R$ 23.000,50
```

A função também organiza o alinhamento dos resultados no terminal.

---

### `exibir_tutorial()`

Exibe as instruções de utilização do programa.

A função apresenta exemplos das três formas de aplicação do desconto e explica como os valores devem ser digitados.

---

### `executar_caso()`

É a principal função responsável pelos cálculos financeiros.

Recebe como parâmetro o tipo de operação escolhido:

```c
executar_caso(1);
executar_caso(2);
executar_caso(3);
```

Cada número representa uma modalidade:

```text
1 → Porcentagem
2 → Valor final
3 → Valor nominal
```

A função realiza os cálculos e exibe os resultados.

---

### `main()`

É a função principal do programa.

Responsável por:

* Exibir o menu;
* Receber a opção do usuário;
* Validar a entrada da opção;
* Executar a funcionalidade escolhida;
* Manter o programa em execução até que o usuário escolha `0`.

O menu funciona através de um laço:

```c
while (opcao != 0)
```

Portanto, o programa continua sendo executado até que a opção **Sair** seja selecionada.

---

## 🔢 Fórmulas utilizadas

### Desconto percentual

Quando o desconto é informado em porcentagem:

```text
Valor Líquido = Valor Original × (1 - Desconto / 100)
```

---

### Percentual a partir do valor líquido

Quando o usuário informa o valor final:

```text
Desconto (%) = (1 - Valor Líquido / Valor Original) × 100
```

---

### Desconto nominal

Quando o desconto é informado diretamente em reais:

```text
Valor Líquido = Valor Original - Valor do Desconto
```

O percentual equivalente é calculado por:

```text
Desconto (%) = (Valor do Desconto / Valor Original) × 100
```

---

### Fator de desconto

O programa utiliza um fator para distribuir o desconto proporcionalmente:

```text
Fator = Valor Líquido / Valor Original
```

Esse fator é utilizado para determinar a relação entre os valores com e sem desconto.

---

## 📂 Estrutura sugerida do projeto

```text
MontarFinanceiro/
│
├── main.c
└── README.md
```

Onde:

* `main.c` contém o código-fonte do programa;
* `README.md` contém a documentação do projeto.

---

## ▶️ Como executar

### Windows

Caso esteja utilizando um compilador como **Dev-C++**, **Code::Blocks**, **Visual Studio Code com GCC** ou outro compilador C:

1. Abra o arquivo `main.c`;
2. Compile o programa;
3. Execute o arquivo gerado.

Pelo terminal, utilizando GCC:

```bash
gcc main.c -o montar_financeiro
```

Depois execute:

```bash
montar_financeiro
```

No Windows, dependendo do terminal:

```bash
.\montar_financeiro.exe
```

---

## ⚠️ Observações

O programa utiliza o tipo `double` para representar valores financeiros. Para uma aplicação comercial real, sistemas financeiros normalmente utilizam estratégias específicas para evitar problemas de precisão de ponto flutuante.

Este programa tem como objetivo principal **auxiliar nos cálculos e na montagem de negociações financeiras**, proporcionando uma interface simples para uso em terminal.

---

## 📌 Resumo

O **Montar Financeiro** permite calcular negociações de forma rápida a partir de três diferentes métodos:

```text
┌─────────────────────────────────────────┐
│       MONTAR FINANCEIRO                 │
├─────────────────────────────────────────┤
│ 1. Desconto por porcentagem             │
│ 2. Definição do valor final             │
│ 3. Desconto por valor nominal           │
│ 4. Tutorial                              │
│ 0. Sair                                  │
└─────────────────────────────────────────┘
```

O sistema recebe o valor original, aplica a modalidade de desconto escolhida, considera a entrada e a quantidade de parcelas e apresenta uma visão detalhada dos valores **com e sem desconto**.
