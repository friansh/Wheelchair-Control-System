// Motor Functions

void setMotorSpeed( int leftMotor, int rightMotor ) {
  leftMotorSpeed = leftMotor;
  analogWrite( L_MOTOR_PWM, leftMotor );
  rightMotorSpeed = rightMotor;
  analogWrite( R_MOTOR_PWM, rightMotor );

  Serial.print( "[CONF] Motor speed is set to R:" );
  Serial.print( leftMotor );
  Serial.print( " and L:");
  Serial.println( rightMotor );
}

void setMotorDirection( bool leftMotor, bool rightMotor ){
  if ( leftMotor ) {
    digitalWrite( L_MOUT1, HIGH );
    digitalWrite( L_MOUT2, LOW );
    Serial.print("[CONF] Motor direction is set to L:Forward ");
  } else {
    digitalWrite( L_MOUT1, LOW );
    digitalWrite( L_MOUT2, HIGH );
    Serial.print("[CONF] Motor direction is set to L:Backward");
  }

  if ( rightMotor ) {
    digitalWrite( R_MOUT1, HIGH );
    digitalWrite( R_MOUT2, LOW );
    Serial.println(" and R:Forward");
  } else {
    digitalWrite( R_MOUT1, LOW );
    digitalWrite( R_MOUT2, HIGH );
    Serial.println(" and R:Backward");
  }
}

void setMotorEnable( bool leftMotor, bool rightMotor ){
  if (leftMotor) {
      digitalWrite( L_ENABLE_1, HIGH );
      digitalWrite( L_ENABLE_2, HIGH );
      L_MOTOR_ENABLED = true;
      Serial.println("[CONF] Left motor driver control enabled");
      
  } else {
      digitalWrite( L_ENABLE_1, LOW );
      digitalWrite( L_ENABLE_2, LOW );
      L_MOTOR_ENABLED = false;
      Serial.println("[CONF] Left motor driver control disabled");
  }

  if (rightMotor) {
      digitalWrite( R_ENABLE_1, HIGH );
      digitalWrite( R_ENABLE_2, HIGH );
      R_MOTOR_ENABLED = true;
      Serial.println("[CONF] Right motor driver control enabled");
  } else {
      digitalWrite( R_ENABLE_1, LOW );
      digitalWrite( R_ENABLE_2, LOW );
      R_MOTOR_ENABLED = false;
      Serial.println("[CONF] Right motor driver control disabled");
  }
}

void setMotorSafety( bool safety ) {
  digitalWrite( L_SAFETY, !safety );
  digitalWrite( R_SAFETY, !safety );
  MOTOR_SAFETY = safety;
  
  if (safety)
    Serial.println("[CONF] Motor safety mechanism has turned on");
   else
    Serial.println("[CONF] Motor safety mechanism has turned off");
}
