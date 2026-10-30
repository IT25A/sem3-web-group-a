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

    return 0;
}
