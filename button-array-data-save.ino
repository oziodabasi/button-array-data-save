int buttonPin1 = 2;
int buttonPin2 = 3;
int buttonPin3 = 4;
int buttonPin4 = 5;
int externalButtonPin = 7;

int button1;
int button2;
int button3;
int button4;
int play_button;

int i = 0;
int z = 0;
int ledPin1 = 8;
int ledPin2 = 9;
int ledPin3 = 10;
int ledPin4 = 11;

int record[10] = {};
int record_order = 0;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(externalButtonPin, INPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  Serial.begin(9600);
}

//------------------------------------------------
void btn1() 
{
  digitalWrite(ledPin1, HIGH);
  delay(500);
  digitalWrite(ledPin1, LOW);
  delay(100);
  record[record_order] = ledPin1;
  record_order++;
  delay(10);
}


void btn2() 
{
  digitalWrite(ledPin2, HIGH);
  delay(500);
  digitalWrite(ledPin2, LOW);
  delay(100);
  record[record_order] = ledPin2;
  record_order++;
  delay(10);
}


void btn3() 
{
  digitalWrite(ledPin3, HIGH);
  delay(500);
  digitalWrite(ledPin3, LOW);
  delay(100);
  record[record_order] = ledPin3;
  record_order++;
  delay(10);
}


void btn4() 
{
  digitalWrite(ledPin4, HIGH);
  delay(500);
  digitalWrite(ledPin4, LOW);
  delay(100);
  record[record_order] = ledPin4;
  record_order++;
  delay(10);
}


void serial() 

{
  Serial.print("btn1 ");
  Serial.println(digitalRead(buttonPin1));
  Serial.print("btn2 ");
  Serial.println(digitalRead(buttonPin2));
  Serial.print("btn3 ");
  Serial.println(digitalRead(buttonPin3));
  Serial.print("btn4 ");
  Serial.println(digitalRead(buttonPin4));
  Serial.println(record[record_order]);
  delay(200);
}


//------------------------------------------------



void loop() {
button1= digitalRead(buttonPin1);
button2= digitalRead(buttonPin2);
button3= digitalRead(buttonPin3);
button4= digitalRead(buttonPin4);
play_button= digitalRead(externalButtonPin);




  if (play_button == LOW) {
    if (button1 == HIGH) {
      btn1();
    }
    if (button2 == HIGH) {
      btn2();
    }
    if (button3 == HIGH) {
      btn3();
    }
    if (button4 == HIGH) {
      btn4();
    }
  }

  if (play_button == HIGH) {


    for (int i = 0; i < 10; i++) {
      digitalWrite(record[i], HIGH);
      delay(300);
      digitalWrite(record[i], LOW);
      delay(1);


      if (record[i] == 0) {

        for (int z = 0; z < 10; z++) {
          record[z] = {};
          delay(1);

          record_order = 0;
        }
      }
    }
  }

  serial();
}
