/*
     ________  ___   ___
    / __/ __ \/ _ | / _ \
   _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Practice
  > By 1487Quantum ( https://github.com/1487quantum )
  
  > Activity 2 (7 segment display, common anode), Task D
  > =====================================================
  > Display countdown of the numbers 9 to 0 on the 7 segment display.


*/

//Segment pins to turn off for the various numbers
const int dispNum[10][5] = {
  {12},				//Num 0: g
  {10,11,12,8,7},	//Num 1: a f g e d
  {11,6},			//Num 2: f c
  {11,8},			//Num 3: f e
  {10,8,7},			//Num 4: a e d
  {9,8},			//Num 5: b e
  {9,5},			//Num 6: b
  {11,12,8,7},		//Num 7: f g e d
  {0},				//Num 8: -NONE-
  {8}				//Num 9: e
};

void onAllSegments() {
  for (int i = 6; i < 13; ++i)
    digitalWrite(i, LOW);	                //Turn on all the segment
}

void setNum(int num) {
  onAllSegments();
  for (int j = 0; j < 5; ++j) {
    Serial.println(dispNum[num][j]);
    if (dispNum[num][j] == 0)
      break;
    else {
      digitalWrite(dispNum[num][j], HIGH);	//Turn off segments
    }
  }
  delay(1000);
}

void setup() {
  Serial.begin(115200);
  for (int i = 6; i < 13; ++i){
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);	                //Turn off all the segment
  }
}

void loop() {
 //Display 9 - 0
  for (int k = 9; k >= 0; --k) {
    setNum(k);
  }
}