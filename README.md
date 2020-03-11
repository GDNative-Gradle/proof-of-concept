# proof-of-concept
A proof of concept project showing Gradle being used to build a GDNative library for Godot.

# How to build it:
**Requirements:**
1. Have the JVM installed (_This is the only hard requirement_)
2. Have a C++ toolchain installed (_We may be able to automatically set this up in the future, more on that later_)

**Instructions:**
Simply execute: `gradlew.bat assemble` and it will build the Godot-cpp bindings, and then the user GDNative library as `gdnative-gradle.dll`.

The Included Godot project already points to that DLL for windows. Running the main scene will print `Hello from C++!`

## How it works
Gradle added native support a couple years ago, but recently more effort was put in and things are starting to approach maturity.

This project uses the `cpp-library` gradle plugin to build everything.

There are two gradle "projects":
1. `<root>/cpp` The root gradle project is the users GDnative C++ code
2. `<root>/cpp/godot-cpp` The Godot C++ bindings are in a child directory to the user's own gradle project

In this POC the godot-cpp bindings are just included as a pre-built sub directory inside the repositoy. All of the header generation has already taken place. Importantly, the bindings are also built using Gradle, not SCONS. This allows gradle to automatically know where the headers and outputs are, so they can be consumed by the user's Gradle project.

## Why do this when we already have Scons
Currently getting setup to make a GDNative script in C++ is quite complicated for new users. Scons is nice once it's setup, but gradle offers some distinct advantages over it:
1. A self assembling build environment:
    - Using the gradle wrapper, we can provide as close to a zero setup experience as can be acheived I think.
    - All the user needs installed is the JVM.
        - _Right now you also need a C++ toolchain installed._

    - From here the provided platform specific scripts (_batch and shell_) will boot strap the process. They will download gradle if needed. Then it will begin downloading tools, dependencies, compiler** what ever else is required to build the projects.
    - Finally it'll automatically build the godot-cpp bindings, and lastly, the user's own code.
2. Modern dependency management for C++
3. Extensible build
    - Users can add build tasks to automate teadous tasks
    - Automate things like releases
    - Create Godot files such as the `.gdnlib` file (_Not sure how it could do the `.gdns` files, but in theory it'd be possible to automate that as well._)

** _In theory Gradle can provision c++ toolchains by it's self, but this doesn't work for all toolchains on all platforms yet. And I have yet to get it working at all with the new `cpp-library` plugin_

## Where to go from here
- There is a way to set the C++ standard to use via the plugin supposidely, but I can't find any documentation on how to do it
- Currently gradle does a good job of discovering your installed toolchains and using them automatically. But Gradle does support automatic provisining of C++ toolchains, which would mean the user doesn't even need to have that pre-installed.
- The `godot-cpp` repo and `godot-headers` should be cloned from github, not included inside this repo. That is possible inside of Gradle, but then the header generation needs to be done, and I'm not sure how that works exactly.
    - If this proves too difficult, I think shipping a "pre-build" stripped down version of the bindings is fine. I'm not sure why there isn't already a pre-built one honestly.
- Lastly, even the setup of this can be stream-lined further with a Godot Editor Plugin which would download and setup the initial structure automatically for the user all from a nice GUI inside Godot.
