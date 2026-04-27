#include QMK_KEYBOARD_H
#include "ergohaven.h"
#include "ergohaven_pointing.h"

#define ENC_CODE   EH_RSRV2
#define ENC_DEL4   EH_RSRV3
#define ENC_BSPC4  EH_RSRV4

#define ENC_MODE_TAB     EH_RSRV5
#define ENC_MODE_DESKTOP EH_RSRV6
#define ENC_MODE_APP     EH_RSRV1

// clang-format off

// --- Encoding sequences (ported from ZMK encoding_macros.dtsi) ---
static const uint16_t PROGMEM enc_lower_A[4] = { KC_4, KC_D, S(KC_5), S(KC_F) };
static const uint16_t PROGMEM enc_upper_A[4] = { KC_2, S(KC_SLSH), KC_L, S(KC_L) };
static const uint16_t PROGMEM enc_lower_B[4] = { KC_6, S(KC_EQL), KC_U, S(KC_Y) };
static const uint16_t PROGMEM enc_upper_B[4] = { KC_5, KC_R, S(KC_6), S(KC_W) };
static const uint16_t PROGMEM enc_lower_C[4] = { KC_R, KC_4, S(KC_7), S(KC_F) };
static const uint16_t PROGMEM enc_upper_C[4] = { KC_3, KC_D, S(KC_V), S(KC_SLSH) };
static const uint16_t PROGMEM enc_lower_D[4] = { KC_F, KC_8, S(KC_1), S(KC_M) };
static const uint16_t PROGMEM enc_upper_D[4] = { S(KC_6), KC_3, S(KC_T), KC_N };
static const uint16_t PROGMEM enc_lower_E[4] = { S(KC_N), KC_EQL, KC_9, KC_H };
static const uint16_t PROGMEM enc_upper_E[4] = { KC_Q, KC_6, S(KC_R), S(KC_EQL) };
static const uint16_t PROGMEM enc_lower_F[4] = { S(KC_EQL), KC_I, KC_3, S(KC_N) };
static const uint16_t PROGMEM enc_upper_F[4] = { KC_4, S(KC_N), S(KC_6), KC_J };
static const uint16_t PROGMEM enc_lower_G[4] = { KC_7, KC_S, S(KC_S), S(KC_2) };
static const uint16_t PROGMEM enc_upper_G[4] = { KC_A, S(KC_D), KC_9, S(KC_2) };
static const uint16_t PROGMEM enc_lower_H[4] = { S(KC_6), S(KC_M), KC_O, KC_8 };
static const uint16_t PROGMEM enc_upper_H[4] = { KC_2, S(KC_V), S(KC_3), KC_N };
static const uint16_t PROGMEM enc_lower_I[4] = { KC_D, S(KC_R), KC_3, S(KC_7) };
static const uint16_t PROGMEM enc_upper_I[4] = { S(KC_N), KC_5, S(KC_1), KC_Y };
static const uint16_t PROGMEM enc_lower_J[4] = { S(KC_E), KC_K, S(KC_3), KC_3 };
static const uint16_t PROGMEM enc_upper_J[4] = { S(KC_B), S(KC_6), KC_G, KC_8 };
static const uint16_t PROGMEM enc_lower_K[4] = { KC_4, KC_A, S(KC_T), S(KC_EQL) };
static const uint16_t PROGMEM enc_upper_K[4] = { KC_1, S(KC_SLSH), S(KC_N), KC_B };
static const uint16_t PROGMEM enc_lower_L[4] = { KC_W, S(KC_8), S(KC_K), KC_3 };
static const uint16_t PROGMEM enc_upper_L[4] = { S(KC_1), S(KC_R), KC_Z, KC_3 };
static const uint16_t PROGMEM enc_lower_M[4] = { S(KC_X), S(KC_4), KC_1, KC_D };
static const uint16_t PROGMEM enc_upper_M[4] = { S(KC_G), KC_0, KC_O, S(KC_4) };
static const uint16_t PROGMEM enc_lower_N[4] = { S(KC_O), KC_E, S(KC_4), KC_5 };
static const uint16_t PROGMEM enc_upper_N[4] = { KC_1, S(KC_Z), S(KC_2), KC_C };
static const uint16_t PROGMEM enc_lower_O[4] = { KC_B, KC_5, S(KC_E), S(KC_3) };
static const uint16_t PROGMEM enc_upper_O[4] = { S(KC_E), S(KC_EQL), KC_9, KC_E };
static const uint16_t PROGMEM enc_lower_P[4] = { S(KC_R), S(KC_6), KC_5, KC_Z };
static const uint16_t PROGMEM enc_upper_P[4] = { S(KC_H), S(KC_1), KC_Z, KC_3 };
static const uint16_t PROGMEM enc_lower_Q[4] = { KC_H, KC_0, S(KC_X), S(KC_SLSH) };
static const uint16_t PROGMEM enc_upper_Q[4] = { KC_8, KC_S, S(KC_L), S(KC_EQL) };
static const uint16_t PROGMEM enc_lower_R[4] = { KC_D, S(KC_J), S(KC_6), KC_5 };
static const uint16_t PROGMEM enc_upper_R[4] = { S(KC_C), KC_V, S(KC_5), KC_7 };
static const uint16_t PROGMEM enc_lower_S[4] = { KC_6, KC_K, S(KC_A), S(KC_6) };
static const uint16_t PROGMEM enc_upper_S[4] = { S(KC_W), KC_3, KC_X, KC_EQL };
static const uint16_t PROGMEM enc_lower_T[4] = { KC_9, KC_Z, S(KC_3), S(KC_R) };
static const uint16_t PROGMEM enc_upper_T[4] = { S(KC_2), KC_1, S(KC_S), KC_P };
static const uint16_t PROGMEM enc_lower_U[4] = { KC_3, KC_H, KC_EQL, S(KC_L) };
static const uint16_t PROGMEM enc_upper_U[4] = { KC_0, S(KC_3), KC_O, S(KC_A) };
static const uint16_t PROGMEM enc_lower_V[4] = { S(KC_6), KC_4, S(KC_Z), KC_Z };
static const uint16_t PROGMEM enc_upper_V[4] = { S(KC_1), S(KC_X), KC_J, KC_9 };
static const uint16_t PROGMEM enc_lower_W[4] = { S(KC_EQL), S(KC_D), KC_J, KC_5 };
static const uint16_t PROGMEM enc_upper_W[4] = { S(KC_3), KC_D, KC_8, S(KC_S) };
static const uint16_t PROGMEM enc_lower_X[4] = { KC_8, S(KC_6), KC_L, S(KC_J) };
static const uint16_t PROGMEM enc_upper_X[4] = { KC_E, KC_7, S(KC_V), S(KC_8) };
static const uint16_t PROGMEM enc_lower_Y[4] = { S(KC_2), KC_I, KC_9, S(KC_S) };
static const uint16_t PROGMEM enc_upper_Y[4] = { KC_9, S(KC_B), KC_Q, KC_EQL };
static const uint16_t PROGMEM enc_lower_Z[4] = { KC_3, S(KC_Q), S(KC_4), KC_P };
static const uint16_t PROGMEM enc_upper_Z[4] = { S(KC_K), KC_T, S(KC_SLSH), KC_0 };
static const uint16_t PROGMEM enc_num_0[4] = { S(KC_GRV), KC_3, S(KC_X), KC_K };
static const uint16_t PROGMEM enc_num_1[4] = { S(KC_O), KC_9, KC_M, S(KC_4) };
static const uint16_t PROGMEM enc_num_2[4] = { KC_7, KC_Q, S(KC_I), S(KC_EQL) };
static const uint16_t PROGMEM enc_num_3[4] = { S(KC_D), KC_U, S(KC_8), KC_9 };
static const uint16_t PROGMEM enc_num_4[4] = { KC_8, S(KC_EQL), S(KC_G), KC_Q };
static const uint16_t PROGMEM enc_num_5[4] = { KC_4, KC_V, S(KC_3), S(KC_G) };
static const uint16_t PROGMEM enc_num_6[4] = { S(KC_L), KC_S, S(KC_EQL), KC_7 };
static const uint16_t PROGMEM enc_num_7[4] = { KC_P, S(KC_1), S(KC_S), KC_1 };
static const uint16_t PROGMEM enc_num_8[4] = { S(KC_5), KC_1, KC_F, S(KC_P) };
static const uint16_t PROGMEM enc_num_9[4] = { KC_6, S(KC_T), S(KC_8), KC_G };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV,   KC_1,   KC_2,    KC_3,     KC_4,     KC_5,                                              KC_6,  KC_7,     KC_8,     KC_9,   KC_0,    KC_BSPC,
        KC_ESC,   KC_Q,   KC_W,    KC_E,     KC_R,     KC_T,                                              KC_Y,  KC_U,     KC_I,     KC_O,   KC_P,    KC_BSLS,
        KC_TAB,   KC_A,   KC_S,    KC_D,     KC_F,     KC_G,                                              KC_H,  KC_J,     KC_K,     KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,     KC_V,     KC_B,                                              KC_N,  KC_M,     KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                          KC_PGDN, KC_PGUP,  KC_LCTL,  LOWER, KC_LALT, KC_SPACE,         KC_ENT, KC_RGUI, RAISE, KC_RCTL,  KC_LBRC,  KC_RBRC,
                                                                       KC_MUTE,          KC_MUTE
    ),

    [_LOWER] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,                                              KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,
        _______, _______, KC_HOME, KC_UP,   KC_END,   KC_INS,                                             _______, KC_7,    KC_8,    KC_9,   _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENT,                                             _______, KC_4,    KC_5,    KC_6,   _______, _______,
        _______, _______, PREVWRD, KC_CAPS, NEXTWRD,  KC_DEL,                                             KC_PSCR, KC_1,    KC_2,    KC_3,   _______, _______,
                          _______, _______, _______, _______, _______, _______,         _______, _______, ADJUST, _______, KC_0, _______,
                                                                       _______,         _______
    ),

    [_RAISE] = LAYOUT(
        _______, _______, KC_AT,   KC_DLR,  KC_HASH, _______,                                             _______, _______, KC_CIRC, _______, _______,  _______,
        _______, _______, KC_LT,   KC_EQL,  KC_GT,   KC_GRV,                                              _______, KC_LBRC, KC_UNDS, KC_RBRC, _______,  _______,
        _______, KC_BSLS, KC_LPRN, KC_MINS, KC_RPRN, KC_PLUS,                                             KC_PERC, KC_LCBR, KC_SCLN, KC_RCBR, KC_EXLM,  _______,
        _______, _______, KC_ASTR, KC_COLN, KC_SLSH, _______,                                             _______, KC_PIPE, KC_TILD, KC_AMPR, _______,  _______,
                          _______, _______, _______, ADJUST, _______, _______,         _______, _______, _______, _______, _______, _______,
                                                                      _______,         _______
    ),

    [_ADJUST] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, DM_PLY1, DM_REC1,
        _______, _______, _______, _______, _______, _______,                                              _______, KC_VOLD, KC_MUTE, KC_VOLU, DM_PLY2, DM_REC2,
        _______, _______, _______, _______, _______, _______,                                              _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, DM_RSTP,
                          _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
                                                                       _______,          _______
    ),

    [_FOUR] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______, _______,
        _______, EH_SCR,  KC_BTN3, KC_BTN2, KC_BTN1, EH_SNP,                                               _______, _______, _______, _______, _______, _______,
        ENC_MODE_TAB, ENC_MODE_DESKTOP, ENC_MODE_APP, _______, _______, EH_TXT,                            _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
                                                                       _______,          _______
    ),

    [_TEN] = LAYOUT(
        _______,  ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE,                                         ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE, _______,
        _______,  ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE,                                         ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE, _______,
        KC_LSFT,  ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE,                                         ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE, _______,  _______,
        _______,  ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE, ENC_CODE,                                         ENC_CODE, ENC_CODE, _______,  _______,  _______,  _______,
                          _______, _______, _______, TO(_BASE), ENC_DEL4, MO(_BASE),     _______, _______, _______, _______, _______, _______,
                                                                       ENC_BSPC4, _______
    ),
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(_______, _______)},
    [2] = {ENCODER_CCW_CW(_______, _______)},
    [3] = {ENCODER_CCW_CW(_______, _______)},
    [4] = {ENCODER_CCW_CW(_______, _______)},
    [_TEN] = {ENCODER_CCW_CW(_______, _______)},
};
#endif

