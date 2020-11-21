# Wheelchair Control System
This is a program for managing controls for the automated wheelchair developed by LIPI designed to run on Arduino Mega 2560. The purpose for making this firmware is to accomplish the Electronic Control System subject for undergraduate student at Universitas Padjadjaran's electrical engineering major.

The sensor can be used in this program are XY Axis controller with potentiometer based and ultrasonic ping sensor yet. For future development we hope this program can read from bluetooth module, IMU sensors, LIDAR, and connection with Intel NUC. This program is created by <b>Fikri Rida Pebriansyah</b> with student number <b>140910170023</b>.
Then, the pinout for the system is shown below:
<table>
  <tr>
    <td><b>Purpose</b></td>
    <td><b>Arduino Mega's Pin</b></td>
    <td><b>Detail</b></td>
  </tr>
  <tr>
    <td>Left Motor Output 1</td>
    <td>28</td>
    <td>Motor driver pin 1</td>
  </tr>
  <tr>
    <td>Left Motor Output 2</td>
    <td>30</td>
    <td>Motor driver pin 2</td>
  </tr>
  <tr>
    <td>Left Motor Enable 1</td>
    <td>32</td>
    <td>Motor driver pin 3</td>
  </tr>
  <tr>
    <td>Left Motor Enable 2</td>
    <td>37</td>
    <td>Motor driver pin 4</td>
  </tr>
  <tr>
    <td>Left Motor PWM Signal</td>
    <td>7</td>
    <td>Motor driver pin 6</td>
  </tr>
  <tr>
    <td>Right Motor Output 1</td>
    <td>29</td>
    <td>Motor driver pin 1</td>
  </tr>
  <tr>
    <td>Right Motor Output 2</td>
    <td>31</td>
    <td>Motor driver pin 2</td>
  </tr>
  <tr>
    <td>Right Motor Enable 1</td>
    <td>33</td>
    <td>Motor driver pin 3</td>
  </tr>
  <tr>
    <td>Right Motor Enable 2</td>
    <td>35</td>
    <td>Motor driver pin 4</td>
  </tr>
  <tr>
    <td>Right Motor PWM Signal</td>
    <td>10</td>
    <td>Motor driver pin 6</td>
  </tr>
  <tr>
    <td>Left and Right Motor Safety Trigger</td>
    <td>2</td>
    <td>Switch mechanism, connected to interrupt</td>
  </tr>
  <tr>
    <td>Analog X Axis</td>
    <td>A3</td>
    <td>Module X pin</td>
  </tr>
  <tr>
    <td>Analog Y Axis</td>
    <td>A4</td>
    <td>Module Y pin</td>
  </tr>
  <tr>
    <td>Analog Button Axis</td>
    <td>3</td>
    <td>Module B pin, connected to interrupt</td>
  </tr>
  <tr>
    <td>Left Ultrasonic Front-Faced</td>
    <td>7</td>
    <td>Single pin ping</td>
  </tr>
  <tr>
    <td>Right Ultrasonic Front-Faced</td>
    <td>8</td>
    <td>Single pin ping</td>
  </tr>
</table>
