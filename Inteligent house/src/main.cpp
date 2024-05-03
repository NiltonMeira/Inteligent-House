#include <Arduino.h>
#include <Servo.h>
#include <Keypad.h> // Biblioteca do codigo
#include <Wire.h>

String x = "";
const int pinoBuzzer = 51; // PINO DIGITAL UTILIZADO PELO LED]

const int servoPoortao = 52;
const int servoPorta = 53;

const int pinPir = 49;
const int pinDht = 12;

const int trig = 11;
const int echo = 10;
bool isemiting;
int current_time_millis;
int time_passed_millis;

bool alarm;

Servo meuServo;

const byte LINHAS = 4;
const byte COLUNAS = 4;

const char TECLAS_MATRIZ[LINHAS][COLUNAS] = { // Matriz de caracteres (mapeamento do teclado)
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

const char SENHA[] = {'1', '9', '2', '8', '6', '3'};
char TENTATIVA[6];

const byte PINOS_LINHAS[LINHAS] = {2, 3, 4, 5};   // Pinos de conexao com as linhas do teclado
const byte PINOS_COLUNAS[COLUNAS] = {6, 7, 8, 9}; // Pinos de conexao com as colunas do teclado

Keypad teclado_personalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS); // Inicia teclado

// teclado matrixial 2/9

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.setTimeout(1);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(pinoBuzzer, OUTPUT);

  meuServo.attach(50);

  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  isemiting = false;
 
}

void action()
{
  String action = x.substring(0, x.indexOf(" "));
  String valor = x.substring(x.indexOf(" ") + 1);

  if (action == "true")
  {
    if (valor == "room")
    {
      digitalWrite(3, 1);
    }

    else if (valor == "bedroom")
    {
      digitalWrite(4, 1);
    }

    else if (valor == "kitchen")
    {
      digitalWrite(5, 1);
    }

    else if (valor == "alarm")
    {
      alarm = true;
    }

    else if (valor == "gate")
    {
      openGate();
    }

    else if (valor == "soundalarm")
    {
      tone(pinoBuzzer, 1000);
    }

    else if (valor == "door")
    {
      openGate();
    }

    Serial.println(valor + " ON");

    return;
  }

  if (action == "false")
  {
    if (valor == "room")
    {
      digitalWrite(3, 0);
    }

    else if (valor == "bedroom")
    {
      digitalWrite(4, 0);
    }

    else if (valor == "kitchen")
    {
      digitalWrite(5, 0);
    }

    else if (valor == "alarm")
    {

      alarm = false;
    }

    else if (valor == "gate")
    {
      closeGate();
    }

    else if (valor == "soundalarm")
    {

      noTone(pinoBuzzer);
    }

    else if (valor == "door")
    {
      openGate();
    }

    Serial.println(valor + " OFF");

    return;
  }

  Serial.println("Error: invalid param (" + x + ")");
}
void openGate()
{
  meuServo.write(90);
}

void closeGate()
{
  meuServo.write(-90);
}

double measure_distance()
{
  unsigned long duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2;
}

void loop()
{

  while (Serial.available() == 0)
    ;

  char tmp = Serial.read();

  if (tmp == '\0')
  {
    action();
    x = "";
    return;
  }

  x += tmp;

  if (isemiting && (time_passed_millis >= 20))
  {
    digitalWrite(trig, LOW);
    isemiting = false;
    
    double distance = measure_distance();
    current_time_millis = millis();
  }
  else if (time_passed_millis >= 80)
  {
    digitalWrite(trig, HIGH);
    isemiting = true;
    
    current_time_millis = millis();
  }
}



