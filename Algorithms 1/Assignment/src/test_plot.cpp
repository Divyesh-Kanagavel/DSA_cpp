#include <cairo.h>
#include <vector>

int main() {
    // Define the size of your drawing area
    int width = 400;
    int height = 400;

    // Create an image surface and a Cairo context
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cairo_t *cr = cairo_create(surface);

    // Set background to white
    cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
    cairo_paint(cr);

    // Define two points
    double x1 = 100, y1 = 100;
    double x2 = 300, y2 = 300;

    // Draw the first point (a small blue circle)
    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0); // Blue
    cairo_arc(cr, x1, y1, 5.0, 0, 2 * 3.14159);
    cairo_fill(cr);

    // Draw the second point (a small blue circle)
    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0); // Blue
    cairo_arc(cr, x2, y2, 5.0, 0, 2 * 3.14159);
    cairo_fill(cr);

    // Draw a red line segment between the two points
    cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); // Red
    cairo_set_line_width(cr, 2.0);
    cairo_move_to(cr, x1, y1);
    cairo_line_to(cr, x2, y2);
    cairo_stroke(cr);

    // Save the plot to a PNG file
    cairo_surface_write_to_png(surface, "test_plot.png");

    // Clean up
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}