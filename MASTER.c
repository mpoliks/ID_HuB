#include <Wire.h>
int wireVAL = 0;
int wireID = 0;


// - - - - - - - - - - - STATUS ARRAY
int asts[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
// first (0) element is always empty

// - - - - - - - - - - - ID ARRAYS
const int v[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
const int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
// asts should have 22 elements because asts[1] should have the value corresponding to v1
int vSH[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
const int vRL[] = {16,9,18,8,17,7,15,12,14,11,13,10,6,3,5,2,4,1};
const int vWR[] = {1,2,3,10,11,12,15,7,8,9,16,18,17,14,13,6,5,4};
const int vWing[] = {7,8,9,17,18};
int vWingSH[] = {7,8,9,17,18};
int allT[] = {19, 20, 21};
// A GROUP ("teeth")
const int vA[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int vASH[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// B GROUP ("grey")
const int vB[] = {10, 11, 12, 13, 14, 15, 16, 17, 18};
int vBSH[] = {10, 11, 12, 13, 14, 15, 16, 17, 18};

int vex10[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18};
int vex16[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 18};
int vex1_3_4_5_7[] = {2, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
int vBex1_3_4_5_7[] = {18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 6, 2};

int vexRW10[] = {4, 5, 6, 13, 14, 17, 18, 16, 9, 8, 7, 15, 12, 11, 3, 2, 1};
int vexWR10[] = {1, 2, 3, 11, 12, 15, 7, 8, 9, 16, 18, 17, 14, 13, 6, 5, 4};
int vexWR10_16[] = {1, 2, 3, 11, 12, 15, 7, 8, 9, 18, 17, 14, 13, 6, 5, 4};
int vexRL10_16[] = {9, 18, 8, 17, 7, 15, 12, 14, 11, 13, 6, 3, 5, 2, 4, 1};
int vexWR7_8_9_10[] = {1, 2, 3, 11, 12, 15, 16, 18, 17, 14, 13, 6, 5, 4};
int vexRW7_8_9_10[] = {4, 5, 6, 13, 14, 17, 18, 16, 15, 12, 11, 3, 2, 1};

bool allOn = false;
bool allOff = true;
bool AOn = false;
bool AOff = true;
bool BOn = false;
bool BOff = true;

// - - - - - - - - - - - CLOCKS
// variables for main clock
  unsigned long currentMillis = 0;
  unsigned long previousMillis = 0;
  unsigned long startTime;
  unsigned long adjuster = 0;
  int counter = 0;
  int prevCounter = 0;
  int Min = 0;
  int Sec = 0;
  
// - - - - - - - - - - - MILLIS VARS

  int mInstructorAssigner = 0;
  int mInstructorAssigner2 = 0;
  int mIStorageSZ = 0;
  int mIStorageSZ2 = 0;
  int mIStorageA1 = 0;
  int mIStorageA12 = 0;
  int prevmInstruction;
  int prevmInstruction2;
  bool altAssigner1 = true;
  bool ligetiCounter1 = true; 
  bool ligetiCounter2 = true; 
  bool ligetiCounter21 = true;  
  bool ligetiCounter22 = true; 
  bool mInstructorReset = true;
  bool mInstructorReset2 = true;
  bool grandLigetiCounterH1 = true; 
  bool grandLigetiCounterH2 = true;  
  bool grandLigetiCounterQ1 = true; 
  bool grandLigetiCounterQ2 = true; 
  bool grandLigetiCounterQ3 = true; 
  bool grandLigetiCounterQ4 = true; 
  bool grandLigetiCounterE1 = true; 
  bool grandLigetiCounterE2 = true; 
  bool grandLigetiCounterE3 = true; 
  bool grandLigetiCounterE4 = true; 
  bool grandLigetiCounterE5 = true; 
  bool grandLigetiCounterE6 = true; 
  bool grandLigetiCounterE7 = true; 
  bool grandLigetiCounter2T1 = false;
  bool grandLigetiCounter2T2 = false;
  bool grandLigetiCounter2T3 = false;
  bool stopNow = false;
  bool fcnAltInit = true;
  bool gLigetiInit = true;
  bool gLigetiInit2 = true;
  bool fcnLigetiInit = true;
  bool fcnLigetiInit2 = true;


// - - - - - - - - - - - INSTRUCTION ARRAYS
const int lOnOffFAST[] = {130, 131, 132, 136, 137, 138};
const int lOnFAST[] = {130, 131, 132};
const int lOffFAST[] = {136, 137, 138};
const int lOnOffMID[] = {133, 134, 135, 139, 140, 141};
const int lOnMID[] = {133, 134, 135};
const int lOffMID[] = {139, 140, 141};
int allOns[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int allOffs[] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
int chrOns[] = {30, 31, 32, 33, 34, 35, 36};
int chrOffs[] = {40, 41, 42, 43, 44, 45, 46};
int solFinsLO2[] = {70, 80, 90};
int solFinsMID2[] = {71, 81, 91};
int solFinsHI2[] = {72, 82, 92};
int solFinsLO4[] = {73, 83, 93};
int solFinsMID4[] = {74, 84, 94};
int solFinsHI4[] = {75, 85, 95};
int solFinsLO6[] = {76, 86, 96};
int solFinsMID6[] = {77, 87, 97};
int solFinsHI6[] = {78, 88, 98};
int solFoutsLO2[] = {100, 110, 120};
int solFoutsMID2[] = {101, 111, 121};
int solFoutsHI2[] = {102, 112, 122};
int solFoutsLO4[] = {103, 113, 123};
int solFoutsMID4[] = {104, 114, 124};
int solFoutsHI4[] = {105, 115, 125};
int solFoutsLO6[] = {106, 116, 126};
int solFoutsMID6[] = {107, 117, 127};
int solFoutsHI6[] = {108, 118, 128};
int chrFlttrs[] = {142, 143, 144, 145, 146, 147, 148, 149};
int solFlttrs[] = {150, 151, 152, 153, 154, 155, 156, 157};
int chayaCH[] = {160, 161, 162, 164, 165, 166, 168};
int musicians[] = {170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209};
int ligetis[] = {210, 212, 214, 216, 218};





// - - - - - - - - - - - - - - - - - - SETUP - ||
void setup() {
  Wire.begin();
  Serial.begin(9600); 
  allOn = false;
  startTime = millis();
}
// - - - - - - - - - - - - - - - - - - LOOP - ||
void loop() { 
delay(1);
// - - - - - - - - - - - - - - - - - - SERIAL CLOCK RESET
if ( Serial.available () > 0 ) {
 static char input[16];
 static uint8_t R;
 char c = Serial.read ();
 if ( c != '\r' && R < 15 ) 
   input[R++] = c;   
 else
 {
   input[R] = '\0';
   R = 0;
// NOTE: typing number in serial monitor will set clock to given MINUTE     
   int number = atoi( input );
   Serial.println( number );
   mp_reset(number); }}
// - - - - - - - - - - - - - - - - - - SECOND COUNTER
currentMillis = millis();  
if ((currentMillis - previousMillis) > 1000) {
counter = (((currentMillis - startTime) + adjuster)/1000);
    previousMillis = currentMillis;
}
// - - - - - - - - - - - - - - - - COUNTER CONVERSION
Min = counter / 60;
Sec = counter % 60;
if (counter != prevCounter) {
    Serial.print (Min);
    Serial.print (":");
    Serial.println (Sec);
    prevCounter = counter;
}
// - - - - - - - - - - - - - - - - MINUTE SWICH
switch (Min) {

//  mp_sequence1I (int ax[],int axSz, int instruction, int dlyTime, float stagger)
//  mp_mInstructor (int ax[], int axSz, int instruction, int dlyTime, float stagger, bool amIRandom)
//  mp_sequence2I (int ax[],  int axSz, int instruction1, int instruction2, int dlyTime, float stagger, int increment)
//  mp_sequence3I (int ax[], int axSz, int instruction1, int instruction2, int instruction3, int dlyTime, float stagger) 
//  mp_sequence6I (int ax[], int axSz, int instructionx[], int dlyTime, float stagger, int increment)
//  mp_sequenceAI (int ax[], int axSz, int instructionx[], int instructionASz, int dlyTime, float stagger)
//  mp_TL3I (int ax[], int axSz, int instructionx[], int dlyTime)
//  mp_TLD3I (int ax[], int axSz, int instructionx[], int dlyTime)
//  mp_TL6I (int ax[], int axSz, int instructionx[], int dlyTime, int increment)
//  mp_FB1I (int ax[], int axSz, int instruction, int dlyTime, float stagger)
//  mp_FB6I (int ax[], int axSz, int instructionx[], int dlyTime, float stagger) 
//  mp_region1I (int region,int regionSize,int instruction, int dlyTime, float stagger) 
//  mp_regionAI (int region, int regionSize, int instructionx[], int instructionASz, int dlyTime, float stagger)
//  mp_fcnAlt(int region1, int region1Sz, int region2, int region2Sz, int instruction1, int instruction2, int dlyTime, float stagger)
//  mp_fcnLigeti(int region1, int region1Sz, int region2, int region2Sz, int instruction1, int instruction2, int tempo, int ratio1, int ratio2)
//  mp_grandLigeti(int howManyDivisions, int instructionx1[], int instructionx1Sz, int instructionx2[], int instructionx2Sz, int tempo, int multiple) 
//  mp_random1I (int axSH[], int axSHSz, int instruction, int dlyTime, float stagger) 
//  mp_random2I (int axSH[], int axSHSz, int instruction1, int instruction2, int dlyTime, float stagger, int increment)
//  mp_randomAI (int axSH[], int axSHSz, int instructionx[], int instructionASz, int dlyTime, float stagger) 
//  mp_wireAdjuster (int ax[], int axSz, int prevInstruction, int instruction) 
//  mp_wireArrayAdjuster (int ax[], int axSz, int prevInstructionx[], int prevInstructionxSz, int instruction) 




// * * * * * INITIALIZATION * * * * * 
// - - - - - - - - - - - - - - - - 0:00 - ||  
  case 0:
  
    if (Sec > 10 && Sec < 15) mp_wireTransmitter(10, 161);
// vent group 10 starts, randomly alternating between two states

    if (Sec > 30 && stopNow == false) {
        mp_TL6I(vex10, 17, lOnOffFAST, 200, 3);
        mp_TL6IR(vex10, 17, lOnOffFAST, 200, 3);
// two longitudinal sweeps, one forward and one backward, of chrOns
        stopNow = true; }
        
    break;
    
// - - - - - - - - - - - - - - - - 1:00 - ||  
  case 1: 

// **** 1:00-1:20 longitude scans continue ****
  
    if (Sec > 20 && Sec < 30 && allOn == false) {
        stopNow = false;
        mp_sequence2I (vex10, 17, 33, 146, 150, 1, 3);
// chorus powers on, then flutters quickly
        allOn = true; }
       
    if (Sec > 40 && Sec < 43  && allOn == true) {
        mp_sequence1I (vexRW10, 17, 20, 20, 1); 
// chorus quickly off
        allOn = false; }
        
    if (Sec > 39 && Sec < 45) {
        mp_wireTransmitter(7, 161);
        mp_wireTransmitter(8, 162);
        mp_wireTransmitter(9, 164); }
// 7,8,and 9 flutter counterpoints, joining group 10

    break;
    
// - - - - - - - - - - - - - - - - 2:00 - ||  
  case 2:
  
    if (Sec > 1 && Sec < 30 && allOn == false) {
          mp_sequenceAI (vexRW7_8_9_10, 14, chrOns, 7, 1000, 2);
// chrOns distributed across surface
          delay (1000);
          mp_sequence2I (vexRL10_16, 16, 41, 31, 200, 1, 4);
// chorus off then on

          mp_wireTransmitter(16, 40);
          delay (500);
          mp_wireTransmitter(16, 162);
// 16 chroff and then joins 10 as a counterpoint unit

          allOn = true; }
          
      if (Sec > 40 && Sec < 45 && stopNow == false) {
          mp_wireTransmitter(10, 40);
          delay (500);
          mp_wireTransmitter(10, 160);
          stopNow = true; }
// 10 shifts its counterpoint status slightly

      if (Sec > 45 && Sec < 59) {
          mp_TL3I (vexWR10_16, 16, lOffMID, 450);
// slow longitudinal offs across
          allOn = false;
          stopNow = false; }

    break;
    
// - - - - - - - - - - - - - - - - 3:00 - ||  

  case 3:
  
// **** 3:05-3:30 tacet (10 and 16 are counterpointers) ****
  
    if (Sec > 30 && Sec < 45 && allOn == false) {
          mp_TLD3I(vexWR10, 17, lOnMID, 1000);
// chorus on for everyone, except 10 (16 is now a chron)
          allOn = true; }
          

    if (Sec > 45 && Sec < 48 && stopNow == false) {
          mp_regionAI(6, 3, chrFlttrs, 8, 100, 2);
          stopNow = true; }
 // chrfltters in rear (6, 5, and 13)
    
    if (Sec > 47 && Sec < 49 && stopNow == true) { 
          mp_sequenceAI (vWing, 5, chrFlttrs, 8, 100, 2);
          stopNow = false; }
// chrfltters in wings
    
    if (Sec > 51 && Sec < 55) mp_region1I(6, 4, 149, 100, 2);
// fast chrflttr in back (6, 5, 4, and 13)
    
    if (Sec > 55 && Sec < 57) mp_wireTransmitter(15, 145);
// chrflttr in group 15
    
    if (Sec > 57 && Sec < 59) mp_sequence1I (vWing, 5, 43, 10, 1);    
// wings chroff

    break;
    
// - - - - - - - - - - - - - - - - 4:00 - ||  

  case 4:
  
    if (Sec > 1 && Sec < 8 && stopNow == false) {
        mp_sequence1I (vexWR7_8_9_10, 14, 30, 10, 1);
        mp_sequenceAI (vexWR7_8_9_10, 14, chrFlttrs, 8, 10, 1);
// flutters across whole ship except front wing
        stopNow = true; }

    if (Sec > 8 && Sec < 11) stopNow = false;
    
    if (Sec > 15 && Sec < 24 && stopNow == false) {
      mp_sequence1I (vexWR7_8_9_10, 14, 30, 10, 1);
      mp_sequence1I (vexWR7_8_9_10, 14, 148, 10, 1); 
      stopNow = true; }
// flutters intensify

    if (Sec > 30 && Sec < 32) {
      stopNow = false;
      mp_wireTransmitter(17, 211); 
      delay(800);
      mp_wireTransmitter(18, 213); }
// rear wing starts doing ligeti

    if (Sec > 41 && Sec < 52 && BOn == false) {
        mp_randomAI(vBSH, 9, ligetis, 5, 10, 1);
        mp_random1I(vASH, 9, 49, 500, 4);
// B does ligeti, A shuts off
        BOn = true;
        allOn = false;
        stopNow = false; }
        
// **** 4:51-5:00 tacet (Bs are ligeti) ****

    break;

// - - - - - - - - - - - - - - - - 5:00 - ||  
  case 5:
  
// **** 5:00-5:20 tacet (Bs are ligeti) ****

    if (Sec > 20 && Sec < 34 && BOn == true) {
          mp_random1I(vBSH, 9, 49, 1000, 2);
// B group fades out very slowly

          mp_wireTransmitter(19, 200);
// * TRANSDUCER FADE IN STARTS      
          BOn = false; }


// * * * * * LIFTOFF * * * * * 

    if (Sec > 50 && BOn == false) {
        mp_sequence1I(allT, 3, 210, 10, 1);
// * LEDS -> WHITE  
      
        mp_random1I(vBSH, 9, 55, 5, 150);
// B group "grey" units turn on        
        BOn = true; }

    if (Sec > 56 && allOn == false) {
        mp_sequence1I(vRL, 18, 30, 5, 10);
// chorus of whole ship turns on, accompanying "grey" units

        mp_wireTransmitter(16, 150);
        mp_wireTransmitter(14, 151); 
// 16 and 14 "grey" units flutter

        allOn = true; }
        
    break;
    
// - - - - - - - - - - - - - - - - 6:00 - ||  
  case 6:
  
    if (Sec > 5 && Sec < 55 && stopNow == false) {
      mp_randomAI(vBSH, 9, solFlttrs, 3, 1000, 7);
      stopNow = true; }
// flutters distributed evenly around "grey" units  

// **** 6:36-7:20 tacet (Bs have solflttrs) ****

    break;
    
// - - - - - - - - - - - - - - - - 7:00 - ||  
  case 7:
  
    if (Sec < 20) stopNow = false;
    if (Sec > 20 && Sec < 27 && stopNow == false) {
      mp_wireTransmitter(2,52);
      delay (1000);
      mp_wireTransmitter(3,53);
      delay (1400);
      mp_wireTransmitter(1,59); 
// 1, 2, and 3 teeth units turn on
      stopNow = true; }
      
    if (Sec > 21 && Sec < 55) mp_fcnLigeti(6, 2, 7, 1, 54, 65, 30, 3, 5);
// solOff and solOn alternation between rear and front wing
     
    if (Sec > 27 && Sec < 29) stopNow = false;
    
    if (Sec > 29 && Sec < 33 && stopNow == false) {
        mp_wireTransmitter(2,63);
        mp_wireTransmitter(3,64);
        delay (1100);
        mp_wireTransmitter(4,56);
// 2 and 3 teeth units turn off / 4 turns on
        stopNow = true; }
        
    if (Sec > 33 && Sec < 37) stopNow = false;
    
    if (Sec > 37 && Sec < 40 && stopNow == false) {
      mp_wireTransmitter(1, 65);
// 1 teeth unit turns off
      stopNow = true; }
      
    if (Sec > 39 && Sec < 41) mp_wireTransmitter (4, 66);
// 4 teeth unit turns off

    if (Sec > 43 && Sec < 47) stopNow = false;
    
    if (Sec > 50 && Sec < 52 && stopNow == false) {
        mp_wireTransmitter(2,53);
        mp_wireTransmitter(3,52);
// 2 and 3 teeth units turn on
        stopNow = true; }
        
    if (Sec > 51 && Sec < 54) stopNow = false;
    
    if (Sec > 53 && Sec < 57 && stopNow == false) {
        mp_wireTransmitter(2,69);
        mp_wireTransmitter(3,68);
// 2 and 3 teeth units turn off
        delay (1300);
        mp_wireTransmitter(5,65);
        mp_wireTransmitter(6,65);
        mp_wireTransmitter(7,65);
// teeth units 5, 6, aand 7 turn off
        stopNow = true; }
        
    break;
    
// - - - - - - - - - - - - - - - - 8:00 - ||  
  case 8:
  
    if (Sec > 3 && Sec < 57) {
        mp_fcnLigeti(5, 2, 7, 1, 53, 63, 28, 3, 5);
// rear and front wing alternate solOn and solOff
        mp_fcnLigeti2(1, 1, 3, 1, 54, 64, 45, 4, 7);
// 1 and 3 alternate solOn and solOff
        mp_mInstructor (vex1_3_4_5_7, 13, 20, 2000, 4, false);
// allOffs distributed to everyone else rather slowly
        allOn = false;
        stopNow = false; }

    
    if (Sec > 56) {
      mp_wireTransmitter(4,60);
      mp_wireTransmitter(5,60);
      mp_wireTransmitter(7,61); }
// precaution fadeout of 4, 5, and 6

    break;
    
// - - - - - - - - - - - - - - - - 9:00 - ||  
  case 9:
  
    if (Sec > 1 && Sec < 4) { 
      mp_wireTransmitter(1, 64);
      mp_wireTransmitter(3, 64); }
// precaution fadeout of 1, and 3

    if (Sec > 1 && Sec < 26)  mp_mInstructor (vBex1_3_4_5_7, 13, 20, 1000, 4, false);
// continue with alloffs just to make sure

    if (Sec > 26 && Sec < 33) mp_sequence1I (v, 18, 20, 1, 1);
// last ditch "make sure all off!!!"

    if (Sec > 34 && Sec < 37) mp_sequence1I(allT, 3, 201, 10, 1);
// * TRANSDUCER FADE IN OF TRACK 2
    
    if (Sec > 35 && Sec < 42) { 
        mp_mInstructor (vBSH, 9, 10, 1, 1, true);
        mp_mInstructor2 (vASH, 9, 10, 1, 1, true); }
// BIG fadein as fast as possible

    if (Sec > 41 && Sec < 50 && stopNow == false) {
      mp_randomAI(vASH, 9, solFlttrs, 3, 10, 7);
// teeth groups Hi-PWM flutters
      stopNow = true;
    }

    break;
    
// - - - - - - - - - - - - - - - -10:00 - ||  
  case 10:
  
// **** 10:00-11:30 tacet ****
// structural rhythm slows, all vents are on with light fluttering of teeth

    break;   
    
// - - - - - - - - - - - - - - - -11:00 - ||  
  case 11:
  
    if (Sec < 6) stopNow = false;
    if (Sec  > 30 && Sec < 59) mp_fcnAlt(18, 2, 8, 3, 42, 33, 3500, 1);
// chroff alternation starts in wings

    break;
    
// - - - - - - - - - - - - - - - -12:00 - ||  
  case 12:
  
    if (Sec > 1 && Sec < 4) mp_wireAdjuster (v, 18, 42, 31);
// lingering chrOns adjusted to chrOffs

    if (Sec > 3 && Sec < 59) mp_fcnAlt(18, 2, 8, 3, 43, 36, 3500, 2.5);
// chroff alternation gets slightly slower and slightly unstable

    break;
    
// - - - - - - - - - - - - - - - -13:00 - ||  
  case 13:
  
    if (Sec > 1 && Sec < 4) mp_wireAdjuster (v, 18, 43, 31);
// lingering chrOns adjusted to chrOffs

    if (Sec > 3 && Sec < 57) mp_fcnAlt(17, 1, 8, 2, 46, 36, 4000, 2.5);
// chroff alternation in wings narrows and becomes more unstable

    break;
    
// - - - - - - - - - - - - - - - -14:00 - ||  
  case 14:
  
    if (Sec > 2 && Sec < 5) mp_wireAdjuster (v, 18, 46, 31);
// lingering chrOns adjusted to chrOffs
    
    if (Sec > 4 && Sec < 15 && stopNow == false) {
      mp_randomAI (vWingSH, 5, chrOns, 7, 1000, 2);
      stopNow = true; }
// chrOns distributed across wings

    if (Sec > 15 && Sec < 25) stopNow = false;

    if (Sec > 30 && stopNow == false) { 
        mp_wireTransmitter (16, 168);
// 16 starts counterpoint motion

        mp_random1I (vWingSH, 5, 49, 200, 1);
// wings turn off "very slowly" 
        stopNow = true; }     

// **** 14:33-15:00 tacet (rest of ship remains on) ****

    break;
    
// - - - - - - - - - - - - - - - -15:00 - ||  
  case 15:
  
    if (Sec < 3) stopNow = false;

    if (Sec > 3 && Sec < 6 && stopNow == false) {
      mp_sequence1I(allT, 3, 202, 10, 1);
      stopNow = true; }
// * TRANSDUCER FADE IN OF TRACK 3, TRIGGERING LARGE SCALE SHUTOFF

    if (Sec > 5 && Sec < 8) stopNow = false;
     
    if (Sec > 8 && stopNow == false) { 
        mp_sequence2I(vRL, 18, 64, 44, 2000, 1, 4);
// "multi-stage shutoff" off, with only transducers left
        stopNow = true; }

    break;
    
// - - - - - - - - - - - - - - - -16:00 - ||  
  case 16:

  stopNow = false;
  
// **** 15:40-17:30 tacet **** (only transducers)

    break;
    
// - - - - - - - - - - - - - - - -17:00 - ||     
  case 17:
  
// * * * * * SUBLIGHT * * * * * 

    if (Sec > 30) mp_grandLigeti(8, solFinsLO6, 3, solFoutsLO6, 3, 12, 2);
// 8-segment giant millis metronome
    if (Sec > 30 && stopNow == false) {
        mp_sequence1I(allT, 3, 211, 10, 1);
        mp_sequence1I(allT, 3, 203, 10, 1);
        stopNow = true; }
// * LEDS -> RED, TRANSDUCERS TRACK 4
 
    break;
    
// - - - - - - - - - - - - - - - -18:00 - ||  
  case 18:
  
    stopNow = false;
    
    mp_grandLigeti(8, solFinsLO6, 3, solFoutsLO6, 3, 12, 2);
// 8-segment giant millis metronome continues

    break;
    
// - - - - - - - - - - - - - - - -19:00 - ||  
  case 19:
  
    if (Sec < 5) { 
        mp_wireArrayAdjuster (v, 18, solFinsLO6, 3, 106);
// precaution to adjust to transition
        stopNow = false; }
  
    if (Sec > 5) mp_grandLigeti(8, solFinsLO2, 3, solFoutsLO2, 3, 13, 2);
// 8-segment giant millis metronome transitions from 6-banks to 2-banks

    break;
    
// - - - - - - - - - - - - - - - -20:00 - ||  
  case 20:
  
    if (Sec < 3 && stopNow == false) {
        mp_sequenceAI(vB, 9, chayaCH, 7, 1, 1);
        stopNow = true; }  
// vBs assigned to counterpoint
  
    if (Sec > 3) { 
        mp_grandLigeti(8, solFinsLO2, 3, solFoutsLO2, 3, 13, 2);
        stopNow = false; }  
// 8-segment giant millis metronome continues

    break;   
    
// - - - - - - - - - - - - - - - -21:00 - ||  
  case 21:
  
    if (Sec < 3 && stopNow == false) {
        mp_sequenceAI(vA, 9, chayaCH, 7, 1, 1);
        mp_sequenceAI(vB, 9, chrOffs, 7, 1, 1);
        stopNow = true; }  
// vAs assigned to counterpoint, vBs chroff
  
    if (Sec > 3 && Sec < 47) {
        mp_grandLigeti(8, solFinsLO2, 3, solFoutsLO2, 3, 13, 3);
        stopNow = false; }        
// 8-segment giant millis metronome continues
    if (Sec > 46 && Sec < 49) gLigetiInit = true;
    if (Sec > 49) mp_grandLigeti(4, solFinsMID2, 3, solFoutsMID2, 3, 10, 3);
// 8-segment giant millis metronome transitions to 4 segments


    break;   
        
// - - - - - - - - - - - - - - - -22:00 - ||  
  case 22:
  
    if (Sec < 3 && stopNow == false) {
        mp_sequenceAI(vB, 9, chayaCH, 7, 1, 1);
        mp_sequenceAI(vA, 9, chrOffs, 7, 1, 1);
        stopNow = true; }  
// vBs assigned to counterpoint, vAs chroff

    if (Sec > 3) {
        mp_grandLigeti(4, solFinsMID2, 3, solFoutsMID2, 3, 10, 3);
        stopNow = false; }
// 4-segment giant millis metronome continues

    if (Sec > 51 && Sec < 54) mp_sequence1I(v, 18, 40, 1, 1);
// chrOffs distributed to everyone, chaya metronome off

    break;  
         
// - - - - - - - - - - - - - - - -23:00 - ||  
  case 23:
  
    mp_grandLigeti(4, solFinsMID2, 3, solFoutsMID2, 3, 10, 3);
// 4-segment giant millis metronome continues

    break;
           
// - - - - - - - - - - - - - - - -24:00 - ||  
  case 24:
  
    if (Sec < 3 && stopNow == false) {
        mp_sequenceAI(vA, 9, chayaCH, 7, 1, 1);
        mp_sequenceAI(vB, 9, chrOffs, 7, 1, 1);
        stopNow = true; }
// vAs assigned to counterpoint, vBs chroff
  
    if (Sec > 3 && Sec < 20) {
        mp_grandLigeti(4, solFinsMID2, 3, solFoutsMID2, 3, 10, 3);
        stopNow = false; }
// 4-segment giant millis metronome continues      
    if (Sec > 19 && Sec < 22) gLigetiInit = true;
    if (Sec > 22) mp_grandLigeti(8, solFinsMID4, 3, solFoutsMID4, 3, 13, 2);  
// 4-segment giant millis metronome transitions to 8 segments
  
    break;  
         
// - - - - - - - - - - - - - - - -25:00 - ||  
  case 25:
  
    if (Sec < 3 && stopNow == false) {
        mp_sequenceAI(vB, 9, chayaCH, 7, 1, 1);
        mp_sequenceAI(vA, 9, chrOffs, 7, 1, 1);
        stopNow = true; }
// vBs assigned to counterpoint, vAs chroff
  
    if (Sec > 3 && Sec < 57) {
        mp_grandLigeti(8, solFinsMID4, 3, solFoutsMID4, 3, 13, 2);
        stopNow = false; } 
// 8-segment giant millis metronome continues   
        
    if (Sec > 56) mp_sequence1I(v, 18, 40, 1, 1);
// chaya CH metronome stops

    break;  
         
// - - - - - - - - - - - - - - - -26:00 - ||  
  case 26:
  
    mp_grandLigeti(8, solFinsMID4, 3, solFoutsMID4, 3, 13, 2); 
// 8-segment giant millis metronome continues 


// * * * * * LIGHTSPEED * * * * * 

    if (Sec < 15 && stopNow == false) {
        mp_sequence1I(allT, 3, 212, 10, 1);
        stopNow = true; }
// * BLUE LIGHTS
        
    if (Sec > 15 && Sec < 19) { 
      mp_wireArrayAdjuster (v, 18, solFinsMID4, 3, 61);  
      gLigetiInit = true; }
    if (Sec > 18) mp_grandLigeti(2, solFinsLO6, 3, solFoutsLO6, 3, 3, 1);
// giant millis metronome slows down a TON

    if (Sec > 45 && stopNow == true) {
        mp_sequence1I(allT, 3, 204, 10, 1);
        stopNow = false; }        
// * TRANSDUCERS TRANSITION TO TRACK 5

    if (Sec > 47) mp_grandLigeti2(213, 214, 5, 2);
    break;   
        
// - - - - - - - - - - - - - - - -27:00 - ||  
  case 27:
  
    mp_grandLigeti2(213, 214, 5, 2);
// * LED BLUES THROB RHYTHMICALLY

    mp_grandLigeti(2, solFinsLO6, 3, solFoutsLO6, 3, 3, 1);
// slowed-down 8-segment giant millis metronome continues 
    
    break;   
        
// - - - - - - - - - - - - - - - -28:00 - ||  
  case 28:

    mp_grandLigeti2(213, 214, 8, 2);
// * LED BLUES SPEEDS UP

    mp_grandLigeti(2, solFinsLO6, 3, solFoutsLO6, 3, 3, 1);
// slowed-down 8-segment giant millis metronome continues 

    break;    
       
// - - - - - - - - - - - - - - - -29:00 - ||  
  case 29:

    mp_grandLigeti2(213, 214, 8, 2);
// * LED BLUES THROB RHYTHMICALLY

    mp_grandLigeti(2, solFinsLO6, 3, solFoutsLO6, 3, 3, 1);
// slowed-down 8-segment giant millis metronome continues 
    
    break;   
    
// - - - - - - - - - - - - - - - -30:00 - ||  
  case 30:

    mp_grandLigeti2(213, 216, 9, 2);
// * LED BLUES CHANGE COLOR SLIGHTLY

    mp_grandLigeti(2, solFinsLO6, 3, solFoutsLO6, 3, 3, 1);
// slowed-down 8-segment giant millis metronome continues 
    
    break;   
    
// - - - - - - - - - - - - - - - -31:00 - ||  
  case 31:
  
    mp_grandLigeti2(213, 216, 9, 3);
// * LED BLUES SLOW

    if (Sec < 10) mp_wireArrayAdjuster (vA, 9, solFinsLO6, 3, 61);
// any remaining vAs power down (solOff) 

    if (Sec > 10 && Sec < 17) mp_wireArrayAdjuster (vB, 9, solFinsLO6, 3, 61);
// any remaining vBs power down (solOff)     

    break;   
    
// - - - - - - - - - - - - - - - -32:00 - ||  
  case 32:

    mp_grandLigeti2(213, 216, 7, 3);
// * LED BLUES SLOW FURTHER, TRANSDUCERS ONLY

    break;   
    
// - - - - - - - - - - - - - - - -33:00 - ||  
  case 33:

    mp_grandLigeti2(215, 216, 6, 3);
// * LED BLUES CHANGE COLOR AND SLOW FURTHER, TRANSDUCERS ONLY

    break;   
    
// - - - - - - - - - - - - - - - -34:00 - ||  
  case 34:
  
    mp_grandLigeti2(215, 216, 6, 3);
// * LED BLUES CONTINUE, TRANSDUCERS ONLY

    break;   
        
// - - - - - - - - - - - - - - - -35:00 - ||  
  case 35:
  
    mp_grandLigeti2(215, 216, 6, 3);
// * LED BLUES CONTINUE, TRANSDUCERS ONLY

    break;   
    
// - - - - - - - - - - - - - - - -36:00 - ||  
  case 36:

    mp_grandLigeti2(215, 216, 6, 3);
// * LED BLUES CONTINUE, TRANSDUCERS ONLY

    break;   

// - - - - - - - - - - - - - - - -37:00 - ||  
  case 37:

    mp_grandLigeti2(215, 216, 6, 3);
// * LED BLUES CONTINUE, TRANSDUCERS ONLY

    if (Sec < 20 && stopNow == false) {
        mp_randomAI (vSH, 18, musicians, 39, 10, 4); 
        stopNow = true; }
// bank of "musicians" distributed around
    
    if (Sec > 50 && Sec < 55) {  
        mp_fastWireTransmitter (v, 18, 20);
        stopNow = false; }
// musicians power off
    
    break;   

// - - - - - - - - - - - - - - - -38:00 - ||  
  case 38:
  
    mp_grandLigeti2(215, 216, 6, 3);
// * LED BLUES CONTINUE, TRANSDUCERS ONLY  

    if (Sec < 20 && stopNow == false) {
        mp_randomAI (vSH, 18, musicians, 39, 800, 4); 
        stopNow = true; }
// second bank of "musicians" distributed around (slower this time)
        
    if (Sec > 50 && Sec < 55) {  
        mp_fastWireTransmitter (v, 18, 20);
        stopNow = false;
        mp_sequence1I (v, 18, 20, 10, 1); }        
// musicians power off again
  
    break;   

// - - - - - - - - - - - - - - - -39:00 - ||  
  case 39:
  
    mp_grandLigeti2(216, 218, 6, 3);
// * LED BLUES START FADEOUT, TRANSDUCERS ONLY  
  
  mp_sequence1I (v, 18, 20, 10, 1);
// power remains off
  
    break;   
    
// - - - - - - - - - - - - - - - -40:00 - ||  
  case 40:
  
    mp_grandLigeti2(216, 218, 6, 3);
// * LED BLUES CONTINUE FADEOUT, TRANSDUCERS ONLY  
  
    break; 

// - - - - - - - - - - - - - - - -41:00 - ||  
  case 41:
  
    mp_grandLigeti2(216, 218, 6, 3);
// * LED BLUES INTENSIFY FADEOUT, TRANSDUCERS ONLY  
  
    break; 

// - - - - - - - - - - - - - - - -42:00 - ||  
  case 42:
  
    mp_grandLigeti2(217, 219, 6, 3);
// * LED BLUES CONTINUE FADEOUT, TRANSDUCERS ONLY  
  
    break; 
    
// - - - - - - - - - - - - - - - -43:00 - ||  
  case 43:

  if (Sec < 50 && stopNow == false) {
    mp_sequence1I (v, 18, 20, 10, 1);
// safety shutoff of fans

    mp_sequence1I(allT, 3, 220, 10, 1); }
// * LEDS HARD CUT     

  if (Sec > 50) mp_reset(0);
// power remains off, reset

    break; 
    
  }  // switch machine ends

} // void loop ends




























// - - - - - - - - - - - - - - DISTRIBUTIVE FUNCTIONS - ||
// - - - - - - - - - - - - - - SEQUENTIAL INSTRUCTORS - ||
// Sequential 1-Instructor
// GOOD FOR DISTRIBUTING SINGLE COMMAND TO ENTIRE VENT ARRAYS
  void mp_sequence1I (int ax[],int axSz, int instruction, int dlyTime, float stagger)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instruction, // instruction in question
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
    for (int i=0; i< axSz; i++) {
        mp_wireTransmitter (ax[i], instruction);
        delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1)); }
  }

// millis() 1-Instructor
// GOOD FOR PASSING INSTRUCTIONS WHILE OTHER MILLIS FUNCTION IS HAPPENING
  void mp_mInstructor (int ax[], int axSz, int instruction, int dlyTime, float stagger, bool amIRandom)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instruction, // instruction in question
//  int dlyTime, // interval between successive instructions
//  float stagger, // 1 for nonrandom
//  bool amIRandom) // shuffles or doesnt shuffle array
  {    
  static unsigned long mInstructorCounter;
  
  if ((mIStorageSZ != axSz) && (mIStorageA1 != ax[0]) && (prevmInstruction != instruction)) {
    mInstructorReset = true; }
  // checks conditions to set about an auto-reset
  if (mInstructorReset == true) {
    mInstructorAssigner = 0;
    mIStorageSZ = axSz; 
    mIStorageA1 = ax[0];
    prevmInstruction = instruction;
  }
  // resets all counters
  
  if (mInstructorAssigner > axSz) mInstructorAssigner = 0;
  // resets the assigner counter
  if ((mInstructorAssigner == 0) && (amIRandom == true)) shuffleArray (ax, axSz); 
  // randomizes (only after array is completed)
  if (mInstructorAssigner < axSz) {
    if (millis() > mInstructorCounter) {
          mp_wireTransmitter (ax[mInstructorAssigner], instruction);
          mInstructorAssigner++;
          int truDly = dlyTime;
          if (stagger != 1) {
            truDly = jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1); }
          mInstructorCounter = millis() + truDly;
          mInstructorReset = false;
      }}}
  
// millis() 1-Instructor (No 2)
// GOOD FOR PASSING INSTRUCTIONS WHILE OTHER MILLIS FUNCTION IS HAPPENING
  void mp_mInstructor2 (int ax[], int axSz, int instruction, int dlyTime, float stagger, bool amIRandom)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instruction, // instruction in question
//  int dlyTime, // interval between successive instructions
//  float stagger, // 1 for nonrandom
//  bool amIRandom) // shuffles or doesnt shuffle array
  {
  static unsigned long mInstructorCounter2;
  if ((mIStorageSZ2 != axSz) && (mIStorageA12 != ax[0]) && (prevmInstruction2 != instruction)) {
    mInstructorReset2 = true; }
  // checks conditions to set about an auto-reset
  if (mInstructorReset2 == true) {
    mInstructorAssigner2 = 0;
    mIStorageSZ2 = axSz; 
    mIStorageA12 = ax[0];
    prevmInstruction2 = instruction;
  }
  // resets all counters
  if (mInstructorAssigner2 > axSz) mInstructorAssigner = 0;
  // resets the assigner counter
  if ((mInstructorAssigner2 == 0) && (amIRandom == true)) shuffleArray (ax, axSz); 
  // randomizes (only after array is completed)
  if (mInstructorAssigner2 < axSz) {
    if (millis() > mInstructorCounter2) {
          mp_wireTransmitter (ax[mInstructorAssigner2], instruction);
          mInstructorAssigner2++;
          int truDly = dlyTime;
          if (stagger != 1) {
            truDly = jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1); }
          mInstructorReset2 = false;
          mInstructorCounter2 = millis() + truDly;
      }}}

// Sequential 2-Instructor
// GOOD FOR DISTRIBUTING COMMAND AND DEACTIVATING IT IN SEQUENCE
  void mp_sequence2I(int ax[],  int axSz, int instruction1, int instruction2, int dlyTime, float stagger, int increment)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instruction1, 
//  int instruction2, 
//  int dlyTime, // interval between successive instructions
//  float stagger, // 1 for nonrandom
//  int increment) // distance between instruction 1 and instruction 2
  {
    for (int i=0; i< (axSz + increment); i++) {
      if ((i - increment) >= 0) {
        mp_wireTransmitter (ax[(i - increment)], instruction2); }
      if (i < axSz) {   
        mp_wireTransmitter (ax[i], instruction1); }
      delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1));
      if (i > axSz) {
        mp_wireTransmitter (ax[(i - increment)], instruction2); }
    }
  }
  
