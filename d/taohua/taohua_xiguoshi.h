//xiguoshi.h

//Sample for room: ˼����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_xiguoshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "˼����");

	//add npcs into the room
	add_npc("taohuadao_mei");/////////////////////////

	add_door("�һ�ɽׯСԺ", "�һ�ɽׯСԺ", "�һ���˼����");
	add_door("�һ����һ���", "�һ����һ���", "�һ���˼����");

	set("long", "�����һ����Ϲ����ŵ��ӱ���˼���ĵط��������������һ�Ŵ����Եÿյ����ġ��������ǹ�ͺͺ��ǽ�ڣ�����ȥ������ģ�ԭ��ȴ�������ġ����ŵĵط���һС�������߷���һֻ�롣������һ�䲻���۵�С�ݣ����Ϲ��˸����ӡ��һ�������");

/*****************************************************
	set("exits", ([
		"west"  : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/mei" : 1,
	]) );    
//	
********************************************/
};


ROOM_END;
