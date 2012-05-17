#ifndef _AG2D_NODESTATUS_H_
#define _AG2D_NODESTATUS_H_

namespace ag2d
{
	enum Ag2dNodeStatus
	{
		//将要被创建
		NODE_NEW,
		//将要被删除
		NODE_DEL,
		//将要被隐藏
		NODE_HIDE,
		//正在显示状态
		NODE_SHOW
	};
};
#endif