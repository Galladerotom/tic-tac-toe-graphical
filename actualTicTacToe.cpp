#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;
#define Empty 0
#define X 1
#define O -1

using namespace std;
using namespace sf;

void printOutput(int board[3][3], int row, int col, bool turn, bool validMove, bool gameOver, int winCode) 
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
    }
    
    cout << row << " " << col << " " << validMove << " " << gameOver << " " << winCode << endl;
}
void newGame(int board[3][3], bool& turn, bool& validMove, bool& gameOver, int& winCode, bool &playSound)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
    turn = true;
    validMove = false;
    gameOver = false;
    winCode = 0;
    playSound = false;
    cout << "New Game\n";
}

void playMove(int board[3][3], // The board 2-d array
    int row, // Board row where mouse is clicked
    int col, // Board column where mouse is clicked
    bool& turn, // Whose turn is it?
    bool& validMove, // Is the move valid?
    bool& gameOver, // Is the game over?
    int& winCode // A code of winning sequence
    )
{
    if (board[row][col] != Empty) {
        validMove = false;
        printOutput(board, row, col, turn, validMove, gameOver, winCode);
        cout << "Invalid Move" << endl;
        return;
    }
    else
    {
        if (turn) {
            board[row][col] = X;
        }
        else
        {
            board[row][col] = O;
        }
        validMove = true;
        //check for gameover
        if ((board[0][0] == X && board[0][1] == X && board[0][2] == X) || board[0][0] == O && board[0][1] == O && board[0][2] == O) {
            gameOver = true;
            winCode = 1;
            printOutput(board, row, col, turn, validMove, gameOver, winCode);
            turn = !turn;
            return;
        }
        else if ((board[1][0] == X && board[1][1] == X && board[1][2] == X) || board[1][0] == O && board[1][1] == O && board[1][2] == O) {
            gameOver = true;
            winCode = 2;
            printOutput(board, row, col, turn, validMove, gameOver, winCode);
            turn = !turn;
            return;
        }
        else if ((board[2][0] == X && board[2][1] == X && board[2][2] == X) || board[2][0] == O && board[2][1] == O && board[2][2] == O) {
            gameOver = true;
            winCode = 3;
            printOutput(board, row, col, turn, validMove, gameOver, winCode);
            turn = !turn;
            return;
        }
        else if ((board[0][0] == X && board[1][0] == X && board[2][0] == X) || board[0][0] == O && board[1][0] == O && board[2][0] == O) {
            gameOver = true;
            winCode = 4;
            printOutput(board, row, col, turn, validMove, gameOver, winCode);
            turn = !turn;
            return;
        }
        else if ((board[0][1] == X && board[1][1] == X && board[2][1] == X) || board[0][1] == O && board[1][1] == O && board[2][1] == O) {
            gameOver = true;
            winCode = 5;
            printOutput(board, row, col, turn, validMove, gameOver, winCode);
            turn = !turn;
            return;
        }
        else if ((board[0][2] == X && board[1][2] == X && board[2][2] == X) || board[0][2] == O && board[1][2] == O && board[2][2] == O) {
            gameOver = true;
            winCode = 6;
            printOutput(board, row, col, turn, validMove, gameOver, winCode);
            turn = !turn;
            return;
        }
        else if ((board[0][0] == X && board[1][1] == X && board[2][2] == X) || board[0][0] == O && board[1][1] == O && board[2][2] == O) {
            gameOver = true;
            winCode = 7;
            printOutput(board, row, col, turn, validMove, gameOver, winCode);
            turn = !turn;
            return;
        }
        else if ((board[0][2] == X && board[1][1] == X && board[2][0] == X) || board[0][2] == O && board[1][1] == O && board[2][0] == O) {
            gameOver = true;
            winCode = 8;
            printOutput(board, row, col, turn, validMove, gameOver, winCode);
            turn = !turn;
            return;
        }
        gameOver = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0)
                    gameOver = false;
            }
        }
        printOutput(board, row, col, turn, validMove, gameOver, winCode);
        turn = !turn;
    }
}

