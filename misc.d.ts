declare const LV_ALIGN_DEFAULT: number;
declare const LV_ALIGN_TOP_LEFT: number;
declare const LV_ALIGN_TOP_MID: number;
declare const LV_ALIGN_TOP_RIGHT: number;
declare const LV_ALIGN_BOTTOM_LEFT: number;
declare const LV_ALIGN_BOTTOM_MID: number;
declare const LV_ALIGN_BOTTOM_RIGHT: number;
declare const LV_ALIGN_LEFT_MID: number;
declare const LV_ALIGN_RIGHT_MID: number;
declare const LV_ALIGN_CENTER: number;
declare const LV_ALIGN_OUT_TOP_LEFT: number;
declare const LV_ALIGN_OUT_TOP_MID: number;
declare const LV_ALIGN_OUT_TOP_RIGHT: number;
declare const LV_ALIGN_OUT_BOTTOM_LEFT: number;
declare const LV_ALIGN_OUT_BOTTOM_MID: number;
declare const LV_ALIGN_OUT_BOTTOM_RIGHT: number;
declare const LV_ALIGN_OUT_LEFT_TOP: number;
declare const LV_ALIGN_OUT_LEFT_MID: number;
declare const LV_ALIGN_OUT_LEFT_BOTTOM: number;
declare const LV_ALIGN_OUT_RIGHT_TOP: number;
declare const LV_ALIGN_OUT_RIGHT_MID: number;
declare const LV_ALIGN_OUT_RIGHT_BOTTOM: number;

declare const LV_OBJ_FLAG_HIDDEN: number;
declare const LV_OBJ_FLAG_CLICKABLE: number;
declare const LV_OBJ_FLAG_CLICK_FOCUSABLE: number;
declare const LV_OBJ_FLAG_CHECKABLE: number;
declare const LV_OBJ_FLAG_SCROLLABLE: number;
declare const LV_OBJ_FLAG_SCROLL_ELASTIC: number;
declare const LV_OBJ_FLAG_SCROLL_MOMENTUM: number;
declare const LV_OBJ_FLAG_SCROLL_ONE: number;
declare const LV_OBJ_FLAG_SCROLL_CHAIN_HOR: number;
declare const LV_OBJ_FLAG_SCROLL_CHAIN_VER: number;
declare const LV_OBJ_FLAG_SCROLL_CHAIN: number;
declare const LV_OBJ_FLAG_SCROLL_ON_FOCUS: number;
declare const LV_OBJ_FLAG_SCROLL_WITH_ARROW: number;
declare const LV_OBJ_FLAG_SNAPPABLE: number;
declare const LV_OBJ_FLAG_PRESS_LOCK: number;
declare const LV_OBJ_FLAG_EVENT_BUBBLE: number;
declare const LV_OBJ_FLAG_GESTURE_BUBBLE: number;
declare const LV_OBJ_FLAG_ADV_HITTEST: number;
declare const LV_OBJ_FLAG_IGNORE_LAYOUT: number;
declare const LV_OBJ_FLAG_FLOATING: number;
declare const LV_OBJ_FLAG_OVERFLOW_VISIBLE: number;
declare const LV_OBJ_FLAG_LAYOUT_1: number;
declare const LV_OBJ_FLAG_LAYOUT_2: number;
declare const LV_OBJ_FLAG_WIDGET_1: number;
declare const LV_OBJ_FLAG_WIDGET_2: number;
declare const LV_OBJ_FLAG_USER_1: number;
declare const LV_OBJ_FLAG_USER_2: number;
declare const LV_OBJ_FLAG_USER_3: number;
declare const LV_OBJ_FLAG_USER_4: number;

