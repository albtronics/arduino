//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
//PROGRAM FOR BLUETOOTH INTERFACE WITH STM32F103C8
//const int pinout = PB7; // declare pinout with int data type and pin value
char inputdata = 0;  //Variable for storing received data

void setup()
{
  Serial1.begin(9600);                      //Sets the baud rate for bluetooth pins
  Serial1.print("albtronics.com\n");
  Serial1.print("BLUETOOTH WITH STM32\n");
  pinMode(PB7, OUTPUT);
  pinMode(PB5, OUTPUT);
  pinMode(PB4, OUTPUT);
}

void loop()
{
  if (Serial1.available() > 0)     // Send data only when you receive data:
  {
    inputdata = Serial1.read();        //Read the incoming data & store into data

    if (inputdata == 'A')
    {
      digitalWrite(PB7, HIGH);

    }

    else if (inputdata == '1')
    {
      digitalWrite(PB7, LOW);

    }
    if (inputdata == 'B')
    {
      digitalWrite(PB5, HIGH);

    }

    else if (inputdata == '2')
    {
      digitalWrite(PB5, LOW);

    }
    if (inputdata == 'C')
    {
      digitalWrite(PB4, HIGH);

    }

    else if (inputdata == '3')
    {
      digitalWrite(PB4, LOW);

    }
    if (inputdata == 'D')
    {
      digitalWrite(PB7, HIGH);
      digitalWrite(PB5, HIGH);
      digitalWrite(PB4, HIGH);

    }

    else if (inputdata == '4')
    {
      digitalWrite(PB7, LOW);
      digitalWrite(PB5, LOW);
      digitalWrite(PB4, LOW);

    }
  }
}
