//18hell_4_4.h
//十八地狱入口奈何桥4号房间

ROOM_BEGIN(CR18hell_4_4);

virtual void create()			//Call it when Room Create
{
	set_name("鬼门关");
	set("long", "一座古式楼亭，四角飞檐。漆黑的山门空阔如宇，古意苍茫。血锈般的横匾上，镌着骇人的“鬼门关”三个大字，引人注目。关侧古树荫蔽，雀鸦聒噪，寒星凉月，给人阴森恐怖之感。");
	
	add_npc("diyu_shizhe4");

};

ROOM_END;
