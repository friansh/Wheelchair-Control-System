// Interrupt Functions

void motorEnableTriggered() {
  if ( millis() - lastMET  >= 500 ) {
    setMotorEnable( !L_MOTOR_ENABLED, !R_MOTOR_ENABLED );
    lastMET = millis();
  }
}

void motorSafetyTriggered() {
  if ( millis() - lastMST  >= 500 ) {
    setMotorSafety( !MOTOR_SAFETY );
    lastMST = millis();
  }
}
