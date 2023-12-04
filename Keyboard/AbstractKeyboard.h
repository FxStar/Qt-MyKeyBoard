/**********************************************************
#Author: Qtjun
#WeChat Official Accounts: qthub_com
#QQ Group: 732271126
#Email: 2088201923@qq.com
**********************************************************/

#ifndef AEA_ABSTRACT_KEYBOARD_H
#define AEA_ABSTRACT_KEYBOARD_H

#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QKeyEvent>

typedef void (*CallbackOnKeyPressed)(int key, QString value);

namespace AeaQt
{


    class AbstractKeyboard : public QWidget
    {
        Q_OBJECT
    public:
        AbstractKeyboard(QWidget *parent = 0) : QWidget(parent)
        {
        }
        ~AbstractKeyboard() {}

        void CallbackOnKeyPressed(int key, QString value);
        const QString name() { return m_name; }
        void setName(const QString &name) { m_name = name; }
        void registerCallback(::CallbackOnKeyPressed callback)
        {
            callback_ = callback;
        }

    public slots:
        virtual void update(const QString &text) { Q_UNUSED(text); }

        void onKeyPressed(int key, QString value)
        {
            qDebug() << "key: " << key << "Value: " << value;
            if (callback_)
            {
                (this->callback_)(key, value);
            }
            QWidget *receiver = QApplication::focusWidget();
            if (!receiver)
                return;

            QKeyEvent keyPress(QEvent::KeyPress, key, Qt::NoModifier, value);
            QKeyEvent keyRelease(QEvent::KeyRelease, key, Qt::NoModifier, value);

            QApplication::sendEvent(receiver, &keyPress);
            QApplication::sendEvent(receiver, &keyRelease);
        }

    signals:
        void keyPressed(int key, QString value);

    private:
        QString m_name;
        ::CallbackOnKeyPressed callback_ = nullptr;
    };


}
#endif // AEA_ABSTRACT_KEYBOARD_H
