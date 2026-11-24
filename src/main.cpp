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
}