#include <stm32f4xx_hal.h>


HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef * /*pEraseInit*/, uint32_t * /*SectorError*/)
{
    return HAL_ERROR;
}
