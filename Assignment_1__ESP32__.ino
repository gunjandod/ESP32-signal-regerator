//Assignment1 ESP32
const int led_1 = 15;
const int led_2 = 21;
const int button_1 = 22;
const int button_2 = 23;
 void setup() {
  Serial.begin(115200);
   pinMode(15, OUTPUT);
   pinMode(21, OUTPUT);
   pinMode(22, INPUT); 
   pinMode(23, INPUT);
 }
 
 void mod_a(int pin, int puls_a, int time_inc, int pause_b, int d) {
   digitalWrite(led_2, HIGH);
   delayMicroseconds(50); 
   digitalWrite(led_2, LOW);
   delayMicroseconds(50);
   for(int i = 0; i < 18; i ++) {
     digitalWrite(pin, HIGH);
     delayMicroseconds(puls_a);
     puls_a = puls_a + time_inc;
     Serial.println(puls_a);
     digitalWrite(pin, LOW);
     delayMicroseconds(pause_b);
     Serial.println("NORMAL MODE");

   }
   digitalWrite(pin, LOW);
   delayMicroseconds(d);
 }

  void mod_b(int pin, int puls_a, int time_inc, int pause_b, int d) {
   digitalWrite(led_2, HIGH);
   delayMicroseconds(50);
   digitalWrite(led_2, LOW);
   delayMicroseconds(50);
   for(int i = 0; i < 15; i ++) {
     digitalWrite(pin, HIGH);
     delayMicroseconds(puls_a);
     puls_a = puls_a - time_inc;
     Serial.println(puls_a);
     digitalWrite(pin, LOW);
     delayMicroseconds(pause_b);
     Serial.println("MODE 1");

   }
   digitalWrite(pin, LOW);
   delayMicroseconds(d);
 }
 
 void loop() {

  if(digitalRead(button_1)==HIGH)
  {
   //mod_a(led_1,700, 50, 2100, 500);
   //Serial.println(puls_a);
   digitalWrite(led_1, LOW);
   digitalWrite(led_2, LOW);
  }
  else if(digitalRead(button_2)==HIGH)
  {
   mod_b(led_1,700, 50, 2100, 500);
   //Serial.println(puls_a);
  }
  else
  {
    mod_a(led_1,700, 50, 2100, 500);
   //Serial.println(puls_a);
   //digitalWrite(led_1, LOW);
   //digitalWrite(led_2, LOW); 
   }
 }
