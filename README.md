# ESP32-C3 DevKit. 
Author: Ulises

## About:


## Project list:
#### 1. ADC
#### 2. basic FreeRTOS
#### 3. Blink
#### 4. Custom configuration
#### 5. DAC
#### 6. deep sleep EXT1
#### 7. deep sleep EXT0
#### 8. deep sleep TIMER
#### 9. GPIO
#### 10. HALL-Sensor
#### 11. Hibernation.
#### 12. I2C LM75A
#### 13. include lib example
#### 14. Key board input
#### 15. Light Sleep GPIO
#### 16. Light sleep Timer
#### 17. NTP Time
#### 18. PWM
#### 19. REST client simple GET
#### 20. Simple Server
#### 21. SPI Display
#### 22. SPI SSDCard
#### 23. UART Echo
#### 24. UART queue
#### 25. Website on chip
#### 26. Wifi connection lib
#### 27. wifi example connection
#### 28. wifi scanner

## Menuconfig
    idf.py menuconfig
    
## Solving intellisense problems with vscode and IDF
    Sintax error highlight fix
    1. Go to .vscode/settings.json and change the "C_Cpp.intelliSenseEngine" 
    configuration from 'Tag Parser' to 'Default'
    
    Intellisense fix
    Re-open the vscode and click 'Yes' on the message 'Would you like to use a compile_json file to autoconfigure...'
    and choose the first one '../build/compile_commands.json

    note: if the message does not appear, open the c_cpp_properties.json file  and add
        "compileCommands": "${workspaceFolder}/build/compile_commands.json" line
    after the 'browser' inside in 'configurations'
    


    