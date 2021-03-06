#pragma once

#define START_MULTI_MEASUREMENT() Timer::StartMultiMeasurement()
#define PAUSE_ON_TICKS(ticks)     Timer::PauseOnTicks(ticks)
#define PAUSE_ON_MS(ms)           Timer::PauseOnTime(ms)


// ���������� �����, ��������� � ������� ���������� ������ ������� Timer_StartMultiMeasurement(). �� ����� (1 << 32)
 // � ����� ������� 120.000.000 ����� ��� �8-53 � 90.000.000 ����� ��� �8-54.
 // ������������ ������� �������, ������� ����� ��������� � � ������� - 35 ���.
#undef TIME_TICKS
#undef TIME_MS
#define TIME_TICKS Timer::TimeTicks()
#define TIME_US    Timer::TimeUS()
#define TIME_MS    Timer::TimeMS()


struct TypeTimer
{
    enum E
    {
        ShowLevelTrigLev,       // ����� �������������, ����� ���������� ��������� ����� ������ �������������
        ShowMessages,           // ������ ��� ��������� ����� ������ �������������� � ��������������� ���������.
        MenuAutoHide,           // ������ ��� ������� ������� ��������� ����.
        RShiftMarkersAutoHide,  // ������ ��� ������� ������� ��������� �������������� ������� �����.
        StopSound,              // ��������� ����
        StrNaviAutoHide,        // ������� ������ ��������� ����
        Display,                // ������ �� ������ ��������� ������
        RemoveAddFunction,      // ������ �� �������� �������������� ������� ���������
        USB,                    ///<
        Temp,
        Count
    };
};


struct Timer
{
    static void Init();

    static void DeInit();
    // ��������� ������� timer ������� � ����� ������������
    static void Set(TypeTimer::E type, pFuncVV func, uint dTms);

    static void SetAndStartOnce(TypeTimer::E type, pFuncVV func, uint dTms);

    static void SetAndEnable(TypeTimer::E type, pFuncVV func, uint dTms);

    static void StartOnce(TypeTimer::E type);

    static void Enable(TypeTimer::E type);

    static void Disable(TypeTimer::E type);
    // ���������� true, ���� ������ � ������ ������ ���� ������
    static bool IsRunning(TypeTimer::E type);

    static void PauseOnTime(uint timeMS);

    static void PauseOnTicks(uint numTicks);
    // ��������� ������� ��� ��������� ����� �������� �������
    static void StartMultiMeasurement();
    // ������� ����������� ����� ������������ �������� � ����� for
    static void PauseOnOPS(uint ops);

    static bool IsBusy();
    // ���������� ���������� �����������, ��������� � ������� ���������� ������ StartMultiMeasurement()
    static uint TimeUS();
    // ���������� ���������� �����, ��������� � ������� ���������� ������ StartMultiMeasurement();
    static uint TimeTicks();
    // ���������� ���������� �����������, ��������� � ������� ������ ���������
    static uint TimeMS();
    // ������������� ��������� ����� ������������. ����� ������ Timer_LogPoint �������� ��������� ��������� �� ��� �����
    static void StartLogging();

    static uint LogPointUS(char *name);

    static uint LogPointMS(char *name);
    // ��������� �������. ���������� ������ �� ����������
    static void ElapsedCallback();
};