// Sequential 3-Instructor
// GOOD FOR LONGITUDE ARRAYS IN SEQUENCE
  void mp_sequence3I(int ax[], int axSz, int instruction1, int instruction2, int instruction3, int dlyTime, float stagger)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instruction1, 
//  int instruction2, 
//  int instruction3, 
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
  for (int i=0; i<axSz; i++) {
    for (int x=0; x<3; x++) {
      switch (x) {
        case 0:
          mp_wireTransmitter (ax[i], instruction1);
          break;
        case 1:
          mp_wireTransmitter (ax[i], instruction2);
          break;      
        case 2:
          mp_wireTransmitter (ax[i], instruction3);
          break;
        }
      delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1));
      }
    }   
  }

//Sequential 6-Instructor
// GOOD FOR LONGITUDINAL "SCAN" ACROSS SURFACE
  void mp_sequence6I(int ax[], int axSz, int instructionx[], int dlyTime, float stagger, int increment)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instructionx[], // array of 6 instructions 
//  int dlyTime, // interval between successive instructions
//  float stagger, // 1 for nonrandom
//  int increment) // distance between instructions 1-3 and 4-6
  {
  for (int i=0; i<(axSz + increment); i++) {
  // run through entire array issuing instructions
    if (i <= axSz) {
      for (int x=0; x<3; x++) {
        switch (x) {
          case 0:
              mp_wireTransmitter (ax[i], instructionx[1]);
              if ((i - increment) >= 0) {
                mp_wireTransmitter (ax[(i - increment)], instructionx[4]); }
              delay (dlyTime/4);
            break;
          case 1:
              mp_wireTransmitter (ax[i], instructionx[2]);
              if ((i - increment) >= 0) {
                mp_wireTransmitter (ax[(i - increment)], instructionx[5]); }  
              delay (dlyTime/4);
            break;      
          case 2:
              mp_wireTransmitter (ax[i], instructionx[3]);
              if ((i - increment) >= 0) {
                mp_wireTransmitter (ax[(i - increment)], instructionx[6]); }         
              delay (dlyTime/4);
            break;
            }
        delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1));
        }
      }
  // issue remaining instructions after first run-through has finished 
    if (i > axSz) {
      for (int x=0; x<3; x++) {
        switch (x) {
          case 0:
              mp_wireTransmitter (ax[(i - increment)], instructionx[4]);       
              delay (dlyTime/4);
              break;          
          case 1:
              mp_wireTransmitter (ax[(i - increment)], instructionx[5]);
              delay (dlyTime/4);
              break;
          case 2:
              mp_wireTransmitter (ax[(i - increment)], instructionx[6]);
              delay (dlyTime/4);
              break;
            } 
          delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1));
        }
      }
    }
  }
  
