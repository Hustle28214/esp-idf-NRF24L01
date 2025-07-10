#ifndef __NRF24L01_H__
#define __NRF24L01_H__


class NRF24L01
{
private:
    /* data */
public:
    NRF24L01(/* args */);
    ~NRF24L01();
    void CE_Pin_Write(uint8_t _ce_mode);
    void CSN_Pin_Write(uint8_t _csn_mode);
    void SCK_Pin_Write(uint8_t _sck);
    void MOSI_Pin_Write(uint8_t _mosi);
    void MISO_Pin_Read(void* args);
    void NRF24L01_GPIO_Config();
    void NRF24L01_SPI_SwapByte(uint8_t _swap_byte);
};



#endif