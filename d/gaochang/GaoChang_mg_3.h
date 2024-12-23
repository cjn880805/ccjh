//GaoCang_mg_3.h 地狱入口二奈何桥
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_3);

virtual void create()			
{
	set_name("奈何桥");

	CDoor * a = add_yewaidoor("west", 4, 20);
	CDoor * b = add_yewaidoor("north", 4, 20);
	CDoor * c = add_yewaidoor("east", 4, 20);
	CDoor * d = add_yewaidoor("south", 4, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("黄泉之路", "高昌黄泉之路", "高昌奈何桥");
	add_npc("dy_master");

	set("long", "这里是通往十八地狱的“奈何桥”，三座并列的石拱桥，均建于平地，大小、形制完全相同。每桥宽仅四尺许，两侧护以雕花石栏，桥面略呈弧形，用青石铺砌，两端各有两级踏道。桥下跨一方形池，池底及桥壁均为条石嵌砌。桥下血河里虫蛇满布，波涛翻滚，腥风扑面。");

};

YEWAIDOOR_END;
