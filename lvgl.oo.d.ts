declare namespace lv {
	declare class Obj {
		constructor(parent: lv_obj_t | Obj);
		pointer: lv_obj_t;
		setSize(w: lv_coord_t, h: lv_coord_t): void;
		setPos(x: lv_coord_t, y: lv_coord_t): void;
		setAlign(align: lv_align_t): void;
		setStyleBorderWidth(value: lv_coord_t, selector: lv_style_selector_t): void;
		setStylePadAll(value: lv_coord_t, selector: lv_style_selector_t): void;
		setStyleBgColor(color: lv_color_t, selector: lv_style_selector_t): void;
		setStyleTextColor(color: lv_color_t, selector: lv_style_selector_t): void;
		setStyleTextFont(font: lv_font_t, selector: lv_style_selector_t): void;
		addFlag(flag: lv_obj_flag_t): void;
		clearFlag(flag: lv_obj_flag_t): void;
		addEventCb(filter: lv_event_code_t, cb: (e: lv_event_t) => void): void;
		del(): void;
		delAsync(): void;
	}
	declare class Btn extends Obj {
		constructor(parent: lv_obj_t | Obj);
	}
	declare class Label extends Obj {
		constructor(parent: lv_obj_t | Obj);
		setText(text: string): void;
	}
	declare class Img extends Obj {
		constructor(parent: lv_obj_t | Obj);
		setSrc(src: lv_img_dsc_t): void;
		setZoom(zoom: uint16_t): void;
		setAntialias(antialias: boolean): void;
	}
}
