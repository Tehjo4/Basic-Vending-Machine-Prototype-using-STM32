
#include "keypad.h"
#include "main.h"  // Include global macros if necessary

char scan_keypad(void) {
    for (int row = 0; row < 4; row++) {
        HAL_GPIO_WritePin(ROW_PORT, (GPIO_PIN_12 << row), GPIO_PIN_SET);  // Activate row
        for (int col = 0; col < 3; col++) {
            if (HAL_GPIO_ReadPin(COL_PORT, (GPIO_PIN_9 << col)) == GPIO_PIN_SET) {
                HAL_GPIO_WritePin(ROW_PORT, (GPIO_PIN_12 << row), GPIO_PIN_RESET);  // Reset row
                return decode_key(row, col);  // Decode the key based on row & column
            }
        }
        HAL_GPIO_WritePin(ROW_PORT, (GPIO_PIN_12 << row), GPIO_PIN_RESET);  // Reset row
    }
    return '\0';  // Return '\0' if no key is pressed
}

char decode_key(int row, int col) {
    char keys[4][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}};
    return keys[row][col];
}