/*
win code
0 No win
1 Row 0 of the grid, cell (0,0) to cell (0,2)
2 Row 1 of the grid, cell (1,0) to cell (1,2)
3 Row 2 of the grid, cell (2,0) to cell (2,2)
4 Column 0 of the grid, cell (0,0) to cell (2,0)
5 Column 1 of the grid, cell (0,1) to cell (2,1)
6 Column 2 of the grid, cell (0,2) to cell (2,2)
7 Left to right diagonal, cell (0,0) to cell (2,2)
8 Right to left diagonal, cell (2,0) to cell (0,2)
*/

int main()
{
    /************************************************************************************************************/
    /* The following variables define the state of the game                                                     */
    /************************************************************************************************************/

    // You should complete the following declarations
    // Make sure to initalize the variables

    // The game board array
    int gameBoard[3][3] = { Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty };

    
    // An boolean that represents the turn in the game
    bool turn = true;
    // A boolean to represent if the move is valid
    bool validMove = false;
    // A boolean to represent if the game is over
    bool gameOver = false;
    // An integer that represents the win code
    int wincode = 0;
    /************************************************************************************************************/
    /* Insert code that loads the various images used by the game and creates the sprites                       */
    /* The loading of the X image is shown. Repreat for the rest of the images                                  */
    /************************************************************************************************************/

    // Get the X image
    sf::Texture xTexture;
    if (!xTexture.loadFromFile("X.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite xSprite(xTexture);
    
    // Get the O image
    sf::Texture oTexture;
    if (!oTexture.loadFromFile("O.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite oSprite(oTexture);

    //get the blank image
    sf::Texture blankTexture;
    if (!blankTexture.loadFromFile("blank.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite blankSprite(blankTexture);
    /************************************************************************************************************/
    /* Insert code that creates the window and displays it                                                      */
    /************************************************************************************************************/

    // First, we find the sizes of the images so we can determine the size of the window we must create
    // The images (X, O and Black) are assumed to be square are are all of the same size
    // Thus, we just find the size of one of them

    // The tile size is the size of the images
    const int tileSize = xTexture.getSize().x;

    // The cell borders (thick lines) are rectangles
    // The size of these rectangles is 1/20th of the size of the tile by 3 cell sizes plus 2 barWidth's
    const int barWidth = tileSize / 20;
    const int barHeight = 3 * tileSize + (3 - 1) * barWidth;

    // The size of the window in pixels can now be calculated
    const int windowSize = 3 * tileSize + (3 - 1) * barWidth;

    // Create the main window: it has a title bar and a close button, but is not resizable
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Tic-Tac-Toe", sf::Style::Titlebar | sf::Style::Close);

    // Set the Icon that appears in the task bar when the window is minimized
    // Insert you code here, see the lab handout
    sf::Image icon;
    if (!icon.loadFromFile("icon.jpg")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Create the horizonal (vertical) borders as rectangles of sizes barWidth and barHeight (berHeight and barWidth)
    // Insert your code here
    //
    sf::RectangleShape borderRect(sf::Vector2f(barWidth, barHeight));
    sf::RectangleShape winningLine(sf::Vector2f(windowSize, 10));
    sf::RectangleShape winningDiag(sf::Vector2f(windowSize * 1.414, 10));
    borderRect.setFillColor(sf::Color(0, 0, 0));
    winningLine.setFillColor(sf::Color(255, 255, 255));
    winningDiag.setFillColor(sf::Color(255, 255, 255));

    int row=0, col=0;

    /************************************************************************************************************/
    /* This is the main event loop of the code                                                                  */
    /************************************************************************************************************/

    // Start the game loop that runs as long as the window is open
   
    //load sound
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("victory.wav"))
        return -1;
    
    sf::Sound victorySound;
    victorySound.setBuffer(buffer);
    
    bool playedSound = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
                window.close();
            if (Mouse::isButtonPressed(Mouse::Left)) {
                // left mouse button is pressed
                // Get the coordinates in pixels.
                sf::Vector2i localPosition = Mouse::getPosition(window);
                // The Vector2i is a type defined in SFML that defines a
                // two element integer vector (x,y). This is how the
                // elements of the vector are accessed
                int xPosition = localPosition.x;
                int yPosition = localPosition.y;
                // Important to keep in mind that the x axis is the
                // horizontal one (i.e., columns) while the y axis is
                // the vertical one (i.e., rows)
                //std::cout << xPosition << "\t" << yPosition << endl;
                //sprite.setPosition(xPosition, yPosition);
                double x = xPosition * 10.00 / 10.00;
                double y = yPosition * 10.00 / 10.00;
                if (x / tileSize > 0 && x / tileSize < 1) {
                    col = 0;

                    if (y / tileSize > 0 && y / tileSize < 1) {
                        row = 0;

                    }
                    else if (y / tileSize >= 1 && y / tileSize < 2) {
                        row = 1;
                    }
                    else {
                        row = 2;
                    }
                }
                else if (x / tileSize >= 1 && x / tileSize < 2) {
                    col = 1;

                    if (y / tileSize > 0 && y / tileSize < 1) {
                        row = 0;

                    }
                    else if (y / tileSize >= 1 && y / tileSize < 2) {
                        row = 1;
                    }
                    else {
                        row = 2;
                    }
                }
                else if (x / tileSize >= 2 && x / tileSize <= 3) {
                    col = 2;

                    if (y / tileSize > 0 && y / tileSize < 1) {
                        row = 0;

                    }
                    else if (y / tileSize >= 1 && y / tileSize < 2) {
                        row = 1;
                    }
                    else {
                        row = 2;
                    }
                }

                if(!gameOver)
                    playMove(gameBoard, row, col, turn, validMove, gameOver, wincode);

                
            }
            if (gameOver && event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                newGame(gameBoard, turn, validMove, gameOver, wincode, playedSound);
            }
        }
        // Insert code to draw the tiles using the sprites created earlier
       // You must determine the position of each cell on the grid, taking into account the width of
       // the border and then position the sprite there and draw it.
       // Draw the entire board, cell borders included,
       // reflecting any move that has just happened (check the gameBoard array)
       // Further, if the game is over and one player wins, you must create and draw a rectangle of
       // windowSize width and 10 pixels height to indicate the winning marks
       // The fill of this rectangle should be white

       // Insert your code here
       // draw board
        int xGrid = 0;
        int yGrid = 0;
        window.clear();
        for (int i = 0; i < 3; i++)
        {
            
            for (int j = 0; j < 3; j++)
            {
                if (gameBoard[i][j] == X) {
                    xSprite.setPosition(xGrid, yGrid);
                    window.draw(xSprite);
                }
                if (gameBoard[i][j] == O) {
                    oSprite.setPosition(xGrid, yGrid);
                    window.draw(oSprite);
                }
                if (gameBoard[i][j] == Empty) {
                    blankSprite.setPosition(xGrid, yGrid);
                    window.draw(blankSprite);
                }
                borderRect.setPosition(xGrid + tileSize, yGrid);
                xGrid += tileSize + barWidth;
                window.draw(borderRect);
            }
            yGrid += tileSize+barWidth;
            xGrid = 0;
        }
        // draw line for win
        switch (wincode) {
        case 1:
            winningLine.setPosition(0, tileSize / 2);
            window.draw(winningLine);
            break;
        case 2:
            winningLine.setPosition(0, windowSize / 2);
            window.draw(winningLine);
            break;
        case 3:
            winningLine.setPosition(0, tileSize * 5 / 2 + 2*barWidth);
            window.draw(winningLine);
            break;
        case 4:
            winningLine.setPosition(tileSize / 2, 0);
            winningLine.rotate(90);
            window.draw(winningLine);
            break;
        case 5:
            winningLine.setPosition(windowSize / 2, 0);
            winningLine.rotate(90);
            window.draw(winningLine);
            break;
        case 6:
            winningLine.setPosition(tileSize * 5 / 2 + 2 * barWidth, 0);
            winningLine.rotate(90);
            window.draw(winningLine);
            break;
        case 7:
            winningDiag.setPosition(0, 0);
            winningDiag.rotate(45);
            window.draw(winningDiag);
            break;
        case 8:
            winningDiag.setPosition(windowSize, 0);
            winningDiag.rotate(135);
            window.draw(winningDiag);
            break;
        }
        if (wincode && !playedSound) {
            victorySound.play();
            playedSound = true;
        }

        window.display();

        //rotate back the winning lines

        switch (wincode) {
        case 4:
            winningLine.rotate(-90);
            break;
        case 5: 
            winningLine.rotate(-90);
            break;
        case 6:
            winningLine.rotate(-90);
            break;
        case 7:
            winningDiag.rotate(-45);
            break;
        case 8:
            winningDiag.rotate(-135);
            break;
        }
    }

    return 0;
}