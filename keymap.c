#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// Layers
enum layers {
	BASE = 0,
	SYM,
	NAV,
};

enum custom_keycodes {
	PLACEHOLDER = SAFE_RANGE, // can always be here
	EPRM,
};

#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LSHFT OSM(MOD_LSFT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSL_SYM OSL(SYM)

/* Keymap Blank Template
 
	[BLANK] = LAYOUT_ergodox(
	
		// LEFT MAIN CLUSTER
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,					
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,					
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,	
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,					
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,

		// LEFT THUMB CLUSTER
					KC_TRANSPARENT,		KC_TRANSPARENT,
								KC_TRANSPARENT,
		KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,


		// RIGHT MAIN CLUSTER
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,					
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,					
					KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,	
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,					
								KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,	

		// RIGHT THUMB CLUSTER
		KC_TRANSPARENT,		KC_TRANSPARENT,
		KC_TRANSPARENT,
		KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT

	),
*/

// CTRL ALT WIN SHIFT L_SYMBOL L_NAV
// L_SYMBOL SHIFT WIN CTRL
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_ergodox(
	
		// LEFT MAIN CLUSTER
		KC_TRANSPARENT, 	KC_1,			KC_2,			KC_3,  			KC_4,			KC_5,			KC_TRANSPARENT,					
		KC_TAB,		 	KC_Q,			KC_W,			KC_E,	  		KC_R,			KC_T,			KC_ENTER,					
		KC_ESC,		 	KC_A,			KC_S,			KC_D,		  	KC_F,			KC_G,	
		KC_TRANSPARENT,	 	KC_Z,			KC_X,			KC_C,		  	KC_V,			KC_B,			KC_TRANSPARENT,						
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_SPACE,

		// LEFT THUMB CLUSTER
					KC_TRANSPARENT,		KC_TRANSPARENT,
								KC_TRANSPARENT,
		OSM_LSHFT,		OSM_LGUI,		KC_TRANSPARENT,

		// RIGHT MAIN CLUSTER
		KC_TRANSPARENT, 	KC_6,			KC_7,			KC_8,  			KC_9,			KC_0,			RESET,		
		KC_TRANSPARENT, 	KC_Y,			KC_U,			KC_I,	  		KC_O,			KC_P,			KC_TRANSPARENT,					
					KC_H,			KC_J,			KC_K,	  		KC_L,			KC_COLON,		KC_TRANSPARENT,	
		KC_TRANSPARENT, 	KC_N,			KC_M,			KC_COMMA,  		KC_DOT,			KC_BSPACE,		KC_TRANSPARENT,					
								KC_SPACE,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,

		// RIGHT THUMB CLUSTER
		KC_TRANSPARENT,		KC_TRANSPARENT,
		KC_TRANSPARENT,
		KC_TRANSPARENT,		OSM_LCTL,		OSL_SYM

	),
	[SYM] = LAYOUT_ergodox(
	
		// LEFT MAIN CLUSTER
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,					
		KC_TRANSPARENT, 	KC_TILDE,		KC_LCBR,		KC_LBRC,	  	KC_LPRN,		KC_MINUS,		KC_TRANSPARENT,					
		KC_TRANSPARENT, 	KC_EXLM,		KC_QUOTE,		KC_PERC,	  	KC_COLON,		KC_LABK,	
		KC_TRANSPARENT, 	KC_EQUAL,		KC_HASH,		KC_CIRC,	  	KC_SLASH,		KC_ASTR,		KC_TRANSPARENT,					
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,

		// LEFT THUMB CLUSTER
					KC_TRANSPARENT,		KC_TRANSPARENT,
								KC_TRANSPARENT,
		KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,


		// RIGHT MAIN CLUSTER
		KC_TRANSPARENT, 	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,					
		KC_TRANSPARENT, 	KC_UNDS,		KC_RPRN,		KC_RBRC,	  	KC_RCBR,		KC_PIPE,		KC_TRANSPARENT,					
					KC_RABK,		KC_SCOLON,		KC_AMPR,	  	KC_DQUO,		KC_QUES,		KC_TRANSPARENT,	
		KC_TRANSPARENT, 	KC_AT,			KC_BSLASH,		KC_TRANSPARENT,  	KC_DOLLAR,		KC_PLUS,		KC_TRANSPARENT,					
								KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT,  	KC_TRANSPARENT,		KC_TRANSPARENT,	

		// RIGHT THUMB CLUSTER
		KC_TRANSPARENT,		KC_TRANSPARENT,
		KC_TRANSPARENT,
		KC_TRANSPARENT,		KC_TRANSPARENT,		KC_TRANSPARENT

	)


};

const uint16_t PROGMEM fn_actions[] = {
	[1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
			switch(id) {
				case 0:
				if (record->event.pressed) {
					SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
				}
				break;
			}
		return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
	rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		// dynamically generate these.
		case EPRM:
			if (record->event.pressed) {
				eeconfig_init();
			}
			return false;
			break;
	}
	return true;
}

uint32_t layer_state_set_user(uint32_t state) {


		uint8_t layer = biton32(state);

		ergodox_board_led_off();
		ergodox_right_led_1_off();
		ergodox_right_led_2_off();
		ergodox_right_led_3_off();
		switch (layer) {
			case 0:
				#ifdef RGBLIGHT_COLOR_LAYER_0
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
				#endif
				break;
			case 1:
				ergodox_right_led_1_on();
				#ifdef RGBLIGHT_COLOR_LAYER_1
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
				#endif
				break;
			case 2:
				ergodox_right_led_2_on();
				#ifdef RGBLIGHT_COLOR_LAYER_2
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
				#endif
				break;
			case 3:
				ergodox_right_led_3_on();
				#ifdef RGBLIGHT_COLOR_LAYER_3
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
				#endif
				break;
			case 4:
				ergodox_right_led_1_on();
				ergodox_right_led_2_on();
				#ifdef RGBLIGHT_COLOR_LAYER_4
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
				#endif
				break;
			case 5:
				ergodox_right_led_1_on();
				ergodox_right_led_3_on();
				#ifdef RGBLIGHT_COLOR_LAYER_5
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
				#endif
				break;
			case 6:
				ergodox_right_led_2_on();
				ergodox_right_led_3_on();
				#ifdef RGBLIGHT_COLOR_LAYER_6
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
				#endif
				break;
			case 7:
				ergodox_right_led_1_on();
				ergodox_right_led_2_on();
				ergodox_right_led_3_on();
				#ifdef RGBLIGHT_COLOR_LAYER_7
					rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
				#endif
				break;
			default:
				break;
		}
		return state;
};
