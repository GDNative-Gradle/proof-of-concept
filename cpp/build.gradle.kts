plugins {
	id("org.ajoberstar.grgit") version "4.0.1"
	id("cpp-library")
	id("visual-studio")
}

library {
	targetMachines.set(listOf(//machines.linux.x86_64,
							  //machines.windows.x86,
							  machines.windows.x86_64,
							  machines.macOS.x86_64))

	linkage.set(listOf(Linkage.SHARED))

	privateHeaders.from(file("godot-cpp/godot_headers/"), file("godot-cpp/include/core"), file("godot-cpp/include/gen"))

	dependencies {
		implementation(project(":godot-cpp"))
	}
}

tasks.withType(CppCompile::class.java).configureEach {
	// Define toolchain-specific compiler options
	compilerArgs.addAll(toolChain.map { toolChain ->
		when(toolChain)
		{
			is Gcc, is Clang -> listOf("-O2", "-fno-access-control")
			is VisualCpp -> listOf("/std:c++17")
			else -> listOf()
		}
	})
}