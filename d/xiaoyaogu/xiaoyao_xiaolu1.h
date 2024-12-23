//xiaoyao_xiaolu1.h 小路1
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_xiaolu1);

virtual void create()
{
	set_name( "小路1");
	set("monster_chance",60);
	set("no_autosave",1);

	add_door("逍遥谷追月观大门", "逍遥谷追月观大门", "逍遥谷小路1");
	add_door("逍遥谷紫莲峰山脚", "逍遥谷紫莲峰山脚", "逍遥谷小路1");
	add_door("逍遥谷小路2", "逍遥谷小路2", "逍遥谷小路1");	

};

XiaoYao_END;