typedef union {
    uint32_t raw;
    struct {
        uint8_t text_mode : 3;
        uint8_t scroll_mode : 3;
        uint8_t sniper_mode : 2;
        uint8_t dpi_mode : 4;
        bool    invert_scroll : 1;
        bool    acceleration : 1;
    };
} vial_config_t;

static vial_config_t vial_config;

const int     DPI_TABLE[15]    = {100, 200, 300, 400, 500, 600, 800, 1000, 1200, 1600, 2000, 2500, 3200, 4000, 5000};
const int32_t SNIPER_TABLE[15] = {2, 3, 4, 5};
const int32_t SCROLL_TABLE[15] = {6, 8, 11, 16, 23, 32, 45, 64};
const int32_t TEXT_TABLE[15]   = {6, 8, 11, 16, 23, 32, 45, 64};

int get_dpi(uint8_t dpi_mode) {
    if (dpi_mode < ARRAY_SIZE(DPI_TABLE))
        return DPI_TABLE[dpi_mode];
    else
        return DPI_TABLE[0];
}

void via_set_layout_options_kb(uint32_t value) {
    dprintf("via_set_layout_options_kb %lx\n", value);
    vial_config.raw = value;
    pointing_device_set_cpi(get_dpi(vial_config.dpi_mode));
    set_scroll_sens(SCROLL_TABLE[vial_config.scroll_mode]);
    set_sniper_sens(SNIPER_TABLE[vial_config.sniper_mode]);
    set_text_sens(TEXT_TABLE[vial_config.text_mode]);
    set_invert_scroll(vial_config.invert_scroll);
    set_acceleration(vial_config.acceleration);
}

