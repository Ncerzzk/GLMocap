#ifndef MULTIPLEVIEWTRANGULATION_H
#define MULTIPLEVIEWTRANGULATION_H

#include "workspace.h"
#include <QObject>

#include <Eigen/Dense>


using namespace Eigen;

typedef Matrix<double,3,4> Matrix34d;
typedef Matrix<double,3,9> Matrix39d;
typedef Matrix<double,6,1> Vector6d;
typedef Matrix<double,6,3> Matrix63d;
typedef Matrix<double,6,6> Matrix6d;
typedef Matrix<double,9,1> Vector9d;
typedef Matrix<double,9,9> Matrix9d;
typedef DiagonalMatrix<double,9> DiagMatrix9d;

#define Default_f0  1.0
#define PT_NUM       1
#define CAM_NUM_ALL   2

class MultipleViewTriangulation : public QObject
{
    Q_OBJECT
private:
    char positionFlag[4] = {0,0,0,0};

    Matrix34d Prj[CAM_NUM_ALL];
    MatrixXd xy[PT_NUM];
    
    Vector3d Xr[PT_NUM];
public:
    MultipleViewTriangulation();

    // triangulation from all cameras and points
    bool triangulation_all(const Matrix34d Prj[],
                          int CamNum,
                          MatrixXd x[],
                          Vector3d Xr[],
                          int PtNum,
                          const MatrixXi& idx,
                          double f0 = Default_f0);

private slots:
    void positionSlot(int camIndex, double x,double y);
signals:
    onXYZSignals(double x,double y,double z);
};

#endif
