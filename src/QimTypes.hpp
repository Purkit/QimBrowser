#ifndef QIMTYPES_HPP
#define QIMTYPES_HPP

namespace Qim {

struct Point {
    int x, y;
};

struct Size {
    int width;
    int height;
};

struct Frame {
    Point absolute_position;
    Size absolute_size;
};

struct RelativeSize {
    float width;
    float height;
};

} // namespace Qim

#endif // QIMTYPES_HPP
