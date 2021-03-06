#include <stm32f4xx_hal.h>


HAL_StatusTypeDef HAL_RTC_GetTime(RTC_HandleTypeDef * /*hrtc*/, RTC_TimeTypeDef * /*sTime*/, uint32_t /*Format*/)
{
    return HAL_OK;
}


HAL_StatusTypeDef HAL_RTC_GetDate(RTC_HandleTypeDef * /*hrtc*/, RTC_DateTypeDef * /*sDate*/, uint32_t /*Format*/)
{
    return HAL_OK;
}


HAL_StatusTypeDef HAL_RTC_SetDate(RTC_HandleTypeDef * /*hrtc*/, RTC_DateTypeDef * /*sDate*/, uint32_t /*Format*/)
{
    return HAL_OK;
}


HAL_StatusTypeDef HAL_RTC_SetTime(RTC_HandleTypeDef * /*hrtc*/, RTC_TimeTypeDef * /*sTime*/, uint32_t /*Format*/)
{
    return HAL_OK;
}


HAL_StatusTypeDef HAL_RTC_Init(RTC_HandleTypeDef * /*hrtc*/)
{
    return HAL_OK;
}


uint32_t HAL_RTCEx_BKUPRead(RTC_HandleTypeDef * /*hrtc*/, uint32_t /*BackupRegister*/)
{
    return 0U;
}


void HAL_RTCEx_BKUPWrite(RTC_HandleTypeDef * /*hrtc*/, uint32_t /*BackupRegister*/, uint32_t /*Data*/)
{

}
