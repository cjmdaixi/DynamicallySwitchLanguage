#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
#include <QtDebug>
#include "appglobal.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    auto appGlobal = new AppGlobal;
    auto translator = new QTranslator(&app);
    translator->load("en.qm");
    app.installTranslator(translator);
    QObject::connect(appGlobal, &AppGlobal::languageChanged, &app, [&](QString lang){
        auto newTranslator = new QTranslator(&app);
        auto loadResult = true;
        if(lang == "en") {
            loadResult = newTranslator->load("en.qm");

        }else{
            loadResult = newTranslator->load("zh.qm");
        }
        if(!loadResult){
            qWarning()<<"Cannot load zh.qm!";
            delete newTranslator;
            return;
        }
        app.removeTranslator(translator);
        app.installTranslator(newTranslator);
        translator = newTranslator;
        emit appGlobal->langTokenChanged("");
        qDebug()<<"finish changing language to"<<lang;
        //engine.retranslate();
    });
    engine.rootContext()->setContextProperty("$app", appGlobal);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
