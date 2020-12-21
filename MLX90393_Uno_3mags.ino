 
#include <Wire.h>
#include <MLX90393.h>

MLX90393 mlx1;
MLX90393 mlx2;
MLX90393 mlx3;
MLX90393::txyz data; //Create a structure, called data, of four floats (t, x, y, and z)


int GAIN = 7;
int RES_X = 0;
int RES_Y = 0;
int RES_Z = 0;
int OSR = 1;
int DIG_FILT = 3;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(100000);


  mlx1.begin(); //iic jumpers set  
  mlx1.setGainSel(GAIN);
  mlx1.setResolution(RES_X, RES_Y, RES_Z); //x, y, z
  mlx1.setOverSampling(OSR);
  mlx1.setDigitalFiltering(DIG_FILT);

  mlx2.begin(1,0); //iic jumpers set  
  mlx2.setGainSel(GAIN);
  mlx2.setResolution(RES_X, RES_Y, RES_Z); //x, y, z
  mlx2.setOverSampling(OSR);
  mlx2.setDigitalFiltering(DIG_FILT);

  mlx3.begin(0,1); //iic jumpers set  
  mlx3.setGainSel(GAIN);
  mlx3.setResolution(RES_X, RES_Y, RES_Z); //x, y, z
  mlx3.setOverSampling(OSR);
  mlx3.setDigitalFiltering(DIG_FILT);


}

void loop()
{
  
  mlx1.readData(data);
  //Serial.print("channel1:  ");
  Serial.println(String(millis())+ ", "+ data.x+","+data.y+","+data.z);

  mlx2.readData(data);
  //Serial.print("channel1:  ");
  Serial.println(String(millis())+ ", "+ data.x+","+data.y+","+data.z);

  mlx3.readData(data);
  //Serial.print("channel1:  ");
  Serial.println(String(millis())+ ", "+ data.x+","+data.y+","+data.z);
  //delay(500);

}
