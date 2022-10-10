/***********************************************************
 *                      PIECE.H
 * 
 *  Class to handle all pieces and movement ranges
 *      - file path
 *      - colour
 *      - piece type
 *      - Global piece list & ID
 * 
 * 
 ***********************************************************/
#pragma once

// INTERNAL INCLUDES
#include "Coords.h"

// EXTERNAL INCLUDES
#include <string>
#include <vector>
#include <queue>

enum PIECE_COLOUR {
    WHITE = 0,
    BLACK = 1
};

enum PIECE_TYPE {
    PAWN = 0,
    ROOK = 1,
    KNIGHT = 2,
    BISHOP = 3,
    QUEEN = 4,
    KING = 5
};

struct PieceDescriptor {

    std::string filePath;
    PIECE_TYPE type;
};


class Piece 
{
    protected:
        // STATIC MEMBERS FOR GLOBAL FUNCTIONALITY
        static std::vector<Piece*> Piece_instanceList;          // Global ID list
        static int Piece_count;                        // Global piece count

        // CLASS SPECFIC FUNCTIONALITY
        const PieceDescriptor& descriptor;              // Sub-class specific descriptor

        // INSTANCE SPECIFIC FUNCTIONALITY
        int Piece_ID;                                   // Unique Piece ID
        const PIECE_COLOUR col;                         // Enumerated colour
        bool flag_move;                                  // Movement flag
        BoardPosition pos;                                     // Current position


        
    public:
        Piece(const PieceDescriptor& descriptor_, PIECE_COLOUR col_, int x, int y) : descriptor(descriptor_), col(col_), pos(x, y) {
            Piece_count += 1;
            Piece_ID = Piece_instanceList.size();
            Piece_instanceList.push_back(this); 
            flag_move = 0; 
        };                    
        virtual ~Piece() {
            Piece_count -= 1;
            Piece_instanceList[Piece_ID] = nullptr;
        }

        // STATIC METHODS FOR GLOBAL FUNCTIONALITY
        static int returnCount() {return Piece_count;};
        static std::vector<Piece*> returnInstanceList() {return Piece_instanceList;};

        // NON-STATIC RETURNS
        PieceDescriptor returnDescriptor() {return descriptor;};
        std::string returnPath(); 
        PIECE_COLOUR returnColour() {return col;};
        BoardPosition returnPosition() {return pos;};

        // FLAGS
        bool hasMoved() {return flag_move;};

        // SETTER METHODS
        void updatePosition(BoardPosition pos);
        
        // FUNCTIONALITY METHODS
        virtual std::queue<BoardPosition> moveRange() = 0; 


        
};



/***********************************************************
 *                   PIECE SUB-CLASSES
 ***********************************************************/

class Pawn : public Piece
{
    private:
        static PieceDescriptor pawn_description; 
    public:
        Pawn(PIECE_COLOUR col_, int x, int y) : Piece(pawn_description, col_, x, y) {};
        std::queue<BoardPosition> moveRange();
};

class Rook : public Piece
{
    private:
        static PieceDescriptor rook_description; 
    public:
        Rook(PIECE_COLOUR col_, int x, int y) : Piece(rook_description, col_, x, y){};
        std::queue<BoardPosition> moveRange();
};

class Knight : public Piece
{
    private:
        static PieceDescriptor knight_description; 
    public:
        Knight(PIECE_COLOUR col_, int x, int y) : Piece(knight_description, col_, x, y) {};
        std::queue<BoardPosition> moveRange();
};

class Bishop : public Piece
{
    private:
        static PieceDescriptor bishop_description; 
    public:
        Bishop(PIECE_COLOUR col_, int x, int y) : Piece(bishop_description, col_, x, y) {};
        std::queue<BoardPosition> moveRange();
};

class Queen : public Piece
{
    private:
        static PieceDescriptor queen_description; 
    public:
        Queen(PIECE_COLOUR col_, int x, int y) : Piece(queen_description, col_, x, y) {};
        std::queue<BoardPosition> moveRange();
};

class King : public Piece
{
    private:
        static PieceDescriptor king_description; 
    public:
        King(PIECE_COLOUR col_, int x, int y) : Piece(king_description, col_, x, y) {};
        std::queue<BoardPosition> moveRange();
};
