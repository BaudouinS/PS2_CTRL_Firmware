 #include <PS2X_lib.h>  //for v1.6 https://github.com/madsci1016/Arduino-PS2X  Bill Porter's library

/*
 * Baudouin SAINTYVES 06/15/2019
  PS2 Controler for 5 axis CAM and lighting
  
 // will be TRUE as long as button is pressed
    if(ps2x.Button(PSB_START))

 // this will set the large motor vibrate speed based on how hard you press the blue (X) button
    vibrate = ps2x.Analog(PSAB_BLUE);
    
 // will be TRUE if any button changes state (on to off, or off to on)
    if (ps2x.NewButtonState())

 // will be TRUE if button was JUST pressed
    if(ps2x.ButtonPressed(PSB_RED))
    
 // will be TRUE if button was JUST released
    if(ps2x.ButtonReleased(PSB_PINK))
   
 // this will set the large motor vibrate speed based on how hard you press the blue (X) button
 //vibrate = ps2x.Analog(PSAB_BLUE);
*/

// create PS2 Controller Class
PS2X ps2x;
int error = 0; 
byte type = 0;
byte vibrate = 0;
int St=0;
int Se=0;
int L3=0;
//int R1=0;
//int R2=0;
int R3=0;
int LZ=0;

void setup()
{
  Serial.begin(115200);//  monitor port
  Serial1.begin(115200);// light port
  Serial3.begin(115200);// 5 axis stage port

  // CHANGES for v1.6 HERE!!! **************PAY ATTENTION*************
  // setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  error = ps2x.config_gamepad(43,47,45,32, true, true);//UN0:(10,12,11,13, true, true); MEGA: (43,47,45,32, true, true);
//  if(error == 0)
//  {
//    Serial.println("Found Controller, configured successful");
//    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
//    Serial.println("holding L1 or R1 will print out the analog stick values.");
//    Serial.println("Go to www.billporter.info for updates and to report bugs.");
//  }
//  else if(error == 1)
//    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
//  else if(error == 2)
//    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
//  else if(error == 3)
//    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  Serial.print("E");Serial.print(error);
  Serial1.print("E");Serial1.print(error);
  Serial3.print("E");Serial3.print(error);

  // Serial.print(ps2x.Analog(1), HEX);
  type = ps2x.readType();
  switch(type)
  {
    case 0:
     // Serial.println("Unknown Controller type");
      Serial.print("T");Serial.println(type);
      Serial1.print("T");Serial.println(type);
      Serial3.print("T");Serial.println(type);
      break;
    case 1:
     // Serial.println("DualShock Controller Found");
      Serial.print("T");Serial.println(type);
      Serial1.print("T");Serial.println(type);
      Serial3.print("T");Serial.println(type);

      break;
   
  }
}

