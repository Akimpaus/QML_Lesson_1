#include "loginpassword.h"

#include <QPainter>
#include <QLayout>
#include <QPropertyAnimation>

#include <QDebug>

LoginPassword::LoginPassword(QWidget *parent) :
    QWidget(parent)
{
    m_login    = new QLineEdit(this);
    m_password = new QLineEdit(this);
    m_button   = new QPushButton("Вход", this);

    constexpr size_t fields_height = 35;
    m_login->setFixedHeight(fields_height);
    m_login->setPlaceholderText("Логин");
    m_password->setFixedHeight(fields_height);
    m_password->setPlaceholderText("Пароль");
    m_password->setEchoMode(QLineEdit::Password);
    m_button->setFixedHeight(fields_height);
    m_button->setStyleSheet
    (
        "QPushButton         {background: #f6f6f6; border:none;}"
        "QPushButton:hover   {background: #d6d6d6; border:none;}"
        "QPushButton:pressed {background: #bbbbbb; border:none;}"
    );

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(32);
    layout->setContentsMargins(32,32,32,32);
    layout->addWidget(m_login, Qt::AlignHCenter);
    layout->addWidget(m_password, Qt::AlignCenter);
    layout->addWidget(m_button, Qt::AlignCenter);


    connect(m_button, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
}

void LoginPassword::paintEvent(QPaintEvent *paint_event)
{
    QPainter painter(this);
    painter.setPen(Qt::transparent);
    painter.setBrush(QBrush(QColor(255,255,255, palette().color(QPalette::Window).alpha())));
    painter.drawRoundedRect(rect(), 5,5);


    return QWidget::paintEvent(paint_event);
}

QColor LoginPassword::loginTextColor() const
{
    return m_login->palette().text().color();
}

void LoginPassword::setLoginTextColor(const QColor& color)
{
    auto p = m_login->palette();
    p.setColor(QPalette::Text, color);
    m_login->setPalette(p);
}

QColor LoginPassword::passwordTextColor() const
{
    return m_password->palette().text().color();
}

void LoginPassword::setPasswordTextColor(const QColor &color)
{
    auto p = m_password->palette();
    p.setColor(QPalette::Text, color);
    m_password->setPalette(p);
}

void LoginPassword::on_button_clicked()
{
    if(m_login->text() == m_login_value && m_password->text() == m_password_value)
    {
        emit auth_success();
    }
    else
    {
        emit auth_error();
    }
}
