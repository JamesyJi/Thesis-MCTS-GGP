#pragma once

#define P0 Common::Player::PLAYER0
#define P1 Common::Player::PLAYER1
#define P2 Common::Player::PLAYER2
#define P1_WIN Common::Result::PLAYER1_WIN
#define P2_WIN Common::Result::PLAYER2_WIN
#define DRAW Common::Result::DRAW
#define ONGOING Common::Result::ONGOING

#define X Common::Piece(Common::Player::PLAYER1)
#define O Common::Piece(Common::Player::PLAYER2)
#define A Common::Piece()

#define C_X Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::CHICK)
#define C_O Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::CHICK)
#define E_X Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::ELEPHANT)
#define E_O Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::ELEPHANT)
#define G_X Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::GIRAFFE)
#define G_O Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::GIRAFFE)
#define L_X Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::LION)
#define L_O Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::LION)
#define H_X Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::HEN)
#define H_O Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::HEN)
#define N_A Common::CatchTheLionPiece()
