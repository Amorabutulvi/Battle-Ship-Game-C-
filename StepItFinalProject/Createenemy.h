#pragma once

void CreateEnemy() {
    srand(time(0));
    bool flag = true;
    while (flag) {
        int random = 1 + (rand() % 14);
        int randomX = 1 + (rand() % 14);
        int randomY = 1 + (rand() % 14);
        if (random > 7) {
            if (enemyDestroyer != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX + 1][randomY] != 1 && enemyTable[randomX + 2][randomY] != 1 && enemyTable[randomX + 3][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX + 1][randomY] = 1;
                    enemyTable[randomX + 2][randomY] = 1;
                    enemyTable[randomX + 3][randomY] = 1;
                    enemyDestroyer--;
                }
            }
            else if (enemySubMarine != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX + 1][randomY] != 1 && enemyTable[randomX + 2][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX + 1][randomY] = 1;
                    enemyTable[randomX + 2][randomY] = 1;
                    enemySubMarine--;
                }
            }
            else if (enemyBattleShip != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX + 1][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX + 1][randomY] = 1;
                    enemyBattleShip--;
                }
            }
            else if (enemyCarrier != 0) {
                if (enemyTable[randomX][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyCarrier--;
                }
            }
            else {
                flag = false;
            }
        }
        else {
            if (enemyDestroyer != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX][randomY + 1] != 1 && enemyTable[randomX][randomY + 2] != 1 && enemyTable[randomX][randomY + 3] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX][randomY + 1] = 1;
                    enemyTable[randomX][randomY + 2] = 1;
                    enemyTable[randomX][randomY + 3] = 1;
                    enemyDestroyer--;
                }
            }
            else if (enemySubMarine != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX][randomY + 1] != 1 && enemyTable[randomX][randomY + 2] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX][randomY + 1] = 1;
                    enemyTable[randomX][randomY + 2] = 1;
                    enemySubMarine--;
                }
            }
            else if (enemyBattleShip != 0) {
                if (enemyTable[randomX][randomY] != 1 && enemyTable[randomX][randomY + 1] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyTable[randomX][randomY + 1] = 1;
                    enemyBattleShip--;
                }
            }
            else if (enemyCarrier != 0) {
                if (enemyTable[randomX][randomY] != 1) {
                    enemyTable[randomX][randomY] = 1;
                    enemyCarrier--;
                }
            }
            else {
                flag = false;
            }
        }
    }

}