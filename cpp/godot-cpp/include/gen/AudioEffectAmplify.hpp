#ifndef GODOT_CPP_AUDIOEFFECTAMPLIFY_HPP
#define GODOT_CPP_AUDIOEFFECTAMPLIFY_HPP


#include <gdnative_api_struct.gen.h>
#include <stdint.h>

#include <core/CoreTypes.hpp>
#include <core/Ref.hpp>

#include "AudioEffect.hpp"
namespace godot {


class AudioEffectAmplify : public AudioEffect {
	struct ___method_bindings {
		godot_method_bind *mb_get_volume_db;
		godot_method_bind *mb_set_volume_db;
	};
	static ___method_bindings ___mb;

public:
	static void ___init_method_bindings();

	static inline const char *___get_class_name() { return (const char *) "AudioEffectAmplify"; }
	static inline Object *___get_from_variant(Variant a) { godot_object *o = (godot_object*) a; return (o) ? (Object *) godot::nativescript_1_1_api->godot_nativescript_get_instance_binding_data(godot::_RegisterState::language_index, o) : nullptr; }

	// enums

	// constants


	static AudioEffectAmplify *_new();

	// methods
	real_t get_volume_db() const;
	void set_volume_db(const real_t volume);

};

}

#endif