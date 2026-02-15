# 📄 CMakeLists.txt


## add_executable

```cmake
add_executable (KifuwaraperyR
    "Main.cpp"
    "Main.h")
```

👆 ここでは、"KifuwaraperyR" という名前の実行可能ファイルを作成し、"Main.cpp" と "Main.h" をソースファイルとして指定しています。  


## message

```cmake
# ビルドディレクトリのパスを表示してみる
message(STATUS "CMAKE_BINARY_DIR はここだぜ: ${CMAKE_BINARY_DIR}")
```

👆 ここでは、ビルドディレクトリのパスを表示するメッセージを出力しています。  


## include(FetchContent) ～ FetchContent_MakeAvailable()

```cmake
include(FetchContent)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.15.0
)
FetchContent_MakeAvailable(spdlog)
```

👆 ここでは、外部ライブラリである spdlog を Git リポジトリから取得し、プロジェクトに組み込んでいます。  
NuGet などのパッケージマネージャーを使用せずに、直接ソースコードを取得してビルドに含める方法です。  
ソースコードは ビルドディレクトリ（CMAKE_BINARY_DIR）の下にダウンロードされます。  
`${CMAKE_BINARY_DIR}/_deps/` 参照。  


## target_compile_features

```cmake
# C++標準の最低限必要なバージョンを設定（必要なら）
target_compile_features(KifuwaraperyR PRIVATE cxx_std_20)
```

👆 ここでは、"KifuwaraperyR" ターゲットに対して最低限 C++20 以上の標準を使用するように設定しています。  


## C++標準のバージョン確認

```cmake
# CXX_STANDARDの確認
message(STATUS "CXX_STANDARD for KifuwaraperyR: ${CMAKE_CXX_STANDARD}")  # グローバル変数（参考）
get_target_property(std KifuwaraperyR CXX_STANDARD)
message(STATUS "CXX_STANDARD property: ${std}")
```

👆 ここでは、"KifuwaraperyR" ターゲットに設定されている C++ 標準のバージョンを確認し、メッセージとして出力しています。  


## target_link_libraries

```cmake
# spdlogリンク！
target_link_libraries(KifuwaraperyR PRIVATE spdlog::spdlog)
```
👆 ここでは、"KifuwaraperyR" ターゲットに対して spdlog ライブラリをリンクしています。  
