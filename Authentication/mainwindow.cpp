#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginpassword.h"
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_login_password = new LoginPassword(this);
    setPalette(QPalette(QColor("#e5ecef")));

    QPoint window_center = rect().center();
    constexpr QSize log_pass_size = {300,250};
    m_login_password->setGeometry
    (
        window_center.x() - log_pass_size.width() / 2,
        window_center.y() - log_pass_size.height() / 2,
        log_pass_size.width(),
        log_pass_size.height()
    );


    connect(m_login_password, SIGNAL(auth_error()), this, SLOT(on_authError()));
    connect(m_login_password, SIGNAL(auth_success()), this, SLOT(on_authSuccess()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_authError()
{
    QSize size = m_login_password->size();
    QPoint start_pos(rect().center().x() - size.width() / 2, m_login_password->pos().y());

    QPropertyAnimation *animation_1 = new QPropertyAnimation(m_login_password, "geometry", this);
    animation_1->setDuration(50);
    animation_1->setStartValue(QRectF(m_login_password->pos(), m_login_password->size()));
    animation_1->setEndValue(QRectF(start_pos - QPoint(5,0), size));

    QPropertyAnimation *animation_2 = new QPropertyAnimation(m_login_password, "geometry", this);
    animation_2->setDuration(100);
    animation_2->setStartValue(QRectF(m_login_password->pos(), m_login_password->size()));
    animation_2->setEndValue(QRectF(start_pos + QPoint(10,0), size));

    QPropertyAnimation *animation_3 = new QPropertyAnimation(m_login_password, "geometry", this);
    animation_3->setDuration(50);
    animation_3->setStartValue(QRectF(m_login_password->pos(), m_login_password->size()));
    animation_3->setEndValue(QRectF(start_pos, size));

    QSequentialAnimationGroup* seq_animation_group = new QSequentialAnimationGroup(this);
    seq_animation_group->addAnimation(animation_1);
    seq_animation_group->addAnimation(animation_2);
    seq_animation_group->addAnimation(animation_3);


    QPropertyAnimation* color_anim_login_start = new QPropertyAnimation(m_login_password, "loginTextColor");
    color_anim_login_start->setDuration(0);
    color_anim_login_start->setEndValue(QColor("red"));

    QPropertyAnimation* color_anim_login_end = new QPropertyAnimation(m_login_password, "loginTextColor");
    color_anim_login_end->setDuration(400);
    color_anim_login_end->setEndValue(QColor("black"));

    QSequentialAnimationGroup* seq_animation_color_login_group = new QSequentialAnimationGroup(this);
    seq_animation_color_login_group->addAnimation(color_anim_login_start);
    seq_animation_color_login_group->addAnimation(color_anim_login_end);

    QPropertyAnimation* color_anim_password_start = new QPropertyAnimation(m_login_password, "passwordTextColor");
    color_anim_password_start->setDuration(0);
    color_anim_password_start->setEndValue(QColor("red"));

    QPropertyAnimation* color_anim_password_end = new QPropertyAnimation(m_login_password, "passwordTextColor");
    color_anim_password_end->setDuration(400);
    color_anim_password_end->setEndValue(QColor("black"));

    QSequentialAnimationGroup* seq_animation_color_password_group = new QSequentialAnimationGroup(this);
    seq_animation_color_password_group->addAnimation(color_anim_password_start);
    seq_animation_color_password_group->addAnimation(color_anim_password_end);

    QParallelAnimationGroup* paral_anim_group = new QParallelAnimationGroup(this);
    paral_anim_group->addAnimation(seq_animation_group);
    paral_anim_group->addAnimation(seq_animation_color_login_group);
    paral_anim_group->addAnimation(seq_animation_color_password_group);
    paral_anim_group->start();
}

void MainWindow::on_authSuccess()
{
    qDebug() << "Success";
}
