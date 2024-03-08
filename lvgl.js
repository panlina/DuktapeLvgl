/*
This file is to be #include'd in a cpp source. Following content is not a valid js source by intention.
Since it's not possible to use `#include` in `R"()"`, the opening and closing brackets (`R"(` and `)"`)
have to be written in the file itself. This will result in syntax errors in bracket lines, but at least
in VSCode the content between them is parsed successfully and should not bring problems to development.
*/

R"(
lv = {};
lv.Obj = function (parent) {
	this.pointer = lv_obj_create(typeof parent == 'pointer' ? parent : parent.pointer);
};
lv.Obj.prototype.setSize = function (w, h) {
	lv_obj_set_size(this.pointer, w, h);
};
lv.Obj.prototype.setPos = function (x, y) {
	lv_obj_set_pos(this.pointer, x, y);
};
lv.Obj.prototype.setAlign = function (align) {
	lv_obj_set_align(this.pointer, align);
};
lv.Obj.prototype.setStyleBorderWidth = function (value, selector) {
	lv_obj_set_style_border_width(this.pointer, value, selector);
};
lv.Obj.prototype.setStylePadAll = function (value, selector) {
	lv_obj_set_style_pad_all(this.pointer, value, selector);
};
lv.Obj.prototype.setStyleBgColor = function (color, selector) {
	lv_obj_set_style_bg_color(this.pointer, color, selector);
};
lv.Obj.prototype.setStyleTextColor = function (color, selector) {
	lv_obj_set_style_text_color(this.pointer, color, selector);
};
lv.Obj.prototype.setStyleTextFont = function (font, selector) {
	lv_obj_set_style_text_font(this.pointer, font, selector);
};
lv.Obj.prototype.addEventCb = function (filter, cb) {
	lv_obj_add_event_cb(this.pointer, cb, filter);
};
lv.Obj.prototype.del = function () {
	lv_obj_del(this.pointer);
};
lv.Btn = function (parent) {
	this.pointer = lv_btn_create(typeof parent == 'pointer' ? parent : parent.pointer);
};
Object.setPrototypeOf(lv.Btn.prototype, lv.Obj.prototype);
lv.Label = function (parent) {
	this.pointer = lv_label_create(typeof parent == 'pointer' ? parent : parent.pointer);
};
Object.setPrototypeOf(lv.Label.prototype, lv.Obj.prototype);
lv.Label.prototype.setText = function (text) {
	lv_label_set_text(this.pointer, text);
};
)"