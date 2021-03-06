void Show_FuelLevel() {

unsigned int top_bar = 9;
unsigned int bottom_bar = 56;
unsigned int current_bar = 56;
unsigned int bar_hight = 0;
// unsigned int last_bar = 39;
unsigned int current_liters = 0;
unsigned int full_tank_liters = 82;
String s_liters = "";
// Fuel
  
  current_liters = TankLevel1;
  bar_hight= ((double)bottom_bar - (double)top_bar)*(double)TankLevel1/(double)full_tank_liters;
  current_bar = bottom_bar - bar_hight;

  s_liters += current_liters;
  s_liters += "L";
 
  
  GLCD.SelectFont(newbasic3x5);
  GLCD.CursorToXY(0, 0);
  GLCD.print(s_liters);


  GLCD.FillRect(2,top_bar,6,bottom_bar - top_bar,WHITE);
  GLCD.FillRect(2,current_bar,6,bar_hight);

}


void Show_FuelFlow() {
// Flow
  GLCD.SelectFont(newbasic3x5);
  GLCD.CursorToXY(18, 24);
  GLCD.print("FL 20.4 / 20.0");
  GLCD.CursorToXY(18, 32);
  GLCD.print("E 03:10 / 03:20");
}


void Show_FuelPressure() {

// this is normal fuel pressure range
unsigned int FPressMin = 5; //30% of the bottom scale kPa
unsigned int FPressMax = 20; //20% of the upper scale kPa

unsigned int AbsMax;
unsigned int BarFull = 45; //full scale is 45 pix
unsigned int BarMin = 11; //lower range from zero to TempMin is 11 pix
unsigned int BarMax = 21; //upper range above TempMax is 6 pix
int BarLength = 0;
AbsMax = FPressMax / 0.8;


//bar length 
if (FuelPressure <= FPressMin) {
  BarLength = (float)BarMin * (float)FuelPressure/(float)FPressMin;
} 

if (FuelPressure > FPressMin and OilTemperature < FPressMax) {
  BarLength = BarMin + (BarMax - BarMin) * (FuelPressure - FPressMin)/(FPressMax - FPressMin);
} 

if (FuelPressure > FPressMax) {
  BarLength = BarMax + (BarFull - BarMax) * (FuelPressure - FPressMax)/(AbsMax - FPressMax);
} 

if (BarLength > BarFull) {
  BarLength = BarFull;
}


//   GLCD.DrawRect(35,43,46,11);

   GLCD.FillRect(36,59,BarFull-1,3, WHITE);
   GLCD.FillRect(36,59,BarLength,3);
 //  GLCD.DrawLine(47, 52, 47, 50); // Green Temp Min   
 //  GLCD.DrawLine(67, 52, 67, 50); // Green Temo Max   

  
// Pressure
//   GLCD.DrawRect(35,57,46,7);
//   GLCD.FillRect(36,59,22,3);


// markers
     GLCD.DrawLine(47, 63, 47, 60); // Green Pressure Min   
     GLCD.DrawLine(67, 63, 67, 60); // Green Pressure Max 
  
  
}
