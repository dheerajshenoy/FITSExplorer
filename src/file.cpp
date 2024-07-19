#include "file.h"

File::File(QString &filename, QObject *parent)
    : QObject(parent), m_filename(filename)
{

    // Change brightness when slider is moved and released
    connect(m_img_widget, &ImageWidget::changeBrightness, this, [&]() {
        changeBrightness();
    });

    auto gv = m_img_widget->GetGraphicsView();

    connect(gv, &MyGraphicsView::pixelAnalysisRequested, this, &File::pix);
}

int File::getNHDU()
{
    return m_nhdu;
}

fitsfile* File::getFPTR()
{
    return m_fptr;
}

Colormap File::getColormap()
{
    return m_colormap;
}

int File::getNKEYS()
{
    return m_nkeys;
}

float* File::getImgData()
{
    return m_image_data;
}

int File::getImgDataAt(QPoint p)
{
    // if (m_image_data)
        // return m_image_data[p.y() * width + p.x()];

    return static_cast<int>(m_img_widget->GetImage().pixel(p));
}

int File::getStatus()
{
    return m_status;
}

bool File::Open()
{
    // set status before opening the file according to then norms of cfitsio
    m_status = 0;
    if(fits_open_file(&m_fptr, m_filename.toStdString().c_str(), READONLY, &m_status))
    {
        fits_report_error(stderr, m_status);
        return false;
    }

    if(fits_get_num_hdus(m_fptr, &m_nhdu, &m_status))
    {
        fits_report_error(stderr, m_status);
        return false;;
    }

    if (m_nhdu < 1)
        return false;

    return true;
}

ImageWidget* File::getImgWidget()
{
    return m_img_widget;
}


QList<int> File::getHDUTypes()
{
    QList <int> typelist;
    typelist.resize(m_nhdu);
    m_status = 0;
    for(int i=1; i <= m_nhdu; i++)
    {

        if(fits_movabs_hdu(m_fptr, i, nullptr, &m_status))
        {
            fits_report_error(stderr, m_status);
            return {-1};
        }

        int type;

        if(fits_get_hdu_type(m_fptr, &type, &m_status))
        {
            fits_report_error(stderr, m_status);
            return {-1};
        }

        typelist[i] = type;

    }

    return typelist;
}

int File::moveAbsRow(const int &row, int &type)
{

    if(fits_movabs_hdu(m_fptr, row, &type, &m_status))
    {
        fits_report_error(stderr, m_status);
        return m_status;
    }

    m_row = row;

    return m_status;
}

int File::getImgDim()
{
    if(fits_get_img_dim(m_fptr, &m_naxis, &m_status))
    {
        fits_report_error(stderr, m_status);
        return -1;
    }

    return m_naxis;
}

int File::getImgSize(long *naxes)
{
    if(fits_get_img_size(m_fptr, m_naxis, naxes, &m_status))
    {
        fits_report_error(stderr, m_status);
        return m_status;
    }

    m_naxes = naxes;
    return m_status;
}

int File::getImgType()
{

    if(fits_get_img_type(m_fptr, &m_bitpix, &m_status))
    {
        fits_report_error(stderr, m_status);
        return -1;
    }

    return m_bitpix;
}

bool File::checkIfValidDim()
{
    if (!m_naxes) return false;

    width = m_naxes[0];
    height = m_naxes[1];

    if(width <= 0 || height <= 0)
    {
        return false;
    }

    return true;
}

int File::initImgData()
{

    try {
        m_image_data = new float[width * height];
    }
    catch(const std::bad_array_new_length &e)
    {
        qCritical() << "Caught std::bad_array_new_length: " << e.what();
        // QMessageBox::critical(this, "Error", "Bad array length");
        return 1;
    }

    long fpixel = 1; // Starting pixel

    if(fits_read_img(m_fptr, TFLOAT, fpixel, width * height,
                      NULL, m_image_data, NULL, &m_status))
    {
        fits_report_error(stderr, m_status);
        return m_status;
    }

    return 0;
}

