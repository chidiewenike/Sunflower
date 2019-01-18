// TONES  ==========================================
#define  c     261
#define  d     294
#define  e     329
#define  f     349
#define  fs    370
#define  g     392
#define  gs    415
#define  a     440
#define  as    466
#define  b     493
#define  C     523
#define  CS    554
#define  D     587
#define  DS    622
#define  E     659
#define  F     698
#define  FS    740
#define  G     784
#define  GS    831
#define  A     880
#define  AS    932
#define  B     988
#define  C_U     1047
#define  D_U     1175
#define  DS_U    1245
#define  E_U     1319
#define  F_U     1397
#define  G_U     1568

// GLOBAL VARIABLES  ===============================

const int bodakMelody[] = {b, 3, C, 3, E, 3, b, 3, C, 3, E, 3, b, 3, C, 3, b, 3, C, 3, E, 3, b, 3, C, 3, E, 3, b, 3, E, 3, b, 3, C, 3, E, 3, b, 3, C, 3, E, 3, b, 3, C, 3, b, 3, C, 3, E, 3, b, 3, C, 3, E, 3, b, 3, E, 3};
const int gotMelody[] = {G_U, 2, C_U, 2, DS_U, 1, F_U, 1, G_U, 2, C_U, 2, DS_U, 1, F_U, 1, G_U, 2, C_U, 2, DS_U, 1, F_U, 1, G_U, 2, C_U, 2, DS_U, 1, F_U, 1, G_U, 2, C_U, 2, E_U, 1, F_U, 1, G_U, 2, C_U, 2, E_U, 1, F_U, 1, G_U, 2, C_U, 2, E_U, 1, F_U, 1, G_U, 2, C_U, 2, E_U, 1, F_U, 1, G,G,6,C,C,6,DS,1,F,1,G,3,C,3,DS,1,F,1,D,2,G,2,AS,1,C_U,1,D_U,2,G,2,AS,1,C_U,1,D_U,2,G,2,AS,1,C_U,1,D_U,2,G,2,AS,2,F,6,as,6,DS,1,D,1,F,3,as,6,DS,1,D,1,C,3,GS,1,AS,1,C_U,2,F,2,GS,1,AS,1,C_U,2,F,2,GS,1,AS,1,C_U,2,F,2,GS,2};
const int meltMelody[] =  {C, 2, C, 2, C, 1, C, 1, 2, g, 2, g, 2, g, 1, a, 1, 8, C, 2, C, 2, C, 1, C, 1, 2, g, 2, g, 2, g, 2, g, 1, a, 2, g, 2, e, 3, e, 2, f, 1, e, 1};
const int majidMelody[] = {A, 2, G, 2, F, 2, E, 2, A, 2, G, 2, F, 2, E, 2, D_U, 10, E, 2, E, 5, G, 2, G, 2, G, 2, E, 2, C_U, 10, A, 2, G, 2, F, 2, E, 2, A, 2, G, 2, F, 2, E, 2, D_U, 10, E, 2, E, 5, G, 2, G, 2, G, 2, E, 2, C_U, 2};
const int rmMelody[] = {as, as, as, as, as, as, 2, CS, 2, C, 2, DS, 2, gs, 2, fs, 2, f, f, 5, CS, CS, CS, CS, 2, DS, DS, DS, DS, 2, F, F, F, F, 4, as, as, as, as, as, as, 2, CS, 2, C, 2, DS, 2, GS, 2, FS, 2, F, F, 5, as, as, as, as, 2, CS, CS, CS, CS, 5, CS, 2, C, 2, DS, 2, GS, 2, FS, 2, F, F, 4};
const int swMelody[] = {G,G,G,3,D_U,D_U,D_U,3,C_U,B,A,G_U,G_U,G_U,3,D_U,D_U,1,C_U,B,A,G_U,G_U,G_U,3,D_U,D_U,1,C_U,B,C_U,A,A,A,8};
const int ledPins [10] = {2, 3, 4, 5, 6, 7, 8, 9};

