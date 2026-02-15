# 📄 CMakeLists.txt 解説

このドキュメントでは、CMakeLists.txt ファイルの各セクションについて説明します。  
CMakeLists.txt は、CMake ビルドシステムで使用される設定ファイルであり、プロジェクトのビルドプロセスを定義します。  


## cmake_minimum_required

```cmake
cmake_minimum_required (VERSION 3.10)
```

👆 この行は、CMake の最低バージョンを指定します。  


## if ～ cmake_policy(), set()

```cmake
# サポートされている場合は、MSVC コンパイラのホット リロードを有効にします。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
```

👆 このセクションは、MSVC コンパイラのホットリロード機能を有効にするためのポリシー設定を行います。  


## project

```cmake
project ("KifuwaraperyR")
```

👆 ここでは、プロジェクトの名前を "KifuwaraperyR" に設定しています。  


## add_subdirectory

```cmake
add_subdirectory ("src")
```

👆 "src" サブディレクトリを追加し、その中の CMakeLists.txt を読み込みます。  
