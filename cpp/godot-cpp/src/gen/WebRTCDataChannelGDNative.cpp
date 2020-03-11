#include "WebRTCDataChannelGDNative.hpp"


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


WebRTCDataChannelGDNative::___method_bindings WebRTCDataChannelGDNative::___mb = {};

void WebRTCDataChannelGDNative::___init_method_bindings() {
}

WebRTCDataChannelGDNative *WebRTCDataChannelGDNative::_new()
{
	return (WebRTCDataChannelGDNative *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"WebRTCDataChannelGDNative")());
}
}