const int buttonPin = 12;
const int speakerPin = 11;
const int NUM_MODES = 7;
const int bodakTones = sizeof(bodakMelody) / sizeof(bodakMelody[0]);
const int gotTones = sizeof(gotMelody) / sizeof(gotMelody[0]);
const int meltTones = sizeof(meltMelody) / sizeof(meltMelody[0]);
const int majidTones = sizeof(majidMelody) / sizeof(majidMelody[0]);
const int rmTones = sizeof(rmMelody) / sizeof(rmMelody[0]);
const int swTones = sizeof(swMelody) / sizeof(swMelody[0]);

bool delayStart = false;
bool idle = false;
bool readBtn = false;

double currTime = 0;
double c_timer = 0;
double c_timer_start = 0;
double b_timer = 0;
double b_timer_start = 0;
double d_countdown = 0;
double d_timer = 0;
double d_timer_start = 0;
double m_timer = 0;
double m_timer_start = 0;
double i_timer = 0;
double i_timer_start = 0;

int btnCnt = 0;
int buttonState = 0;
int cirCnt = 0;
int currState = 0;
int lightSeqCnt = 0;
int melodyParse = 0;
int prevState = 0;
int prevRLED = 0;
int randLED = 0;
int randSeq = 0;
int seqCnt = 0;
int swPlayCount = 0;

void setup()
{
  pinMode(ledPins[0], OUTPUT);
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);
  pinMode(ledPins[3], OUTPUT);
  pinMode(ledPins[4], OUTPUT);
  pinMode(ledPins[5], OUTPUT);
  pinMode(ledPins[6], OUTPUT);
  pinMode(ledPins[7], OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  Debounce();
  LightModes();
}

void Debounce()
{
  currState = digitalRead(buttonPin);
  if ((!readBtn) && (currState))
  {
    buttonState = 1;
    b_timer_start = millis();
    readBtn = true;
    btnCnt++;
    melodyParse = 0;
    idle = false;
    if (btnCnt > NUM_MODES)
    {
      btnCnt = 0;
    }
  }

  else
  {
    b_timer = millis() - b_timer_start;
    if (b_timer > 250)
    {
      readBtn = false;
      buttonState = 0;
    }
  }

}

void LightModes()
{
  switch (btnCnt)
  {

      // all LEDs on
      case 0: 
      {
        PinWrite(1, 1, 1, 1, 1, 1, 1, 1);   
        melodyParse = 0;
        noTone(speakerPin);      
        swPlayCount = 0;       
        break;
      }
          
      // Idle state 
      case 1: 
      {
        Idle();
        break;
      }
      
      // Rick and Morty
      case 2:
      {
        if (melodyParse <= rmTones - 1)
        {
          PlayMelody(rmMelody, 125);
        }
        else
        {
          noTone(speakerPin);
          Idle();        
        }
        break;
      }
      
      // I Melt With You
      case 3:
      {
        if (melodyParse <= meltTones - 1)
        {
          PlayMelody(meltMelody, 50);
        }
        else
        {
          noTone(speakerPin);
          Idle();        
        }
        break;
      }
      
      // Cardi B - Bodak Yellow
      case 4:
      {
        if (melodyParse <= bodakTones - 1)
        {
          PlayMelody(bodakMelody, 100);
        }
        else
        {
          noTone(speakerPin);
          Idle();        
        }
        break;
      }

      // Majid Jordan - Every Step of the Way
      case 5:
      {
        if (melodyParse <= majidTones - 1)
        {
          PlayMelody(majidMelody, 55);
        }
        else
        {
          noTone(speakerPin);
          Idle();        
        }
        break;
      }
      
      // Game of Thrones theme song
      case 6:
      {
        if (melodyParse <= gotTones - 1)
        {
          PlayMelody(gotMelody, 55);
        }
        else
        {
          noTone(speakerPin);
          Idle();        
        }
        break;
      }

      // Star Wars Theme Song
      case 7:
      {
        if (melodyParse <= swTones - 1)
        {
          PlayMelody(swMelody, 125);
        }
        else if((melodyParse > swTones - 1) && (swPlayCount < 2))
        {
          swPlayCount++;
          melodyParse = 0;
        }
        else
        {
          noTone(speakerPin);
          Idle();          
        }
        break;
      }
      
      default:
      {
        PinWrite(0, 0, 0, 0, 0, 0, 0, 0);
      }
  }
  
}

