#include "defines.h"
#include "HAL.h"
#include <stm32f4xx_hal.h>
#include <cstring>


int HAL_OTP::GetSerialNumber(char buffer[17]) //-V2506
{
    // \todo �������� - ������ �������������� �������. ������ ������ ������ �������� ������� �����, ������� � ��� ��������, � �� 16, ��� ������.

    const int allShotsMAX = 512 / 16;   // ������������ ����� ������� � OTP ��������� ������.

    uint8 *address = (uint8 *)(FLASH_OTP_END - 15U); //-V566 //-V2571

    do
    {
        address -= 16; //-V2563
    } while (*address == 0xff && address > (uint8 *)FLASH_OTP_BASE); //-V566 //-V2571

    if (*address == 0xff)   // �� ����� ������ � �����������, ����� �� ���������� ������ OTP
    {
        buffer[0] = 0;
        return allShotsMAX;
    }

    std::strcpy(buffer, const_cast<const char *>(reinterpret_cast<char *>(address))); //-V2513

    return allShotsMAX - (address - (uint8 *)FLASH_OTP_BASE) / 16 - 1; //-V566 //-V2571
}


bool HAL_OTP::SaveSerialNumber(char *servialNumber) //-V2506
{
    // ������� ������ ������ ������ ������ 16 ���� � ������� OTP, ������� � ������
    uint8 *address = (uint8 *)FLASH_OTP_BASE; //-V566 //-V2571

    while ((*address) != 0xff &&                    // *address != 0xff ��������, ��� ������ � ��� ������ ��� �������������
        address < (uint8 *)FLASH_OTP_END - 16) //-V566 //-V2563 //-V2571
    {
        address += 16; //-V2563
    }

    if (address < (uint8 *)FLASH_OTP_END - 16) //-V566 //-V2563 //-V2571
    {
        HAL_ROM::WriteBufferBytes(reinterpret_cast<uint>(address), static_cast<void *>(servialNumber), static_cast<int>(std::strlen(servialNumber) + 1)); //-V2513 //-V2571
        return true;
    }

    return false;
}
