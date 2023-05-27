#pragma once
#include "prints.h"
#include "Manually.h"
int gameRow = 7, gameCol = 7;
int enemyDestroyer = 1, enemySubMarine = 2, enemyBattleShip = 3, enemyCarrier = 4;
#include "Createenemy.h"
char turn = 'p';
bool found = false;
int foundX = 0, foundY = 0;
#include "Playgame.h"