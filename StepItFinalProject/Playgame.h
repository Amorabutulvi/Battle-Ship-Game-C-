#pragma once

void PlayGame(int startedGame[14][14], char _turn = 'p') {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int size = 15;
    int tempX = 0;
    int tempY = 0;
    cout << "Debug Area: " << endl;

    cout << "Enemy Area: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                SetConsoleTextAttribute(hConsole, 6);
                cout << "* ";
            }
            else if (startedGame[i][j]) {
                SetConsoleTextAttribute(hConsole, 9);
                cout << char(startedGame[i][j]) << " ";
                SetConsoleTextAttribute(hConsole, 6);
            }
            else if (enemyTable[i][j] == 254 || enemyTable[i][j] == 248) {
                SetConsoleTextAttribute(hConsole, 9);
                cout << char(enemyTable[i][j]) << " ";
                SetConsoleTextAttribute(hConsole, 6);
            }
            else cout << "# ";

        }
        cout << endl;
    }
    cout << "Your Area: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                SetConsoleTextAttribute(hConsole, 6);
                cout << "* ";
            }
            else if (gameTable[i][j]) {
                SetConsoleTextAttribute(hConsole, 9);
                cout << char(gameTable[i][j]) << " ";
                SetConsoleTextAttribute(hConsole, 6);
            }
            else cout << "# ";

        }
        cout << endl;
    }
    if (_turn == 'p') cout << "Player" << endl;
    else cout << "Computer" << endl;
    char c;
    while (true) {
        if (_turn == 'p') {
            switch ((c = _getch())) {
            case 72: // UP
                if (gameRow - 1 > 0) {
                    gameRow--;
                    startedGame[gameRow][gameCol] = 197;
                    startedGame[gameRow + 1][gameCol] = 0;
                    PlayGame(startedGame);
                }
                break;
            case 80: // Down
                if (gameRow + 1 > 0 && gameRow + 1 < 14) {
                    gameRow++;
                    startedGame[gameRow][gameCol] = 197;
                    startedGame[gameRow - 1][gameCol] = 0;
                    PlayGame(startedGame);
                }
                break;
            case 77: // Right
                if (gameCol + 1 > 0 && gameCol + 1 < 14) {
                    gameCol++;
                    startedGame[gameRow][gameCol] = 197;
                    startedGame[gameRow][gameCol - 1] = 0;
                    PlayGame(startedGame);
                }
                break;
            case 75: // Left
                if (gameCol - 1 > 0 && gameCol - 1 < 14) {
                    gameCol--;
                    startedGame[gameRow][gameCol] = 197;
                    startedGame[gameRow][gameCol + 1] = 0;
                    PlayGame(startedGame);
                }
                break;
            case '\r':
                if (enemyTable[gameRow][gameCol] == 1) {
                    cout << "700" << endl;
                    enemyTable[gameRow][gameCol] = 254;
                    PlayGame(startedGame, 'c');
                }
                else {
                    if (enemyTable[gameRow][gameCol] != 254) {
                        if (enemyTable[gameRow][gameCol] != 248) {
                            enemyTable[gameRow][gameCol] = 248;
                            cout << "708" << endl;
                            PlayGame(startedGame, 'c');
                        }
                    }
                }
                break;
            default: break;
            }
        }
        else {
            if (found) {
                int randomm = 1 + (rand() % 14);
                if (randomm > 7) {
                    int randommm = 1 + (rand() % 14);
                    if (randomm > 7) {
                        if (gameTable[foundX + 1][foundY] == 1) {
                            gameTable[foundX + 1][foundY] = 254;
                            PlayGame(startedGame, 'p');
                        }
                        else {
                            found = false;
                            PlayGame(startedGame, 'c');
                        }
                    }
                    else {
                        if (gameTable[foundX - 1][foundY] == 1) {
                            gameTable[foundX - 1][foundY] = 254;
                            PlayGame(startedGame, 'p');
                        }
                        else {
                            found = false;
                            PlayGame(startedGame, 'c');
                        }
                    }

                }
                else {
                    int randommm = 1 + (rand() % 14);
                    if (randomm > 7) {
                        if (gameTable[foundX][foundY + 1] == 1) {
                            gameTable[foundX][foundY + 1] = 254;
                            PlayGame(startedGame, 'p');
                        }
                        else {
                            found = false;
                            PlayGame(startedGame, 'c');
                        }
                    }
                    else {
                        if (gameTable[foundX][foundY - 1] == 1) {
                            gameTable[foundX][foundY - 1] = 254;
                            PlayGame(startedGame, 'p');
                        }
                        else {
                            found = false;
                            PlayGame(startedGame, 'c');
                        }
                    }
                }
            }
            else {
                int randomX = 1 + (rand() % 14);
                int randomY = 1 + (rand() % 14);
                if (gameTable[randomX][randomY] == 1) {
                    foundX = randomX;
                    foundY = randomY;
                    gameTable[randomX][randomY] = 254;
                    found = true;
                    PlayGame(startedGame, 'p');
                }
                else {
                    if (gameTable[gameRow][gameCol] != 254) {
                        if (gameTable[randomX][randomY] != 248) {
                            gameTable[randomX][randomY] = 248;
                            PlayGame(startedGame, 'p');
                        }
                    }
                    else {
                        PlayGame(startedGame, 'c');
                    }
                }
            }
        }
    }
}