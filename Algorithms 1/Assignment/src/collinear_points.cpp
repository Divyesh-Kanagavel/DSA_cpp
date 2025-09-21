#include <iostream>
#include <cairo.h>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

// To compile: g++ collinear_points.cpp -o collinear_points $(pkg-config --cflags --libs cairo)

using namespace std;

// Global variables for Cairo, generally not good practice but used here to match the user's code structure
int width = 32767;
int height = 32767;
cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
cairo_t *cr = cairo_create(surface);

// Initialize the Cairo canvas
void init_canvas()
{
    // Set background to white
    cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
    cairo_paint(cr);
}

class Point
{
public:
    // Public member variables for easier access
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    // Default constructor to allow vector creation
    Point() : x(0), y(0) {}

    void draw() const
    {
        cairo_set_source_rgb(cr, 0.0, 0.0, 1.0); // Blue
        cairo_arc(cr, x, y, 5.0, 0, 2 * M_PI);
        cairo_fill(cr);
    }

    void drawTo(const Point& other) const
    {
        cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); // Red
        cairo_set_line_width(cr, 2.0);
        cairo_move_to(cr, x, y);
        cairo_line_to(cr, other.x, other.y);
        cairo_stroke(cr);
    }

    string toString() const
    {
        return "( " + to_string(x) + ", " + to_string(y) + " )";
    }

    // Custom comparison for sorting points by y, then x
    bool operator<(const Point& other) const
    {
        if (y == other.y)
            return x < other.x;
        return y < other.y;
    }

    // Equality check for points
    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }

    // Inequality check
    bool operator!=(const Point& other) const
    {
        return !(*this == other);
    }

    // Method to calculate slope to another point
    double slopeTo(const Point& other) const
    {
        if (*this == other)
            return -numeric_limits<double>::infinity();
        if (y == other.y)
            return 0.0;
        if (x == other.x)
            return numeric_limits<double>::infinity();

        return static_cast<double>(other.y - y) / static_cast<double>(other.x - x);
    }
};

// Functor for sorting points by slope relative to a reference point
struct SlopeComparator
{
    const Point& p;
    SlopeComparator(const Point& p) : p(p) {}
    bool operator()(const Point& q, const Point& r) const
    {
        return p.slopeTo(q) < p.slopeTo(r);
    }
};

class LineSegment
{
public:
    Point p; // start point
    Point q; // end point

    LineSegment(Point p, Point q)
    {
        // Ensure canonical representation (p is the smaller point)
        if (q < p) {
            this->p = q;
            this->q = p;
        } else {
            this->p = p;
            this->q = q;
        }
    }

    string toString() const
    {
        return p.toString() + " -> " + q.toString();
    }

    void draw() const
    {
        p.drawTo(q);
    }

    // Equality check for line segments
    bool operator==(const LineSegment& other) const
    {
        return (p == other.p) && (q == other.q);
    }
    
    // Comparison for sorting line segments
    bool operator<(const LineSegment& other) const
    {
        if (p < other.p) return true;
        if (other.p < p) return false;
        return q < other.q;
    }
};

class BruteCollinearPoints
{
public:
    BruteCollinearPoints(const vector<Point>& points)
    {
        this->points = points;
    }

    int numberLineSegments()
    {
        // Ensure segments are found before returning the count
        if (linesegments.empty()) {
            findLineSegments();
        }
        return linesegments.size();
    }

    vector<LineSegment> segments()
    {
        findLineSegments();
        return linesegments;
    }

private:
    vector<Point> points;
    vector<LineSegment> linesegments;

    // Correct method to remove duplicates from a sorted vector
    void remove_duplicates()
    {
        // Sort line segments for correct duplicate removal
        std::sort(linesegments.begin(), linesegments.end());
        // along with duplicates, we need to remove the sub segments as well
        vector<LineSegment> unique_segments;
        unique_segments.push_back(linesegments[0]);
        for(int i=1;i < linesegments.size();++i)
        {
            LineSegment last_segment = unique_segments.back();
            LineSegment cur_segment = linesegments[i];
            // check if cur_segment is a subsegment of last segment
            if (last_segment.p == cur_segment.p && 
            last_segment.p.slopeTo(last_segment.q) == last_segment.p.slopeTo(cur_segment.q))
            {}
            else
                unique_segments.push_back(cur_segment);
        }
        linesegments = unique_segments;
    }

    // Find line segments with at least 4 collinear points using a brute-force approach
    void findLineSegments()
    {
        linesegments.clear();
        linesegments.reserve(points.size());

        size_t size = points.size();
        if (size < 4)
        {
            cout << "Not enough points to find line segments!\n";
            return;
        }

        // Sort points to handle collinearity checks robustly
        vector<Point> sorted_points = points;
        std::sort(sorted_points.begin(), sorted_points.end());

        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = i + 1; j < size; ++j)
            {
                for (size_t k = j + 1; k < size; ++k)
                {
                    for (size_t l = k + 1; l < size; ++l)
                    {
                        // Check for collinearity using cross-product to avoid floating-point issues
                        // Collinearity for 3 points (p1, p2, p3): (y2 - y1)*(x3 - x1) == (y3 - y1)*(x2 - x1)
                        if ((long long)(sorted_points[j].y - sorted_points[i].y) * (sorted_points[k].x - sorted_points[i].x) == (long long)(sorted_points[k].y - sorted_points[i].y) * (sorted_points[j].x - sorted_points[i].x) &&
                            (long long)(sorted_points[k].y - sorted_points[i].y) * (sorted_points[l].x - sorted_points[i].x) == (long long)(sorted_points[l].y - sorted_points[i].y) * (sorted_points[k].x - sorted_points[i].x))
                        {
                            // All four points are collinear. Add the line segment.
                            linesegments.push_back(LineSegment(sorted_points[i], sorted_points[l]));
                        }
                    }
                }
            }
        }
        remove_duplicates();
    }
};

