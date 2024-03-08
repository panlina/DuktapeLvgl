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

static duk_ret_t js_lv_scr_act(duk_context *ctx) {
	auto obj = lv_scr_act();
	duk_push_pointer(ctx, obj);
	return 1;
}

static duk_ret_t js_lv_layer_top(duk_context *ctx) {
	auto obj = lv_layer_top();
	duk_push_pointer(ctx, obj);
	return 1;
}

static duk_ret_t js_lv_layer_sys(duk_context *ctx) {
	auto obj = lv_layer_sys();
	duk_push_pointer(ctx, obj);
	return 1;
}

static void lv_obj_init(lv_obj_t *obj);

static duk_ret_t js_lv_obj_create(duk_context *ctx) {
	auto parent = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto obj = lv_obj_create(parent);
	duk_push_pointer(ctx, obj);
	lv_obj_init(obj);
	return 1;
}

static void lv_obj_init(lv_obj_t *obj) {
	lv_obj_add_event_cb(obj, [](lv_event_t *e) {
		auto obj = lv_event_get_target(e);
		for (auto i = 1; i < obj->spec_attr->event_dsc_cnt; i++)
			delete (function<void(lv_event_t *)> *)obj->spec_attr->event_dsc[i].user_data;
	}, LV_EVENT_DELETE, nullptr);
}

static duk_ret_t js_lv_btn_create(duk_context *ctx) {
	auto parent = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto btn = lv_btn_create(parent);
	duk_push_pointer(ctx, btn);
	lv_obj_init(btn);
	return 1;
}

static duk_ret_t js_lv_label_create(duk_context *ctx) {
	auto parent = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto label = lv_label_create(parent);
	duk_push_pointer(ctx, label);
	lv_obj_init(label);
	return 1;
}

static duk_ret_t js_lv_obj_set_size(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto w = (lv_coord_t)duk_get_int(ctx, 1);
	auto h = (lv_coord_t)duk_get_int(ctx, 2);
	lv_obj_set_size(obj, w, h);
	return 0;
}

static duk_ret_t js_lv_obj_set_align(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto align = (lv_align_t)duk_get_uint(ctx, 1);
	lv_obj_set_align(obj, align);
	return 0;
}

static duk_ret_t js_lv_obj_set_style_border_width(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto value = duk_get_int(ctx, 1);
	auto selector = duk_get_uint(ctx, 2);
	lv_obj_set_style_border_width(obj, value, selector);
	return 0;
}

static duk_ret_t js_lv_obj_set_style_pad_all(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto value = duk_get_int(ctx, 1);
	auto selector = duk_get_uint(ctx, 2);
	lv_obj_set_style_pad_all(obj, value, selector);
	return 0;
}

static duk_ret_t js_lv_obj_set_style_bg_color(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto value = duk_get_uint(ctx, 1);
	auto selector = duk_get_uint(ctx, 2);
	lv_obj_set_style_bg_color(obj, lv_color_t{.full = value}, selector);
	return 0;
}

static duk_ret_t js_lv_obj_set_style_text_color(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto value = duk_get_uint(ctx, 1);
	auto selector = duk_get_uint(ctx, 2);
	lv_obj_set_style_text_color(obj, lv_color_t{.full = value}, selector);
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
		duk_push_pointer(ctx, e);
		duk_call(ctx, 1);
		duk_pop_2(ctx);
	});
	lv_obj_add_event_cb(
		obj, [](lv_event_t *e) {
			auto user_data = (function<void(lv_event_t *)> *)lv_event_get_user_data(e);
			(*user_data)(e);
		},
		filter, user_data
	);
	stashId++;
	return 0;
}

static duk_ret_t js_lv_obj_del(duk_context *ctx) {
	auto obj = (lv_obj_t *)duk_get_pointer(ctx, 0);
	lv_obj_del(obj);
	return 0;
}

static duk_ret_t js_lv_label_set_text(duk_context *ctx) {
	auto label = (lv_obj_t *)duk_get_pointer(ctx, 0);
	auto text = duk_get_string(ctx, 1);
	lv_label_set_text(label, text);
	return 0;
}

static duk_ret_t js_lv_event_get_target(duk_context *ctx) {
	auto event = (lv_event_t *)duk_get_pointer(ctx, 0);
	auto target = lv_event_get_target(event);
	duk_push_pointer(ctx, target);
	return 1;
}

static duk_ret_t js_lv_event_get_current_target(duk_context *ctx) {
	auto event = (lv_event_t *)duk_get_pointer(ctx, 0);
	auto target = lv_event_get_current_target(event);
	duk_push_pointer(ctx, target);
	return 1;
}

static duk_ret_t js_lv_event_get_code(duk_context *ctx) {
	auto event = (lv_event_t *)duk_get_pointer(ctx, 0);
	auto code = lv_event_get_code(event);
	duk_push_uint(ctx, code);
	return 1;
}

