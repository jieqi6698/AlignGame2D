#include "..\include\ag2d_corenode.h"
using namespace ag2d;

Ag2dCoreNode::Ag2dCoreNode(int tag)
	:tag(tag),status(NODE_NEW)
{
}

Ag2dCoreNode::Ag2dCoreNode(int tag,float x,float y)
	:tag(tag),
	pos_x(x),
	pos_y(y),
	status(NODE_NEW)
{
}