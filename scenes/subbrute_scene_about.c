#include "../subbrute_i.h"
#include "subbrute_scene.h"

void subbrute_scene_about_on_enter(void* context) {
    furi_assert(context);
    SubBruteState* instance = context;

    Popup* popup = instance->popup;
    popup_set_icon(popup, 40, 22, &I_DolphinNice_96x59);
    popup_set_header(popup, "About", 5, 3, AlignLeft, AlignTop);
    popup_set_text(
        popup, "Sub-GHz Fuzzer v4\nby TheZakMan", 5, 18, AlignLeft, AlignTop);
    popup_set_context(popup, instance);
    popup_set_callback(popup, subbrute_popup_closed_callback);

    view_dispatcher_switch_to_view(instance->view_dispatcher, SubBruteViewPopup);
}

bool subbrute_scene_about_on_event(void* context, SceneManagerEvent event) {
    SubBruteState* instance = (SubBruteState*)context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        if(event.event == SubBruteCustomEventTypePopupClosed) {
            scene_manager_previous_scene(instance->scene_manager);
            consumed = true;
        }
    }

    return consumed;
}

void subbrute_scene_about_on_exit(void* context) {
    furi_assert(context);
    SubBruteState* instance = (SubBruteState*)context;

    Popup* popup = instance->popup;
    popup_set_header(popup, NULL, 0, 0, AlignCenter, AlignBottom);
    popup_set_text(popup, NULL, 0, 0, AlignCenter, AlignTop);
    popup_set_icon(popup, 0, 0, NULL);
    popup_set_callback(popup, NULL);
    popup_set_context(popup, NULL);
}