// Sequential Array-Instructor
// GOOD FOR DISTRIBUTING RANDOM INSTRUCTIONS FROM WITHIN AN ARRAY SEQUENTIALLY
  void mp_sequenceAI(int ax[], int axSz, int instructionx[], int instructionASz, int dlyTime, float stagger)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instructionx[], // instruction in question
//  int instructionASz,
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
    for (int i=0; i< axSz; i++) {
      int instruction = instructionx[(jo_rand (0, instructionASz, 1))];
        mp_wireTransmitter (ax[i], instruction);
        delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1)); }
  }

// - - - - - - - - - - - - - - TRUE LONGITUDE INSTRUCTORS - ||
// True Longitude 3-Instructor
// DISTRIBUTES ONE COMMAND ACROSS LONGITUDINAL SERIES
  void mp_TL3I(int ax[], int axSz, int instructionx[], int dlyTime)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instructionx[], // instruction array
//  int dlyTime) // interval between successive instructions
  {
  int pos1 = 100;
  int pos2 = 100;
  int pos3 = 100;
  int pos4 = 100;
  int axisSz = 0;  
  for (int i=0; i<7; i++) {
  switch(i) {
    case 0: {
      pos1 = mp_arrayCrawler(ax, axSz, 1);
      pos2 = mp_arrayCrawler(ax, axSz, 4);
      int axis1[] = {pos1, pos2};
      axisSz = (sizeof(axis1) / sizeof(int));
      mp_TL3IOperator (ax, axis1, axisSz, instructionx, dlyTime); }
      break;
    case 1: {
      pos1 = mp_arrayCrawler(ax, axSz, 2);
      pos2 = mp_arrayCrawler(ax, axSz, 3);
      pos3 = mp_arrayCrawler(ax, axSz, 6);
      pos4 = mp_arrayCrawler(ax, axSz, 5);
      int axis2[] = {pos1, pos2, pos3, pos4};
      axisSz = (sizeof(axis2) / sizeof(int));
      mp_TL3IOperator (ax, axis2, axisSz, instructionx, dlyTime); }
      break;
    case 2: {
      pos1 = mp_arrayCrawler(ax, axSz, 10);
      pos2 = mp_arrayCrawler(ax, axSz, 11);
      pos3 = mp_arrayCrawler(ax, axSz, 14);
      pos4 = mp_arrayCrawler(ax, axSz, 13);
      int axis3[] = {pos1, pos2, pos3, pos4};
      axisSz = (sizeof(axis3) / sizeof(int));
      mp_TL3IOperator (ax, axis3, axisSz, instructionx, dlyTime); }
    case 3: {
      pos1 = mp_arrayCrawler(ax, axSz, 12);
      pos2 = mp_arrayCrawler(ax, axSz, 15);
      int axis4[] = {pos1, pos2};
      axisSz = (sizeof(axis4) / sizeof(int));
      mp_TL3IOperator (ax, axis4, axisSz, instructionx, dlyTime); }
      break;
    case 4: {
      pos1 = mp_arrayCrawler(ax, axSz, 7);
      pos2 = mp_arrayCrawler(ax, axSz, 17);
      int axis5[] = {pos1, pos2};
      axisSz = (sizeof(axis5) / sizeof(int));
      mp_TL3IOperator (ax, axis5, axisSz, instructionx, dlyTime); }
      break;
    case 5: {
      pos1 = mp_arrayCrawler(ax, axSz, 8);
      pos2 = mp_arrayCrawler(ax, axSz, 9);
      pos3 = mp_arrayCrawler(ax, axSz, 18);
      int axis6[] = {pos1, pos2, pos3};
      axisSz = (sizeof(axis6) / sizeof(int));
      mp_TL3IOperator (ax, axis6, axisSz, instructionx, dlyTime); }
      break;
    case 6: {
      pos1 = mp_arrayCrawler(ax, axSz, 16);
      int axis7[] = {pos1};
      axisSz = (sizeof(axis7) / sizeof(int));
      mp_TL3IOperator (ax, axis7, axisSz, instructionx, dlyTime); }
      break;
    }
  }
}
      void mp_TL3IOperator (int ax[], int axis[], int axisSz, int instructionx[], int dlyTime) {
        for (int x=0; x<3; x++) {
          for (int y=0; y<axisSz; y++){
            if (axis[y] != 100) {
              int pos = axis[y];
              mp_wireTransmitter(ax[pos], instructionx[x]);
              delay (dlyTime);
            }
          }
        }
      }

