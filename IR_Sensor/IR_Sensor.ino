//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
int i = 10;
int x;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(i, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("No. of Obstacles :   ");
  Serial.println(x);

  // Serial.println(x);
  if (digitalRead(i) == LOW) {
    digitalWrite(13, HIGH);
    Serial.println("Obstacle Detected !!!");
    x = x + 1;
    delay(200);
  }
  else {
    Serial.println("The Path is CLEAR.");
    digitalWrite(13, LOW);
    delay(200);
  }

}
