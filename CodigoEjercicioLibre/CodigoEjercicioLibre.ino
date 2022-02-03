#include <DHT.h>
DHT dht (4,DHT22);

int temp;
int humedad;
int boton;
String mensaje;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  dht.begin();
}

void loop() {
  temp = dht.readTemperature();
  humedad = dht.readHumidity();
  mensaje = "{\"temp\":\""+String(temp)+"\",\"humedad\":\""+String(humedad)+"\"}";
  Serial.println (mensaje);

  if (Serial.available() > 0)
  {
    boton = Serial.parseInt();
    if (boton == 1)
    {
      digitalWrite(13,HIGH);
    }
    else
    {
      digitalWrite(13,LOW);
    }
  }
  delay(1000);
}
