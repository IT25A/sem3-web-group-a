<<<<<<< HEAD
    #include <stdio.h>
    #include <iostream>
    #include <filesystem>
    #include <vector>

    #include <crow.h>
    #include <http_response.h>
    #include <query_string.h>

    using namespace std;

    const auto src = std::filesystem::current_path().string();

	#define CROW_STATIC_DIRECTORY "src/"

    int main()
    {
        crow::SimpleApp app;

        CROW_ROUTE(app, "/FuelCalc")
        ([](crow::request &req, crow::response &res) {
			cout << src << endl;
            res.set_static_file_info("src/index.html", "text/html");
            res.end();
        });

    	app.static_file("/main.js", CROW_STATIC_DIRECTORY "main.js");

        app.bindaddr("0.0.0.0")
        .port(8080)
        .multithreaded()
        .run();
=======
#include <filesystem>

#include <crow.h>

using namespace std;

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/FuelCalc")
    ([](crow::request &req, crow::response &res) {
        res.set_static_file_info("src/index.html", "text/html");
        cout << std::filesystem::current_path() << endl;
        res.end();
    });

    CROW_STATIC_FILE(app, "/main.js", "src/main.js");

    app.port(18080).run();
>>>>>>> 1b3bb1d52252f39418c8467b4f1028f0f25c7801

        return 0;
    }
