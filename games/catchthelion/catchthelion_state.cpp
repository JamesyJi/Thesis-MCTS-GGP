#include <iostream>
#include <memory>

#include "catchthelion_state.h"

namespace CatchTheLion
{

Common::Result CatchTheLion::EvaluateState(const CTLMove &lastMove)
{
    if (lastMove.player == Common::Player::NONE)
    {
        return Common::Result::ONGOING;
    }

    // If there's a drop, the game cannot be anything but ongoing
    if (lastMove.moveType == MoveType::DROP)
    {
        return Common::Result::ONGOING;
    }

    // Capturing the lion wins the game
    if (lastMove.capturedPiece == CTLPieceType::LION)
    {
        return PlayerToResult(lastMove.player);
    }

    // Lion to back rank (not in check) wins the game
    if (lastMove.piece == CTLPieceType::LION)
    {
        switch (lastMove.player)
        {
            case Common::Player::PLAYER1:
                if (lastMove.row == 3) return Common::Result::PLAYER1_WIN;
                break;
            case Common::Player::PLAYER2:
                if (lastMove.row == 0) return Common::Result::PLAYER2_WIN;
                break;
        }
    }

    // TODO: Determine if draw

    return Common::Result::ONGOING;  
};

