int pinY1=7; // Motora Yönvermek için ayarlanana pinler
int pinY2=8; // Motora Yönvermek için ayarlanana pinler
int pinE1=9; // Enable pini (PWM sinyal için)

void setup() {
  Serial.begin(9600);//serial haberleşmeyi başlattık.
  analogWrite(pinE1,50); // Başlangıçta hızı 50 olacak 
}

void loop() 
{
  if(Serial.available())
  {
   String s1 = Serial.readString();// s1 is String type variable.
 
    if(s1.indexOf("a")>=0)
    {
      digitalWrite(pinY1,HIGH);
      digitalWrite(pinY2,LOW);
      Serial.println("Motor geri");
    }
    else if(s1.indexOf("d")>=0)
    {
      digitalWrite(pinY1,LOW); 
      digitalWrite(pinY2,HIGH);
      Serial.println("Motor ileri");
    }
    else if(s1.indexOf("s")>=0)
    {
      digitalWrite(pinY1,LOW); 
      digitalWrite(pinY2,LOW);
      Serial.println("Motor durdu");
    }
    else
    {
      Serial.print("S1:"); 
      Serial.println(s1.toInt());
      analogWrite(pinE1,s1.toInt());
    } 
  }
}