void PinWrite(int ledOne, int ledTwo, int ledThree, int ledFour, int ledFive, int ledSix, int ledSeven, int ledEight)
{
  digitalWrite(ledPins[0], ledOne);
  digitalWrite(ledPins[1], ledTwo);
  digitalWrite(ledPins[2], ledThree);
  digitalWrite(ledPins[3], ledFour);
  digitalWrite(ledPins[4], ledFive);
  digitalWrite(ledPins[5], ledSix);
  digitalWrite(ledPins[6], ledSeven);
  digitalWrite(ledPins[7], ledEight);
}

void LightSequence1()
{
  switch (cirCnt)
  {
    case 0: // led #1
      {
        PinWrite(1, 0, 0, 0, 0, 0, 0, 0);
        break;
      }
    case 1: // led #2
      {
        PinWrite(0, 1, 0, 0, 0, 0, 0, 0);
        break;
      }
    case 2: // led #3
      {
        PinWrite(0, 0, 1, 0, 0, 0, 0, 0);
        break;
      }
    case 3: // led #4
      {
        PinWrite(0, 0, 0, 1, 0, 0, 0, 0);
        break;
      }
    case 4: // led #5
      {
        PinWrite(0, 0, 0, 0, 1, 0, 0, 0);
        break;
      }
    case 5: // led #6
      {
        PinWrite(0, 0, 0, 0, 0, 1, 0, 0);
        break;
      }
    case 6: // led #7
      {
        PinWrite(0, 0, 0, 0, 0, 0, 1, 0);
        break;
      }
    case 7: // led #8
      {
        PinWrite(0, 0, 0, 0, 0, 0, 0, 1);
        break;
      }
  }
}


void LightSequence2()
{
  switch (cirCnt)
  {
    case 0: // led #1
      {
        PinWrite(1, 1, 0, 0, 0, 0, 0, 0);
        break;
      }
    case 1: // led #2
      {
        PinWrite(0, 1, 1, 0, 0, 0, 0, 0);
        break;
      }
    case 2: // led #3
      {
        PinWrite(0, 0, 1, 1, 0, 0, 0, 0);
        break;
      }
    case 3: // led #4
      {
        PinWrite(0, 0, 0, 1, 1, 0, 0, 0);
        break;
      }
    case 4: // led #5
      {
        PinWrite(0, 0, 0, 0, 1, 1, 0, 0);
        break;
      }
    case 5: // led #6
      {
        PinWrite(0, 0, 0, 0, 0, 1, 1, 0);
        break;
      }
    case 6: // led #7
      {
        PinWrite(0, 0, 0, 0, 0, 0, 1, 1);
        break;
      }
    case 7: // led #8
      {
        PinWrite(1, 0, 0, 0, 0, 0, 0, 1);
        break;
      }
  }
}

void LightSequence3()
{
  switch (cirCnt)
  {
    case 0: // led #1
      {
        PinWrite(1, 1, 1, 0, 0, 0, 0, 0);
        break;
      }
    case 1: // led #2
      {
        PinWrite(0, 1, 1, 1, 0, 0, 0, 0);
        break;
      }
    case 2: // led #3
      {
        PinWrite(0, 0, 1, 1, 1, 0, 0, 0);
        break;
      }
    case 3: // led #4
      {
        PinWrite(0, 0, 0, 1, 1, 1, 0, 0);
        break;
      }
    case 4: // led #5
      {
        PinWrite(0, 0, 0, 0, 1, 1, 1, 0);
        break;
      }
    case 5: // led #6
      {
        PinWrite(0, 0, 0, 0, 0, 1, 1, 1);
        break;
      }
    case 6: // led #7
      {
        PinWrite(1, 0, 0, 0, 0, 0, 1, 1);
        break;
      }
    case 7: // led #8
      {
        PinWrite(1, 1, 0, 0, 0, 0, 0, 1);
        break;
      }
  }
}

