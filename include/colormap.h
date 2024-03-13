#pragma once

#include <qt/QtGui/QImage>

class CM
{

    public:
        static QImage winter(const QImage& img);
        static QImage autumn(const QImage& img);
        static QImage bone(const QImage& img);
        static QImage cool(const QImage& img);
        static QImage hot(const QImage& img);
        static QImage hsv(const QImage& img);
        static QImage jet(const QImage& img);
        static QImage ocean(const QImage& img);
        static QImage parula(const QImage& img);
        static QImage pink(const QImage& img);
        static QImage rainbow(const QImage& img);
        static QImage spring(const QImage& img);
        static QImage summer(const QImage& img);
        static QImage turbo(const QImage& img);
        static QImage grayscale(const QImage& img);
};
