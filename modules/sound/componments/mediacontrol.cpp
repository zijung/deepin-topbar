#include "mediacontrol.h"
#include "fontlabel.h"

#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>

using namespace dtb;
using namespace dtb::sound;
using namespace dtb::widgets;

MediaControl::MediaControl(QWidget *parent)
    : QFrame(parent)
{
    m_lastBtn = new FontLabel;
    m_lastBtn->setIcon(QChar(0xE893), 18);
    m_lastBtn->installEventFilter(this);

    m_previousBtn = new FontLabel;
    m_previousBtn->setIcon(QChar(0xE892), 18);
    m_previousBtn->installEventFilter(this);

    m_pauseBtn = new FontLabel;
    m_pauseBtn->installEventFilter(this);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(2);
    layout->setSpacing(0);

    layout->addWidget(m_previousBtn, 0, Qt::AlignLeft | Qt::AlignVCenter);
    layout->addWidget(m_pauseBtn, 0, Qt::AlignCenter | Qt::AlignVCenter);
    layout->addWidget(m_lastBtn, 0, Qt::AlignRight | Qt::AlignVCenter);

    setPlayState(Pause);

    setLayout(layout);
}

void MediaControl::setPlayState(MediaControl::PlayState state) {
    m_playState = state;

    switch (state) {
    case Play: {
        m_pauseBtn->setIcon(QChar(0xE769), 18);
        break;
    }
    case Stop:
        break;
    case Pause: {
        m_pauseBtn->setIcon(QChar(0xE768), 18);
        break;
    }
    case Last:
        break;
    case Previous:
        break;
    default:
        break;
    }
}

bool MediaControl::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_lastBtn) {
        if (event->type() == QMouseEvent::Enter) {
            m_lastBtn->setStyleSheet("color: #00BFFF;");
        }

        if (event->type() == QMouseEvent::Leave) {
            m_lastBtn->setStyleSheet("color: rgb(67, 67, 62);");
        }

        if (event->type() == QMouseEvent::MouseButtonPress) {
            m_lastBtn->setStyleSheet("color: #1E90FF;");
        }

        if (event->type() == QMouseEvent::MouseButtonRelease) {
            m_lastBtn->setStyleSheet("color: rgb(67, 67, 62);");
            emit requestLast();
        }
    }

    if (watched == m_previousBtn) {
        if (event->type() == QMouseEvent::Enter) {
            m_previousBtn->setStyleSheet("color: #00BFFF;");
        }

        if (event->type() == QMouseEvent::Leave) {
            m_previousBtn->setStyleSheet("color: rgb(67, 67, 62);");
        }

        if (event->type() == QMouseEvent::MouseButtonPress) {
            m_previousBtn->setStyleSheet("color: #1E90FF;");
        }

        if (event->type() == QMouseEvent::MouseButtonRelease) {
            m_previousBtn->setStyleSheet("color: rgb(67, 67, 62);");
            emit requestPrevious();
        }
    }

    if (watched == m_pauseBtn) {
        if (event->type() == QMouseEvent::Enter) {
            m_pauseBtn->setStyleSheet("color: #00BFFF;");
        }

        if (event->type() == QMouseEvent::Leave) {
            m_pauseBtn->setStyleSheet("color: rgb(67, 67, 62);");
        }

        if (event->type() == QMouseEvent::MouseButtonPress) {
            m_pauseBtn->setStyleSheet("color: #1E90FF;");
        }

        if (event->type() == QMouseEvent::MouseButtonRelease) {
            m_pauseBtn->setStyleSheet("color: rgb(67, 67, 62);");
            emit requestPause();
        }
    }

    return false;
}
