# CMakeList.txt : KifuwaraperyR の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#


# 実行ファイルにコンパイルするソースファイルを全部羅列してください。
add_executable (KifuwaraperyR
    # 📁 src
    "main.cpp" "main.hpp"
    # 📁 src/layer_app
    "layer_app/muz_default_logger_model.cpp" "layer_app/muz_default_logger_model.hpp"
    "layer_app/muz_logging_service.cpp" "layer_app/muz_logging_service.hpp"
    # 📁 layer_game_engine
    "layer_game_engine/muz_game_engine_storage_model.cpp" "layer_game_engine/muz_game_engine_storage_model.hpp"
    # 📁 lib_cpp
    "lib_cpp/int.hpp"
    "lib_cpp/overload_enum_operators.hpp"
    # 📁 lib_gui
    "lib_gui/muz_engine_option_abstract_model.cpp" "lib_gui/muz_engine_option_abstract_model.hpp"
    "lib_gui/muz_engine_option_button_model.cpp" "lib_gui/muz_engine_option_button_model.hpp"
    "lib_gui/muz_engine_option_checkbox_model.cpp" "lib_gui/muz_engine_option_checkbox_model.hpp"
    "lib_gui/muz_engine_option_spinbox_model.cpp" "lib_gui/muz_engine_option_spinbox_model.hpp"
    "lib_gui/muz_engine_option_textbox_model.cpp" "lib_gui/muz_engine_option_textbox_model.hpp"
    "lib_gui/muz_engine_settings_initialize_service.cpp" "lib_gui/muz_engine_settings_initialize_service.hpp"
    "lib_gui/muz_engine_settings_model.cpp" "lib_gui/muz_engine_settings_model.hpp"
    #
    "muz_game_engine_service.cpp" "muz_game_engine_service.hpp")


#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET KifuwaraperyR PROPERTY CXX_STANDARD 20)
#endif()


# 出力ディレクトリを CMAKE_BINARY_DIR の直下に固定（src/ の下じゃなく）
# これで .exe と config.toml が out\build\x64-debug\KifuwaraperyR.exe みたいになる
set_target_properties(KifuwaraperyR PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}"
)

# 設定ファイルをビルド出力ディレクトリにコピーする
add_custom_command(TARGET KifuwaraperyR POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/config.toml
            ${CMAKE_BINARY_DIR}/config.toml
    COMMENT "Copying config.toml to output directory"
)


# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。


# ビルドディレクトリのパスを表示してみる
message(STATUS "CMAKE_BINARY_DIR はここだぜ: ${CMAKE_BINARY_DIR}")


# ========================================
# モジュール読込
# ========================================


include(FetchContent)


# モジュール読込　＞　spdlog　-　ロギング
# ----------------------------------------


FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.17.0
)
FetchContent_MakeAvailable(spdlog)
target_link_libraries(KifuwaraperyR PRIVATE spdlog::spdlog)


# モジュール読込　＞　tomlplusplus　-　設定ファイルパーサー
# ----------------------------------------


FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG        v3.4.0   # 最新版（2026年現在でv3.4.0あたりが安定、GitHubで確認）
    # GIT_TAG master とかでもOKだけど、タグ固定が安全
)
FetchContent_MakeAvailable(tomlplusplus)
target_link_libraries(KifuwaraperyR PRIVATE tomlplusplus::tomlplusplus)


# ========================================
# その他の設定
# ========================================


# C++標準の最低限必要なバージョンを設定（必要なら）
target_compile_features(KifuwaraperyR PRIVATE cxx_std_20)

# CXX_STANDARDの確認
message(STATUS "CXX_STANDARD for KifuwaraperyR: ${CMAKE_CXX_STANDARD}")  # グローバル変数（参考）
get_target_property(std KifuwaraperyR CXX_STANDARD)
message(STATUS "CXX_STANDARD property: ${std}")

# 警告とか追加（オプション）
#target_compile_options(KifuwaraperyR PRIVATE -Wall -Wextra -Wpedantic)
