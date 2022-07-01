#ifndef LOGINPASSWORD_H
#define LOGINPASSWORD_H

#include <QWidget>
#include <QPaintEvent>
#include <QLineEdit>
#include <QPushButton>

class LoginPassword : public QWidget
{

    Q_OBJECT
    Q_PROPERTY(
            QColor loginTextColor READ loginTextColor
            WRITE setLoginTextColor
            );

    Q_PROPERTY(
            QColor passwordTextColor READ passwordTextColor
            WRITE setPasswordTextColor
            );

public:

    explicit LoginPassword(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* paint_event) override;

    QColor loginTextColor() const;
    void setLoginTextColor(const QColor& color);

    QColor passwordTextColor() const;
    void setPasswordTextColor(const QColor& color);

    QLineEdit* m_login;
    QLineEdit* m_password;
    QPushButton* m_button;

    const QString m_login_value    = "login";
    const QString m_password_value = "password";


signals:

    void auth_error() const;
    void auth_success() const;


public slots:

    void on_button_clicked();

};

#endif // LOGINPASSWORD_H
