#include <duktape.h>
#include <lvgl.h>

void duktape_lvgl_define_alignments(duk_context *ctx) {
	duk_push_uint(ctx, LV_ALIGN_DEFAULT);
	duk_put_global_string(ctx, "LV_ALIGN_DEFAULT");
	duk_push_uint(ctx, LV_ALIGN_TOP_LEFT);
	duk_put_global_string(ctx, "LV_ALIGN_TOP_LEFT");
	duk_push_uint(ctx, LV_ALIGN_TOP_MID);
	duk_put_global_string(ctx, "LV_ALIGN_TOP_MID");
	duk_push_uint(ctx, LV_ALIGN_TOP_RIGHT);
	duk_put_global_string(ctx, "LV_ALIGN_TOP_RIGHT");
	duk_push_uint(ctx, LV_ALIGN_BOTTOM_LEFT);
	duk_put_global_string(ctx, "LV_ALIGN_BOTTOM_LEFT");
	duk_push_uint(ctx, LV_ALIGN_BOTTOM_MID);
	duk_put_global_string(ctx, "LV_ALIGN_BOTTOM_MID");
	duk_push_uint(ctx, LV_ALIGN_BOTTOM_RIGHT);
	duk_put_global_string(ctx, "LV_ALIGN_BOTTOM_RIGHT");
	duk_push_uint(ctx, LV_ALIGN_LEFT_MID);
	duk_put_global_string(ctx, "LV_ALIGN_LEFT_MID");
	duk_push_uint(ctx, LV_ALIGN_RIGHT_MID);
	duk_put_global_string(ctx, "LV_ALIGN_RIGHT_MID");
	duk_push_uint(ctx, LV_ALIGN_CENTER);
	duk_put_global_string(ctx, "LV_ALIGN_CENTER");
	duk_push_uint(ctx, LV_ALIGN_OUT_TOP_LEFT);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_TOP_LEFT");
	duk_push_uint(ctx, LV_ALIGN_OUT_TOP_MID);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_TOP_MID");
	duk_push_uint(ctx, LV_ALIGN_OUT_TOP_RIGHT);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_TOP_RIGHT");
	duk_push_uint(ctx, LV_ALIGN_OUT_BOTTOM_LEFT);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_BOTTOM_LEFT");
	duk_push_uint(ctx, LV_ALIGN_OUT_BOTTOM_MID);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_BOTTOM_MID");
	duk_push_uint(ctx, LV_ALIGN_OUT_BOTTOM_RIGHT);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_BOTTOM_RIGHT");
	duk_push_uint(ctx, LV_ALIGN_OUT_LEFT_TOP);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_LEFT_TOP");
	duk_push_uint(ctx, LV_ALIGN_OUT_LEFT_MID);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_LEFT_MID");
	duk_push_uint(ctx, LV_ALIGN_OUT_LEFT_BOTTOM);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_LEFT_BOTTOM");
	duk_push_uint(ctx, LV_ALIGN_OUT_RIGHT_TOP);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_RIGHT_TOP");
	duk_push_uint(ctx, LV_ALIGN_OUT_RIGHT_MID);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_RIGHT_MID");
	duk_push_uint(ctx, LV_ALIGN_OUT_RIGHT_BOTTOM);
	duk_put_global_string(ctx, "LV_ALIGN_OUT_RIGHT_BOTTOM");
}

