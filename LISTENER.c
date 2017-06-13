#include <Wire.h>
int wireVAL = 0;
int cwireVAL = 0;
const int wireID = 17;
int instruction = 0;

// - - - - - - - - - - - VARIABLES ::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// - - - - - - - - - - -  AGENTS - - - - - - - - - - - - - - - - -|
// - - - - - - - - - - - - - UNO VERSION - - - - - - - - - - - - -|
// - - - - - - - - - - - COMMENT HERE
const int chr1 = 1;
const int chr2 = 2;
const int chr3 = 4;
const int chr4 = 7;
const int chr5 = 8;
const int chr6 = 12;
const int sol1 = 3;
const int sol2 = 5;
const int sol3 = 6;
const int sol4 = 9;
const int sol5 = 10;
const int sol6 = 11;
const int CHRINDEX = 6;
const int CHRHALFINDEX = 6;
const int SOLINDEX = 6;
const int SOLHALFINDEX = 6;
const int ALLINDEX = 12;
const int chr[] = {chr1, chr2, chr3, chr4, chr5, chr6};
int chrSH[] = {chr1, chr2, chr3, chr4, chr5, chr6};
const int chrH1[] = {chr1, chr2, chr3};
int chrH1SH[] = {chr1, chr2, chr3};
const int chrH2[] = {chr4, chr5, chr6};
int chrH2SH[] = {chr4, chr5, chr6};
const int sol[] = {sol1, sol2, sol3, sol4, sol5, sol6};
int solSH[] = {sol1, sol2, sol3, sol4, sol5, sol6};
int solSHFF[] = {sol1, sol2, sol3, sol4, sol5, sol6};
const int all[] = {chr1, chr2, chr3, chr4, chr5, chr6, sol1, sol2, sol3, sol4, sol5, sol6};
int allSH[] = {chr1, chr2, chr3, chr4, chr5, chr6, sol1, sol2, sol3, sol4, sol5, sol6};
// - - - - - - - - - - - END COMMENT HERE

// - - - - - - - - - - - - - MEGA VERSION - - - - - - - - - - - - -|
// - - - - - - - - - - - COMMENT HERE
//const int chr1 = 24;
//const int chr2 = 25;
//const int chr3 = 26;
//const int chr4 = 27;
//const int chr5 = 28;
//const int chr6 = 29;
//const int chr7 = 30;
//const int chr8 = 31;
//const int chr9 = 32;
//const int chr10 = 33;
//const int chr11 = 34;
//const int chr12 = 35;
//const int chr13 = 36;
//const int chr14 = 37;
//const int chr15 = 38;
//const int chr16 = 39;
//const int chr17 = 40;
//const int chr18 = 41;
//const int chr19 = 42;
//const int chr20 = 43;
//const int sol1 = 3;
//const int sol2 = 4;
//const int sol3 = 5;
//const int sol4 = 6;
//const int sol5 = 7;
//const int sol6 = 8;
//const int sol7 = 9;
//const int sol8 = 10;
//const int sol9 = 11;
//const int sol10 = 12;
//const int sol11 = 13;
//const int CHRINDEX = 20;
//const int CHRHALFINDEX = 10;
//const int SOLINDEX = 11;
//const int SOLHALFINDEX = 6;
//const int ALLINDEX = 31;
//const int chr[] = {chr1, chr2, chr3, chr4, chr5, chr6, chr7, chr8, chr9, chr10, chr11, chr12, chr13, chr14, chr15, chr16, chr17, chr18, chr19, chr20};
//int chrSH[] = {chr1, chr2, chr3, chr4, chr5, chr6, chr7, chr8, chr9, chr10, chr11, chr12, chr13, chr14, chr15, chr16, chr17, chr18, chr19, chr20};
//const int chrH1[] = {chr1, chr2, chr3, chr4, chr5, chr6, chr7, chr8, chr9, chr10};
//int chrH1SH[] = {chr1, chr2, chr3, chr4, chr5, chr6, chr7, chr8, chr9, chr10};
//const int chrH2[] = {chr11, chr12, chr13, chr14, chr15, chr16, chr17, chr18, chr19, chr20};
//int chrH2SH[] = {chr11, chr12, chr13, chr14, chr15, chr16, chr17, chr18, chr19, chr20};
//const int sol[] = {sol1, sol2, sol3, sol4, sol5, sol6, sol7, sol8, sol9, sol10, sol11};
//int solSH[] = {sol1, sol2, sol3, sol4, sol5, sol6, sol7, sol8, sol9, sol10, sol11};
//int solSHFF[] = {sol1, sol2, sol3, sol4, sol5, sol6, sol7, sol8, sol9, sol10, sol11};
//const int all[] = {chr1, chr2, chr3, chr4, chr5, chr6, chr7, chr8, chr9, chr10, chr11, chr12, chr13, chr14, chr15, chr16, chr17, chr18, chr19, chr20, sol1, sol2, sol3, sol4, sol5, sol6, sol7, sol8, sol9, sol10, sol11};
//int allSH[] = {chr1, chr2, chr3, chr4, chr5, chr6, chr7, chr8, chr9, chr10, chr11, chr12, chr13, chr14, chr15, chr16, chr17, chr18, chr19, chr20, sol1, sol2, sol3, sol4, sol5, sol6, sol7, sol8, sol9, sol10, sol11};
// - - - - - - - - - - - END COMMENT HERE

// - - - - - - - - - - - FOR FUNCTIONS
bool ctrPtrU0 = false;
bool ctrPtrU1 = false;
bool ctrPtrUOp = false;
bool rampMeIn = true;
int ctrPtrCtr = 1;
int metronome = 0;
int PWMval = 0;
int truDensity;
int tempo;
int tempoRegistration = 0;
int beatNo = 0;
bool chrOn = false;
bool solOn = false;
bool long1On = false;
bool long2On = false;
bool long3On = false;
bool fadeIn = false;
bool chrFlttrStatus = false;
bool solFlttrStatus = false;
bool musicMakerInitiator = true;
bool musicMaker1Status = false;
bool musicMaker2Status = false;
bool metronomeStatus = false;
long chrFlttrTimeInt = 0;
long solFlttrTimeInt = 0;
long ctrPtrTimeInt = 0;
long metronomeTimeInt = 0;
long musicMakerTimeInt = 0;


// - - - - - - - - - - - SETUP AND LOOP :::::::::::::::::::::::::::::::::::::::::::::::::::
void setup() {
  for (int p = 0; p < ALLINDEX; p++) {
    pinMode (all[p], OUTPUT); } 
randomSeed(2);
Wire.begin(wireID);
Wire.onReceive(receiveEvent);
Serial.begin(9600);
}


// - - - - - - - - - - - SWITCH MACHINE AND INTERRUPT
void receiveEvent() {
  while (0 < Wire.available()) {
  wireVAL = Wire.read();
  Serial.println (wireVAL); }}

