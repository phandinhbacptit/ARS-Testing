#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

#include  <vector>

class movingAverage
{
public:
    movingAverage(int numOfFilterPoint, int maxOfMaxDataPoint);
    float addData(float data);

    std::vector<float> m_listInputData;
    void setNumOfFilter(int numOfFil) {m_nFilterPoint = numOfFil; m_nMaxDataPoint = numOfFil + 2; }
private:
    int m_nFilterPoint;
    int m_nMaxDataPoint;
};

#endif // MOVINGAVERAGE_H
