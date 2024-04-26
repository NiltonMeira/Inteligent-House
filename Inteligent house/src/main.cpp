#include <Arduino.h>

String x = "";

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);
}

void action() {
  String action = x.substring(0, x.indexOf(" "));
  String valor = x.substring(x.indexOf(" ") + 1);

  if (action  == "true") {
    if (valor == "room") {
      
    }
    Serial.println( valor + " ON");
    return;
  }

  if (action == "false") {
    Serial.println( valor + " OFF");
    return;
  }

  Serial.println("Error: invalid param (" + x + ")");
  
  x = "";

}

void  loop() {
  while (Serial.available() == 0);

  char tmp = Serial.read();

  if (tmp == '\0') {
    action();

    return;
  }

  x += tmp;
}