// True Longitude Double-3-Instructor
// CROSSFADES IN OR OUT ACROSS LONGITUDINAL SERIES
  void mp_TLD3I(int ax[], int axSz, int instructionx[], int dlyTime)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instructionx[], // instruction array
//  int dlyTime) // interval between successive instructions
  {
  int pxs1 = 100;
  int pxs2 = 100;
  int pxs3 = 100;
  int pxs4 = 100;
  int pys1 = 100;
  int pys2 = 100;
  int pys3 = 100;
  int pys4 = 100;
  int axisSz = 0;
  int ayisSz = 0;  
  for (int i=0; i<4; i++) {
  switch(i) {
    case 0: {
      pxs1 = mp_arrayCrawler(ax, axSz, 1);
      pxs2 = mp_arrayCrawler(ax, axSz, 4);
      pys1 = mp_arrayCrawler(ax, axSz, 16);
      int axis1[] = {pxs1, pxs2};
      int ayis1[] = {pys1};
      axisSz = 2;
      ayisSz = 1;
      mp_TLD3IOperator (ax, axis1, axisSz, ayis1, ayisSz, instructionx, dlyTime); }
      break;
    case 1: {
      pxs1 = mp_arrayCrawler(ax, axSz, 2);
      pxs2 = mp_arrayCrawler(ax, axSz, 3);
      pxs3 = mp_arrayCrawler(ax, axSz, 6);
      pxs4 = mp_arrayCrawler(ax, axSz, 5);
      pys1 = mp_arrayCrawler(ax, axSz, 8);
      pys2 = mp_arrayCrawler(ax, axSz, 9);
      pys3 = mp_arrayCrawler(ax, axSz, 18);
      int axis2[] = {pxs1, pxs2, pxs3, pxs4};
      int ayis2[] = {pys1, pys2, pys3};
      axisSz = 4;
      ayisSz = 3;
      mp_TLD3IOperator (ax, axis2, axisSz, ayis2, ayisSz, instructionx, dlyTime); }
      break;
    case 2: {
      pxs1 = mp_arrayCrawler(ax, axSz, 10);
      pxs2 = mp_arrayCrawler(ax, axSz, 13);
      pys1 = mp_arrayCrawler(ax, axSz, 7);
      pys2 = mp_arrayCrawler(ax, axSz, 17);
      int axis3[] = {pxs1, pxs2};
      int ayis3[] = {pys1, pys2};
      axisSz = 2;
      ayisSz = 2;
      mp_TLD3IOperator (ax, axis3, axisSz, ayis3, ayisSz, instructionx, dlyTime); }
      break;
    case 3: {
      pxs1 = mp_arrayCrawler(ax, axSz, 11);
      pxs2 = mp_arrayCrawler(ax, axSz, 14);
      pys1 = mp_arrayCrawler(ax, axSz, 12);
      pys2 = mp_arrayCrawler(ax, axSz, 15);
      int axis4[] = {pxs1, pxs2};
      int ayis4[] = {pys1, pys2};
      axisSz = 2;
      ayisSz = 2;
      mp_TLD3IOperator (ax, axis4, axisSz, ayis4, ayisSz, instructionx, dlyTime); }
      break;
    }
  }
}    
    void mp_TLD3IOperator (int ax[], int axis[], int axisSz, int ayis[], int ayisSz, int instructionx[], int dlyTime) {
      int x = 0;
      for (int x = 0; x < 3; x++) {
        if (axisSz > ayisSz) {
          for (int y = 0; y < axisSz; y++) {
            
            if (axis[y] != 100) {
              mp_wireTransmitter(ax[axis[y]], instructionx[x]); }
              
            if (y < ayisSz) {
              if (ayis[y] != 100) {
                mp_wireTransmitter(ax[ayis[y]], instructionx[(2-x)]); }}
                
            delay (dlyTime/2); }}
            
        if (ayisSz >= axisSz) {
          for (int y = 0; y < ayisSz; y++) {
            
            if (ayis[y] != 100) {
              mp_wireTransmitter(ax[ayis[y]], instructionx[(2-x)]); }
              
            if (y < axisSz) {
              if (axis[y] != 100) {
                mp_wireTransmitter(ax[axis[y]], instructionx[x]); }}
                
            delay (dlyTime/2); }}
            
          }
        }


