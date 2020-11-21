/*
 * Sistem Kontrol Elektronika 2020
 * Wheel Chair Control Program
 * Fikri Rida Pebriansyah
 * NPM 140910170023
 * 
 * S1 Teknik Elektro Universitas Padjadjaran
 * 
 */

#define L_SAFETY        26

#define L_MOUT1         28  // --> PIN 1
#define L_MOUT2         30  // --> PIN 2
#define L_ENABLE_1      32  // --> PIN 3
#define L_ENABLE_2      34  // --> PIN 4
#define L_MOTOR_PWM     7   // --> PIN 6

#define R_SAFETY        27

#define R_MOUT1         29  // --> PIN 1
#define R_MOUT2         31  // --> PIN 2
#define R_ENABLE_1      33  // --> PIN 3
#define R_ENABLE_2      35  // --> PIN 4
#define R_MOTOR_PWM     10  // --> PIN 6

#define ANALOG_X        A3
#define ANALOG_Y        A4
#define ANALOG_B        3

#define SAFETY_TRIG     2

#define R_ULTRASONIC_1  7
#define R_ULTRASONIC_2  8

unsigned int leftMotorSpeed;
unsigned int rightMotorSpeed;

unsigned long subfRefreshAnalog = 0;
unsigned long subfRefreshUltrasonic = 0;
unsigned long subfTestMotor = 0;

volatile unsigned long lastMET = 0;
volatile unsigned long lastMST = 0;

bool L_MOTOR_ENABLED = false;
bool R_MOTOR_ENABLED = false;

bool MOTOR_SAFETY = false;

int ANALOG_X_CENTER;
int ANALOG_Y_CENTER;

const int ZERO_THRESHOLD = 10;
const unsigned int analogPollingRate = 500;

int speedOfSound = 340;

void setup() {
  Serial.begin(9600);
  Serial.println("Program Started...");
  
  pinMode( L_MOTOR_PWM, OUTPUT );
  pinMode( L_SAFETY, OUTPUT );
  pinMode( L_MOUT1, OUTPUT );
  pinMode( L_MOUT2, OUTPUT );
  pinMode( L_ENABLE_1, OUTPUT );
  pinMode( L_ENABLE_2, OUTPUT );
  
  pinMode( R_MOTOR_PWM, OUTPUT );
  pinMode( R_SAFETY, OUTPUT );
  pinMode( R_MOUT1, OUTPUT );
  pinMode( R_MOUT2, OUTPUT );
  pinMode( R_ENABLE_1, OUTPUT );
  pinMode( R_ENABLE_2, OUTPUT );

  pinMode( ANALOG_X, INPUT );
  pinMode( ANALOG_Y, INPUT );
  pinMode( ANALOG_B, INPUT );

  attachInterrupt(digitalPinToInterrupt(ANALOG_B), motorEnableTriggered, FALLING);
  attachInterrupt(digitalPinToInterrupt(SAFETY_TRIG), motorSafetyTriggered, RISING);

  int X_buff = 0;
  int Y_buff = 0;
  
  for ( int i=0; i<10; i++ ){
      X_buff += ANALOG_X;
      Y_buff += ANALOG_Y;
      delay(100);
  }

  X_buff = X_buff / 10;
  Y_buff = Y_buff / 10;
  
  ANALOG_X_CENTER = analogRead( ANALOG_X) ;
  ANALOG_Y_CENTER = analogRead( ANALOG_Y) ;
  Serial.print( "[INFO] The analog center point is set to X: " );
  Serial.print( ANALOG_X_CENTER );
  Serial.print( " Y: " );
  Serial.println( ANALOG_Y_CENTER );

  Serial.print("[INFO] The analog polling rate is set to ");
  Serial.print(analogPollingRate);
  Serial.println(" read(s) per second");

  Serial.print("[INFO] The sound velocity in this area is ");
  Serial.print(calculateSoundSpeed (25.3));
  Serial.println(" m/s");
  
  delay(1000);
  setMotorSafety( false );
  delay(1000);
  setMotorDirection( true, true );
  delay(1000);
  setMotorEnable( true, true );
  delay(1000);
}

void loop() {
  if ( millis() - subfRefreshAnalog >= ( 1000 / analogPollingRate ) ) {
//    subRoutine1();
    subfRefreshAnalog = millis();
  }

  if ( millis() - subfRefreshUltrasonic >= 1 ) {
//    subRoutine2();
    subfRefreshUltrasonic = millis();
  }
  
  if ( millis() - subfTestMotor >= 2000 ) {
    static int motorSpeed = 0;
    if ( motorSpeed >= 255 ) motorSpeed = 0; else motorSpeed += 55;
    if ( motorSpeed > 255 ) motorSpeed = 255;

    setMotorSpeed( motorSpeed, motorSpeed );
    subfTestMotor = millis();
  }
}
