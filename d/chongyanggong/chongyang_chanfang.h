//chanfang.h

//Sample for room:  重阳宫禅房
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_chanfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫禅房");

	add_npc("quanzhen_zhangli");

	CBox * box = Add_Box();
	box->add_object("gangjian");	
	box->set_name( "铁柜");
	
	box->add_object("gangdao");				
	box->add_object("tiejiang");	
	
	add_door("重阳宫练功房", "重阳宫练功房", "重阳宫禅房");

	set("long", "这里是全真教弟子摆放兵器的禅房，地下杂乱地堆着一些剑，有的已经锈纹斑斑了，有的还是锋利透亮，全真弟子练功的时候，就到这里来挑选兵刃。");

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
//last, register the room into ../server/RoomSetup.cpp