declare const LV_EVENT_ALL: number;
declare const LV_EVENT_PRESSED: number;
declare const LV_EVENT_PRESSING: number;
declare const LV_EVENT_PRESS_LOST: number;
declare const LV_EVENT_SHORT_CLICKED: number;
declare const LV_EVENT_LONG_PRESSED: number;
declare const LV_EVENT_LONG_PRESSED_REPEAT: number;
declare const LV_EVENT_CLICKED: number;
declare const LV_EVENT_RELEASED: number;
declare const LV_EVENT_SCROLL_BEGIN: number;
declare const LV_EVENT_SCROLL_END: number;
declare const LV_EVENT_SCROLL: number;
declare const LV_EVENT_GESTURE: number;
declare const LV_EVENT_KEY: number;
declare const LV_EVENT_FOCUSED: number;
declare const LV_EVENT_DEFOCUSED: number;
declare const LV_EVENT_LEAVE: number;
declare const LV_EVENT_HIT_TEST: number;
declare const LV_EVENT_COVER_CHECK: number;
declare const LV_EVENT_REFR_EXT_DRAW_SIZE: number;
declare const LV_EVENT_DRAW_MAIN_BEGIN: number;
declare const LV_EVENT_DRAW_MAIN: number;
declare const LV_EVENT_DRAW_MAIN_END: number;
declare const LV_EVENT_DRAW_POST_BEGIN: number;
declare const LV_EVENT_DRAW_POST: number;
declare const LV_EVENT_DRAW_POST_END: number;
declare const LV_EVENT_DRAW_PART_BEGIN: number;
declare const LV_EVENT_DRAW_PART_END: number;
declare const LV_EVENT_VALUE_CHANGED: number;
declare const LV_EVENT_INSERT: number;
declare const LV_EVENT_REFRESH: number;
declare const LV_EVENT_READY: number;
declare const LV_EVENT_CANCEL: number;
declare const LV_EVENT_DELETE: number;
declare const LV_EVENT_CHILD_CHANGED: number;
declare const LV_EVENT_CHILD_CREATED: number;
declare const LV_EVENT_CHILD_DELETED: number;
declare const LV_EVENT_SCREEN_UNLOAD_START: number;
declare const LV_EVENT_SCREEN_LOAD_START: number;
declare const LV_EVENT_SCREEN_LOADED: number;
declare const LV_EVENT_SCREEN_UNLOADED: number;
declare const LV_EVENT_SIZE_CHANGED: number;
declare const LV_EVENT_STYLE_CHANGED: number;
declare const LV_EVENT_LAYOUT_CHANGED: number;
declare const LV_EVENT_GET_SELF_SIZE: number;
declare const _LV_EVENT_LAST: number;
declare const LV_EVENT_PREPROCESS: number;

declare const lv_font_montserrat_14: lv_font_t;
declare const lv_font_montserrat_24: lv_font_t;
declare const lv_font_montserrat_48: lv_font_t;
declare const LV_FONT_DEFAULT: lv_font_t;

declare const LV_IMG_CF_UNKNOWN: number;
declare const LV_IMG_CF_RAW: number;
declare const LV_IMG_CF_RAW_ALPHA: number;
declare const LV_IMG_CF_RAW_CHROMA_KEYED: number;
declare const LV_IMG_CF_TRUE_COLOR: number;
declare const LV_IMG_CF_TRUE_COLOR_ALPHA: number;
declare const LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED: number;
declare const LV_IMG_CF_INDEXED_1BIT: number;
declare const LV_IMG_CF_INDEXED_2BIT: number;
declare const LV_IMG_CF_INDEXED_4BIT: number;
declare const LV_IMG_CF_INDEXED_8BIT: number;
declare const LV_IMG_CF_ALPHA_1BIT: number;
declare const LV_IMG_CF_ALPHA_2BIT: number;
declare const LV_IMG_CF_ALPHA_4BIT: number;
declare const LV_IMG_CF_ALPHA_8BIT: number;
declare const LV_IMG_CF_RGB888: number;
declare const LV_IMG_CF_RGBA8888: number;
declare const LV_IMG_CF_RGBX8888: number;
declare const LV_IMG_CF_RGB565: number;
declare const LV_IMG_CF_RGBA5658: number;
declare const LV_IMG_CF_RGB565A8: number;
declare const LV_IMG_CF_RESERVED_15: number;
declare const LV_IMG_CF_RESERVED_16: number;
declare const LV_IMG_CF_RESERVED_17: number;
declare const LV_IMG_CF_RESERVED_18: number;
declare const LV_IMG_CF_RESERVED_19: number;
declare const LV_IMG_CF_RESERVED_20: number;
declare const LV_IMG_CF_RESERVED_21: number;
declare const LV_IMG_CF_RESERVED_22: number;
declare const LV_IMG_CF_RESERVED_23: number;
declare const LV_IMG_CF_USER_ENCODED_0: number;
declare const LV_IMG_CF_USER_ENCODED_1: number;
declare const LV_IMG_CF_USER_ENCODED_2: number;
declare const LV_IMG_CF_USER_ENCODED_3: number;
declare const LV_IMG_CF_USER_ENCODED_4: number;
declare const LV_IMG_CF_USER_ENCODED_5: number;
declare const LV_IMG_CF_USER_ENCODED_6: number;
declare const LV_IMG_CF_USER_ENCODED_7: number;