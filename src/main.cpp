#include <crow.h>

#include <stdio.h>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/crow")([] {
        return "Hello from Crow!";
    });

    CROW_ROUTE(app, "/crow/<int>")([](int count) {
        return crow::response(std::to_string(count));
    });

    app.port(18080).run();

    return 0;h
}
