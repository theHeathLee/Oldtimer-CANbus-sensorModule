# Oldtimer-CANbus-Box

This is a device to read vital engine information and broadcast it on a CAN bus network.

The following will be impimented

- motor temperature
- carburetor vacuum
- rpm from distributer
- fuel flow
s

## Reference Projects:

[Carburetor Vacuum Guage](https://www.instructables.com/id/DIY-Digital-Vacuum-Gauge/)

[Motor RPM from Ignition Coil](https://www.chippernut.com/shift-light-v31.html#/)

[Motor RPM Code](https://github.com/chippernut/ShiftlightV_31/blob/master/ShiftLightV3_11.ino)

## Hardware:

[Arduino Nano - Main Controller](https://store.arduino.cc/arduino-nano)

[MCP 2515 - CAN BUS Tranceiver](http://henrysbench.capnfatz.com/henrys-bench/arduino-projects-tips-and-more/arduino-can-bus-module-pin-outs-and-schematics/)

[MAX6675 - CHT Temperature](https://de.banggood.com/MAX6675-Sensor-Module-Thermocouple-Cable-1024-Celsius-High-Temperature-Available-p-1086406.html?gmcCountry=DE&currency=EUR&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgcs&utm_content=garman&utm_campaign=pla-deg-ele-pc&gclid=Cj0KCQjwitPnBRCQARIsAA5n84l_m2LucaqTAD_XRxMBzMbeXdLC7jNOUG5H9TpO2s92qSuOHLTqlHIaAnfCEALw_wcB&cur_warehouse=CN)

[MPXH6250AC6U - Carburetor Vacuum Sensor](https://de.rs-online.com/web/p/absolutdruck-sensoren-ics/8212428/?relevancy-data=636F3D3126696E3D4931384E525353746F636B4E756D626572266C753D656E266D6D3D6D61746368616C6C26706D3D5E2828282872737C5253295B205D3F293F285C647B337D5B5C2D5C735D3F5C647B332C347D5B705061415D3F29297C283235285C647B387D7C5C647B317D5C2D5C647B377D2929292426706F3D3126736E3D592673723D2673743D52535F53544F434B5F4E554D4245522677633D4E4F4E45267573743D38323132343238267374613D3832313234323826&searchHistory=%7B%22enabled%22%3Atrue%7D)




## libraries:

[MCP CAn - CAN Bus](https://github.com/coryjfowler/MCP_CAN_lib)

[MAX6675 Adafruti - Temperature](https://github.com/adafruit/MAX6675-library)
