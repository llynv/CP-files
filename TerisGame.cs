using System;
using System.Drawing;
using System.Windows.Forms;
using System.Timers;

public class TetrisGame : Form
{
    private const int GridWidth = 10;
    private const int GridHeight = 20;
    private const int BlockSize = 30;
    private const int TimerInterval = 500;

    private int[,] grid = new int[GridHeight, GridWidth];
    private Timer gameTimer;
    private Point currentBlockPosition;
    private int[,] currentBlock;
    private Random random = new Random();
    private int score = 0;
    private Label scoreLabel;
    private Label gameOverLabel;
    private Button startButton;
    private Button restartButton;

    public TetrisGame()
    {
        this.Text = "Tetris Game";
        this.ClientSize = new Size(GridWidth * BlockSize + 100, GridHeight * BlockSize);
        this.DoubleBuffered = true;

        scoreLabel = new Label
        {
            Text = "Score: 0",
            Location = new Point(GridWidth * BlockSize + 10, 10),
            AutoSize = true
        };
        this.Controls.Add(scoreLabel);

        gameOverLabel = new Label
        {
            Text = "Game Over",
            Location = new Point(GridWidth * BlockSize / 2 - 40, GridHeight * BlockSize / 2),
            AutoSize = true,
            ForeColor = Color.Red,
            Visible = false
        };
        this.Controls.Add(gameOverLabel);

        startButton = new Button
        {
            Text = "Start",
            Location = new Point(GridWidth * BlockSize + 10, 40),
            Size = new Size(80, 30)
        };
        startButton.Click += StartButton_Click;
        this.Controls.Add(startButton);

        restartButton = new Button
        {
            Text = "Restart",
            Location = new Point(GridWidth * BlockSize + 10, 80),
            Size = new Size(80, 30),
            Enabled = false
        };
        restartButton.Click += RestartButton_Click;
        this.Controls.Add(restartButton);

        gameTimer = new Timer();
        gameTimer.Interval = TimerInterval;
        gameTimer.Elapsed += OnGameTick;

        this.Paint += OnPaint;
        this.KeyDown += OnKeyDown;
    }

    private void StartButton_Click(object sender, EventArgs e)
    {
        StartGame();
    }

    private void RestartButton_Click(object sender, EventArgs e)
    {
        RestartGame();
    }

    private void StartGame()
    {
        startButton.Enabled = false;
        restartButton.Enabled = true;
        gameOverLabel.Visible = false;
        Array.Clear(grid, 0, grid.Length);
        score = 0;
        scoreLabel.Text = "Score: 0";
        SpawnBlock();
        gameTimer.Start();
        this.Focus();
    }

    private void RestartGame()
    {
        gameTimer.Stop();
        StartGame();
    }

    private void OnGameTick(object sender, ElapsedEventArgs e)
    {
        MoveBlock(0, 1);
    }

    private void OnPaint(object sender, PaintEventArgs e)
    {
        Graphics g = e.Graphics;

        for (int y = 0; y < GridHeight; y++)
        {
            for (int x = 0; x < GridWidth; x++)
            {
                if (grid[y, x] != 0)
                {
                    g.FillRectangle(Brushes.Blue, x * BlockSize, y * BlockSize, BlockSize, BlockSize);
                    g.DrawRectangle(Pens.Black, x * BlockSize, y * BlockSize, BlockSize, BlockSize);
                }
            }
        }

        for (int y = 0; y < currentBlock.GetLength(0); y++)
        {
            for (int x = 0; x < currentBlock.GetLength(1); x++)
            {
                if (currentBlock[y, x] != 0)
                {
                    int drawX = (currentBlockPosition.X + x) * BlockSize;
                    int drawY = (currentBlockPosition.Y + y) * BlockSize;
                    g.FillRectangle(Brushes.Red, drawX, drawY, BlockSize, BlockSize);
                    g.DrawRectangle(Pens.Black, drawX, drawY, BlockSize, BlockSize);
                }
            }
        }
    }

    private void OnKeyDown(object sender, KeyEventArgs e)
    {
        switch (e.KeyCode)
        {
            case Keys.Left:
                MoveBlock(-1, 0);
                break;
            case Keys.Right:
                MoveBlock(1, 0);
                break;
            case Keys.Down:
                MoveBlock(0, 1);
                break;
            case Keys.Up:
                RotateBlock();
                break;
        }
    }