// - - - - - GENERIC FUNCTION TESTER
// COMMENT FROM HERE;
void loop() {
  delay(1);

switch (wireVAL) {

// - - - - - - - - - - - REST
case 1:{
//void mp_rest() {
  delay(10);
}
break;

case 2: {
//void mp_reset() {
  mp_allOff(10,1,false);
  ctrPtrU0 = false;
  ctrPtrU1 = false;
  ctrPtrUOp = false;
  rampMeIn = true;
  ctrPtrCtr = 1;
  metronome = 0;
  PWMval = 0;
  tempoRegistration = 0;
  beatNo = 0;
  chrOn = false;
  solOn = false;
  long1On = false;
  long2On = false;
  long3On = false;
  chrFlttrStatus = false; 
  solFlttrStatus = false;
  musicMakerInitiator = true;
  musicMaker1Status = false;
  musicMaker2Status = false;
  metronomeStatus = false;
  chrFlttrTimeInt = 0;
  solFlttrTimeInt = 0;
  ctrPtrTimeInt = 0;
  metronomeTimeInt = 0;
  musicMakerTimeInt = 0;
  while (wireVAL == 2) mp_rest();
}


// - - - - - - - - - - - 010-029 ALLON/ALLOF
// 010 // 310ms
case 10: {
// void mf_allOnFAST(){
  if (chrOn == false || solOn == false) mp_allOn(10,1,false);
  instruction = wireVAL;
}
break;

case 11: {
// 011 // 3,100ms
//void mf_allOnMID(){
  if (chrOn == false || solOn == false) mp_allOn(100,1,false);
  instruction = wireVAL;
}
break;

case 12: {
// 012 // 3,100ms
//void mf_allOnMID_R(){
  if (chrOn == false || solOn == false) mp_allOn(100,1,true);
  instruction = wireVAL;
}
break;

case 13: {
// 013 // 3,100ms
//void mf_allOnMID_RR(){
  if (chrOn == false || solOn == false) mp_allOn(100,2,true);
  instruction = wireVAL;
}
break;

case 14: {
// 014 // 9,300ms
//void mf_allOnSLO(){
  if (chrOn == false || solOn == false) mp_allOn(300,1,false);
  instruction = wireVAL;
}
break;

case 15: {
// 015 // 9,300ms
//void mf_allOnSLO_R(){
  if (chrOn == false || solOn == false) mp_allOn(300,1,true);
  instruction = wireVAL;
}
break; 

// 016 // 9,300ms
case 16: {
//void mf_allOnSLO_RR(){  
  if (chrOn == false || solOn == false) mp_allOn(300,2,true);
  instruction = wireVAL;
}
break;

case 17: {
// 017 // 27,900ms
//void mf_allOnVSLO(){
  if (chrOn == false || solOn == false) mp_allOn(1100,1,false);
  instruction = wireVAL;
}
break;

case 18: {
// 018 // 27,900ms
//void mf_allOnVSLO_R(){
  if (chrOn == false || solOn == false) mp_allOn(2200,1,true);
  instruction = wireVAL;
}
break;

case 19: {
// 019 // 27,900ms
//void mf_allOnVSLO_RR(){  
  if (chrOn == false || solOn == false) mp_allOn(2200,2,true);
  instruction = wireVAL;
}
break;

case 20: {
// 020 // 310ms
//void mf_allOffFAST(){
  if (chrOn == true || solOn == true) mp_allOff(10,1,false);
  instruction = wireVAL;
}
break;

case 21: {
// 021 // 3,100ms
//void mf_allOffMID(){
  if (chrOn == true || solOn == true) mp_allOff(100,1,false);
  instruction = wireVAL;
}
break;

case 22: {
// 022 // 3,100ms
//void mf_allOffMID_R(){
  if (chrOn == true || solOn == true) mp_allOff(100,1,true);
  instruction = wireVAL;
}
break;

case 23: {
// 023 // 3,100ms
//void mf_allOffMID_RR(){
  if (chrOn == true || solOn == true) mp_allOff(100,2,true);
  instruction = wireVAL;
}
break;

case 24: {
// 024 // 9,300ms
//void mf_allOffSLO(){
  if (chrOn == true || solOn == true) mp_allOff(300,1,false);
  instruction = wireVAL;
}
break;

case 25: {
// 025 // 9,300ms
//void mf_allOffSLO_R(){
  if (chrOn == true || solOn == true) mp_allOff(300,1,true);
  instruction = wireVAL;
}
break;

case 26: {
// 026 // 9,300ms
//void mf_allOffSLO_RR(){  
  if (chrOn == true || solOn == true) mp_allOff(300,2,true);
  instruction = wireVAL;
}
break;

case 27: {
// 027 // 27,900ms
//void mf_allOffVSLO(){
  if (chrOn == true || solOn == true) mp_allOff(1100,1,false);
  instruction = wireVAL;
}
break;

case 28: {
// 028 // 27,900ms
//void mf_allOffVSLO_R(){
  if(chrOn == true || solOn == true) mp_allOff(2200,1,true);
  instruction = wireVAL;
}
break;

case 29: {
// 029 // 27,900ms
//void mf_allOffVSLO_RR(){  
  if(chrOn == true || solOn == true) mp_allOff(2200,2,true);
  instruction = wireVAL;
}
break;


// - - - - - - - - - - - 030-049 CHRON/CHROFF
case 30: {
// 030 // 200ms
//void mf_chrOnFAST(){
  if(chrOn == false) mp_chrOn(10,1,false);
  instruction = wireVAL;
}
break;

case 31: {
// 031 // 2,000ms
//void mf_chrOnMID(){
  if (chrOn == false) mp_chrOn(100,1,false);
  instruction = wireVAL;
}
break;

case 32: {
// 032 // 2,000ms
//void mf_chrOnMID_R(){
  if (chrOn == false) mp_chrOn(100,1,true);
  instruction = wireVAL;
}
break;

case 33: {
// 033 // 2,000ms
//void mf_chrOnMID_RR(){
  if (chrOn == false) mp_chrOn(100,2,true);
  instruction = wireVAL;
}
break;

case 34: {
// 034 // 3,600ms 
//void mf_chrOnSLO(){
  if (chrOn == false) mp_chrOn(180,1,false);
  instruction = wireVAL;
}
break;

case 35: {
// 035 // 3,600ms 
//void mf_chrOnSLO_R(){
  if (chrOn == false) mp_chrOn(180,1,true);
  instruction = wireVAL;
}
break;

case 36: {
// 036 // 3,600ms 
//void mf_chrOnSLO_RR(){  
  if (chrOn == false) mp_chrOn(180,2,true);
  instruction = wireVAL;
}
break;

case 37: {
// 037 // 7,200ms
//void mf_chrOnVSLO(){
  if (chrOn == false) mp_chrOn(360,1,false);
  instruction = wireVAL;
}
break;

case 38: {
// 038 // 7,200ms
//void mf_chrOnVSLO_R(){
  if (chrOn == false) mp_chrOn(360,1,true);
  instruction = wireVAL;
}
break;

case 39: {
// 039 // 7,200ms
//void mf_chrOnVSLO_RR(){  
  if (chrOn == false) mp_chrOn(360,2,true);
  instruction = wireVAL;
}
break;

case 40: {
// 040 // 200ms
//void mf_chrOffFAST(){
  if (chrOn == true) mp_chrOff(10,1,false);
  instruction = wireVAL;
}
break;

case 41: {
// 041 // 2,000ms
//void mf_chrOffMID(){
  if (chrOn == true) mp_chrOff(100,1,false);
  instruction = wireVAL;
}
break;

case 42: {
// 042 // 2,000ms
//void mf_chrOffMID_R(){
  if (chrOn == true) mp_chrOff(100,1,true);
  instruction = wireVAL;
}
break;

case 43: {
// 043 // 2,000ms
//void mf_chrOffMID_RR(){
  if (chrOn == true) mp_chrOff(100,2,true);
  instruction = wireVAL;
}
break;

case 44: {
// 044 // 3,600ms 
//void mf_chrOffSLO(){
  if (chrOn == true) mp_chrOff(180,1,false);
  instruction = wireVAL;
}
break;

case 45: {
// 045 // 3,600ms 
//void mf_chrOffSLO_R(){
  if (chrOn == true) mp_chrOff(180,1,true);
  instruction = wireVAL;
}
break;

case 46: {
// 046 // 5,000ms
//void mf_chrOffSLO_RR(){  
  if (chrOn == true) mp_chrOff(250,2,true);
  instruction = wireVAL;
}
break;

case 47: {
// 047 // 7,200ms
//void mf_chrOffVSLO(){
  if (chrOn == true) mp_chrOff(360,1,false);
  instruction = wireVAL;
}
break;

case 48: {
// 048 // 7,200ms
//void mf_chrOffVSLO_R(){
  if (chrOn == true) mp_chrOff(360,1,true);
  instruction = wireVAL;
}
break;

case 49: {
// 049 // 7,200ms
//void mf_chrOffVSLO_RR(){  
  if(chrOn == true) mp_chrOff(360,2,true);
  instruction = wireVAL;
}
break;

// - - - - - - - - - - - 050-069 SOLON/SOLOFF
case 50: {
// 050 // 110ms
//void mf_solOnFAST(){
  if(solOn == false) mp_solOn(10,1,false);
  instruction = wireVAL;
}
break;

case 51: {
// 051 // 1,650ms
//void mf_solOnMID(){
  if (solOn == false) mp_solOn(150,1,false);
  instruction = wireVAL;
}
break;

case 52: {
// 052 // 1,650ms
//void mf_solOnMID_R(){
  if (solOn == false) mp_solOn(150,1,true);
  instruction = wireVAL;
}
break;

case 53: {
// 053 // 1,650ms
//void mf_solOnMID_RR(){
  if (solOn == false) mp_solOn(150,2,true);
  instruction = wireVAL;
}
break;

case 54: {
// 054 // 2,750ms
//void mf_solOnSLO(){
  if (solOn == false) mp_solOn(250,1,false);
  instruction = wireVAL;
}
break;

case 55: {
// 055 // 2,750ms
//void mf_solOnSLO_R(){
  if (solOn == false) mp_solOn(250,1,true);
  instruction = wireVAL;
}
break;

case 56: {
// 056 // 2,750ms
//void mf_solOnSLO_RR(){  
  if (solOn == false) mp_solOn(250,2,true);
  instruction = wireVAL;
}
break;

case 57: {
// 057 // 14,300ms
//void mf_solOnVSLO(){
  if (solOn == false) mp_solOn(1300,1,false);
  instruction = wireVAL;
}
break;

case 58: {
// 058 // 14,300ms
//void mf_solOnVSLO_R(){
  if (solOn == false) mp_solOn(1300,1,true);
  instruction = wireVAL;
}
break;

case 59: {
// 059 // 14,300ms
//void mf_solOnVSLO_RR(){  
  if (solOn == false) mp_solOn(1300,2,true);
  instruction = wireVAL;
}
break;

case 60: {
// 060 // 110ms
//void mf_solOffFAST(){
  if (solOn == true) mp_solOff(10,1,false);
  instruction = wireVAL;
}
break;

case 61: {
// 061 // 1,650ms
//void mf_solOffMID(){
  if (solOn == true) mp_solOff(150,1,false);
  instruction = wireVAL;
}

break;
case 62: {
// 062 // 1,650ms
//void mf_solOffMID_R(){
  if (solOn == true) mp_solOff(150,1,true);
  instruction = wireVAL;
}
break;

case 63: {
// 063 // 1,650ms
//void mf_solOffMID_RR(){
  if (solOn == true) mp_solOff(150,2,true);
  instruction = wireVAL;
}
break;

case 64: {
// 064 // 2,750ms
//void mf_solOffSLO(){
  if (solOn == true) mp_solOff(250,1,false);
  instruction = wireVAL;
}
break;

case 65: {
// 065 // 2,750ms
//void mf_solOffSLO_R(){
  if (solOn == true) mp_solOff(250,1,true);
  instruction = wireVAL;
}
break;

case 66: {
// 066 // 2,750ms
//void mf_solOffSLO_RR(){  
  if (solOn == true) mp_solOff(250,2,true);
  instruction = wireVAL;
}
break;

case 67: {
// 067 // 14,300ms
//void mf_solOffVSLO(){
  if (solOn == true) mp_solOff(1300,1,false);
  instruction = wireVAL;
}
break;

case 68: {
// 068 // 14,300ms
//void mf_solOffVSLO_R(){
  if (solOn == true) mp_solOff(1300,1,true);
  instruction = wireVAL;
}
break;

case 69: {
// 069 // 14,300ms
//void mf_solOffVSLO_RR(){  
  if (solOn == true) mp_solOff(1300,2,true);
  instruction = wireVAL;
}
break; 

// - - - - - - - - - - - 070-098 SOLFIN
case 70: {
// 070 // 2,500ms
//void mf_solFinMID_2_LO(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (2500, 2, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 71: {
// 071 // 2,200ms
//void mf_solFinMID_2_MID(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if(solOn == false) mp_solFin (2200, 2, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 72: {
// 072 // 3,000ms
//void mf_solFinMID_2_HI(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (3000, 2, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 73: {
// 073 // 2,500ms
//void mf_solFinMID_4_LO(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (2500, 4, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 74: {
// 074 // 2,200ms
//void mf_solFinMID_4_MID(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (2200, 4, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 75: {
// 075 // 3,000ms
//void mf_solFinMID_4_HI(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (3000, 4, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 76: {
// 076 // 2,500ms
//void mf_solFinMID_6_LO(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (2500, 6, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 77: {
// 077 // 2,200ms
//void mf_solFinMID_6_MID(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (2200, 6, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 78: {
// 078 // 3,000ms
//void mf_solFinMID_6_HI(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (3000, 6, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 80: {
// 080 // 4,500ms
//void mf_solFinSLO_2_LO(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (4500, 2, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 81: {
// 081 // 4,800ms
//void mf_solFinSLO_2_MID(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (4800, 2, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 82: {
// 082 // 5,300ms
//void mf_solFinSLO_2_HI(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (5300, 2, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 83: {
// 083 // 4,500ms
//void mf_solFinSLO_4_LO(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (4500, 4, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 84: {
// 084 // 4,800ms
//void mf_solFinSLO_4_MID(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (4800, 4, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 85: {
// 085 // 5,300ms
//void mf_solFinSLO_4_HI(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (5300, 4, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break;
 
case 86: {
// 086 // 4,500ms
//void mf_solFinSLO_6_LO(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (4500, 6, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 87: {
// 087 // 4,800ms
//void mf_solFinSLO_6_MID(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (4800, 6, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 88: {
// 088 // 5,300ms
//void mf_solFinSLO_6_HI(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (5300, 6, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 90: {
// 090 // 9,000ms
//void mf_solFinVSLO_2_LO(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (9000, 2, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 91: {
// 091 // 12,000ms
//void mf_solFinVSLO_2_MID(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (12000, 2, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 92: {
// 092 // 13,000ms
//void mf_solFinVSLO_2_HI(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if(solOn == false) mp_solFin (13000, 2, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 93: {
// 093 // 9,000ms
//void mf_solFinVSLO_4_LO(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (9000, 4, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 94: {
// 094 // 12,000ms
//void mf_solFinVSLO_4_MID(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (12000, 4, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 95: {  
// 095 // 13,000ms
//void mf_solFinVSLO_4_HI(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (13000, 4, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 96: {
// 096 // 9,000ms
//void mf_solFinVSLO_6_LO(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (9000, 6, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 97: {
// 097 // 12,000ms
//void mf_solFinVSLO_6_MID(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (12000, 6, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 98: {
// 098 // 13,000ms
//void mf_solFinVSLO_6_HI(){
  if (fadeIn == false) mp_solOff(10,1,false);
  if (solOn == false) mp_solFin (13000, 6, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

// - - - - - - - - - - - 100-128 SOLFOUT
case 100: {
// 100 // 2,500ms
//void mf_solFoutMID_2_LO(){
  if (solOn == true) mp_solFout (2500, 2, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 101: {
// 101 // 2,200ms
//void mf_solFoutMID_2_MID(){
  if (solOn == true) mp_solFout (2200, 2, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 102: {
// 102 // 3,000ms
//void mf_solFoutMID_2_HI(){
  if (solOn == true) mp_solFout (3000, 2, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 103: {
// 103 // 2,500ms
//void mf_solFoutMID_4_LO(){
  if (solOn == true) mp_solFout (2500, 4, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 104: {
// 104 // 2,200ms
//void mf_solFoutMID_4_MID(){
  if (solOn == true) mp_solFout (2200, 4, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 105: {
// 105 // 3,000ms
//void mf_solFoutMID_4_HI(){
  if (solOn == true) mp_solFout (3000, 4, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 106: {
// 106 // 2,500ms
//void mf_solFoutMID_6_LO(){
  if (solOn == true) mp_solFout (2500, 6, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 107: {
// 107 // 2,200ms
//void mf_solFoutMID_6_MID(){
  if (solOn == true) mp_solFout (2200, 6, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 108: {
// 108 // 3,000ms
//void mf_solFoutMID_6_HI(){
  if (solOn == true) mp_solFout (3000, 6, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 110: {
// 110 // 4,500ms
//void mf_solFoutSLO_2_LO(){
  if (solOn == true) mp_solFout (4500, 2, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 111: {
// 111 // 4,800ms
//void mf_solFoutSLO_2_MID(){
  if (solOn == true) mp_solFout (4800, 2, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 112: {
// 112 // 5,300ms
//void mf_solFoutSLO_2_HI(){
  if (solOn == true) mp_solFout (5300, 2, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 113: {
// 113 // 4,500ms
//void mf_solFoutSLO_4_LO(){
  if (solOn == true) mp_solFout (4500, 4, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}

case 114: {
// 114 // 4,800ms
//void mf_solFoutSLO_4_MID(){
  if (solOn == true) mp_solFout (4800, 4, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 115: {
// 115 // 5,300ms
//void mf_solFoutSLO_4_HI(){
  if (solOn == true) mp_solFout (5300, 4, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 116: {
// 116 // 4,500ms
//void mf_solFoutSLO_6_LO(){
  if (solOn == true) mp_solFout (4500, 6, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 117: {
// 117 // 4,800ms
//void mf_solFoutSLO_6_MID(){
  if (solOn == true) mp_solFout (4800, 6, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 118: {
// 118 // 5,300ms
//void mf_solFoutSLO_6_HI(){
  if (solOn == true) mp_solFout (5300, 6, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 120: {
// 120 // 9,000ms
//void mf_solFoutVSLO_2_LO(){
  if (solOn == true) mp_solFout (9000, 2, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 121: {
// 121 // 12,000ms
//void mf_solFoutVSLO_2_MID(){
  if (solOn == true) mp_solFout (12000, 2, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 122: {
// 122 // 13,000ms
//void mf_solFoutVSLO_2_HI(){
  if (solOn == true) mp_solFout (13000, 2, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 123: {
// 123 // 9,000ms
//void mf_solFoutVSLO_4_LO(){
  if (solOn == true) mp_solFout (9000, 4, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 124: {
// 124 // 12,000ms
//void mf_solFoutVSLO_4_MID(){
  if (solOn == true) mp_solFout (12000, 4, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 125: {
// 125 // 13,000ms
//void mf_solFoutVSLO_4_HI(){
  if (solOn == true) mp_solFout (13000, 4, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 126: {
// 126 // 9,000ms
//void mf_solFoutVSLO_6_LO(){
  if (solOn == true) mp_solFout (9000, 6, 100);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 127: {
// 127 // 12,000ms
//void mf_solFoutVSLO_6_MID(){
  if (solOn == true) mp_solFout (12000, 6, 150);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

case 128: {
// 128 // 13,000ms
//void mf_solFoutVSLO_6_HI(){
  if (solOn == true) mp_solFout (13000, 6, 250);
  if ((instruction > 159) && (instruction < 170)) mp_chayaFixer(instruction);
}
break; 

// - - - - - - - - - - - 130-141 LONGON/OFF
case 130: {
// 130 // 700ms
//void mf_long1OnFAST(){
  if (long1On == false) mp_longOn (100, 1);
  instruction = wireVAL;
}
break; 

case 131: {
// 131 // 700ms
//void mf_long2OnFAST(){
  if (long2On == false) mp_longOn (100, 2);
  instruction = wireVAL;
}
break; 

case 132: {
// 132 // 700ms
//void mf_long3OnFAST(){
  if (long3On == false) mp_longOn (100, 3);
  instruction = wireVAL;
}
break; 

case 133: { 
// 133 // 1,470ms
//void mf_long1OnMID(){
  if (long1On == false) mp_longOn (210, 1);
  instruction = wireVAL;
}
break; 

case 134: {
// 134 // 1,470ms
//void mf_long2OnMID(){
  if (long2On == false) mp_longOn (210, 2);
  instruction = wireVAL;
}
break; 

case 135: {
// 135 // 1,470ms
//void mf_long3OnMID(){
  if (long3On == false) mp_longOn (210, 3);
  instruction = wireVAL;
}
break; 

case 136: { 
// 136 // 700ms
//void mf_long1OffFAST(){
  if (long1On == true) mp_longOff (100, 1);
  instruction = wireVAL;
}
break; 

case 137: {
// 137 // 700ms
//void mf_long2OffFAST(){
  if (long2On == true) mp_longOff (100, 2);
  instruction = wireVAL;
}
break; 

case 138: {
// 138 // 700ms
//void mf_long3OffFAST(){
  if (long3On == true) mp_longOff (100, 3);
  instruction = wireVAL;
}
break; 

case 139: { 
// 139 // 1,470ms
//void mf_long1OffMID(){
  if (long1On == true) mp_longOff (210, 1);
  instruction = wireVAL;
}
break; 

case 140: {
// 140 // 1,470ms
//void mf_long2OffMID(){
  if (long2On == true) mp_longOff (210, 2);
  instruction = wireVAL;
}
break; 

case 141: {
// 141 // 1,470ms
//void mf_long3OffMID(){
  if (long3On == true) mp_longOff (210, 3);
  instruction = wireVAL;
}
break; 


// - - - - - - - - - - - 142-157 CHRFLTTR/SOLFLTTR
case 142: {
// 142
//void mf_chrFlttr1() {
  mp_chrFlttr (chrSH, CHRINDEX, 8000, 1);
  instruction = wireVAL;
}
break; 

case 143: {
// 143
//void mf_chrFlttr2() {
  mp_chrFlttr (chrSH, CHRINDEX, 6000, 1);
  instruction = wireVAL;
}
break; 

case 144: {
// 144
//void mf_chrFlttr3() {
  mp_chrFlttr (chrSH, CHRINDEX, 5000, 2);
  instruction = wireVAL;
}
break; 

case 145: {
// 145
//void mf_chrFlttr4() {
  mp_chrFlttr (chrSH, CHRINDEX, 3500, 1);
  instruction = wireVAL;
}
break; 

case 146: {
// 146
//void mf_chrFlttr5() {
  mp_chrFlttr (chrSH, CHRINDEX, 2600, 1);
  instruction = wireVAL;
}
break; 

case 147: {
// 147
//void mf_chrFlttr6() {
  mp_chrFlttr (chrSH, CHRINDEX, 2500, 2);
  instruction = wireVAL;
}
break; 

case 148: {
// 148
//void mf_chrFlttr7() {
  mp_chrFlttr (chrSH, CHRINDEX, 2000, 1);
  instruction = wireVAL;
}
break; 

case 149: {
// 149
//void mf_chrFlttr8() {
  mp_chrFlttr (chrSH, CHRINDEX, 1000, 2);
  instruction = wireVAL;
}
break; 

case 150: {
// 150
//void mf_solFlttr1() {
  mp_solFlttr (solSH, SOLINDEX, 5000, 1, 230);
  instruction = wireVAL;
}
break; 

case 151: {
// 151
//void mf_solFlttr2() {
  mp_solFlttr (solSH, SOLINDEX, 4000, 1, 220);
  instruction = wireVAL;
}
break; 

case 152: {
// 152
//void mf_solFlttr3() {
  mp_solFlttr (solSH, SOLINDEX, 3000, 2, 220);
  instruction = wireVAL;
}
break; 

case 153: {
// 153
//void mf_solFlttr4() {
  mp_solFlttr (solSH, SOLINDEX, 2500, 1, 220);
  instruction = wireVAL;
}
break; 

case 154: {
// 154
//void mf_solFlttr5() {
  mp_solFlttr (solSH, SOLINDEX, 1600, 1, 210);
  instruction = wireVAL;
}
break; 

case 155: {
// 155
//void mf_solFlttr6() {
  mp_solFlttr (solSH, SOLINDEX, 1500, 2, 210);
  instruction = wireVAL;
}
break; 

case 156: {
// 156
//void mf_solFlttr7() {
  mp_solFlttr (solSH, SOLINDEX, 1000, 1, 190);
  instruction = wireVAL;
}
break; 

case 157: {
// 157
//void mf_solFlttr8() {
  mp_solFlttr (chrSH, SOLINDEX, 900, 2, 190);
  instruction = wireVAL;
}
break; 


// - - - - - - - - - - - 160-169 CHAYA
case 160: {
// 160
//void mf_chaya1() {
  mp_chaya (chrH1SH, 1, true, chrH2SH, 1, true, 4000, .4);
  instruction = wireVAL;
}
break; 

case 161: {
// 161
//void mf_chaya2() {
  mp_chaya (chrH1SH, 2, true, chrH2SH, 2, true, 3000, .5);
  instruction = wireVAL;
}
break; 

case 162: {
// 162
//void mf_chaya3() {
  mp_chaya (chrH1SH, 2, true, chrH2SH, 2, true, 4000, .4);
  instruction = wireVAL;
}

case 163: {
// 163
//void mf_chaya4() {
  mp_chaya (chrH1SH, 1, true, solSH, 1, false, 2000, .3);
  instruction = wireVAL;
}
break; 

case 164: {
// 164
//void mf_chaya5() {
  mp_chaya (chrH1SH, 2, true, chrH2SH, 1, true, 3000, .6);
  instruction = wireVAL;
}
break; 

case 165: {
// 165
//void mf_chaya6() {
  mp_chaya (chrH1SH, 2, true, chrH2SH, 1, true, 2600, .7);
  instruction = wireVAL;
}
break; 

case 166: {
// 166
//void mf_chaya7() {
  mp_chaya (chrH1SH, 3, true, chrH2SH, 1, true, 2000, .4);
  instruction = wireVAL;
}
break; 

case 167: {
// 167
//void mf_chaya8() {
  mp_chaya (chrH1SH, 3, true, solSH, 2, false, 3000, .6);
  instruction = wireVAL;
}
break; 

case 168: {
// 168
//void mf_chaya9() {
  mp_chaya (chrH1SH, 3, true, chrH2SH, 3, true, 2200, .7);
  instruction = wireVAL;
}
break; 

case 169: {
// 169
//void mf_chaya10() {
  mp_chaya (chrH1SH, CHRHALFINDEX, true, solSH, SOLINDEX, false, 1000, .8);
  instruction = wireVAL;
}
break; 


// - - - - - - - - - - - 170-209 MUSICIANS
case 170: {
// 170
//void mf_musicianCHR1_60BPM_2() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 60, 1, 2);
  instruction = wireVAL;
}
break; 

case 171: {
// 171
//void mf_musicianCHR1_47BPM_2() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 47, 1, 2);
  instruction = wireVAL;
}
break; 

case 172: {
// 172
//void mf_musicianCHR1_33BPM_2() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 33, 1, 2);
  instruction = wireVAL;
}
break; 

case 173: {
// 173
//void mf_musicianCHR1_22BPM_2() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 22, 1, 2);
  instruction = wireVAL;
}
break; 

case 174: {
// 174
//void mf_musicianCHR1_60BPM_5() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 60, 1, 5);
  instruction = wireVAL;
}
break; 

case 175: {
// 175
//void mf_musicianCHR1_47BPM_5() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 47, 1, 5);
  instruction = wireVAL;
}
break; 

case 176: {
// 176
//void mf_musicianCHR1_33BPM_5() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 33, 1, 5);
  instruction = wireVAL;
}
break; 

case 177: {
// 177
//void mf_musicianCHR1_22BPM_5() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 22, 1, 5);
  instruction = wireVAL;
}
break; 

case 178: {
// 178
//void mf_musicianCHR1_47BPMa_6() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 47, 1.2, 6);
  instruction = wireVAL;
}
break; 

case 179: {
// 179
//void mf_musicianCHR1_33BPMa_5() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 33, 1.2, 5);
  instruction = wireVAL;
}
break; 

case 180: {
// 180
//void mf_musicianCHR1_47BPMd_6() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 47, .8, 6);
  instruction = wireVAL;
}
break; 

case 181: {
// 181
//void mf_musicianCHR1_33BPMd_5() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 33, .8, 5);
  instruction = wireVAL;
}
break; 

case 182: {
// 182
//void mf_musicianCHR_60BPM_2() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 60, 1, 2);
  instruction = wireVAL;
}
break; 

case 183: {
// 183
//void mf_musicianCHR_47BPM_2() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 47, 1, 2);
  instruction = wireVAL;
}
break; 

case 184: {
// 184
//void mf_musicianCHR_33BPM_2() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 33, 1, 2);
  instruction = wireVAL;
}
break; 

case 185: {
// 185
//void mf_musicianCHR_22BPM_2() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 22, 1, 2);
  instruction = wireVAL;
}
break; 

case 186: {
// 186
//void mf_musicianCHR_60BPM_5() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 60, 1, 5);
  instruction = wireVAL;
}
break; 

case 187: {
// 187
//void mf_musicianCHR_47BPM_5() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 47, 1, 5);
  instruction = wireVAL;
}
break; 

case 188: {
// 188
//void mf_musicianCHR_33BPM_5() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 33, 1, 5);
  instruction = wireVAL;
}
break; 

case 189: {
// 189
//void mf_musicianCHR_22BPM_5() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 22, 1, 5);
  instruction = wireVAL;
}
break; 

case 190: {
// 190
//void mf_musicianCHR_47BPMa_6() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 47, 1.2, 6);
  instruction = wireVAL;
}
break; 

case 191: {
// 191
//void mf_musicianCHR_33BPMa_5() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 33, 1.2, 5);
  instruction = wireVAL;
}
break; 

case 192: {
// 192
//void mf_musicianCHR_47BPMd_6() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 47, .8, 6);
  instruction = wireVAL;
}
break; 

case 193: {
// 193
//void mf_musicianCHR_33BPMd_5() {
  mp_musician (chrH1SH, CHRHALFINDEX, chrH2SH, CHRHALFINDEX, 33, .8, 5);
  instruction = wireVAL;
}
break; 

case 194: {
// 194
//void mf_musicianALL_60BPM_2() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 60, 1, 2);
  instruction = wireVAL;
}
break; 

case 195: {
// 195
//void mf_musicianALL_47BPM_2() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 47, 1, 2);
  instruction = wireVAL;
}
break; 

case 196: {
// 196
//void mf_musicianALL_33BPM_2() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 33, 1, 2);
  instruction = wireVAL;
}
break; 

case 197: {
// 197
//void mf_musicianALL_22BPM_2() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 22, 1, 2);
  instruction = wireVAL;
}
break; 

case 198: {
// 198
//void mf_musicianALL_60BPM_5() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 60, 1, 5);
  instruction = wireVAL;
}
break; 

case 199: {
// 199
//void mf_musicianALL_47BPM_5() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 47, 1, 5);
  instruction = wireVAL;
}
break; 

case 200: {
// 200
//void mf_musicianALL_33BPM_5() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 33, 1, 5);
  instruction = wireVAL;
}
break; 

case 201: {
// 201
//void mf_musicianALL_22BPM_5() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 22, 1, 5);
  instruction = wireVAL;
}
break; 

case 202: {
// 202
//void mf_musicianALL_47BPMa_6() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 47, 1.2, 6);
  instruction = wireVAL;
}
break; 

case 203: {
// 203
//void mf_musicianALL_33BPMa_5() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 33, 1.2, 5);
  instruction = wireVAL;
}
break; 

case 204: {
// 204
//void mf_musicianALL_47BPMd_6() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 47, .8, 6);
  instruction = wireVAL;
}
break; 

case 205: {
// 205
//void mf_musicianALL_33BPMd_5() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 33, .8, 5);
  instruction = wireVAL;
}
break; 

case 206: {
// 206
//void mf_musicianSpecial1() {
  mp_musician (solSH, 1, chrSH, 3, 47, 1.01, 20);
  instruction = wireVAL;
}
break; 

case 207: {
// 207
//void mf_musicianSpecial2() {
  mp_musician (solSH, 1, chrSH, 2, 33, .93, 17);
  instruction = wireVAL;
}
break; 

case 208: {
// 208
//void mf_musicianSpecial3() {
  mp_musician (solSH, SOLINDEX, chrSH, CHRINDEX, 10, 1.1, 11);
  instruction = wireVAL;
}
break; 

case 209: {
// 209
//void mf_musicianSpecial4() {
  mp_musician (chrH1SH, 1, chrH2SH, 1, 11, 1.01, 40);
  instruction = wireVAL;
}
break; 


// - - - - - - - - - - - 210-219 LIGETI
case 210: {
// 210
//void mf_ligeti1() {
  mp_ligeti (chr, CHRINDEX, 2000);
  instruction = wireVAL;
}
break; 

case 211: {
// 211
//void mf_ligeti2() {
  mp_ligeti (all, ALLINDEX, 2000);
  instruction = wireVAL;
}
break; 

case 212: {
// 212
//void mf_ligeti3() {
  mp_ligeti (chr, CHRINDEX, 1800);
  instruction = wireVAL;
}
break; 

case 213: {
// 213
//void mf_ligeti4() {
  mp_ligeti (all, ALLINDEX, 1800);
  instruction = wireVAL;
}
break; 

case 214: {
// 214
//void mf_ligeti5() {
  mp_ligeti (chr, CHRINDEX, 1600);
  instruction = wireVAL;
}
break; 

case 215: {
// 215
//void mf_ligeti6() {
  mp_ligeti (all, ALLINDEX, 1600);
  instruction = wireVAL;
}
break; 

case 216: {
// 216
//void mf_ligeti7() {
  mp_ligeti (chr, CHRINDEX, 1400);
  instruction = wireVAL;
}
break; 

case 217: {
// 217
//void mf_ligeti8() {
  mp_ligeti (all, ALLINDEX, 1400);
  instruction = wireVAL;
}
break; 

case 218: {
// 218
//void mf_ligeti9() {
  mp_ligeti (chr, CHRINDEX, 1000);
  instruction = wireVAL;
}
break; 

case 219: {
// 219
//void mf_ligeti10() {
  mp_ligeti (all, ALLINDEX, 1000);
  instruction = wireVAL;
}
break; 

} // switch loop ends
// - - - - - - - - - - - - - -  COMMENT TO HERE

} // void loop ends


//void loop() { delay (1); }

// - - - - - - - - - - - FUNCTIONS :::::::::::::::::::::::::::::::::::::::::::::::::::::
// - - - - - - - - - - - NONLOOPING FUNCTIONS - - - - - - - - - - - |
// - - - - - - - - - - - ALLON / ALLOF
void mp_allOn (int rampTime, float stagger, bool amIRandom) {
int ax[12]; // DECLARES EMPTY ARRAY WHICH CAN BE EITHER RANDOM OR LIN
// IF RANDOM, SHUFFLE ARRAY AND POPULATE AX[] WITH ALLSH[]
  if (amIRandom == true) {
    shuffleArray (allSH, ALLINDEX);
    for (int i=0; i < ALLINDEX; i++) {
      ax[i] = allSH[i];
      }
    }
// IF NOT RANDOM, POPULATE AX[] WITH ALL[]
  else {
    for (int i=0; i < ALLINDEX; i++) {
      ax[i] = all[i];
      }
    }
// FUNCTION WRITE
  for (int i = 0; i < ALLINDEX; i++) {
    digitalWrite (ax[i], HIGH);
    delay (jo_rand(rampTime/stagger, ((rampTime*stagger)+1), 1));
    }
  for (int i = 0; i < ALLINDEX; i++) {
    for (int x = 0; x < SOLINDEX; x++) {
      if (ax[i] == sol[x]); analogWrite (ax[i], 255);
    }
  }
// ADJUST STATE BOOLS
  chrOn = true;
  solOn = true;
  long1On = true;
  long2On = true;
  long3On = true;
}

// - - - - - - - - - - - ALLOFF
void mp_allOff (int rampTime, float stagger, bool amIRandom) {
int ax[12]; // DECLARES EMPTY ARRAY WHICH CAN BE EITHER RANDOM OR LIN
// IF RANDOM, SHUFFLE ARRAY AND POPULATE AX[] WITH ALLSH[]
  if (amIRandom == true) {
    shuffleArray (allSH, ALLINDEX);
    for (int i=0; i < ALLINDEX; i++) {
      ax[i] = allSH[i];
      }
    }
// IF NOT RANDOM, POPULATE AX[] WITH ALL[]
  else {
    for (int i=0; i < ALLINDEX; i++) {
      ax[i] = all[i];
      }
    }
// FUNCTION WRITE
  for (int i = 0; i < ALLINDEX; i++) {
    digitalWrite (ax[i], LOW);
    delay (jo_rand(rampTime/stagger, ((rampTime*stagger)+1), 1));
    }
  for (int i = 0; i < ALLINDEX; i++) {
    for (int x = 0; x < SOLINDEX; x++) {
      if (ax[i] == sol[x]); analogWrite (ax[i], 0); 
    }
  }
// ADJUST STATE BOOLS
  chrOn = false;
  solOn = false;
  long1On = false;
  long2On = false;
  long3On = false;
}

// - - - - - - - - - - - CHRON / CHROFF
void mp_chrOn (int rampTime, float stagger, bool amIRandom) {
int ax[6]; // DECLARES EMPTY ARRAY WHICH CAN BE EITHER RANDOM OR LIN
// IF RANDOM, SHUFFLE ARRAY AND POPULATE AX[] WITH CHRSH[]
  if (amIRandom == true) {
    shuffleArray (chrSH, CHRINDEX);
    for (int i=0; i < CHRINDEX; i++) {
      ax[i] = chrSH[i];
      }
    }
// IF NOT RANDOM, POPULATE AX[] WITH CHR[]
  else {
    for (int i=0; i < CHRINDEX; i++) {
      ax[i] = chr[i];
      }
    }
// FUNCTION WRITE
  for (int i = 0; i < CHRINDEX; i++) {
    digitalWrite (ax[i], HIGH);
    delay (jo_rand(rampTime/stagger, ((rampTime*stagger)+1), 1));
    }
// ADJUST STATE BOOLS
  chrOn = true;
  long1On = true;
  long2On = true;
  long3On = true;
}

void mp_chrOff (int rampTime, float stagger, bool amIRandom) {
int ax[6]; // DECLARES EMPTY ARRAY WHICH CAN BE EITHER RANDOM OR LIN
// IF RANDOM, SHUFFLE ARRAY AND POPULATE AX[] WITH CHRSH[]
  if (amIRandom == true) {
    shuffleArray (chrSH, CHRINDEX);
    for (int i=0; i < CHRINDEX; i++) {
      ax[i] = chrSH[i];
      }
    }
// IF NOT RANDOM, POPULATE AX[] WITH CHR[]
  else {
    for (int i=0; i < CHRINDEX; i++) {
      ax[i] = chr[i];
      }
    }
// FUNCTION WRITE
  for (int i = 0; i < CHRINDEX; i++) {
    digitalWrite (ax[i], LOW);
    delay (jo_rand(rampTime/stagger, ((rampTime*stagger)+1), 1));
    }
// ADJUST STATE BOOLS
  chrOn = false;
  long1On = false;
  long2On = false;
  long3On = false;
}

void mp_longOn (int rampTime, int whichLong) {
// ORIENTATION OF LONGITUDE ROWS
if ((wireID % 2) == 0) {
    int ArrayLong1[7] = {20, 19, 18, 17, 16, 15, 14};
    int ArrayLong2[7] = {13, 12, 11, 10, 9, 8, 7};
    int ArrayLong3[6] = {6, 5, 4, 3, 2, 1};
    int ArrayLong1Max = 7;
    int ArrayLong3Max = 6;
    
      switch (whichLong) {
        case 1: {
          for (int i=0; i<ArrayLong1Max; i++) {
          digitalWrite (ArrayLong1[i], HIGH);
          delay(20);
          long1On = true;
          }
        }
        break;
        case 2: {
          for (int i=0; i<7; i++) {
          digitalWrite (ArrayLong2[i], HIGH);
          delay(20);
          long2On = true;
          }
        }
        break;
        case 3: {
          for (int i=0; i<ArrayLong3Max; i++) {
          digitalWrite (ArrayLong3[i], HIGH);
          delay(20);
          long3On = true;
          chrOn = true;
          }
        }
        break;
      }
    }
else {
    int ArrayLong1[6] = {1, 2, 3, 4, 5, 6};
    int ArrayLong2[7] = {7, 8, 9, 10, 11, 12, 13};
    int ArrayLong3[7] = {14, 15, 16, 17, 18, 19, 20};
    int ArrayLong1Max = 6;
    int ArrayLong3Max = 7;
    
      switch (whichLong) {
        case 1: {
          for (int i=0; i<ArrayLong1Max; i++) {
          digitalWrite (ArrayLong1[i], HIGH);
          delay(20);
          long1On = true;
          }
        }
        break;
        case 2: {
          for (int i=0; i<7; i++) {
          digitalWrite (ArrayLong2[i], HIGH);
          delay(20);
          long2On = true;
          }
        }
        break;
        case 3: {
          for (int i=0; i<ArrayLong3Max; i++) {
          digitalWrite (ArrayLong3[i], HIGH);
          delay(20);
          long3On = true;
          chrOn = true;
          }
        }
        break;
      }
    }
}

void mp_longOff (int rampTime, int whichLong) {
// ORIENTATION OF LONGITUDE ROWS
if ((wireID % 2) == 0) {
    int ArrayLong1[7] = {20, 19, 18, 17, 16, 15, 14};
    int ArrayLong2[7] = {13, 12, 11, 10, 9, 8, 7};
    int ArrayLong3[6] = {6, 5, 4, 3, 2, 1};
    int ArrayLong1Max = 7;
    int ArrayLong3Max = 6;
    
      switch (whichLong) {
        case 1: {
          for (int i=0; i<ArrayLong1Max; i++) {
          digitalWrite (ArrayLong1[i], LOW);
          delay(20);
          long1On = false;
          }
        }
        break;
        case 2: {
          for (int i=0; i<7; i++) {
          digitalWrite (ArrayLong2[i], LOW);
          delay(20);
          long2On = false;
          }
        }
        break;
        case 3: {
          for (int i=0; i<ArrayLong3Max; i++) {
          digitalWrite (ArrayLong3[i], LOW);
          delay(20);
          long3On = false;
          chrOn = false;
          }
        }
        break;
      }
    }
else {
    int ArrayLong1[6] = {1, 2, 3, 4, 5, 6};
    int ArrayLong2[7] = {7, 8, 9, 10, 11, 12, 13};
    int ArrayLong3[7] = {14, 15, 16, 17, 18, 19, 20};
    int ArrayLong1Max = 6;
    int ArrayLong3Max = 7;
    
      switch (whichLong) {
        case 1: {
          for (int i=0; i<ArrayLong1Max; i++) {
          digitalWrite (ArrayLong1[i], LOW);
          delay(20);
          long1On = false;
          }
        }
        break;
        case 2: {
          for (int i=0; i<7; i++) {
          digitalWrite (ArrayLong2[i], LOW);
          delay(20);
          long2On = false;
          }
        }
        break;
        case 3: {
          for (int i=0; i<ArrayLong3Max; i++) {
          digitalWrite (ArrayLong3[i], LOW);
          delay(20);
          long3On = false;
          chrOn = false;
          }
        }
        break;
      }
    }
}


// - - - - - - - - - - - SOLON / SOLOFF
void mp_solOn (int rampTime, float stagger, bool amIRandom) {
int ax[6]; // DECLARES EMPTY ARRAY WHICH CAN BE EITHER RANDOM OR LIN
// IF RANDOM, SHUFFLE ARRAY AND POPULATE AX[] WITH SOLSH[]
  if (amIRandom == true) {
    shuffleArray (solSH, SOLINDEX);
    for (int i=0; i < SOLINDEX; i++) {
      ax[i] = solSH[i];
      }
    }
// IF NOT RANDOM, POPULATE AX[] WITH SOL[]
  else {
    for (int i=0; i < SOLINDEX; i++) {
      ax[i] = sol[i];
      }
    }
// FUNCTION WRITE
  for (int i = 0; i < SOLINDEX; i++) {
    int hiVal = jo_rand(200,255,.6);
    analogWrite (ax[i], hiVal);
    delay (jo_rand(rampTime/stagger, ((rampTime*stagger)+1), 1));
    }
// ADJUST STATE BOOLS
  solOn = true;
}

void mp_solOff (int rampTime, float stagger, bool amIRandom) {
int ax[SOLINDEX]; // DECLARES EMPTY ARRAY WHICH CAN BE EITHER RANDOM OR LIN
// IF RANDOM, SHUFFLE ARRAY AND POPULATE AX[] WITH SOLSH[]
  if (amIRandom == true) {
    shuffleArray (solSH, SOLINDEX);
    for (int i=0; i < SOLINDEX; i++) {
      ax[i] = solSH[i];
      }
    }
// IF NOT RANDOM, POPULATE AX[] WITH SOL[]
  else {
    for (int i=0; i < SOLINDEX; i++) {
      ax[i] = sol[i];
      }
    }
// FUNCTION WRITE
  for (int i = 0; i < SOLINDEX; i++) {
    analogWrite (ax[i], 0);
    delay (jo_rand(rampTime/stagger, ((rampTime*stagger)+1), 1));
    }
// ADJUST STATE BOOLS
  solOn = false;
}

// - - - - - - - - - - - SOLFIN / SOLFOUT
void mp_solFin(int timeIn, int density, int range) {
// SHUFFLES ARRAY EXCLUSIVE TO FADEINS AND OUTS
shuffleArray (solSHFF, SOLINDEX);
// RAMP LOOP
for (int rampLV=0; rampLV<range; rampLV=(rampLV+3)) {
// UNIT LOOP
  for (int i=0; i < density; i++) {
    analogWrite((solSHFF[i]), rampLV);
    }
  float delayVal = (timeIn / (range/3));
  delay(delayVal);
  }
solOn = true;
fadeIn = true;
// ADJUST STATE BOOLS
}

void mp_solFout(int timeOut, int density, int range) {
// RAMP LOOP
for (int rampLV=range; rampLV>0; rampLV=(rampLV-3)) {
// UNIT LOOP
for (int i=0; i < density; i++) {
  analogWrite(solSHFF[i], rampLV);
  }
  float delayVal = (timeOut / (range/3));
  delay(delayVal);
  }
// ADJUST STATE BOOLS
solOn = false;
fadeIn = false;
}


// - - - - - - - - - - - LOOPING FUNCTIONS - - - - - - - - - - - - - - - - - - -|
// - - - - - - - - - - - FLUTTERS (VARIABLE HIGH STATES)
void mp_chrFlttr (int ax[], int axSz, int loopSpeed, int density) {
  switch (chrFlttrStatus) {      
    case false:{
    if (millis() > (chrFlttrTimeInt + loopSpeed)) {
      shuffleArray (ax, axSz);
      int densityMod = jo_rand (0, (density+1), .7);
      for (int i=0; i < densityMod; i++) {
        digitalWrite ((ax[i]), LOW);
        delay(2);
        truDensity = densityMod;
        chrFlttrStatus = true;
        chrFlttrTimeInt = millis();
        } } }
    break;  
    case true: {
    if (millis() > (chrFlttrTimeInt + loopSpeed)) {
      for (int i=0; i < truDensity; i++) {
        digitalWrite ((ax[i]), HIGH);
        delay(2);
        chrFlttrStatus = false;
        chrFlttrTimeInt = millis();
      } } }
    break;
  }
  chrOn = true;
}

void mp_solFlttr (int ax[], int axSz, int loopSpeed, int density, int range) {
if (millis() > (solFlttrTimeInt + loopSpeed)) {
  shuffleArray (ax, axSz);
  int densityMod = jo_rand (0, (density+1), .7);
  for (int i=0; i < densityMod; i++) {
    int modRange = jo_rand (range, 255, 1);
    analogWrite (ax[i], modRange); 
    }
  solFlttrTimeInt = millis();
  }
  solOn = true;
}


// - - - - - - - - - - - COUNTERPOINTERS
void mp_chaya (int a0[], int a0Sz, bool am0Chorus, int a1[], int a1Sz, bool am1Chorus, int rate, float rto) {
  if (millis() > ctrPtrTimeInt) {
    int chayaReader = jo_rand(0, 3, .9);
    switch (chayaReader) {
      case 0:
        if (am0Chorus == true) {
          mp_chrCtrPtr(a0, a0Sz, 0); }
        else {
          mp_solCtrPtr(a0, a0Sz, 0); }
      break;
      case 1:
        if (am1Chorus == true) {
          mp_chrCtrPtr(a1, a1Sz, 1); }
        else {
          mp_solCtrPtr(a1, a1Sz, 1); }
      break;      
    }
    int ctrPtrIntvl = jo_rand(rate*rto, rate/rto, 1);
    ctrPtrTimeInt = millis() + ctrPtrIntvl;
  }
  chrOn = true;
}

void mp_chrCtrPtr(int ctrPtrPCArray[], int axSz, int ctrPtrUnit) {
switch (ctrPtrUnit) {
  case 0: 
  ctrPtrU0 = !ctrPtrU0;
  ctrPtrUOp = ctrPtrU0;
  break;
  case 1:
  ctrPtrU1 = !ctrPtrU1;
  ctrPtrUOp = ctrPtrU1;
  break;  
}
for(int cPPu = 0; cPPu < axSz; cPPu++) {
    digitalWrite(ctrPtrPCArray[cPPu], ctrPtrUOp);
    delay (2); 
    }
}

void mp_solCtrPtr(int ctrPtrPCArray[], int axSz, int ctrPtrUnit) {
switch (ctrPtrUnit) {
  case 0: 
  ctrPtrU0 = !ctrPtrU0;
  ctrPtrUOp = ctrPtrU0;
  break;
  case 1:
  ctrPtrU1 = !ctrPtrU1;
  ctrPtrUOp = ctrPtrU1;
  break;  
}
if (ctrPtrUOp == true) {
  PWMval = jo_rand (180, 255, 1);
}
else {
  PWMval = 0;
  }
for(int cPPu = 0; cPPu < axSz; cPPu++) {
    analogWrite(ctrPtrPCArray[cPPu], PWMval);
    delay (2); 
    }
solOn = true;
}

void mp_chayaFixer (int instruction) {
  switch (instruction) {
      case 160: {
    // 160
    //void mf_chaya1() {
      mp_chaya (chrH1SH, 1, true, chrH2SH, 1, true, 4000, .4);
    }
    break; 
    
    case 161: {
    // 161
    //void mf_chaya2() {
      mp_chaya (chrH1SH, 1, true, chrH2SH, 1, true, 3000, .5);
    }
    break; 
    
    case 162: {
    // 162
    //void mf_chaya3() {
      mp_chaya (chrH1SH, 2, true, chrH2SH, 2, true, 4000, .4);
    }
    
    case 163: {
    // 163
    //void mf_chaya4() {
      mp_chaya (chrH1SH, 1, true, solSH, 1, false, 2000, .3);
    }
    break; 
    
    case 164: {
    // 164
    //void mf_chaya5() {
      mp_chaya (chrH1SH, 2, true, chrH2SH, 1, true, 3000, .6);
    }
    break; 
    
    case 165: {
    // 165
    //void mf_chaya6() {
      mp_chaya (chrH1SH, 2, true, chrH2SH, 1, true, 2600, .7);
    }
    break; 
    
    case 166: {
    // 166
    //void mf_chaya7() {
      mp_chaya (chrH1SH, 3, true, chrH2SH, 1, true, 2000, .4);
    }
    break; 
    
    case 167: {
    // 167
    //void mf_chaya8() {
      mp_chaya (chrH1SH, 3, true, solSH, 2, false, 3000, .6);
    }
    break; 
    
    case 168: {
    // 168
    //void mf_chaya9() {
      mp_chaya (chrH1SH, 3, true, chrH2SH, 3, true, 2200, .7);
    }
    break; 
    
    case 169: {
    // 169
    //void mf_chaya10() {
      mp_chaya (chrH1SH, CHRHALFINDEX, true, solSH, SOLINDEX, false, 1000, .8);
    }
    break; 
  }
}

// - - - - - - - - - - - MUSIC MAKERS
void mp_musician (int a0[], int a0Sz, int a1[], int a1Sz, int tempoIn, float tempoScl, int meter) {
int measureSize = meter + 1;
int measure[measureSize];
measure[1] = 1;
for (int i = 2; i < measureSize; i++) {
  measure[i] = 0; }
if (beatNo > meter) {
  musicMakerInitiator = true; }
if (beatNo == 0) {
  musicMakerInitiator = true; }
switch (musicMakerInitiator) {
  case true: {
      if (tempoRegistration != tempoIn) {
        tempo = tempoIn; }
      if ((tempo > 100) || (tempo < 10)) {
        tempo = tempoIn; }
      musicMakerInitiator = false;
      musicMaker1Status = false;
      musicMaker2Status = false;
      beatNo = 1;
      }
      break;
  case false: {
      switch (measure[beatNo]) {
        case 1: { // DOWNBEAT
            switch (musicMaker1Status) {
              case false: {
                  if (millis() > (musicMakerTimeInt + (30000/tempo))) {
                  for (int i=0; i<a0Sz; i++) {
                    digitalWrite (a0[i], HIGH);
                    delay(10); }
                    musicMaker1Status = true;
                    musicMakerTimeInt = millis();
                  } }
                break;
              case true: {
                  if (millis() > (musicMakerTimeInt + (30000/tempo))) {
                    for (int i=0; i<a0Sz; i++) {
                    digitalWrite (a0[i], LOW);
                    delay(10); }
                    musicMakerTimeInt = millis();
                    musicMaker1Status = false;
                    musicMaker2Status = false;
                    beatNo++;
                    tempo = tempo * tempoScl;
                    tempoRegistration = tempoIn;
                    } }
                break;
                } } 
            break;
        case 0: { // OFFBEATS
            switch (musicMaker2Status) {
              case false: {
                if (millis() > (musicMakerTimeInt + (30000/tempo))) {
                  for (int i=0; i<a1Sz; i++) {
                    digitalWrite (a1[i], HIGH);
                    delay(10); }
                    musicMakerTimeInt = millis();
                    musicMaker2Status = true;
                    } }
                break;
              case true: {
                  if (millis() > (musicMakerTimeInt + (30000/tempo))) {
                    for (int i=0; i<a1Sz; i++) {
                    digitalWrite (a1[i], LOW);
                    delay(10); }
                    musicMakerTimeInt = millis();
                    musicMaker2Status = false;
                    beatNo++;
                    tempo = (tempo * tempoScl);
                    } }
                break;
                }
              }
            break;
        } }
      break;
  }
chrOn = true;
}

void mp_ligeti(int a0[], int aSz, int dlyFactor) {
  switch (metronomeStatus) {
  case false: {
    metronome++;
    for (int x=0; x<aSz; x++) {
      if ((metronome % x) == 0) {
        digitalWrite (a0[x], HIGH);
      }
      delay (10);
      metronomeStatus = true;
      }
    }
    break;
  case true: {
    if (millis() > (metronomeTimeInt + dlyFactor)) {    
      for (int x=0; x<aSz; x++) {
        if ((metronome % x) == 0) {
          digitalWrite (a0[x], LOW);
        }
        delay (10);
        metronomeStatus = false;
        metronomeTimeInt = millis();
        }
      }
    }
    break;
  }
  chrOn = true;
}
  
// - - - - - - - - - - - UTILITY FUNCTIONS - - - - - - - |
void mp_rest() {
  delay(1);
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




// - - - - - - - - - - - LIBRARY OF FUNCTIONS AND ARGUMENTS ::::::::::::::::::::::::::::

// - - - - NON-LOOPING: needs "if (! x){}" conditions - - - - 
// mp_chrOn, mp_chrOff, mp_solOn, mp_solOff, mp_allOn, mp_allOff::
// (int TIME BETWEEN EACH UNIT ON/OFF, float RANDOM FACTOR, bool RANDOM ORDER?)
// mp_longOn, mp_longOff::
// (int TIME BETWEEN EACH UNIT ON/OFF, int WHICH LONGITUDINAL ARRAY) 
// mp_solFin, mp_solFout::
// (int TIME IN or TIME OUT, int DENSITY OF EACH PASS, int HIGH PWM RANGE)

// - - - - LOOPING: - - - - 
// mp_chrFlttr::
// (int SHUFFLE ARRAY, int ARRAYSIZE, int MAX LOOPSPEED (/4 = min), int DENSITY EACH PASS)
// mp_solFlttr::
// (int SHUFFLE ARRAY, int ARRAYSIZE, int MAX LOOPSPEED (/4 = min), int DENSITY, int LOW PWM RANGE)
// mp_chaya::
// (int SHUFFLE ARRAY NO 1, int ARRAYSIZE 1, bool CHORUS?, int SHUFFLE ARRAY NO 2, int ARRAYSIZE 2, bool CHORUS?
// int COUNTER POINT RATE, float RATIO (.25 ~ 4:1), 
// mp_musician::
// (int ARRAY DOWNBEAT, int ARRAYSIZE, int ARRAY OTHER BEATS, int ARRAYSIZE 2, int STARTING TEMPO,
// float ACCELERANDO or DECELERANDO, int METER)
// mp_ligeti::
// (int ARRAY, int ARRAYSIZE, int INTERVAL BETWEEN ON/OFF / SUCCESSIVE READS FROM GENERATIVE SERIES)



