int sensor1 = 49;
int sensor2 = 47;
int sensor3 = 45;
int sensor4 = 43;
int sensor5 = 41;

void setup() {


  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  Serial.begin(9600);

}

void loop() {

  // Read sensor values
  int val1 = digitalRead(sensor1);
  int val2 = digitalRead(sensor2);
  int val3 = digitalRead(sensor3);
  int val4 = digitalRead(sensor4);
  int val5 = digitalRead(sensor5);
  Serial.print(val1);
  Serial.print("  ");
    Serial.print(val2);
  Serial.print("  ");
   Serial.print(val3);
  Serial.print("  ");
    Serial.print(val4);
  Serial.print("  ");
    Serial.print(val5);
  Serial.println();
}