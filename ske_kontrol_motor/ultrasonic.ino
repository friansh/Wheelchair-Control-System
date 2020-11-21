// Ultrasonic Functions

float calculateSoundSpeed( float temperature ) {
  // 1.4 is adiabatic constant for air
  // 8.314 J/mol K is the universal gas constant
  // 28.95 gr/mol is the average molecular mass for dry air
  // source: http://hyperphysics.phy-astr.gsu.edu/hbase/Sound/souspe3.html#c1
  
  return sqrt( ( 1.4 * 8.314 * ( temperature + 273.15 ) ) / 0.028953  );
}

float measureDistance( int pin ) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);
  
  pinMode(pin, INPUT);
  long duration = pulseIn(pin, HIGH);

  float timeToBounce = ( 1000000.00 / ( speedOfSound * 100.00 ) );
  float distance = duration / timeToBounce / 2;
  
  Serial.print("[INFO] Measured range: ");
  Serial.print(distance);
  Serial.println("cm");

  return distance;
}
