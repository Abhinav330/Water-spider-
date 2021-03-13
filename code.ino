 #define motor1 3 
#define motor2 4 
#define touch  12
#define safty 2
int safe;
void setup() {
  Serial.begin(9600);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(touch,INPUT);  
  pinMode(safty,INPUT_PULLUP);
  digitalWrite(motor1 , LOW);
  digitalWrite(motor2 , LOW);
}

void loop() 
{
  int touchh;
  safe = digitalRead(safty); // safty off(ready to use)  = 0 and safty on (Not ready to use) = 1
 
if(safe == 0)
 { 
   touchh = digitalRead(touch); // no touch = 0 and when touched = 1 
   // Serial.print("Switch = "); Serial.println(button);
   // Serial.print("Touch = ") ; Serial.println(touchh);

   if(touchh == 1)
      {
        digitalWrite(motor1 , HIGH);
        digitalWrite(motor2 , LOW);
      }
  
   else if (touchh == 0)
      {
        digitalWrite(motor1 , LOW);
        digitalWrite(motor2 , LOW);
      }
  
 }
else 
  {
    digitalWrite(motor1 , LOW);
    digitalWrite(motor2 , LOW);
  }
delay(100);
}
