# DFITS

* A modern FITS image viewer written using CFITSIO library.

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





## Libraries Used

* CFITSIO
* QT (for GUI)

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

