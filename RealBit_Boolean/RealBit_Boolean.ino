//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
//************************************************************************
#define BB_TRUE(bp,bb)    bp |= bb
#define BB_FALSE(bp,bb)   bp &= ~(bb)
#define BB_READ(bp,bb)    bool(bp & bb)
//************************************************************************
//************************************************************************


// Boolean variable definitions are here
// You can give any name to your boolean. I used "BB_" as prefix of (B)it (B)oolean
// Every BB should have a 2^n number max 128
#define BB_LED_RED       1
#define BB_LED_ORANGE    2
#define BB_LED_GREEN     4
#define BB_LED_BLUE      8
#define BB_ANY           16
#define BB_OTHER         32
#define BB_VAR1          64
#define BB_VAR2          128

// This is one byte variable which contains 8 boolean, so 7 bytes saved!
// If you need more boolean variable you can add another boolPack e.g. boolPack2
// With this method; 24 boolean variable can be stored in 3 bytes intead of 24bytes in SDRAM memory!
byte boolPack = 0;

void setup() {
  Serial.begin(9600);

  // set real Bit Boolean BB_LED_BLUE to true
  BB_TRUE(boolPack, BB_LED_BLUE);

  // set real Bit Boolean BB_LED_ORANGE to true
  BB_TRUE(boolPack, BB_LED_ORANGE);

  // up to 8 boolean can set to true/false at once, example below 2 booleans set to true
  //BB_TRUE(boolPack, BB_LED_BLUE + BB_LED_ORANGE);

  //Show all values of booleans
  showStatus();
}
void showStatus() {
  Serial.println(F("====================="));
  Serial.println(F("Check indivual boolean values:"));
  Serial.print(F("Blue LED status: "));
  Serial.println(BB_READ(boolPack, BB_LED_BLUE));

  Serial.print(F("Green LED status: "));
  Serial.println(BB_READ(boolPack, BB_LED_GREEN));

  Serial.print(F("Orange LED status: "));
  Serial.println(BB_READ(boolPack, BB_LED_ORANGE));

  Serial.print(F("Red LED status: "));
  Serial.println(BB_READ(boolPack, BB_LED_RED));

  Serial.println(F("Other unused variables:"));
  Serial.println(BB_READ(boolPack, BB_ANY));
  Serial.println(BB_READ(boolPack, BB_OTHER));
  Serial.println(BB_READ(boolPack, BB_VAR1));
  Serial.println(BB_READ(boolPack, BB_VAR2));
}
void loop() { }