class FastCollinearPoints
{
public:
    FastCollinearPoints(const vector<Point>& points)
    {
        // Copy points to avoid modifying the original vector and check for duplicates
        vector<Point> unique_points = points;
        std::sort(unique_points.begin(), unique_points.end());
        for (size_t i = 0; i < unique_points.size() - 1; ++i)
        {
            if (unique_points[i] == unique_points[i+1]) {
                // Handle duplicate points
                cout << "Error: duplicate points are not allowed." << endl;
                this->points.clear();
                return;
            }
        }
        this->points = points;
    }

    int numberLineSegments()
    {
        // Ensure segments are found before returning the count
        if (line_segments.empty()) {
            findLineSegments();
        }
        return line_segments.size();
    }

    vector<LineSegment> segments()
    {
        findLineSegments();
        return line_segments;
    }

private:
    vector<Point> points;
    vector<LineSegment> line_segments;

    // Correct method to remove duplicates from a sorted vector
    void remove_duplicates()
    {
        // Sort line segments for correct duplicate removal
        std::sort(line_segments.begin(), line_segments.end());

        int i = 0;
        while (i < line_segments.size() - 1)
        {
            if (line_segments[i] == line_segments[i+1])
            {
                line_segments.erase(line_segments.begin() + i);
            }
            else
            {
                i++;
            }
        }
    }

    void findLineSegments()
    {
        line_segments.clear();
        if (points.size() < 4) {
            return;
        }

        vector<Point> points_copy = points;

        for (size_t i = 0; i < points_copy.size(); ++i)
        {
            Point p = points_copy[i];
            vector<Point> other_points;
            for(size_t j=0; j < points_copy.size(); ++j)
            {
                if(i != j) {
                    other_points.push_back(points_copy[j]);
                }
            }
            
            // Sort remaining points by slope relative to p
            SlopeComparator sc(p);
            std::sort(other_points.begin(), other_points.end(), sc);

            int count = 1;
            for (size_t j = 1; j < other_points.size(); ++j)
            {
                if (abs(p.slopeTo(other_points[j]) - p.slopeTo(other_points[j - 1])) < 1e-7)
                {
                    count++;
                }
                else
                {
                    if (count >= 3)
                    {
                        // Found a segment of at least 3 points (4 or more total including p)
                        vector<Point> collinear_points;
                        collinear_points.push_back(p);
                        for(size_t k = j - count; k < j; ++k)
                        {
                            collinear_points.push_back(other_points[k]);
                        }
                        std::sort(collinear_points.begin(), collinear_points.end());
                        
                        // Check if p is the first point in the canonical representation
                        if (p == collinear_points.front()) {
                            line_segments.push_back(LineSegment(collinear_points.front(), collinear_points.back()));
                        }
                    }
                    count = 1;
                }
            }
            // Check for a segment at the end of the loop
            if (count >= 3)
            {
                vector<Point> collinear_points;
                collinear_points.push_back(p);
                for(size_t k = other_points.size() - count; k < other_points.size(); ++k)
                {
                    collinear_points.push_back(other_points[k]);
                }
                std::sort(collinear_points.begin(), collinear_points.end());
                
                // Check if p is the first point in the canonical representation
                if (p == collinear_points.front()) {
                    line_segments.push_back(LineSegment(collinear_points.front(), collinear_points.back()));
                }
            }
        }
        remove_duplicates();
    }
};

int main()
{
    init_canvas();

    // The points given in the example are not collinear
    // The corrected code finds a collinear segment from this list
    /*test 1*/
    // std::vector<Point> points;
    // points.push_back(Point(10000,0));
    // points.push_back(Point( 0,10000));
    // points.push_back(Point(3000,7000));
    // points.push_back(Point(7000,3000));
    // points.push_back(Point(20000,21000));
    // points.push_back(Point(3000,4000));
    // points.push_back(Point(14000,15000));
    // points.push_back(Point(6000,7000));

    /*test 2*/
    std::vector<Point> points;
    points.push_back(Point(19000,10000 ));
    points.push_back(Point( 18000 ,10000));
    points.push_back(Point(32000,10000));
    points.push_back(Point(21000,10000));
    points.push_back(Point(1234,5678 ));
    points.push_back(Point(14000,10000));

    cout << "Brute collinear points!\n";
    BruteCollinearPoints bcp(points);

    vector<LineSegment> line_segments = bcp.segments();

    cout << "Number of line segments: " << bcp.numberLineSegments() << endl;

    for (const auto& ls : line_segments)
    {
        cout << ls.toString() << endl;
    }

    std::cout << "Fast collinear points!\n";

    FastCollinearPoints fcp(points);
    vector<LineSegment> f_line_segments = fcp.segments();
    cout << "Number of line segments: " << fcp.numberLineSegments() << endl;

    for (const auto& ls : f_line_segments)
    {
        cout << ls.toString() << endl;
    } 

    // Cleanup Cairo resources
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}
