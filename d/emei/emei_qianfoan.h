//qianfoan.h

//Sample for room:  峨嵋千佛庵
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CREMei_qianfoan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋千佛庵");

	add_npc("emei_daoming");
				
	add_door("峨嵋九十九道拐1", "峨嵋九十九道拐1", "峨嵋千佛庵");
	add_door("峨嵋黑龙江栈道", "峨嵋黑龙江栈道", "峨嵋千佛庵");

	set("long","此处是洪椿坪千佛庵。山间小坪坝，四面层峦叠障，峰环岭护；两侧深谷幽岚，溪涧玲叮。坪上古木扶疏，亭亭如盖，山阴沁透，白雾飘游，极为幽静清凉。此处常见雨雾霏霏，林中迷迷蒙蒙，乃山中雾气所为。正所谓「山行本无雨，空翠湿人衣」。这就是誉为奇观的「洪椿晓雨」。此处殿美景幽，气象新异，令人心醉。沿途南上是「九十九道拐」，北下经黑龙江栈道至清音阁。");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
