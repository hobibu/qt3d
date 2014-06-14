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

#include <Qt3DQuick/quickwindow.h>
#include <Qt3DRenderer/rendereraspect.h>

#include <QGuiApplication>
#include <QtQml>

#include <iostream>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QCommandLineParser parser;
    parser.addPositionalArgument(QStringLiteral("meshfile"), QStringLiteral("The mesh file to load"));
    parser.process(app);

    const QStringList meshFileNames = parser.positionalArguments();
    if (meshFileNames.length() == 0) {
        std::cerr << "Please specify mesh files to load" << std::endl;
        return 1;
    }

    Qt3D::Quick::QuickWindow view;
    view.registerAspect(new Qt3D::RendererAspect());
    // There should be some synchronising mechanism to make sure
    // the source is set after alll aspects have been completely initialized
    // Otherwise we might encounter cases where an Aspect's QML elements have
    // not yet been registered
    view.engine()->rootContext()->setContextProperty("_meshFileNames", meshFileNames);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return app.exec();
}