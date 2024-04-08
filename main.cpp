
const int pinoPIR = 12; //PINO DIGITAL UTILIZADO PELO SENSOR
const int pinoBuzzer = 10; //PINO DIGITAL UTILIZADO PELO LED

void setup(){
  pinMode(pinoBuzzer, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoPIR, INPUT); //DEFINE O PINO COMO ENTRADA
}
void loop(){
  int pir_state = digitalRead(pinoPIR);
 if(pir_state == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
    tone(pinoBuzzer,1000); //ACENDE O LED
    delay(500);
    noTone(pinoBuzzer);
    delay(2000);
    
 }else{ //SENÃO, FAZ
  noTone(pinoBuzzer); //APAGA O LED
 }
}
