#include <iostream>
#include <random>

#include <QCoreApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    app.setApplicationVersion(QStringLiteral("1.0.0"));

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addOption(
    {{QStringLiteral("i"),QStringLiteral("info")}, QStringLiteral("Get the player's info")}
                );

    parser.process(app);

    if(parser.isSet(QStringLiteral("i"))){
        std::cout << R"({"name": "snakesssss"})" << std::endl;
        return 0;
    }

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(0,3);
    std::string temp;

    bool go=true;
    int distVal = 0;
    while(go){
        std::getline(std::cin,temp);

        if(dist(engine)==0){
            distVal = dist(engine);
        }
        switch (distVal) {
            case 0: {
                std::cout <<R"({"dir": "RIGHT"})" << std::endl;
                break;
            }
            case 1: {
                std::cout <<R"({"dir": "LEFT"})" << std::endl;
                break;
            }
            case 2:{
                std::cout <<R"({"dir": "UP"})" << std::endl;
                break;
            }
            case 3:{
                std::cout <<R"({"dir": "DOWN"})" << std::endl;
                break;
            }
        }
    }


    return app.exec();
}
