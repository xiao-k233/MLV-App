#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QFileDialog>
#include <QDebug>
#include <QTimerEvent>
#include <QResizeEvent>
#include "../../src/mlv_include.h"
#include "InfoDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void timerEvent( QTimerEvent *t );
    void resizeEvent( QResizeEvent *event );

private slots:
    void on_actionOpen_triggered();
    void on_actionAbout_triggered();
    void on_horizontalSliderPosition_valueChanged(void);
    void on_checkBoxUseAmaze_toggled(bool checked);
    void on_actionClip_Information_triggered();
    void on_horizontalSliderExposure_valueChanged(int position);
    void on_horizontalSliderTemperature_valueChanged(int position);
    void on_horizontalSliderTint_valueChanged(int position);
    void on_horizontalSliderSaturation_valueChanged(int position);
    void on_horizontalSliderDS_valueChanged(int position);
    void on_horizontalSliderDR_valueChanged(int position);
    void on_horizontalSliderLS_valueChanged(int position);
    void on_horizontalSliderLR_valueChanged(int position);
    void on_horizontalSliderLighten_valueChanged(int position);

    void on_actionGoto_First_Frame_triggered();

private:
    Ui::MainWindow *ui;
    InfoDialog *m_pInfoDialog;
    mlvObject_t *m_pMlvObject;
    processingObject_t *m_pProcessingObject;
    QLabel *m_pRawImageLabel;
    uint8_t *m_pRawImage;
    bool m_frameChanged;
    int m_currentFrameIndex;
    bool m_dontDraw;
    bool m_frameStillDrawing;
    bool m_fileLoaded;
    int m_timerId;
    QString m_lastSaveFileName;
    void drawFrame();
};

#endif // MAINWINDOW_H
