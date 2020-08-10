// Arduino Dino Game ! :)
//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
#include <Servo.h>
Servo myservo;
int sensorPin = PA3;    //Connect LDR on A0
int sensorValue = 0;  // variable to store the value coming from LDR
int thresholdValue = 2238
                     //1552
                     ; //this one depend on your trial and error method.
void setup() {
  myservo.attach(PB6);
  Serial.begin(9600);  //Serial begin on 9600
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); //read sensor data
  Serial.println(sensorValue);  //uncomment this while first use and take your thresholdValue and set.

  if (sensorValue <= thresholdValue) { //if condition to detect obstacle.
    // Press();
    // Serial.println(1);                 //Serial printing if condition is true.

    myservo.write(120);              // tell servo to go to position in variable 'pos'


    myservo.write(90);
    delay(100);
  }
  else {
    myservo.write(120);              // tell servo to go to position in variable 'pos'

  }
  delay(50);
  //delay 50ms
}
/*void Press() {
  myservo.write(120);              // tell servo to go to position in variable 'pos'
  delay(500);

  myservo.write(90);
  delay(500);
  }*/
