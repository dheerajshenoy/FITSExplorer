# FITSExplorer

A modern FITS image viewer written in C++ using CFITSIO library.

## What are FITS files ?

Flexible Image Transport System images or FITS for short are image formats used extensively in Astronomy domain. These are completely different from your typical image formats like JPEG, PNG etc. when it comes to the way they store their data. FITS files can contain many kinds of data like BINARY TABLES, ASCII TABLES or IMAGE DATA. In addition to this, they also contain metadata which is the main focus of these file formats. These metadatas contain imoportant information like the location from which the image was taken, observer position, quality of the data, dimensions etc. which are very important for astronomical and astrophysical applications. For those interested, refer to this [wiki](https://en.wikipedia.org/wiki/FITS) or go straight to NASA [page](https://fits.gsfc.nasa.gov/fits_primer.html) who created the format.

## How is it modern ?

Well....it looks modern and sleek.

## Why did I create this ?

This started off as a project I did for the Astronomy & Astrophysics class at my University during my Masters. Most of the FITS image viewers that exist like SAOImage DS9, qfitsview looked a bit ancient, and since I was working on FITS files extensively for my thesis, I went ahead and created this software.

## How does it work ?

1. CFITSIO library from NASA is a defacto-standard library for accessing these files. This is written in C.
2. For the frontend, I use Qt framework
3. I just made the two libraries talk to each other and create this magical software.

## Features

1. View FITS Images
2. Apply colormap
3. Check light curve
4. Add Region of Interests (ROI)
5. Export FITS images to different file formats like PDF, JPEG, PNG etc.

## Note

There are many features that are not yet implemented like adding and editing markers, image overview, image overview of selected ROI, resetting image.

## Installation

1. Install the necessary dependencies `Qt6-base`, `Qt6-charts`, `cfitsio`
    - If you're on Arch Linux the install command will be
      `sudo pacman -S qt6-base qt6-charts cfitsio`
    - If you're on any other linux, check for these packages as they might be differently named
       
2. Clone this repo
    - `git clone github.com/dheerajshenoy/FITSExplorer` 
4. cd into the directory and run the following command
    - `cd FITSExplorer && qmake6 && make`
5. The software binary will be called `FITSExplorer`
# Screenshots

![img1](https://github.com/dheerajshenoy/FITSExplorer/blob/main/images/1.png)
![img2](https://github.com/dheerajshenoy/FITSExplorer/blob/main/images/2.png)
![img3](https://github.com/dheerajshenoy/FITSExplorer/blob/main/images/3.png)
![img4](https://github.com/dheerajshenoy/FITSExplorer/blob/main/images/4.png)
![img5](https://github.com/dheerajshenoy/FITSExplorer/blob/main/images/5.png)
![img6](https://github.com/dheerajshenoy/FITSExplorer/blob/main/images/6.png)
![img7](https://github.com/dheerajshenoy/FITSExplorer/blob/main/images/7.png)

# Demo

https://github.com/user-attachments/assets/58015ded-e0eb-4ac7-94de-3892cdff4e7a

https://github.com/user-attachments/assets/d87524d0-8cf9-44b1-83fd-d46f96c861ee

https://github.com/user-attachments/assets/cf7fe125-6aee-4c1c-822f-9ea5583c14c4

# DONE

- [x] Open and display FITS images
- [x] Show image coordinates
- [x] Change brightness
- [x] Show HDU list
- [x] Show HEADER information
- [x] Show file information
- [x] Add default colormap option
- [x] make table change when changing tabs
- [x] SDO AIA colormaps
- [x] ROI Box highlight selection color feedback
- [x] Display Image: The viewer should be able to load and display FITS images, including support for both single and multi-dimensional images.
- [x] Zoom and Pan: Users should be able to zoom in and out of the image and pan across different parts of the image to explore details.
- [x] Colormap Selection: Users should be able to select different color maps (e.g., grayscale, inverted grayscale, heatmaps) to visualize the image data with various color representations.
- [x] Zoom into region of Interest (ROI)
- [x] Overlay and Annotation: Enable overlaying additional graphics, markers, or annotations on the image for visual analysis and interpretation.
- [x] Metadata Display: Provide access to FITS header metadata to view essential information about the image, including keywords like object name, exposure time, and instrument settings.
- [x] Histogram and Statistics: Display histograms of pixel values and provide basic statistics (e.g., mean, median, standard deviation) of the image data to analyze its distribution.
- [x] Export and Saving: Allow users to export images to various formats (e.g., FITS, PNG, JPEG) and save any modifications made during analysis.
- [x] Cross-platform Compatibility: Ensure compatibility with multiple operating systems (e.g., Windows, macOS, Linux) to reach a broader audience of users.

# TODO

- [ ] Image Stretching: It should support different types of image stretching methods, such as linear, logarithmic, and histogram equalization, to enhance the visibility of faint details or adjust contrast.
- [ ] Region of Interest (ROI)
- [ ] Allow users to define regions of interest (ROIs) within the image for analysis, such as measuring intensity profiles or extracting statistics.
- [ ] Image Comparison: Support the ability to open and compare multiple FITS images simultaneously for qualitative and quantitative analysis.
- [ ] Performance Optimization: Optimize rendering performance for handling large, high-resolution images efficiently, ensuring smooth interaction and responsiveness.
- [ ] Customization and Extensions: Provide options for customization and extension through plugins or scripting interfaces, allowing users to tailor the viewer to their specific needs.

