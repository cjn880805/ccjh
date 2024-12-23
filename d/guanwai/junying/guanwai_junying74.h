//junying73.h  中军营帐3
//秦波 2003、6、5

ROOM_BEGIN(CRGuanWai_junying74);

virtual void create()			
{
	set_name("中军营帐");

	set("renwu", 1);

	add_npc("bj_qiu");

	add_door("中军营帐1", "关外中军营帐1", "关外中军营帐4");
	add_door("左翼营帐2", "关外左翼营帐2", "关外中军营帐4");
	add_door("中军帅帐", "关外中军帅帐", "关外中军营帐4");
	add_door("中军营帐6", "关外中军营帐6", "关外中军营帐4");

	set("long","整个大营是按六子连方阵所布，最是善守，六处偏营护住中央大寨，本阵位于中军之核心，牢不可破。看得出王求仁也是久读兵书，惯战沙场的骁将。" );

};

ROOM_END;
