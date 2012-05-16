#include "..\include\ag2d_scene.h"

using namespace ag2d;


Ag2dScene::Ag2dScene(FlowCode code)
	:M_FlowCode(code)
{
}

Ag2dScene::~Ag2dScene()
{
	m_display_scene->release();
}

void Ag2dScene::initMeasure(float w,float h)
{
	m_measure_height = h;
	m_measure_width = w;
	m_center_x = w / 2;
	m_center_y = h / 2;
}

//场景被引擎渲染到显示窗口中。
CCScene* Ag2dScene::createDisplay()
{
	m_display_scene = CCScene::node();
	m_display_scene->addChild(this);
	draw(m_display_scene);
	this->schedule(schedule_selector(Ag2dScene::scheduleOnFrame));
	return m_display_scene;
}
