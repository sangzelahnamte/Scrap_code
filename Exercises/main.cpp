#include <QCoreApplication>
#include <QSettings>
#include <QRandomGenerator>

// QSettings Methods
void save_state(QSettings &setting, QString group, QString key, int num_value); // LOAD
int load_state(QSettings &setting, QString group, QString key); // SAVE

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setApplicationName("Scarp book App");
    QCoreApplication::setOrganizationName("Soft tech Co.");
    QCoreApplication::setOrganizationDomain("Bigtech.com");

    //QSettings My_settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    QString file_name = a.applicationDirPath() + "/setting.ini";
    qInfo() << file_name;
    QSettings My_settings(file_name, QSettings::Format::IniFormat);

    QString group = "Audio";
    QString key_1 = "Volume";
    int value_1 = 80;
    QString key_2 = "Bass";
    int value_2 = 40;
    QString key_3 = "Mid";
    int value_3 = 50;
    QString key_4 = "Treble";
    int value_4 = 80;

    save_state(My_settings, group, key_1, value_1);
    save_state(My_settings, group, key_2, value_2);
    save_state(My_settings, group, key_3, value_3);
    save_state(My_settings, group, key_4, value_4);
    qInfo() << "Volume:" << load_state(My_settings, group, key_1);
    qInfo() << "Bass:" << load_state(My_settings, group, key_2);
    qInfo() << "Mid:" << load_state(My_settings, group, key_3);
    qInfo() << "Treble:" << load_state(My_settings, group, key_4);

    QString color_group = "Colour group"; // group
    QStringList keys; // key
    keys << "red" << "blue" << "green" << "yellow" << "purple";

    foreach(QString mykeys, keys) // generating key values here
    {
        int key_value = QRandomGenerator::global()->bounded(500);
        save_state(My_settings, color_group, mykeys, key_value);
    }

    My_settings.sync(); // immediately writes to disk

    foreach(QString group, My_settings.childGroups()) // reading and navigating back all data
    {
        My_settings.beginGroup(group);
        qInfo() << "group:" << color_group;
        foreach(QString key, My_settings.childKeys())
        {
            qInfo() << "key:" << key << "key value:" << My_settings.value(key).toString();
        }
        My_settings.endGroup();
    }

    return a.exec();
}

// QSettings Methods
void save_state(QSettings &setting, QString group, QString key, int num_value)
{
    setting.beginGroup(group);
    setting.setValue(key, num_value); // key value save
    setting.endGroup();
}

int load_state(QSettings &setting, QString group, QString key)
{
    setting.beginGroup(group);
    if(!setting.contains(key)) // setting contain key or not
    {
        qWarning() << "Does not containe key:" << key << "in" << group;
        setting.endGroup();
        return 0;
    }
    bool ok;
    int value = setting.value(key).toInt(&ok); // if key value has correct data type and can be converted to int
    setting.endGroup();
    if(!ok)
    {
        qDebug() << "Could not convert to int";
        return 0;
    }
    return value; // return the data
}























