#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QLabel>
#include <QMediaPlayer>

class MyButton : public QLabel {
    QMediaPlayer *sound;
    Q_OBJECT
public:
    MyButton() : QLabel(), sound(new QMediaPlayer()) {
        setPixmap(QPixmap(":/images/button.png"));
        sound->setMedia(QUrl("qrc:/sound/correct.wav"));
        sound->setVolume(5);
        connect(sound, QOverload<QMediaPlayer::State>::of(&QMediaPlayer::stateChanged),
            [=](QMediaPlayer::State state) {
            if (state == QMediaPlayer::StoppedState) setPixmap(QPixmap(":/images/button.png"));
        });
    }

    void mousePressEvent(QMouseEvent *e) override {
        setPixmap(QPixmap(":/images/button_pushed.png"));
        sound->play();
    }

};

#endif // MYBUTTON_H
