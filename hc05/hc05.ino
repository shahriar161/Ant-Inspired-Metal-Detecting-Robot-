char Incoming_value = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
    {
      Incoming_value = Serial.read();
      Serial.print(Incoming_value);
      Serial.print("/n");
      if (Incoming_value == '1')
        digitalWrite(10,HIGH);
      else if(Incoming_value == '0')
        digitalWrite(10,LOW);
        
    }
}
