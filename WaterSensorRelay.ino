

#define RELAY1  7 
void setup() {
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(RELAY1, OUTPUT); 
}

void loop() {
  delay(5000);//wait 5 seconds
  // no water found
  if(analogRead(5) < 300){
    Serial.println("No Water");
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(RELAY1,LOW);
  }
  //water  detected
  if(analogRead(5) > 300){
    Serial.println("Water Detected, Turn on Pump!");
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(RELAY1,HIGH); // Turns ON Relays 1
    delay(120000); // Relay Stays High for 2 minutes
  }
}
