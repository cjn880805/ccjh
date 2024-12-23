//xiaoyao_shanlu5.h 山路5
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_shanlu5);

virtual void create()
{
	set_name( "山路5");

	add_door("逍遥谷紫莲峰山路4", "逍遥谷紫莲峰山路4", "逍遥谷紫莲峰山路5");	
	add_door("逍遥谷空地", "逍遥谷空地", "逍遥谷紫莲峰山路5");	
	add_door("逍遥谷大理城经幢1", "逍遥谷大理城经幢1", "逍遥谷紫莲峰山路5");

};


int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"大理城经幢1"))
	{
		if(me->query("xy/renwu7_1") && !me->query("xy/renwu8"))
			return CRoom::valid_leave(me, dir);
		else
			return notify_fail("你看着经幢里的四大天王像，高约四尺，批甲戴胄，手持斧钺，威严庄重。三人足踏鬼奴。一鬼奴肌肉暴起，右手挽蛇，蛇嘴正触鬼奴下腭；另俩鬼奴戴镣。一天神足下三人，中间一人正以双手各托天王一足，天王之间遍刻梵文佛经，顿时肃然起敬。");;
	}
	return CRoom::valid_leave(me, dir);
}

XiaoYao_END;
