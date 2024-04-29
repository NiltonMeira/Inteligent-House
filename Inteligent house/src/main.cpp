#include <Arduino.h>
String x = "";

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);

  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

}

void action() {
  String action = x.substring(0, x.indexOf(" "));
  String valor = x.substring(x.indexOf(" ") + 1);

  if (action  == "true") {
    if (valor == "room") {
      digitalWrite(3,1);
    }

    else if (valor == "bedroom")
    {
      digitalWrite(4,1);
    }

    else if (valor == "kitchen")
    {
      digitalWrite(5,1);
    }

    Serial.println( valor + " ON");
    
    return;
  }

  if (action == "false") {
    if (valor == "room") {
      digitalWrite(3,0);
    }

    else if (valor == "bedroom")
    {
      digitalWrite(4,0);
    }

    else if (valor == "kitchen")
    {
      digitalWrite(5,0);
    }

    Serial.println( valor + " OFF");
    
    return;
  }

  Serial.println("Error: invalid param (" + x + ")");
  

}

void  loop() {

  while (Serial.available() == 0);

  char tmp = Serial.read();

  if (tmp == '\0') {
    action();
    x = "";
    return;
  }

  x += tmp;
}