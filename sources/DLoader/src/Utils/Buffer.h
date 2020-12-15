#pragma once


/*
    ����� ����������� ������������ ��� ��������������� ���������/������������ ������ �� ����
*/

class Buffer
{
public:
    Buffer(uint size = 0U);
    ~Buffer();
    void Realloc(uint size);
    void Fill(uint8 value);
    uint8 *data;
    uint Size() const { return size; }

    void Log();
    static void LogU8(uint8 *buffer);
private:
    uint size;
    void Free();
    void Malloc(uint size);
};
