//4-Channel Relay Board with Arduino Nano and 4-Channel Momentary Switch
//CREDIT: L.J ESTERHUIZEN @ ESTREUX EED

const int pushButton[] ={2,3,4,5};// define push button inputs
const int relayPin[]={9,8,7,6};// output pins where 4 relays will be connected
String relayNames[] ={"CH1", "CH2","CH3","CH4"};
int pushed[] ={0,0,0,0};// status of each buttons
int relayStatus[] ={HIGH,HIGH,HIGH,HIGH};// initial status of relay


void setup() {
  Serial.begin(9600);// initialize serial monitor 
  for(int i=0; i<4; i++)
  {
    pinMode(pushButton[i], INPUT_PULLUP); 
    pinMode(relayPin[i], OUTPUT);   
    digitalWrite(relayPin[i], HIGH);// initial relay status to be OFF
  }
}

void loop() {

  for(int i=0; i<4; i++)
  {
     int  val = digitalRead(pushButton[i]);   
    if(val == HIGH && relayStatus[i] == LOW){
  
      pushed[i] = 1-pushed[i];
      delay(100);
    }// if   

  relayStatus[i] = val;

      if(pushed[i] == HIGH){
        Serial.print(relayNames[i]);
        Serial.println(" ON");
        digitalWrite(relayPin[i], LOW); 
       
      }else{
        Serial.print(relayNames[i]);
        Serial.println(" OFF");
        digitalWrite(relayPin[i], HIGH);
   
      }
 
  }
    Serial.println("=="); 
  delay(100);
}