// True Longitude 6-Instructor
// "SCANS" COMMANDS LONGITUDINALLY ACROSS
  void mp_TL6I(int ax[], int axSz, int instructionx[], int dlyTime, int increment)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instructionx[], // instruction array
//  int dlyTime, interval between successive instructions
//  int increment) // distance between instructions 1-3 and 4-6
  {
  int pos1 = 100;
  int pos2 = 100;
  int pos3 = 100;
  int pos4 = 100;
  int axisSz = 0;  
  for (int i=0; i<(7 + increment); i++) {
    if (i <= 6) {
      switch(i) {
        case 0: {
          pos1 = mp_arrayCrawler(ax, axSz, 1);
          pos2 = mp_arrayCrawler(ax, axSz, 4);
          int axis1[] = {pos1, pos2};
          axisSz = (sizeof(axis1) / sizeof(int));
          mp_TL6IOperator1 (ax, axis1, axisSz, instructionx, dlyTime); }
          break;
        case 1: {
          pos1 = mp_arrayCrawler(ax, axSz, 2);
          pos2 = mp_arrayCrawler(ax, axSz, 3);
          pos3 = mp_arrayCrawler(ax, axSz, 6);
          pos4 = mp_arrayCrawler(ax, axSz, 5);
          int axis2[] = {pos1, pos2, pos3, pos4};
          axisSz = (sizeof(axis2) / sizeof(int));
          mp_TL6IOperator1 (ax, axis2, axisSz, instructionx, dlyTime); }
          break;
        case 2: {
          pos1 = mp_arrayCrawler(ax, axSz, 10);
          pos2 = mp_arrayCrawler(ax, axSz, 11);
          pos3 = mp_arrayCrawler(ax, axSz, 14);
          pos4 = mp_arrayCrawler(ax, axSz, 13);
          int axis3[] = {pos1, pos2, pos3, pos4};
          axisSz = (sizeof(axis3) / sizeof(int));
          mp_TL6IOperator1 (ax, axis3, axisSz, instructionx, dlyTime); }
        case 3: {
          pos1 = mp_arrayCrawler(ax, axSz, 12);
          pos2 = mp_arrayCrawler(ax, axSz, 15);
          int axis4[] = {pos1, pos2};
          axisSz = (sizeof(axis4) / sizeof(int));
          mp_TL6IOperator1 (ax, axis4, axisSz, instructionx, dlyTime); }
          break;
        case 4: {
          pos1 = mp_arrayCrawler(ax, axSz, 7);
          pos2 = mp_arrayCrawler(ax, axSz, 17);
          int axis5[] = {pos1, pos2};
          axisSz = (sizeof(axis5) / sizeof(int));
          mp_TL6IOperator1 (ax, axis5, axisSz, instructionx, dlyTime); }
          break;
        case 5: {
          pos1 = mp_arrayCrawler(ax, axSz, 8);
          pos2 = mp_arrayCrawler(ax, axSz, 9);
          pos3 = mp_arrayCrawler(ax, axSz, 18);
          int axis6[] = {pos1, pos2, pos3};
          axisSz = (sizeof(axis6) / sizeof(int));
          mp_TL6IOperator1 (ax, axis6, axisSz, instructionx, dlyTime); }
          break;
        case 6: {
          pos1 = mp_arrayCrawler(ax, axSz, 16);
          int axis7[] = {pos1};
          axisSz = (sizeof(axis7) / sizeof(int));
          mp_TL6IOperator1 (ax, axis7, axisSz, instructionx, dlyTime); }
          break;
        }
      }
    if ((i - increment + 1) >= 0) {
      int l = (i - increment);
      switch (l) {
        case 0: {
          pos1 = mp_arrayCrawler(ax, axSz, 1);
          pos2 = mp_arrayCrawler(ax, axSz, 4);
          int axis1[] = {pos1, pos2};
          axisSz = (sizeof(axis1) / sizeof(int));
          mp_TL6IOperator2 (ax, axis1, axisSz, instructionx, dlyTime); }
          break;
        case 1: {
          pos1 = mp_arrayCrawler(ax, axSz, 2);
          pos2 = mp_arrayCrawler(ax, axSz, 3);
          pos3 = mp_arrayCrawler(ax, axSz, 6);
          pos4 = mp_arrayCrawler(ax, axSz, 5);
          int axis2[] = {pos1, pos2, pos3, pos4};
          axisSz = (sizeof(axis2) / sizeof(int));
          mp_TL6IOperator2 (ax, axis2, axisSz, instructionx, dlyTime); }
          break;
        case 2: {
          pos1 = mp_arrayCrawler(ax, axSz, 10);
          pos2 = mp_arrayCrawler(ax, axSz, 11);
          pos3 = mp_arrayCrawler(ax, axSz, 14);
          pos4 = mp_arrayCrawler(ax, axSz, 13);
          int axis3[] = {pos1, pos2, pos3, pos4};
          axisSz = (sizeof(axis3) / sizeof(int));
          mp_TL6IOperator2 (ax, axis3, axisSz, instructionx, dlyTime); }
        case 3: {
          pos1 = mp_arrayCrawler(ax, axSz, 12);
          pos2 = mp_arrayCrawler(ax, axSz, 15);
          int axis4[] = {pos1, pos2};
          axisSz = (sizeof(axis4) / sizeof(int));
          mp_TL6IOperator2 (ax, axis4, axisSz, instructionx, dlyTime); }
          break;
        case 4: {
          pos1 = mp_arrayCrawler(ax, axSz, 7);
          pos2 = mp_arrayCrawler(ax, axSz, 17);
          int axis5[] = {pos1, pos2};
          axisSz = (sizeof(axis5) / sizeof(int));
          mp_TL6IOperator2 (ax, axis5, axisSz, instructionx, dlyTime); }
          break;
        case 5: {
          pos1 = mp_arrayCrawler(ax, axSz, 8);
          pos2 = mp_arrayCrawler(ax, axSz, 9);
          pos3 = mp_arrayCrawler(ax, axSz, 18);
          int axis6[] = {pos1, pos2, pos3};
          axisSz = (sizeof(axis6) / sizeof(int));
          mp_TL6IOperator2 (ax, axis6, axisSz, instructionx, dlyTime); }
          break;
        case 6: {
          pos1 = mp_arrayCrawler(ax, axSz, 16);
          int axis7[] = {pos1};
          axisSz = (sizeof(axis7) / sizeof(int));
          mp_TL6IOperator2 (ax, axis7, axisSz, instructionx, dlyTime); }
          break;
        }
     }
  }
}

// True Longitude 6-Instructor Reverse
// "SCANS" COMMANDS LONGITUDINALLY ACROSS
  void mp_TL6IR(int ax[], int axSz, int instructionx[], int dlyTime, int increment)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instructionx[], // instruction array
