#include <QCoreApplication>
#include <QSettings>

// QSettings Methods
void save_state(QSettings &setting);
void info_state(QSettings &setting);
void load_state(QSettings &setting);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set organisation credentials are needed to be stored as metaData for the application if not it might collide with other app settings.
    QCoreApplication::setApplicationName("Scarp book App");
    QCoreApplication::setOrganizationName("Soft tech Co.");
    QCoreApplication::setOrganizationDomain("Bigtech.com");

    QSettings My_settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    qInfo() << "Saved setting info";
    save_state(My_settings);
    qInfo() << "Setting information";
    info_state(My_settings);
    qInfo() << "Load setting info";
    load_state(My_settings);

    return a.exec();
}

// QSettings Methods
void save_state(QSettings &setting)
{
    setting.setValue("Font changed", 40);
    qInfo() << setting.status();
    qInfo() << "Saved settings";
}

void info_state(QSettings &setting)
{
    qInfo() << "Application name: " << setting.applicationName();
    qInfo() << "Organization name: " << setting.organizationName();
    qInfo() << "File name: " << setting.fileName();
    qInfo() << "Key: " << setting.allKeys();
}

void load_state(QSettings &setting)
{
    // string a convert a nih chhan chu a qdebug() console string angin kan hmuh kan duh vangin a ni.
    qInfo() << "Load: " << setting.value("Font changed").toString(); // key hmangin value a load ang.
    bool ok; // a key value kha a chhia em tih validate nan int a convert tur a ni, a chhan chu tu emaw in an lo khawih sual palh thei data file app setting
    qInfo() << "Load to int: " << setting.value("Font changed").toInt(&ok); // key value hi pangai taka application in load theih nan validation hman ani
    if(!ok)
    {
        qInfo() << "Could not load data";
    }
}