void duktape_lvgl_define_events(duk_context *ctx) {
	duk_push_uint(ctx, LV_EVENT_ALL);
	duk_put_global_string(ctx, "LV_EVENT_ALL");

	/** Input device events*/
	duk_push_uint(ctx, LV_EVENT_PRESSED);
	duk_put_global_string(ctx, "LV_EVENT_PRESSED");
	duk_push_uint(ctx, LV_EVENT_PRESSING);
	duk_put_global_string(ctx, "LV_EVENT_PRESSING");
	duk_push_uint(ctx, LV_EVENT_PRESS_LOST);
	duk_put_global_string(ctx, "LV_EVENT_PRESS_LOST");
	duk_push_uint(ctx, LV_EVENT_SHORT_CLICKED);
	duk_put_global_string(ctx, "LV_EVENT_SHORT_CLICKED");
	duk_push_uint(ctx, LV_EVENT_LONG_PRESSED);
	duk_put_global_string(ctx, "LV_EVENT_LONG_PRESSED");
	duk_push_uint(ctx, LV_EVENT_LONG_PRESSED_REPEAT);
	duk_put_global_string(ctx, "LV_EVENT_LONG_PRESSED_REPEAT");
	duk_push_uint(ctx, LV_EVENT_CLICKED);
	duk_put_global_string(ctx, "LV_EVENT_CLICKED");
	duk_push_uint(ctx, LV_EVENT_RELEASED);
	duk_put_global_string(ctx, "LV_EVENT_RELEASED");
	duk_push_uint(ctx, LV_EVENT_SCROLL_BEGIN);
	duk_put_global_string(ctx, "LV_EVENT_SCROLL_BEGIN");
	duk_push_uint(ctx, LV_EVENT_SCROLL_END);
	duk_put_global_string(ctx, "LV_EVENT_SCROLL_END");
	duk_push_uint(ctx, LV_EVENT_SCROLL);
	duk_put_global_string(ctx, "LV_EVENT_SCROLL");
	duk_push_uint(ctx, LV_EVENT_GESTURE);
	duk_put_global_string(ctx, "LV_EVENT_GESTURE");
	duk_push_uint(ctx, LV_EVENT_KEY);
	duk_put_global_string(ctx, "LV_EVENT_KEY");
	duk_push_uint(ctx, LV_EVENT_FOCUSED);
	duk_put_global_string(ctx, "LV_EVENT_FOCUSED");
	duk_push_uint(ctx, LV_EVENT_DEFOCUSED);
	duk_put_global_string(ctx, "LV_EVENT_DEFOCUSED");
	duk_push_uint(ctx, LV_EVENT_LEAVE);
	duk_put_global_string(ctx, "LV_EVENT_LEAVE");
	duk_push_uint(ctx, LV_EVENT_HIT_TEST);
	duk_put_global_string(ctx, "LV_EVENT_HIT_TEST");

	/** Drawing events*/
	duk_push_uint(ctx, LV_EVENT_COVER_CHECK);
	duk_put_global_string(ctx, "LV_EVENT_COVER_CHECK");
	duk_push_uint(ctx, LV_EVENT_REFR_EXT_DRAW_SIZE);
	duk_put_global_string(ctx, "LV_EVENT_REFR_EXT_DRAW_SIZE");
	duk_push_uint(ctx, LV_EVENT_DRAW_MAIN_BEGIN);
	duk_put_global_string(ctx, "LV_EVENT_DRAW_MAIN_BEGIN");
	duk_push_uint(ctx, LV_EVENT_DRAW_MAIN);
	duk_put_global_string(ctx, "LV_EVENT_DRAW_MAIN");
	duk_push_uint(ctx, LV_EVENT_DRAW_MAIN_END);
	duk_put_global_string(ctx, "LV_EVENT_DRAW_MAIN_END");
	duk_push_uint(ctx, LV_EVENT_DRAW_POST_BEGIN);
	duk_put_global_string(ctx, "LV_EVENT_DRAW_POST_BEGIN");
	duk_push_uint(ctx, LV_EVENT_DRAW_POST);
	duk_put_global_string(ctx, "LV_EVENT_DRAW_POST");
	duk_push_uint(ctx, LV_EVENT_DRAW_POST_END);
	duk_put_global_string(ctx, "LV_EVENT_DRAW_POST_END");
	duk_push_uint(ctx, LV_EVENT_DRAW_PART_BEGIN);
	duk_put_global_string(ctx, "LV_EVENT_DRAW_PART_BEGIN");
	duk_push_uint(ctx, LV_EVENT_DRAW_PART_END);
	duk_put_global_string(ctx, "LV_EVENT_DRAW_PART_END");

	/** Special events*/
	duk_push_uint(ctx, LV_EVENT_VALUE_CHANGED);
	duk_put_global_string(ctx, "LV_EVENT_VALUE_CHANGED");
	duk_push_uint(ctx, LV_EVENT_INSERT);
	duk_put_global_string(ctx, "LV_EVENT_INSERT");
	duk_push_uint(ctx, LV_EVENT_REFRESH);
	duk_put_global_string(ctx, "LV_EVENT_REFRESH");
	duk_push_uint(ctx, LV_EVENT_READY);
	duk_put_global_string(ctx, "LV_EVENT_READY");
	duk_push_uint(ctx, LV_EVENT_CANCEL);
	duk_put_global_string(ctx, "LV_EVENT_CANCEL");

	/** Other events*/
	duk_push_uint(ctx, LV_EVENT_DELETE);
	duk_put_global_string(ctx, "LV_EVENT_DELETE");
	duk_push_uint(ctx, LV_EVENT_CHILD_CHANGED);
	duk_put_global_string(ctx, "LV_EVENT_CHILD_CHANGED");
	duk_push_uint(ctx, LV_EVENT_CHILD_CREATED);
	duk_put_global_string(ctx, "LV_EVENT_CHILD_CREATED");
	duk_push_uint(ctx, LV_EVENT_CHILD_DELETED);
	duk_put_global_string(ctx, "LV_EVENT_CHILD_DELETED");
	duk_push_uint(ctx, LV_EVENT_SCREEN_UNLOAD_START);
	duk_put_global_string(ctx, "LV_EVENT_SCREEN_UNLOAD_START");
	duk_push_uint(ctx, LV_EVENT_SCREEN_LOAD_START);
	duk_put_global_string(ctx, "LV_EVENT_SCREEN_LOAD_START");
	duk_push_uint(ctx, LV_EVENT_SCREEN_LOADED);
	duk_put_global_string(ctx, "LV_EVENT_SCREEN_LOADED");
	duk_push_uint(ctx, LV_EVENT_SCREEN_UNLOADED);
	duk_put_global_string(ctx, "LV_EVENT_SCREEN_UNLOADED");
	duk_push_uint(ctx, LV_EVENT_SIZE_CHANGED);
	duk_put_global_string(ctx, "LV_EVENT_SIZE_CHANGED");
	duk_push_uint(ctx, LV_EVENT_STYLE_CHANGED);
	duk_put_global_string(ctx, "LV_EVENT_STYLE_CHANGED");
	duk_push_uint(ctx, LV_EVENT_LAYOUT_CHANGED);
	duk_put_global_string(ctx, "LV_EVENT_LAYOUT_CHANGED");
	duk_push_uint(ctx, LV_EVENT_GET_SELF_SIZE);
	duk_put_global_string(ctx, "LV_EVENT_GET_SELF_SIZE");

	duk_push_uint(ctx, _LV_EVENT_LAST);
	duk_put_global_string(ctx, "_LV_EVENT_LAST");

	duk_push_uint(ctx, LV_EVENT_PREPROCESS);
	duk_put_global_string(ctx, "LV_EVENT_PREPROCESS");
}
