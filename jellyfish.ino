
int blue = 9;    // LED connected to digital pin 9
int red =10;
int green =11;

int bluein = 2;
int redin = 1;
int greenin = 0;


static float redinc=0.0011/3;
static float greeninc=0.0023/3;
static float blueinc=0.0032/3;
static float brightinc=0.001;

float m=0.0113582931798;
float c=3.05125924434;


int sensorPin = A5;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
float voltage = 0;

int neverun=0;

void setup()  {
  // nothing happens in setup
  analogWrite(red,0);
  analogWrite(blue,0);
  analogWrite(green,0);
  //Serial.begin(115200);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  //voltage = sensorValue*m +c;
  //Serial.println(sensorValue);
  if (neverun==0){
    if (sensorValue>530){

      //Read analogue
      int redread = analogRead(redin) / 2;
      int blueread  = analogRead(bluein)/2;
      int greenread = analogRead(greenin)/2;

      static float brightin = 4.712;
      float brightout;

      // do input, etc. here - as long as you don't pause, the LED will keep pulsing

//      brightin = brightin + brightinc;
//      if (brightin > 10.995)
//        brightin = 4.712;
//      brightout = (sin(brightin) +1)/2;
//      brightout=brightout*1;   //BRIGHTNESS ADJUSTMENT
      //analogWrite(bright,brightout);

      analogWrite(red,redread);

      analogWrite(green,greenread);

      analogWrite(blue,blueread);
    }
    else{
      analogWrite(blue,0);
      analogWrite(red,0);
      analogWrite(green,0);
      neverun=1;
      delay(100000);


    }
  }
}

int smooth(int x){
  const int numReadings = 50;

  static int readings[numReadings];      // the readings from the analog input
  static int index = 0;                  // the index of the current reading
  static int total = 0;                  // the running total
  static int average = 0;                // the average


  // subtract the last reading:
  total= total - readings[index];
  // read from the sensor:
  readings[index] = x;
  // add the reading to the total:
  total= total + readings[index];
  // advance to the next position in the array:
  index = index + 1;

  // if we're at the end of the array...
  if (index >= numReadings)
    // ...wrap around to the beginning:
    index = 0;

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  return x;
}
