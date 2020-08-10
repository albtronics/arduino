//albtronics Music Reactive Lights-A
//For More Info:https://albtronics.wordpress.com/
int x = 0;
int sound;

int led2 = 23;
int led3 = 26;
int led4 = 27;
int led6 = 31;
int led7 = 34;



void setup()
{

  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  Serial.begin(9600);
}

void loop()
{

  sound = analogRead(x);
  Serial.println(sound);
  if (sound > 0 && sound < 5 || sound > 31  && sound < 35 || sound > 61 && sound < 65 || sound > 91 && sound < 95 || sound > 121 && sound < 125 || sound > 151 && sound < 155 || sound > 181 && sound < 185 || sound > 211 && sound < 215 || sound > 241 && sound < 245 || sound > 271 && sound < 275 || sound > 111 && sound < 115 || sound > 141 && sound < 145)
  {
    digitalWrite(led2, LOW);
    delay(40);
  }
  else
  {
    digitalWrite(led2, HIGH);
  }
  if (sound > 6 && sound < 10 || sound > 36  && sound < 40 || sound > 66 && sound < 70 || sound > 96 && sound < 100 || sound > 126 && sound < 130 || sound > 156 && sound < 160 || sound > 186 && sound < 190 || sound > 216 && sound < 220 || sound > 246 && sound < 250 || sound > 276 && sound < 280 || sound > 261 && sound < 265 || sound > 291 && sound < 295)
  {
    digitalWrite(led3, LOW);
    delay(40);

  }
  else
  {
    digitalWrite(led3, HIGH);

  }
  if (sound > 11 && sound < 15 || sound > 41  && sound < 45 || sound > 71 && sound < 75 || sound > 101 && sound < 105 || sound > 131 && sound < 135 || sound > 161 && sound < 165 || sound > 191 && sound < 195 || sound > 221 && sound < 225 || sound > 251 && sound < 255 || sound > 281 && sound < 285 || sound > 26 && sound < 30 || sound > 56  && sound < 60)
  {
    digitalWrite(led4, LOW);

    delay(40);
  }
  else
  {
    digitalWrite(led4, HIGH);

  }
  if (sound > 16 && sound < 20 || sound > 46  && sound < 50 || sound > 76 && sound < 80 || sound > 106 && sound < 110 || sound > 136 && sound < 140 || sound > 166 && sound < 170 || sound > 196 && sound < 200 || sound > 226 && sound < 230 || sound > 256 && sound < 260 || sound > 286 && sound < 290 || sound > 176 && sound < 180 || sound > 206  && sound < 210)
  {
    digitalWrite(led6, LOW);
    delay(40);
  }
  else
  {
    digitalWrite(led6, HIGH);

  }
  if (sound > 21 && sound < 25 || sound > 51  && sound < 55 || sound > 81 && sound < 85 || sound > 171 && sound < 175 || sound > 201  && sound < 205 || sound > 231 && sound < 235 || sound > 86 && sound < 90 || sound > 116 && sound < 120 || sound > 146 && sound < 150 || sound > 236 && sound < 240 || sound > 266 && sound < 270 || sound > 296 && sound < 300 )
  {
    digitalWrite(led7, LOW);
    delay(40);
  }
  else
  {
    digitalWrite(led7, HIGH);

  }



  delay(35);
  if (sound == 0)
  {
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
  }

}
