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

    save_state(My_settings);

    //info_state(My_settings);

    load_state(My_settings);

    return a.exec();
}

// QSettings Methods
void save_state(QSettings &setting)
{
    setting.beginGroup("Audio"); // Audio settings group
    setting.setValue("Volume", 70);
    setting.setValue("Mute", false);
    setting.setValue("Bass", 40);
    setting.setValue("Mid", 50);
    setting.setValue("Treble", 80);
    setting.endGroup(); // exit group setting

    setting.beginGroup("Project Template"); // template setting group
    setting.setValue("Orientation", "Portrait");
    setting.setValue("Paper size", "A4");
    setting.setValue("Empty project", true);
    setting.endGroup(); // exit template setting group
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
    setting.beginGroup("Audio");
    qDebug() << "Volume: " << setting.value("Volume").toInt();
    qDebug() << "Mute: " << setting.value("Mute").toBool();
    qDebug() << "Bass: " << setting.value("Bass").toInt();
    qDebug() << "Mid: " << setting.value("Mid").toInt();
    qDebug() << "Treble: " << setting.value("Treble").toInt();
    setting.endGroup();

    setting.beginGroup("Project Template"); // template setting group
    qDebug() << "Orientation: " << setting.value("Orientation").toString();
    qDebug() << "Paper size: " << setting.value("Paper size").toString();
    qDebug() << "Start empty project: " << setting.value("Empty project").toBool();
    setting.endGroup(); // exit template setting group
}























