//Carrega as bibliotecas
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <Wire.h>
//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);

//Definindo o pino do DHT
#define DHTPIN 2   
//Definindo o tipo do DHT  
#define DHTTYPE DHT11   // DHT 11  

DHT dht(DHTPIN, DHTTYPE);

//Caracteres Personalizados
//Caractere Personalizado da Logo
byte L[8] = { B01111, B01111, B01111, B01111, B01111, B01111, B00000, B11111 };
byte A[8] = { B11011, B10101, B01110, B01110, B00000, B01110, B01110, B11111 };
byte N[8] = { B01110, B00110, B01010, B01100, B01110, B01110, B01110, B11111 };
byte E[8] = { B00000, B01111, B01111, B00011, B01111, B01111, B00000, B11111 };
byte ponto[8] = { B11111, B11111, B11111, B11111, B11111, B10011, B10011, B11111 };
byte nada[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };

//Caractere personalizado para luminosidade ligada/desligada
byte luz_1[8] = { B00000, B00000, B00010, B01001, B00100, B10010, B01001, B00000 };
byte lampada_1_1[8] = { B00000, B00001, B00011, B00010, B00010, B00011, B00010, B00100 };
byte lampada_1_2[8] = { B00000, B10000, B11000, B01000, B01000, B11000, B01000, B00100 };
byte luz_2[8] = { B10101, B00000, B01001, B10010, B00100, B01001, B00010, B00000 };
byte lampada_2_1[8] = { B01010, B01010, B01010, B01001, B00100, B00011, B00000, B00000 };
byte lampada_2_2[8] = { B00010, B00010, B00010, B00010, B00100, B11000, B00000, B00000 };

//Gota 0 Estado Inicial e Final
byte gota[8] = { B11011, B11011, B10001, B10001, B00000, B00000, B00000, B10001 };
//Gota 0 Caindo 1
byte gota1_1[8] = { B11111, B11011, B11011, B10001, B10001, B00000, B00000, B00000 };
byte gota1_2[8] = { B10001, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };
//Gota 0 Caindo 2
byte gota2_2[8] = { B00000, B10001, B11111, B11111, B11111, B11111, B11111, B11111 };
byte gota2_1[8] = { B11111, B11111, B11011, B11011, B10001, B10001, B00000, B00000 };
//Gota 0 Caindo 3
byte gota3_1[8] = { B11111, B11111, B11011, B11011, B10001, B10001, B00000, B00000 };
byte gota3_2[8] = { B00000, B10001, B11111, B11111, B11111, B11111, B11111, B11111 };
//Gota 0 Caindo 4
byte gota4_2[8] = { B00000, B00000, B10001, B11111, B11111, B11111, B11111, B11111 };
byte gota4_1[8] = { B11111, B11111, B11111, B11011, B11011, B10001, B10001, B00000 };
//Gota 0 Caindo 5
byte gota5_2[8] = { B00000, B00000, B00000, B10001, B11111, B11111, B11111, B11111 };
byte gota5_1[8] = { B11111, B11111, B11111, B11111, B11011, B11011, B10001, B10001 };
//Gota 0 Caindo 6
byte gota6_1[8] = { B11111, B11111, B11111, B11111, B11111, B11011, B11011, B10001 };
byte gota6_2[8] = { B10001, B00000, B00000, B00000, B10001, B11111, B11111, B11111 };
//Gota 0 Caindo 7
byte gota7_2[8] = { B10001, B10001, B00000, B00000, B00000, B10001, B11111, B11111 };
byte gota7_1[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11011, B11011 };
//Gota 0 Caindo 8
byte gota8_1[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11011 };
byte gota8_2[8] = { B11011, B10001, B10001, B00000, B00000, B00000, B10001, B11111 };
  
