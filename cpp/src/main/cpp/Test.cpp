//
// Created by Adam on 2/27/2020.
//

#include "Test.h"
#include "Values.h"
#include <iostream>

using namespace std;
using namespace GradleTest;
using namespace godot;

TestNode::TestNode() : value(42)
{

}

TestNode::~TestNode() = default;

void TestNode::_init()
{
	Godot::print("Hello from C++!");
}

int TestNode::getValue() const
{
    return value;
}

void TestNode::_register_methods()
{
    register_method("_init", &TestNode::_init);
}