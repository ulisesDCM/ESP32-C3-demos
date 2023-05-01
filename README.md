# ESP32-C3 DevKit. 
Author: Ulises

## About:


## Project list:


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
    


    