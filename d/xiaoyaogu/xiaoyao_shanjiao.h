//xiaoyao_shanjiao.h 山脚
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_shanjiao);

virtual void create()
{
	set_name( "山脚");
	set("monster_chance",60);
	set("no_autosave",1);

	add_door("逍遥谷小路1", "逍遥谷小路1", "逍遥谷紫莲峰山脚");
	add_door("逍遥谷紫莲峰山路1", "逍遥谷紫莲峰山路1", "逍遥谷紫莲峰山脚");



};

XiaoYao_END;
