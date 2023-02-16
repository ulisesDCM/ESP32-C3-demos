idf_component_register(
        SRCS            #Define here the path for the source files.
        "myGPIO.c"
        INCLUDE_DIRS    # Define here the path for the include files (headers).
        "."
        REQUIRES        # Define here the esp-idf components.
        "driver"
        )