void File::changeBrightness()
{

    QImage image = m_img_widget->GetImage();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            float value = m_image_data[y * width + x];
            value = qBound(0, static_cast<int>(value * static_cast<int>(m_img_widget->GetSlider()->value())/100), 255);
            image.setPixel(x, y, qRgb(value, value, value));
        }
    }

    if (getColormap() != Colormap::None)
    {
        image.convertTo(QImage::Format_Indexed8);
        image = ApplyColormap(image);
    }

    m_img_widget->setPixmap(QPixmap::fromImage(image));
}


QImage File::ApplyColormap(QImage &img)
{
    if (m_should_copy_before_applying_colormap)
    {
        m_orig_img = img.copy();
        m_should_copy_before_applying_colormap = false;
    }
    switch(m_colormap)
    {

    case Colormap::None:
        return m_orig_img;
        break;

    case Colormap::Autumn:
        return CM::autumn(img);
        break;

    case Colormap::Bone:
        return CM::bone(img);
        break;

    case Colormap::Cool:
        return CM::cool(img);
        break;

    case Colormap::Grayscale:
        return CM::grayscale(img);
        break;

    case Colormap::HSV:
        return CM::hsv(img);
        break;

    case Colormap::Hot:
        return CM::hot(img);
        break;

    case Colormap::Winter:
        return CM::winter(img);
        break;

    case Colormap::Jet:
        return CM::jet(img);
        break;

    case Colormap::Ocean:
        return CM::ocean(img);
        break;

    case Colormap::Parula:
        return CM::parula(img);
        break;

    case Colormap::Pink:
        return CM::pink(img);
        break;

    case Colormap::Summer:
        return CM::summer(img);
        break;

    case Colormap::Rainbow:
        return CM::rainbow(img);
        break;

    case Colormap::Turbo:
        return CM::turbo(img);
        break;

    case Colormap::Spring:
        return CM::spring(img);
        break;

    case Colormap::Custom:
        break;

    case Colormap::SDO_AIA_94:
        return CM::SDO_AIA_94(img);
        break;

    case Colormap::SDO_AIA_131:
        return CM::SDO_AIA_131(img);
        break;

    case Colormap::SDO_AIA_171:
        return CM::SDO_AIA_171(img);
        break;

    case Colormap::SDO_AIA_193:
        return CM::SDO_AIA_193(img);
        break;

    case Colormap::SDO_AIA_211:
        return CM::SDO_AIA_211(img);
        break;


    case Colormap::Temp:
        return CM::temp(img);
        break;
    }
}

File::~File()
{

    // fprintf(stderr, "DD");
    if(fits_close_file(m_fptr, &m_status))
        fits_report_error(stderr, m_status);

    if (overview != nullptr)
    {
        delete overview;
        overview = nullptr;
    }

    if (m_img_widget != nullptr)
    {
        delete m_img_widget;
        m_img_widget = nullptr;
    }

    // if (m_naxes != nullptr)
    // {
        // delete [] m_naxes;
        // m_naxes = nullptr;
    // }

    if (m_image_data != nullptr)
    {
        delete [] m_image_data;
        m_image_data = nullptr;
    }

}

void File::setColormap(const Colormap &cmap)
{
    m_colormap = cmap;

    MyGraphicsView *gv = m_img_widget->GetGraphicsView();
    QImage img = gv->GetPixmap().toImage();
    img.convertTo(QImage::Format_Indexed8);
    gv->setPixmap(QPixmap::fromImage(ApplyColormap(img)));
}

void File::resetBrightness()
{
    m_img_widget->setImage(m_orig_img);
}

int File::getCurrentHDU()
{
    return m_row;
}

void File::fitToWidth(int width)
{
    auto gv = m_img_widget->GetGraphicsView();
    gv->fitToWidth(width);

}

void File::setSelectMode(bool state)
{
    setMode(Mode::SELECT_MODE);
    m_img_widget->GetGraphicsView()->setSelectMode(state);
}

void File::setPixelAnalysisMode(bool state)
{
    setMode(Mode::PIXEL_ANALYSIS_MODE);
    m_img_widget->GetGraphicsView()->setPixelAnalysisMode(state);
}

void File::setMode(Mode mode)
{
    m_mode = mode;
    emit modeChanged(mode);
}

Mode File::getMode()
{
    return m_mode;
}

void File::pix(QPoint loc)
{
    m_img_widget->GetGraphicsView()->setPixValue(getImgDataAt(loc));
    m_img_widget->GetGraphicsView()->movePixAnalyser(loc);
}
