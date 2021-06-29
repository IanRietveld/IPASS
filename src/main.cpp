#include "dht.h"
#include "hwlib.hpp"

//*
// BUTTON STATE: 0, displays temperature.
// BUTTON STATE: 1, displays humidity.
//*

int main()
{
    hwlib::wait_ms(2000);

    auto scl_oled = hwlib::target::pin_oc(hwlib::target::pins::d9);             // Pin definition, Oled clock.
    auto sda_oled = hwlib::target::pin_oc(hwlib::target::pins::d10);            // Pin definition, Oled data.
    auto sda_dht = hwlib::target::pin_oc(hwlib::target::pins::d2);              // Pin definition, DHT11 data.

    auto scl_button = hwlib::target::pin_oc(hwlib::target::pins::d7);           // Pin definition, Button.

    auto relais = hwlib::target::pin_out(hwlib::target::pins::d6);              // Pin definition, Relais.

    auto scl_red_led = hwlib::target::pin_out(hwlib::target::pins::d5);         // Pin definition, Red LED.
    auto scl_green_led = hwlib::target::pin_out(hwlib::target::pins::d4);       // Pin definition, Green LED.

    auto i2c_bus_oled = hwlib::i2c_bus_bit_banged_scl_sda(scl_oled, sda_oled);  // I2C bus, Oled.
    auto oled = hwlib::glcd_oled(i2c_bus_oled, 0x3c);                           // Oled Adress.

    auto font = hwlib::font_default_8x8();                                      // Oled font, small letters.
    auto font_big = hwlib::font_default_16x16();                                // Oled font, big letters.
    auto display = hwlib::terminal_from(oled, font); 

    dht11 dht11(sda_dht);
    dht11.set_fahrenheit(true);                                                 // If user wants Fahrenheit scale, set this function to "true".
                                                                                // for Celsius "false".
    while(true)
    {
        
        dht11.get_data();
        int temperature = dht11.get_temperature();
        const char* scale = dht11.get_temperature_scale();
            // **********************************************************
                                                                                // Uncomment till "***" to let display switch between temperature and humidity every x seconds.

            display << "\f"
                    << "   Humidity "
                    << "\n"
                    << "\n"
                    << "    Level:"
                    << "\n"
                    << "\n"
                    << "\n"
                    << "\n"
                    << "\n"
                    << "      " << dht11.humidity << " %"
                    << "\n"
                    << hwlib::flush;

        hwlib::wait_ms(2000);


	    display << "\f"
	            << "    Current"
	            << "\n"
	            << "\n"
	            << "  Temperature: "
	            << "\n"
	            << "\n"
	            << "\n"
	            << "\n"
	            << "\n"
	            << "   " << temperature << scale
	            << "\n"
	            << hwlib::flush;
        hwlib::wait_ms(2000);
              
	    

              

        // **********************************************************

        // ----------------------------------------------------------
                                                                                    // Uncomment till "---" to press a button for displaying humidity, default is temperature.

    //     if(scl_button.read()) {
    //         scl_button.write(0);
    //         display << "\f"
    //                 << "   Humidity "
    //                 << "\n"
    //                 << "\n"
    //                 << "    Level:"
    //                 << "\n"
    //                 << "\n"
    //                 << "\n"
    //                 << "\n"
    //                 << "\n"
    //                 << "      " << dht11.humidity << " %"
    //                 << "\n"
    //                 << hwlib::flush;

    //         hwlib::cout << "Button state: " << scl_button.read() << "\n";
	//   } 
    // else 
    // {

	//     display << "\f"
	//             << "    Current"
	//             << "\n"
	//             << "\n"
	//             << "  Temperature: "
	//             << "\n"
	//             << "\n"
	//             << "\n"
	//             << "\n"
	//             << "\n"
	//             << "   " << dht11.temperature << " Celcius"
	//             << "\n"
	//             << hwlib::flush;
              
	//     hwlib::cout << "Button state: "<< scl_button.read() << "\n";
      
	// }

    // ----------------------------------------------------------

                                                                // Temperature has to be in set range for specific animal needs, 
                                                                // if temp within positive range a green LED will turn on. 
                                                                // If this is not the case, a red LED will turn on.
	    						                                // **This is also where u can set the temperature or humidity conditions
	    						                                //   for the "relais"**
    if(dht11.temperature_c <= 30 && dht11.temperature_c >= 20)
	{
		scl_green_led.write(1);
        	relais.write(1);
        } 
	    
        else if(dht11.temperature_c < 20)
	{
		relais.write(1);
	}
	else
        {
	  	scl_red_led.write(1);
        	relais.write(0);
        }


    hwlib::cout << "Current humidity = " << dht11.humidity << "%" << hwlib::endl;

    hwlib::cout << "Current temperature = " << dht11.temperature_c << " degrees Celcius" << hwlib::endl;

    hwlib::wait_ms(1000);

    hwlib::cout << "\n"
	            << "Fresh data below:" 
                << "\n"
                << hwlib::endl;
    }
}
