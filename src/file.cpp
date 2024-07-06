#include "file.h"

File::File(QString &filename)
    : m_filename(filename)
{}

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

bool File::Close()
{
    return true;
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

void File::changeBrightness(int val, QImage &image)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            float value = m_image_data[y * width + x];
            value = qBound(0, static_cast<int>(value * val/100), 255);
            image.setPixel(x, y, qRgb(value, value, value));
        }
    }
}

File::~File()
{

}
