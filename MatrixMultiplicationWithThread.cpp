#include <iostream>
#include <thread>
#include <vector>

void f_multplicacao(int tamanho, float **m_a, float **m_b, float **m_c, int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m_c[tamanho][i] += m_a[tamanho][j] * m_b[i][j];
        }
    }
}

int main(int argc, char *argv[]) {

    int n = 2;
    float **m_a, **m_b, **m_c;
    std::vector<std::thread> resultado;
    
    m_a = new float*[n];
    m_b = new float*[n];
    m_c = new float*[n];

    for(int i=0; i<n; i++) {
        m_a[i] = new float[n];
        m_b[i] = new float[n];
        m_c[i] = new float[n];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            m_a[i][j] = i+1;
            m_b[i][j] = (i+1) + (j+1);
            m_c[i][j] = 0.0;
        }
    }
        
    //Print A
    std::cout << "Matriz A" << std::endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cout << m_a[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    
    //Print B
    std::cout << "Matriz B" << std::endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cout << m_b[i][j] << ", ";
        }
        std::cout << std::endl;
    }
        
    for(int i=0; i<n; i++) {
        std::thread threads(f_multplicacao, i, m_a, m_b, m_c, n);
        resultado.emplace_back(threads);
    }
    
    for(int i=0; i<n; i++) {
        resultado[i].join();
    }
        
    std::cout << "Matriz C" << std::endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cout << m_c[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}