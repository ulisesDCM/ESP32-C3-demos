idf_component_register(
        SRCS 
        "main.c"
        "ADC/adc.c"

        INCLUDE_DIRS 
        "."
        "ADC"
        REQUIRES
        "driver"
        )
