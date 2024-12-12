#include <transform.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

Transform transform = Transform(5);

void Transform::set_unit_length(int length) {
    unit_length = length;
}

void Transform::update_origin() {
    getviewport(&left, &top, &right, &bottom);
    origin.setX(left + (right - left) / 2);
    origin.setY(bottom + (top - bottom) / 2);
}

void Transform::set_origin(Point p) {
    origin = p;
}

void Transform::draw_line(Point p1, Point p2, double dl) {
    Point p1t = transform(p1);
    Point p2t = transform(p2);
    std::cout << "Drawing line from " << p1 << " to " << p2 << std::endl;
    Point cur = p1t;
    Vector2D d = (p2t - p1t).normalize() * dl;
    while (cur.distance(p2t) > d.length()) {
        line(cur.getX(), cur.getY(), cur.getX() + d.getX(), cur.getY() + d.getY());
        cur = cur + d;
        delay_fps(1000);
    }
    line(p1t.getX(), p1t.getY(), p2t.getX(), p2t.getY());
}

void Transform::draw_arc(Point center, double radius, double start_angle, double end_angle, double dtheta) {
    Point center_t = transform(center);
    double theta = start_angle;
    // 转换角度为弧度单位
    double rad_unit = M_PI / 180.0;

    // 初始点
    double x1 = center_t.getX() + radius * unit_length * std::cos(theta * rad_unit);
    double y1 = center_t.getY() + radius * unit_length * std::sin(theta * rad_unit);
    while (theta < end_angle) {
        theta += dtheta;

        // 计算下一点的坐标
        double x2 = center_t.getX() + radius * unit_length * std::cos(theta * rad_unit);
        double y2 = center_t.getY() + radius * unit_length * std::sin(theta * rad_unit);

        // 使用 line 画出从 (x1, y1) 到 (x2, y2) 的直线
        line(static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x2), static_cast<int>(y2));
        // 输出调试信息
        std::cout << "line: (" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")" << std::endl;
        // 延迟，模拟绘制效果
        delay_fps(1000);
        // 更新起始点
        x1 = x2;
        y1 = y2;
    }
}

void Transform::draw_circle(Point center, double radius, double dtheta){
    Point center_t = transform(center);
    double theta = 0;
    // while (theta < 360) {
    //     arcf(center_t.getX(), center_t.getY(), theta, theta + dtheta, radius*unit_length);
    //     theta += dtheta;
    //     std::cout << "arcf: center=(" << center_t.getX() << "," << center_t.getY() 
    //       << "), start=" << theta 
    //       << ", end=" << theta + dtheta 
    //       << ", radius=" << radius * unit_length << std::endl;
    //     delay_fps(1000);
    //     // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // }

    // 转换角度为弧度单位
    double rad_unit = M_PI / 180.0;

    // 初始点
    double x1 = center_t.getX() + radius * unit_length * std::cos(theta * rad_unit);
    double y1 = center_t.getY() + radius * unit_length * std::sin(theta * rad_unit);
    while (theta < 360) {
        theta += dtheta;

        // 计算下一点的坐标
        double x2 = center_t.getX() + radius * unit_length * std::cos(theta * rad_unit);
        double y2 = center_t.getY() + radius * unit_length * std::sin(theta * rad_unit);

        // 使用 line 画出从 (x1, y1) 到 (x2, y2) 的直线
        line(static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x2), static_cast<int>(y2));
        // 输出调试信息
        std::cout << "line: (" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")" << std::endl;
        // 延迟，模拟绘制效果
        delay_fps(1000);
        // 更新起始点
        x1 = x2;
        y1 = y2;
    }

    // 最后连接回起点，闭合圆
    double x_start = center_t.getX() + radius * unit_length * std::cos(0);
    double y_start = center_t.getY() + radius * unit_length * std::sin(0);
    line(static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x_start), static_cast<int>(y_start));

    circle(center_t.getX(), center_t.getY(), radius*unit_length);
}

Point Transform::transform(Point p){
    double x = origin.getX() + p.getX() * unit_length;
    double y = origin.getY() - p.getY() * unit_length;
    return Point(x, y);
}