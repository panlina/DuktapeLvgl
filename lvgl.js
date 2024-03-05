/*
This file is to be #include'd in a cpp source. Following content is not a valid js source by intention.
Since it's not possible to use `#include` in `R"()"`, the opening and closing brackets (`R"(` and `)"`)
have to be written in the file itself. This will result in syntax errors in bracket lines, but at least
in VSCode the content between them is parsed successfully and should not bring problems to development.
*/

R"(
lv = {};
lv.Obj = function () {
	this.pointer = lv_obj_create();
};
lv.Obj.prototype.setSize = function (w, h) {
	lv_obj_set_size(this.pointer, w, h);
};
lv.Obj.prototype.addEventCb = function (filter, cb) {
	lv_obj_add_event_cb(this.pointer, cb, filter);
};
lv.Btn = function () {
	this.pointer = lv_btn_create();
};
Object.setPrototypeOf(lv.Btn.prototype, lv.Obj.prototype);
)"