void loop()
{
  /*
    You must Read Gamepad to get new values
    Read GamePad and set vibration values
    ps2x.read_gamepad(small motor on/off, larger motor strenght from 0-255)
    if you don't enable the rumble, use ps2x.read_gamepad(); with no values
    you should call this at least once a second
  */
  // skip loop if no controller found
  if(error == 1)
    return; 
    

    // DualShock Controller
    // read controller and set large motor to spin at 'vibrate' speed
    ps2x.read_gamepad(false, vibrate);
    
    if(ps2x.ButtonPressed(PSB_START)){
      if (St==0){
            Serial.print("St");Serial.println(1);
            Serial3.print("St");Serial3.println(1);
            St=1;}
      else {Serial.print("St");Serial.println(0);
            Serial3.print("St");Serial3.println(0);
            St=0;}
      }
      
   
    if(ps2x.ButtonPressed(PSB_SELECT)){
      if (Se==0){
            Serial.print("Se");Serial.println(1);
            Serial1.print("Se");Serial1.println(1);
            Se=1;}
      else {Serial.print("Se");Serial.println(0);
            Serial1.print("Se");Serial1.println(0);
            Se=0;}
      }
    
    // will be TRUE as long as button is pressed
    if(ps2x.Button(PSB_PAD_UP))
    { Serial.println("U");
      Serial1.println("U");
      //Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
    }
    if(ps2x.Button(PSB_PAD_RIGHT))
    { Serial.println("Ri");
      Serial1.println("Ri");
      //Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
    }
    if(ps2x.Button(PSB_PAD_LEFT))
    { Serial.println("Le");
      Serial1.println("Le");
      //Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
    }
    if(ps2x.Button(PSB_PAD_DOWN))
    { Serial.println("D");
      Serial1.println("D");
      //Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
    }

    if(ps2x.Button(PSB_L1)){
      Serial.println("L1");
      Serial1.println("L1");}

    if(ps2x.Button(PSB_L2)){
      Serial.println("L2");
      Serial1.println("L2");}
    
    if(ps2x.Button(PSB_L3)){
      Serial.println("L3");
      Serial3.println("L3");
//      if (L3==0){
//            Serial.print("L3");Serial.println(1);
//            Serial3.print("L3");Serial3.println(1);
//            L3=1;}
//      else {Serial.print("L3");Serial.println(0);
//            Serial3.print("L3");Serial3.println(0);
//            L3=0;}
      }
   

//    if(ps2x.ButtonPressed(PSB_R1)){
//       if (R1==0){
//            Serial.print("R1");Serial.println(1);
//            Serial3.print("R1");Serial3.println(1);
//            R1=1;}
//      else {Serial.print("R1");Serial.println(0);
//            Serial3.print("R1");Serial3.println(0);
//            R1=0;}
//      }

//      if(ps2x.Button(PSB_R1)){      
//            Serial.println("R1");
//            Serial3.println("R1");
//      }
  
      
     // Serial.println("R1");
     // Serial3.println("R1");}
     
//    if(ps2x.ButtonPressed(PSB_R2)){
//       if (R2==0){
//            Serial.print("R2");Serial.println(1);
//            Serial3.print("R2");Serial3.println(1);
//            R2=1;}
//      else {Serial.print("R2");Serial.println(0);
//            Serial3.print("R2");Serial3.println(0);
//            R2=0;}
//      }

//      if(ps2x.Button(PSB_R2)){
//            Serial.println("R2");
//            Serial3.println("R2");
//      }
//      
      //Serial.println("R2");
      //Serial3.println("R2");}
    
   
     if(ps2x.ButtonPressed(PSB_R3)){
       if (R3==0){
            Serial.print("R3");Serial.println(1);
            Serial3.print("R3");Serial3.println(1);
            R3=1;}
      else {Serial.print("R3");Serial.println(0);
            Serial3.print("R3");Serial3.println(0);
            R3=0;}
      }   
    
//    
//    if(ps2x.Button(PSB_R3)){
//      Serial.println("R3");
//      Serial3.println("R3");}
      
    if(ps2x.Button(PSB_GREEN)){
      Serial.println("G");
      Serial3.println("G");}
    
    if(ps2x.Button(PSB_RED)){
      Serial.println("Re");
      Serial3.println("Re");}
      
    if(ps2x.Button(PSB_PINK)){
      Serial.println("P");
      Serial3.println("P");}

    if(ps2x.Button(PSB_BLUE)){
      Serial.println("B");
      Serial3.println("B");}

//
////////    /////Joysticks L
//// //   if (ps2x.Analog(PSS_LY)!=127 ||  ps2x.Analog(PSS_LX)!=128){
    Serial3.print("LX");
    Serial3.print(ps2x.Analog(PSS_LX), DEC);
    Serial3.print(";");
    Serial3.print("LY");
    Serial3.print(ps2x.Analog(PSS_LY), DEC); 
    Serial3.print(";");

    if(ps2x.Button(PSB_R1)){      
            Serial3.print("LZ0");
      } else if(ps2x.Button(PSB_R2)){
            Serial3.print("LZ255");
      } else {Serial3.print("LZ128");} 
    Serial3.println(";");
//    Serial.print("LX");
//    Serial.print(ps2x.Analog(PSS_LX), DEC);
//    Serial.print(";");
//    Serial.print("LY");
//    Serial.print(ps2x.Analog(PSS_LY), DEC); 
//    Serial.println(";");
////  }
////
////
//// /////Joysticks R
////  //  if (ps2x.Analog(PSS_RY)!=127 || ps2x.Analog(PSS_RX)!=128){
    Serial3.print("RX");
    Serial3.print(ps2x.Analog(PSS_RX), DEC); 
    Serial3.print(";");
    Serial3.print("RY");
    Serial3.print(ps2x.Analog(PSS_RY), DEC); 
    Serial3.println(";");
////   // }

 delay(50);
}
