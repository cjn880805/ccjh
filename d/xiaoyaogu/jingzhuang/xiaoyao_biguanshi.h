//biguanshi.h
//Sample for room: 逍遥谷闭关室

ROOM_BEGIN(CRXiaoYao_biguanshi);

virtual void create()
{
	set_name( "闭关室");

	set("no_autosave",1);

	add_npc("xy_tielao1");

	add_door("大理城经幢7", "逍遥谷大理城经幢7", "逍遥谷闭关室");
};


ROOM_END;

