//xiaoyao_lianwuchang.h 练武场
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_lianwuchang);

virtual void create()
{
	set_name( "练武场");

	add_npc("xy_qingfeng");

	add_door("逍遥谷追月观怀月庭", "逍遥谷追月观怀月庭", "逍遥谷追月观练武场");

};

XiaoYao_END;
