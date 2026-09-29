#include QMK_KEYBOARD_H

// 引脚定义
#define PIN_D  D2
#define PIN_F  D3
#define PIN_J  D4
#define PIN_K  D5

#define LED_D  D6
#define LED_F  D7
#define LED_J  D8
#define LED_K  D9

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_D, KC_F, KC_J, KC_K
    )
};

void matrix_init_user(void) {
    // 设置按键引脚：输入+内部上拉
    setPinInputHigh(PIN_D);
    setPinInputHigh(PIN_F);
    setPinInputHigh(PIN_J);
    setPinInputHigh(PIN_K);

    // 设置LED引脚为输出，初始关灯
    setPinOutput(LED_D);
    setPinOutput(LED_F);
    setPinOutput(LED_J);
    setPinOutput(LED_K);
    writePinLow(LED_D);
    writePinLow(LED_F);
    writePinLow(LED_J);
    writePinLow(LED_K);
}

bool matrix_scan_user(void) {
    // 按下=灯亮，松开=灯灭
    writePin(LED_D, !readPin(PIN_D));
    writePin(LED_F, !readPin(PIN_F));
    writePin(LED_J, !readPin(PIN_J));
    writePin(LED_K, !readPin(PIN_K));
    return true;
}
