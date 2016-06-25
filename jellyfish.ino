
int blue = 9;    // LED connected to digital pin 9
int red =10;
int green =11;

static float redinc=0.001;
static float greeninc=0.001;
static float blueinc=0.001;
static float brightinc=0.001;


void setup()  {
  // nothing happens in setup
 analogWrite(red,0);
analogWrite(blue,0);
analogWrite(green,0);
}

void loop()
{
  static float redin = 4.712;
  float redout;

  static float greenin = 4.712;
  float greenout;

   static float bluein = 4.712;
  float blueout;

   static float brightin = 4.712;
  float brightout;

 // do input, etc. here - as long as you don't pause, the LED will keep pulsing

    brightin = brightin + brightinc;
  if (brightin > 10.995)
    brightin = 4.712;
  brightout = sin(brightin) * 127.5;
  //analogWrite(bright,brightout);


  redin = redin + redinc;
  if (redin > 10.995)
    redin = 4.712;
  redout = sin(redin);
    redout=1;
    redout = redout * 127.5 +brightout;
  redout = redout ;

  analogWrite(red,redout);

  greenin = greenin + greeninc;
  if (greenin > 10.995)
    greenin = 4.712;
  greenout = sin(greenin);
    greenout=1;
    greenout = greenout * 127.5 + brightout;
  greenout = greenout ;

  analogWrite(green,greenout);

  bluein = bluein + blueinc;
  if (bluein > 10.995)
    bluein = 4.712;
  blueout = sin(bluein);
  blueout=1;
  blueout=blueout * 127.5 + brightout;
  blueout=blueout ;
  analogWrite(blue,blueout);


}
