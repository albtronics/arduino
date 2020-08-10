//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
bool led_red    = false;
bool led_orange = false;
bool led_green  = false;
bool led_blue   = false;
bool any        = false;
bool other      = false;
bool var1       = false;
bool var2       = false;

void setup() {
  Serial.begin(9600);


  led_blue = true;
  led_orange = true;

  showStatus();

}
void showStatus()
{
  Serial.println(F("====================="));
  Serial.println(F("Check indivual boolean values:"));
  Serial.print(F("Blue LED status: "));
  Serial.println(led_blue);

  Serial.print(F("Green LED status: "));
  Serial.println(led_green);

  Serial.print(F("Orange LED status: "));
  Serial.println(led_orange);

  Serial.print(F("Red LED status: "));
  Serial.println(led_red);

  Serial.println(F("Other unused variables:"));
  Serial.println(any);
  Serial.println(other);
  Serial.println(var1);
  Serial.println(var2);
}
void loop() { }
