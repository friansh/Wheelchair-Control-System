// Subroutine 1

void subRoutine1() {
    int X = (analogRead( ANALOG_X ) - ANALOG_X_CENTER) / 2;
    int Y = (analogRead( ANALOG_Y ) - ANALOG_Y_CENTER) / 2;
      
    // Clipping operation
    if ( X > 255 ) X = 255;
    if ( Y > 255 ) Y = 255;
    if ( X < -255 ) X = -255;
    if ( Y < -255 ) Y = -255;

    long A;
    long B;
    Serial.print("[INFO] ");
    // Center Point
    if ( ( X > -ZERO_THRESHOLD && X < ZERO_THRESHOLD ) && ( Y > -ZERO_THRESHOLD && Y < ZERO_THRESHOLD ) ) {
      Serial.print("CENTER POINT\t");
      printPoint(X, Y, A, B);
      A = 0;
      B = 0;
    }
    
    //PRECISE NORTH
    if ( ( X > -ZERO_THRESHOLD && X < ZERO_THRESHOLD ) && Y >= ZERO_THRESHOLD ) {
      Serial.print("PRECISE NORTH\t");
      printPoint(X, Y, A, B);
      setMotorDirection(true, true);
      A = Y;
      B = Y;
    }

    //PRECISE EAST
    if ( X >= ZERO_THRESHOLD && ( Y > -ZERO_THRESHOLD && Y <= ZERO_THRESHOLD ) ) {
      Serial.print("PRECISE EAST\t");
      printPoint(X, Y, A, B);
      setMotorDirection(true, true);
      A = X;
      B = 0;
    }

    //PRECISE SOUTH
    if ( ( X > -ZERO_THRESHOLD && X < ZERO_THRESHOLD ) && Y <= -ZERO_THRESHOLD ) { 
      Serial.print("PRECISE SOUTH\t");
      printPoint(X, Y, A, B);
      setMotorDirection(false, false);
      A = -Y;
      B = -Y;
    }

    //PRECISE WEST
    if ( X <= -ZERO_THRESHOLD && ( Y > -ZERO_THRESHOLD && Y < ZERO_THRESHOLD ) ) {
      Serial.print("PRECISE WEST\t");
      printPoint(X, Y, A, B);
      setMotorDirection(true, true);
      A = 0;
      B = -X;
    }

    //QUADRANT 1
    if ( X > ZERO_THRESHOLD && Y > ZERO_THRESHOLD) {
      Serial.print("QUADRANT 1\t");
      printPoint(X, Y, A, B);
      setMotorDirection(true, true);
      A = map(sqrt(pow((0 - X), 2) + pow((0 - Y), 2)), 0, 361, 0, 255);
      B = map(sqrt(pow((255 - X), 2) + pow((0 - Y), 2)), 0, 361, 0, 255);
    }

    //QUADRANT 2
    if ( X > ZERO_THRESHOLD && Y < -ZERO_THRESHOLD) {
      Serial.print("QUADRANT 2\t");
      printPoint(X, Y, A, B);
      setMotorDirection(false, false);
      A = map(sqrt(pow((0 - X), 2) + pow((0 - Y), 2)), 0, 361, 0, 255);
      B = map(sqrt(pow((255 - X), 2) + pow((0 - Y), 2)), 0, 361, 0, 255);
    }

    //QUADRANT 3
    if ( X < -ZERO_THRESHOLD && Y < -ZERO_THRESHOLD) {
      Serial.print("QUADRANT 3\t");
      printPoint(X, Y, A, B);
      setMotorDirection(false, false);
      A = map(sqrt(pow((-255 - X), 2) + pow((0 - Y), 2)), 0, 361, 0, 255);
      B = map(sqrt(pow((0 - X), 2) + pow((0 - Y), 2)), 0, 361, 0, 255);
    }

    //QUADRANT 4
    if ( X < -ZERO_THRESHOLD && Y > ZERO_THRESHOLD) {
      Serial.print("QUADRANT 4\t");
      printPoint(X, Y, A, B);
      setMotorDirection(true, true);
      A = map(sqrt(pow((-255 - X), 2) + pow((0 - Y), 2)), 0, 361, 0, 255);
      B = map(sqrt(pow((0 - X), 2) + pow((0 - Y), 2)), 0, 361, 0, 255);
    }
   
    setMotorSpeed(A, B);
}

void printPoint(int X, int Y, int A, int B) {
    Serial.print(" X: ");
    Serial.print(X);
    Serial.print("\tY: ");
    Serial.print(Y);
    Serial.print("\tA: ");
    Serial.print(A);
    Serial.print("\tB: ");
    Serial.println(B);
}
