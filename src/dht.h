#include "hwlib.hpp"
/// @file 


class dht11
{
private:

    hwlib::pin_oc& pin;
	bool temp_fahrenheit = false; 

public:
								// Public variables to store specific sensor data.
    int humidity;				
    int temperature_f;
	int temperature_c;			
								/// \brief
								/// Constructor that creates an DHT11 instance, from an open collector pin.
								
    dht11(hwlib::pin_oc& pin)
        : pin(pin)
    {
		pin.write(1); 			// Datasheet states that we need to send a start signal. 
    }
								/// \brief
    						 	/// Function to read one byte from DHT11.
								/// \details
								/// This functions purpose is to read one byte from the sensor
								/// and saving it into the result variabel.
	uint8_t read_dht11_byte() 
    {
	
	uint8_t result = 0;			// Variable for saving byte of data.

	for(unsigned int i = 0; i < 8; i++) {

	    while(!pin.read()) 		// Wait forever till pin is '1'.
		; 

	    hwlib::wait_us(30); 	// Datasheet states we need to wait between 20-40 us, 30us to be safe.

	    result <<= 1; 			
 
	    if(pin.read())			// If pin is still '1' after 30us.

			result |= 1; 		

	    while(pin.read()); 		// Wait for pin to be '0'.
	}
	return result; 				
    }


						/// \brief 
						///	Read five bytes send by the sensor.
						/// \details 
    					/// Function to read the 5 bytes sent by the sensor of which the first (integral RH data) and 
						/// third (integral T data) byte contain data which are stored for later usage.  
    					/// If the high pulse is ~28 microseconds then it's a 0 and if it's ~70 microseconds
    					/// then it's a 1. (This can be visualized by using a logic analyzer.)
	void get_data(){
	
	int temperature; 

	pin.write(0); 		
	hwlib::wait_ms(25);
	pin.write(1); 		
	
	hwlib::wait_us(60);

						// First expect a low signal for ~80 microseconds followed by a high signal
    					// for ~80 microseconds again.

	if(pin.read()) {
	    				// Wait for first response: Low.
	    return;
	}
	hwlib::wait_us(80);

	if(!pin.read()) { 
						// Wait for second response: High.
	    return;
	}

	hwlib::wait_us(80); // After 80us wait, ready for data reception.

	for(unsigned int i = 0; i < 5; i++)
	{

		if (i == 0)
			humidity = read_dht11_byte(); 		// Store first byte in variabel "humidity"
		else if (i == 2)
			{
				temperature = read_dht11_byte();  				// Store third byte in variabel "Temperature_c"	
				// temperature_f = (read_dht11_byte() * 1.8 + 32);  	// Store third byte in variabel "Temperature_f"	
			}
			 		
		else
			read_dht11_byte();
	}
	temperature_c = temperature; 
	temperature_f = temperature * 1.8 + 32;
  }


						/// \brief 
						/// function to get temperature in either fahrenheit or celcius.
  int get_temperature()		
  {
	if (temp_fahrenheit)
		return temperature_f;

	return temperature_c; 
  }
						/// \brief
						/// function to set string to right scale.
  const char* get_temperature_scale()
  {
	  if (temp_fahrenheit)
	  	return " Fahrenheit";
	  return " Celcius";
  }	
						/// \brief
						/// boolean function to set wether u want to use fahrenheit or celcius.
  void set_fahrenheit(bool F)
  {
	  temp_fahrenheit = F; 
  }
};

