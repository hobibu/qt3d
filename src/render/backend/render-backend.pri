INCLUDEPATH += $$PWD

include("framegraph/framegraph.pri")
include("jobs/render-jobs.pri")

HEADERS += \
    $$PWD/rendereraspect.h \
    $$PWD/renderthread_p.h \
    $$PWD/renderconfiguration_p.h \
    $$PWD/renderdevice_p.h \
    $$PWD/renderer_p.h \
    $$PWD/rendermaterial_p.h \
    $$PWD/rendermesh_p.h \
    $$PWD/qgraphicscontext_p.h \
    $$PWD/rendershader_p.h \
    $$PWD/rendertechnique_p.h \
    $$PWD/rendercameralens_p.h \
    $$PWD/quniformvalue_p.h \
    $$PWD/rendertexture_p.h \
    $$PWD/rendertextureprovider_p.h \
    $$PWD/meshdatamanager_p.h \
    $$PWD/states/blendstate_p.h \
    $$PWD/genericstate_p.h \
    $$PWD/qgraphicshelperinterface_p.h \
    $$PWD/qgraphicshelpergl3_p.h \
    $$PWD/qgraphicshelperes2_p.h \
    $$PWD/qgraphicshelpergl2_p.h \
    $$PWD/renderview_p.h \
    $$PWD/rendercommand_p.h \
    $$PWD/cameramanager_p.h \
    $$PWD/renderqueues_p.h \
    $$PWD/materialmanager_p.h \
    $$PWD/meshmanager_p.h \
    $$PWD/matrixmanager_p.h \
    $$PWD/vaomanager_p.h \
    $$PWD/shadermanager_p.h \
    $$PWD/techniquemanager_p.h \
    $$PWD/rendereffect_p.h \
    $$PWD/effectmanager_p.h \
    $$PWD/renderrenderpass_p.h \
    $$PWD/renderpassmanager_p.h \
    $$PWD/parameterpack_p.h \
    $$PWD/texturemanager_p.h \
    $$PWD/texturedatamanager_p.h \
    $$PWD/renderlayer_p.h \
    $$PWD/layermanager_p.h \
    $$PWD/renderlight_p.h \
    $$PWD/lightmanager_p.h \
    $$PWD/renderentity_p.h \
    $$PWD/entitymanager_p.h \
    $$PWD/rendercriterion_p.h \
    $$PWD/criterionmanager_p.h \
    $$PWD/framegraphmanager_p.h \
    $$PWD/rendertransform_p.h \
    $$PWD/transformmanager_p.h \
    $$PWD/renderstate_p.h \
    $$PWD/rendertarget_p.h \
    $$PWD/renderattachment_p.h \
    $$PWD/rendertargetmanager_p.h \
    $$PWD/renderscene_p.h \
    $$PWD/scenemanager_p.h \
    $$PWD/attachmentpack_p.h \
    $$PWD/attachmentmanager_p.h \
    $$PWD/sortcriterionmanager_p.h \
    $$PWD/shadervariables_p.h \
    $$PWD/qgraphicsutils_p.h \
    $$PWD/rendernodefunctor_p.h

SOURCES += \
    $$PWD/rendereraspect.cpp \
    $$PWD/renderthread.cpp \
    $$PWD/renderconfiguration.cpp \
    $$PWD/renderdevice.cpp \
    $$PWD/renderer.cpp \
    $$PWD/rendermaterial.cpp \
    $$PWD/rendermesh.cpp \
    $$PWD/qgraphicscontext.cpp \
    $$PWD/rendershader.cpp \
    $$PWD/rendertechnique.cpp \
    $$PWD/rendercameralens.cpp \
    $$PWD/quniformvalue.cpp \
    $$PWD/rendertexture.cpp \
    $$PWD/rendertextureprovider.cpp \
    $$PWD/meshdatamanager.cpp \
    $$PWD/states/blendstate.cpp \
    $$PWD/qgraphicshelpergl3.cpp \
    $$PWD/qgraphicshelperes2.cpp \
    $$PWD/qgraphicshelpergl2.cpp \
    $$PWD/renderview.cpp \
    $$PWD/rendercommand.cpp \
    $$PWD/cameramanager.cpp \
    $$PWD/renderqueues.cpp \
    $$PWD/materialmanager.cpp \
    $$PWD/meshmanager.cpp \
    $$PWD/matrixmanager.cpp \
    $$PWD/vaomanager.cpp \
    $$PWD/shadermanager.cpp \
    $$PWD/techniquemanager.cpp \
    $$PWD/rendereffect.cpp \
    $$PWD/effectmanager.cpp \
    $$PWD/renderrenderpass.cpp \
    $$PWD/renderpassmanager.cpp \
    $$PWD/parameterpack.cpp \
    $$PWD/texturemanager.cpp \
    $$PWD/texturedatamanager.cpp \
    $$PWD/renderlayer.cpp \
    $$PWD/layermanager.cpp \
    $$PWD/renderlight.cpp \
    $$PWD/lightmanager.cpp \
    $$PWD/renderentity.cpp \
    $$PWD/entitymanager.cpp \
    $$PWD/rendercriterion.cpp \
    $$PWD/criterionmanager.cpp \
    $$PWD/framegraphmanager.cpp \
    $$PWD/rendertransform.cpp \
    $$PWD/transformmanager.cpp \
    $$PWD/renderstate.cpp \
    $$PWD/rendertarget.cpp \
    $$PWD/renderattachment.cpp \
    $$PWD/rendertargetmanager.cpp \
    $$PWD/renderscene.cpp \
    $$PWD/scenemanager.cpp \
    $$PWD/attachmentpack.cpp \
    $$PWD/attachmentmanager.cpp \
    $$PWD/sortcriterionmanager.cpp
