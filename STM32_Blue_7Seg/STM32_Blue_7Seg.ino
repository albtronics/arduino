//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
char inputdata = 0;  //Variable for storing received data
const int A = PA6;
const int B = PA5;
const int C = PB13;
const int D = PB14;
const int E = PB15;
const int F = PB0;
const int G = PA7;
//int inputdata;
void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  pinMode(A, OUTPUT);  digitalWrite(A, HIGH);
  pinMode(B, OUTPUT);  digitalWrite(B, HIGH);
  pinMode(C, OUTPUT);  digitalWrite(C, HIGH);
  pinMode(D, OUTPUT);  digitalWrite(D, HIGH);
  pinMode(E, OUTPUT);  digitalWrite(E, HIGH);
  pinMode(F, OUTPUT);  digitalWrite(F, HIGH);
  pinMode(G, OUTPUT);  digitalWrite(G, HIGH);
  pinMode(PB12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PB12, HIGH);
  delay(100);
  digitalWrite(PB12, LOW);
  delay(100);
  if (Serial1.available() > 0)     // Send data only when you receive data:
  {
    inputdata = Serial1.read();        //Read the incoming data & store into data

    if (inputdata == '0') {
      onA(); onB(); onC(); onD(); onE(); onF();
      offG();
    }
    else if (inputdata == '1') {
      onB(); onC();
      offA(); offD(); offE(); offF(); offG();
    }
    else if (inputdata == '2') {
      onA(); onB(); onG(); onE(); onD();
      offF(); offC();
    }
    else if (inputdata == '3') {
      onA(); onB(); onG(); onC(); onD();
      offE(); offF();
    }
    else if (inputdata == '4') {
      onF(); onG(); onB(); onC();
      offA(); offE(); offD();
    }
    else if (inputdata == '5') {
      onA(); onF(); onG(); onC(); onD();
      offB(); offE();
    }
    else if (inputdata == '6') {
      onA(); onC(); onD(); onE(); onF(); onG();
      offB();
    }
    else if (inputdata == '7') {
      onA(); onB(); onC();
      offD(); offE(); offF(); offG();
    }
    else if (inputdata == '8') {
      onA(); onB(); onC(); onD(); onE(); onF(); onG();
    }
    else if (inputdata == '9') {
      onA(); onB(); onC(); onF(); onG();
      offE(); onD();
    }
  }
}

/*THESE FUNCTIONS ARE SELF EXPLATNATORY FOR CONTROLLING(ON/OFF) THE 7SEGMENT LED DISPLAY */

void onA() {
  digitalWrite(A, LOW);
} void offA() {
  digitalWrite(A, HIGH);
}
void onB() {
  digitalWrite(B, LOW);
} void offB() {
  digitalWrite(B, HIGH);
}
void onC() {
  digitalWrite(C, LOW);
} void offC() {
  digitalWrite(C, HIGH);
}
void onD() {
  digitalWrite(D, LOW);
} void offD() {
  digitalWrite(D, HIGH);
}
void onE() {
  digitalWrite(E, LOW);
} void offE() {
  digitalWrite(E, HIGH);
}
void onF() {
  digitalWrite(F, LOW);
} void offF() {
  digitalWrite(F, HIGH);
}
void onG() {
  digitalWrite(G, LOW);
} void offG() {
  digitalWrite(G, HIGH);
}
