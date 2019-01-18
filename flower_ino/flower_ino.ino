const int buttonPin = 12;
const int ledPins [10] = {2,3,4,5,6,7,8,9,10,11};
const int speakerPin = 13;

double c_timer = 0;
double c_timer_start = 0;

int btnCnt = 0;
int buttonState = 0;
int cirCnt = 0;
int currState = 0;
int prevState = 0;

double currTime = 0;



void setup() 
{
  pinMode(ledPins[0],OUTPUT);
  pinMode(ledPins[1],OUTPUT);
  pinMode(ledPins[2],OUTPUT);
  pinMode(ledPins[3],OUTPUT);
  pinMode(ledPins[4],OUTPUT);
  pinMode(ledPins[5],OUTPUT);
  pinMode(ledPins[6],OUTPUT); 
  pinMode(ledPins[7],OUTPUT);
  pinMode(ledPins[8],OUTPUT);
  pinMode(ledPins[9],OUTPUT);
  pinMode(speakerPin,OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);  
}

void loop()
{  
  PinWrite(0,0,0,0,0,0,0,0,0,0);
  delay(1000);
  PinWrite(1,1,1,1,1,1,1,1,1,1);
  delay(1000);
}

void Debounce()
{
  currState = digitalRead(buttonPin);
  if(currState)
  {      
        if (!buttonState)
        {
          buttonState = 1;
          currTime = millis();
        }
        
        else if(buttonState)
        {
           if(millis() - currTime == 500)
           {
              buttonState = 0; 
              btnCnt++;      
           }
        }
  }
}

void cases()
{
  switch(btnCnt)
  {
    case 0: // reset
    {
      PinWrite(0,0,0,0,0,0,0,0,0,0);    
    }
    
    case 1: // all on
    {
      PinWrite(1,1,1,1,1,1,1,1,1,1); 
    }
    
    case 2: // circle
    {
      c_timer = millis() - c_timer_start;

      if (c_timer > 500) // timer reset
      {
        c_timer_start = millis();
        cirCnt++; 
      }

      
      
    }
    
//    // I Melt With You
//    case 3:
//    // Majid
//    case 4:
//    // Cardi
//    case 5:
//    
  }
}

void PinWrite(int ledOne,int ledTwo,int ledThree,int ledFour,int ledFive,int ledSix,int ledSeven,int ledEight,int ledNine,int ledTen)
{
        digitalWrite(ledPins[0],ledOne);
        digitalWrite(ledPins[1],ledTwo);
        digitalWrite(ledPins[2],ledThree);
        digitalWrite(ledPins[3],ledFour);
        digitalWrite(ledPins[4],ledFive);
        digitalWrite(ledPins[5],ledSix);
        digitalWrite(ledPins[6],ledSeven);
        digitalWrite(ledPins[7],ledEight);
        digitalWrite(ledPins[8],ledNine);
        digitalWrite(ledPins[9],ledTen);  
}

