class Solution:
    """
    @param image: a 2-D array
    @param sr: an integer
    @param sc: an integer
    @param newColor: an integer
    @return: the modified image
    """
    def floodFill(self, image, sr, sc, newColor):
        lenx, leny = len(image), len(image[0])
        def in_block(x, y):
            return (0<=x and x<lenx) and (0<=y and y<leny)

        def dfs(x, y, color):
            if  in_block(x, y) and (image[x][y] == color):
                image[x][y] = newColor
                for (nx, ny) in ((x+1, y), (x-1, y), (x, y+1), (x, y-1)):
                    dfs(nx, ny, color)
                return;

        dfs(sr, sc, image[sr][sc])
        return image
