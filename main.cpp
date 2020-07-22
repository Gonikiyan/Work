#include<iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include"stb_image_write.h"

using namespace std;

class Bitmap {
private :
    uint32_t const static w = 800, h = 600;
    uint32_t color;
    uint32_t pixels[h][w];
public :

    Bitmap(uint32_t x) {
        color = x;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                pixels[i][j] = color;
            }
        }
    }

    void horizLine(double start_col, double end_col, int row, uint32_t color1) {
        for (int i = start_col; i < end_col; i++) {
            pixels[row][i] = color1;
        }
    }

    void vertLine(double start_row, double end_row, int col, uint32_t color1) {
        for (int i = start_row; i < end_row; i++) {
            pixels[i][col] = color1;
        }
    }

    void drawRect(double x_axis, double y_axis, double width, double height, uint32_t color2) {
        horizLine(x_axis, x_axis + width, y_axis, color2);
        vertLine(y_axis, y_axis + height, x_axis, color2);
        vertLine(x_axis, x_axis + height, x_axis + width, color2);
        horizLine(y_axis, y_axis + width, y_axis + height, color2);

    }

    void fillRect(double x_axis, double y_axis, double width, double height, uint32_t color3) {
        for (int j = y_axis; j <= y_axis + height; j++) {
            for (int k = x_axis; k <= x_axis + width; k++) {
                pixels[j][k] = color3;
            }
        }
    }

    void line(int x1, int y1, int x2, double y2, int color4){
        double diff_x = x2-x1, diff_y = y2-y1;
        double slope_error =  2*(diff_y) - diff_x;
        if(x1<x2 && y1<y2) {                                             // assumption of bresenham's line algorithm
            for (int i = x1; i <= x2; i++) {
                if(slope_error > 0){
                    slope_error += 2*diff_y - 2*diff_x;
                    x1++; y1++;

                    pixels[y1][i] = color4;

                }
                else{
                    slope_error += 2*diff_y;
                    x1++;

                    pixels[y1][i] = color4;

                }
            }
        }
    }

    void ellipse(double a, double b, double c, double d) {


        for(int i=1; i<=360; i++){
             int x=a+((c/2)*cos(i*M_PI/180));
             int y=b+((d/2)*sin(i*M_PI/180));
             pixels[y][x]=0xFFFFFFFF;
        }
    }

    void antialiasedLine(int x1, int y1, int x2, double y2, int color4){
        double diff_x = x2-x1, diff_y = y2-y1;
        double slope_error =  2*(diff_y) - diff_x;
        if(x1<x2 && y1<y2) {                                             // assumption of bresenham's line algorithm
            for (int i = x1; i <= x2; i++) {
                if(slope_error > 0){
                    slope_error += 2*diff_y - 2*diff_x;
                    x1++; y1++;
                    pixels[y1][i-2]=0x80808080;
                    pixels[y1][i-1]=0x8080FFFF;
                    pixels[y1][i] = color4;
                    pixels[y1][i+1]=0x8080FFFF;
                    pixels[y1][i+2]=0x80808080;
                }
                else{
                    slope_error += 2*diff_y;
                    x1++;

                    pixels[y1][i-2]=0x80808080;
                    pixels[y1][i-1]=0x8080FFFF;
                    pixels[y1][i] = color4;
                    pixels[y1][i+1]=0x8080FFFF;
                    pixels[y1][i+2]=0x80808080;

                }
            }
        }
    }

    void save(const char filename[]) {
        stbi_write_png(filename, w, h, 4, pixels, w * 4);
    }
};


int main() {
    // FIRST PART (ADD COLORS HERE)
    constexpr uint32_t BLACK = 0xFF000000; // black opaque
    constexpr uint32_t RED = 0xFF0000FF; // red opaque
    constexpr uint32_t BLUE = 0xFFFF0000; // blue opaque
    constexpr uint32_t WHITE = 0xFFFFFFFF; // white opaque
    constexpr uint32_t YELLOW = 0xFF00FFFF; //yellow opaque



    // SECOND PART (DO NOT EDIT)
    int xcenter = 100;
    int ycenter = 100;
    int xdiameter = 200;
    int ydiameter = 100;

    Bitmap b(BLACK); // Hardcoded size (**800 x 600 pixels**)

    b.horizLine(0, 500, 200, RED); // Red horizontal line, from x=0 to x=500, at y = 200
    b.vertLine(0, 399, 300, RED); // Red vertical line, from y=0 to y=399, at x = 300
    b.drawRect(200, 200, 100, 50, BLUE); // Blue rectangle, TOP-LEFT at x=200, y=200. width=100, height=50
    b.fillRect(201, 201, 98, 48, WHITE); // White rectangle, same rules as above, but filled with color
    b.line(400, 0, 550, 300, YELLOW);  //Line drawn using https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
    b.ellipse(xcenter, ycenter, xdiameter, ydiameter); //Ellipse using specs from above
    b.antialiasedLine(300,0, 550,500, YELLOW);
    b.save("bitmap4.png");


    // THIRD PART - OPTIONAL FUNCTION
    // 100pt bonus for properly implementing Wu's antialiasing
    //https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
    //b.antialiasedLine(400,0, 550,300, YELLOW);
}
