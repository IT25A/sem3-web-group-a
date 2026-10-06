#include <stddef.h>

#define NOB_IMPLEMENTATION

#include "nob.h"

#define BUILD_FOLDER "bin/"
#define SRC_FOLDER "src/"

#define CROW "external/crow/include"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);

    if (!nob_mkdir_if_not_exists(BUILD_FOLDER)) return 1;

    #ifdef _WIN32
    #define EXE ".exe"
    #else
    #define EXE ""
    #endif

    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd,
        "g++",
        "-std=c++20",
        "-I" CROW,
        "-pthread" );

    nob_cc_flags(&cmd);

    Nob_File_Paths files = {0};

    if (!nob_read_entire_dir(SRC_FOLDER, &files)) return 1;

    for (size_t i = 0; i < files.count; ++i) {
        const char *file = files.items[i];

        if (nob_sv_end_with(nob_sv_from_cstr(file), ".cpp")) {
            nob_cc_inputs(&cmd,
                nob_temp_sprintf("%s%s", SRC_FOLDER, file)
            );
        }
    }

    nob_cc_output(&cmd, BUILD_FOLDER "server" EXE);

    if (!nob_cmd_run_sync(cmd)) return 1;
}