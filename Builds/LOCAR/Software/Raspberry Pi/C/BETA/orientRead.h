/*
 * Supposedly reorients readings. For now, it only stores readings into an array.
 */

#include <wiringPi.h>

// Array that will house the smoothed RAW sensor orientation adjusted readings, for printing.
double RAW[NSENS][NAXES] = {0};

void orientRead( uint8_t pair )
{
	// No orientation attempt has been made. RHR is not enforced.
	// Single Exponential Smoothing has been implemented.
	uint8_t n_HI = (pair - 1) * 2;
	uint8_t n_LO = (2 * pair) - 1;
	
	// HI sensors:
	RAW[n_HI][0] = ema_filter( double( imuHI.calcMag(imuHI.mx) ), n_HI, 0);
	RAW[n_HI][1] = ema_filter( double( imuHI.calcMag(imuHI.my) ), n_HI, 1);
	RAW[n_HI][2] = ema_filter( double( imuHI.calcMag(imuHI.mz) ), n_HI, 2);
	
	// LO Sensors:
	RAW[n_LO][0] = ema_filter( double( imuLO.calcMag(imuLO.mx) ), n_LO, 0);
	RAW[n_LO][1] = ema_filter( double( imuLO.calcMag(imuLO.my) ), n_LO, 1);
	RAW[n_LO][2] = ema_filter( double( imuLO.calcMag(imuLO.mz) ), n_LO, 2);
}

// ===================    ReOrient Readings       ===================
//This is an example for a setup whereby the sensor outputs are corrected to match the right hand rule.

//void orientRead(int pair) {
//  // The sensors need to output data along a consistent Coordinate System; all "x-components" point in the same direction.
//  // The XYZ coordinate system we're imposing is defined EXTERNALLY by the designer.
//  // Sensor orientations have, hence, been predefined; when they change this has to as well.
//
//  switch (pair) {
//    case 1:
//      //Sensor 1: mz -> X, -mx -> Y, my -> Z
//      RAW[0][0] = double( high.calcMag(high.mz) );
//      RAW[0][1] = -1 * double( high.calcMag(high.mx) );
//      RAW[0][2] = double( high.calcMag(high.my) );
//
//      //Sensor 2: mz -> X, -mx -> Y, my -> Z
//      RAW[1][0] = double( low.calcMag(low.mz) );
//      RAW[1][1] = -1 * double( low.calcMag(low.mx) );
//      RAW[1][2] = double( low.calcMag(low.my) );
//      break;
//
//    case 2:
//      //Sensor 3: mz -> X, my -> Y, mx -> Z
//      RAW[2][0] = double( high.calcMag(high.mz) );
//      RAW[2][1] = double( high.calcMag(high.my) );
//      RAW[2][2] = double( high.calcMag(high.mx) );
//
//      //Sensor 4: mz -> X, -my -> Y, -mx -> Z
//      RAW[3][0] = double( low.calcMag(low.mz) );
//      RAW[3][1] = -1 * double( low.calcMag(low.my) );
//      RAW[3][2] = -1 * double( low.calcMag(low.mx) );
//      break;
//
//    case 3:
//      //Sensor 5: mz -> X, mx -> Y, -my -> Z
//      RAW[4][0] = double( high.calcMag(high.mz) );
//      RAW[4][1] = double( high.calcMag(high.mx) );
//      RAW[4][2] = -1 * double( high.calcMag(high.my) );
//
//      //Sensor 6: mz -> X, mx -> Y, -my -> Z
//      RAW[5][0] = double( low.calcMag(low.mz) );
//      RAW[5][1] = double( low.calcMag(low.mx) );
//      RAW[5][2] = -1 * double( low.calcMag(low.my) );
//      break;
//
//    default:
//      Serial.print( F("Error. This sensor pair doesn't exist!") );
//      while (1);
//      break;
//  };
//}
