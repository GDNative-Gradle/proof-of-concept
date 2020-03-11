plugins {
	id("cpp-library")
	id("visual-studio")
}

library {
	targetMachines.set(listOf(//machines.linux.x86_64,
							  machines.windows.x86_64,
							  //machines.windows.x86,
							  machines.macOS.x86_64))

	linkage.set(listOf(Linkage.STATIC))

	source.from(file("src/"))
	privateHeaders.from(file("src/"), file("godot_headers/"), file("include/core"), file("include/gen"))
	publicHeaders.from(file("include/"))
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

