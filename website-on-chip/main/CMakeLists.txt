idf_component_register(SRCS "pushButton.c" "toogleLED.c" "main.c"
                    INCLUDE_DIRS "."
                    )

spiffs_create_partition_image(spiffs ../site/build FLASH_IN_PROJECT)