void LightSequence4()
{
  switch (cirCnt)
  {
    case 0: // led #1
      {
        PinWrite(1, 0, 0, 0, 1, 0, 0, 0);
        break;
      }
    case 1: // led #2
      {
        PinWrite(0, 1, 0, 0, 0, 1, 0, 0);
        break;
      }
    case 2: // led #3
      {
        PinWrite(0, 0, 1, 0, 0, 0, 1, 0);
        break;
      }
    case 3: // led #4
      {
        PinWrite(0, 0, 0, 1, 0, 0, 0, 1);
        break;
      }
    case 4: // led #5
      {
        PinWrite(1, 0, 0, 0, 1, 0, 0, 0);
        break;
      }
    case 5: // led #6
      {
        PinWrite(0, 1, 0, 0, 0, 1, 0, 0);
        break;
      }
    case 6: // led #7
      {
        PinWrite(0, 0, 1, 0, 0, 0, 1, 0);
        break;
      }
    case 7: // led #8
      {
        PinWrite(0, 0, 0, 1, 0, 0, 0, 1);
        break;
      }
  }
}

void LightSequence5()
{
  switch (cirCnt)
  {
    case 0: // led #1
      {
        PinWrite(1, 1, 0, 0, 1, 1, 0, 0);
        break;
      }
    case 1: // led #2
      {
        PinWrite(0, 1, 1, 0, 0, 1, 1, 0);
        break;
      }
    case 2: // led #3
      {
        PinWrite(0, 0, 1, 1, 0, 0, 1, 1);
        break;
      }
    case 3: // led #4
      {
        PinWrite(1, 0, 0, 1, 1, 0, 0, 1);
        break;
      }
    case 4: // led #5
      {
        PinWrite(1, 1, 0, 0, 1, 1, 0, 0);
        break;
      }
    case 5: // led #6
      {
        PinWrite(0, 1, 1, 0, 0, 1, 1, 0);
        break;
      }
    case 6: // led #7
      {
        PinWrite(0, 0, 1, 1, 0, 0, 1, 1);
        break;
      }
    case 7: // led #8
      {
        PinWrite(1, 0, 0, 1, 1, 0, 0, 1);
        break;
      }
  }
}

void LightSequence6()
{
  switch (cirCnt)
  {
    case 0: // led #1
      {
        PinWrite(1, 1, 1, 0, 1, 1, 1, 0);
        break;
      }
    case 1: // led #2
      {
        PinWrite(0, 1, 1, 1, 0, 1, 1, 1);
        break;
      }
    case 2: // led #3
      {
        PinWrite(1, 0, 1, 1, 1, 0, 1, 1);
        break;
      }
    case 3: // led #4
      {
        PinWrite(1, 1, 0, 1, 1, 1, 0, 1);
        break;
      }
    case 4: // led #5
      {
        PinWrite(1, 1, 1, 0, 1, 1, 1, 0);
        break;
      }
    case 5: // led #6
      {
        PinWrite(0, 1, 1, 1, 0, 1, 1, 1);
        break;
      }
    case 6: // led #7
      {
        PinWrite(1, 0, 1, 1, 1, 0, 1, 1);
        break;
      }
    case 7: // led #8
      {
        PinWrite(1, 1, 0, 1, 1, 1, 0, 1);
        break;
      }
  }
}

void LightSequence7()
{
  switch (cirCnt)
  {
    case 0: // led #1
      {
        PinWrite(1, 0, 1, 0, 1, 0, 1, 0);
        break;
      }
    case 1: // led #2
      {
        PinWrite(0, 1, 0, 1, 0, 1, 0, 1);
        break;
      }
    case 2: // led #3
      {
        PinWrite(1, 0, 1, 0, 1, 0, 1, 0);
        break;
      }
    case 3: // led #4
      {
        PinWrite(0, 1, 0, 1, 0, 1, 0, 1);
        break;
      }
    case 4: // led #5
      {
        PinWrite(1, 0, 1, 0, 1, 0, 1, 0);
        break;
      }
    case 5: // led #6
      {
        PinWrite(0, 1, 0, 1, 0, 1, 0, 1);
        break;
      }
    case 6: // led #7
      {
        PinWrite(1, 0, 1, 0, 1, 0, 1, 0);
        break;
      }
    case 7: // led #8
      {
        PinWrite(0, 1, 0, 1, 0, 1, 0, 1);
        break;
      }
  }
}

