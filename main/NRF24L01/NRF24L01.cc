#include <driver/gpio.h>
#include <stdio.h>
#include <string.h>
#include <driver/spi_common.h>
#include <driver/spi_slave.h>
#include "esp_flash_spi_init.h"
#include "esp_flash.h"
#include <driver/spi_master.h>
#include "NRF24L01.h"
#include "config.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

NRF24L01::NRF24L01(/* args */)
{
}

NRF24L01::~NRF24L01()
{
}

void NRF24L01::CE_Pin_Write(uint8_t _ce_mode){
    /**
     * Function: Write CE Pin with high or low level
     * Args: CE pin mode, 0/1
     * ReturnValue : none
     * Illustration: none
     */
    gpio_set_level(NRF24L01_CE_PIN,_ce_mode);
}

void NRF24L01::CSN_Pin_Write(uint8_t _csn_mode){
    /**
    * Function: Write CSN Pin with high or low level
    * Args: CSN pin mode, 0/1
    * ReturnValue : none
    * Illustration: none
    */
    gpio_set_level(NRF24L01_CSN_PIN,_csn_mode);
}

void NRF24L01::SCK_Pin_Write(uint8_t _sck){
    /**
    * Function: Write SCK Pin with high or low level
    * Args: SCK pin mode, 0/1
    * ReturnValue : none
    * Illustration: none
    */
    gpio_set_level(NRF24L01_SCK_PIN,_sck);
}

void NRF24L01::MOSI_Pin_Write(uint8_t _mosi){
    gpio_set_level(NRF24L01_MOSI_PIN,_mosi);
}

void NRF24L01::MISO_Pin_Read(void* args){
    gpio_get_level(NRF24L01_MISO_PIN);
}



void NRF24L01::NRF24L01_GPIO_Config(){
    // esp_flash_spi_device_config_t spi_cfg = {
    //     .host_id = NRF24L01_SPI_BUS_NUM,
    //     .cs_io_num = NRF24L01_CE_PIN_NUM,
    //     .io_mode = SPI_FLASH_DIO,
    //     .input_delay_ns = 0,
    //     .freq_mhz = 50,        
    // };
    gpio_config_t NRF24L01_io_cfg = {
        .pin_bit_mask = (1ULL << NRF24L01_MOSI_PIN_NUM) | (1ULL << NRF24L01_CE_PIN_NUM) | (1ULL << NRF24L01_CSN_PIN_NUM) | (1ULL << NRF24L01_SCK_PIN_NUM),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    ESP_ERROR_CHECK(gpio_config(&NRF24L01_io_cfg));

    CE_Pin_Write(0);
    CSN_Pin_Write(1);
    SCK_Pin_Write(0);
    MOSI_Pin_Write(0);
}

void NRF24L01::NRF24L01_SPI_SwapByte(uint8_t _swap_byte){

}
