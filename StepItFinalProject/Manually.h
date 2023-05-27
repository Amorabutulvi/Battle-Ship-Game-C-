#pragma once

int setupGame(char type, int matrix[14][14], int len = 1, int destroyer = 0, int subMarine = 0, int battleShip = 0, int carrier = 0) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(hConsole, 14);
    cout <<"\nRotation: " << type << " Axis" << endl;
    cout << "Player Board" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    SetConsoleTextAttribute(hConsole, 13);
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            if (i != lastRow && j != lastColumn)
                matrix[i][j] = 0;
        }
    }
    int size = 15;
    int tempX = 0;
    int tempY = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) cout << "* ";
            else if (matrix[i][j]) {
                cout << "$" << " ";
                if (type == 'x') {
                    if (len > tempX + 1) {
                        tempX++;
                        matrix[i + 1][j] = 1;
                    }
                }
                else {
                    if (len > tempY + 1) {
                        tempY++;
                        matrix[i][j + 1] = 1;
                    }
                }
            }
            else if (gameTable[i][j]) cout << "$" << " ";
            else cout << "  ";

        }
        cout << endl;
        
    }
    SetConsoleTextAttribute(hConsole, 15);
    if (choice != 5) {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Remaining WarShips : " << endl;

        if (destroyer && choice == 0) cout << ">> Destroyer(" << destroyer << ") ~ 4" << endl;
        else cout << "   Destroyer(" << destroyer << ") ~ 4" << endl;

        if (subMarine && choice == 1) cout << ">> SubMarine(" << subMarine << ") ~ 3" << endl;
        else cout << "   SubMarine(" << subMarine << ") ~ 3" << endl;

        if (battleShip && choice == 2) cout << ">> BattleShip(" << battleShip << ") ~ 2" << endl;
        else cout << "   BattleShip(" << battleShip << ") ~ 2" << endl;

        if (carrier && choice == 3) cout << ">> Carrier(" << carrier << ") ~ 1" << endl;
        else cout << "   Carrier(" << carrier << ") ~ 1" << endl;
        SetConsoleTextAttribute(hConsole, 15);
    }
    else {
        cout << ">> Play" << endl;
    }
    char c;
    while (active1) {
        switch ((c = _getch())) {
        case 72:
            if (choice > flagint && choice != 5) {
                choice--;
            }

            setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            break;
        case 80:
            if (choice < 3 && choice != 5)
                choice++;
            setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            break;
        case '\r':
            if (choice == 5) {
                active1 = false;
                active2 = false;
            }
            else {
                active1 = false;
                active2 = true;
                //matrix[lastRow][lastColumn] = 1;
                setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            }
            break;
        default: break;
        }
    }
    while (active2) {
        switch ((c = _getch())) {
        case 72: // UP
            if (lastRow - 1 > 0 && gameTable[lastRow - 2][lastColumn] != 1 && gameTable[lastRow - 2][lastColumn + 1] != 1 && gameTable[lastRow - 2][lastColumn - 1] != 1) {
                if (choice == 0 && destroyer != 0) {
                    if (type == 'x') {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 4][lastColumn] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 1][lastColumn] = 0;
                        matrix[lastRow + 2][lastColumn] = 0;
                        matrix[lastRow + 3][lastColumn] = 0;
                        matrix[lastRow + 4][lastColumn] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else if (choice == 1 && subMarine != 0) {
                    if (type == 'x') {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 3][lastColumn] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 1][lastColumn] = 0;
                        matrix[lastRow + 2][lastColumn] = 0;
                        matrix[lastRow + 3][lastColumn] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else if (choice == 2 && battleShip != 0) {
                    if (type == 'x') {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 2][lastColumn] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastRow--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow + 1][lastColumn] = 0;
                        matrix[lastRow + 2][lastColumn] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else if (choice == 3 && carrier != 0) {
                    lastRow--;
                    matrix[lastRow][lastColumn] = 1;
                    matrix[lastRow + 1][lastColumn] = 0;
                    setupGame(type, matrix, 1, destroyer, subMarine, battleShip, carrier);
                }
                else {
                    active1 = true;
                    active2 = false;
                    setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
                }
            }
            break;
        case 80: // Down
            if (choice == 0 && destroyer != 0) {
                if (type == 'x') {
                    if (lastRow + 1 > 0 && lastRow + 1 < 11 && gameTable[lastRow + 5][lastColumn] != 1 && gameTable[lastRow + 5][lastColumn + 1] != 1 && gameTable[lastRow + 5][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastRow + 1 > 0 && lastRow + 1 < 14 && gameTable[lastRow + 2][lastColumn] != 1 && gameTable[lastRow + 2][lastColumn + 1] != 1 && gameTable[lastRow + 2][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        matrix[lastRow + 1][lastColumn] = 0;
                        matrix[lastRow + 2][lastColumn] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 1 && subMarine != 0) {
                if (type == 'x') {
                    if (lastRow + 1 > 0 && lastRow + 1 < 12 && gameTable[lastRow + 4][lastColumn] != 1 && gameTable[lastRow + 4][lastColumn + 1] != 1 && gameTable[lastRow + 4][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastRow + 1 > 0 && lastRow + 1 < 14 && gameTable[lastRow + 2][lastColumn] != 1 && gameTable[lastRow + 2][lastColumn + 1] != 1 && gameTable[lastRow + 2][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        matrix[lastRow + 1][lastColumn] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 2 && battleShip != 0) {
                if (type == 'x') {
                    if (lastRow + 1 > 0 && lastRow + 1 < 13 && gameTable[lastRow + 3][lastColumn] != 1 && gameTable[lastRow + 3][lastColumn + 1] != 1 && gameTable[lastRow + 3][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastRow + 1 > 0 && lastRow + 1 < 14 && gameTable[lastRow + 2][lastColumn] != 1 && gameTable[lastRow + 2][lastColumn + 1] != 1 && gameTable[lastRow + 2][lastColumn - 1] != 1) {
                        lastRow++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow - 1][lastColumn] = 0;
                        matrix[lastRow - 2][lastColumn] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 3 && carrier != 0) {
                if (lastRow + 1 > 0 && lastRow + 1 < 14 && gameTable[lastRow + 2][lastColumn] != 1 && gameTable[lastRow + 2][lastColumn + 1] != 1 && gameTable[lastRow + 2][lastColumn - 1] != 1) {
                    lastRow++;
                    matrix[lastRow][lastColumn] = 1;
                    matrix[lastRow - 1][lastColumn] = 0;
                    setupGame(type, matrix, 1, destroyer, subMarine, battleShip, carrier);
                }
            }
            else {
                active1 = true;
                active2 = false;
                setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            }
            break;
        case 77: // Right
            if (choice == 0 && destroyer != 0) {
                if (type == 'x') {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 14 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 3][lastColumn + 2] != 1 && gameTable[lastRow + 3][lastColumn - 2] != 1 && gameTable[lastRow - 1][lastColumn + 2] != 1 && gameTable[lastRow + 4][lastColumn + 2] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 11 && gameTable[lastRow][lastColumn + 5] != 1 && gameTable[lastRow - 1][lastColumn + 5] != 1 && gameTable[lastRow + 1][lastColumn + 5] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        matrix[lastRow][lastColumn - 2] = 0;
                        matrix[lastRow][lastColumn - 3] = 0;
                        matrix[lastRow][lastColumn - 4] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 1 && subMarine != 0) {
                if (type == 'x') {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 14 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow - 1][lastColumn + 2] != 1 && gameTable[lastRow + 3][lastColumn + 2] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 12 && gameTable[lastRow][lastColumn + 4] != 1 && gameTable[lastRow - 1][lastColumn + 4] != 1 && gameTable[lastRow + 1][lastColumn + 4] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        matrix[lastRow][lastColumn - 2] = 0;
                        matrix[lastRow][lastColumn - 3] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 2 && battleShip != 0) {
                if (type == 'x') {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 14 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow - 1][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
                else {
                    if (lastColumn + 1 > 0 && lastColumn + 1 < 13 && gameTable[lastRow][lastColumn + 3] != 1 && gameTable[lastRow - 1][lastColumn + 3] != 1 && gameTable[lastRow + 1][lastColumn + 3] != 1) {
                        lastColumn++;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn - 1] = 0;
                        matrix[lastRow][lastColumn - 2] = 0;
                        matrix[lastRow][lastColumn - 3] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 3 && carrier != 0 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow - 1][lastColumn + 2] != 1 && gameTable[lastRow + 1][lastColumn + 2] != 1) {
                if (lastColumn + 1 > 0 && lastColumn + 1 < 14 && gameTable[lastRow][lastColumn + 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1) {
                    lastColumn++;
                    matrix[lastRow][lastColumn] = 1;
                    matrix[lastRow][lastColumn - 1] = 0;
                    setupGame(type, matrix, 1, destroyer, subMarine, battleShip, carrier);
                }
            }
            else {
                active1 = true;
                active2 = false;
                setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            }
            break;
        case 75: // Left
            if (choice == 0 && destroyer != 0) {
                if (lastColumn - 1 > 0 && lastColumn - 1 < 14 && gameTable[lastRow][lastColumn - 2] != 1 && gameTable[lastRow + 3][lastColumn - 2] != 1 && gameTable[lastRow + 3][lastColumn + 2] != 1 && gameTable[lastRow - 1][lastColumn - 2] != 1 && gameTable[lastRow + 4][lastColumn - 2] != 1) {
                    if (type == 'x') {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        matrix[lastRow][lastColumn + 2] = 0;
                        matrix[lastRow][lastColumn + 3] = 0;
                        matrix[lastRow][lastColumn + 4] = 0;
                        setupGame(type, matrix, 4, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 1 && subMarine != 0) {
                if (lastColumn - 1 > 0 && lastColumn - 1 < 14 && gameTable[lastRow][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow - 1][lastColumn - 2] != 1 && gameTable[lastRow + 3][lastColumn - 2] != 1) {
                    if (type == 'x') {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        matrix[lastRow][lastColumn + 2] = 0;
                        matrix[lastRow][lastColumn + 3] = 0;
                        setupGame(type, matrix, 3, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 2 && battleShip != 0) {
                if (lastColumn - 1 > 0 && lastColumn - 1 < 14 && gameTable[lastRow][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow - 1][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1) {
                    if (type == 'x') {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        matrix[lastRow][lastColumn + 2] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                    else {
                        lastColumn--;
                        matrix[lastRow][lastColumn] = 1;
                        matrix[lastRow][lastColumn + 1] = 0;
                        matrix[lastRow][lastColumn + 2] = 0;
                        setupGame(type, matrix, 2, destroyer, subMarine, battleShip, carrier);
                    }
                }
            }
            else if (choice == 3 && carrier != 0) {
                if (lastColumn - 1 > 0 && lastColumn - 1 < 14 && gameTable[lastRow][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn - 2] != 1 && gameTable[lastRow + 2][lastColumn + 2] != 1 && gameTable[lastRow - 1][lastColumn - 2] != 1 && gameTable[lastRow + 1][lastColumn - 2] != 1) {
                    lastColumn--;
                    matrix[lastRow][lastColumn] = 1;
                    matrix[lastRow][lastColumn + 1] = 0;
                    setupGame(type, matrix, 1, destroyer, subMarine, battleShip, carrier);
                }
            }
            else {
                active1 = true;
                active2 = false;
                setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            }
            break;
        case 'r':
            if (type == 'x') type = 'y';
            else type = 'x';
            setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
        case '\r':
            for (int i = 0; i < 14; i++) {
                for (int j = 0; j < 14; j++) {
                    if (matrix[i][j] == 1) {
                        gameTable[i][j] = 1;
                        cout << i << " | " << j << endl;
                    }
                }
            }
            if (choice == 0) destroyer--;
            else if (choice == 1) subMarine--;
            else if (choice == 2) battleShip--;
            else if (choice == 3) carrier--;
            active1 = true;
            active2 = false;
            if (destroyer == 0 && flagint == 0) {
                flagint = 1;
                choice = 1;
            }
            else if (subMarine == 0 && flagint == 1) {
                flagint = 2;
                choice = 2;
            }
            else if (battleShip == 0 && flagint == 2) {
                flagint = 3;
                choice = 3;
            }
            else if (carrier == 0 && flagint == 3) {
                flagint = 5;
                choice = 5;
            }
            setupGame(type, matrix, 0, destroyer, subMarine, battleShip, carrier);
            break;
        default: break;
        }
    }
    return 0;
}