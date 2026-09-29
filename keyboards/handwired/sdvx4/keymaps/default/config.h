#pragma once

#define DIRECT_PINS { \
    { D2, D3, D4, D5 } \
}

#undef MATRIX_ROWS
#undef MATRIX_COLS
#define MATRIX_ROWS 1
#define MATRIX_COLS 4

#define USB_POLLING_INTERVAL_MS 1
