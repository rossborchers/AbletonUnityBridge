git submodule foreach --recursive git reset --hard
git submodule update --init --recursive

REM Set Visual Studio warnings to W3 (Avoids Spectre warnings causing failed build, could also set WX- to disable warnings as errors
cd Plugin\Modules\Link
powershell -Command "(gc CMakeLists.txt) -replace 'if\(WIN32\)', \"if(WIN32)`n  add_compile_options(/W3)\" | Set-Content -encoding ASCII CMakeLists.txt"