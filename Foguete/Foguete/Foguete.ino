// CONTROLE DO FOGUETE

const int LED = 13; 
const int MOTOR = 11; 

const int soundDetectedPin = 10; 
const int soundDetectedVal = HIGH; // When there is a noise, becomes LOW !

const int soundAlarmTime = 200; 

void setup ()
{
  Serial.begin(9600);  
  pinMode (soundDetectedPin, INPUT) ; 
  pinMode (LED, OUTPUT) ; 
  pinMode (MOTOR, OUTPUT) ; 
  
  digitalWrite(LED, LOW);   
  digitalWrite(MOTOR, LOW); 
  delay(10000);   // 10 secconds so everybody shut up!!          
  digitalWrite(LED, HIGH);  


}
void loop ()
{
  soundDetectedVal = digitalRead (soundDetectedPin) ; 
  
  if (soundDetectedVal == LOW) 
    {  
      Serial.println("Fogo!!");
      delay(25);
      digitalWrite(LED, LOW);   
      digitalWrite(MOTOR, HIGH); 
      delay(soundAlarmTime);
 
      Serial.println("Disparou...");
      digitalWrite(LED, HIGH);   
      digitalWrite(MOTOR, LOW);  
  delay(90000);  // So... It wont fire AGAIN!

    }
  
}