//  int dlyTime, interval between successive instructions
//  int increment) // distance between instructions 1-3 and 4-6
  {
  int pos1 = 100;
  int pos2 = 100;
  int pos3 = 100;
  int pos4 = 100;
  int axisSz = 0;  
  for (int i=0; i<(7 + increment); i++) {
    if (i <= 6) {
      switch(i) {
        case 6: {
          pos1 = mp_arrayCrawler(ax, axSz, 1);
          pos2 = mp_arrayCrawler(ax, axSz, 4);
          int axis1[] = {pos1, pos2};
          axisSz = (sizeof(axis1) / sizeof(int));
          mp_TL6IOperator1 (ax, axis1, axisSz, instructionx, dlyTime); }
          break;
        case 5: {
          pos1 = mp_arrayCrawler(ax, axSz, 2);
          pos2 = mp_arrayCrawler(ax, axSz, 3);
          pos3 = mp_arrayCrawler(ax, axSz, 6);
          pos4 = mp_arrayCrawler(ax, axSz, 5);
          int axis2[] = {pos1, pos2, pos3, pos4};
          axisSz = (sizeof(axis2) / sizeof(int));
          mp_TL6IOperator1 (ax, axis2, axisSz, instructionx, dlyTime); }
          break;
        case 4: {
          pos1 = mp_arrayCrawler(ax, axSz, 10);
          pos2 = mp_arrayCrawler(ax, axSz, 11);
          pos3 = mp_arrayCrawler(ax, axSz, 14);
          pos4 = mp_arrayCrawler(ax, axSz, 13);
          int axis3[] = {pos1, pos2, pos3, pos4};
          axisSz = (sizeof(axis3) / sizeof(int));
          mp_TL6IOperator1 (ax, axis3, axisSz, instructionx, dlyTime); }
        case 3: {
          pos1 = mp_arrayCrawler(ax, axSz, 12);
          pos2 = mp_arrayCrawler(ax, axSz, 15);
          int axis4[] = {pos1, pos2};
          axisSz = (sizeof(axis4) / sizeof(int));
          mp_TL6IOperator1 (ax, axis4, axisSz, instructionx, dlyTime); }
          break;
        case 2: {
          pos1 = mp_arrayCrawler(ax, axSz, 7);
          pos2 = mp_arrayCrawler(ax, axSz, 17);
          int axis5[] = {pos1, pos2};
          axisSz = (sizeof(axis5) / sizeof(int));
          mp_TL6IOperator1 (ax, axis5, axisSz, instructionx, dlyTime); }
          break;
        case 1: {
          pos1 = mp_arrayCrawler(ax, axSz, 8);
          pos2 = mp_arrayCrawler(ax, axSz, 9);
          pos3 = mp_arrayCrawler(ax, axSz, 18);
          int axis6[] = {pos1, pos2, pos3};
          axisSz = (sizeof(axis6) / sizeof(int));
          mp_TL6IOperator1 (ax, axis6, axisSz, instructionx, dlyTime); }
          break;
        case 0: {
          pos1 = mp_arrayCrawler(ax, axSz, 16);
          int axis7[] = {pos1};
          axisSz = (sizeof(axis7) / sizeof(int));
          mp_TL6IOperator1 (ax, axis7, axisSz, instructionx, dlyTime); }
          break;
        }
      }
    if ((i - increment + 1) >= 0) {
      int l = (i - increment);
      switch (l) {
        case 6: {
          pos1 = mp_arrayCrawler(ax, axSz, 1);
          pos2 = mp_arrayCrawler(ax, axSz, 4);
          int axis1[] = {pos1, pos2};
          axisSz = (sizeof(axis1) / sizeof(int));
          mp_TL6IOperator2 (ax, axis1, axisSz, instructionx, dlyTime); }
          break;
        case 5: {
          pos1 = mp_arrayCrawler(ax, axSz, 2);
          pos2 = mp_arrayCrawler(ax, axSz, 3);
          pos3 = mp_arrayCrawler(ax, axSz, 6);
          pos4 = mp_arrayCrawler(ax, axSz, 5);
          int axis2[] = {pos1, pos2, pos3, pos4};
          axisSz = (sizeof(axis2) / sizeof(int));
          mp_TL6IOperator2 (ax, axis2, axisSz, instructionx, dlyTime); }
          break;
        case 4: {
          pos1 = mp_arrayCrawler(ax, axSz, 10);
          pos2 = mp_arrayCrawler(ax, axSz, 11);
          pos3 = mp_arrayCrawler(ax, axSz, 14);
          pos4 = mp_arrayCrawler(ax, axSz, 13);
          int axis3[] = {pos1, pos2, pos3, pos4};
          axisSz = (sizeof(axis3) / sizeof(int));
          mp_TL6IOperator2 (ax, axis3, axisSz, instructionx, dlyTime); }
        case 3: {
          pos1 = mp_arrayCrawler(ax, axSz, 12);
          pos2 = mp_arrayCrawler(ax, axSz, 15);
          int axis4[] = {pos1, pos2};
          axisSz = (sizeof(axis4) / sizeof(int));
          mp_TL6IOperator2 (ax, axis4, axisSz, instructionx, dlyTime); }
          break;
        case 2: {
          pos1 = mp_arrayCrawler(ax, axSz, 7);
          pos2 = mp_arrayCrawler(ax, axSz, 17);
          int axis5[] = {pos1, pos2};
          axisSz = (sizeof(axis5) / sizeof(int));
          mp_TL6IOperator2 (ax, axis5, axisSz, instructionx, dlyTime); }
          break;
        case 1: {
          pos1 = mp_arrayCrawler(ax, axSz, 8);
          pos2 = mp_arrayCrawler(ax, axSz, 9);
          pos3 = mp_arrayCrawler(ax, axSz, 18);
          int axis6[] = {pos1, pos2, pos3};
          axisSz = (sizeof(axis6) / sizeof(int));
          mp_TL6IOperator2 (ax, axis6, axisSz, instructionx, dlyTime); }
          break;
        case 0: {
          pos1 = mp_arrayCrawler(ax, axSz, 16);
          int axis7[] = {pos1};
          axisSz = (sizeof(axis7) / sizeof(int));
          mp_TL6IOperator2 (ax, axis7, axisSz, instructionx, dlyTime); }
          break;
        }
     }
  }
}
  // "ON" or "OFF"
    void mp_TL6IOperator1 (int ax[], int axis[], int axisSz, int instructionx[], int dlyTime) {
      for (int x=0; x<3; x++) {
        for (int y=0; y<axisSz; y++){
          if (axis[y] != 100) {
            int pos = axis[y];
              mp_wireTransmitter(ax[pos], instructionx[x]);
              delay (dlyTime); }
          }
        }
      }
  // "OFF" or "ON"
    void mp_TL6IOperator2 (int ax[], int axis[], int axisSz, int instructionx[], int dlyTime) {
      for (int x=0; x<3; x++) {
        for (int y=0; y<axisSz; y++){
          if (axis[y] != 100) {
            int pos = axis[y];
              mp_wireTransmitter(ax[pos], instructionx[(x+3)]);
              delay (dlyTime); }
          }
        }
      }    


// - - - - - - - - - - - - - - FWD/BKWD INSTRUCTORS - ||
// Forwards-Backwards 1-Instructor
// GOOD FOR SINGLE INSTRUCTION CONVERGING ON MIDDLE
  void mp_FB1I(int ax[], int axSz, int instruction, int dlyTime, float stagger)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instruction, 
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
    int halfArray;
    if (axSz % 2 == 0) {
      halfArray = axSz / 2; }
    if (axSz % 2 != 0) {
      halfArray = ((axSz / 2) + 1); }
    for (int i=0; i<halfArray; i++) {
      mp_wireTransmitter (ax[i], instruction);
      mp_wireTransmitter (ax[(axSz - i)], instruction);
      delay (dlyTime); }
  }
  
// Forwards-Backwards 6-Instructor
// GOOD FOR LONGITUDINAL CROSSFADE ACROSS SHIP
  void mp_FB6I(int ax[], int axSz, int instructionx[], int dlyTime, float stagger)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instructionx[], // array of 6 instructions 
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
    int halfArray;
    if (axSz % 2 == 0) {
      halfArray = axSz / 2; }
    if (axSz % 2 != 0) {
      halfArray = ((axSz / 2) + 1); }
      
    for (int i=0; i<halfArray; i++) {
      for (int x=0; x<3; x++) {
        switch (x) {
          case 0:
            mp_wireTransmitter (ax[i], instructionx[1]);
            delay (dlyTime/10);
            mp_wireTransmitter (ax[(18 - i)], instructionx[3]);
            break;
          case 1:
            mp_wireTransmitter (ax[i], instructionx[2]);
            delay (dlyTime/10);
            mp_wireTransmitter (ax[(18-i)], instructionx[2]);
            break;
          case 2:
            mp_wireTransmitter (ax[i], instructionx[3]);
            delay (dlyTime/10);
            mp_wireTransmitter (ax[(18-i)], instructionx[1]);
            break;
          }
        delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1)); }}
    
    for (int i=halfArray; i<axSz; i++) {
      for (int x=0; x<3; x++) {
        switch (x) {
          case 0:
            mp_wireTransmitter (ax[i], instructionx[4]);
            delay (dlyTime/10);
            mp_wireTransmitter (ax[(18 - i)], instructionx[6]);
            break;
          case 1:
            mp_wireTransmitter (ax[i], instructionx[5]);
            delay (dlyTime/10);
            mp_wireTransmitter (ax[(18-i)], instructionx[5]);
            break;
          case 2:
            mp_wireTransmitter (ax[i], instructionx[6]);
            delay (dlyTime/10);
            mp_wireTransmitter (ax[(18-i)], instructionx[4]);
            break;
          }
        delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1)); }}
  }

// - - - - - - - - - - - - - - REGION INSTRUCTORS - ||
// Region 1-Instructor
// GOOD FOR DISTRIBUTING SINGLE INSTRUCTION AT SINGLE REGION
  void mp_region1I(int region, int regionSize, int instruction, int dlyTime, float stagger)
//  (int region,
//  int regionSize,
//  int instruction,
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
  // find region within allVWrap array
    int wantedVal = region;
    int wantedPos = 0;
    int x = 0;
    for (int i=0; i<18; i++) {
     if (wantedVal == vWR[i]) {
       wantedPos = i;
       break;
      }
    }
  // assign mins and maxes
  int regionMax;
  int regionMin;
  if ((regionSize % 2) == 0) {
    regionMin = constrain ((wantedPos - (regionSize) + (regionSize/2)), 0, 18);
    regionMax = constrain ((wantedPos + (regionSize/2) + 1), 0, 18); }
  if ((regionSize % 2) != 0) {
    regionMin = constrain ((wantedPos - ((regionSize + 1)/2)), 0, 18);
    regionMax = constrain ((wantedPos + ((regionSize + 1)/2)), 0, 18); }
  // write to region      
  if (regionSize == 1) {
      mp_wireTransmitter (vWR[wantedPos], instruction); }
  if (regionSize > 1) {
    for (int i=wantedPos; i < regionMax && i > regionMin; i = (i + x)) {
      mp_wireTransmitter (vWR[i], instruction);
      delay (jo_rand((dlyTime/stagger), (dlyTime*stagger), 1));
    // increment    
      x = abs(x) + 1;
      if (x%2 == 0) (x = -(x));
      }
    }
  }

  // Region Array-Instructor
  // GOOD FOR DISTRIBUTING RANDOM INSTRUCTIONS FROM WITHIN AN ARRAY WITHIN A REGION
  void mp_regionAI(int region, int regionSize, int instructionx[], int instructionASz, int dlyTime, float stagger)
//  (int region,
//  int regionSize,
//  int instructionx[],
//  int instructionASz,
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
  // find region within allVWrap array
    int wantedVal = region;
    int wantedPos = 0;
    int x = 0;
    for (int i=0; i<18; i++) {
     if (wantedVal == vWR[i]) {
       wantedPos = i;
       break;
      }
    }
  // assign mins and maxes
  int regionMax;
  int regionMin;
  if ((regionSize % 2) == 0) {
    regionMin = constrain ((wantedPos - (regionSize) + (regionSize/2)), 0, 18);
    regionMax = constrain ((wantedPos + (regionSize/2) + 1), 0, 18); }
  if ((regionSize % 2) != 0) {
    regionMin = constrain ((wantedPos - ((regionSize + 1)/2)), 0, 18);
    regionMax = constrain ((wantedPos + ((regionSize + 1)/2)), 0, 18); }
  // write to region
  for (int i=wantedPos; i < regionMax && i > regionMin; i = (i + x)) {
    int instruction = instructionx[(jo_rand (0, instructionASz, 1))];
    mp_wireTransmitter (vWR[i], instruction);
    delay (jo_rand((dlyTime/stagger), (dlyTime*stagger), 1));
  // increment    
    x = abs(x) + 1;
    if (x%2 == 0) (x = -(x));
    }
  }

// - - - - - - - - - - - - - - FUNCTION ALTERNATOR- ||
void mp_fcnAlt(int region1, int region1Sz, int region2, int region2Sz, int instruction1, int instruction2, int dlyTime, float stagger)
//  LIKE A "BLOCK BLOCKER" BUT WITH ARRAYS 
//  (int region1 // starting point of first array
//  int region1Sz // how big is first array
//  int region2 // starting point of second array
//  int region2Sz // how big is second array
//  int instruction1,
//  int instruction2,
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
    static unsigned long altCounter;
    
    if (fcnAltInit == true) {
    unsigned long now = millis();
    altCounter = now;
    fcnAltInit = false; }

    switch (altAssigner1) {
      case true: 
        if (millis() > altCounter) {
          mp_region1I(region1, region1Sz, instruction1, 1, 1);
          mp_region1I(region2, region2Sz, instruction2, 1, 1);          
  // reset variables  
          int actualDly = jo_rand((dlyTime/stagger), (dlyTime*stagger), 1);
          altCounter = millis() + actualDly;
          altAssigner1 = false; }
       break;
       case false:
        if (millis() > altCounter) {
          mp_region1I(region2, region2Sz, instruction1, 1, 1);
          mp_region1I(region1, region1Sz, instruction2, 1, 1);          
  // reset variables
          int actualDly = jo_rand((dlyTime/stagger), (dlyTime*stagger), 1);
          altCounter = millis() + actualDly;
          altAssigner1 = true; }
          break;
    }
  }

