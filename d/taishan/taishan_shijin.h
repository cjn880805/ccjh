//shijin.h

//Sample for room: ̩ɽʯ����
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_shijin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽʯ����");

	set("monster_chance", 30);
	//add npcs into the room
	//add_npc("sengren");
	add_npc("taishan_yujizi");          //add by zdn 2001-07-20
	
	add_door("̩ɽ��ĸ��", "̩ɽ��ĸ��", "̩ɽʯ����");
	add_door("̩ɽ������", "̩ɽ������", "̩ɽʯ����");

	set("long","������һ���ʯƺ��ʯ�����׭�ġ���վ�������������綷����ȴû�м��ؿ�ʯ�ߵ����ֺͿ�ʯ����������˴˴��������ɽ��ɽ·Խ��Խ�������ˡ�");
	

/*****************************************************
	set("exits", ([
		"northup" : __DIR__"huima",
		"westdown" : __DIR__"doumo",
	]));
	set("objects",([
		__DIR__"npc/seng-ren" : 1,
	]));
*****************************************************/
};


FIELD_END;
