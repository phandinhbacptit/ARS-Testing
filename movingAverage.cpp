#include "movingAverage.h"

movingAverage::movingAverage(int numOfFilterPoint, int maxOfMaxDataPoint) : m_nFilterPoint(numOfFilterPoint), m_nMaxDataPoint(maxOfMaxDataPoint)
{

}


float movingAverage::addData(float data)
{

    if(m_listInputData.size() < m_nMaxDataPoint) {
        m_listInputData.push_back(data);
        float sum = 0;
        for(int i=0; i< m_listInputData.size(); ++i) {
            sum += m_listInputData[i];
        }
        return sum/(float)m_listInputData.size();
    } else
    {
        m_listInputData.erase(m_listInputData.begin());
        m_listInputData.push_back(data);

        float sum = 0;
        for(int i= m_listInputData.size() - m_nFilterPoint; i< m_listInputData.size(); ++i) {
            sum += m_listInputData[i];
        }
        return sum/(float)m_nFilterPoint;
    }
}

