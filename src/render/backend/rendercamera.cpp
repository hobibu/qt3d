/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "rendercamera.h"
#include "rendereraspect.h"
#include "renderlogging.h"
#include <transform.h>
#include <cameralens.h>

#include <entity.h>
#include <qaspectmanager.h>

#include <QOpenGLContext>

QT_BEGIN_NAMESPACE

namespace Qt3D {
namespace Render {

RenderCamera::RenderCamera()
    : m_rendererAspect(Q_NULLPTR)
    , m_peer(Q_NULLPTR)
{
    m_clearColor = QVector4D(0.5, 0.5, 1.0, 1.0);
}

void RenderCamera::setRendererAspect(RendererAspect *rendererAspect)
{
    m_rendererAspect = rendererAspect;
}

void RenderCamera::setPeer(CameraLens *peer)
{
    if (peer != m_peer) {
        QChangeArbiter *arbiter = m_rendererAspect->aspectManager()->changeArbiter();
        if (m_peer)
            arbiter->unregisterObserver(this, m_peer);
        m_peer = peer;
        if (m_peer) {
            // Register for changes
            arbiter->registerObserver(this, m_peer, ComponentUpdated);
        }
    }
}

void RenderCamera::sync()
{

}

unsigned int RenderCamera::clearMask() const
{
    return GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
}

void RenderCamera::setProjection(const QMatrix4x4 &projection)
{
    m_projection = projection;
}

QMatrix4x4 RenderCamera::projection() const
{
    return m_projection;
}

void RenderCamera::setViewMatrix(const QMatrix4x4 &view)
{
    m_view = view;
}

QMatrix4x4 RenderCamera::view() const
{
    return m_view;
}

void RenderCamera::sceneChangeEvent(const QSceneChangePtr &e)
{
    switch (e->m_type) {
    case ComponentUpdated: {
        QScenePropertyChangePtr propertyChange = qSharedPointerCast<QScenePropertyChange>(e);
        QVariant propertyValue = propertyChange->m_value;
        QMatrix4x4 viewMatrix = propertyValue.value<QMatrix4x4>();
        m_projection = viewMatrix;
        break;
    }

    default:
        break;
    }
}

} // Render
} // Qt3D

QT_END_NAMESPACE