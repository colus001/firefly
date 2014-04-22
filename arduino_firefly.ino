const int analogInPin = A0;
const int lights[] = { 
  10, 9, 11 };

int sensorValue = 0;
int outputValue = 0;
int no = 0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  // TURN ON
  moodLight();
  
  // DEBUG
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(outputValue);   

  delay(2);                     
}

void moodLight () {
  for ( int i = 0; i < 150; i++ ) {
    no = checkSensor(analogRead(analogInPin));

    lightOn(lights, no, i);
    delay(10); 
  }
  
  for ( int i = 150; i > 0; i-- ) {
    no = checkSensor(analogRead(analogInPin));

    lightOn(lights, no, i);
    delay(10); 
  }
}

int checkSensor(int sensorValue) {
  if ( sensorValue > 750 ) {
    return 0;
  }
  else if ( sensorValue > 600 ) {
    return 1;
  } 
  else if ( sensorValue > 400 ) {
    return 2;
  } 
  else {
    return 3;
  }
}

void lightOn(const int LED[], int no, int i) {
  for ( int j = 0; j < no; j++ ) {
    analogWrite(LED[j], i);
  }

  for ( int k = 3; k >= no; k-- ) {
    analogWrite(LED[k], 0);
  }
}


