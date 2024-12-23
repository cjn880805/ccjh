//18hell_3_2.h
//十八地狱入口鬼门关二号房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_3_2);

virtual void create()			//Call it when Room Create
{
	set_name( "奈何桥");
	set("long", "这里是通往十八地狱的“奈何桥”，三座并列的石拱桥，均建于平地，大小、形制完全相同。每桥宽仅四尺许，两侧护以雕花石栏，桥面略呈弧形，用青石铺砌，两端各有两级踏道。桥下跨一方形池，池底及桥壁均为条石嵌砌。桥下血河里虫蛇满布，波涛翻滚，腥风扑面。");

	add_npc("diyu_shizhe3");

};

ROOM_END;