static duk_ret_t js_lv_event_get_indev(duk_context *ctx) {
	auto event = (lv_event_t *)duk_get_pointer(ctx, 0);
	auto indev = lv_event_get_indev(event);
	duk_push_pointer(ctx, indev);
	return 1;
}

static duk_ret_t js_lv_indev_get_point(duk_context *ctx) {
	auto indev = (lv_indev_t *)duk_get_pointer(ctx, 0);
	auto obj = duk_push_object(ctx);
	lv_point_t point;
	lv_indev_get_point(indev, &point);
	duk_push_int(ctx, point.x);
	duk_put_prop_string(ctx, obj, "x");
	duk_push_int(ctx, point.y);
	duk_put_prop_string(ctx, obj, "y");
	return 1;
}

static duk_ret_t js_lv_color_hex(duk_context *ctx) {
	auto hex = (uint32_t)duk_get_uint(ctx, 0);
	auto color = lv_color_hex(hex);
	duk_push_uint(ctx, color.full);
	return 1;
}

static const char *lvgljs =
	#include "lvgl.js"
;

void duktape_lvgl_install(duk_context *ctx) {
	duk_push_c_function(ctx, js_lv_scr_act, 0);
	duk_put_global_string(ctx, "lv_scr_act");
	duk_push_c_function(ctx, js_lv_layer_top, 0);
	duk_put_global_string(ctx, "lv_layer_top");
	duk_push_c_function(ctx, js_lv_layer_sys, 0);
	duk_put_global_string(ctx, "lv_layer_sys");
	duk_push_c_function(ctx, js_lv_obj_create, 1);
	duk_put_global_string(ctx, "lv_obj_create");
	duk_push_c_function(ctx, js_lv_btn_create, 1);
	duk_put_global_string(ctx, "lv_btn_create");
	duk_push_c_function(ctx, js_lv_label_create, 1);
	duk_put_global_string(ctx, "lv_label_create");
	duk_push_c_function(ctx, js_lv_obj_set_size, 3);
	duk_put_global_string(ctx, "lv_obj_set_size");
	duk_push_c_function(ctx, js_lv_obj_set_align, 2);
	duk_put_global_string(ctx, "lv_obj_set_align");
	duk_push_c_function(ctx, js_lv_obj_set_style_border_width, 3);
	duk_put_global_string(ctx, "lv_obj_set_style_border_width");
	duk_push_c_function(ctx, js_lv_obj_set_style_pad_all, 3);
	duk_put_global_string(ctx, "lv_obj_set_style_pad_all");
	duk_push_c_function(ctx, js_lv_obj_set_style_bg_color, 3);
	duk_put_global_string(ctx, "lv_obj_set_style_bg_color");
	duk_push_c_function(ctx, js_lv_obj_set_style_text_color, 3);
	duk_put_global_string(ctx, "lv_obj_set_style_text_color");
	duk_push_c_function(ctx, js_lv_obj_add_event_cb, 3);
	duk_put_global_string(ctx, "lv_obj_add_event_cb");
	duk_push_c_function(ctx, js_lv_obj_del, 1);
	duk_put_global_string(ctx, "lv_obj_del");
	duk_push_c_function(ctx, js_lv_label_set_text, 2);
	duk_put_global_string(ctx, "lv_label_set_text");
	duk_push_c_function(ctx, js_lv_event_get_target, 1);
	duk_put_global_string(ctx, "lv_event_get_target");
	duk_push_c_function(ctx, js_lv_event_get_current_target, 1);
	duk_put_global_string(ctx, "lv_event_get_current_target");
	duk_push_c_function(ctx, js_lv_event_get_code, 1);
	duk_put_global_string(ctx, "lv_event_get_code");
	duk_push_c_function(ctx, js_lv_event_get_indev, 1);
	duk_put_global_string(ctx, "lv_event_get_indev");
	duk_push_c_function(ctx, js_lv_indev_get_point, 1);
	duk_put_global_string(ctx, "lv_indev_get_point");
	duk_push_c_function(ctx, js_lv_color_hex, 1);
	duk_put_global_string(ctx, "lv_color_hex");
	duk_push_uint(ctx, LV_EVENT_CLICKED);
	duk_put_global_string(ctx, "LV_EVENT_CLICKED");
	duk_push_uint(ctx, LV_PART_MAIN);
	duk_put_global_string(ctx, "LV_PART_MAIN");

	void duktape_lvgl_define_alignments(duk_context * ctx);
	duktape_lvgl_define_alignments(ctx);
	void duktape_lvgl_define_events(duk_context * ctx);
	duktape_lvgl_define_events(ctx);

	duk_push_string(ctx, lvgljs);
	duk_int_t rc = duk_peval(ctx);
	duk_pop(ctx);
}