//Gota 1 Estado inicial
byte gota11_1[8] = { B11111, B11111, B11011, B10001, B10001, B00000, B00000, B10001 };
//Gota 1 Caindo 1
byte gota1_1_2[8] = { B11111, B11111, B11111, B11011, B10001, B10001, B00000, B00000 };
byte gota1_1_1[8] = { B10001, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };
//Gota 1 Caindo 2  
byte gota1_2_2[8] = { B11111, B11111, B11111, B11111, B11011, B10001, B10001, B00000 };
byte gota1_2_1[8] = { B00000, B10001, B11111, B11111, B11111, B11111, B11111, B11111 };
//Gota 1 Caindo 3
byte gota1_3_2[8] = { B11111, B11111, B11111, B11111, B11111, B11011, B10001, B10001 };
byte gota1_3_1[8] = { B00000, B00000, B10001, B11111, B11111, B11111, B11111, B11111 };
//Gota 1 Caindo 4
byte gota1_4_2[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11011, B10001 };
byte gota1_4_1[8] = { B10001, B00000, B00000, B10001, B11111, B11111, B11111, B11111 };
//Gota 1 Caindo 5
byte gota1_5_2[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11011 };
byte gota1_5_1[8] = { B10001, B10001, B00000, B00000, B10001, B11111, B11111, B11111 };
//Gota 1 Caindo 6
byte gota1_6_1[8] = { B11011, B10001, B10001, B00000, B00000, B10001, B11111, B11111 };
//Gota 1 Caindo 7
byte gota1_7_1[8] = { B11111, B11011, B10001, B10001, B00000, B00000, B10001, B11111 };
//Caractere personalizado da temperatura baixa
byte neve1[8] = { B00000, B00000, B00000, B00010, B01001, B11011, B00101, B10011 };
byte neve2[8] = { B00000, B00000, B00000, B10000, B00100, B10110, B01000, B10101 };
byte neve3[8] = { B01110, B10011, B00101, B11011, B01001, B00010, B00000, B00000 };
byte neve4[8] = { B11110, B10101, B01000, B10110, B00100, B10000, B00000, B00000 };
//Caractere personalizado da temperatura alta
byte sol1[8] = { B00000, B00000, B01000, B01001, B00101, B10000, B01011, B00011 };
byte sol2[8] = { B00000, B00000, B10010, B10010, B00100, B00001, B11010, B11000 };
byte sol3[8] = { B00011, B01011, B10000, B00101, B01001, B01000, B00000, B00000 };
byte sol4[8] = { B11000, B11010, B00001, B00100, B10010, B10010, B00000, B00000 };
//Caractere personalizado da temperatura ideal
byte nuvem1[8] = { B00000, B00000, B00000, B00000, B00000, B00001, B00111, B01110 };
byte nuvem2[8] = { B00000, B00000, B00000, B00000, B11000, B11100, B11110, B10110 };
byte nuvem3[8] = { B11111, B11101, B01110, B00011, B00000, B00000, B00000, B00000 };
byte nuvem4[8] = { B11111, B11011, B00110, B11000, B00000, B00000, B00000, B00000 };
//Caractere Personalizado do graus
byte graus[] = { B00000, B00111, B00101, B00111, B00000, B00000, B00000, B00000 };

//Definindo as notas
#define NOTE_D4  294
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_AS4 466

int buzzerPin = 13;//Alarme ligado ao pino 13
int gPin = 5;//Led verde ligada no pino 5
int yPin = 4;//Led amarela ligada no pino 4
int rPin = 3;//Led vermelha ligada no pino 3
int LDR = A0; //LDR ligado ao pino A0

//LDR Caracteristicas
const float GAMMA = 0.7;
const float RL10 = 50;

//Definindo uma variável para as médias
float mediaLux = 0;
float mediaUmidade = 0;
float mediaTemp = 0;

//Defindo uma variável para as médias finais (Após 10 ciclos)
float mediaLux_final = 0;
float mediaUmidade_final = 0;
float mediaTemp_final = 0;


