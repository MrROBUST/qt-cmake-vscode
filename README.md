Build and Install Qt
--------------------

Use the latest **stable** release source: https://github.com/qt/qtbase/tags. `v6.7.2` at the moment.

Configure and install `Release` and `Debug` configurations separately.

Run from `vcvars64.bat` environment:

```
md C:\qt
git clone git://code.qt.io/qt/qt5.git C:\qt\qt6
cd C:\qt\qt6
git checkout origin/6.7.2 -b 6.7.2
git submodule update --init --recursive

md C:\qt\qt6\build\Debug
cd C:\qt\qt6\build\Debug
..\..\configure.bat -no-pch -skip qtwebengine -debug -prefix C:\qt\6.7.2\Debug
cmake --build .
cmake --install .

md C:\qt\qt6\build\Release
cd C:\qt\qt6\build\Release
..\..\configure.bat -no-pch -skip qtwebengine -release -prefix C:\qt\6.7.2\Release
cmake --build .
cmake --install .
```

Use the template
----------------

`git clone https://github.com/MrROBUST/qt-cmake-vscode.git`

Open a folder in Visual Studio Code.

Install recommended extensions listed in `.vscode\extensions.json` for C++ and CMake support.

Configure `cmake-tools-kits.json` to use `vcvars64.bat` and preferred tools, for example:

```
  {
    "name": "Clang-cl",
    "isTrusted": true,
    "preferredGenerator": {
      "name": "Ninja"
    },
    "compilers": {
      "C": "clang-cl.exe",
      "CXX": "clang-cl.exe"
    },
    "environmentSetupScript" : "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat",
    "keep": true
  }
```

Set CMake options to use the required kit, configuration, and build target.

Run configure CMake cache and build the target executable.

Run the debug with `cppvsdbg`, `.natvis` should work.

You can use Qt Creator to edit `.ui` forms.
