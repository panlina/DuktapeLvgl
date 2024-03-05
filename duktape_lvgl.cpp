#include <duktape.h>
#include <lvgl.h>
#include <functional>

using std::function;

// from lv_event.c
typedef struct _lv_event_dsc_t {
	lv_event_cb_t cb;
	void * user_data;
	lv_event_code_t filter : 8;
} lv_event_dsc_t;

static duk_ret_t js_lv_btn_create(duk_context *ctx) {
	auto btn = lv_btn_create(lv_scr_act());
	duk_push_pointer(ctx, btn);

	lv_obj_add_event_cb(btn, [](lv_event_t *e) {
		auto obj = lv_event_get_target(e);
		for (auto i = 1; i < obj->spec_attr->event_dsc_cnt; i++)
			delete (function<void(lv_event_t *)> *)obj->spec_attr->event_dsc[i].user_data;
	}, LV_EVENT_DELETE, nullptr);

	return 1;
}

static duk_ret_t js_lv_obj_set_size(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto w = (lv_coord_t)duk_get_int(ctx, 1);
	auto h = (lv_coord_t)duk_get_int(ctx, 2);
	lv_obj_set_size(obj, w, h);
	return 0;
}

static unsigned long stashId = 0;

static duk_ret_t js_lv_obj_add_event_cb(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	duk_push_global_stash(ctx);
	duk_dup(ctx, 1);
	auto filter = (lv_event_code_t)duk_get_uint(ctx, 2);
	// [ obj, cb, filter, stash, cb]
	char s[8];
	itoa(stashId, s, 10);
	duk_put_prop_string(ctx, -2, s);
	// [ obj, cb, filter, stash ]
	auto _stashId = stashId;
	auto user_data = new function<void(lv_event_t *)>([=](lv_event_t *e) {
		auto stashId = _stashId;
		duk_push_global_stash(ctx);
		char s[8];
		itoa(stashId, s, 10);
		duk_get_prop_string(ctx, -1, s);
		duk_call(ctx, 0);
		duk_pop_2(ctx);
	});
	lv_obj_add_event_cb(
		obj, [](lv_event_t *e) {
			auto user_data = (function<void(lv_event_t *)> *)lv_event_get_user_data(e);
			(*user_data)(nullptr);
		},
		filter, user_data
	);
	stashId++;
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
	duk_push_c_function(ctx, js_lv_obj_add_event_cb, 3);
	duk_put_global_string(ctx, "lv_obj_add_event_cb");
	duk_push_uint(ctx, LV_EVENT_CLICKED);
	duk_put_global_string(ctx, "LV_EVENT_CLICKED");

	duk_push_string(ctx, lvgljs);
	duk_int_t rc = duk_peval(ctx);
	duk_pop(ctx);
}
