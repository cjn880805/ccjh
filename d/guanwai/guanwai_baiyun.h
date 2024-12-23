//baiyun.h

//Sample for room: 白云峰
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_baiyun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白云峰");

	add_npc("pub3_huangyishizhe");    // add by zdn 2001-07-13
	add_npc("guanwai_tengyilei");        //add by zdn 2001-07-20

	set("monster_chance", 50);

	add_door("关外鹿鸣峰", "关外鹿鸣峰", "关外白云峰");
	add_door("关外白头山天池1", "关外白头山天池1", "关外白云峰");
	add_door("关外玉柱峰", "关外玉柱峰", "关外白云峰");

	set("long","白云峰在天池之西，鹿鸣峰之南，为长白山主峰。山峰圆而高大，临天池而耸立，巍峨磅礴，如一口宝剑直插云天。天气晴好，天池十六峰毕露，惟独此峰常有烟云缭绕，终日不散。古人有“看罢归来回首顾，白山依旧白云封”的赞语。登临此峰，诚有飘飘欲仙之感。" );
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
