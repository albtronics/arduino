//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    char data = Serial.readString(); // reading the data received from the bluetooth module
    switch (data)
    {
      case "a": digitalWrite(13, HIGH); break; // when a is pressed on the app on your smart phone
      case "d": digitalWrite(13, LOW); break; // when d is pressed on the app on your smart phone
      default : break;
    }
    Serial.println(data);
  }
  delay(50);
}
