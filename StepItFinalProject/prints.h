#pragma once
#pragma once
int flagint = 0;
int choice = 0, lastRow = 7, lastColumn = 7;
bool active1 = true, active2 = false;
int gameTable[14][14] = {};
int enemyTable[14][14] = {};

void asciiPrint() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(hConsole, 9);
    cout << "\n\n\t\t\tXXXXX    XXXX   XXXXXX  XXXXXX  XX      XXXXXX    XXXXX  XX  XX  XX  XXXXX\n";
    cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX       XX      XX  XX  XX  XX  XX\n";
    cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX       XX      XX  XX  XX  XX  XX\n";
    cout << "\t\t\tXXXXX   XX  XX    XX      XX    XX      XXXX      XXXX   XXXXXX  XX  XXXXX\n";
    cout << "\t\t\tXX  XX  XXXXXX    XX      XX    XX      XX           XX  XX  XX  XX  XX\n";
    cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX           XX  XX  XX  XX  XX\n";
    cout << "\t\t\tXXXXX   XX  XX    XX      XX    XXXXXX  XXXXXX   XXXXX   XX  XX  XX  XX\n";
    SetConsoleTextAttribute(hConsole, 15);
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\n\n\n\t\t\t\t\t     BattleShip Game\n";
    SetConsoleTextAttribute(hConsole, 15);
}

int mainScreen() {
    int load = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (load < 101) {
        SetConsoleTextAttribute(hConsole, 13);
        cout << "\n\n\n\t\t\t\t\tThe BattleShip Game Is Starting!\n\t\t\t\t\t\tLOADING... " << load << "%\n\n\n";
        SetConsoleTextAttribute(hConsole, 15);
        load += rand() % 20;
        SetConsoleTextAttribute(hConsole, 9);
        cout << "\n\n\t\t\tXXXXX    XXXX   XXXXXX  XXXXXX  XX      XXXXXX    XXXXX  XX  XX  XX  XXXXX\n";
        cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX       XX      XX  XX  XX  XX  XX\n";
        cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX       XX      XX  XX  XX  XX  XX\n";
        cout << "\t\t\tXXXXX   XX  XX    XX      XX    XX      XXXX      XXXX   XXXXXX  XX  XXXXX\n";
        cout << "\t\t\tXX  XX  XXXXXX    XX      XX    XX      XX           XX  XX  XX  XX  XX\n";
        cout << "\t\t\tXX  XX  XX  XX    XX      XX    XX      XX           XX  XX  XX  XX  XX\n";
        cout << "\t\t\tXXXXX   XX  XX    XX      XX    XXXXXX  XXXXXX   XXXXX   XX  XX  XX  XX\n";
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 14);
        cout << "\n\n\n\t\t\t\t\t     BattleShip Game\n";
        SetConsoleTextAttribute(hConsole, 15);
        Sleep(150);
        system("cls");
    }
    int selected = 0;
    bool active = true;
    asciiPrint();
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t\t>> Play\n";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\t\t\t   Exit\n";
    char c;
    while (active) {
        switch ((c = _getch())) {
        case 72:
            if (selected != 0)
                selected--;
            break;
        case 80:
            if (selected == 0)
                selected++;
            break;
        case '\r':
            if (selected == 0) {
                active = false;
            }
            else {
                exit(0);
            }
            break;
        default: break;
        }
        if (active) {
            if (selected == 0) {
                asciiPrint();
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t>> Play\n";
                SetConsoleTextAttribute(hConsole, 15);
                cout << "\t\t\t   Exit\n";
            }
            else {
                asciiPrint();
                cout << "\t\t\t   Play\n";
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t>> Exit\n";
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
    }
    return 0;
}

int secondScreen(bool& gametype) {
    int selected = 0;
    bool active = true;
    asciiPrint();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t\t>> Random\n";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\t\t\t   Manually\n";
    char c;
    while (active) {
        switch ((c = _getch())) {
        case 72:
            if (selected != 0)
                selected--;
            break;
        case 80:
            if (selected == 0)
                selected++;
            break;
        case '\r':
            if (selected == 0) {
                active = false;
            }
            else {
                active = false;
            }
            break;
        default: break;
        }
        if (active) {
            if (selected == 0) {
                asciiPrint();
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t>> Random\n";
                SetConsoleTextAttribute(hConsole, 15);
                cout << "\t\t\t   Manually\n";
                gametype = false;
            }
            else {
                asciiPrint();
                cout << "\t\t\t   Random\n";
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\t\t>> Manually\n";
                SetConsoleTextAttribute(hConsole, 15);
                gametype = true;
            }
        }
    }
    return 0;
}
