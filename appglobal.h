#ifndef APPGLOBAL_H
#define APPGLOBAL_H

#include <QObject>

class AppGlobal : public QObject
{
    Q_OBJECT
    QString m_language = "en";

    QString m_langToken;

public:
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)
    Q_PROPERTY(QString langToken READ langToken NOTIFY langTokenChanged)
    explicit AppGlobal(QObject *parent = nullptr);

    QString language() const
    {
        return m_language;
    }

    QString langToken() const
    {
        return m_langToken;
    }

signals:

    void languageChanged(QString language);

    void langTokenChanged(QString langToken);

public slots:
    void setLanguage(QString language)
    {
        if (m_language == language)
            return;

        m_language = language;
        emit languageChanged(m_language);
    }
};

#endif // APPGLOBAL_H
