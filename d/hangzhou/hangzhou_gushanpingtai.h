//gushanpingtai.h

//Sample for room: 杭州孤山平台
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_gushanpingtai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州孤山平台");
	
	add_npc("pub_whitelady");           // add by zdn 2001-07-14


	add_door("杭州孤山", "杭州孤山", "杭州孤山平台");

	set("long"," 平台北面有“西湖天下景”亭阁，亭柱两旁有一对联(duilian)。这里还有曲桥水池，临池有叠石假山，布置得高低参差，疏密有致。北边是下山的路。");
    

/*****************************************************
        set("exits", ([
            "northdown" : __DIR__"gushan",
        ]));
        set("item_desc", ([
            "duilian" :
"水              晴
山              雨
处              时
处              时
明              好
秀              奇\n"
        ]));
 ********************************************/

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