void RandomLights()
{
  randLED = random(10);
  if (randLED == prevRLED)
  {
    randLED = (randLED + 5) % 10;
  }
  prevRLED = randLED;
  switch (randLED)
  {
    case 0: // led #1
      {
        PinWrite(1, 0, 0, 0, 0, 0, 0, 0);
        break;
      }
    case 1: // led #2
      {
        PinWrite(0, 1, 0, 0, 0, 0, 0, 0);
        break;
      }
    case 2: // led #3
      {
        PinWrite(0, 0, 1, 0, 0, 0, 0, 0);
        break;
      }
    case 3: // led #4
      {
        PinWrite(0, 0, 0, 1, 0, 0, 0, 0);
        break;
      }
    case 4: // led #5
      {
        PinWrite(0, 0, 0, 0, 1, 0, 0, 0);
        break;
      }
    case 5: // led #6
      {
        PinWrite(0, 0, 0, 0, 0, 1, 0, 0);
        break;
      }
    case 6: // led #7
      {
        PinWrite(0, 0, 0, 0, 0, 0, 1, 0);
        break;
      }
    case 7: // led #8
      {
        PinWrite(0, 0, 0, 0, 0, 0, 0, 1);
        break;
      }
  }
  delay(250);
}


void PlayMelody(int melodyArray[], int tempo)
{
  if (melodyArray[melodyParse] > 20)
  {
    m_timer_start = millis();
    seqCnt++;
    switch (seqCnt%2)
    {
      case 0:
        {
          PinWrite(1, 0, 1, 0, 1, 0, 1, 0);
          break;
        }
      case 1:
        {
          PinWrite(0, 1, 0, 1, 0, 1, 0, 1);
          break;  
        }
    }  
//    randSeq = random(3);
//    switch (randSeq)
//    {
//      case 0:
//        {
//          PinWrite(1, 0, 1, 0, 1, 0, 1, 0);
//          break;
//        }
//      case 1:
//        {
//          PinWrite(0, 1, 0, 1, 0, 1, 0, 1);
//          break;
//        }
//      case 2:
//        {
//          PinWrite(1, 1, 1, 1, 1, 1, 1, 1);
//          break;
//        }
//    }
    tone(speakerPin, melodyArray[melodyParse]);
    delay(tempo);
    melodyParse++;
  }
  else if ((melodyArray[melodyParse] <= 20) && (!delayStart))
  {
    delayStart = true;
    d_timer_start = millis();
    d_countdown = melodyArray[melodyParse] * 125;
  }
  else if ((melodyArray[melodyParse] <= 20) && (delayStart))
  {
    if (millis() - d_timer_start > d_countdown)
    {
      delayStart = false;
      melodyParse++;
    }
    else
    {
      PinWrite(0, 0, 0, 0, 0, 0, 0, 0);
      noTone(speakerPin);
    }
  }
}

void Idle()
{
          c_timer = millis() - c_timer_start;

        if (c_timer > 150) // timer reset
        {
          c_timer_start = millis();
          cirCnt++;
          if (cirCnt > 7)
          {
            lightSeqCnt++;
            if (lightSeqCnt > 20)
            {
              lightSeqCnt = 0;
            }
            cirCnt = 0;
          }
        }
        switch (lightSeqCnt / 3)
        {
          case 0:
            {
              LightSequence1();
              break;
            }
          case 1:
            {
              LightSequence2();
              break;
            }
          case 2:
            {
              LightSequence3();
              break;
            }
          case 3:
            {
              LightSequence4();
              break;
            }
          case 4:
            {
              LightSequence5();
              break;
            }
          case 5:
            {
              LightSequence6();
              break;
            }
          case 6:
            {
              LightSequence7();
              break;
            }
}
}
