#pragma once

#include <cstdint>

namespace kernel::drivers {

class VGADisplay {
public:
    VGADisplay();
    
    void clear();
    void print_char(char c, uint8_t color);
    void print_string(const char* str, uint8_t color);
    
    void set_cursor_position(uint8_t x, uint8_t y);
    
private:
    static constexpr uint16_t WIDTH = 80;
    static constexpr uint16_t HEIGHT = 25;
    
    uint16_t* m_buffer = reinterpret_cast<uint16_t*>(0xB8000);
    uint8_t m_cursor_x = 0;
    uint8_t m_cursor_y = 0;
};

} // namespace kernel::drivers
