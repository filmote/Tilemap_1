// Copyright (C) 2019 Hannu Viitala
// 
// The source code in this file is released under the MIT license.
// Go to http://opensource.org/licenses/MIT for the full license details.
// 
// Converted to C++ by Filmote

// *** A TILEMAP DEMO FOR THE POKITTO ***

#include "Pokitto.h"
#include "Tilemap.hpp"
#include "Data.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;

const uint16_t worldWidth = 16 * 16;        // 16 tiles of 16 pixels
const uint16_t worldHeight = 16 * 16;        // 16 tiles of 16 pixels

enum TileType {
    
	Water = 0,
	Green = 1,
	Tree = 2,
	Grass = 3,
	
}; 

Tilemap tilemap;

int16_t x = 48;
int16_t y = 48;


void calculateViewPortPosition(int16_t &xViewPort, int16_t &yViewPort) {
    
    if (x < PD::width / 2) {
        
        xViewPort = 0;
        
    }
    else if (x > worldWidth - PD::width / 2) {

        xViewPort = PD::width - worldWidth;
        
    }
    else {
        
        xViewPort = PD::width / 2 - x;

    }
    
    if (y < PD::height / 2) {
        
        yViewPort = 0;
        
    }
    else if (y > worldHeight - PD::height / 2) {

        yViewPort = PD::height - worldHeight;
        
    }
    else {
        
        yViewPort = PD::height / 2 - y;

    }
    
}



void calculatePlayerPosition(int16_t &xPlayer, int16_t &yPlayer) {
    
    if (x < PD::width / 2) {
        
        xPlayer = x;
        
    }
    else if (x > worldWidth - PD::width / 2) {

        xPlayer = x - (worldWidth - PD::width);
        
    }
    else {
        
        xPlayer = PD::width / 2;

    }
    
    if (y < PD::height / 2) {
        
        yPlayer = y;
        
    }
    else if (y > worldHeight - PD::height / 2) {

        yPlayer = y - (worldHeight - PD::height);
        
    }
    else {
        
        yPlayer = PD::height / 2;

    }

}


int main(){

    PC::begin();
    PD::loadRGBPalette(palettePico);   
    PD::persistence = true;
    PD::invisiblecolor = 12;


    // Initialise the map ..
    
    tilemap.set(16, 16, Data::mapPixels);
    tilemap.setTile(TileType::Green, 16, 16, Data::green16);
    tilemap.setTile(TileType::Tree, 16, 16, Data::tree16);
    tilemap.setTile(TileType::Grass, 16, 16, Data::grass16);
    tilemap.setTile(TileType::Water, 16, 16, Data::water16);

    int16_t heroOnScreenX = PD::width / 2; 
    int16_t heroOnScreenY = PD::height / 2;

    
    while (PC::isRunning()) {
        
        if (!PC::update()) continue;

        PC::buttons.pollButtons();        

        int16_t oldX = x;
        int16_t oldY = y;

        if (PC::buttons.pressed(BTN_LEFT)  || PC::buttons.repeat(BTN_LEFT, 1))    { x = x - 1; }
        if (PC::buttons.pressed(BTN_RIGHT) || PC::buttons.repeat(BTN_RIGHT, 1))   { x = x + 1; }
        if (PC::buttons.pressed(BTN_UP)    || PC::buttons.repeat(BTN_UP, 1))      { y = y - 1; }
        if (PC::buttons.pressed(BTN_DOWN)  || PC::buttons.repeat(BTN_DOWN, 1))    { y = y + 1; }


        // Check the map tile under the girl.
        
        uint8_t tileId = tilemap.GetTileId(x + 6, y + 7, 16);


        // If the tile is not grass, do not move.
        
        if (tileId != TileType::Green) {
            x = oldX;
            y = oldY;
        }

        
        // Check for out of bounds.
        
        if (x < 0)                          x = 0;
        if (x > worldWidth - 12)            x = worldWidth;
        if (y < 0)                          y = 0;
        if (y > worldHeight - 15)           y = worldHeight;
        
        
        int16_t xViewPort;
        int16_t yViewPort;
        
        calculateViewPortPosition(xViewPort, yViewPort);
        tilemap.draw(xViewPort, yViewPort);

        int16_t xPlayer;
        int16_t yPlayer;
        
        calculatePlayerPosition(xPlayer, yPlayer);
        PD::drawBitmapData(xPlayer, yPlayer, 12, 15, Data::girl12x15Pixels);
        
    }
    
    return 0;
    
}

