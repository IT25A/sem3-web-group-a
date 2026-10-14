#include <stdio.h>

#include <crow.h>
#include <http_response.h>
#include <query_string.h>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/crow")([] {
        return "Hello from Crow!";
    });

    CROW_ROUTE(app, "/crow/<int>")
    .methods("PUT"_method)
    ([](crow::request& req, crow::response& res, int count) {        
        const crow::query_string qs = req.get_body_params();
        std::cout << "Body: " << qs << std::endl;

        if(count == 0){

        }

        res = crow::response(200, "Created!");
        res.end();
    });

    app.port(80).run();

    return 0;
}
