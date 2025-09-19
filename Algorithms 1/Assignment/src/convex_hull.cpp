/*
Given a set of 2D points on a plane, find a convex hull i.e smallest polygon enclosing
the points
Graham's scan algorithm
*/

#include <algorithm>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;

const float eps = 1e-8;


struct Point
{
    float x;
    float y;
};
Point g_lowest_point;
bool is_ccw(Point prev_point, Point cur_point, Point next_point)
{
    float area = (cur_point.x-prev_point.x)*(next_point.y-prev_point.y) - (cur_point.y-prev_point.y)*(next_point.x-prev_point.x);
    if (area > eps)
        return true;
    return false;
}

bool compare_y(const Point& a, const Point& b)
{
    if (fabs(a.y - b.y) > eps)
        return a.y < b.y;
    return a.x < b.x;
}

bool compare_polar_angle(const Point& a, const Point& b)
{
    float ang_a = atan2(a.y - g_lowest_point.y, a.x - g_lowest_point.x + eps);
    float ang_b = atan2(b.y - g_lowest_point.y, b.x - g_lowest_point.x + eps);

    if (fabs(ang_a - ang_b) > eps)
        return ang_a < ang_b;
    
    float dist_a = (a.x - g_lowest_point.x) * (a.x - g_lowest_point.x) + ((a.y - g_lowest_point.y) * (a.y - g_lowest_point.y));
    float dist_b = (b.x - g_lowest_point.x) * (b.x - g_lowest_point.x) + ((b.y - g_lowest_point.y) * (b.y - g_lowest_point.y));

    return dist_a < dist_b;
}


std::vector<Point> convex_hull(vector<Point>& points)
{
    if (points.size() < 3)
    {
        return {};
    }
    std::stack<Point> q;
    std::sort(points.begin(), points.end(), compare_y);
    g_lowest_point = points[0];
    std::sort(points.begin() + 1, points.end(), compare_polar_angle);

    q.push(points[0]);
    q.push(points[1]);
    for (int i=2;i < points.size();i++)
    {
        Point top = q.top();
        q.pop();
        while (q.size() > 0 && !is_ccw(q.top(), top, points[i]))
        {
            top = q.top();
            q.pop();
        }
        q.push(top);
        q.push(points[i]);
    }

    vector<Point> hull;

    while(q.size()!=0)
    {
        hull.push_back(q.top());
        q.pop();
    }
    std::reverse(hull.begin(), hull.end());
    return hull;
}

void print_points(const std::vector<Point>& points) {
    for (const auto& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ")" << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test Case 1: Simple set of points forming a convex hull
    cout << "Test Case 1:" << endl;
    vector<Point> p1 = {
        {-2, -2}, {0, 3}, {2, 0}, {0, -1}, {-1, 1}
    };
    vector<Point> hull1 = convex_hull(p1);
    cout << "Input Points: ";
    print_points(p1);
    cout << "Convex Hull Points: ";
    print_points(hull1);
    cout << "Expected: (-2, -2) (2, 0) (0, 3)" << endl;
    
    // Test Case 2: Points with a collinear segment
    cout << "\nTest Case 2:" << endl;
    vector<Point> p2 = {
        {0, 0}, {1, 1}, {2, 2}, {3, 0}, {1.5, 3}
    };
    vector<Point> hull2 = convex_hull(p2);
    cout << "Input Points: ";
    print_points(p2);
    cout << "Convex Hull Points: ";
    print_points(hull2);
    cout << "Expected: (0, 0) (3, 0) (1.5, 3)" << endl;
    
    // Test Case 3: Points in a circle
    cout << "\nTest Case 3:" << endl;
    vector<Point> p3 = {};
    for (int i = 0; i < 10; ++i) {
        p3.push_back({static_cast<float>(cos(i * M_PI / 5)), static_cast<float>(sin(i * M_PI / 5))});
    }
    vector<Point> hull3 = convex_hull(p3);
    cout << "Input Points: ";
    print_points(p3);
    cout << "Convex Hull Points: All 10 points should be on the hull." << endl;
    print_points(hull3);
    
    // Test Case 4: No convex hull possible (fewer than 3 points)
    cout << "\nTest Case 4:" << endl;
    vector<Point> p4 = {{0, 0}, {1, 1}};
    vector<Point> hull4 = convex_hull(p4);
    cout << "Input Points: ";
    print_points(p4);
    cout << "Convex Hull Points: ";
    print_points(hull4);
    cout << "Expected: Empty set" << endl;
    
    return 0;
}
