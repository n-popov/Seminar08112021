
int** transpose(int** matrix, unsigned int N, unsigned int M) {
    int** transposed = new int*[M];
    for(auto i = 0u; i < M; i++) {
        transposed[i] = new int[N];
    }
    for(auto i = 0u; i < N; i++) {
        for(auto j = 0u; j < M; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}