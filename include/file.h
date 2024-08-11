#ifndef FILE_H
#define FILE_H

#include <fitsio2.h>
#include "qcustomplot.h"
#include "imagewidget.h"
#include "overview.h"
#include "lightcurve.h"
#include "colormap.h"
#include <QMessageBox>
#include <QObject>
#include "mode.h"
#include "exttype.h"
#include <QtDebug>
#include <CCfits/CCfits>


enum Colormap
{
    None,
    Grayscale,
    Winter,
    Autumn,
    Bone,
    Cool,
    Hot,
    HSV,
    Jet,
    Ocean,
    Parula,
    Pink,
    Rainbow,
    Spring,
    Summer,
    Turbo,
    Custom,
    SDO_AIA_94,
    SDO_AIA_131,
    SDO_AIA_171,
    SDO_AIA_193,
    SDO_AIA_211,
    SDO_AIA_304,
    SDO_AIA_1600,
    SDO_AIA_4500,
    SDO_AIA_1700,
    Temp
};

class File : public QObject
{
    Q_OBJECT
public:
    File(QString &filename, QObject *obj = nullptr);
    ~File();

    bool Open();
    int getNHDU();
    fitsfile* getFPTR();
    Colormap getColormap();
    int getNKEYS();
    const std::valarray<unsigned long>& getImgData();
    int getImgDataAt(QPoint);
    int getStatus();
    std::vector<long> getImgDim();
    int getImgSize(long *naxes);
    int getImgType();
    QList<ExtType> getHDUTypes();
    void changeBrightness();
    void resetBrightness();
    bool moveAbsRow(const int &row, int &type);
    int initImgData();
    int getCols();
    int getRows();
    ImageWidget* getImgWidget();
    QImage ApplyColormap(QImage &img);
    void setColormap(const Colormap &cmap);
    int getCurrentHDU();
    void fitToWidth(int);
    void setSelectMode(bool);
    void setPixelAnalysisMode(bool);
    void setMode(Mode mode);
    Mode getMode();
    void pix(QPoint);


signals:
    void modeChanged(Mode);

private:

    fitsfile *m_fptr;
    std::unique_ptr<CCfits::FITS> m_fitsptr;
    QString m_filename;

    int m_row = -1;
    int m_status = 0;
    // float *m_image_data = nullptr;
    std::valarray<unsigned long> m_image_data;
    int width, height;
    int m_bitpix;
    int m_nhdu;
    int m_nkeys;
    int m_naxis;
    long *m_naxes = nullptr;
    QCPItemStraightLine *m_line = nullptr;
    Overview *overview = nullptr;
    Colormap m_colormap = Colormap::None;
    QCustomPlot *lightCurvePlot = nullptr;
    QImage m_orig_img;
    ImageWidget *m_img_widget = new ImageWidget();
    bool m_should_copy_before_applying_colormap = true;
    Mode m_mode  = Mode::NORMAL_MODE;
};

#endif // FILE_H
