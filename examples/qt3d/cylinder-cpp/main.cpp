/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QGuiApplication>

#include <window.h>
#include <Qt3DCore/qcamera.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qcameralens.h>

#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/qcylindermesh.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DRender/qframegraph.h>
#include <Qt3DRender/qforwardrenderer.h>

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    Window view;
    Qt3DCore::QAspectEngine engine;
    engine.registerAspect(new Qt3DRender::QRenderAspect());
    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
    engine.registerAspect(input);
    engine.initialize();
    QVariantMap data;
    data.insert(QStringLiteral("surface"), QVariant::fromValue(static_cast<QSurface *>(&view)));
    data.insert(QStringLiteral("eventSource"), QVariant::fromValue(&view));
    engine.setData(data);

    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

    // Camera
    Qt3DCore::QCamera *cameraEntity = new Qt3DCore::QCamera(rootEntity);
    cameraEntity->setObjectName(QStringLiteral("cameraEntity"));

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, -20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));
    input->setCamera(cameraEntity);

    // FrameGraph
    Qt3DRender::QFrameGraph *frameGraph = new Qt3DRender::QFrameGraph();
    Qt3DRender::QForwardRenderer *forwardRenderer = new Qt3DRender::QForwardRenderer();

    // TechiqueFilter and renderPassFilter are not implement yet
    forwardRenderer->setCamera(cameraEntity);
    forwardRenderer->setClearColor(Qt::black);

    frameGraph->setActiveFrameGraph(forwardRenderer);


    // Cylinder shape data
    Qt3DRender::QCylinderMesh *cylinder = new Qt3DRender::QCylinderMesh();
    cylinder->setRadius(1);
    cylinder->setLength(3);
    cylinder->setRings(100);
    cylinder->setSlices(20);

    // CylinderMesh Transform
    Qt3DCore::QTransform *cylinderTransform = new Qt3DCore::QTransform;
    cylinderTransform->setScale(1.5f);
    cylinderTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    // Cylinder
    Qt3DCore::QEntity *cylinderEntity = new Qt3DCore::QEntity(rootEntity);
    cylinderEntity->addComponent(cylinder);
    cylinderEntity->addComponent(cylinderTransform);

    // Setting the FrameGraph
    rootEntity->addComponent(frameGraph);

    // Set root object of the scene
    engine.setRootEntity(rootEntity);
    // Show window
    view.show();

    return app.exec();
}
