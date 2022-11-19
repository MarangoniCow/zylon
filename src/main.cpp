/*                       ZYLO                           
 A small chess program developed on C++ using SDL2.
 */


// EXTERNAL DEPENDENCIES                                
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>


// INTERNAL DEPENDENCIES
#include "SDL_EventManager.h"
#include "SDL_Board.h"
#include "GameplayManager.h"



// TEMP
#include "Piece.h"






int main () {

    std::cout << "Welcome to Zylo!" << std::endl;

    // Initalise board and board logic
    Board board;
    // Initialise gameplay manager
    GameplayManager manager(&board);
    manager.newGame();

    // Initialise a game window and render the current state
    SDL_Board gameWindow;
    gameWindow.renderBoard(board.getState());

    // Gamne boolean
    
    

    SDL_EventManager zylo(&gameWindow, &manager);
    zylo.RunGame();
    



    return 0;
}