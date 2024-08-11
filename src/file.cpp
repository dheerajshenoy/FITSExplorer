#include "file.h"

File::File(QString &filename, QObject *parent)
    : QObject(parent), m_filename(filename)
{

    CCfits::FITS::setVerboseMode(true);
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

const std::valarray<unsigned long>& File::getImgData()
{
    return m_image_data;
}

int File::getImgDataAt(QPoint p)
{
    return static_cast<int>(m_img_widget->GetImage().pixel(p));
}

int File::getStatus()
{
    return m_status;
}

bool File::Open()
{
    try
    {
        m_fitsptr = std::make_unique<CCfits::FITS>(m_filename.toStdString(), CCfits::Read, true);
    }
    catch (const CCfits::FitsException &e)
    {
        qDebug() << "Unable to open the file: " << e.message();
        return false;
    }

    fprintf(stderr, "\n\nDD");

    const CCfits::ExtMap hduList = m_fitsptr->extension();

    m_nhdu = hduList.size();

    if (m_nhdu < 1)
        return false;

    return true;
}

ImageWidget* File::getImgWidget()
{
    return m_img_widget;
}


QList<ExtType> File::getHDUTypes()
{
    QList <ExtType> typelist;
    typelist.resize(m_nhdu);

    auto exts = m_fitsptr->extension();
    std::vector<const CCfits::HDU*> extVector;

    for (const auto& extPair : exts) {
        extVector.push_back(extPair.second);
    }

    // Iterate using an index
    for (size_t i = 0; i < extVector.size(); ++i) {
        const CCfits::HDU* hdu = extVector[i];

        // You can check for the type of HDU here
        if (dynamic_cast<const CCfits::ExtHDU*>(hdu)) {
            typelist[i] = ExtType::Image;
        } else if (dynamic_cast<const CCfits::BinTable*>(hdu)) {
            typelist[i] = ExtType::Binary;
        } else if (dynamic_cast<const CCfits::AsciiTable*>(hdu)) {
            typelist[i] = ExtType::ASCII;
        }
    }

    return typelist;
}

bool File::moveAbsRow(const int &row, int &type)
{
    m_row = row;
    try
    {
        const auto &neweext = m_fitsptr->extension(m_row);
        neweext.makeThisCurrent();
        return true;
    } catch (const CCfits::FitsException &e)
    {
        qDebug() << "Error moving to the extension: " << e.message();
        return false;
    }
}

std::vector<long> File::getImgDim()
{
    CCfits::ExtHDU &img = m_fitsptr->currentExtension();

    //img.readAllKeys();

    return std::vector<long>{img.axis(0), img.axis(1)};
}

int File::getImgSize(long *naxes)
{
    m_naxes = naxes;
    return m_status;
}

int File::getImgType()
{
    return m_fitsptr->currentExtension().bitpix();
}

int File::initImgData()
{

    auto &img = m_fitsptr->currentExtension();

    try
    {
        img.read(m_image_data);
    } catch (const CCfits::FitsException &e)
    {
        fprintf(stderr, "\nCannot read Image:%s", e.message().c_str());
        return -1;
    }

    return 0;
}

void File::changeBrightness()
{

    QImage image = m_img_widget->GetImage();
    auto height = image.height();
    auto width = image.width();

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

    return CM::grayscale(img);
}

File::~File()
{

    // fprintf(stderr, "DD");
    // if(fits_close_file(m_fptr, &m_status))
        // fits_report_error(stderr, m_status);
    m_fitsptr->destroy();

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
