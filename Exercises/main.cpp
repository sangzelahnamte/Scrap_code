#include <QCoreApplication>
#include <QSettings>

// QSettings Methods
void save_state(QSettings &setting);
void info_state(QSettings &setting);
void load_state(QSettings &setting);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set organisation credentials to save state changes
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
    qInfo() << "Load: " << setting.value("Font changed").toString(); // key hmangin value a load ang
    bool ok;
    qInfo() << "Load to int: " << setting.value("Font changed").toInt(&ok);
    if(!ok)
    {
        qInfo() << "Could not load data";
    }
}