void setup(){
  //Começa o LCD
  lcd.init();
  //Define o número de colunas e linhas do LCD
  lcd.begin(16,2);
  //Liga a luz de fundo
  lcd.backlight();
  //Define os pinos como saída  
  pinMode(buzzerPin,OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(yPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  //Define os pinos de saída
  pinMode(LDR, INPUT);
  //Inicia o Serial do Arduino
  Serial.begin(9600);

  dht.begin();

  tone(buzzerPin, NOTE_D4);//Toca a nota no Buzzer
  digitalWrite(rPin, HIGH);//Led vermelho liga
  digitalWrite(yPin, HIGH);//Led amarelo liga
  digitalWrite(gPin, HIGH);//Led verde liga
  delay(250);
  tone(buzzerPin, NOTE_F4);
  LedsOff(); //Chama a função que desliga todos os LEDS
  delay(250);
  tone(buzzerPin, NOTE_G4); //Toca a nota no Buzzer
  digitalWrite(rPin, HIGH);//Led vermelho liga
  digitalWrite(yPin, HIGH);//Led amarelo liga
  digitalWrite(gPin, HIGH);//Led verde liga
  delay(250);
  tone(buzzerPin, NOTE_AS4); //Toca a nota no Buzzer
  LedsOff(); //Chama a função que desliga todos os LEDS
  delay(250);
  noTone(buzzerPin); //Buzzer para de tocar

  logo(); //Chama a função da logo
}

void loop(){
  
  //Variável para guardar o tempo inicial
  unsigned long intervalo = millis();

  for(int i = 0; i < 10; i++){
    Serial.print("Ciclo ");
    Serial.println(i+1);
    if(millis() - intervalo <= 5000){
      Luminosidade(); //Chama a função da Luminosidade
      intervalo = millis(); //Atualiza o valor do intervalo
    }
    if(millis() - intervalo <= 5000){
       Umidade();//Chama a função da Umidade
       intervalo = millis(); //Atualiza o valor do intervalo
    }
    if(millis() - intervalo <= 5000){
       Temperatura();//Chama a função da Temperatura
       intervalo = millis(); //Atualiza o valor do intervalo
    }
  }

  Final_10_Ciclos();
}
// Função para mostrar a logo na tela
void logo(){

  lcd.createChar(5, nada);

  //Limpa a tela
  lcd.clear();
  
  //Posiciona o cursor na coluna 6, linha 0;
  lcd.setCursor(6, 0);
  //Imprime o texto entre aspas no LCD
  lcd.print("L.A.");
  //Posiciona o cursor na coluna 6, linha 1;
  lcd.setCursor(6, 1);
  //Imprime o texto entre aspas no LCD
  lcd.print("N.E.");

  delay(200);
  
  
  //Imprime o byte todo preenchido variás vezes até o final do loop for
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 2; j++) {
      //Posiciona o cursor na coluna j, linha i;
    	lcd.setCursor(i, j);
      //Imprime o byte 5 no LDC
  		lcd.write(byte(5));
        delay(100);
  	}
  }
  
  //Chama a função para Criar um caractere personalizado temporário
  exibirCaracterePersonalizado(L,6,0,0);
  
  delay(100);
  
  //Chama a função para Criar um caractere personalizado temporário
  exibirCaracterePersonalizado(N,6,1,1);
  
  delay(100);
  
  //Chama a função para Criar um caractere personalizado temporário
  exibirCaracterePersonalizado(ponto,7,0,2);
  
  delay(100);
  
  //Chama a função para Criar um caractere personalizado temporário
  exibirCaracterePersonalizado(ponto,7,1,2);
  
  delay(100);
  
  //Chama a função para Criar um caractere personalizado temporário
  exibirCaracterePersonalizado(A,8,0,3);
  
  delay(100);
  
  //Chama a função para Criar um caractere personalizado temporário
  exibirCaracterePersonalizado(E,8,1,4);
  
  delay(100);
  
  //Chama a função para Criar um caractere personalizado temporário
  exibirCaracterePersonalizado(ponto,9,0,2);
  
  delay(100);
  
  //Chama a função para Criar um caractere personalizado temporário
  exibirCaracterePersonalizado(ponto,9,1,2);
  
  delay(100);
  
  for(int i = 10; i < 16; i++) {
    for(int j = 0; j < 2; j++) {
      //Posiciona o cursor na coluna j, linha i;
    	lcd.setCursor(i, j);
      //Imprime o byte 5 no LDC
  		lcd.write(byte(5));
      delay(100);
  	}
  }
}
// Função para a Luminosidade
void Luminosidade(){

  //Zera a média da lux
  mediaLux = 0;

  // Realiza 5 leituras e calcula a média de porcentagem de luz
  for(int i = 0; i < 5; i++){
    //Transforma o valor do LDR em LUX
    int analogValue = analogRead(A0);
    float voltage = analogValue / 1024. * 5;
    float resistance = 2000 * voltage / (1 - voltage / 5);
    float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

    mediaLux += lux; //Adiciona o valor da luminosidade na média

    delay(300);
  }

  lcd.clear(); //Limpa o LCD

  // Calcula a média dividindo pelo número de leituras
  mediaLux /= 5;

  //Se o valor do LDR for maior ou igual que 400
  if(mediaLux >=400){
    lcd.print("Iluminado"); //Imprime o texto entre aspas no LCD
    digitalWrite(rPin, HIGH);//Led vermelho liga
    tone(buzzerPin, 600);//Define o tom do alarme
    //Chama a função para Criar um caractere personalizado temporário
    exibirCaracterePersonalizado(luz_1,13,0,0);
    exibirCaracterePersonalizado(luz_2,13,1,1);
    exibirCaracterePersonalizado(lampada_1_1,14,0,2);
    exibirCaracterePersonalizado(lampada_1_2,15,0,3);
    exibirCaracterePersonalizado(lampada_2_1,14,1,4);
    exibirCaracterePersonalizado(lampada_2_2,15,1,6);

  //Se o valor da média do lux for maior ou igual que 100 e menor que 250
  }else if(mediaLux  >= 100 && mediaLux < 400){
    digitalWrite(yPin, HIGH);//Led amarela liga
    lcd.print("Meia-luz"); //Imprime o texto entre aspas no LCD
    //Chama a função para Criar um caractere personalizado temporário
    exibirCaracterePersonalizado(luz_1,13,0,0);
    exibirCaracterePersonalizado(luz_2,13,1,1);
    exibirCaracterePersonalizado(lampada_1_1,14,0,2);
    exibirCaracterePersonalizado(lampada_1_2,15,0,3);
    exibirCaracterePersonalizado(lampada_2_1,14,1,4);
    exibirCaracterePersonalizado(lampada_2_2,15,1,6);
  //Se o valor do LDR for menor que 150
  }else{
    digitalWrite(gPin, HIGH);//Led verde liga
    lcd.print("Escuro"); //Imprime o texto entre aspas no LCD
    //Chama a função para Criar um caractere personalizado temporário
    exibirCaracterePersonalizado(lampada_1_1,14,0,2);
    exibirCaracterePersonalizado(lampada_1_2,15,0,3);
    exibirCaracterePersonalizado(lampada_2_1,14,1,4);
    exibirCaracterePersonalizado(lampada_2_2,15,1,6);
  }
  lcd.setCursor(0, 1); //Posiciona o cursor
  lcd.print("Lux: "); //Imprime o texto entre aspas no LCD
  lcd.print(mediaLux); //Exibe a variável no display

  Serial.print("Lux: ");
  Serial.println(mediaLux); // Mostra esse valor no Monitor Serial
  
  //Atualiza a média final do Lux
  mediaLux_final += mediaLux;
  
  delay(4000);
  //Chama a função de desligar todos os LEDS
  LedsOff();
  //Desliga o buzzer
  noTone(buzzerPin);
  
  
}
// Função para a Umidade
void Umidade(){
  float somaUmidade = 0;      // Variável para armazenar a soma das umidades lidas
  int numLeituras = 5;        // Número de leituras a serem feitas

  // Realiza várias leituras em um intervalo de 5 segundos
  for (int i = 0; i < numLeituras; i++) {
    float Umidade = dht.readHumidity();        // Lê a umidade do sensor

    // Verifica se houve falha na leitura e sai do loop se houver
    if (isnan(mediaUmidade)) {
      Serial.println(F("Falha ao ler o sensor DHT!"));
      return;
    }

    // Adiciona os valores lidos à soma total
    somaUmidade += Umidade;

    // Aguarda 1 segundo antes de fazer a próxima leitura
    delay(100);
  }

  // Calcula a média da umidade lida
  mediaUmidade = somaUmidade / numLeituras;

  // Imprime a média das umidades no monitor serial
  Serial.print(("Média da Umidade: "));
  Serial.print(mediaUmidade);
  Serial.println("%");
 
  lcd.clear(); //Limpa o LCD

  //Conecta as temperaturas com o led!
    if(mediaUmidade >= 70){
    lcd.print("Umi.: "); //Imprime o texto entre aspas no LCD
    lcd.print(mediaUmidade); //Exibe a variável no display
    lcd.print("%"); //Imprime o texto entre aspas no LCD
    lcd.setCursor(0,1); //Posiciona o cursor
    lcd.print("Alta"); //Imprime o texto entre aspas no LCD
    digitalWrite(rPin, HIGH);//Led vermelho liga
    tone(buzzerPin, 600);//Define o tom do alarme
    gotaCaindoAlto(); //Chama a função para uma animação de gota caindo
  //Se o valor da média da umidade for maior ou igual que 70 e menor que 50
  }else if(mediaUmidade  >= 50 && mediaUmidade < 70){
    lcd.print("Umi.: "); //Imprime o texto entre aspas no LCD
    lcd.print(mediaUmidade); //Exibe a variável no display
    lcd.print("%"); //Imprime o texto entre aspas no LCD
    lcd.setCursor(0,1); //Posiciona o cursor
    lcd.print("Ok"); //Imprime o texto entre aspas no LCD
    digitalWrite(gPin, HIGH);//Led verde liga
    gotaCaindoMedio(); //Chama a função para uma animação de gota caindo
  //Se a media da umidade for menor que 50
  }else{
    lcd.print("Umi.: "); //Imprime o texto entre aspas no LCD
    lcd.print(mediaUmidade); //Exibe a variável no display
    lcd.print("%"); //Imprime o texto entre aspas no LCD
    lcd.setCursor(0,1); //Posiciona o cursor
    lcd.print("Baixo"); //Imprime o texto entre aspas no LCD
    digitalWrite(rPin, HIGH);//Led vermelho liga
    tone(buzzerPin, 600);//Define o tom do alarme
    gotaCaindoBaixo(); //Chama a função para uma animação de gota caindo
  }

  mediaUmidade_final += mediaUmidade ; //Adiciona o valor da média da umidade na média final

  //Chama a função de desligar todos os LEDS
  LedsOff();
  //Desliga o Buzzer
  noTone(buzzerPin);
}
// Função para a Temperatura
void Temperatura(){
  float somaTemperatura = 0;  // Variável para armazenar a soma das temperaturas lidas
  int numLeituras = 5;        // Número de leituras a serem feitas

  // Realiza várias leituras em um intervalo de 5 segundos
  for (int i = 0; i < numLeituras; i++) {
    float armazeTemperatura = dht.readTemperature();  // Lê a temperatura do sensor

    // Verifica se houve falha na leitura e sai do loop se houver
    if (isnan(armazeTemperatura)) {
      Serial.println(F("Falha ao ler o sensor DHT!"));
      return;
    }

    // Adiciona os valores lidos à soma total
    somaTemperatura += armazeTemperatura;

    // Aguarda 0,1 segundo antes de fazer a próxima leitura
    delay(100);
  }

  // Calcula a média das temperaturas  lidas
  mediaTemp = somaTemperatura / numLeituras;
  
  mediaTemp_final += mediaTemp; //Adiciona o valor da média da temperatura na média final

  lcd.clear(); //Limpa o LCD
  //Conecta as temperaturas com o led!
    if(mediaTemp >= 15){
    lcd.print("Temp.: "); //Imprime o texto entre aspas no LCD
    lcd.print(mediaTemp); //Exibe a variável no display
    exibirCaracterePersonalizado(graus,11,0,7); //Chama a função para Criar um caractere personalizado temporário
    lcd.print("C"); //Imprime o texto entre aspas no LCD
    lcd.setCursor(0,1); //Posiciona o cursor
    lcd.print("Alta"); //Imprime o texto entre aspas no LCD
    digitalWrite(yPin, HIGH);//Led vermelho liga
    tone(buzzerPin, 600);//Define o tom do alarme
    //Chama a função para Criar um caractere personalizado temporário
    exibirCaracterePersonalizado(sol1,14,0,0);
    exibirCaracterePersonalizado(sol3,14,1,1);
    exibirCaracterePersonalizado(sol2,15,0,2);
    exibirCaracterePersonalizado(sol4,15,1,3);
  //Se o valor da média da temperatura for maior ou igual que 10 e menor que 50
  }else if(mediaTemp  >= 10 && mediaTemp <= 15){
    lcd.print("Temp.: "); //Imprime o texto entre aspas no LCD
    lcd.print(mediaTemp); //Exibe a variável no display
    exibirCaracterePersonalizado(graus,11,0,7); //Chama a função para Criar um caractere personalizado temporário
    lcd.print("C"); //Imprime o texto entre aspas no LCD
    lcd.setCursor(0,1); //Posiciona o cursor
    lcd.print("Ok"); //Imprime o texto entre aspas no LCD
    digitalWrite(gPin, HIGH);//Led verde liga
    //Chama a função para Criar um caractere personalizado temporário
    exibirCaracterePersonalizado(nuvem1,14,0,0);
    exibirCaracterePersonalizado(nuvem3,14,1,1);
    exibirCaracterePersonalizado(nuvem2,15,0,2);
    exibirCaracterePersonalizado(nuvem4,15,1,3);
  //Se a media da temperatura for menor que 50
  }else{
    lcd.print("Temp.: ");
    lcd.print(mediaTemp); //Exibe a variável no display
    exibirCaracterePersonalizado(graus,11,0,7); //Chama a função para Criar um caractere personalizado temporário
    lcd.print("C");
    lcd.setCursor(0,1); //Posiciona o cursor
    lcd.print("Baixo");
    digitalWrite(yPin, HIGH);//Led vermelho liga
    tone(buzzerPin, 600);//Define o tom do alarme
    //Chama a função para Criar um caractere personalizado temporário
    exibirCaracterePersonalizado(neve1,14,0,0);
    exibirCaracterePersonalizado(neve3,14,1,1);
    exibirCaracterePersonalizado(neve2,15,0,2);
    exibirCaracterePersonalizado(neve4,15,1,3);
  }
  // Imprime a média das temperaturas e umidades no monitor serial
  Serial.print(F("Média da Temperatura: "));
  Serial.print(mediaTemp);
  Serial.println(F("°C "));

  // Aguarda alguns segundos antes de fazer outra leitura
  delay(4000);
  //Chama a função de desligar todos os LEDS
  LedsOff();
}
// Função para calcular a média depois de 10 ciclos
void Final_10_Ciclos(){

  lcd.clear(); //Limpa o LCD

  //Faz as médias dos valores
  mediaLux_final /= 10;
  mediaUmidade_final /= 10;
  mediaTemp_final /= 10;

  //
  lcd.setCursor(5, 0); //Posiciona o cursor
  lcd.print("Media"); //Imprime o texto entre aspas no LCD
  lcd.setCursor(6, 1); //Posiciona o cursor
  lcd.print("Final"); //Imprime o texto entre aspas no LCD
  delay(2000);

  lcd.clear(); //Limpa o LCD

  lcd.setCursor(2, 0); //Posiciona o cursor
  lcd.print("Luminosidade"); //Imprime o texto entre aspas no LCD
  lcd.setCursor(3, 1); //Posiciona o cursor
  lcd.print("LUX: "); //Imprime o texto entre aspas no LCD
  lcd.print(mediaLux_final); //Exibe a variável no display
  delay(2000);

  lcd.clear(); //Limpa o LCD

  lcd.setCursor(5, 0); //Posiciona o cursor
  lcd.print("Umidade"); //Imprime o texto entre aspas no LCD
  lcd.setCursor(6, 1); //Posiciona o cursor
  lcd.print(mediaUmidade_final); //Exibe a variável no display
  lcd.print("%"); //Imprime o texto entre aspas no LCD
  delay(2000);

  lcd.clear(); //Limpa o LCD

  lcd.setCursor(2, 0); //Posiciona o cursor
  lcd.print("Temperatura"); //Imprime o texto entre aspas no LCD
  lcd.setCursor(5, 1); //Posiciona o cursor
  lcd.print(mediaTemp_final); //Exibe a variável no display
  exibirCaracterePersonalizado(graus,9,1,7);
  lcd.print("C"); //Imprime o texto entre aspas no LCD

  delay(2000);
  lcd.clear(); //Limpa o LCD
  lcd.setCursor(5, 0); //Posiciona o cursor
  lcd.print("FIM"); //Imprime o texto entre aspas no LCD
  
}
// Função para exibir um caractere personalizado no display LCD
void exibirCaracterePersonalizado(byte caractere[],int linha, int coluna, int byt) {
  // Carrega o caractere personalizado na memória do display LCD
  lcd.createChar(byt, caractere);
  // Escreve o caractere personalizado na posição (linha, coluna) do display
  lcd.setCursor(linha, coluna);
  lcd.write(byte(byt)); // Escreve o caractere personalizado
}
// Função para exibir uma animação de gota caindo
void gotaCaindoAlto(){
  unsigned long tempoUmidade = millis(); //Variável de tempo

  while(millis() - tempoUmidade <= 5000){
    lcd.setCursor(14, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    lcd.setCursor(13, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 1
    exibirCaracterePersonalizado(gota,14,0,0);
    //Gota 2
    exibirCaracterePersonalizado(gota11_1,13,1,1);
    //Gota 3
    exibirCaracterePersonalizado(gota1_6_1,15,1,2);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200); 
    //Gota 1
    exibirCaracterePersonalizado(gota1_1,14,0,0);
    exibirCaracterePersonalizado(gota1_2,14,1,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_1_1,13,0,2);
    exibirCaracterePersonalizado(gota1_1_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_7_1,15,1,4);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota2_1,14,0,0);
    exibirCaracterePersonalizado(gota2_2,14,1,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_2_1,13,0,2);
    exibirCaracterePersonalizado(gota1_2_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota11_1,15,1,4);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota3_1,14,0,0);
    exibirCaracterePersonalizado(gota3_2,14,1,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_3_1,13,0,2);
    exibirCaracterePersonalizado(gota1_3_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_1_1,15,0,4);
    exibirCaracterePersonalizado(gota1_1_2,15,1,6);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota4_1,14,0,0);
    exibirCaracterePersonalizado(gota4_2,14,1,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_4_1,13,0,2);
    exibirCaracterePersonalizado(gota1_4_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_2_1,15,0,4);
    exibirCaracterePersonalizado(gota1_2_2,15,1,6);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota5_1,14,0,0);
    exibirCaracterePersonalizado(gota5_2,14,1,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_5_1,13,0,2);
    exibirCaracterePersonalizado(gota1_5_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_3_1,15,0,4);
    exibirCaracterePersonalizado(gota1_3_2,15,1,6);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota6_1,14,0,0);
    exibirCaracterePersonalizado(gota6_2,14,1,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_6_1,13,0,2);
    lcd.setCursor(13, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_4_1,15,0,4);
    exibirCaracterePersonalizado(gota1_4_2,15,1,6);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota7_1,14,0,0);
    exibirCaracterePersonalizado(gota7_2,14,1,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_7_1,13,0,2);
    lcd.setCursor(13, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_5_1,15,0,4);
    exibirCaracterePersonalizado(gota1_5_2,15,1,6);
    delay(200);
    lcd.setCursor(14, 0);
    lcd.write(byte(5)); //Exibe o byte no LCD
    lcd.setCursor(13, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    lcd.setCursor(15, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 1
    exibirCaracterePersonalizado(gota,14,1,0);
    //Gota 2
    exibirCaracterePersonalizado(gota11_1,13,0,1);
    lcd.setCursor(13, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_6_1,15,0,4);
    lcd.setCursor(15, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota1_1,14,1,0);
    exibirCaracterePersonalizado(gota1_2,14,0,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_1_1,13,1,2);
    exibirCaracterePersonalizado(gota1_1_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_7_1,15,0,4);
    lcd.setCursor(15, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota2_1,14,1,0);
    exibirCaracterePersonalizado(gota2_2,14,0,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_2_1,13,1,2);
    exibirCaracterePersonalizado(gota1_2_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota11_1,15,0,4);
    lcd.setCursor(15, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota3_1,14,1,0);
    exibirCaracterePersonalizado(gota3_2,14,0,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_3_1,13,1,2);
    exibirCaracterePersonalizado(gota1_3_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_2_1,15,1,4);
    exibirCaracterePersonalizado(gota1_2_2,15,0,6);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota4_1,14,1,0);
    exibirCaracterePersonalizado(gota4_2,14,0,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_4_1,13,1,2);
    exibirCaracterePersonalizado(gota1_4_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_3_1,15,1,4);
    exibirCaracterePersonalizado(gota1_3_2,15,0,6);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota5_1,14,1,0);
    exibirCaracterePersonalizado(gota5_2,14,0,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_5_1,13,1,2);
    exibirCaracterePersonalizado(gota1_5_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_4_1,15,1,4);
    exibirCaracterePersonalizado(gota1_4_2,15,0,6);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota6_1,14,1,0);
    exibirCaracterePersonalizado(gota6_2,14,0,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_6_1,13,1,2);
    lcd.setCursor(13, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_5_1,15,1,3);
    exibirCaracterePersonalizado(gota1_5_2,15,0,4);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota7_1,14,1,0);
    exibirCaracterePersonalizado(gota7_2,14,0,1);
    //Gota 2
    exibirCaracterePersonalizado(gota1_7_1,13,1,2);
    lcd.setCursor(13, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_6_1,15,1,3);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    lcd.setCursor(14, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    lcd.setCursor(13, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 1
    exibirCaracterePersonalizado(gota,14,0,0);
    //Gota 2
    exibirCaracterePersonalizado(gota11_1,13,1,1);
    //Gota 3
    exibirCaracterePersonalizado(gota11_1,15,1,2);
    //Gota 3
    exibirCaracterePersonalizado(gota1_7_1,15,1,3);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
  }
  tempoUmidade = millis(); //Atualiza o valor do tempoUmidade
}
// Função para exibir uma animação de gota caindo
void gotaCaindoMedio(){
  
  lcd.setCursor(14, 1); //Posiciona o cursor
  lcd.write(byte(5));  //Exibe o byte no LCD
  lcd.setCursor(14, 0); //Posiciona o cursor
  lcd.write(byte(5)); //Exibe o byte no LCD

  unsigned long tempoUmidade = millis();

  while(millis() - tempoUmidade <= 5000){
    lcd.setCursor(13, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 2
    exibirCaracterePersonalizado(gota11_1,13,1,1);
    //Gota 3
    exibirCaracterePersonalizado(gota1_6_1,15,1,2);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_1_1,13,0,2);
    exibirCaracterePersonalizado(gota1_1_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_7_1,15,1,4);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);;
    //Gota 2
    exibirCaracterePersonalizado(gota1_2_1,13,0,2);
    exibirCaracterePersonalizado(gota1_2_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota11_1,15,1,4);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200); 
    //Gota 2
    exibirCaracterePersonalizado(gota1_3_1,13,0,2);
    exibirCaracterePersonalizado(gota1_3_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_1_1,15,0,4);
    exibirCaracterePersonalizado(gota1_1_2,15,1,6);
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_4_1,13,0,2);
    exibirCaracterePersonalizado(gota1_4_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_2_1,15,0,4);
    exibirCaracterePersonalizado(gota1_2_2,15,1,6);
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_5_1,13,0,2);
    exibirCaracterePersonalizado(gota1_5_2,13,1,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_3_1,15,0,4);
    exibirCaracterePersonalizado(gota1_3_2,15,1,6);
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_6_1,13,0,2);
    lcd.setCursor(13, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_4_1,15,0,4);
    exibirCaracterePersonalizado(gota1_4_2,15,1,6);
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_7_1,13,0,2);
    lcd.setCursor(13, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_5_1,15,0,4);
    exibirCaracterePersonalizado(gota1_5_2,15,1,6);
    delay(200);
    lcd.setCursor(13, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    lcd.setCursor(15, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 2
    exibirCaracterePersonalizado(gota11_1,13,0,1);
    lcd.setCursor(13, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_6_1,15,0,4);
    lcd.setCursor(15, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_1_1,13,1,2);
    exibirCaracterePersonalizado(gota1_1_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_7_1,15,0,4);
    lcd.setCursor(15, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_2_1,13,1,2);
    exibirCaracterePersonalizado(gota1_2_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota11_1,15,0,4);
    lcd.setCursor(15, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_3_1,13,1,2);
    exibirCaracterePersonalizado(gota1_3_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_2_1,15,1,4);
    exibirCaracterePersonalizado(gota1_2_2,15,0,6);
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_4_1,13,1,2);
    exibirCaracterePersonalizado(gota1_4_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_3_1,15,1,4);
    exibirCaracterePersonalizado(gota1_3_2,15,0,6);
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_5_1,13,1,2);
    exibirCaracterePersonalizado(gota1_5_2,13,0,3);
    //Gota 3
    exibirCaracterePersonalizado(gota1_4_1,15,1,4);
    exibirCaracterePersonalizado(gota1_4_2,15,0,6);
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_6_1,13,1,2);
    lcd.setCursor(13, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_5_1,15,1,3);
    exibirCaracterePersonalizado(gota1_5_2,15,0,4);
    delay(200);
    //Gota 2
    exibirCaracterePersonalizado(gota1_7_1,13,1,2);
    lcd.setCursor(13, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 3
    exibirCaracterePersonalizado(gota1_6_1,15,1,3);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
    lcd.setCursor(13, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 2
    exibirCaracterePersonalizado(gota11_1,13,1,1);
    //Gota 3
    exibirCaracterePersonalizado(gota11_1,15,1,2);
    //Gota 3
    exibirCaracterePersonalizado(gota1_7_1,15,1,3);
    lcd.setCursor(15, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    delay(200);
  }
  tempoUmidade = millis(); //Atualiza o valor do tempoUmidade
}
// Função para exibir uma animação de gota caindo
void gotaCaindoBaixo(){
  
  lcd.setCursor(15, 1); //Posiciona o cursor
  lcd.write(byte(5)); //Exibe o byte no LCD
  lcd.setCursor(15, 0); //Posiciona o cursor
  lcd.write(byte(5)); //Exibe o byte no LCD
  lcd.setCursor(13, 1); //Posiciona o cursor
  lcd.write(byte(5)); //Exibe o byte no LCD
  lcd.setCursor(13, 0); //Posiciona o cursor
  lcd.write(byte(5));  //Exibe o byte no LCD

  unsigned long tempoUmidade = millis(); //Variável de tempo

  while(millis() - tempoUmidade <= 5000){
    lcd.setCursor(14, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 1
    exibirCaracterePersonalizado(gota,14,0,0);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota1_1,14,0,0);
    exibirCaracterePersonalizado(gota1_2,14,1,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota2_1,14,0,0);
    exibirCaracterePersonalizado(gota2_2,14,1,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota3_1,14,0,0);
    exibirCaracterePersonalizado(gota3_2,14,1,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota4_1,14,0,0);
    exibirCaracterePersonalizado(gota4_2,14,1,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota5_1,14,0,0);
    exibirCaracterePersonalizado(gota5_2,14,1,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota6_1,14,0,0);
    exibirCaracterePersonalizado(gota6_2,14,1,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota7_1,14,0,0);
    exibirCaracterePersonalizado(gota7_2,14,1,1);
    delay(200);
    lcd.setCursor(14, 0); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 1
    exibirCaracterePersonalizado(gota,14,1,0);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota1_1,14,1,0);
    exibirCaracterePersonalizado(gota1_2,14,0,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota2_1,14,1,0);
    exibirCaracterePersonalizado(gota2_2,14,0,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota3_1,14,1,0);
    exibirCaracterePersonalizado(gota3_2,14,0,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota4_1,14,1,0);
    exibirCaracterePersonalizado(gota4_2,14,0,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota5_1,14,1,0);
    exibirCaracterePersonalizado(gota5_2,14,0,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota6_1,14,1,0);
    exibirCaracterePersonalizado(gota6_2,14,0,1);
    delay(200);
    //Gota 1
    exibirCaracterePersonalizado(gota7_1,14,1,0);
    exibirCaracterePersonalizado(gota7_2,14,0,1);
    delay(200);
    lcd.setCursor(14, 1); //Posiciona o cursor
    lcd.write(byte(5)); //Exibe o byte no LCD
    //Gota 1
    exibirCaracterePersonalizado(gota,14,0,0);
    delay(200);
  }
  tempoUmidade = millis(); //Atualiza o valor do tempoUmidade 
}
// Função para desligar todos os LEDS
void LedsOff(){
  digitalWrite(rPin, LOW);//Led vermelho desliga
  digitalWrite(yPin, LOW);//Led amarelo desliga
  digitalWrite(gPin, LOW);//Led verde desliga
}
