// Graphics by Lanea Zimmerman
// https://opengameart.org/content/tiny-16-basic
// Licensed under CC-BY 3.0, https://creativecommons.org/licenses/by/3.0/

#include "Pokitto.h"
#include "Tilemap.hpp"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


namespace Data {
    
    // map, 16x16
    
    const unsigned char mapPixels[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x22, 0x21, 0x11, 0x00, 0x00, 0x11, 0x13, 0x22,
    0x22, 0x31, 0x31, 0x10, 0x00, 0x11, 0x11, 0x32,
    0x23, 0x33, 0x11, 0x11, 0x00, 0x11, 0x13, 0x22,
    0x22, 0x21, 0x11, 0x11, 0x10, 0x01, 0x12, 0x22,
    0x22, 0x31, 0x13, 0x11, 0x11, 0x01, 0x12, 0x22,
    0x22, 0x21, 0x32, 0x31, 0x11, 0x01, 0x13, 0x33,
    0x22, 0x31, 0x13, 0x11, 0x11, 0x01, 0x13, 0x23,
    0x23, 0x31, 0x11, 0x11, 0x10, 0x11, 0x12, 0x22,
    0x32, 0x33, 0x11, 0x11, 0x11, 0x11, 0x13, 0x23,
    0x22, 0x23, 0x11, 0x33, 0x11, 0x11, 0x11, 0x13,
    0x22, 0x23, 0x31, 0x11, 0x11, 0x13, 0x32, 0x23,
    0x32, 0x32, 0x22, 0x33, 0x22, 0x33, 0x22, 0x22,
    0x33, 0x22, 0x22, 0x32, 0x22, 0x23, 0x22, 0x22,
    };
    
    
    const unsigned char green16Pixels[] = {
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    };
        
    Tilemap::Tile green16 = { green16Pixels, 16, 16 };
    
    
    const unsigned char tree16Pixels[] = {
    0xbb, 0xbb, 0xb4, 0x44, 0x44, 0x4b, 0xbb, 0xbb,
    0xbb, 0xb4, 0x44, 0x4b, 0x4b, 0x44, 0x4b, 0xbb,
    0xbb, 0x44, 0x4b, 0xbb, 0xbb, 0xb4, 0x44, 0xbb,
    0xbb, 0x11, 0x44, 0xbb, 0xbb, 0x44, 0x41, 0xbb,
    0xb1, 0x14, 0x4b, 0x4b, 0xb4, 0xb4, 0x44, 0x1b,
    0xb1, 0x41, 0x44, 0x4b, 0x44, 0x44, 0x11, 0x1b,
    0xb1, 0x14, 0x41, 0x44, 0x44, 0x14, 0x41, 0x1b,
    0xb4, 0x11, 0x14, 0x41, 0x44, 0x41, 0x41, 0x4b,
    0xb1, 0x44, 0x14, 0x11, 0x41, 0x11, 0x11, 0x1b,
    0xbb, 0x11, 0x11, 0x41, 0x11, 0x41, 0x41, 0xbb,
    0xbb, 0xb1, 0x11, 0x41, 0x11, 0x14, 0x1b, 0xbb,
    0xbb, 0xb7, 0x77, 0x11, 0x51, 0x77, 0x77, 0xbb,
    0xbb, 0x77, 0x77, 0x15, 0x51, 0x77, 0x77, 0x7b,
    0xbb, 0x77, 0x71, 0x55, 0x51, 0x17, 0x77, 0x7b,
    0xbb, 0xb7, 0x77, 0x51, 0x55, 0x77, 0x77, 0xbb,
    0xbb, 0xbb, 0x77, 0x77, 0x77, 0x77, 0xbb, 0xbb,
    };
        