void mp_fcnLigeti(int region1, int region1Sz, int region2, int region2Sz, int instruction1, int instruction2, int tempo, int ratio1, int ratio2)
//  LIKE A LIGETI BUT WITH ARRAYS
//  (int region1 // starting point of first array
//  int region1Sz // how big is first array
//  int region2 // starting point of second array
//  int region2Sz // how big is second array
//  int instruction1,
//  int instruction2,
//  int tempo, // interval between successive instructions
//  int ratio1, // rate of a0 writes to
//  int ratio2) // rate of a1 writes
  {
    
  static unsigned long altCounter1;
  static unsigned long altCounter2;
  
  if (fcnLigetiInit == true) {
    unsigned long now = millis();
    altCounter1 = now;
    altCounter2 = now;
    fcnLigetiInit = false;   
  }       
    switch (ligetiCounter1) {
      case true:
        if (millis() > altCounter1) {
          mp_region1I(region1, region1Sz, instruction1, 1, 1);
          int dlyTime = (60000/tempo) * ratio1;
          ligetiCounter1 = false;
          altCounter1 = millis() + dlyTime; }
      break;      
      case false:
        if (millis() > altCounter1) {
          mp_region1I(region1, region1Sz, instruction2, 1, 1);
          int dlyTime = (60000/tempo) * ratio1;
          ligetiCounter1 = true;
          altCounter1 = millis() + dlyTime; }
      break;
    }
    switch (ligetiCounter2) {
      case true:
        if (millis() > altCounter2) {
          mp_region1I(region2, region2Sz, instruction1, 1, 1);
          int dlyTime = (60000/tempo) * ratio2;
          ligetiCounter2 = false;
          altCounter2 = millis() + dlyTime; }
      break;      
      case false:
        if (millis() > altCounter2) {
          mp_region1I(region2, region2Sz, instruction2, 1, 1);
          int dlyTime = (60000/tempo) * ratio2;
          ligetiCounter2 = true;
          altCounter2 = millis() + dlyTime; }
      break;
    }
  }

void mp_fcnLigeti2(int region1, int region1Sz, int region2, int region2Sz, int instruction1, int instruction2, int tempo, int ratio1, int ratio2)
//  LIKE A LIGETI BUT WITH ARRAYS
//  (int region1 // starting point of first array
//  int region1Sz // how big is first array
//  int region2 // starting point of second array
//  int region2Sz // how big is second array
//  int instruction1,
//  int instruction2,
//  int tempo, // interval between successive instructions
//  int ratio1, // rate of a0 writes to
//  int ratio2) // rate of a1 writes
  {
  static unsigned long altCounter21;
  static unsigned long altCounter22;
  
  if (fcnLigetiInit2 == true) {
    unsigned long now = millis();
    altCounter21 = now;
    altCounter22 = now;
    fcnLigetiInit2 = false;   
  }    
    switch (ligetiCounter21) {
      case true:
        if (millis() > altCounter21) {
          mp_region1I(region1, region1Sz, instruction1, 1, 1);
          int dlyTime = (60000/tempo) * ratio1;
          ligetiCounter21 = false;
          altCounter21 = millis() + dlyTime; }
      break;      
      case false:
        if (millis() > altCounter21) {
          mp_region1I(region1, region1Sz, instruction2, 1, 1);
          int dlyTime = (60000/tempo) * ratio1;
          ligetiCounter21 = true;
          altCounter21 = millis() + dlyTime; }
      break;
    }
    switch (ligetiCounter22) {
      case true:
        if (millis() > altCounter22) {
          mp_region1I(region2, region2Sz, instruction1, 1, 1);
          int dlyTime = (60000/tempo) * ratio2;
          ligetiCounter22 = false;
          altCounter22 = millis() + dlyTime; }
      break;      
      case false:
        if (millis() > altCounter22) {
          mp_region1I(region2, region2Sz, instruction2, 1, 1);
          int dlyTime = (60000/tempo) * ratio2;
          ligetiCounter22 = true;
          altCounter22 = millis() + dlyTime; }
      break;
    }
  }



void mp_grandLigeti(int howManyDivisions, int instructionx1[], int instructionx1Sz, int instructionx2[], int instructionx2Sz, int tempo, int multiple) 
//  GIANT MILLIS METRONOME
//  (int howManyDivisions // 2, 4, or 8
//  int instructionx1[],
//  int instructionx1Sz,
//  int instructionx2[],
//  int instructionx2Sz,
//  int tempo, // interval between successive instructions
//  int multiple) if you use high tempo, use high multiple to stagger entrances more randomly
  {
  static unsigned long grandLigetiTimerH1;
  static unsigned long grandLigetiTimerH2;
  static unsigned long grandLigetiTimerQ1;
  static unsigned long grandLigetiTimerQ2;
  static unsigned long grandLigetiTimerQ3;
  static unsigned long grandLigetiTimerQ4;
  static unsigned long grandLigetiTimerE1;
  static unsigned long grandLigetiTimerE2;
  static unsigned long grandLigetiTimerE3;
  static unsigned long grandLigetiTimerE4;
  static unsigned long grandLigetiTimerE5;
  static unsigned long grandLigetiTimerE6;
  static unsigned long grandLigetiTimerE7;
if (gLigetiInit == true) {
  unsigned long now = millis();
  grandLigetiTimerH1 = now;
  grandLigetiTimerH2 = now;
  grandLigetiTimerQ1 = now;
  grandLigetiTimerQ2 = now;
  grandLigetiTimerQ3 = now;
  grandLigetiTimerQ4 = now;
  grandLigetiTimerE1 = now;
  grandLigetiTimerE2 = now;
  grandLigetiTimerE3 = now;
  grandLigetiTimerE4 = now;
  grandLigetiTimerE5 = now;
  grandLigetiTimerE6 = now;
  grandLigetiTimerE7 = now; 
  gLigetiInit = false;         
}
switch (howManyDivisions) {
  case 2: {
    int halfDiv1[] = {1, 4, 2, 5, 3, 6, 10, 13};
    int halfDiv2[] = {11, 14, 12, 15, 7, 17, 8, 18, 16};
    int instruction1 = instructionx1[(jo_rand(0, (instructionx1Sz), 1))];
    int instruction2 = instructionx2[(jo_rand(0, (instructionx2Sz), 1))];

    switch (grandLigetiCounterH1) {
      case true:
        if (millis() > (grandLigetiTimerH1 + ((60000/tempo) * multiple))) {
          mp_fastWireTransmitter(halfDiv1, 8, instruction1);
          grandLigetiCounterH1 = false;
          grandLigetiTimerH1 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerH1 + ((60000/tempo) * multiple))) {
          mp_fastWireTransmitter(halfDiv1, 8, instruction2);
          grandLigetiCounterH1 = true;
          grandLigetiTimerH1 = millis(); }
      break;      
      }

    switch (grandLigetiCounterH2) {
      case true:
        if (millis() > (grandLigetiTimerH2 + ((60000/tempo) * (multiple + 1)))) {
          mp_fastWireTransmitter(halfDiv2, 8, instruction1);
          grandLigetiCounterH2 = false;
          grandLigetiTimerH2 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerH2 + ((60000/tempo) * (multiple + 1)))) {
          mp_fastWireTransmitter(halfDiv2, 8, instruction2);
          grandLigetiCounterH2 = true;
          grandLigetiTimerH2 = millis(); }
      break;      
      }
    }
    break;

  case 4: {
    int quarterDiv1[] = {1, 2, 3, 10, 11};
    int quarterDiv2[] = {12, 15, 7, 8, 9, 16};
    int quarterDiv3[] = {18, 17, 14, 13};
    int quarterDiv4[] = {6, 5, 4};
    int instruction1 = instructionx1[(jo_rand(0, instructionx1Sz, 1))];
    int instruction2 = instructionx2[(jo_rand(0, instructionx2Sz, 1))];

    switch (grandLigetiCounterQ1) {
      case true:
        if (millis() > (grandLigetiTimerQ1 + ((60000/tempo) * multiple))) {
          mp_fastWireTransmitter(quarterDiv1, 5, instruction1);
          grandLigetiCounterQ1 = false;
          grandLigetiTimerQ1 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerQ1 + ((60000/tempo) * multiple))) {
          mp_fastWireTransmitter(quarterDiv1, 5, instruction2);
          grandLigetiCounterQ1 = true;
          grandLigetiTimerQ1 = millis(); }
      break;      
      }

    switch (grandLigetiCounterQ2) {
      case true:
        if (millis() > (grandLigetiTimerQ2 + ((60000/tempo) * (multiple + 1)))) {
          mp_fastWireTransmitter(quarterDiv2, 6, instruction1);
          grandLigetiCounterQ2 = false;
          grandLigetiTimerQ2 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerQ2 + ((60000/tempo) * (multiple + 1)))) {
          mp_fastWireTransmitter(quarterDiv2, 6, instruction2);
          grandLigetiCounterQ2 = true;
          grandLigetiTimerQ2 = millis(); }
      break;      
      } 

    switch (grandLigetiCounterQ3) {
      case true:
        if (millis() > (grandLigetiTimerQ3 + ((60000/tempo) * (multiple + 2)))) {
          mp_fastWireTransmitter(quarterDiv3, 4, instruction1);
          grandLigetiCounterQ3 = false;
          grandLigetiTimerQ3 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerQ3 + ((60000/tempo) * (multiple + 2)))) {
          mp_fastWireTransmitter(quarterDiv3, 4, instruction2);
          grandLigetiCounterQ3 = true;
          grandLigetiTimerQ3 = millis(); }
      break;      
      }

    switch (grandLigetiCounterQ4) {
      case true:
        if (millis() > (grandLigetiTimerQ4 + ((60000/tempo) * (multiple + 3)))) {
          mp_fastWireTransmitter(quarterDiv4, 3, instruction1);
          grandLigetiCounterQ4 = false;
          grandLigetiTimerQ4 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerQ4 + ((60000/tempo) * (multiple + 3)))) {
          mp_fastWireTransmitter(quarterDiv4, 3, instruction2);
          grandLigetiCounterQ4 = true;
          grandLigetiTimerQ4 = millis(); }
      break;      
      }
    }
    break;

  case 8: {
    int eigthDiv1[] = {6, 5, 4};
    int eigthDiv2[] = {7, 8, 9};
    int eigthDiv3[] = {15, 16};
    int eigthDiv4[] = {10, 11, 12};
    int eigthDiv5[] = {18, 17};
    int eigthDiv6[] = {1, 2, 3};
    int eigthDiv7[] = {7, 8, 9};    
    int instruction1 = instructionx1[(jo_rand(0, instructionx1Sz, 1))];
    int instruction2 = instructionx2[(jo_rand(0, instructionx2Sz, 1))];

    switch (grandLigetiCounterE1) {
      case true:
        if (millis() > (grandLigetiTimerE1 + ((60000/tempo) * multiple))) {
          mp_fastWireTransmitter(eigthDiv1, 3, instruction1);
          grandLigetiCounterE1 = false;
          grandLigetiTimerE1 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerE1 + ((60000/tempo) * multiple))) {
          mp_fastWireTransmitter(eigthDiv1, 3, instruction2);
          grandLigetiCounterE1 = true;
          grandLigetiTimerE1 = millis(); }
      break;      
      }

    switch (grandLigetiCounterE2) {
      case true:
        if (millis() > (grandLigetiTimerE2 + ((60000/tempo) * (multiple + 1)))) {
          mp_fastWireTransmitter(eigthDiv2, 3, instruction1);
          grandLigetiCounterE2 = false;
          grandLigetiTimerE2 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerE2 + ((60000/tempo) * (multiple + 1)))) {
          mp_fastWireTransmitter(eigthDiv2, 3, instruction2);
          grandLigetiCounterE2 = true;
          grandLigetiTimerE2 = millis(); }
      break;      
      } 

    switch (grandLigetiCounterE3) {
      case true:
        if (millis() > (grandLigetiTimerE3 + ((60000/tempo) * (multiple + 2)))) {
          mp_fastWireTransmitter(eigthDiv3, 2, instruction1);
          grandLigetiCounterE3 = false;
          grandLigetiTimerE3 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerE3 + ((60000/tempo) * (multiple + 2)))) {
          mp_fastWireTransmitter(eigthDiv3, 2, instruction2);
          grandLigetiCounterE3 = true;
          grandLigetiTimerE3 = millis(); }
      break;      
      }

    switch (grandLigetiCounterE4) {
      case true:
        if (millis() > (grandLigetiTimerE4 + ((60000/tempo) * (multiple + 3)))) {
          mp_fastWireTransmitter(eigthDiv4, 3, instruction1);
          grandLigetiCounterE4 = false;
          grandLigetiTimerE4 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerE4 + ((60000/tempo) * (multiple + 3)))) {
          mp_fastWireTransmitter(eigthDiv4, 3, instruction2);
          grandLigetiCounterE4 = true;
          grandLigetiTimerE4 = millis(); }
      break;      
      }

    switch (grandLigetiCounterE5) {
      case true:
        if (millis() > (grandLigetiTimerE5 + ((60000/tempo) * (multiple + 4)))) {
          mp_fastWireTransmitter(eigthDiv5, 2, instruction1);
          grandLigetiCounterE5 = false;
          grandLigetiTimerE5 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerE5 + ((60000/tempo) * (multiple + 4)))) {
          mp_fastWireTransmitter(eigthDiv5, 2, instruction2);
          grandLigetiCounterE5 = true;
          grandLigetiTimerE5 = millis(); }
      break;      
      }

    switch (grandLigetiCounterE6) {
      case true:
        if (millis() > (grandLigetiTimerE6 + ((60000/tempo) * (multiple + 5)))) {
          mp_fastWireTransmitter(eigthDiv6, 3, instruction1);
          grandLigetiCounterE6 = false;
          grandLigetiTimerE6 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerE6 + ((60000/tempo) * (multiple + 5)))) {
          mp_fastWireTransmitter(eigthDiv6, 3, instruction2);
          grandLigetiCounterE6 = true;
          grandLigetiTimerE6 = millis(); }
      break;      
      }

    switch (grandLigetiCounterE7) {
      case true:
        if (millis() > (grandLigetiTimerE7 + ((60000/tempo) * (multiple + 6)))) {
          mp_fastWireTransmitter(eigthDiv7, 3, instruction1);
          grandLigetiCounterE7 = false;
          grandLigetiTimerE7 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimerE7 + ((60000/tempo) * (multiple + 6)))) {
          mp_fastWireTransmitter(eigthDiv7, 3, instruction2);
          grandLigetiCounterE7 = true;
          grandLigetiTimerE7 = millis(); }
      break;      
      }
    break;
    }
  }
}


