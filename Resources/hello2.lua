local cclog = function(...)
    print(string.format(...))
end

local bg_layer_tag = 0
local bg_layer = Ag2dEngine:sharedDirector():getRunningScene()

if nil == bg_layer then
	CC("dddddddddddd")
end
