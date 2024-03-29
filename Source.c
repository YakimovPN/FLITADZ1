#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

HANDLE hConsole;

enum ColorConsole {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

int iter() {
    SetConsoleTextAttribute(hConsole, White);
    printf("������� i-�������� ������� ��������� (�� �������� �� ������������):\n");
    SetConsoleTextAttribute(hConsole, Blue);
    int f = 0, iin = 0, in = 0;
    char ich = getchar();
    while (ich != 10) {
        if ((ich != ' ') && (ich != '\t')) {
            iin = ich - '0';
            if ((iin >= 2) && (iin <= 9)) {
                in = iin;
                break;
            }
            else {
                if (iin == 1) {
                    ich = getchar();
                    iin = ich - '0';
                    if ((ich != 10) && (ich != ' ') && (ich != '\t') && (iin == 0)) {
                        in = 10;
                        break;
                    }
                    else {
                        in = 0;
                        break;
                    };
                };
            };
        };
        ich = getchar();
        f++;
        if (f >= 255) {
            in = 1;
            break;
        };
    };
    return(in);
};

int main() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "Rus");
    char ch;
    SetConsoleTextAttribute(hConsole, White);
    printf("����� ���������� � ����������� �� �������� ����� �� ����� �� � ������! ��� ������ ������ ������� Enter (q - ��������� ������ ���������).\n");
    SetConsoleTextAttribute(hConsole, Blue);
    ch = getchar();
    while (ch != 10) {
        if (ch == 113) {
            SetConsoleTextAttribute(hConsole, White);
            return 0;
        };
        ch = getchar();
    };    
    int in = 0;
    goto iter;

iter: {
    in = iter();
    };

    if (in == 0) {
        SetConsoleTextAttribute(hConsole, Red);
        printf("������� ������������ ������, ������� Enter, ����� ����������� ������ (q - ��������� ������ ���������)!\n");
        SetConsoleTextAttribute(hConsole, Blue);
        ch = getchar();
        while (ch != 10) {
            if (ch == 113) {
                SetConsoleTextAttribute(hConsole, White);
                return 0;
            };
            ch = getchar();
        };
        goto iter;
    }
    else {
        if (in == 1) {
            SetConsoleTextAttribute(hConsole, Red);
            printf("������� ������� ������� ���������� ��������, ������� Enter, ����� ����������� ������ (q - ��������� ������ ���������)!\n");
            SetConsoleTextAttribute(hConsole, Blue);
            ch = getchar();
            while (ch != 10) {
                if (ch == 113) {
                    SetConsoleTextAttribute(hConsole, White);
                    return 0;
                };
                ch = getchar();
            };
            goto iter;
        }
        else {
            int *mas = NULL, fl = 0;
            char z = 0;
            unsigned size = 0;
            ch = getchar();
            vvod: {
                SetConsoleTextAttribute(hConsole, Green);
                printf("������� ����� (�� ����� 65535) � %d-������ ������� ���������, �������� �� ��������� ��� ����������:\n", in);
                SetConsoleTextAttribute(hConsole, Blue);
                fl = 2;
                size = 0;
                z = 0;
                int ich = 0, i = 0, kof = 1;
                ch = getchar();
                while (ch != 10){
                    if ((ch != ' ') && (ch != '\t')) {
                        fl = 0;
                        if (((ch - '0') >= 0) && ((ch - '0') <= (in-1))) {
                            if (i == 0) {
                                ich = ch - '0';
                                i++;
                                if (z == 45) {
                                    kof = -1;
                                };
                            }
                            else {
                                ich = ich * 10 + ch - '0';
                                i++;
                            };
                        }
                        else {
                            if (((ch - '0') >= in) && ((ch - '0') <= 10)) {
                                SetConsoleTextAttribute(hConsole, Red);
                                printf("�� ����� ����� �� �� ��������� �� (������� Enter, ����� ����������� ������ ��� q, ����� ��������� ������ ���������)!\n");
                                SetConsoleTextAttribute(hConsole, Blue);
                                fl = 1;
                                break;
                            };
                        };
                    }
                    else {
                        if (i > 0) {
                            if (size == 0) {
                                mas = malloc((size + 1) * sizeof(int));
                                *mas = ich * kof;
                                kof = 1;
                                ich = 0;
                                i = 0;
                                size = size++;
                            }
                            else {
                                mas = realloc(mas, (size + 1) * sizeof(int));
                                *(mas + size) = ich * kof;
                                kof = 1;
                                ich = 0;
                                i = 0;
                                size = size++;
                            };
                        };
                    };
                    z = ch;
                    ch = getchar();
                };
                if (fl == 0) {
                    if (i > 0) {
                        if (size == 0) {
                            mas = malloc((size + 1) * sizeof(int));
                            *mas = ich * kof;
                            kof = 1;
                            ich = 0;
                            i = 0;
                            size = size++;
                        }
                        else {
                            mas = realloc(mas, (size + 1) * sizeof(int));
                            *(mas + size) = ich * kof;
                            kof = 1;
                            ich = 0;
                            i = 0;
                            size = size++;
                        };
                    };
                };
            };
            if (fl == 1) {
                while (ch != 10) {
                    ch = getchar();
                };
                ch = getchar();
                while (ch != 10) {
                    if (ch == 113) {
                        SetConsoleTextAttribute(hConsole, White);
                        return 0;
                    };
                    ch = getchar();
                };
                goto vvod;
            }
            else {
                if (fl == 2) {
                    SetConsoleTextAttribute(hConsole, Red);
                    printf("�� �� ����� ����� �� ��������� �� (������� Enter, ����� ����������� ������ ��� q, ����� ��������� ������ ���������)!\n");
                    SetConsoleTextAttribute(hConsole, Blue);
                    ch = getchar();
                    while (ch != 10) {
                        if (ch == 113) {
                            SetConsoleTextAttribute(hConsole, White);
                            return 0;
                        };
                        ch = getchar();
                    };
                    goto vvod;
                }
                else {
                    int *mas1 = NULL, k = 0, sum = 0, r = 0, kk=0;
                    mas1 = malloc(size * sizeof(int));
                    SetConsoleTextAttribute(hConsole, Green);
                    printf("-----------------------------------\n|%3d-(�)����� �� |  10-������ ��  |\n-----------------------------------\n", in);
                    for (int j = 0; j <= (size - 1); j++) {
                        if (mas[j] < 0) {
                            k = -mas[j];
                            kk = -1;
                        }
                        else {
                            k = mas[j];
                            kk = 1;
                        }
                        r = 0;
                        sum = 0;
                        while (k > 0) {
                            sum = sum + (k % 10) * pow(in, r);
                            k = k / 10;
                            r++;
                        };
                        mas1[j] = sum * kk;
                        printf("|%16d|%16d|\n", mas[j], mas1[j]);
                    };
                    printf("-----------------------------------\n");
                    SetConsoleTextAttribute(hConsole, White);
                    printf("��� ����, ����� ���������� ��� 1 ������ �����, ������� Enter (q - ��������� ������ ���������)!\n");
                    ch = getchar();
                    while (ch != 10) {
                        if (ch == 113) {
                            SetConsoleTextAttribute(hConsole, White);
                            return 0;
                        };
                        ch = getchar();
                    };
                    goto iter;
                };
            };
        };
    };
    SetConsoleTextAttribute(hConsole, White);
    return 0;
};