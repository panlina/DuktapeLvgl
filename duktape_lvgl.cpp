#include <duktape.h>
#include <lvgl.h>

static duk_ret_t js_lv_btn_create(duk_context *ctx) {
	auto btn = lv_btn_create(lv_scr_act());
	duk_push_pointer(ctx, btn);
	return 1;
}

static duk_ret_t js_lv_obj_set_size(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto w = (lv_coord_t)duk_get_int(ctx, 1);
	auto h = (lv_coord_t)duk_get_int(ctx, 2);
	lv_obj_set_size(obj, w, h);
	return 0;
}

static const char *lvgljs =
	#include "lvgl.js"
;

void duktape_lvgl_install(duk_context *ctx) {
	duk_push_c_function(ctx, js_lv_btn_create, 0);
	duk_put_global_string(ctx, "lv_btn_create");
	duk_push_c_function(ctx, js_lv_obj_set_size, 3);
	duk_put_global_string(ctx, "lv_obj_set_size");

	duk_push_string(ctx, lvgljs);
	duk_int_t rc = duk_peval(ctx);
	duk_pop(ctx);
}
