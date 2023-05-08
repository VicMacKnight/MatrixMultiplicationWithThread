#include <iostream>
#include <thread> 

void f_multplicacao(bool linha, int tamanho, float **m_a, float **m_b, float **m_c, float **m_d, float **m_e) {
    if(linha){
        m_d[i][j] = 0.0;
        for (int i = linha; i <= tamanho; i++){
             for ( int j=0; j< tamanho; j++){
                m_d[i][j] = m_d[i][j] + m_a[i][1] * m_b[1][j];
            }
        }
    } else {
        m_e[i][j] = 0.0;
        for (int i = linha; i <= tamanho; i++){
             for ( int j=0; j< tamanho; j++){
                m_e[i][j] = m_e[i][j] + m_a[1][j] * m_b[i][1];
            }
        }
    }
}

int main(int argc, char *argv[]) {

    int n;
    float **m_a, **m_b, **m_c, **m_d, **m_e;

    if(argc < 2) return -1;
    n = atoi(argv[1]);
    
    m_a = new float*[n];
    m_b = new float*[n];
    m_c = new float*[n];
    m_d = new float*[n];
    m_e = new float*[n];

    for(int i=0; i<n; i++)
    {
        m_a[i] = new float[n];
        m_b[i] = new float[n];
        m_c[i] = new float[n];
        m_d[i] = new float[n];
        m_e[i] = new float[n];
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            m_a[i][j] = i+1;
            m_b[i][j] = (i+1) + (j+1);
            m_c[i][j] = 0.0;
        }
        
    std::thread thread1(f_multplicacao, true, n, m_a, m_b, m_c, m_d, m_e);
    std::thread thread2(f_multplicacao, false, n, m_a, m_b, m_c, m_d, m_e);

    thread1.join();
    thread2.join();

    m_c = new float*[n];
    for(int i=0; i<n; i++){
        m_c[i] = new float[n];
        for(int j=0; j<n; j++){
            m_c[i][j] = m_d[i][j] + m_e[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            std::cout << m_c[i][j] << ", ";
        }
        std::cout << std::endl;
    };
    return 0;
}