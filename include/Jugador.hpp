#pragma once
#include<iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

#include <Enemigo.hpp>
#include <EstadoJuego.hpp>
#include <Interfaz.hpp>
#include <Logica.hpp>

const int N = 10;
const int M = 10;
const int size = 82;
const int w = 1000;
const int h = 1000;
const float enemySpeed = 0.5f;
const float respawnTime = 3.0f;

class Jugador 
{
private:
    int x, y;
    std::vector<std::vector<bool>> visited;

public:
    Jugador(){}
    ~Jugador(){}
    Jugador() : x(1), y(1), visited(N, std::vector<bool>(M, false)) {
        visited[0][0] = true;
    }

    int getX() const { return x; }
    int getY() const { return y; }

    void move(int dx, int dy) {
        int newX = x + dx;
        int newY = y + dy;

        if (newX >= 0 && newX < N + 2 && newY >= 0 && newY < M + 2) {
            x = newX;
            y = newY;

            if (newX > 0 && newX <= N && newY > 0 && newY <= M) {
                visited[newX - 1][newY - 1] = true;
            }
        }
    }

    bool isVisited(int gridX, int gridY) const {
        return visited[gridX][gridY];
    }

    void reset() {
        x = y = 1;
        visited = std::vector<std::vector<bool>>(N, std::vector<bool>(M, false));
        visited[0][0] = true;
    }

    bool hasVisitedAll() const {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (!visited[i][j])
                    return false;
        return true;
    }
};