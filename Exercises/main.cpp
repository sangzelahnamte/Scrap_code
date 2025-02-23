#include <QCoreApplication>
#include <QSettings>

// QSettings Methods
void save_state(QSettings &setting, QString group, QString key, int num_value); // LOAD
int load_state(QSettings &setting, QString group, QString key); // SAVE

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setApplicationName("Scarp book App");
    QCoreApplication::setOrganizationName("Soft tech Co.");
    QCoreApplication::setOrganizationDomain("Bigtech.com");

    QSettings My_settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

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
    if(!setting.contains(key))
    {
        qWarning() << "Does not containe key:" << key << "in" << group;
        setting.endGroup();
        return 0;
    }
    bool ok;
    int value = setting.value(key).toInt(&ok); // key value load
    setting.endGroup();
    if(!ok)
    {
        qDebug() << "Could not convert to int";
        return 0;
    }
    return value;
}