void keyboard_post_init_user(void) {
    vial_config.raw = via_get_layout_options();
    via_set_layout_options_kb(vial_config.raw);
    set_led_blinks(false);
}

static void tap_seq4(const uint16_t seq[4]) {
    for (uint8_t i = 0; i < 4; i++) {
        tap_code16(pgm_read_word(&seq[i]));
    }
}

static bool shift_active(void) {
    return (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
}

static void run_encoding_macro(const uint16_t lower[4], const uint16_t upper[4], bool shifted) {
    tap_seq4(shifted ? upper : lower);
}

static bool is_encoding_keycode(uint16_t keycode) {
    switch (keycode) {
        case ENC_CODE:
        case ENC_DEL4:
        case ENC_BSPC4:
            return true;
        default:
            return false;
    }
}

typedef enum {
    ENCODER_MODE_VOL = 0,
    ENCODER_MODE_TABS,
    ENCODER_MODE_DESKTOPS,
    ENCODER_MODE_APPS,
} encoder_mode_t;

static encoder_mode_t encoder_mode = ENCODER_MODE_VOL;

static void set_encoder_mode(encoder_mode_t mode) {
    encoder_mode = mode;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENC_MODE_TAB:
        case ENC_MODE_DESKTOP:
        case ENC_MODE_APP: {
            static uint16_t       press_timer      = 0;
            static encoder_mode_t prev_encoder_mode = ENCODER_MODE_VOL;

            const encoder_mode_t new_mode = (keycode == ENC_MODE_TAB) ? ENCODER_MODE_TABS
                                           : (keycode == ENC_MODE_DESKTOP) ? ENCODER_MODE_DESKTOPS
                                                                           : ENCODER_MODE_APPS;

            if (record->event.pressed) {
                prev_encoder_mode = encoder_mode;
                set_encoder_mode(new_mode);
                press_timer = timer_read();
            } else {
                if (timer_elapsed(press_timer) < get_tapping_term(keycode, record)) {
                    if (prev_encoder_mode == new_mode) {
                        set_encoder_mode(ENCODER_MODE_VOL);
                    } else {
                        set_encoder_mode(new_mode);
                    }
                } else {
                    set_encoder_mode(ENCODER_MODE_VOL);
                }
            }
            return false;
        }
    }

    if (!is_encoding_keycode(keycode)) {
        return true;
    }

    if (!record->event.pressed) {
        return true;
    }

    const bool shifted = shift_active();
    const uint8_t saved_mods = get_mods();
    const uint8_t saved_oneshot_mods = get_oneshot_mods();

    clear_mods();
    clear_oneshot_mods();

    bool handled = true;
    if (keycode == ENC_DEL4) {
        tap_code(KC_DEL);
        tap_code(KC_DEL);
        tap_code(KC_DEL);
        tap_code(KC_DEL);
    } else if (keycode == ENC_BSPC4) {
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
    } else if (keycode == ENC_CODE) {
        const uint8_t row = record->event.key.row;
        const uint8_t col = record->event.key.col;

        handled = true;

        // Explicit per-position mapping
        {
            handled = true;
            // Digits
            if (row == 0 && col == 1) tap_seq4(enc_num_1);
            else if (row == 0 && col == 2) tap_seq4(enc_num_2);
            else if (row == 0 && col == 3) tap_seq4(enc_num_3);
            else if (row == 0 && col == 4) tap_seq4(enc_num_4);
            else if (row == 0 && col == 5) tap_seq4(enc_num_5);
            else if (row == 6 && col == 0) tap_seq4(enc_num_0);
            else if (row == 6 && col == 1) tap_seq4(enc_num_9);
            else if (row == 6 && col == 2) tap_seq4(enc_num_8);
            else if (row == 6 && col == 3) tap_seq4(enc_num_7);
            else if (row == 6 && col == 4) tap_seq4(enc_num_6);

            // QWERTY
            else if (row == 1 && col == 1) run_encoding_macro(enc_lower_Q, enc_upper_Q, shifted);
            else if (row == 1 && col == 2) run_encoding_macro(enc_lower_W, enc_upper_W, shifted);
            else if (row == 1 && col == 3) run_encoding_macro(enc_lower_E, enc_upper_E, shifted);
            else if (row == 1 && col == 4) run_encoding_macro(enc_lower_R, enc_upper_R, shifted);
            else if (row == 1 && col == 5) run_encoding_macro(enc_lower_T, enc_upper_T, shifted);

            else if (row == 7 && col == 1) run_encoding_macro(enc_lower_P, enc_upper_P, shifted);
            else if (row == 7 && col == 2) run_encoding_macro(enc_lower_O, enc_upper_O, shifted);
            else if (row == 7 && col == 3) run_encoding_macro(enc_lower_I, enc_upper_I, shifted);
            else if (row == 7 && col == 4) run_encoding_macro(enc_lower_U, enc_upper_U, shifted);
            else if (row == 7 && col == 5) run_encoding_macro(enc_lower_Y, enc_upper_Y, shifted);

            // ASDFG / HJKL
            else if (row == 2 && col == 1) run_encoding_macro(enc_lower_A, enc_upper_A, shifted);
            else if (row == 2 && col == 2) run_encoding_macro(enc_lower_S, enc_upper_S, shifted);
            else if (row == 2 && col == 3) run_encoding_macro(enc_lower_D, enc_upper_D, shifted);
            else if (row == 2 && col == 4) run_encoding_macro(enc_lower_F, enc_upper_F, shifted);
            else if (row == 2 && col == 5) run_encoding_macro(enc_lower_G, enc_upper_G, shifted);

            else if (row == 8 && col == 1) run_encoding_macro(enc_lower_L, enc_upper_L, shifted);
            else if (row == 8 && col == 2) run_encoding_macro(enc_lower_K, enc_upper_K, shifted);
            else if (row == 8 && col == 3) run_encoding_macro(enc_lower_J, enc_upper_J, shifted);
            else if (row == 8 && col == 4) run_encoding_macro(enc_lower_H, enc_upper_H, shifted);

            // ZXCVB / NM
            else if (row == 3 && col == 1) run_encoding_macro(enc_lower_Z, enc_upper_Z, shifted);
            else if (row == 3 && col == 2) run_encoding_macro(enc_lower_X, enc_upper_X, shifted);
            else if (row == 3 && col == 3) run_encoding_macro(enc_lower_C, enc_upper_C, shifted);
            else if (row == 3 && col == 4) run_encoding_macro(enc_lower_V, enc_upper_V, shifted);
            else if (row == 3 && col == 5) run_encoding_macro(enc_lower_B, enc_upper_B, shifted);

            else if (row == 9 && col == 4) run_encoding_macro(enc_lower_M, enc_upper_M, shifted);
            else if (row == 9 && col == 5) run_encoding_macro(enc_lower_N, enc_upper_N, shifted);
            else handled = false;
        }
    } else {
        handled = false;
    }

    set_mods(saved_mods);
    set_oneshot_mods(saved_oneshot_mods);

    return !handled;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index != 0) {
        return true;
    }

    const bool reverse = !clockwise;
    const bool mac = split_get_mac();

    switch (encoder_mode) {
        case ENCODER_MODE_TABS:
            tap_code16(reverse ? S(C(KC_TAB)) : C(KC_TAB));
            return false;

        case ENCODER_MODE_DESKTOPS:
            if (mac) {
                tap_code16(reverse ? C(KC_LEFT) : C(KC_RGHT));
            } else {
                tap_code16(reverse ? C(G(KC_LEFT)) : C(G(KC_RGHT)));
            }
            return false;

        case ENCODER_MODE_APPS:
            if (mac) {
                tap_code16(reverse ? S(G(KC_TAB)) : G(KC_TAB));
            } else {
                tap_code16(reverse ? S(A(KC_TAB)) : A(KC_TAB));
            }
            return false;

        case ENCODER_MODE_VOL:
        default:
            tap_code16(reverse ? KC_VOLD : KC_VOLU);
            return false;
    }
}
