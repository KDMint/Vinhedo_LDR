# Projeto de Monitoramento de Luz para Vinhedo

Este projeto utiliza um Arduino em conjunto com um sensor LDR (Light Dependent Resistor), LEDs e um buzzer para monitorar a intensidade da luz em um vinhedo. O objetivo é fornecer feedback visual e sonoro sobre os níveis de luz, ajudando os agricultores a determinar se as condições de luz são adequadas para o cultivo das uvas.

## Componentes Utilizados

- `Arduino Uno (ou equivalente)`
- `Sensor LDR`
- `LEDs (vermelho, amarelo e verde)`
- `Buzzer`
- `Resistores`:
  - `LED Vermelho: 220 ohms`
  - `LED Amarelo: 220 ohms`
  - `LED Verde: 220 ohms`
  - `LDR: 10k ohms`

## Funcionamento

O sensor LDR mede a intensidade da luz ambiente e fornece um valor analógico ao Arduino. Com base neste valor, o Arduino controla os LEDs e o buzzer de acordo com os seguintes critérios:

- **LED Vermelho**: Indica que a intensidade da luz está muito alta, o que pode ser prejudicial para o crescimento das uvas.
- **LED Amarelo**: Indica que a intensidade da luz está em um nível mediano. O buzzer emite um sinal sonoro por 3 segundos, repetindo-se em intervalos, para alertar sobre condições de luz moderadas.
- **LED Verde**: Indica que a intensidade da luz está em um nível adequado para o cultivo das uvas.

## Instalação e Configuração

1. Conecte o sensor LDR ao pino analógico A0 do Arduino.
2. Conecte os LEDs vermelho, amarelo e verde aos pinos 12, 11 e 10, respectivamente, utilizando resistores de corrente limitadora adequados.
3. Conecte o buzzer ao pino digital 13 do Arduino.
4. Carregue o código fornecido para o Arduino.

## Código

```cpp
int ledvermelho = 12;  // Pino referente ao LED vermelho
int ledamarelo = 11;    // Pino referente ao LED amarelo
int ledverde = 10;      // Pino referente ao LED verde
int ldr = A0;           // Pino referente ao sensor LDR
int valorldr = 0;       // Valor que será armazenado o valor do LDR
int alarme = 13;        // Pino referente ao alarme (buzzer)

void setup() {
  pinMode(ldr, INPUT);       // LDR sinal de entrada
  pinMode(alarme, OUTPUT);   // Alarme (buzzer) sinal de saída
  pinMode(ledvermelho, OUTPUT);  // LED vermelho sinal de saída
  pinMode(ledamarelo, OUTPUT);    // LED amarelo sinal de saída
  pinMode(ledverde, OUTPUT);      // LED verde sinal de saída
  Serial.begin(9600);         // Inicializa a comunicação serial com a taxa de 9600 bps
}

void loop() {
  valorldr = analogRead(ldr);  // Faz a leitura do pino analógico LDR e armazena o valor na variável valorldr
  Serial.print("LDR : ");      // Mostra o valor no monitor serial
  Serial.println(valorldr);
  
  if (valorldr >= 945) {  // Se o valor do LDR for maior ou igual a 945, ligar LED vermelho
    digitalWrite(ledvermelho, HIGH);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(ledverde, LOW);
  } else if (valorldr > 920 && valorldr < 945) {  // Se o valor do LDR for maior que 920 e menor que 945, ligar LED amarelo e acionar alarme por 3 segundos
    digitalWrite(ledvermelho, LOW);
    digitalWrite(ledamarelo, HIGH);
    digitalWrite(ledverde, LOW);
    
    digitalWrite(alarme, HIGH);
    delay(3000);
    digitalWrite(alarme, LOW);
    delay(3000);
  } else {  // Se o valor do LDR for maior ou igual a 0 e menor ou igual 920, ligar LED verde
    digitalWrite(ledamarelo, LOW);
    digitalWrite(ledverde, HIGH);
    digitalWrite(ledvermelho, LOW);
  }
}
