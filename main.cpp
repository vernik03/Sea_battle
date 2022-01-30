#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>
#include <QDebug>
#include <QQmlContext>
#include "unit.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    unit* til= new unit;
    QObject* obj= til;
    auto cont= engine.rootContext();
    cont->setContextProperty("object", obj);
    engine.load(url);
    QObject *root = engine.rootObjects()[0];
    QObject::connect(root, SIGNAL(send(int, int, int)), obj, SLOT(cppSlot(int, int, int)));
    return app.exec();
}
