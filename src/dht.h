#include "hwlib.hpp"

class dht11
{
private:

    hwlib::pin_oc& pin;

public:
								// Public variables to store specific sensor data.
    int humidity;
    int temperature;			

    dht11(hwlib::pin_oc& pin)
        : pin(pin)
    {
		pin.write(1); 			// Datasheet states that we need to send a start signal. 
    }

    uint8_t read_dht11_byte() 	// Function to read one byte from DHT11.
    {
	
	uint8_t result = 0;			// Variable for saving byte of data.

	for(unsigned int i = 0; i < 8; i++) {

	    while(!pin.read()) 		// Wait forever till pin is '1'.
		; 

	    hwlib::wait_us(30); 	// Datasheet states we need to wait between 20-40 us, 30us to be safe.

	    result <<= 1; 			// Shift bits one space (left).
 
	    if(pin.read())			// If pin is still '1' after 30us.

			result |= 1; 		// Make lowest bit '1'.

	    while(pin.read()); 		// Wait for pin to be '0'.
	}
	return result; 				// Return result.
    }



    void get_data(){	// Function to read the 5 bytes sent by the sensor of which the first (integral RH data) and 
						// third (integral T data) byte contain data which are stored for later usage.  
    					// If the high pulse is ~28 microseconds then it's a 0 and if it's ~70 microseconds
    					// then it's a 1. (This can be visualized by using a logic analyzer.)

	pin.write(0); 		// Pull down pin for 25ms.
	
	hwlib::wait_ms(25);
	
	pin.write(1); 		// Pull down pin for 60us. 
	
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
			temperature = read_dht11_byte();	// Store first byte in variabel "Temperature"	
		else
			read_dht11_byte();
	}
  }
};