void mp_grandLigeti2(int instruction1, int instruction2, int tempo, int multiple) 
//  FOR TRANSDUCERS AND LEDS
//  (int instruction1,
//  int instruction2,
//  int tempo, // interval between successive instructions
//  int multiple) if you use high tempo, use high multiple to stagger entrances more randomly
  {
    
  static unsigned long grandLigetiTimer2T1;
  static unsigned long grandLigetiTimer2T2;
  static unsigned long grandLigetiTimer2T3;
  
if (gLigetiInit2 == true) {
  unsigned long now = millis();
  grandLigetiTimer2T1 = now;
  grandLigetiTimer2T2 = now;
  grandLigetiTimer2T3 = now;
  gLigetiInit2 = false;         
}

    switch (grandLigetiCounter2T1) {
      case true:
        if (millis() > (grandLigetiTimer2T1 + ((60000/tempo) * multiple))) {
          mp_wireTransmitter (19, instruction1);
          grandLigetiCounter2T1 = false;
          grandLigetiTimer2T1 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimer2T1 + ((60000/tempo) * multiple))) {
          mp_wireTransmitter (19, instruction2);
          grandLigetiCounter2T1 = true;
          grandLigetiTimer2T1 = millis(); }
      break;      
      }

    switch (grandLigetiCounter2T2) {
      case true:
        if (millis() > (grandLigetiTimer2T2 + ((60000/tempo) * multiple))) {
          mp_wireTransmitter (20, instruction1);
          grandLigetiCounter2T2 = false;
          grandLigetiTimer2T2 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimer2T2 + ((60000/tempo) * multiple))) {
          mp_wireTransmitter (20, instruction2);
          grandLigetiCounter2T2 = true;
          grandLigetiTimer2T2 = millis(); }
      break;      
      }


    switch (grandLigetiCounter2T3) {
      case true:
        if (millis() > (grandLigetiTimer2T3 + ((60000/tempo) * multiple))) {
          mp_wireTransmitter (21, instruction1);
          grandLigetiCounter2T3 = false;
          grandLigetiTimer2T3 = millis(); }
      break;     
      
      case false:
        if (millis() > (grandLigetiTimer2T3 + ((60000/tempo) * multiple))) {
          mp_wireTransmitter (21, instruction2);
          grandLigetiCounter2T3 = true;
          grandLigetiTimer2T3 = millis(); }
      break;      
      }
    }









 
// - - - - - - - - - - - - - - RANDOM INSTRUCTORS - ||
// Random 1-Instructor
// GOOD FOR DISTRIBUTING SINGLE COMMAND RANDOMLY ACROSS SHIP
  void mp_random1I(int axSH[], int axSHSz, int instruction, int dlyTime, float stagger)
//  (int axSH[], // array subject to distribution
//  int axSHSz, // size of array
//  int instruction, // instruction in question
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
    shuffleArray (axSH, axSHSz);
    for (int i=0; i< axSHSz; i++) {
          mp_wireTransmitter (axSH[i], instruction);
          delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1)); }
  }
  
// Random 2-Instructor
// GOOD FOR DISTRIBUTING COMMAND AND DEACTIVATING IT RANDOMLY ACROSS SHIP
  void mp_random2I(int axSH[], int axSHSz, int instruction1, int instruction2, int dlyTime, float stagger, int increment)
//  (int ax[], // array subject to distribution
//  int axSz, // size of array
//  int instruction1, 
//  int instruction2, 
//  int dlyTime, // interval between successive instructions
//  float stagger, // 1 for nonrandom
//  int increment) // distance between instruction 1 and instruction 2
  {
    shuffleArray (axSH, axSHSz);
    for (int i=0; i< (axSHSz + increment); i++) {
      if ((i - increment) >= 0) {
        mp_wireTransmitter (axSH[(i - increment)], instruction2); }
      if (i <= axSHSz) {   
        mp_wireTransmitter (axSH[i], instruction1);
        delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1)); }
      if (i > axSHSz) {
        mp_wireTransmitter (axSH[(i - increment)], instruction2);
        delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1)); }}
  }
  
// Sequential Array-Instructor
// GOOD FOR DISTRIBUTING RANDOM INSTRUCTIONS FROM WITHIN AN ARRAY RANDOMLY ACROSS SHIP
  void mp_randomAI(int axSH[], int axSHSz, int instructionx[], int instructionASz, int dlyTime, float stagger) 
//  (int axSh[], // array subject to distribution
//  int axSHSz, // size of array
//  int instructionx[], // instruction in question
//  int instructionASz,
//  int dlyTime, // interval between successive instructions
//  float stagger) // 1 for nonrandom
  {
    shuffleArray (axSH, axSHSz);
    for (int i=0; i< axSHSz; i++) {
      int instruction = instructionx[(jo_rand (0, instructionASz, 1))];
      mp_wireTransmitter (axSH[i], instruction);
      delay (jo_rand((dlyTime/stagger), ((dlyTime*stagger)+1), 1)); }
  }


// - - - - - - - - - - - UTILITY FUNCTIONS - - - - - - - - - - - - - - - - |
// - - - - - - - - - - - WIRE TRANSMITTER
void mp_wireTransmitter (int wireID, int wireVAL) {
  bool sp = true;
  if (asts[wireID] != wireVAL) {
    for (int i = 0; i < 10; i++) {
    Wire.beginTransmission (wireID);
    if (sp == true) {    
      Serial.print ("transmitting to operator:");
      Serial.println (wireID); }
    Wire.write(wireVAL);
    Wire.endTransmission();
    if (sp == true) {
      Serial.print ("the message:");
      Serial.println (wireVAL); }
    sp = false;
    delay(2);
    }
  asts[wireID] = wireVAL; 
  }
}

void mp_fastWireTransmitter (int ax[], int axSz, int wireVAL) {
  // WARNING: NOTE - DOES NOT CHECK if asts[wireID] = wireVAL
  bool sp = true;
  for (int i = 0; i < 10; i++) {
    for (int x = 0; x < axSz; x++) {
    Wire.beginTransmission (ax[x]);
    if (sp == true) {
      Serial.print ("transmitting to operator:");
      Serial.println (ax[x]);}
    Wire.write(wireVAL);
    Wire.endTransmission();
    if (sp == true) {
      Serial.print ("the message:");
      Serial.println (wireVAL); }}
    sp = false;
    delay(2); }
  for (int y = 0; y < axSz; y++) {
    asts[ax[y]] = wireVAL; }
  }

void mp_wireAdjuster (int ax[], int axSz, int prevInstruction, int instruction) {
  for (int i = 0; i < axSz; i++) {
    if (asts[ax[i]] == prevInstruction) {
      mp_wireTransmitter (ax[i], instruction); }}
}

void mp_wireArrayAdjuster (int ax[], int axSz, int prevInstructionx[], int prevInstructionxSz, int instruction) {
  for (int i = 0; i < axSz; i++) {
      for (int x = 0; x < prevInstructionxSz; x++) {
      if (asts[ax[i]] == prevInstructionx[x]) {
      mp_wireTransmitter (ax[i], instruction); }}}
}


// - - - - - - - - - - - SKEW RANDOMIZER
int jo_rand (int minIn, int maxIn, float skew) {
float seeder = random(0, 10000);
float randUnscl = (pow(seeder/10000, skew) * 100);
int randScl = map (randUnscl, 0, 100, minIn, maxIn);
return randScl;
}

// - - - - - - - - - - - SHUFFLER
void shuffleArray(int * array, int SIZE)
{
  int last = 0;
  int temp = array[last];
  for (int i = 0; i < SIZE; i++) {
    int index = random(SIZE);
    array[last] = array[index];
    last = index;
  }
  array[last] = temp;
}


// - - - - - - - - - - - ARRAY LOOKUP
int mp_arrayCrawler (int ax[], int axSz, int wantedVal) {
    int wantedPos = 100;
    for (int i=0; i<axSz; i++) {
       if (wantedVal == ax[i]) {
       wantedPos = i;
       break;
      }
    }
  return (wantedPos);
}

// - - - - - - - - - - - RESET
void mp_reset(int whichMin) {
mp_sequence2I (a, 21, 20, 2, 100, 1, 10);
allOn = false;
allOff = true;
AOn = false;
AOff = true;
BOn = false;
BOff = true;
altAssigner1 = true;
ligetiCounter1 = false; 
ligetiCounter2 = false;
ligetiCounter21 = false; 
ligetiCounter22 = false;
mInstructorAssigner = 0;
mInstructorAssigner2 = 0;
mInstructorReset = true;
mInstructorReset2 = true;
grandLigetiCounterH1 = true; 
grandLigetiCounterH2 = true; 
grandLigetiCounterQ1 = true; 
grandLigetiCounterQ2 = true; 
grandLigetiCounterQ3 = true; 
grandLigetiCounterQ4 = true; 
grandLigetiCounterE1 = true; 
grandLigetiCounterE2 = true; 
grandLigetiCounterE3 = true; 
grandLigetiCounterE4 = true; 
grandLigetiCounterE5 = true; 
grandLigetiCounterE6 = true; 
grandLigetiCounterE7 = true; 
grandLigetiCounter2T1 = true; 
grandLigetiCounter2T2 = true; 
grandLigetiCounter2T3 = true; 
mIStorageSZ = 0;
mIStorageSZ2 = 0;
mIStorageA1 = 0;
mIStorageA12 = 0;
fcnAltInit = true;
gLigetiInit = true;
gLigetiInit2 = true;
fcnLigetiInit = true;
fcnLigetiInit2 = true;
stopNow = false;
startTime = millis(); 
adjuster = (whichMin * 60000);
}