    Tilemap::Tile tree16 = { tree16Pixels, 16, 16 };
    
    
    const unsigned char grass16Pixels[] = {
    0xbb, 0xb4, 0xbb, 0xb4, 0x4b, 0xbb, 0xbb, 0xbb,
    0x4b, 0xb4, 0xbb, 0xbb, 0xbb, 0x4b, 0xbb, 0xbb,
    0xb4, 0xb4, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0x4b, 0xbb, 0xb4, 0xb4,
    0xbb, 0x4b, 0xbb, 0xbb, 0x4b, 0x4b, 0xb4, 0xbb,
    0x4b, 0x4b, 0xb4, 0xbb, 0x44, 0x4b, 0xbb, 0xbb,
    0xb4, 0x44, 0x4b, 0xbb, 0x44, 0xbb, 0xbb, 0xbb,
    0xb4, 0x4b, 0x4b, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb4, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb4, 0xb4, 0xbb,
    0xbb, 0xb4, 0xbb, 0xbb, 0xb4, 0xb4, 0x4b, 0xbb,
    0xbb, 0xb4, 0xb4, 0x4b, 0xbb, 0x44, 0x4b, 0xbb,
    0xbb, 0xb4, 0x44, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0x4b, 0xb4, 0xbb, 0xb4, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xb4, 0xb4, 0xb4, 0xbb, 0xbb,
    };
    
    Tilemap::Tile grass16 = { grass16Pixels, 16, 16 };
    
    
    const unsigned char water16Pixels[] = {
    0x8c, 0x88, 0x88, 0x8c, 0x88, 0x8c, 0x88, 0x88,
    0xff, 0xc8, 0x88, 0x88, 0x88, 0x88, 0xc8, 0x8c,
    0x88, 0x88, 0xcc, 0x88, 0x88, 0x88, 0x8c, 0xc8,
    0x88, 0x88, 0x8f, 0x88, 0x88, 0x88, 0x8c, 0x88,
    0x88, 0x88, 0x8f, 0x88, 0x88, 0x88, 0xc8, 0x88,
    0x88, 0x8c, 0xcc, 0xc8, 0x88, 0x8c, 0xf8, 0x88,
    0x88, 0xf8, 0x88, 0x88, 0xcc, 0x88, 0xc8, 0x88,
    0x8c, 0xc8, 0x88, 0x88, 0xc8, 0x88, 0x8c, 0x88,
    0x88, 0x8c, 0x88, 0x88, 0x88, 0x88, 0x88, 0xcc,
    0x88, 0x88, 0xc8, 0x8c, 0x88, 0x88, 0x88, 0xf8,
    0x88, 0x88, 0xcc, 0xc8, 0x88, 0x88, 0x88, 0xc8,
    0xc8, 0x88, 0x88, 0xc8, 0x88, 0x88, 0x88, 0x8c,
    0x8c, 0xc8, 0x88, 0x88, 0xc8, 0x88, 0xc8, 0x88,
    0x8c, 0x88, 0x88, 0x88, 0x8c, 0xff, 0x88, 0x88,
    0x88, 0x88, 0x88, 0x88, 0x88, 0xc8, 0x88, 0x88,
    0x8c, 0x88, 0x88, 0x88, 0xfc, 0xcc, 0x88, 0x88,
    };
    
    Tilemap::Tile water16 = { water16Pixels, 16, 16 };
    

    const unsigned char girl12x15Pixels[] = {
    0x00, 0x01, 0x11, 0x11, 0x10, 0x00,
    0x00, 0x15, 0x99, 0x99, 0x51, 0x00,
    0x01, 0x59, 0x59, 0xe1, 0x55, 0x10,
    0x01, 0xe5, 0xee, 0x11, 0x95, 0x10,
    0x19, 0x59, 0x11, 0x19, 0x19, 0x51,
    0x15, 0x51, 0x1e, 0xe1, 0x91, 0x51,
    0x15, 0x1e, 0x1f, 0xf1, 0xe1, 0x51,
    0x15, 0x15, 0xdd, 0xdd, 0x51, 0x51,
    0x11, 0x18, 0x59, 0x95, 0x81, 0x11,
    0x01, 0x82, 0xf8, 0x8f, 0x28, 0x10,
    0x01, 0xd1, 0x2f, 0xf2, 0x1d, 0x10,
    0x00, 0x12, 0x8f, 0xf8, 0x21, 0x00,
    0x00, 0x18, 0x8c, 0xc8, 0x81, 0x00,
    0x07, 0x11, 0xcc, 0xcc, 0x11, 0x70,
    0x07, 0x77, 0x11, 0x11, 0x77, 0x70,
    };
    
    
    Tilemap::Tile girl12x15 = { girl12x15Pixels, 12, 156 };

};