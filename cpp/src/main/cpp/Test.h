//
// Created by Adam on 2/27/2020.
//

#ifndef GDNATIVEGRADLE_TEST_H
#define GDNATIVEGRADLE_TEST_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace GradleTest
{
	class TestNode : public godot::Node2D {
        GODOT_CLASS(TestNode, godot::Node2D)

    private:
        int value;
    
	public:
		TestNode();
		~TestNode();

        void _init();
        int getValue() const;

        static void _register_methods();
	};
}

#endif //GDNATIVEGRADLE_TEST_H
