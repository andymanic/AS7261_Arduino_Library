/*
  This is a library written for the AS726X Spectral Sensor (Visible or IR) with I2C firmware
  specially loaded. SparkFun sells these at its website: www.sparkfun.com

  Written by Nathan Seidle & Andrew England @ SparkFun Electronics, July 12th, 2017

  https://github.com/sparkfun/Qwiic_Spectral_Sensor_AS726X

  Do you like this library? Help support SparkFun. Buy a board!

  Development environment specifics:
  Arduino IDE 1.8.1

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.


  ---AVAILABLE FUNCTIONS---
  AS726X(TwoWire &wirePort = Wire, byte gain = 3, byte measurementMode = 3);
  void takeMeasurements();
  void takeMeasurementsWithBulb();
  void printMeasurements();
  byte getTemperature();
  float getTemperatureF();
  void setMeasurementMode(byte mode);
  boolean dataAvailable();
  void enableIndicator();
  void disableIndicator();
  void setIndicatorCurrent(byte current);
  void enableBulb();
  void disableBulb();
  void setBulbCurrent(byte current);
  void softReset();
  void setGain(byte gain);
  void setIntegrationTime(byte integrationValue);
  void enableInterrupt();
  void disableInterrupt();

  //Get the various color readings
  int getX();
  int getY();
  int getZ();
  int getNIR();
  int getDark();
  int getClear();

  //Returns the various calibration data
  float getCalibratedX();
  float getCalibratedY();
  float getCalibratedZ();
  float getCalibratedNIR();
  float getCalibratedDark();
  float getCalibratedClear();

*/

#include "AS726X.h"

AS726X sensor;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  
  sensor.begin();
}

void loop() {
  sensor.takeMeasurements();
  //Prints all measurements
  
    //Visible readings
    Serial.print(" Reading: V[");
    Serial.print(sensor.getCalibratedX(), 2);
    Serial.print("] B[");
    Serial.print(sensor.getCalibratedY(), 2);
    Serial.print("] G[");
    Serial.print(sensor.getCalibratedZ(), 2);
    Serial.print("] Y[");
    Serial.print(sensor.getCalibratedNIR(), 2);
    Serial.print("] O[");
    Serial.print(sensor.getCalibratedDark(), 2);
    Serial.print("] R[");
    Serial.print(sensor.getCalibratedClear(), 2);
  

  Serial.print("] tempC[");
  Serial.print(sensor.getTemperature(), 1);
  Serial.print("]");

  Serial.println();
}
