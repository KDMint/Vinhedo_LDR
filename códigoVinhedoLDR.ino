// C++ code
//
int ledvermelho = 8; //Pino referente ao LED vermelho
int ledamarelo = 9;   //Pino referente ao LED amarelo
int ledverde = 10;  //Pino referente ao LED verde
int ldr = A0; // Pino referente ao sensor LDR
int valorldr = 0; // valor que sera armazenado o valor do LDR
int alarme = 13; // Pino referente ao alarme (buzzer)
  
void setup(){
 pinMode(ldr, INPUT); //LDR sinal de entrada
 pinMode(alarme, OUTPUT); // Alarme (buzzer) sinal se saida
 pinMode(ledvermelho, OUTPUT); // LED vermelho sinal de saida
 pinMode(ledamarelo, OUTPUT); // LED amarelo sinal de saida
 pinMode(ledverde, OUTPUT); // LED vermelho sinal de saida
 Serial.begin(9600); // // inicializa a comunicação serial com a taxa de 9600 bps
}

void loop(){
  	valorldr = analogRead (ldr); // Faz a leitura do pino analógico LDR e armazena o valor na variavel valorldr
	Serial.print("LDR : "); // Mostra o valor no monitor serial
 	Serial.println(valorldr);
  
  if ((valorldr) >= 945 ) // Se o valorldr for maoir ou igual a 945, ligar LED vermelho
  {
    digitalWrite(ledvermelho, HIGH);
    digitalWrite(ledamarelo, LOW);
    digitalWrite(ledverde, LOW);
	}
  
  else if ((valorldr) > 920 && (valorldr) < 945)// Se o valorldr for maoir que 920 e menor que 945, ligar LED amarelo e acionar alarme por 3 segundos
  {
    digitalWrite(ledvermelho, LOW);
    digitalWrite(ledamarelo, HIGH);
    digitalWrite(ledverde, LOW);
    
    digitalWrite(alarme, HIGH);
    delay(3000);
    digitalWrite(alarme, LOW);
    delay(3000);
    
    }
  
  else // Se valorldr for maior ou igual a 0 e menor ou igual 920, ligar LED verde
  {
    digitalWrite(ledamarelo,LOW);
    digitalWrite(ledverde, HIGH);
    digitalWrite(ledvermelho,LOW);
  	}
}