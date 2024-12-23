//GaoCang_mg_4.h 地狱入口三鬼门关
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_4);

virtual void create()			
{
	set_name("鬼门关");

	CDoor * a = add_yewaidoor("west", 5, 20);
	CDoor * b = add_yewaidoor("north", 5, 20);
	CDoor * c = add_yewaidoor("east", 5, 20);
	CDoor * d = add_yewaidoor("south", 5, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("奈何桥", "高昌奈何桥", "高昌鬼门关");
	add_npc("dy_master");

	set("long", "一座古式楼亭，四角飞檐。漆黑的山门空阔如宇，古意苍茫。血锈般的横匾上，镌着骇人的“鬼门关”三个大字，引人注目。关侧古树荫蔽，雀鸦聒噪，寒星凉月，给人阴森恐怖之感。");

};

YEWAIDOOR_END;
