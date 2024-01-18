#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

void displayImage(const Mat& image) {
    imshow("Image Processing Tool", image);
    waitKey(0);
}

void applyGrayscale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

void applyBlur(Mat& image) {
    blur(image, image, Size(5, 5));
}

void applySharpen(Mat& image) {
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(image, image, image.depth(), kernel);
}

void adjustBrightnessContrast(Mat& image, double alpha, int beta) {
    image.convertTo(image, -1, alpha, beta);
}

void cropImage(Mat& image, int x, int y, int width, int height) {
    Rect roi(x, y, width, height);
    image = image(roi);
}

void resizeImage(Mat& image, int newWidth, int newHeight) {
    resize(image, image, Size(newWidth, newHeight));
}

int main() {
    Mat image = imread("path_to_your_image.jpg");

    if (image.empty()) {
        std::cerr << "Error: Unable to load the image." << std::endl;
        return -1;
    }

    while (true) {
        std::cout << "\n===== IMAGE PROCESSING TOOL =====" << std::endl;
        std::cout << "1. Display Image\n2. Grayscale\n3. Blur\n4. Sharpen\n";
        std::cout << "5. Adjust Brightness/Contrast\n6. Crop Image\n7. Resize Image\n8. Save Image\n9. Exit\n";

        int choice;
        std::cout << "Enter your choice (1-9): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayImage(image);
                break;
            case 2:
                applyGrayscale(image);
                break;
            case 3:
                applyBlur(image);
                break;
            case 4:
                applySharpen(image);
                break;
            case 5: {
                double alpha;
                int beta;
                std::cout << "Enter alpha (contrast adjustment, e.g., 1.5): ";
                std::cin >> alpha;
                std::cout << "Enter beta (brightness adjustment, e.g., 30): ";
                std::cin >> beta;
                adjustBrightnessContrast(image, alpha, beta);
                break;
            }
            case 6: {
                int x, y, width, height;
                std::cout << "Enter x, y, width, height for cropping: ";
                std::cin >> x >> y >> width >> height;
                cropImage(image, x, y, width, height);
                break;
            }
            case 7: {
                int newWidth, newHeight;
                std::cout << "Enter new width and height for resizing: ";
                std::cin >> newWidth >> newHeight;
                resizeImage(image, newWidth, newHeight);
                break;
            }
            case 8: {
                imwrite("processed_image.jpg", image);
                std::cout << "Image saved successfully." << std::endl;
                break;
            }
            case 9:
                std::cout << "Exiting the Image Processing Tool. Goodbye!" << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please enter a valid option (1-9)." << std::endl;
        }
    }

    return 0;
}
