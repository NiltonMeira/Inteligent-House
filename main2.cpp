#include <Servo.h>
#include <Keypad.h> // Biblioteca do codigo
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo meuServo;
const byte LINHAS = 4; // Linhas do teclado
const byte COLUNAS = 4; // Colunas do teclado
LiquidCrystal_I2C lcd(0x3F,16,2);

const char TECLAS_MATRIZ[LINHAS][COLUNAS] = { // Matriz de caracteres (mapeamento do teclado)
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const char SENHA[] = {'1', '9', '2', '8', '6', '3'};
char TENTATIVA[6];

const byte PINOS_LINHAS[LINHAS] = {2, 3, 4, 5}; // Pinos de conexao com as linhas do teclado
const byte PINOS_COLUNAS[COLUNAS] = {6, 7, 8, 9}; // Pinos de conexao com as colunas do teclado

Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS); // Inicia teclado

void setup() {
  Wire.begin();
  Serial.begin(9600); // Inicia porta serial
  meuServo.attach(10);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("hello world!");
}

void loop() {
  lcd.setBacklight(HIGH);
  for(int i = 0; i < 6; i++)
  {
    char leitura_teclas = teclado_personalizado.getKey();
    if(leitura_teclas){
      TENTATIVA[i] = leitura_teclas;
    }
    else{
      i--;
    }
  }

  for(int j = 0; j < 6; j++){
    if(TENTATIVA[j] != SENHA[j]){
      lcd.setCursor(1,0);
      lcd.print("Acesso negado.");
      return;
    }
  }
  lcd.setCursor(1,1);
  lcd.print("Acesso permitido.");


  meuServo.write(90);
  meuServo.write(-90);
}
