//fengchan.h

//Sample for room: 泰山封禅台
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRTaiShan_fengchan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山封禅台");
	
	add_npc("taishan_tianbai");        //add by zdn 2001-07-20



	add_door("泰山玉皇顶", "泰山玉皇顶", "泰山封禅台");

	set("long","如今这里是推选天下武林总盟主之处，各路英雄如能技压群雄，比武夺魁，便能问鼎盟主宝座，成为统领中原武林的领袖。高台上摆放着汉白玉宝座，盟主便在此坐堂议事。台上高高立着一竿旗，上书：替天行道 四个大字。 盟主左右各侍立着两位白衣武士，两边都放着一长排虎皮交椅，时常有武林前辈高手前来参见盟主");
	

/*****************************************************
	set("exits", ([
		"down" : __DIR__"yuhuang",
		"east" : __DIR__"xiayi",
		"west" : __DIR__"zhengqi",
	]));
	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));
*****************************************************/
};


ROOM_END;