    private void MoveBlock(int dx, int dy)
    {
        Point newPosition = new Point(currentBlockPosition.X + dx, currentBlockPosition.Y + dy);

        if (IsValidPosition(newPosition, currentBlock))
        {
            currentBlockPosition = newPosition;
            this.Invalidate();
        }
        else if (dy > 0)
        {
            PlaceBlock();
            ClearLines();
            if (!SpawnBlock())
            {
                gameOverLabel.Visible = true;
                gameTimer.Stop();
                startButton.Enabled = true;
                restartButton.Enabled = false;
            }
        }
    }

    private void RotateBlock()
    {
        int[,] rotatedBlock = new int[currentBlock.GetLength(1), currentBlock.GetLength(0)];

        for (int y = 0; y < currentBlock.GetLength(0); y++)
        {
            for (int x = 0; x < currentBlock.GetLength(1); x++)
            {
                rotatedBlock[x, currentBlock.GetLength(0) - 1 - y] = currentBlock[y, x];
            }
        }

        if (IsValidPosition(currentBlockPosition, rotatedBlock))
        {
            currentBlock = rotatedBlock;
            this.Invalidate();
        }
    }

    private bool IsValidPosition(Point position, int[,] block)
    {
        for (int y = 0; y < block.GetLength(0); y++)
        {
            for (int x = 0; x < block.GetLength(1); x++)
            {
                if (block[y, x] != 0)
                {
                    int newX = position.X + x;
                    int newY = position.Y + y;

                    if (newX < 0 || newX >= GridWidth || newY < 0 || newY >= GridHeight || grid[newY, newX] != 0)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    private void PlaceBlock()
    {
        for (int y = 0; y < currentBlock.GetLength(0); y++)
        {
            for (int x = 0; x < currentBlock.GetLength(1); x++)
            {
                if (currentBlock[y, x] != 0)
                {
                    grid[currentBlockPosition.Y + y, currentBlockPosition.X + x] = currentBlock[y, x];
                }
            }
        }
    }

    private void ClearLines()
    {
        for (int y = GridHeight - 1; y >= 0; y--)
        {
            bool isLineFull = true;

            for (int x = 0; x < GridWidth; x++)
            {
                if (grid[y, x] == 0)
                {
                    isLineFull = false;
                    break;
                }
            }

            if (isLineFull)
            {
                for (int yy = y; yy > 0; yy--)
                {
                    for (int xx = 0; xx < GridWidth; xx++)
                    {
                        grid[yy, xx] = grid[yy - 1, xx];
                    }
                }

                for (int xx = 0; xx < GridWidth; xx++)
                {
                    grid[0, xx] = 0;
                }

                y++;
                score += 100;
                scoreLabel.Text = "Score: " + score;
            }
        }
    }

    private bool SpawnBlock()
    {
        currentBlockPosition = new Point(GridWidth / 2 - 1, 0);

        switch (random.Next(0, 7))
        {
            case 0:
                currentBlock = new int[,] {
                    { 1, 1, 1, 1 }
                };
                break;
            case 1:
                currentBlock = new int[,] {
                    { 1, 1 },
                    { 1, 1 }
                };
                break;
            case 2:
                currentBlock = new int[,] {
                    { 0, 1, 0 },
                    { 1, 1, 1 }
                };
                break;
            case 3:
                currentBlock = new int[,] {
                    { 1, 1, 0 },
                    { 0, 1, 1 }
                };
                break;
            case 4:
                currentBlock = new int[,] {
                    { 0, 1, 1 },
                    { 1, 1, 0 }
                };
                break;
            case 5:
                currentBlock = new int[,] {
                    { 1, 0, 0 },
                    { 1, 1, 1 }
                };
                break;
            case 6:
                currentBlock = new int[,] {
                    { 0, 0, 1 },
                    { 1, 1, 1 }
                };
                break;
        }

        if (!IsValidPosition(currentBlockPosition, currentBlock))
        {
            return false;
        }

        return true;
    }

    public static void Main()
    {
        Application.Run(new TetrisGame());
    }
}
