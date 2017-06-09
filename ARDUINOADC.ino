
int led_1, led_2, led_3, led_4, led_5, led_6, led_7, led_8, srl_0, srl_1, srl_2, srl_3, srl_4, srl_5, srl_6, srl_7;
float saida, srl_0, srl_1, srl_2, srl_3, srl_4, srl_5, srl_6, srl_7;

void setup()
{
  Serial.begin(19200);
  
  pinMode (2, INPUT);
  pinMode (3, INPUT);
  pinMode (4, INPUT);
  pinMode (5, INPUT);
  pinMode (6, INPUT);
  pinMode (7, INPUT);
  pinMode (8, INPUT);
  pinMode (9, INPUT);
}

void loop()
{
  srl_0 = digitalRead (2);
  srl_1 = digitalRead (3);
  srl_2 = digitalRead (4);
  srl_3 = digitalRead (5);
  srl_4 = digitalRead (6);
  srl_5 = digitalRead (7);
  srl_6 = digitalRead (8);
  srl_7 = digitalRead (9);

  if (srl_0 == HIGH){
      led_1 = 1;
  } else {
      led_1 = 0 ;
  }

  if (srl_1 == HIGH){
      led_2 = 2;
   } else {
      led_2 = 0 ;
   }
  if (srl_2 == HIGH){
      led_3 = 4;
   } else {
      led_3 = 0 ;
   }

  if (srl_3 == HIGH){
      led_4 = 8;
   } else {
      led_4 = 0 ;
   }

  if (srl_4 == HIGH){
      led_5 = 16;
   } else {
      led_5 = 0 ;
   }

  if (srl_5 == HIGH){
      led_6 = 32;
   } else {
      led_6 = 0 ;
   }

  if (srl_6 == HIGH){
      led_7 = 64;
   } else {
      led_7 = 0 ;
   }

	if (srl_7 == HIGH){
      led_8 = 128;
   } else {
      led_8 = 0 ;
   }
  
  saida = (led_1 + led_2 + led_3 + led_4 + led_5 + led_6 + led_7 + led_8) * 0.0196;

  Serial.println(saida);
}
