//junying.h  军营
//秦波 2002、12、9

ROOM_BEGIN(CRGuanWai_junying);

virtual void create()			
{
	set_name("军营");

	set("renwu", 1);

	add_door("老龙头", "关外老龙头", "关外军营");
	add_door("左先锋营帐", "关外左先锋营帐1", "关外军营");
	add_door("中军先锋营帐", "关外中军先锋营帐1", "关外军营");
	add_door("右先锋营帐", "关外右先锋营帐1", "关外军营");

};

ROOM_END;
