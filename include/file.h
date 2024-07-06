#ifndef FILE_H
#define FILE_H

#include <fitsio2.h>
#include "qcustomplot.h"
#include "imagewidget.h"
#include "overview.h"
#include "lightcurve.h"
#include "colormap.h"
#include <QMessageBox>

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
    Custom
};


class File
{
public:
    File(QString &filename);
    ~File();

    bool Open();
    bool Close();
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
    int moveAbsRow(const int &row, int &type);
    int initImgData();
    int getCols();
    int getRows();
    ImageWidget* getImgWidget();
    QImage ApplyColormap(QImage &img);

private:

    fitsfile *m_fptr;
    QString m_filename;

    int m_status = 0;
    float *m_image_data;
    int width, height;
    int m_bitpix;
    int m_nhdu;
    int m_nkeys;
    int m_naxis;
    long *m_naxes;
    QCPItemStraightLine *m_line;
    Overview *overview = new Overview();
    Colormap m_colormap = Colormap::None;
    QCustomPlot *lightCurvePlot;
    QImage m_orig_img;
    ImageWidget *m_img_widget = new ImageWidget();

    bool m_should_copy_before_applying_colormap = true;

};

#endif // FILE_H
