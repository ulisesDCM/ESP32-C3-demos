idf_component_register(SRCS "pushButton.c" "toogleLED.c" "main.c"
                    INCLUDE_DIRS "."
                    # REQUIRES esp_wifi
                    )

spiffs_create_partition_image(spiffs ../site/build FLASH_IN_PROJECT)