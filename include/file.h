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
    float* getImgData();
    int getStatus();
    int getImgDim();
    int getImgSize(long *naxes);
    int getImgType();
    bool checkIfValidDim();
    QList<int> getHDUTypes();
    void changeBrightness();
    void resetBrightness();
    int moveAbsRow(const int &row, int &type);
    int initImgData();
    int getCols();
    int getRows();
    ImageWidget* getImgWidget();
    QImage ApplyColormap(QImage &img);
    void setColormap(const Colormap &cmap);
    int getCurrentHDU();
    void fitToWidth(int);
    void setSelectMode(bool);

private:

    fitsfile *m_fptr;
    QString m_filename;

    int m_row = -1;
    int m_status = 0;
    float *m_image_data = nullptr;
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

    bool m_select_mode = false;
};

#endif // FILE_H
