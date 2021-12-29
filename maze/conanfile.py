from conans import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps

class Maze(ConanFile):
    name = "maze"
    version = "0.1.0"
    settings = "os", "arch", "compiler", "build_type"
    generators = "cmake_find_package", "virtualenv"

    def export_sources(self):
        self.copy("*")                 # -> copies all  from working dir to a "source" dir
        
    def requirements(self):
        self.requires("boost/1.74.0@")    # -> depend on boost 1.74.0
        self.requires("gtest/1.11.0@")    # -> depend on gtest

    def generate(self):
        CMakeToolchain(self).generate()
        CMakeDeps(self).generate()

    def build(self):
        cmake = CMake(self)                # CMake helper auto-formats CLI arguments for CMake
        cmake.configure()                  # cmake -DCMAKE_TOOLCHAIN_FILE=conantoolchain.cmake
        cmake.build()                      # cmake --build .  
        cmake.test()

    def package(self):
        cmake = CMake(self)                # For CMake projects which define an install target, leverage it
        cmake.install()                    # cmake --build . --target=install 
                                           # sets CMAKE_INSTALL_PREFIX = <appropriate directory in conan cache>
