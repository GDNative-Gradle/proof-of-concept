#include "AnimationNodeTimeSeek.hpp"


#include <core/GodotGlobal.hpp>
#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>
#include <core/Godot.hpp>

#include "__icalls.hpp"




namespace godot {


AnimationNodeTimeSeek::___method_bindings AnimationNodeTimeSeek::___mb = {};

void AnimationNodeTimeSeek::___init_method_bindings() {
}

AnimationNodeTimeSeek *AnimationNodeTimeSeek::_new()
{
	return (AnimationNodeTimeSeek *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, godot::api->godot_get_class_constructor((char *)"AnimationNodeTimeSeek")());
}
}